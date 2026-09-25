// jcl212 - Lab 5: Sensor + Actuator Integration
// jcl212 - Sensor: potentiometer module. Actuator: SG90 servo.
// jcl212 - Behavior: the servo arm follows the knob. Knob all the way one way = 0°,
// jcl212 - middle = 90°, all the way the other way = 180°.

#include <Arduino.h>     // jcl212 - core Arduino functions (analogRead, map, delay, Serial)
#include <ESP32Servo.h>  // jcl212 - servo library for the ESP32 (same one as Lab 4)


const int potPin = A1;    // jcl212 - A1 
const int servoPin = A0;  // jcl212 - A0 

const int minPulseWidth = 500;   // jcl212 - 0.5 ms pulse = 0°
const int maxPulseWidth = 2500;  // jcl212 - 2.5 ms pulse = 180°


const int adcMax = 4095;      // jcl212 - the ESP32 ADC is 12-bit, so analogRead() returns 0-4095
const int numSamples = 10;    // jcl212 - average 10 readings to smooth out ADC noise
const int deadband = 2;       // jcl212 - ignore angle changes of 2° or less so the servo doesn't jitter

Servo myServo;          // jcl212 - servo object that sends the PWM signal
int currentAngle = -1;  // jcl212 - last angle sent to the servo (-1 = nothing sent yet)

// jcl212 - reads the potentiometer several times and returns the average (0-4095)
int readPotAverage() {
  long total = 0;                        // jcl212 - long so the sum can't overflow
  for (int i = 0; i < numSamples; i++) {
    total += analogRead(potPin);         // jcl212 - add one raw reading
    delay(1);                            // jcl212 - short gap between readings
  }
  return total / numSamples;             // jcl212 - average of all the readings
}

void setup() {
  Serial.begin(115200);  // jcl212 - open the serial monitor so I can see the knob value and angle

  analogReadResolution(12);        // jcl212 - make sure the ADC uses the full 0-4095 range
  analogSetAttenuation(ADC_11db);  // jcl212 - lets the ADC read the full 0-3.3 V from the knob

  myServo.setPeriodHertz(50);                               // jcl212 - standard 50 Hz servo signal
  myServo.attach(servoPin, minPulseWidth, maxPulseWidth);   // jcl212 - connect the servo with the Lab 4 pulse range

  Serial.println("Lab 5: turn the potentiometer to move the servo");
}

void loop() {
  int potValue = readPotAverage();                 // jcl212 - smoothed knob position, 0-4095
  int angle = map(potValue, 0, adcMax, 0, 180);    // jcl212 - convert knob position to a servo angle, 0-180°
  angle = constrain(angle, 0, 180);                // jcl212 - keep the angle inside the servo's range

  // jcl212 - only move the servo when the knob actually moved (bigger than the deadband)
  if (currentAngle < 0 || abs(angle - currentAngle) > deadband) {
    int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);  // jcl212 - angle -> pulse width, like Lab 4
    myServo.writeMicroseconds(pulseWidth);                               // jcl212 - send the new position to the servo
    currentAngle = angle;                                                // jcl212 - remember where the servo is now

    // jcl212 - print what happened so it shows in the serial monitor
    Serial.print("Pot: ");
    Serial.print(potValue);
    Serial.print("  ->  Angle: ");
    Serial.println(angle);
  }

  delay(20);  // jcl212 - update about 50 times a second, same rate as the servo signal
}
