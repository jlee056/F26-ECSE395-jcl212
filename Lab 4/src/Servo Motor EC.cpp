#include <ESP32Servo.h>

// jcl212 - Extra credit: accelerate and decelerate the servo instead of moving at a constant speed
Servo myServo;
const int servoPin = 26; // jcl212 - A0 (GPIO 26) -> servo orange signal wire

const int minPulseWidth = 500;  // 0.5 ms = 0 degrees
const int maxPulseWidth = 2500; // 2.5 ms = 180 degrees

const int STEPS = 150;     // jcl212 - number of small moves per sweep
const int STEP_DELAY = 10; // jcl212 - ms per step, so one sweep takes ~1.5 s

// jcl212 - moves from startAngle to endAngle using an ease-in/ease-out curve:
// jcl212 - eased = (1 - cos(pi * t)) / 2 starts slow, is fastest in the middle, and ends slow
void easeMove(int startAngle, int endAngle) {
  for (int i = 0; i <= STEPS; i++) {
    float t = (float)i / STEPS;                  // jcl212 - progress from 0.0 to 1.0
    float eased = (1.0 - cos(PI * t)) / 2.0;     // jcl212 - reshape progress so speed ramps up then down
    float angle = startAngle + (endAngle - startAngle) * eased;
    int pulseWidth = minPulseWidth + (int)((maxPulseWidth - minPulseWidth) * angle / 180.0); // jcl212 - same mapping as map(), but keeps the fraction
    myServo.writeMicroseconds(pulseWidth);
    delay(STEP_DELAY);
  }
}

void setup() {
  Serial.begin(115200); // jcl212 - serial output to follow the sweeps

  myServo.setPeriodHertz(50); // Standard 50Hz servo
  myServo.attach(servoPin, minPulseWidth, maxPulseWidth);
}

void loop() {
  Serial.println("Easing 0 -> 180");
  easeMove(0, 180);
  delay(500); // jcl212 - pause at the end so the slow-down is visible

  Serial.println("Easing 180 -> 0");
  easeMove(180, 0);
  delay(500);
}
