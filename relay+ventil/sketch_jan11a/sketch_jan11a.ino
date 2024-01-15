#define relay2 14

void setup() {
  pinMode(relay2, OUTPUT);
}

void loop() {
  digitalWrite (relay2, LOW);
  delay(20000);
  digitalWrite (relay2, HIGH);
  delay(3000);

}
