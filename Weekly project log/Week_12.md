# Week 12 - Project Log

### ECSE 395 - Jeremy Lee (`jcl212`)

---

## Individual Contributions

**November 10, 2026 - Start Validation Testing report**

I wrote our Start Validation Testing report from the course template. It has the raw data, the validation protocol (study goal, participants, procedure, measures, lessons learned and changes for the next iteration) and the evidence of testing. I added frames from the two test videos as figures. The report does not analyze the data yet, because the assignment only asks for the raw data and the protocol. I uploaded the report to the new `08 Start Validation Testing` folder in our team Drive, and the team added their own edits to it the same night.

**November 10, 2026 - Team Drive cleanup**

I moved the 12 loose files in the team Drive root into the numbered folders, so the Gantt chart, the midterm decks, the prototype drafts and the needfinding files each have a place. This makes the videos and reports easier to find when we write the final report.

---

## Team Contributions

**November 9, 2026 - First validation session**

Two of us tested in the lab around 8:15 PM and 8:34 PM, and George recorded two phone videos. The ESP32 printed the lid angle on the laptop while the stand-in lid moved. The state machine moved between idle, closing, retracting and flushing along with the angle, and the idle state waited for both the angle and the button press. We used the clear case from an Arduino starter kit as the lid.

In the second video, a teammate acted as a user whose cat jumps into the toilet and blocked the lid with a hand. The system detected the obstruction, stopped the motor and went into an error state that needs the user to restart it. The teammate did not feel extra force from the gear train. We have no reference angle yet, so apart from the fully open and fully closed positions we cannot report sensor accuracy. The Done button was not part of this session.

**November 10, 2026 - Next iteration plan**

From the first session we decided to save the serial output to a timestamped text file, put a protractor or marked reference angle in the frame, add the flush LED, tape the gyroscope sensor to the lid, and test with people outside the team.

**November 13, 2026 - Week 12 check-in plan**

For the design review of our data analysis, we decided to recruit a control group and start testing so we have actual data beyond what the serial monitor shows.

---

## Next steps

- Get a control group and start testing, so we collect actual data and do not rely only on the serial monitor and the videos.
- Save the serial angle readings to a timestamped file so we have real data to analyze for the data analysis milestone.
- Record readings at known reference angles and compare them with the sensor.
- Run the Done interlock test and add the flush LED.
- Test with volunteers outside the team after we confirm what approval we need.
- Update the Gantt chart with the validation and data analysis dates.
- Revise the MVP report once the grade is released.
