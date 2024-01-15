#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
int Gas_analog = 25;    
int Gas_digital = 26;  

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  pinMode(Gas_digital, INPUT);
}

void loop() {
  int gassensorAnalog = analogRead(Gas_analog);  
  int gassensorDigital = digitalRead(Gas_digital);
  int gazpourcentage =   map(gassensorAnalog, 0, 4096, 0, 100);

  Serial.print("Gas Sensor: ");
  Serial.print(gazpourcentage);
  Serial.print("%");
  Serial.print("Gas Sensorreading: ");
  Serial.print(gassensorAnalog);
  Serial.print("\t");
  Serial.print("Gas Class: ");
  Serial.print(gassensorDigital);
  Serial.print("\t");

  if (gassensorAnalog > 2000) {
    
 
    lcd.clear();
    lcd.print("GAAAAAZ");
    lcd.setCursor(0, 1);
    lcd.print("Gas Sensor: ");
    lcd.print(gazpourcentage);
    lcd.print("%\n");
    delay(1000);
  }
  else {
    Serial.println("\t No Gas");
    lcd.clear();
    lcd.print("NO GAZ");
    lcd.setCursor(0, 1);
    lcd.print("Gas Sensor: ");
    lcd.print(gazpourcentage);
    lcd.print("%");
    delay(1000);
  }
  delay(100);

}
