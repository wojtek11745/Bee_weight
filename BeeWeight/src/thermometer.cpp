#include <Arduino.h>
#include <LiquidCrystal.h>
int temperature;
int temperatureCorrection;  

void Settemperature(int p_temperature){
  temperature = p_temperature;
}

int temperaturaRun(){
  if (temperature > 15){

  temperatureCorrection = (temperature - 15) * 100;
  
    Serial.println("temperature=");
    Serial.println(temperature);
    Serial.println("temperatureCorrection=");
    Serial.println(temperatureCorrection);
  }
  return(temperatureCorrection);
}