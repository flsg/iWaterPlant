const int buzzerPin = 3;

void setup() {
  // Buzzer
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  tone(buzzerPin, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzerPin);     // Stop sound...
  delay(1000);        // ...for 1sec
}
