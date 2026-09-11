#include <Arduino.h>

// jcl212 - touch sensor SIG is wired to A1 (GPIO25)
const int sensorPin = A1;
// jcl212 - define the builtin LED, which is on pin 13 on the Feather ESP32 V2
const int ledPin = 13;

void setup() {
  pinMode(sensorPin, INPUT);  // Set the sensor pin as input
  pinMode(ledPin, OUTPUT);    // jcl212 - set the LED pin as an output so the code can turn it on and off
  Serial.begin(115200);
}

void loop() {
  if (digitalRead(sensorPin) == 1) {
    Serial.println("Touch detected!");
    digitalWrite(ledPin, HIGH);  // jcl212 - turn the builtin LED on while the sensor is being touched
  } else {
    Serial.println("No touch detected...");
    digitalWrite(ledPin, LOW);   // jcl212 - turn the builtin LED off when nothing is touching the sensor
  }
  delay(100);  // jcl212 - check the sensor every 100 ms
}
