# Week 2 — Project Log
### ECSE 395 — Jeremy Lee (`jcl212`)

**Project:** Reminding or automatically preventing people from flushing with the toilet lid open
**Team:** Jeremy Lee, Ethan Sloat, George Guaman

---

## Individual Contributions (Jeremy Lee)

**September 4, 2026 — Lab 2: learned the ESP32 toolchain**
Set up VS Code with the PlatformIO IDE extension and created a project for the Adafruit ESP32
Feather V2 on the Arduino framework. Starting from the course `Skeleton Code.md`, I filled in the
baud rate and serial output and then went past the base requirement: instead of a single blink, I
wrote a three-pattern light show (heartbeat, SOS in real Morse timing, and an accelerating strobe),
built on a reusable `flash(onTime, offTime)` helper with all timings pulled out into named
constants. Commented every change and marked each comment line with my CWRU ID.

**September 4, 2026 — Documented the lab**
Wrote `Lab 2/esp32_basics.md` covering the setup, the upload method, the steps I took, the
troubleshooting I hit (baud-rate mismatch between `platformio.ini` and `Serial.begin()`), and the
Part II reflection.

**September 4, 2026 — Relevance to the semester project**
Getting comfortable with the ESP32 matters directly for our toilet-lid project — whatever we build,
a microcontroller reading a sensor and driving an output is the core of it. Blinking an LED on a
timed pattern is the same shape of problem as driving a reminder indicator or an actuator once a
sensor fires.

**September 4, 2026 — Debugged the board connection**
Spent most of the lab getting the ESP32 to talk to my laptop. The first USB-C cable turned out to be
charge-only, so the board powered on but never enumerated as a serial device. After swapping to a
data cable it appeared, but uploads still failed because PlatformIO had auto-selected one of my
Mac's Bluetooth ports instead of the board. Selecting the correct `usbserial` port fixed it, and I
pinned the port in `platformio.ini` so it cannot happen again.

---

## Team Contributions (whole group)

**September 4, 2026 — Stakeholder has not responded yet**
We emailed our stakeholder during Week 1 to introduce the team and the project. As of this week we
have not heard back, so the need-finding interview has **not happened yet**.

**September 4, 2026 — Escalating to the teaching staff**
The instructors posted a Canvas announcement telling teams to come talk to them if their stakeholder
does not respond. We are following that: the team is meeting with the teaching staff to let them
know our stakeholder has not replied and to figure out next steps — either a follow-up to the same
stakeholder or being pointed toward a different one.

---

## Meeting Notes

**Date:** 9/4/26 · **Format:** in person

- Attendees: Jeremy Lee, Ethan Sloat, George Guaman
- Reviewed the status of the stakeholder email sent in Week 1 and still no response
- Read the Canvas announcement about unresponsive stakeholders
- Decided to raise it with the teaching staff rather than keep waiting

**Next steps:**
- Meet with the teaching staff about the unresponsive stakeholder
- Once a stakeholder is confirmed, schedule and run the need-finding interview
- Continue individual ESP32 practice so we are ready to prototype

---

## Need-Finding Interview Notes

The need-finding interview has **not been conducted yet**. Our stakeholder has not responded to the
introduction email we sent in Week 1. We are meeting with the teaching staff to resolve this, and
these notes will be filled in as soon as the interview is scheduled and completed.

---

## Summary

| | |
| --- | --- |
| **Worked on as a team** | Followed up on the unresponsive stakeholder and decided to escalate to the teaching staff per the Canvas announcement; need-finding interview still pending |
| **My individual contribution** | Completed Lab 2 end to end — ESP32 toolchain setup, custom multi-pattern blink code with commented modifications, and the `esp32_basics.md` write-up |
