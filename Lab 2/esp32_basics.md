# Lab 2: ESP32 Basics
### ECSE 395 — Junior Engineering Design Seminar

**Jeremy Lee** (`jcl212`) — September 4, 2026

---

## Overview

This is my first assignment working with the **ESP32**. For this lab I made the onboard LED
blink on my **Adafruit ESP32 Feather V2**, and I printed custom messages to the Serial Monitor
while it blinks.

Instead of a plain on/off blink, I wrote a small **light show** with three patterns that cycle:

1. **Heartbeat** — a double-thump pulse, like a heart monitor.
2. **SOS** — the letters S-O-S in real Morse code timing (dot = 150 ms, dash = 450 ms).
3. **Ramp strobe** — a strobe that accelerates from 200 ms down to 20 ms, then slows back down.

Each pattern prints its own message to the Serial Monitor right before it runs, so you can match
what you read to what the LED is doing.

---

## How I Uploaded the Code

I used **Visual Studio Code with the PlatformIO IDE extension** (not the Arduino IDE).
The board is connected to my laptop with a **USB-C data cable** (not a charge-only cable).

- **Build:** the checkmark (✓) in the blue status bar at the bottom of VS Code
- **Upload:** the right arrow (→) next to it
- **Serial Monitor:** the plug icon in the same status bar

---

## Steps I Took

1. Installed **VS Code** and the **PlatformIO IDE** extension (the ant head icon).
2. Opened PlatformIO Home and chose **New Project**:
   - **Project Name:** Blink Test
   - **Board:** Adafruit Feather ESP32 V2
   - **Framework:** Arduino
3. Opened `src/main.cpp` and started from the **Skeleton Code.md** in the Lab 2 folder of the repo
   I cloned during Lab 1.
4. Filled in the TODOs in the skeleton:
   - Set the baud rate to **115200** with `Serial.begin(BAUD_RATE)`.
   - Replaced the placeholder `Serial.println("_____")` with my own custom messages.
   - Replaced the single `delay(_____)` pair with my three-pattern light show.
5. Pulled the repeated on/off logic into a helper function, `flash(onTime, offTime)`, and built each
   pattern out of it, so the timing is easy to retune from the `#define` constants at the top.
6. Commented every change and marked each comment line with my CWRU ID, `jcl212`.
7. Added `monitor_speed = 115200` to `platformio.ini` so the Serial Monitor matches the baud rate in
   my code — without this the output comes out as garbage characters.
8. Built the project, then uploaded it to the board.
9. Opened the Serial Monitor and confirmed my messages printed in sync with the LED patterns.
10. Demoed the working board to the teaching staff, recorded a video of it running, and pushed the
    code, the video, and this file to my GitHub repo.

### Troubleshooting notes

- If the Serial Monitor shows strange symbols, the baud rate in `platformio.ini` does not match
  `Serial.begin()` in the code. Both need to be **115200**.
- If the monitor does not update, close the previous Serial Monitor first — only one can be attached
  to the port at a time.
- If the upload fails with `A fatal error occurred: Failed to connect to ESP32: Timed out...`, hold
  the **BOOT** button, click Upload, and release BOOT once `Connecting...` appears in the terminal.

---

## Part II: Time Reporting and Reflection

**1. How long did it take you to complete this assignment?**

About 1 hour and 30 minutes. Most of that was installing VS Code and PlatformIO and waiting on the
first build, since PlatformIO downloads the whole ESP32 toolchain the first time. Writing and tuning
the light show itself took maybe 30 minutes.

**2. What level of difficulty would you associate with this assignment? (Low, Medium, High)**

- [ ] Low
- [x] Medium
- [ ] High

**3. If you associated medium/high difficulty with this assignment, what aspect did you find the most difficult?**

The code itself was straightforward, but the setup was where I spent the most time. The one thing
that actually tripped me up was the Serial Monitor printing garbage characters — it took me a minute
to realize the baud rate in `platformio.ini` has to match the one in `Serial.begin()`. Getting the
Morse timing to look right also took a few passes of building and re-uploading, since 3 seconds of
blinking looks a lot different on the board than it does in the code.

**4. How comfortable do you currently feel with the course content?**

Comfortable. I have programming experience, so the C++ side felt familiar, and the hardware side is
new but approachable. I would like more practice with the other pins and peripherals on the board
before we start building the semester project.

**5. Do you have any additional information or feedback you would like to share with the instructors?**

The quick start video was helpful. It might be worth calling out the `monitor_speed` line in
`platformio.ini` earlier in the instructions rather than in the troubleshooting section, since I
think most people will hit that one.
