#include <Arduino.h>
#include "Screen.h"
#include "Weight.h"

float i = 0;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Starting...");
  WeightConfigure();
  Screen_Configure();
}

void loop() {
  WeightRun(i);
  Screen_Weight(i);
  
}