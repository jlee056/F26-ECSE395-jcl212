/*
#include <Arduino.h>

// function prototype
float voltage(float analogvalue);

// jcl212 - potentiometer signal is wired to A0 (GPIO26)
const int sensorPin = A0;

void setup() {
    Serial.begin(115200);
}

void loop() {
    // jcl212 - read the potentiometer (0-4095) and store it in sensorValue instead of printing it right away
    int sensorValue = analogRead(sensorPin);
    // jcl212 - convert the stored reading to volts using (value * 3.3 V) / 4095
    float sensorVoltage = voltage(sensorValue);
    // jcl212 - print the potentiometer voltage to the serial monitor
    Serial.print("Voltage: ");
    Serial.print(sensorVoltage);
    Serial.println(" V");
    // jcl212 - wait 250 ms between readings (was 50 ms) so the numbers are easier to read
    delay(250);
}

// function to calculate output voltage
float voltage(float analogvalue){
    // jcl212 - 3.3 V is the reference voltage and 4095 is the max 12-bit reading
    return (analogvalue * 3.3) / 4095.0;
}
*/
