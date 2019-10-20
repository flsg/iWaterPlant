// RGB Pins
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Buzzer Pin
const int buzzerPin = 3;

int moistureValue = 0;
int moistureLevel = 0;

int normalMinValue = 40;  // water level minimum threshold
int normalMaxValue = 70;  // water level maximum threshold
  
void setup() {
  // RGB LED pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Buzzer pin
  pinMode(buzzerPin, OUTPUT);

  // Serial communication starts
  Serial.begin(9600);

  Serial.println("iWaterPlant starts up...");
}

void loop() {
  moistureValue = analogRead(A0); // read water analog value
  moistureLevel = map(moistureValue, 0, 1023, 0, 100);  // convert its to percentage
  moistureLevel = 100 - moistureLevel;  // invert reading

  // Display moisture level on serial
  Serial.print("Moisture Level: ");
  Serial.print(moistureLevel);
  Serial.println(" %");

  // Check if water level is in range
  if(moistureLevel >= normalMinValue && moistureLevel <= normalMaxValue) {
    rgbColor(0, 255, 0);
  }

  // Check if water level is out of range
  if(moistureLevel < normalMinValue || moistureLevel > normalMaxValue) {
    for(int i = 0; i < 3; i++) {
      rgbColor(255, 0, 0);  // flashing RGB light
      tone(buzzerPin, 1000);  // play beep sound
      delay(100);
      rgbColor(0, 0, 0);
      noTone(buzzerPin);
      delay(100);
    }
  }

  delay(10000);
}

// RGB color function
void rgbColor(int red, int green, int blue) {
  if(red >=0 && red <=255) analogWrite(redPin, red);
  if(green >=0 && green <=255) analogWrite(greenPin, green);
  if(blue >=0 && blue <=255) analogWrite(bluePin, blue);
}
