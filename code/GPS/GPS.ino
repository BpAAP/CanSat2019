//THIS CODE IS UNTESTED
//Requires adafruit GPS Library
//just need to connect RX/TX lines betwwen module and arduino

//There is some way to use interrupts but IDK how, this way:
// >Call update_gps_data to wait for next data packet, this is blocking.
// >Call whichever function to get the info you need.
// >Probably better to pass pointer to array on stack rather than allocating memory, where necessary

#include <Adafruit_GPS.h>
#define GPSSerial Serial1
Adafruit_GPS GPS(&GPSSerial);

void initialise_GPS(){
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
}

//to get location, pass pointer of empty float array of length 2
//function will return last received data packet
//arr[0] is latitude +/- ==> North/South
//arr[1] is longitude +/- ==> East/West
//degree:minute format
float * get_location(float *arr){
  arr[0] = GPS.latitude;
  if (GPS.lat == 'S'){
    arr[0] = - arr[0];
  }
  arr[1] = GPS.longitude;
  if (GPS.lon == 'W'){
    arr[1] = - arr[1];
    }
  return arr;
}

void update_gps_data(){
  GPS.read();
  while (!GPS.newNMEAreceived()){
    GPS.read();
  }
  GPS.parse(GPS.lastNMEA);
  }

//pass pointer of empy int array length 4
//will return int array pointer with [H:M:S:mS]
int * get_time(int *arr){
  arr[0] = GPS.hour;
  arr[1] = GPS.minute;
  arr[2] = GPS.seconds;
  arr[3] = GPS.miliseconds;
  return arr;
  }

//returns float speed in knots
float get_speed(){
  return GPS.speed;
}

float get_altitude(){
  return GPS.altitude;
}

//pass pointer to empty int array length 2
//will return [fix,quality]
int *get_fix(int *arr){
  arr[0] = GPS.fix;
  arr[1] = GPS.fixquality;
  return arr;
}
