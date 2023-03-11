#include <HX711_ADC.h>
#include "Weight.h"
#include <LiquidCrystal.h>  

const int HX711_dout = 8;
const int HX711_sck = 9;
HX711_ADC LoadCell(HX711_dout, HX711_sck);
float i = 0;
void WeightConfigure(){

    LoadCell.begin();
  float calibrationValue;
  calibrationValue = 22.39;

  unsigned long stabilizingtime = 2000;
 LoadCell.start(stabilizingtime);
  if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  } else {
    LoadCell.setCalFactor(calibrationValue);  // set calibration value (float)
    Serial.println("Startup is complete");
  }
}

void WeightRun(){
      static boolean newDataReady = 0;
  const int serialPrintInterval = 5000; 

  if (LoadCell.update()) newDataReady = true;

  if (newDataReady) {
    if (millis() > serialPrintInterval) {
      i = LoadCell.getData();
    }
  }
}