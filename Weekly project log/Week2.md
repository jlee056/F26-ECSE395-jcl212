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

**September 4, 2026 — Need-finding interview with our stakeholder**
We ran our first need-finding interview with our stakeholder, Samuel Levacy, over Zoom from roughly
5:01 to 5:19 PM. George coordinated the scheduling and took the minutes; all three of us attended and
asked questions. We deliberately kept the conversation on the problem and away from solutions.

**September 4, 2026 — The interview changed how we understand the problem**
We went in thinking the problem was people *forgetting* to close the toilet lid before flushing. That
is not what our stakeholder described. He is not looking for a reminder — he wants the lid to close
and the toilet to flush **on its own**, without him doing anything. The two roots underneath that are
**sanitation** and **convenience**. His current soft-closing lid actually works against the
convenience side, because he has to wait for it to finish closing before he can flush.

**September 4, 2026 — Confirmed the problem statement in writing**
I drafted and sent a follow-up email restating our understanding of the problem back to the
stakeholder and asking him to correct anything we had misread, so that we would not carry a wrong
assumption into the design work. He replied the same evening confirming that our restatement
"clarifies the problem statement well." He also agreed to our proposed second meeting on
**Monday, September 21, 6:00–7:00 PM Eastern**, which George will send a Zoom link for.

---

## Meeting Notes

**Date:** 9/4/26 · **Format:** Zoom (stakeholder interview) + team debrief

- Attendees: Jeremy Lee, Ethan Sloat, George Guaman, Samuel Levacy (stakeholder)
- Ran the first need-finding interview (~18 minutes)
- Agreed during the interview to steer away from proposing solutions
- Debriefed and identified the two underlying roots: sanitation and convenience
- Listed potential obstacles for any future concept: two people in the bathroom at once, shower
  steam, the cat, someone flushing while the lid is still closing, and cleaning the toilet
- Agreed to send a written restatement of the problem to the stakeholder for confirmation
- Proposed and confirmed a second interview for Monday, September 21, 6:00–7:00 PM Eastern

**Next steps:**
- Build the affinity cluster board in Figma from the interview data
- Prepare questions for the September 21 interview to collect the additional detail we still need
- Draft the needs statement and personas for the Project Background assignment
- Continue individual ESP32 practice so we are ready to prototype

---

## Need-Finding Interview Notes

**Stakeholder:** Samuel Levacy · **Date:** 9/4/26 · **Duration:** ~18 min · **Format:** Zoom

**Context**
- He has two bathrooms; he mainly uses one, and the other holds the cat's litter box.
- He has one cat.
- The lights in the bathroom already turn on every time it is used.
- He sometimes uses the bathroom without using the toilet.
- His toilet already has a soft-closing lid.

**The problem in his words**
- He forgets to close the toilet cover before flushing.
- His friend's wife always says to shut the toilet bowl before flushing.
- He raised sanitary concerns as the reason it matters.
- Guests are important to him. He framed it as a household standard.
- The soft-closing lid is slow, and waiting for it before flushing is annoying.
- He said the problem is not so much about not forgetting, he wants an auto-flush function.
- He said the toilet has to close and flush on its own.
- He mentioned the idea of not being able to flush until the lid is closed.

**Concerns and edge cases raised**
- Flushing the toilet without leaving the room, for example before showering.
- Two people in the bathroom at once potentially confusing any sensing.
- Steam from the shower interfering with sensing.
- The cat interfering with sensing.
- Someone trying to flush while the lid is still closing.
- Cleaning the toilet.

**Scheduling**
- 6:00–7:00 PM slots, Monday through Thursday, work best for him.

**Conclusion given to the stakeholder**
The underlying roots of the problem are sanitary concerns and convenience, and we will aim our
concepts at those two issues. He confirmed this in writing by email the same evening.

---

## Summary

| | |
| --- | --- |
| **Worked on as a team** | Ran our first need-finding interview with our stakeholder, reframed the problem from "forgetting to close the lid" to "wanting the lid to close and the toilet to flush automatically," identified sanitation and convenience as the two roots, confirmed that framing with the stakeholder in writing, and scheduled a second interview for September 21 |
| **My individual contribution** | Completed Lab 2 end to end — ESP32 toolchain setup, custom multi-pattern blink code with commented modifications, and the `esp32_basics.md` write-up; also drafted and sent the follow-up email that got our problem statement confirmed by the stakeholder |
