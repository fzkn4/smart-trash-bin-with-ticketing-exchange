#include <Stepper.h>

const int trigPin = 7;
const int echoPin = 6;

const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); // FIXED order

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myStepper.setSpeed(10);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
  if (duration == 0) return;

  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 10) {
    delay(100);                   // Wait for relay to switch
    myStepper.step(stepsPerRevolution); // quarter turn instead of full
  }

  delay(200);
}
