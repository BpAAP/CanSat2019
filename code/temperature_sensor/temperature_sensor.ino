//THIS CODE IS UNTESTED
//Needs OneWire 
//Needs DallasTemperature
#include <OneWire.h>
#include <DallasTemperature.h>

#define BUS_PIN 4
OneWire oneWire(BUS_PIN);

DallasTemperature sensors(&oneWire);

void initialise_temperature_sensor(){
  sensors.begin();
}

float get_temperature(){
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}
