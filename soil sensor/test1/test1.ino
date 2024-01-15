const int moisturePin = 36;  // moisture sensor pin
int moistureReading;         // moisture reading

void setup() {
  Serial.begin(9600);
}

void loop() {
  moistureReading = analogRead(moisturePin);
  int moisturePercentage = map(moistureReading, 0, 4095, 100, 0);

  Serial.print("Soil Moisture is  = ");
  Serial.print(moisturePercentage);
  Serial.println("%");

  delay(1000); 
}
