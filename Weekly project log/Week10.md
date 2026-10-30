# Week 10 - Project Log

### ECSE 395 - Jeremy Lee (`jcl212`)

---

## Individual Contributions

**October 26, 2026 - Prototypes 1-3 report draft**

I put together a six-page working draft using the course template and our midterm presentation. It uses Ethan's cardboard toilet and hinge sensor as Prototype 1 and George's TT motor and cardboard gear rig as Prototype 2. I added the photos from the presentation and linked the bench video from our team Drive. The video shows changing angle readings on the ESP32, but it does not show a known reference angle or a measured motor load. I left the missing angle readings, arm travel and force measurements open instead of treating the planned tests as results. A Word copy of the [working draft](https://docs.google.com/document/d/1Z_GboQBaFUtJPb2xV9vnJ8eD_EpJKHtC/edit) is in our team Drive.

**October 26, 2026 - Controller simulation for Prototype 3**

I made a Python model of the Done-to-close-to-flush sequence for the report. This changes Prototype 3 from the physical servo and cord test proposed in our midterm slides to a software test of the interlock. The model passed 12 scenarios, including an open lid, obstruction, lost sensor, repeated button press and power loss. It also passed 70 fixed-angle trials: 30 at or below the 5-degree closed threshold issued one flush command, and 40 above it issued none. A separate test with the interlock deliberately bypassed issued a command at 90 degrees, and our checker caught it. These are simulated commands. We still need to put the logic on the ESP32 and test the real lid and flush handle.

---

## Team Contributions

**October 26-28, 2026 - Midterm and prototype review**

Our [midterm deck](https://docs.google.com/presentation/d/1N78oqdyiMQT1wXguoCZQQTwq5jRmsxn2/edit) brings together the cardboard hinge model, George's motor rig, the proposed circuits and the flush-cord concept. The physical rig showed that the cardboard gear flexes or slips and that the arm needs an end-of-travel switch. We have CAD parts for a printed gear train in the [prototypes folder](https://drive.google.com/drive/folders/1jGhyndyPvaM5RpyDVNISRfBkG4XvvSwy). We have not recorded a successful printed-gear or real-toilet test yet. The hinge potentiometer is the current test setup; the gyroscope is still an open option. The deck also has conflicting 8:1 and 10.24:1 gear ratios, so we need to check the ratio against the parts we build.

---

## Next steps

- Record Prototype 1 readings at known lid angles, especially around the 5-degree closed threshold.
- Measure Prototype 2 arm travel, force, current and stopping behavior, and confirm the built gear ratio.
- Move the interlock from the software model to the ESP32, then test the Done button and flush actuator on hardware.
- Check whether the team submitted the prototype report and midterm materials on Canvas; the Drive files alone do not show submission.
- Update our Gantt chart for the November 2 MVP deadline and the remaining verification work.
