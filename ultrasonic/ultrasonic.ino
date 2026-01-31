#include <Stepper.h>

const int trigPin = 7;
const int echoPin = 6;
long duration;
int distance;

const int stepsPerRevolution = 600;
// Using pins 2, 3, 4, 5 to avoid conflict with buzzer/LEDs
Stepper myStepper(stepsPerRevolution, 2, 3, 4, 5);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myStepper.setSpeed(60); // Set RPM
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 10) {
    Serial.println("Object detected within 10cm! Turning motor.");
    myStepper.step(stepsPerRevolution); // Turn one full revolution
    delay(500); // A small pause after turning
  }

  delay(250);
}
