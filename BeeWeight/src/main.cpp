#include <Arduino.h>
#include "Screen.h"
#include "Weight.h"
#include "thermometer.h"

float value = 0;
int temperatureCorrection = 0;
void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Starting...");
  WeightConfigure();
  Screen_Configure();
}

void loop() {
temperatureCorrection = temperaturaRun();

  value = WeightRun(temperatureCorrection);
  Screen_Weight(value);
 }