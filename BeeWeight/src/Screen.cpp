#include <LiquidCrystal.h> 
#include <Arduino.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 

float i = 0;

void Screen_Configure(){ 
    Serial.begin(9600);
    lcd.begin(16, 2);
    delay(10);
}
void  Screen_Weight(){
        Serial.print(" ");
        Serial.println(i - 367145 + 11);
  lcd.setCursor(0, 0); 
  lcd.print(i - 367145 + 11); 
    delay(500);
}