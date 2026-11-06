# Week 11 - Project Log

### ECSE 395 - Jeremy Lee (`jcl212`)

---

## Individual Contributions

**November 2, 2026 - MVP status report**

I wrote our MVP status report using the course template. It covers what we built, the feedback we used, what the core functions test, our biggest risks, next week's tests and who is doing what. I added George's photos of the printed gears, the slicer plate and the failed print, plus frames from our bench videos. The report says the gear train and the sensor board are still separate. It also says the ESP32 angle readout changes when the potentiometer turns, but we do not have a reference angle yet, so we have not measured sensor accuracy. I uploaded the [MVP report](https://drive.google.com/file/d/1gg9oyU70UCc0m-J1zx2NIQVq7yIOL0b5/view) and the three videos to the new [MVP folder](https://drive.google.com/drive/folders/1hI2HaToY0vsYn4bHoQkrP_bDqK_Fsddj) in our team Drive, and we submitted the report on Canvas.

**November 2, 2026 - Done button on the breadboard**

I built a breadboard version of the Done button to go with the controller model from Prototype 3. The plan is to run the interlock test on it next: press Done ten times at each lid angle, use an LED in place of the flush command, and count how many commands happen while the lid is open.

---

## Team Contributions

**October 30, 2026 - Class discussion**

In class on Friday we talked about using a laptop lid as a stand-in for the toilet lid, since it closes slowly like a soft-close lid. We also decided to combine the gear train and the sensor board on one mount once both parts work.

**November 2, 2026 - 3D print failure and MVP deadline**

George designed, printed and put together the printed gears and linkage, and recorded the videos. The print was left running during classes and failed about halfway. Filament spilled over the bed and several planned parts never printed, so the linkage in our videos is missing pieces. Ethan emailed Prof. Fu that night to ask for more time. Prof. Fu told us to submit a report on our current status with photos of the misprint, and said we can revise it within 7 days after the grade is released. Ethan also started looking at the gyroscope module as an option for the lid angle sensor.

---

## Next steps

- George: reprint the failed parts, confirm the gear ratio, add the end stop and mount the motor.
- Ethan: mount the angle sensor on a hinge, record readings at known angles and finish the gyroscope assessment.
- Jeremy: run the Done interlock test on the breadboard and record the results.
- Put the servo and cord on a real flush handle and measure how far the handle moves.
- Revise the MVP report with the new results once the grade is released.
