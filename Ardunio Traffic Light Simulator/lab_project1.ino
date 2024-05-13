int redLight = 13;
int yellowLight = 12;
int greenLight = 11;
int pedestrianRed = 10;
int pedestrianGreen = 9;
int button = 2;
int buttonPressed = 0;

unsigned long greenLightStartTime = 0;
bool greenLightOn = false;

void setup() {
  pinMode(redLight, OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
  pinMode(pedestrianRed, OUTPUT);
  pinMode(pedestrianGreen, OUTPUT);
  pinMode(button, INPUT);

  digitalWrite(redLight, LOW);
  digitalWrite(yellowLight, LOW);
  digitalWrite(greenLight, LOW);
  digitalWrite(pedestrianRed, LOW);
  digitalWrite(pedestrianGreen, LOW);
}

void loop() {
  if (!greenLightOn) {
    digitalWrite(greenLight, HIGH);
    digitalWrite(pedestrianRed, HIGH);
    greenLightStartTime = millis();
    greenLightOn = true;
  }

  if (greenLightOn && millis() - greenLightStartTime < 8000) {
    buttonPressed = digitalRead(button);
    if (buttonPressed == HIGH) {
      greenLightOn = false;
      startPedestrianSequence();
    }
  } else if (greenLightOn && millis() - greenLightStartTime >= 8000) {
    greenLightOn = false;
    runTrafficSequence();
  }
}

void startPedestrianSequence() {
  delay(2000);
  digitalWrite(greenLight, LOW);
  for (int i = 0; i <= 3; i++) {
    digitalWrite(yellowLight, HIGH);
    delay(500);
    digitalWrite(yellowLight, LOW);
    delay(500);
  }
  digitalWrite(redLight, HIGH);
  delay(1000);
  digitalWrite(pedestrianRed, LOW);
  digitalWrite(pedestrianGreen, HIGH);
  delay(7000);
  for (int i = 0; i <= 3; i++) {
    digitalWrite(pedestrianGreen, LOW);
    delay(500);
    digitalWrite(pedestrianGreen, HIGH);
    delay(500);
  }
  digitalWrite(pedestrianGreen, LOW);
  digitalWrite(pedestrianRed, HIGH);
  delay(1000);
  digitalWrite(redLight, LOW);
   for (int i = 0; i <= 3; i++) {
    digitalWrite(yellowLight, HIGH);
    delay(500);
    digitalWrite(yellowLight, LOW);
    delay(500);
  }
  digitalWrite(yellowLight, LOW);
}

void runTrafficSequence() {
  digitalWrite(greenLight, LOW);
  for (int i = 0; i <= 3; i++) {
    digitalWrite(yellowLight, HIGH);
    delay(500);
    digitalWrite(yellowLight, LOW);
    delay(500);
  }
  digitalWrite(redLight, HIGH);
  delay(1000);
  digitalWrite(pedestrianRed, LOW);
  digitalWrite(pedestrianGreen, HIGH);
  delay(7000);
  for (int i = 0; i <= 3; i++) {
    digitalWrite(pedestrianGreen, LOW);
    delay(500);
    digitalWrite(pedestrianGreen, HIGH);
    delay(500);
  }
  digitalWrite(pedestrianGreen, LOW);
  digitalWrite(pedestrianRed, HIGH);
  delay(1000);
  digitalWrite(redLight, LOW);
  for (int i = 0; i <= 3; i++) {
    digitalWrite(yellowLight, HIGH);
    delay(500);
    digitalWrite(yellowLight, LOW);
    delay(500);
  }
  digitalWrite(yellowLight, LOW);
}
