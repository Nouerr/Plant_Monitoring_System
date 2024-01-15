#include "DHT.h"   
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 20, 4);  
#define DHTPIN 23
#define DHTTYPE DHT11
#define relay1 27
#define relay2 13
const int moisturePin = 36;
int moistureReading;
#define POWER_PIN  17
#define SIGNAL_PIN 34

int value = 0;
DHT dht(DHTPIN, DHTTYPE);

const int temperatureThreshold = 18;
const int gazThreshold = 50;
const int humsoldesired= 10;

int Gas_analog = 25;
int Gas_digital = 26;


void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

  Serial.begin(9600);
  pinMode(Gas_digital, INPUT);

  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, LOW);

  }

void loop() {
  moistureReading = analogRead(moisturePin);
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  int moisturePercentage = map(moistureReading, 0, 4095, 100, 0);
  int gassensorAnalog = analogRead(Gas_analog);
  int gazpourcentage =  map(gassensorAnalog, 0, 4095, 0, 100);
  int level =  map(value, 0, 1024, 0, 100);

  Serial.print("Temperature:");
  Serial.print(temp);
  Serial.print((char)223);
  Serial.print("C");

  Serial.print(" Humidity:");
  Serial.print(hum);
  Serial.print("%");

  Serial.print(" Soil Moisture is  = ");
  Serial.print(moisturePercentage);
  Serial.println("%");

  Serial.print(" Gas Sensor: ");
  Serial.print(gazpourcentage);
  Serial.print("%");

  digitalWrite(POWER_PIN, HIGH);
  delay(10);
  value = analogRead(SIGNAL_PIN);
  digitalWrite(POWER_PIN, LOW);
  Serial.print("water sensor : ");
  Serial.println(level);

  lcd.clear();
  lcd.print("T:" + String(temp) + (char)223 + "C" + "|" + "H:" + String(hum) + "%");
  lcd.setCursor(0, 1);
  lcd.print("S:" + String(moisturePercentage) + "%" + "|" + "C:" + String(gazpourcentage) + "%" + "|" + "W:" + String(level));

  delay(2000);

  if ((temp > temperatureThreshold) || (gazpourcentage > gazThreshold)) {
    digitalWrite(relay1, LOW);

  } else {
    digitalWrite(relay1, HIGH);
  }

  if (moisturePercentage < humsoldesired) {
    digitalWrite(relay2, LOW);
    }
   else {
    digitalWrite(relay2, HIGH);
  }
}