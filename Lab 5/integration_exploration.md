# Lab 5: Integration Exploration
Jeremy Lee (jcl212)

## Overview
This is my last assignment working with the ESP32. In this lab I integrated a sensor and an actuator into a small "smart system": a **potentiometer** (sensor) controls an **SG90 servo** (actuator).

**Desired behavior:** when I turn the potentiometer knob, the servo arm turns with it. The knob's position (0–4095 on the ESP32's 12-bit ADC) maps to a servo angle from 0° to 180°: knob all the way one way = 0°, the middle = 90°, all the way the other way = 180°. The servo only moves when the knob changes by more than 2°, so it holds still instead of jittering when the knob isn't being touched.

This combination is not one of the Sunfounder website projects listed in the handout (the only banned potentiometer pairing is potentiometer + I2C LCD 1602).

## What's in this folder
- `src/main.cpp` - the code that reads the potentiometer and moves the servo. Every line is commented.
- `platformio.ini` - board settings, the `ESP32Servo` library, and the serial monitor speed (115200)
- `photos/` - picture of my circuit
- `integration_exploration.md` - this write-up

## How I uploaded the code
**Tools used:** Windows PC, VS Code with the PlatformIO extension, Adafruit ESP32 Feather V2, USB-C data cable, the `ESP32Servo` library (`madhephaestus/ESP32Servo`).

**Upload process:**
1. Opened the `Lab 5` folder in VS Code with PlatformIO.
2. Plugged the ESP32 in with the USB-C data cable. It shows up as **COM7** on my PC (COM3–6 are Bluetooth ports).
3. Clicked **Build**, then **Upload** in the PlatformIO toolbar (or ran `pio run -t upload`). PlatformIO installs the `ESP32Servo` library automatically from `lib_deps`.
4. Opened the **Serial Monitor** at 115200 baud to watch the knob value and servo angle while turning the knob.

## Wiring
| Part | Wire | ESP32 pin |
|---|---|---|
| Potentiometer | VCC | 3V (3.3 V) |
| Potentiometer | GND | GND |
| Potentiometer | Signal (middle) | A1 (GPIO25) |
| Servo | Red (power) | USB (5 V) |
| Servo | Brown (ground) | GND |
| Servo | Orange (signal) | A0 (GPIO26) |

**How the circuit works:**
- The potentiometer is a voltage divider. Its outer pins go to 3.3 V and GND, so the middle (signal) pin outputs a voltage between 0 and 3.3 V depending on where the knob is turned. I powered it from **3.3 V, not 5 V**, because the ESP32's analog pins can only read up to 3.3 V.
- The signal goes to **A1 (GPIO25)**. A1 is an ADC2 pin, which can't read analog values while WiFi is on. This project doesn't use WiFi, so it reads normally.
- The servo is powered from the **USB pin (5 V)**, because the SG90 is a 5 V servo and draws more current than the 3.3 V pin should supply. Its signal wire is on **A0 (GPIO26)**, the same as Lab 4.
- **All grounds are connected together** (potentiometer GND, servo GND, ESP32 GND). Otherwise the servo signal and the analog reading have no common reference.

![Circuit](photos/circuit.jpg)

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
- Circuit picture: `photos/circuit.jpg`.
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

