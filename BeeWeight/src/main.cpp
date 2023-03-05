#include <Arduino.h>
#include <HX711_ADC.h>
#include <LiquidCrystal.h> //Dołączenie bilbioteki
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Informacja o podłączeniu nowego wyświetlacza
 

const int HX711_dout = 8;
const int HX711_sck = 9;

HX711_ADC LoadCell(HX711_dout, HX711_sck);

void setup() {
  Serial.begin(9600);
  delay(10);
  Serial.println();
  Serial.println("Starting...");

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

void loop() {
  static boolean newDataReady = 0;
  const int serialPrintInterval = 5000;  //increase value to slow down serial print activity

  // check for new data/start next conversion:
  if (LoadCell.update()) newDataReady = true;

  // get smoothed value from the dataset:
  if (newDataReady) {
    if (millis() > serialPrintInterval) {
      float i = LoadCell.getData();
      Serial.print(" ");
      Serial.println(i - 367145 + 11);
      newDataReady = 0;
          //lcd.begin(16, 2); //Deklaracja typu
  lcd.setCursor(0, 0); //Ustawienie kursora
  lcd.print(i - 367145 + 11); //Wyświetlenie tekstu
  delay(500);
    }
  }

}