# Ground-Based Sensor Subsystem

The ground based sensor subsystem is to sense vehicles passing above the sensor, allowing for the system to keep a count of the
number of cars that are in a specified parking lot on the campus of Tennessee Tech.  This system will be placed at parking lots
that have specified entrances/exits.  By using lots that have this constraint, it will allow the system to keep an accurate count
of the number of cars in a specific lot.

# Constraints
| No. | Constraints | Origin |
| --- | ----------- | ------ |
| 1.  | Subsystem shall detect vehicles entering and exiting a parking lot. | System Requirements |
| 2.  | Vehicle detector shall cover a range of at least 50 &mu;H to 700 &mu;H. | NEMA Standards      |

1. The system will need to detect vehicles that are in the detection area of the loop for determining whether a vehicle is entering a lot or exiting a lot.  For the parking lot in the Engineering Quad on the campus of Tennessee Tech University, there are two entrances/exits to access the parking lot.  This will require two loops at each entrance/exit with a Diablo DSP-15 Vehicle Detector controlling each loop.  This will require two Diablo DSP-15 Detectors for each entrance/exit.  One loop will be near the road that is in front of Brown Hall and the other loop will be at the exit of the parking lot for the entrance/exit.  The output of each loop will be connected to a microcontroller that is part of the Data Transmission subsystem.
2. The vehicle detector system that will be used must be able to either manually tuned or automatically tuned to cover the given range of inductance values or greater [1].  When a vehicle passes over an inductive loop, the vehicle induces eddy currents in the loops.  The eddy currents then force the inductance of the loops to decrease, which leads to a change that is detected by the DSP-15 Vehicle Detector.  If inductance does not change, then a vehicle is not present within the detection range of the inductive loop.  Since frequency is dependent on the loop circuit inductance and inductance is the only value being regulated, frequency does not have to be within the range of 20 kHz to 100 kHz as the vehicle detector adjusts the frequency automatically while the inductance is affected by the design of the loop.

# Buildable Schematic

![Inductive Loop Sensor](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/142754780/1915837b-649b-414a-b374-d49a5c1f0bef)

*Figure 1. Inductive Loop Sensor*

![DSP-15 Vehicle Detector 1](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/142754780/fc92ad28-9006-4e59-bab0-3a26158a1364)

*Figure 2. Diablo DSP-15 Vehicle Detector 1*

![DSP-15 Vehicle Detector 2](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/142754780/b12bb8c3-8caa-413e-a4b9-6271cb82a5b5)

*Figure 3. Diablo DSP-15 Vehicle Detector 2*




# Analysis

<table>
<tr><th>Table 1: DIP Switch </th><th>Table 2: Sensitivity</th><th>Table 3: DIP Switch Selection</th></tr>
<tr><td>
  
| Switch Label | Use                   |
|--------------|-----------------------|
| 12           | Channel 1 Frequency   |
| 11           | Sensitivity 1 (High)  |
| 10           | Sensitivity 1 (Low)   |
| 9            | Pulse/Presence 1      |
| 8            | Channel 2 Frequency   |
| 7            | Sensitivity 2 (High)  |
| 6            | Sensitivity 2 (Low)   |
| 5            | Pulse/Presence 2      |
| 4            | Sensor Boost          |
| 3            | Fail Type             |
| 2            | Mode Selection (High) |
| 1            | Mode Selection (Low)  |

</td><td>

| Setting     | Sensitivity |
|-------------|-------------|
| 0           | .48% ∆L/L   |
| 1           | .32% ∆L/L   |
| 2           | .24% ∆L/L   |
| 3           | .16% ∆L/L   |
| 4           | .12% ∆L/L   |
| 5           | .08% ∆L/L   |
| 6           | .06% ∆L/L   |
| 7           | .04% ∆L/L   |
| 8           | .03% ∆L/L   |
| 9           | .02% ∆L/L   |

</td><td>

| DIP Switch                                              | Frequency Rating (Channel 1)       |                                   |       |                              |
|---------------------------------------------------------|------------------------------------|-----------------------------------|-------|------------------------------|
| 12                                                      |                                    |                                   |       |                              |
| OFF                                                     | Highest Loop Frequency Possible    |                                   |       |                              |
| ON                                                      | Lowest Loop Frequency Possible     |                                   |       |                              |
|                                                         |                                    |                                   |       |                              |
| DIP Switch                                              |                                    | Sensitivity Setting for Channel 1 | ∆L/L  | Counting Modes 1 and 3       |
| 11                                                      | 10                                 |                                   |       |                              |
| OFF                                                     | OFF                                | Low Sensitivity                   | 0.50% | Normal Vehicle Count Mode    |
| OFF                                                     | ON                                 | Medium Low Sensitivity            | 0.10% | Large Vehicle Count Mode     |
| ON                                                      | OFF                                | Medium High Sensitivity           | 0.05% | Unused (same as normal mode) |
| ON                                                      | ON                                 | High Sensitivity                  | 0.02% | Test Mode                    |
|                                                         |                                    |                                   |       |                              |
| DIP Switch 9 (Channel 1)                                | OFF                                | ON                                |       |                              |
| Detector Operating Mode                                 |                                    |                                   |       |                              |
| Mode 0 - Two Individual Channels with Pulse or Presence | Presence                           | Pulse on Entry                    |       |                              |
| Mode 1- Two Individual Channels with Count or Presence  | Presence                           | Count                             |       |                              |
| Mode 2- Two Paired Channels with Directional Logic      | Presence                           | Pulse on Entry                    |       |                              |
| Mode 3- Two Paired Channels with Directional Counting   | Count                              | Count                             |       |                              |
|                                                         |                                    |                                   |       |                              |
| DIP Switch                                              | Frequency Rating (Channel 2)       |                                   |       |                              |
| 8                                                       |                                    |                                   |       |                              |
| OFF                                                     | Highest Loop Frequency Possible    |                                   |       |                              |
| ON                                                      | Lowest Loop Frequency Possible     |                                   |       |                              |
|                                                         |                                    |                                   |       |                              |
| DIP Switch                                              |                                    | Sensitivity Setting for Channel 2 | ∆L/L  | Counting Modes 1 and 3       |
| 7                                                       | 6                                  |                                   |       |                              |
| OFF                                                     | OFF                                | Low Sensitivity                   | 0.50% | Normal Vehicle Count Mode    |
| OFF                                                     | ON                                 | Medium Low Sensitivity            | 0.10% | Large Vehicle Count Mode     |
| ON                                                      | OFF                                | Medium High Sensitivity           | 0.05% | Unused (same as normal mode) |
| ON                                                      | ON                                 | High Sensitivity                  | 0.02% | Test Mode                    |
|                                                         |                                    |                                   |       |                              |
| DIP Switch 5 (Channel 2)                                | OFF                                | ON                                |       |                              |
| Detector Operating Mode                                 |                                    |                                   |       |                              |
| Mode 0 - Two Individual Channels with Pulse or Presence | Presence                           | Pulse on Entry                    |       |                              |
| Mode 1- Two Individual Channels with Count or Presence  | Presence                           | Count                             |       |                              |
| Mode 2- Two Paired Channels with Directional Logic      | Presence                           | Pulse on Entry                    |       |                              |
| Mode 3- Two Paired Channels with Directional Counting   | Count                              | Count                             |       |                              |
|                                                         |                                    |                                   |       |                              |
| DIP Switch                                              | Sensitivity Boost                  |                                   |       |                              |
| 4                                                       |                                    |                                   |       |                              |
| OFF                                                     | Used for entire detection          |                                   |       |                              |
| ON                                                      | 2 seconds                          |                                   |       |                              |
|                                                         |                                    |                                   |       |                              |
| DIP Switch                                              | Fail Type (Only for Presence Mode) |                                   |       |                              |
| 3                                                       |                                    |                                   |       |                              |
| OFF                                                     | Fail Safe Mode is selected         |                                   |       |                              |
| ON                                                      | Fail Secure Mode is selected       |                                   |       |                              |
|                                                         |                                    |                                   |       |                              |
| DIP Switchs 2 and 1 (Channels 1 and 2)                  |                                    |                                   |       |                              |
| Detector Operating Mode                                 | Switch 2                           | Switch 1                          |       |                              |
| Mode 0 - Two Individual Channels with Pulse or Presence | OFF                                | OFF                               |       |                              |
| Mode 1- Two Individual Channels with Count or Presence  | OFF                                | ON                                |       |                              |
| Mode 2- Two Paired Channels with Directional Logic      | ON                                 | OFF                               |       |                              |
| Mode 3- Two Paired Channels with Directional Counting   | ON                                 | ON                                |       |                              |

</td></tr> </table>

<table>
<tr><th>Table 1: LED </th><th>Table 2: Green LED</th><th>Table 3: Red LED</th></tr>
<tr><td>

| Name        | Use        |
|-------------|------------|
| Green LED1  | Power LED  |
| Red LED2    | Detect LED |

</td><td>

| State                | Explanation                                                                                                                        |
|----------------------|------------------------------------------------------------------------------------------------------------------------------------|
| Off                  | Voltage applied to detector is less than 7.75 V. LED will be off                                                                   |
| Low Voltage          | Voltage applied to detector is less than proper operation of 10.25 V.  LED will blink for 50 msec. once every 2 seconds.           |
| Reset in Fail-Safe   | At start of reset event, LED turns off for 500 msec., on for 500 msec., off for 500 msec. and then display normal state.           |
| Reset in Fail-Secure | At start of reset event, LED turns off for 500 msec., on for 500 msec., off for 500 msec. and then display normal state.           |
| Open Loop            | When detector senses loop is open or inductance is too high, LED turns on for 500 msec. and off 500 msec. until fault is resolved. |
| Shorted Loop         | When detector senses loop is shorted or inductance is too low, LED turns on for 100 msec and off 100 msec. until fault is resolved |
| Large Change Fault   | When detector sensors loop is experiencing a large inductance change (greater than 30%), LED turns off for 100 msec., on for 100   |
|                      | msec.,  and then stay on for 500 msec. It will repeat this sequence until the fault is resolved.                                   |
| Prior Fault          | The detector has the ability to remember prior faults that have occurred from power interruption or reset of a function. The       |
|                      | LED will turn on for 1850 msec., off for 50 msec., on for 50 msec. off for 50 msec., and then repeat the sequence until power      |
|                      | is cycled or the detector has reset.                                                                                               |
| Normal               | LED is always on when the detector is in the normal state of operation.                                                            |

</td><td>

| RED LED2             |
|----------------------|
| (Will not be used as |
| it is for Output A   |
| only)                |

</td></tr> </table>





# BOM
| Part | Part Number | Quantity | Price Per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Diablo Controls Inc. DSP-21 Vehicle Detector | DSP-21-LV | 2 | $104.95 | $209.90 |
| Diablo 11 Pin Harness | CBL-005 | 2 | $10.92 | $21.84 |

# References
1. “Chapter 2, Traffic Detector Handbook: Third edition-volume I,” FHWA, https://www.fhwa.dot.gov/publications/research/operations/its/06108/02a.cfm (accessed Oct. 22, 2023).  
