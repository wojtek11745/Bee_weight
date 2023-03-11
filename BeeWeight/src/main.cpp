#include <Arduino.h>
#include "Screen.h"
#include "Weight.h"


void setup() {

  Serial.println();
  Serial.println("Starting...");
  WeightConfigure();
}

void loop() {
  WeightRun();
  Screen_Weight();
}