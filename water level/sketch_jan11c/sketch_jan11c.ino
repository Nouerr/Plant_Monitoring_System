
#define POWER_PIN  17 
#define SIGNAL_PIN 34

int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);  
  digitalWrite(POWER_PIN, LOW); 
}

void loop() {
  

  digitalWrite(POWER_PIN, HIGH);  
  delay(10);                      
  value = analogRead(SIGNAL_PIN);  
  digitalWrite(POWER_PIN, LOW);    
int level =  map(value, 0, 1024, 0, 100);
  Serial.print("The water sensor value: ");
  Serial.println(level);

  delay(1000);
}
