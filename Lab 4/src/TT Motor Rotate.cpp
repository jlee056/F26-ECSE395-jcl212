#include <Arduino.h>

// jcl212 - Same wiring as TT Motor.cpp
const int MOTOR_B_1A = 26; // jcl212 - A0 (GPIO 26) -> motor driver B-1A
const int MOTOR_B_1B = 25; // jcl212 - A1 (GPIO 25) -> motor driver B-1B

void setup() {
  Serial.begin(115200); // jcl212 - start serial at the same baud rate as monitor_speed in platformio.ini

  pinMode(MOTOR_B_1A, OUTPUT); // jcl212 - B-1A drives the motor, so it is an output
  pinMode(MOTOR_B_1B, OUTPUT); // jcl212 - B-1B drives the motor, so it is an output

  Serial.println("TT Motor Rotate ready"); // jcl212 - confirms the board booted and setup finished
}

void loop() {
  // --- SECTION 1: Clockwise (5s) ---
  Serial.println("Clockwise"); // jcl212 - label the step in the serial monitor

  digitalWrite(MOTOR_B_1A, LOW);  // jcl212 - B-1A low...
  digitalWrite(MOTOR_B_1B, HIGH); // jcl212 - ...and B-1B high = clockwise on my motor (checked by watching the shaft)

  delay(5000); // jcl212 - keep spinning for 5 seconds

  // --- SECTION 2: Stop (2s) ---
  Serial.println("Stop"); // jcl212 - label the step in the serial monitor

  digitalWrite(MOTOR_B_1A, LOW); // jcl212 - both inputs low = no voltage across the motor
  digitalWrite(MOTOR_B_1B, LOW); // jcl212 - so the motor stops

  delay(2000); // jcl212 - stay stopped for 2 seconds

  // --- SECTION 3: Counterclockwise (5s) ---
  Serial.println("Counterclockwise"); // jcl212 - label the step in the serial monitor

  digitalWrite(MOTOR_B_1A, HIGH); // jcl212 - B-1A high...
  digitalWrite(MOTOR_B_1B, LOW);  // jcl212 - ...and B-1B low reverses the polarity = counterclockwise

  delay(5000); // jcl212 - keep spinning for 5 seconds

  // --- SECTION 4: Stop (2s) ---
  Serial.println("Stop"); // jcl212 - label the step in the serial monitor

  digitalWrite(MOTOR_B_1A, LOW); // jcl212 - both inputs low again
  digitalWrite(MOTOR_B_1B, LOW); // jcl212 - so the motor stops

  delay(2000); // jcl212 - stay stopped for 2 seconds, then loop() starts the sequence over
}
