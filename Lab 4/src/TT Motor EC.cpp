#include <Arduino.h>

// jcl212 - Extra credit: continuously speed the motor up and slow it down, in both directions
const int MOTOR_B_1A = 26; // jcl212 - A0 (GPIO 26) -> motor driver B-1A
const int MOTOR_B_1B = 25; // jcl212 - A1 (GPIO 25) -> motor driver B-1B

const int STEP_DELAY = 20; // jcl212 - ms between speed steps; 255 steps x 20 ms = ~5 s to ramp up

// jcl212 - ramps one input pin 0 -> 255 -> 0 while the other input is held at 0
void ramp(int drivePin, int groundPin) {
  analogWrite(groundPin, 0); // jcl212 - hold the other side low so current only flows one direction

  for (int speed = 0; speed <= 255; speed++) { // jcl212 - speed up
    analogWrite(drivePin, speed);
    delay(STEP_DELAY);
  }
  Serial.println("  full speed");

  for (int speed = 255; speed >= 0; speed--) { // jcl212 - slow down
    analogWrite(drivePin, speed);
    delay(STEP_DELAY);
  }
}

void setup() {
  Serial.begin(115200); // jcl212 - serial output to follow the ramps

  pinMode(MOTOR_B_1A, OUTPUT); // jcl212 - both driver inputs are outputs from the ESP32
  pinMode(MOTOR_B_1B, OUTPUT);
}

void loop() {
  Serial.println("Clockwise ramp");
  ramp(MOTOR_B_1B, MOTOR_B_1A); // jcl212 - B-1B carries the PWM = clockwise on my motor

  Serial.println("Stop");
  delay(1000); // jcl212 - short pause so the direction change is easy to see

  Serial.println("Counterclockwise ramp");
  ramp(MOTOR_B_1A, MOTOR_B_1B); // jcl212 - B-1A carries the PWM = counterclockwise

  Serial.println("Stop");
  delay(1000);
}
