#include <Arduino.h>
#include <HX711_ADC.h>
#include <LiquidCrystal.h> //Dołączenie bilbioteki
#include "Weight.h"

void setup() {
  Serial.begin(9600);
  delay(10);
  Serial.println();
  Serial.println("Starting...");
  WeightConfigure();
}

void loop() {
  WeightRun();
}