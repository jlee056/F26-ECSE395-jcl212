# Lab 4: Actuator Adventures
Jeremy Lee (jcl212)

## Overview
This is my third assignment working with the ESP32. In this lab I connected actuators to the ESP32: a TT motor (DC gear motor) through a motor driver module, and a servo motor.

## What's in this folder
- `src/TT Motor.cpp` - runs the TT motor once (used to test `analogWrite()` and `delay()`)
- `src/TT Motor Rotate.cpp` - clockwise 5 s, stop 2 s, counterclockwise 5 s, stop 2 s, repeat
- `src/TT Motor EC.cpp` - extra credit: speeds the motor up and slows it down in both directions
- `src/Servo Motor.cpp` - sweeps the servo 0° to 180° and back (used to test the servo parameters)
- `src/Servo Motor Random.cpp` - moves the servo to random angles with random delays
- `src/Servo Motor EC.cpp` - extra credit: servo accelerates and decelerates instead of moving at a constant speed
- `platformio.ini` - one environment per sketch

## How I uploaded the code
**Tools used:** Windows PC, VS Code with the PlatformIO extension, Adafruit ESP32 Feather V2, USB-C data cable.

**Upload process:** Each `.cpp` file has its own `setup()` and `loop()`, so `platformio.ini` has one environment per file (`tt_motor`, `tt_rotate`, `tt_ec`, `servo`, `servo_random`, `servo_ec`). To run a file, pick its environment in the PlatformIO sidebar and click Upload, or run `pio run -e <environment> -t upload`. The servo code needs the `ESP32Servo` library, which is already listed in `lib_deps`.

## Wiring
- **TT motor:** motor wires → Motor B on the driver, driver VCC → USB (5 V), GND → GND, B-1A → A0, B-1B → A1
- **Servo:** brown → GND, red → USB (5 V), orange → A0

A2, A3, and A4 are input only on the Feather V2, so I used A0 and A1.

## Steps
### Setup & Preparation
1. Checked out the ESP32 and Sunfounder kit.
2. Opened the repository in VS Code with PlatformIO and set up one environment per sketch.

### In-Class Task: TT Motor
1. Wired the TT motor through the motor driver and set the pins in `TT Motor.cpp`.
2. Uploaded `TT Motor.cpp`, then changed `analogWrite()`, swapped the `analogWrite()` values, and changed `delay()`, one at a time.
3. Filled in `TT Motor Rotate.cpp` for the clockwise/stop/counterclockwise/stop loop and recorded a video.

### Post-Class Task: Servo Motor
1. Wired the servo and set the pin in `Servo Motor.cpp`.
2. Fixed the second `for` loop in `Servo Motor.cpp`. It used `angle <= 0`, so it never ran and the servo snapped back to 0° instead of sweeping. I changed it to `angle >= 0`.
3. Changed `minPulseWidth`, `maxPulseWidth`, `setPeriodHertz`, the rotation range, and `delay`, one at a time.
4. Filled in `Servo Motor Random.cpp` so the servo moves to a random angle (0–180°) and waits a random 0.3–1.5 s, then recorded a video.

### Extra Credit
- `TT Motor EC.cpp` ramps the PWM from 0 to 255 and back down, clockwise, then counterclockwise, in a loop.
- `Servo Motor EC.cpp` moves between 0° and 180° with an ease-in/ease-out curve, `(1 - cos(πt)) / 2`, so it starts slow, speeds up, and slows down before stopping.

### Documentation
Took 2 pictures (TT motor circuit and servo circuit) and 5 videos (TT motor rotate, TT motor extra credit, servo sweep, servo random, servo extra credit). The pictures and videos are submitted on Canvas.

## TT Motor Parameters
Original: `analogWrite(B_1A, 255)`, `analogWrite(B_1B, 0)`, `delay(5000)`. The motor spun fast for 5 s, then stopped.

| Change | What happened |
|---|---|
| `analogWrite(B_1A, 150)` | Only buzzed and didn't turn. The duty cycle was too low to get the motor moving. |
| `analogWrite(B_1A, 200)` | Spun, but slower than at 255. |
| Swapped: `B_1A = 0`, `B_1B = 255` | Spun in the opposite direction. |
| `delay(2000)` | Same speed, but stopped after 2 s instead of 5 s. |

## Servo Motor Parameters
Original: `minPulseWidth = 500`, `maxPulseWidth = 2500`, `setPeriodHertz(50)`, range 0–180°, `delay(15)`. The servo swept smoothly from 0° to 180° and back.

| Change | What happened |
|---|---|
| `minPulseWidth = 1000` | Moved slower. The swing got shorter, so it covered less distance in the same time. |
| `maxPulseWidth = 2000` | Moved slower. It stopped short of 180°. |
| `setPeriodHertz(200)` | Still swept, but buzzed a lot more. |
| Range 45–135° | Each sweep finished faster because it only moved 90°. |
| `delay(5)` | Swept about 3× faster. |

## Reflection
**1. How long did it take you to complete this assignment?**

About 4.5 hours.

**2. What level of difficulty would you associate with this assignment?**

- [ ] Low
- [x] Medium
- [ ] High

**3. If you associated medium/high difficulty with this assignment, what aspect did you find the most difficult?**

The wiring. The diagram uses a different ESP32 than the Feather, so I had to figure out which pins to use. My first wiring kept the ESP32 from booting, so the upload failed until I rewired it.

**4. How comfortable do you currently feel with the course content?**

Fairly comfortable. The code and uploading feel familiar now, but the hardware side is still new to me.

**5. Do you have any additional information or feedback you would like to share with the instructors?**

The second `for` loop in `Servo Motor.cpp` uses `angle <= 0`, so the servo never sweeps back. It should be `angle >= 0`.
