#include <LiquidCrystal.h> 
#include <Arduino.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 

void Screen_Configure(){ 

    Serial.println("Starting Screen_Configure...");
    lcd.begin(16, 2);
    delay(10);
    Serial.println("Screen_Configure Complete...");
}
void Screen_Weight(float i){
    Serial.println("Starting Screen_Weight...");
    Serial.print(" ");
    Serial.println(i - 367145 + 11);
    lcd.setCursor(0, 0); 
    lcd.print(i - 367145 + 11); 
    delay(500);
    Serial.println("Screen_Weight Complete...");
}