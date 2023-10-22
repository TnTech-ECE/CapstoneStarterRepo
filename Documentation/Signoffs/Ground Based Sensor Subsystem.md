![Inductive Loop Sensor](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/142754780/b3bcd9b6-e894-4930-9a9d-33e58dc76d72)
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

![Inductive Loop Sensor](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/142754780/b3bcd9b6-e894-4930-9a9d-33e58dc76d72)
*Figure 1. Inductive Loop Sensor*



# Analysis

<table>
<tr><th>Table 1: DIP Switch </th><th>Table 2: Sensitivity</th><th>Table 3: DIP Switch Selection</th></tr>
<tr><td>
  
| Switch Label  | Use                                                                       |
|---------------|---------------------------------------------------------------------------|
| 1. FREQ 0     | Frequency Setting                                                         |
| 2. FREQ 1     | Frequency Setting                                                         |
| 3. FAIL MEM   | For Loop Failure for Output A                                             |
| 4. EXT PRES   | Extends Presence for Vehicles Parked on Loop                              |
| 5. RLY CNTL 1 | Output B Selection                                                        |
| 6. RLY CNTL 0 | Output B Selection                                                        |
| 7. BOOST      | Increases sensitivity of channel after initial detection                  |
| 8. EXT. 1     | Time Extension after Vehicle leaves Loop                                  |
| 9. EXT. 0     | Time Extension after Vehicle leaves Loop                                  |
| 10. 2 SEC DLY | Time added after vehicle arrives in loop but before Output A is activated |

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

| DIP Switch |                       | Frequency Rating           |
|------------|-----------------------|----------------------------|
| 1          | 2                     |                            |
| OFF        | OFF                   | High                       |
| OFF        | ON                    | Medium High                |
| ON         | OFF                   | Medium Low                 |
| ON         | ON                    | Low                        |
|            |                       |                            |
| DIP Switch |                       | Output B Mode of Operation |
| 5          | 6                     |                            |
| OFF        | OFF                   | True Presence              |
| OFF        | ON                    | Pulse on Entry             |
| ON         | OFF                   | Pulse on Exit              |
| ON         | ON                    | Fail                       |
|            |                       |                            |
| DIP Switch | Operation             |                            |
| 7          |                       |                            |
| OFF        | Sensitivity Boost Off |                            |
| ON         | Sensitivity Boost ON  |                            |
|            |                       |                            |
| DIP Switch |                       | Output A Extension Time    |
| 8          | 9                     |                            |
| OFF        | OFF                   | 0 seconds                  |
| OFF        | ON                    | 2 seconds                  |
| ON         | OFF                   | 5 seconds                  |
| ON         | ON                    | 10 seconds                 |
|            |                       |                            |
| DIP Switch | Operation             |                            |
| 10         |                       |                            |
| OFF        | 2 sec. delay disabled |                            |
| ON         | 2 sec. delay enabled  |                            |

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
| Diablo Controls Inc. DSP-15 Vehicle Detector | DSP-15-T | 4 | $85.69 | $342.76 |

# References
1. “Chapter 2, Traffic Detector Handbook: Third edition-volume I,” FHWA, https://www.fhwa.dot.gov/publications/research/operations/its/06108/02a.cfm (accessed Oct. 22, 2023).  
