# Lab 5: Integration Exploration
Jeremy Lee (jcl212)

## Overview
This is my last assignment working with the ESP32. In this lab I integrated a sensor and an actuator into a small system of a **potentiometer** (sensor) controls an **SG90 servo** (actuator).

**Behavior:** when I turn the potentiometer knob, the servo arm turns with it. The knob's position maps to a servo angle from 0° to 180° (knob all the way one way = 0°, the middle = 90°, all the way the other way = 180) The servo only moves when the knob changes by more than 2°, so it holds still instead of jittering when the knob isn't being touched.

## What's in this folder
- `src/main.cpp` - the code that reads the potentiometer and moves the servo. Every line is commented.
- `platformio.ini` - board settings, the `ESP32Servo` library, and the serial monitor speed (115200)
- `integration_exploration.md` - this write-up

## Wiring
| Part | Wire | ESP32 pin |
|---|---|---|
| Potentiometer | VCC | 3V (3.3 V) |
| Potentiometer | GND | GND |
| Potentiometer | Signal (middle) | A1 (GPIO25) |
| Servo | Red (power) | USB (5 V) |
| Servo | Brown (ground) | GND |
| Servo | Orange (signal) | A0 (GPIO26) |

## Steps
### Setup & Preparation
1. **Sensor:** Potentiometer module (analog).
2. **Actuator:** SG90 servo (digital PWM).
3. Created this file and set up `platformio.ini` with the `ESP32Servo` library.

### In-Class Task
1. Wired the potentiometer and servo to the ESP32 as shown in the wiring table.
2. Wrote `main.cpp`, reusing my potentiometer reading from Lab 3 and my servo pulse settings (500–2500 µs, 50 Hz) from Lab 4.
3. **Code steps, in order:**
   - Read the knob 10 times and average the readings to smooth out ADC noise.
   - Use `map()` to convert the average (0–4095) to an angle (0–180°).
   - Convert the angle to a pulse width (500–2500 µs) and send it with `writeMicroseconds()`.
   - Skip the update when the angle changed by 2° or less, so the servo doesn't jitter.
   - Repeat every 20 ms.
4. Uploaded the code, turned the knob end to end, and checked in the Serial Monitor that the angle went from 0 to 180.

### Documentation
- Video of the knob moving the servo: posted as a comment on the Lab 5 Canvas assignment.

## How my system works
Turning the potentiometer changes the voltage on A1. The ESP32 reads that voltage as a number from 0 to 4095, converts it to an angle from 0 to 180°, and sends the servo the matching PWM pulse (0.5 ms = 0°, 2.5 ms = 180°). The servo arm follows the knob in real time, and the Serial Monitor prints the knob value and angle each time the servo moves.

**Proof:** picture of the setup above; video on Canvas.

## Reflection
**1. How long did it take you to complete this assignment?**

About 30 minutes.

**2. What level of difficulty would you associate with this assignment?**

- [x] Low
- [ ] Medium
- [ ] High

**3. If you associated medium/high difficulty with this assignment, what aspect did you find the most difficult?**

N/A. It was really easy because I already used the potentiometer in Lab 3 and the servo in Lab 4, so I just had to combine the two.

**4. How comfortable do you currently feel with the course content?**

Very comfortable. I have experience with both the potentiometer and the servo, and uploading to the ESP32 is routine now.

**5. Do you have any additional information or feedback you would like to share with the instructors?**

