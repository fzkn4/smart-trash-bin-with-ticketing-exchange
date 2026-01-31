# Smart Trash Bin

Smart Trash Bin is a smart trash bin system that rewards users for properly disposing of their waste. When a user throws trash into the bin, the system detects it and dispenses a ticket that can be exchanged for rewards.

## How it Works

The system operates in a simple loop:

1.  **Trash Detection:** An ultrasonic sensor is placed at the top of the bin. It continuously measures the distance to the nearest object. When an item is thrown in, the distance reading decreases sharply.
2.  **Ticket Dispensing:** When the sensor detects an object within a 10cm range, it signals the microcontroller. The microcontroller then activates a stepper motor, which turns to dispense a paper ticket as a reward.

## Hardware Components

*   Arduino Uno (or any compatible board)
*   Ultrasonic Sensor (HC-SR04)
*   Stepper Motor (e.g., 28BYJ-48)
*   Stepper Motor Driver (e.g., ULN2003 module)

## Software

*   [Arduino IDE](https://www.arduino.cc/en/software)
*   **Libraries:**
    *   `Stepper.h` (comes standard with the Arduino IDE)

## Connections

The components are connected to the Arduino as follows:

### Ultrasonic Sensor (HC-SR04)

*   `VCC` -> `5V`
*   `GND` -> `GND`
*   `Trig Pin` -> `Digital Pin 7`
*   `Echo Pin` -> `Digital Pin 6`

### Stepper Motor Driver (ULN2003)

*   `IN1` -> `Digital Pin 8`
*   `IN2` -> `Digital Pin 9`
*   `IN3` -> `Digital Pin 10`
*   `IN4` -> `Digital Pin 11`
*   `+` -> `5V`
*   `-` -> `GND`

## Code Overview

The main logic is in the `ecopoints/ecopoints.ino` file.

*   The `setup()` function initializes the pins for the ultrasonic sensor and sets up the serial communication for debugging.
*   The `loop()` function continuously triggers the ultrasonic sensor to get a distance reading.
*   If the distance is 10cm or less, it's assumed that trash has been thrown in.
*   The `myStepper.step()` function is then called to rotate the stepper motor a full revolution, dispensing a ticket.
