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

![DSP-21 Vehicle Detector with 11 Pin Harness](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/142754780/6271e60c-188e-4550-a5a0-9ff182f9266d)



*Figure 1. Diablo DSP-21 Vehicle Detector with 11 Pin Harness*

![Inductive Loop Sensor 1](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/142754780/59442aa9-2150-4ff3-840f-0d66d5555b7b)

*Figure 2. Inductive Loop Sensor 1*

![Inductive Loop Sensor 2](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/142754780/98be6172-899d-4e54-b7ec-4ad343396091)

*Figure 3. Inductive Loop Sensor 2*

<table>
<tr><th>Table 1: DIP Switch </th><th>Table 2: DIP Switch Selection (Ch.1) </th><th> Table 3: DIP Switch Selection (Ch.2) </th><th> Table 4: DIP Switch Selection (Operation) </th></tr>
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

| Channel 1                                               |                                 |                                   |       |                              |
|---------------------------------------------------------|---------------------------------|-----------------------------------|-------|------------------------------|
| DIP Switch                                              | Frequency Rating (Channel 1)    |                                   |       |                              |
| 12                                                      |                                 |                                   |       |                              |
| OFF                                                     | Highest Loop Frequency Possible |                                   |       |                              |
| ON                                                      | Lowest Loop Frequency Possible  |                                   |       |                              |
|                                                         |                                 |                                   |       |                              |
| DIP Switch                                              |                                 | Sensitivity Setting for Channel 1 | ∆L/L  | Counting Modes 1 and 3       |
| 11                                                      | 10                              |                                   |       |                              |
| OFF                                                     | OFF                             | Low Sensitivity                   | 0.50% | Normal Vehicle Count Mode    |
| OFF                                                     | ON                              | Medium Low Sensitivity            | 0.10% | Large Vehicle Count Mode     |
| ON                                                      | OFF                             | Medium High Sensitivity           | 0.05% | Unused (same as normal mode) |
| ON                                                      | ON                              | High Sensitivity                  | 0.02% | Test Mode                    |
|                                                         |                                 |                                   |       |                              |
| DIP Switch 9 (Channel 1)                                | OFF                             | ON                                |       |                              |
| Detector Operating Mode                                 |                                 |                                   |       |                              |
| Mode 0 - Two Individual Channels with Pulse or Presence | Presence                        | Pulse on Entry                    |       |                              |
| Mode 1- Two Individual Channels with Count or Presence  | Presence                        | Count                             |       |                              |
| Mode 2- Two Paired Channels with Directional Logic      | Presence                        | Pulse on Entry                    |       |                              |
| Mode 3- Two Paired Channels with Directional Counting   | Count                           | Count                             |       |                              |

</td><td>

| Channel 2                                               |                                 |                                   |       |                              |
|---------------------------------------------------------|---------------------------------|-----------------------------------|-------|------------------------------|
| DIP Switch                                              | Frequency Rating (Channel 2)    |                                   |       |                              |
| 8                                                       |                                 |                                   |       |                              |
| OFF                                                     | Highest Loop Frequency Possible |                                   |       |                              |
| ON                                                      | Lowest Loop Frequency Possible  |                                   |       |                              |
|                                                         |                                 |                                   |       |                              |
| DIP Switch                                              |                                 | Sensitivity Setting for Channel 2 | ∆L/L  | Counting Modes 1 and 3       |
| 7                                                       | 6                               |                                   |       |                              |
| OFF                                                     | OFF                             | Low Sensitivity                   | 0.50% | Normal Vehicle Count Mode    |
| OFF                                                     | ON                              | Medium Low Sensitivity            | 0.10% | Large Vehicle Count Mode     |
| ON                                                      | OFF                             | Medium High Sensitivity           | 0.05% | Unused (same as normal mode) |
| ON                                                      | ON                              | High Sensitivity                  | 0.02% | Test Mode                    |
|                                                         |                                 |                                   |       |                              |
| DIP Switch 5 (Channel 2)                                | OFF                             | ON                                |       |                              |
| Detector Operating Mode                                 |                                 |                                   |       |                              |
| Mode 0 - Two Individual Channels with Pulse or Presence | Presence                        | Pulse on Entry                    |       |                              |
| Mode 1- Two Individual Channels with Count or Presence  | Presence                        | Count                             |       |                              |
| Mode 2- Two Paired Channels with Directional Logic      | Presence                        | Pulse on Entry                    |       |                              |
| Mode 3- Two Paired Channels with Directional Counting   | Count                           | Count                             |       |                              |

</td><td>

| Detector Operation                                      |                                    |          |
|---------------------------------------------------------|------------------------------------|----------|
| DIP Switch                                              | Sensitivity Boost                  |          |
| 4                                                       |                                    |          |
| OFF                                                     | Used for entire detection          |          |
| ON                                                      | 2 seconds                          |          |
|                                                         |                                    |          |
| DIP Switch                                              | Fail Type (Only for Presence Mode) |          |
| 3                                                       |                                    |          |
| OFF                                                     | Fail Safe Mode is selected         |          |
| ON                                                      | Fail Secure Mode is selected       |          |
|                                                         |                                    |          |
| DIP Switchs 2 and 1 (Channels 1 and 2)                  |                                    |          |
| Detector Operating Mode                                 | Switch 2                           | Switch 1 |
| Mode 0 - Two Individual Channels with Pulse or Presence | OFF                                | OFF      |
| Mode 1- Two Individual Channels with Count or Presence  | OFF                                | ON       |
| Mode 2- Two Paired Channels with Directional Logic      | ON                                 | OFF      |
| Mode 3- Two Paired Channels with Directional Counting   | ON                                 | ON       |

</td></tr> </table>

<table>
<tr><th>Table 1: LED </th><th>Table 2: Green LED1</th><th>Table 3: Red LED2</th><th>Table 4: Red LED3</th></tr>
<tr><td>

| Name        | Use      |
|-------------|----------|
| Green LED1  | Power    |
| Red LED2    | Detect A |
| RED LED3    | Detect B |

</td><td>

| State       | Explanation                                                                                     |
|-------------|-------------------------------------------------------------------------------------------------|
| Off         | Voltage applied to detector is less than 3.5 V. LED will be off                                 |
| Low Voltage | LED will flash once per second with 500 ms on and 500 ms off.  Relay outputs will not function. |
| Reset       | LED will turn off for 500 ms, on for 1 second, off for 500 ms, before returning to normal.      |
| Normal      | LED is always on during normal operation.                                                       |

</td><td>

| RED LED2     |                                                                                                                                                                                                                                                                                                                           |
|--------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| State        | Explanation                                                                                                                                                                                                                                                                                                               |
| Open Loop    | When loop is open or inductance is too high, LED will turn on for 500 ms and then off for 500 ms during the fault. If fault is fixed, it will display the Prior Fault light sequence.                                                                                                                                     |
| Shorted Loop | When loop is shorted or inductance is too low, LED will turn on for 100 ms, then off for 100 ms during the fault. If fault is fixed, it will display the Prior Fault light sequence.                                                                                                                                      |
| Large Change | When detector senses an inductance change of more than 12.5%, LED will turn on for 500 ms, off for 100 ms, on for 100 ms, off for 100 ms, on for 100 ms, off for 100 ms, and then repeat the sequence during the fault. If fault is fixed, it will display the Prior Fault light sequence.                                |
| Prior Fault  | The detector is able to remember faults that have occurred since the last power loss or reset.  LED will turn on for 100 ms, off for 100 ms, on for 100 ms, off for 1700 ms, and repeat sequence until power is cycled, detector is reset, or channel is reset.  This sequence is only displayed when loop is unoccupied. |
| Reset        | When detector or channel is reset, LED will turn off for 500 ms, on for 1000 ms, off for 500 ms, and then resume normal display.                                                                                                                                                                                          |
| Occupancy    | When channel is occupied by a vehicle, the LED will dim itself and LED will be flashing at a very fast rate that will be seen as a LED flickering.                                                                                                                                                                        |

</td><td>

| RED LED3     |                                                                                                                                                                                                                                                                                                                           |
|--------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| State        | Explanation                                                                                                                                                                                                                                                                                                               |
| Open Loop    | When loop is open or inductance is too high, LED will turn on for 500 ms and then off for 500 ms during the fault. If fault is fixed, it will display the Prior Fault light sequence.                                                                                                                                     |
| Shorted Loop | When loop is shorted or inductance is too low, LED will turn on for 100 ms, then off for 100 ms during the fault. If fault is fixed, it will display the Prior Fault light sequence.                                                                                                                                      |
| Large Change | When detector senses an inductance change of more than 12.5%, LED will turn on for 500 ms, off for 100 ms, on for 100 ms, off for 100 ms, on for 100 ms, off for 100 ms, and then repeat the sequence during the fault. If fault is fixed, it will display the Prior Fault light sequence.                                |
| Prior Fault  | The detector is able to remember faults that have occurred since the last power loss or reset.  LED will turn on for 100 ms, off for 100 ms, on for 100 ms, off for 1700 ms, and repeat sequence until power is cycled, detector is reset, or channel is reset.  This sequence is only displayed when loop is unoccupied. |
| Reset        | When detector or channel is reset, LED will turn off for 500 ms, on for 1000 ms, off for 500 ms, and then resume normal display.                                                                                                                                                                                          |
| Occupancy    | When channel is occupied by a vehicle, the LED will dim itself and LED will be flashing at a very fast rate that will be seen as a LED flickering.                                                                                                                                                                        |

</td></tr> </table>



# Analysis

## Power

The subsystem will be powered through the 11 Pin Harness connection found in Figure 1.  The recommended input voltage and current for the detector is 10.5 VDC to 35 VDC with 25 mA to 120 mA<sup>2</sup>.  Since the loops are connected directly to the vehicle detector unit, the loops will receive the necessary power through the detector.  The power through the loops will depend on the selections made using the on-board DIP switch with the provided table in both the user manual and the tables found under the Buildable Schematics section.  To ensure that the input power source is safely connected to the loops, size 14 AWG wire will be used to connect the loops to the detector.  Not only will the wire size be suitable for the amount of current in the wire<sup>2</sup>, but it will also provide extra protection for the wire as it is large enough that it is capable of tolerating a small amount of weight.  For the 11 Pin Harness Connector, the current flow is also small enough for 20 AWG wire to be used for the 11 Pin connection.  As the connections to the ESP32 Microcontroller GPIO pins are capable of handling a maximum of 20 mA of current, the input current to the GPIO pins will not exceed more than the rated maximum current.

## Vehicle Detection

The Diablo DSP-21 Vehicle Detector is capable of detecting vehicles through an inductive loop by sending pulses through the loop.  The pulse output has a 300 millisecond (ms) period ± 10 ms with 150 ms ± 10 ms on and 150 ms ± 10 ms off before the next pulse is sent through the loops.  The response time for the detector is 150 ms ± 25 ms and can hold a vehicle for up to one hour in the loop and still detect the vehicle<sup>2</sup>.

## Inductive Loop Detection Range

For the loop to work correctly with the Diablo DSP-21 Vehicle Detector, the loop has to fit both the size requirements for the detector while also being a reasonable size to detect vehicles entering the Engineering Quad parking lot.  According to the Loop Size chart, using a 4 ft. by 6 ft. size inductive loop with 4 turns will provide an inductance value of 100 &mu;H with a detection height of 3.2 ft (approximately 38" height)<sup>3</sup>.  This size works well for the two entrances/exits of the Engineering Quad as it will be wide enough to detect vehicles that pass by it or pass over the loop in both lanes of traffic and long enough to be detected by the loop.  To ensure the detector would work function and count properly, both the loop inductance and lead-in inductance must be greater than or equal to a ratio of 2:1.  To calculate the loop inductance, the loop inductance formula must be used:

```math
L = (P/4) * (N + N^2);
```
where L = Loop Inductance in &mu;H
      P = Perimeter of loop in ft.
      N = Number of turns in the loop

For the lead-in loop inductance, the base value of 0.22 &mu;H/ft is used.  After calculating both the loop inductance value (100 &mu;H) and lead-in inductance value (5.5 &mu;H), the ratio is 18.2:1 which is greater than the ratio value of 2:1.  

## 11 Pin Harness

For the detector to work with the inductive loops, the detector will use an 11 Pin Harness to connect the output pins from the back side of the detector to the necessary connections.  This system will use a 15 VDC, 50 mA power supply with the positive connected to Pin 1 and negative to Pin 2.  Loop 1 (Channel 1) will be connected to Pins 7 and 8 while Loop 2 (Channel 2) will be connected to Pins 9 and 10 according to both the schematic drawing and the user manual of the Diablo DSP-21 Vehicle Detector.  To detect when a vehicle is present over one or both of the loops, the common pins of both Channels 1 and 2 will be connected, in parallel, to the 3V3 pin of the ESP32 MCU.  The normally open contact for Channel 1 will be connected to Pin VP of the ESP32 Microcontroller to detect a closed contact when Loop 1 detects a vehicle and the normally open contact for Channel 2 will be connected to Pin VN of the ESP32 Microcontroller to detect a closed contact when Loop 2 detects a vehicle.  To securely connect the harness connections to pins of the ESP32 Microcontroller, it will require specific connection ends to the wires to properly fit while also alerting the MCU of when a vehicle is present in either one or both of the loops.

# BOM
| Part | Part Number | Quantity | Price Per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Diablo Controls Inc. DSP-21 Vehicle Detector | DSP-21-LV | 2 | $104.95 | $209.90 |
| Diablo 11 Pin Harness | CBL-005 | 2 | $10.92 | $21.84 |

# References
1. “Chapter 2, Traffic Detector Handbook: Third edition-volume I,” FHWA, https://www.fhwa.dot.gov/publications/research/operations/its/06108/02a.cfm (accessed Oct. 22, 2023).
2. DSP 21 directional counting detector - diablocontrols.com, https://diablocontrols.com/wp-content/uploads/dsp21-man-f-5dbb54cf335d3.pdf (accessed Oct. 24, 2023).
3. Loop sizes and loop characteristics - affordable openers, https://www.affordableopeners.com/manuals/access_controls/diablo/dsp405/chart.pdf (accessed Oct. 24, 2023). 
