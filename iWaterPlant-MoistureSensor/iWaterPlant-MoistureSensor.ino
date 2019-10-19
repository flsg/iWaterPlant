const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  // RGB LED pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // https://color.adobe.com/create
  rgbColor(255, 0, 0);
  delay(500);
  rgbColor(0, 255, 0);
  delay(500);
  rgbColor(0, 0, 255);
  delay(500);
}

void rgbColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
