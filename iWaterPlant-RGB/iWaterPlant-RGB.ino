void setup() {
  // Serial starts
  Serial.begin(9600);
}

void loop() {
  int moistureValue;
  int moisturePercentage;
   
  moistureValue = analogRead(A0);

  moisturePercentage = map(moistureValue, 0, 1024, 0, 100);
  
  Serial.print("Moisture Value: ");
  Serial.print(moisturePercentage);
  Serial.println(" %");

  delay(1000);
}
