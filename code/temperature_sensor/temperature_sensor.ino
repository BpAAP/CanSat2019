//THIS CODE IS UNTESTED
//Needs OneWire 
//Needs DallasTemperature
#include <OneWire.h>
#include <DallasTemperature.h>

#define BUS_PIN 2
OneWire oneWire(BUS_PIN);

DallasTemperature sensors(&oneWire);

void initialise_temperature_sensor(){
  sensors.begin();
}

float get_temperature(){
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}

void setup(){
  Serial.begin(9600);
  Serial.println("Serial Started");
  initialise_temperature_sensor();
}

void loop(){
  Serial.println(get_temperature());
  delay(1000);
}
