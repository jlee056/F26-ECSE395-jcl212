#include <Arduino.h>

// jcl212 - A2-A4 are input only on the Feather V2, so A0/A1 are used
const int MOTOR_B_1A = 26; // jcl212 - A0 (GPIO 26) -> motor driver B-1A
const int MOTOR_B_1B = 25; // jcl212 - A1 (GPIO 25) -> motor driver B-1B


void setup() {

  pinMode(MOTOR_B_1A, OUTPUT);
  pinMode(MOTOR_B_1B, OUTPUT);

  // jcl212 - analogWrite changed from 255 to 150 (only buzzed), then 200 (spun slower)
  // jcl212 - swapped values to B_1A = 0, B_1B = 255 (spun the opposite direction)
  analogWrite(MOTOR_B_1A, 255);
  analogWrite(MOTOR_B_1B, 0);

  delay(2000); // jcl212 - changed from 5000 to 2000 (motor runs 2 s instead of 5 s)

  analogWrite(MOTOR_B_1A, 0);
  analogWrite(MOTOR_B_1B, 0);

}

void loop() {

}

// Note:
// - Please modify the `analogWrite()`, swap the `analogWrite()`, and modify the `delay()`.
// - You don't have to put anything in the loop.
//      - If you would like to run the code again, please press the `RESET BUTTON` on your ESP32.
