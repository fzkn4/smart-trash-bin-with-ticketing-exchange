#include <Stepper.h>
const int stepsPerRevolution = 2048;  // For 28BYJ-48 full-step
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);  // Correct pin order: IN1-IN3-IN2-IN4

void setup() {
  myStepper.setSpeed(10);  // Slow RPM (max reliable ~15)
}

void loop() {
  myStepper.step(stepsPerRevolution);  // Full clockwise rev
  delay(1000);
}
