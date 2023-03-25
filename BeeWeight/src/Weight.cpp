#include <HX711_ADC.h>
#include "Weight.h"
#include <LiquidCrystal.h>  

const int HX711_dout = 8;
const int HX711_sck = 9;

int tareValue;
HX711_ADC LoadCell(HX711_dout, HX711_sck);

void WeightConfigure(){
  Serial.println("Starting WeightConfigure...");
  LoadCell.begin();
  float calibrationValue;
  SetTareValue(367);//367156
  calibrationValue = 22.39;
  unsigned long stabilizingtime = 2000;
  LoadCell.start(stabilizingtime);
  if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  } else {
    LoadCell.setCalFactor(calibrationValue);  // set calibration value (float)
    Serial.println("WeightConfigure is complete");
  }
}

void SetTareValue(int p_tareValue)
{
  tareValue = p_tareValue;
}

int WeightRun(){
  Serial.println("Starting WeightRun...");
  static boolean newDataReady = 0;
  const int serialPrintInterval = 5000; 
  float mass{0};
  if (LoadCell.update()) newDataReady = true;

  if (newDataReady) {
    if (millis() > serialPrintInterval) {
      mass = LoadCell.getData();
    }
  }
  Serial.println("WeightRun Complete...");

  return (mass - tareValue);
}