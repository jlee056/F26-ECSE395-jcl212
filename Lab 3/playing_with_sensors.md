# Lab 3: Playing with Sensors
Jeremy Lee (jcl212)

## Objectives
- Read the analog voltage from a potentiometer with the ESP32 and print it to the serial monitor
- Use a touch sensor to print a message and turn on the onboard LED when it is touched

## Setup
- Mac, VS Code with the PlatformIO extension
- Adafruit Feather ESP32 V2 plugged in with a USB-C data cable
- Code is uploaded with PlatformIO 

## What's in this folder
- `src/potentiometer.cpp` - prints the raw potentiometer value (0-4095)
- `src/voltage.cpp` - converts the potentiometer reading to volts and prints it
- `src/touch.cpp` - prints "Touch detected!" / "No touch detected..." and turns the onboard LED on/off
- `src/main.cpp` - PlatformIO default file, commented out

## Wiring
- Potentiometer: VCC to 3V, GND to GND, signal to A0
- Touch sensor: VCC to 3V, GND to GND, SIG to A1

## How to run it
Only one file in `src` can be uncommented at a time because each one has its own `setup()` and `loop()`. Right now `touch.cpp` is the active one. To run a different file, comment out the others with `/* */`, uncomment the one you want, then build and upload. I added `monitor_speed = 115200` to `platformio.ini` so the serial monitor doesn't print random symbols.

## Reflection
**1. How long did it take you to complete this assignment?**

About 1 hour.

**2. What level of difficulty would you associate with this assignment?**

- [x] Low
- [ ] Medium
- [ ] High

**3. If you associated medium/high difficulty with this assignment, what aspect did you find the most difficult?**

N/A

**4. How comfortable do you currently feel with the course content?**

Very comfortable. I've worked with the ESP32 a lot, so the wiring and the code were pretty straightforward.

**5. Do you have any additional information or feedback you would like to share with the instructors?**

N/A
