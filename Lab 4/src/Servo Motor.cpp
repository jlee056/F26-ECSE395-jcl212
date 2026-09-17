#include <ESP32Servo.h>

Servo myServo;
const int servoPin = 26; // jcl212 - A0 (GPIO 26) -> servo signal (orange)

// Define the minimum and maximum pulse widths for the servo
// jcl212 - values I tested one at a time, then set back:
// jcl212 -   minPulseWidth 500 -> 1000: shorter swing, looked slower
// jcl212 -   maxPulseWidth 2500 -> 2000: stopped short of 180, looked slower
// jcl212 -   setPeriodHertz 50 -> 200: servo buzzed more
// jcl212 -   rotation range 0-180 -> 45-135: sweep finished faster
// jcl212 -   delay 15 -> 5: sweep about 3x faster
const int minPulseWidth = 500; // 0.5 ms
const int maxPulseWidth = 2500; // 2.5 ms

void setup() {
  // Attach the servo to the specified pin and set its pulse width range
  myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

  // Set the PWM frequency for the servo
  myServo.setPeriodHertz(50); // Standard 50Hz servo
}

void loop() {
  // Rotate the servo from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    int pulseWidth;
    // the map function is a puction that maps 0 degrees to 500 pulse width, and 180 degrees to 2500 pulse width
    pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
    myServo.writeMicroseconds(pulseWidth);
    delay(10); // jcl212 - my preferred delay, changed from 15
  }

  // Rotate the servo from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) { // jcl212 - fixed: was `angle <= 0`, so this loop never ran
    int pulseWidth;
    // the map function is a puction that maps 0 degrees to 500 pulse width, and 180 degrees to 2500 pulse width
    pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
    myServo.writeMicroseconds(pulseWidth);
    delay(10); // jcl212 - my preferred delay, changed from 15
  }
}
