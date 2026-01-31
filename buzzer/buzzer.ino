const int buzzer = 5;  // Buzzer on pin 9
const int GREEN_LED_PIN = 4; // Green LED on pin 10
const int RED_LED_PIN = 3;   // Red LED on pin 11

const int SUCCESS_TONE_FREQ = 2000; // Frequency for success tone (e.g., 2000 Hz)
const int FAILED_TONE_FREQ = 500;   // Frequency for failed tone (e.g., 500 Hz)
const int TONE_DURATION = 1000;    // Duration for each tone (1000 milliseconds = 1 second)

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  // Play success tone and light green LED for 1 second
  digitalWrite(GREEN_LED_PIN, HIGH);
  tone(buzzer, SUCCESS_TONE_FREQ);
  delay(TONE_DURATION);
  digitalWrite(GREEN_LED_PIN, LOW);
  noTone(buzzer); // Stop tone before the next sequence


  // Play failed tone and light red LED for 1 second
  digitalWrite(RED_LED_PIN, HIGH);
  tone(buzzer, FAILED_TONE_FREQ);
  delay(TONE_DURATION);
  digitalWrite(RED_LED_PIN, LOW);
  noTone(buzzer); // Stop tone before the loop repeats
}
