#include <Arduino.h>
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