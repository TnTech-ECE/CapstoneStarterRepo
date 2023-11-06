# Ground-Based Sensor Subsystem

The purpose of the ground based sensor subsystem is to be able to detect a car/pickup truck's presence at a designated entrance/exit of a parking lot and determine whether the car/pickup truck (vehicle) is entering a parking lot or leaving a parking lot.  By using inductive loops instead of cameras for detecting vehicles at entrances/exits, parking lots that do not have the infrastructure necessary to support cameras are able to be monitored to determine if there is parking availability.
# Constraints
| No. | Constraints | Origin |
| --- | ----------- | ------ |
| 1.  | Subsystem shall detect cars/pickup trucks (vehicles) and motorcycles that are entering a parking lot at a maximum speed of 20 mph and leaving a parking lot at a maximum speed of 20 mph. | System Requirements |
| 2.  | Vehicle detector shall cover a range of at least 50 &mu;H to 1000 &mu;H at a frequency at 50 kHz | NEMA Detector Standard 6.5.2.11 Loop/Lead in Electrical Properties    |
| 3.  | Vehicle detector shall be compliant with the FCC frequency range for Intentional Radiators and verifying the detector is within permissible part 15 frequencies.  | FCC Standard Title 47, Chapter I, Subchapter A, Section 15.202     |
| 4.  | Each entrance/exit of a parking lot shall have a total of two inductive loops for determining whether a car/pickup truck is entering a parking lot or leaving a parking lot. | System Requirements |
| 5.  | All components of the subsystem, with the exception of the inductive loops and lead-in wire to the induction loops, shall be placed in an area that does not affect pedestrian traffic along the road or nearby sidewalks.  | System Requirements |
| 6.  | All turns in the inductive loop shall be a 45° turn (or 135° as noted in the schematic drawing) to avoid damaging the wire(s) that create the inductive loop that comes from using 90° turns.  | System Requirements |
| 7.  | Any wire that is used as part of the loop and is connected to the vehicle detector shall be protected using a heavy-duty cable protector that is capable of protecting the wires under the weight of a vehicle or pedestrian while protecting the wires from the weather.  | System Requirements |
| 8.  | Vehicle detector shall detect vehicles and motorcycles that are tailgating (when the front bumper of one vehicle is close to the back bumper and the two vehicles are in the same loop at the same time on one side of the roadway).  | System Requirements | 
| 9.  | Vehicle detector shall detect vehicles and motorcycles that are going in opposite directions on the roadway, but are within the detection range of the same loop at the exact same time.  | System Requirements |
| 10.  | Inductive loops shall be placed a minimum of 4 ft. apart from the edge of one loop to the edge of the other loop to avoid cross talk between the loops and possibly give false signals.  | System Requirements |

1. The system will need to detect vehicles that entering a parking lot or leaving a parking lot at a maximum speed of 20 mph.  With numerous parking lots on the campus of Tennessee Tech having designated entrances/exits requiring a vehicle to turn at a 90° angle, vehicles will not be able to have a speed that is higher than 20 mph.  If a vehicle enters a turn that is at a 90° angle at a speed higher than 20 mph, the vehicle will be at risk for overturning and damage not only to the vehicle, but also buildings that are near the turn.  By setting the maximum speed for a vehicle entering/exiting a lot at 20 mph, the inductive loops will be able to detect all vehicles passing through the entrance/exit of a parking lot.  Also, vehicles that use the monitored parking lots across campus consist of spots that are designed for cars and pickup trucks to park in as both faculty, staff, and students tend to use vehicles that are not larger than a standard pickup truck.  Vehicles used for commercial purposes, such as box trucks, flatbed trucks, etc., are highly unlikely to park in these spots as they tend to use more than one spot at a time.  For the prior statement, the focus of the sensor will be to detect cars and pickups only as these types of vehicles are the only vehicles with the capabilities to park in one parking spot in a lot on campus.
2. The vehicle detector system that will be used must be able to be either manually tuned or automatically tuned for frequency to cover the given range of inductance values or greater<sup>1</sup>.  When a vehicle passes over an inductive loop, the vehicle induces eddy currents in the loops.  The eddy currents then force the inductance of the loops to decrease, which leads to a change that is detected by the DSP-21 Vehicle Detector.  If inductance does not change, then a vehicle is not present within the detection range of the inductive loop.  According to the user manual of the Diablo DSP-21 Vehicle Detector, the range for the loop inductance (includes lead-in inductance) is 20 &mu;H to 1500 &mu;H<sup>6</sup>.  When a vehicle passes over the loop, the inductance will be within the 50 &mu;H to 1000 &mu;H range as the inductance will change due to the presence of a vehicle.
3. For the Diablo DSP-21 Vehicle Detector to be used on the market, it must follow FCC regulations regarding Intentional Radiators as the device intentionally outputs a frequency to use for detection of vehicles<sup>3</sup>.  By being in a frequency range of 10 kHz to 200 kHz, the device does not require a license to operate as it is part of the unlicensed Part 15 bands, mainly used by hobbyists in communication<sup>4</sup>.  With this device being within the permissible Part 15 bands, vehicles will not be affected by the frequency output from the loops that is generated by the Diablo DSP-21 Vehicle Detector.
4. For the system to correctly determine the direction of the vehicle, whether the vehicle is entering or leaving a lot, it will require two loops at each entrance/exit with a Diablo DSP-21 Vehicle Detector controlling both loops.  With the Diablo DSP-21 Vehicle Detector, each loop will be connected to a specific channel.  The detector will then be programmed using the DIP switch on the front of the detector for the intended purpose of the detector (specifics of the detector will be explained in the following sections along with the DIP switch and LEDs).  As an example, in order to monitor the Engineering Quad parking lot (parking lot between the four buildings for the College of Engineering), two sets consisting of two loops each and one detector each will be used to monitor the two designated entrances/exits of the parking lot.
5. For the inductive loops to be placed in the road, wire must be placed in the road and sidewalks (if there are any sidewalks at the specific entrance/exit) to connect the vehicle detector unit and any other necessary components to the loops.  To prevent the detector and other components from being accidentally destroyed by vehicles and/or pedestrians, extra wire will be necessary for the lead-in wire to allow the system to be placed in an area that is not affecting both vehicle traffic and pedestrian traffic.  As seen in Figure 4 below, the entrances/exits to the Engineering Quad parking lot behind Brown Hall have areas of grass next to the sidewalks that are within reasonable distance from the road and an ideal place to set the components.  Though the components will be at risk during the summer when the specified area will undergo landscaping projects, the components that are placed away from the road will be protected by safety boxes that will be discussed in the Housing subsystem.
6. In many electrical installation applications that use rigid conduit, 90° turns are completed by using 90° bends that are shaped similar to an arc.  However, it is impossible to use a 90° bend with this application as the 90° turns will damage the wire(s) over time.  To increase the lifespan of the wire(s) used for the inductive loops, every 90° turn will be replaced by two 45° (or 135° as shown in the schematic) turns.  This will help in reducing the damage that is caused to the wire as the wires will experience wear to them that comes from the weight of the vehicles passing over the loops.
7. Due to this system being an above ground inductive loop system, the wire(s) must be protected from both the weight of vehicles and pedestrians and the different weather situations such as heat, rain, cold, etc.  To protect the wire used to connect the inductive loop(s) to the Vehicle Detector Unit, a heavy duty cable protector made of rubber will be implemented to cover all wire that is exposed.  Due to the size and shape of the system, rubber is the best material to use to protect the system as it can be cut to length to cover the entirety of both the loop(s) and the lead-in wires.
8. Many times at the entrances/exits of parking lots, vehicles and motorcycles must wait for traffic to decrease in order to enter/exit a parking lot.  Due to this, vehicles and motorcycles are very close together (can be considered as tailgating) and can affect the accuracy of the number of available parking spots in a specific parking lot.  To resolve this issue, the Diablo DSP-21 Vehicle Detector has a specific mode titled "Mode 3 - Two Paired Channels with Directional Counting" built into the detector.  When this mode is activated in the detector, it is able to determine the direction of travel that passes over the loops.  It is also specifically designed to deal with vehicles and motorcycles tailgating (view Constraint 8 in the table for explanation of tailgating), vehicles and motorcycles that are backing out of the second loop and backing into the first loop (this issue is due to a vehicle or motorcycle that has went too far into the exit and has a high risk for a vehicle traveling in a perpendicular direction of the vehicle or motorcycle to hit the front bumper of the vehicle or motorcycle leaving the parking lot), and other parking maneuvers that can be detected by the loops.  By using the Diablo DSP-21 Vehicle Detector instead of a DIY Vehicle Detector, this logic is already built into the detector and the focus will instead be on verifying the sensitivity level for both the detector and each individual loop/channel is set high enough to detect this scenario while low enough that inaccurate detections will not occur during the use of this system.
9. One event that happens very frequently is vehicles and motorcycles entering/exiting a parking lot at the same time, but the two vehicles are going in opposite directions of each other.  To prevent inaccurate counts from occurring due to this specific situation, the specified Operation mode in the explanation for Constraint 8. (Mode 3 - Two Paired Channels with Directional Counting) will be used.  This mode is specifically designed other maneuvers detected by the loop, including the detection of vehicle direction while accounting for vehicles that are traveling in the opposite direction.  According to the website mentioned in Reference 6. Diablo DSP-21 Directional Counting Detector, page 8 of 31, explains Mode 3 Operation and also includes a table that shows how two vehicles will affect each loop.  It also accounts for an example of a vehicle or motorcycle backing out and an example of one vehicle or motorcycle tailgating another vehicle or motorcycle.  With this specific mode on the Diablo DSP-21 Vehicle Detector, the cost of buying it versus building a DIY Vehicle Detector in-house is worth it as the functions provided in the detector, not only the different operating modes but also adjusting each channel's sensitivity and the detector's sensitivity individually along with many other valuable functions of the Diablo DSP-21 Vehicle Detector, will allow the inductive loops to accurately count the number of vehicles and motorcycles entering/exiting a parking lot and ultimately display an accurate number to students, faculty and staff, and visitors that are looking for places to park in an efficient and timely manner.  Without buying the Diablo DSP-21 Vehicle Detector and using an in-house detector as the replacement, the system will lose the necessary functions needed to accurately determine whether a vehicle or motorcycle is entering/exiting a parking lot as the focus will be moved from verifying the loops are accurately counting vehicles and motorcycles to verifying that the detector built-in house will function properly and meet the standards/constraints that are set for this system.
10. When using inductive loops for vehicle detection, cross talk must be taken into consideration.  Cross talk, or unwanted transfer of signals between the loops/channels, can give false information from one loop to another loop if the distance between the two loops is not large enough.  To avoid having cross talk between the two loops at an entrance/exit, a minimum of 4 ft. will be the distance between the two loops to avoid cross talk between the loops<sup>9</sup>.  With this minimum distance requirement, the detector should only detect when vehicles are passing over the loop and not receive false signals from the loops.

# Buildable Schematic

![DSP-21 Vehicle Detector with 11 Pin Harness](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/142754780/9e6edda6-8988-43ce-8e65-8d044ed19ea9)



*Figure 1. Diablo DSP-21 Vehicle Detector with 11 Pin Harness*

![Inductive Loop Sensor with Protection](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/142754780/a44f3e59-c393-453d-9c71-38174f131df5)



*Figure 2. Inductive Loop Sensor*


![Engineering Quad Parking Lot](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/142754780/7092a0db-ef98-40c4-a551-a04b3f10b1df)


*Figure 3. Engineering Quad Parking Lot*


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

<table>
<tr><th>Table 1: Pin Connections for Diablo DSP-21 Vehicle Detector</th></tr>

| Pin | Function                      |
|-----|-------------------------------|
| 1   | VDC+                          |
| 2   | VDC Common                    |
| 3   | Channel 2 Relay Common        |
| 4   | Earth Ground                  |
| 5   | Channel 1 Relay Common        |
| 6   | Channel 1 Relay Normally Open |
| 7   | Channel 1 Loop                |
| 8   | Channel 1 Loop                |
| 9   | Channel 2 Loop                |
| 10  | Channel 2 Loop                |
| 11  | Channel 2 Relay Normally Open |


</td></tr> </table>


# Analysis

## Power

The subsystem will be powered through the 11 Pin Harness connection found in Figure 1.  The recommended input voltage and current for the detector is 10.5 VDC to 35 VDC with 25 mA to 120 mA<sup>6</sup>.  Since the loops are connected directly to the vehicle detector unit, the loops will receive the necessary power through the detector.  The power through the loops will depend on the selections made using the on-board DIP switch with the provided table in both the user manual and the tables found under the Buildable Schematics section.  To ensure that the input power source is safely connected to the loops, size 14 AWG wire will be used to connect the loops to the detector.  Not only will the wire size be suitable for the amount of current in the wire<sup>5</sup>, but it will also provide extra protection for the wire as it is large enough that it is capable of tolerating a small amount of weight.  For the 11 Pin Harness Connector, the current flow is also small enough for 20 AWG wire to be used for the 11 Pin connection.  As the connections to the ESP32 Microcontroller GPIO pins are capable of handling a maximum of 20 mA of current, the input current to the GPIO pins will not exceed more than the rated maximum current.

## Vehicle Detection

The Diablo DSP-21 Vehicle Detector, found in Figure 1. Diablo DSP-21 Vehicle Detector with 11 Pin Harness, is displayed with both the front side and back side of the detector unit with the 11 Pin Harness Connection that connects the detector to the loops and other necessary equipment.  The 11 Pin Harness Connection is displayed upside down; however, the pins of the 11 Pin Harness are labeled to where each pin of the detector will be connected.  With two loops being connected to the detector, one for the loop closest to the road between Brown Hall and the Lab Science Commons building and the second loop closest to the Engineering Quad Parking lot between the buildings, they are connected to the pins on the harness that are directly connected to the detector.  The connections to the detector that are shown in the schematic drawing are also listed in the section Buildable Schematic under the table: Table 1: Pin Connections for the Diablo DSP-21 Vehicle Detector.  These connections are also found in the references section at the bottom of the document as reference number 6, "DSP 21 directional counting detector".  The pulse output from the Diablo DSP-21 Vehicle Detector has a 300 millisecond (ms) period ± 10 ms with 150 ms ± 10 ms on and 150 ms ± 10 ms off before the next pulse is sent through the loops.  The response time for the detector is 150 ms ± 25 ms and can hold a vehicle for up to one hour in the loop and still detect the vehicle<sup>6</sup>.

Though this subsystem could use a DIY Vehicle Detection Unit instead of the Diablo DSP-21 Vehicle Detector, the specified device has numerous advantages built into it that a DIY device would not include in the unit.  The Diablo DSP-21 Vehicle Detector includes the following advantages:

1. Ability to separate the two loops and act as if both are stand alone loops or have the loops work together with directional counting and directional logic.
2. Ability to increase sensitivity to not only detect cars/pickup trucks (vehicles), but to detect motorcycles that are entering or exiting a parking lot.
3. Ability to detect when a loop is not functioning properly, an issue has occurred in the system, or the loops are working correctly and detecting vehicles passing above the loops through the LEDs on the front of the Diablo DSP-21 Vehicle Detector
4. Ability to automatically reset the detector when mode selection, fail type, or sensitivity boost setting is manually changed by the operator.
5. Ability to automatically reset the channel (loop) when one of the loop settings on the DIP Switch is manually changed by the operator.
6. Ability to follow the constraints mentioned previously in the Constraints section.

For each of the advantages mentioned above, an explanation is given for the advantage and why it is necessary to use the Diablo DSP-21 Vehicle Detector instead of a DIY Vehicle Detection Unit.

1. As mentioned in "Table 1: DIP Switch", there are four individual operating modes.  Two of the four modes separate the loops and creates two stand-alone loops.  This option allows for the loops to output from a detection that is either a high pulse output (stays high for 150 msec.), high presence pulse (stays high for the entire time a vehicle is in the loop, including for cases of vehicles tailgating others), or high count pulse (high for 150 msec. once a vehicle leaves the loop and counts twice when a vehicle is tailgating another vehicle already in the loop).  The other two modes pair the loops together and can use either directional logic or directional counting.  Directional logic will detect a vehicle in the first loop and due to the close proximity of the first loop to the second loop, the detector will be able to determine which direction the vehicle is traveling as the second loop will still detect the vehicle before the vehicle leaves the first loop.  Directional counting will determine the direction of a vehicle and then count the vehicle either entering or exiting a parking lot.  This mode is extremely useful in situations of vehicles tailgating each other and vehicles that back out but then continue through the loops.

2. Since parking lots not only used by vehicles but also motorcycles, the sensitivity of the loops needs to be set accordingly to detect motorcycles.  Due to the smaller frame size of a motorcycle versus a vehicle, motorcycles are not always detected by DIY Vehicle Detection systems.  The Diablo DSP-21 Vehicle Detector has the ability to manually adjust the sensitivity level to have a range of four different sensitivity levels as mentioned in Table 2 and 3 for the DIP Switch for Channels 1 and 2.  The sensitivity boost on DIP Switch 4 will assist the detector to determine if a vehicle or motorcycle passed over the loops and then allow the unit to complete the process for the specific logic it is set to on the DIP Switch.

3. While the LEDs on the system alert the user that power is on or off or the loops detect the presence of a vehicle in the loop(s), the LEDs are also useful in troubleshooting issues with both the unit and the loops.  In both the User Manual under the Indicators section and Tables 1-3 for the LEDs, a list is given for each LED and the meaning of each light combination for the unit.  The green LED (power LED) has four different indicators that cause the LED to flash a specific pattern based on the issue.  If the LED is on continously, the unit has power and is working properly.  Both the Detect A and Detect B LEDs have the same indicators between one another; however, Detect A LED works for the Channel 1 Loop and Detect B LED works for the Channel 2 Loop.  In the User Manual for the Diablo DSP-21 Vehicle Detector under the Troubleshooting Section, it restates the different indicators while also including other possible issues that may arise with both the detector and the inductive loops.

4. For the DIP switch located on the front of the detector, DIP Switches 1-4 affect the entire detector, including the inductive loops.  To prevent any issues from occurring with the system, the detector resets itself when a change is made on any of the four DIP Switches.  Switches 1 and 2 control the operation modes of the detector (view Table 4. DIP Switch Selection (Operation) to understand the different operation modes) while Switches 3 and 4 control the Fail Type mode and sensitivity boost.  Fail Type operation consists of either Fail-Safe operation or Fail-Secure operation.  Fail-Safe operation forces the channel that is suffering from a failure in the loop to stay activated during the failure.  This would force the loop to stay high and never detect another vehicle until the failure is resolved.  Fail-Secure operation forces the channel that is suffering from a failure in the loop to stay deactivated through the entirity of the failure.  This loop would stay close and not be able to detect a vehicle until the failure is resolved within the loop.  If a power outage occurs from the system where both the battery and the main power source does not provide power, the system will result in Fail-Secure operation, no matter the setting of the switch.

5. For the DIP switches that control each channel/loop, the loop will reset when a switch is changed.  This allows for the loop to work properly while also not affecting both the other loop and the detector system.  The reset that follows the changes for each loop is also necessary to ensure that the settings are implemented correctly and will not give incorrect results to the channel output.

6. As noted in the Constraints section of this document, the detector must follow standards from both the FCC and NEMA while also following system requirements.  By using the Diablo DSP-21 Vehicle Detector versus a DIY Vehicle Detector, the device is designed and built with the standards in mind.  For the FCC standards, the frequency range is set well within the range for permissible Part 15 frequency bands.  This allows the owner of the detector to avoid obtaining a special license to operate the device as the frequency range is very low that it will not affect communication frequencies, radio frequencies, etc.  For the NEMA standards, the detector is able to stay within the specified inductance range of 50 &mu;H to 1000 &mu;H at a frequency at 50 kHz.  If a DIY Vehicle Detector was used instead of the DSP-21, it would take more resources to verify that the inductance range is within the specified range at 50 kHz.  For Constraint 8 mentioned in the Constraints section, vehicles that are tailgating can be detected depending on the response time of the detector.  The minimum distance needed for best case, average case, and worst case response time of the detector is mentioned below:

| Best Case Scenario of 125 ms. Response Time |                                    |
|---------------------------------------------|------------------------------------|
| Speed                                       | Distance between vehicles (in ft.) |
| 5 mph                                       | 0.92 ft                            |
| 10 mph                                      | 1.83 ft                            |
| 15 mph                                      | 2.75 ft                            |
| 20 mph                                      | 3.67 ft                            |

| Average Case Scenario of 150 ms. Response Time |                                    |
|------------------------------------------------|------------------------------------|
| Speed                                          | Distance between vehicles (in ft.) |
| 5 mph                                          | 1.10 ft                            |
| 10 mph                                         | 2.20 ft                            |
| 15 mph                                         | 3.30 ft                            |
| 20 mph                                         | 4.40 ft                            |

| Worst Case Scenario of 175 ms. Response Time |                                    |
|----------------------------------------------|------------------------------------|
| Speed                                        | Distance between vehicles (in ft.) |
| 5 mph                                        | 1.28 ft                            |
| 10 mph                                       | 2.57 ft                            |
| 15 mph                                       | 3.85 ft                            |
| 20 mph                                       | 5.13 ft                            |

With this information, the response time of the detector in a best case scenario only requires less than one foot of distance between two vehicles to detect both vehicles passing through the loop(s) and for the worst case scenario, it requires less than 6 ft of distance between two vehicles.  With the response time of the Diablo DSP-21 Vehicle Detector, this will allow the system to detect vehicles tailgating and count them as two vehicles instead of one vehicle.  Though drivers could be less than one foot away from each other, it is highly recommended to not be very close to the vehicle in the front as the vehicle in the front could engage the brakes with a large amount of force and the reaction time would not be short enough to compensate for the sudden braking, resulting in a vehicle accident.

Another advantage not mentioned previously is that if two vehicles, one entering and the other exiting the parking lot, pass by each other, the detector will be able to detect both vehicles and output a signal that alerts of one vehicle leaving while another vehicle is leaving.  Even if the two vehicles cross the loops at the exact same time going in opposite directions without stopping, the detector will be able to determine that one vehicle is leaving while the other is exiting.  The output signals from each loop will be sent to the Data Interpretation system where the counting system will update accordingly based off the information given from the detector output(s).

There are some disadvantages that come with using this detector.  One disadvantage is that it will not be able to tell the difference between two vehicles with one tailgating the other versus a vehicle pulling a trailer.  When using this detector and if it is set to Mode 3 for the Detector Operation DIP Switch Table, it will recognize the trailer as a separate vehicle and state that two vehicles have passed over the inductive loops and not a vehicle pulling a trailer.  Another disadvantage with this system is that if both loops are occupied, due to the exit lane being backed up due to heavy traffic on the road in front of the parking lot, and a vehicle enters into the loops, it is not certain that the loops will detect vehicles entering the parking lot.  Due to very little explanation in the user manual of the detector provided by Diablo Controls and very little work done with this particular detector and this specific scenario, this scenario would have to be simulated in the testing phase of the project to determine if in fact the detector can detect incoming traffic into the parking lot when both loops are occupied due to the exit lane being backed up.  One final disadvantage of the inductive loops is that with the loops being above the roadway and in the center of the road, drivers may move closer to the sidewalk and away from the loop in the center of the entrance/exit.  To account for this scenario, the sensitivity for both the detector and the individual loops will be adjusted accordingly to detect both vehicles and motorcycles that may move further away from the loop and closer to the sidewalk to avoid running over the loops.  Motorcycles present a larger challenge due to the smaller frame compared to vehicles.  With motorcycles possibly moving away from the loops, the detector will be tested extensively during the testing phase to determine whether vehicles and motorcycles that move away from the loop can be detected when entering/exiting a parking lot.  If this detector were to be built in-house instead of bought through a retailer, then the system would not be as reliable as mentioned both in this document and in the user manual mentioned under References section, Reference 6.

To summarize, the Diablo DSP-21 Vehicle Detector has many advantages pre-built into the system that a DIY Vehicle Detector would not have due to time, money, etc.  A DIY Vehicle Detector would also not be as accurate or reliable as the DSP-21 is as it is designed solely to help highway departments, businesses, or researchers that want to know the amount of vehicles entering/exiting a specific parking lot or the amount of vehicles that use a specific roadway.  By purchasing this device instead of designing and building the vehicle detection system in-house, the system will not have the advantages that the DSP-21 has as the main focus for the detector will be to verify that it actually works and does not fail due to design or build issues.  Though it would be more beneficial to design and build a vehicle detector in-house, a vehicle detector that is made by a company with experience in the world of traffic controls operations<sup>8</sup> would be more beneficial to this system so more focus is on guaranteeing that a vehicle is detected when in the detection range of the loop and the output is passed from the output of the vehicle detector to the input of the microcontroller for the Data Interpretation system.

*Since this project is a proof of concept, the system will not use the Diablo DSP-21 Vehicle Detector Unit and instead build a more cost-efficient function generator to replace the Diablo DSP-21 Vehicle Detector.  The use of this function generator will be to prove that the loops work in the manner that they should, but the system needs the Diablo DSP-21 Vehicle Detector Unit to fully maximize the potential of the sensors.  This method will also be used to prove previous statements made that state that this method will not be able to detect different scenarios such as vehicles tailgating, vehicles avoiding the loops, etc.  The function generator that will be used to replace the Diablo DSP-21 Vehicle Detector unit is listed under the section BOM.*
 

## Inductive Loop Detection Range

  For the loop to work correctly with the Diablo DSP-21 Vehicle Detector, the loops, found in Figure 2, have to fit both the size requirements for the detector while also being a reasonable size to detect vehicles entering the Engineering Quad parking lot.  For Figure 2. Inductive Loop Sensor, the dimensions of the loop are given.  The length of the loop will be 48 in. long but to avoid damaging the wires at the 90° turns of the rectangle, the loops will be turning at 45° (135°) angles.  This will create a loop that is shaped as an octagon instead of a rectangle.  The length of the wire between the 45° (135°) turns will be 17 in. long.  This will allow the loop to follow the recommended loop sizes chart (found under References section, Reference #7) that will be a length of 48 in. (4 ft.) by 72 in. (6 ft.).  At the connections of the loop ( labeled as "Pin #7, 8, 9, or 10 of the 11 Pin Harness), the numbers are used to specify exactly where each connection needs to be placed on the 11 Pin Harness for the system to function properly.  To handle the necessary current that will be provided from the detector while also having protection for the copper wire inside the insulation, 14 AWG gauge wire will be the used for the loops.  For each lead-in connection, a range of 17.5 ft. to 34.5 ft of wire will be necessary to ensure that the Diablo DSP-21 is safely located away from the road and sidewalks.  After completing the loops and adding the necessary length of wire for each lead-in connection, the system will need a total of 92.5 ft to 109.5 ft. of wire to detect vehicles through the inductive loops and connect the loops to the detector unit.  For this system to give an accurate number of the available parking spots in the Engineering Quad parking lot, a total of four loops will be needed with two at one entrance/exit and two more at the second entrance/exit.  This parking lot will require a total of 385 ft. of wire (this includes both the single strand wire length of 285 ft. to create the four inductive loops and the jacketed two conductor wire length of 100 ft. for the lead-in connections to the detector) to give an accurate number of the amount of available parking spots in the lot.

  According to the Loop Size chart, using a 4 ft. by 6 ft. size inductive loop with 4 turns will provide an inductance value of 100 &mu;H with a detection height of 3.2 ft (approximately 38" height)<sup>7</sup>.  This size works well for the two entrances/exits of the Engineering Quad as it will be wide enough to detect vehicles that pass by it or pass over the loop in both lanes of traffic and long enough to be detected by the loop.  The detection height (detection range) is set to a height of 3.2 ft to ensure all vehicles are detected when entering through the inductive loops.  Though the ground clearance for many vehicles today is less than 2 ft, many vehicle owners (particularly truck owners) tend to increase the ground clearance of their vehicles for by installing lift kits for offroad purposes or other reasons.  To ensure all vehicles, including lifted trucks, are able to be detected when entering/exiting a lot, the detection height of the loop will be set to 3.2 ft using a 4 ft. by 6 ft. loop.  To ensure the detector would work function and count properly, both the loop inductance and lead-in inductance must be greater than or equal to a ratio of 2:1.  To calculate the loop inductance, the loop inductance formula must be used:

```math
L = (P/4) * (N + N^2);
```
where L = Loop Inductance in &mu;H, P = Perimeter of loop in ft., and N = Number of turns in the loop

For the lead-in loop inductance, the base value of 0.22 &mu;H/ft is used.  After calculating both the loop inductance value (100 &mu;H) and lead-in inductance value (5.5 &mu;H), the ratio is 18.2:1 which is greater than the ratio value of 2:1.

For the lead-in connections to the inductive loops, jacketed 14 AWG, two conductor wire must be used instead of using a single strand 14 AWG wire.  This is to avoid having to add six turns for every foot of the lead-in connection.  The purpose of having six turns per foot in single stranded 14 AWG wire is to keep the wire from moving when vehicles go over the wire.  Jacketed 14 AWG, two conductor wire will keep the wires together and also protect the wire by not exposing the wire to vehicles, pedestrians, etc.  To summarize, the inductive loops that will be used for system are designed to detect a change in inductance when a vehicle passes above the loop(s) and requires the specifications mentioned in both the schematic drawing and in this section to function correctly.  Without these specifications, the system may not function properly and give the wrong output to the Data Interpretation system.  This, in turn, will ultimately cause issues for those looking to find parking lots with available parking in parking lots.

## 11 Pin Harness

For the detector to work with the inductive loops, the detector will use an 11 Pin Harness to connect the output pins from the back side of the detector to the necessary connections.  This system will use a 15 VDC, 50 mA power supply with the positive connected to Pin 1 and negative to Pin 2.  Loop 1 (Channel 1) will be connected to Pins 7 and 8 while Loop 2 (Channel 2) will be connected to Pins 9 and 10 according to both the schematic drawing and the user manual of the Diablo DSP-21 Vehicle Detector.  To detect when a vehicle is present over one or both of the loops, the common pins of both Channels 1 and 2 will be connected, in parallel, to the 3V3 pin of the ESP32 MCU.  The normally open contact for Channel 1 will be connected to Pin VP of the ESP32 Microcontroller to detect a closed contact when Loop 1 detects a vehicle and the normally open contact for Channel 2 will be connected to Pin VN of the ESP32 Microcontroller to detect a closed contact when Loop 2 detects a vehicle.  To securely connect the harness connections to pins of the ESP32 Microcontroller, it will require specific connection ends to the wires to properly fit while also alerting the MCU of when a vehicle is present in either one or both of the loops.

## Loop and Wire Protection

Due to restrictions from Tennessee Technological University, the wires cannot be installed into the road and sidewalk as normally done by highway departments when inductive loops are used on roadways.  With the restrictions in place, wires must be placed directly on top of the existing roadway and sidewalks.  Due to this situation, this exposes both the loop wires and the lead-in connection wires to the weight of vehicles and pedestrians and other physical factors to take into consideration.  To protect the loops and lead-in connections from the weight of vehicles and pedestrians and other physical factor such as weather, flexible rubber floor cable covers that have channels inside the covers will be used to protect the exposed wires.  By using this to protect the system, the wire will last longer and continue to be a reliable form of monitoring parking lots.  Without protection to the exposed wires in the system, the system will have an increased chance of not functioning properly due to vehicles and weather events slowly deteriorating the system and the system will require constant maintenance.  If the system requires constant maintenance, the costs of maintaining the system will become more expensive than it is to fully replace the system with a new product that will monitor parking lots more efficiently while having less costs to maintain the system.  To summarize, the flexible rubber floor cable covers are necessary to protect the exposed wires as without them, the system will deteriorate over time due to vehicles constantly running over the wires and weather related events.

*Since this project is a proof of concept, the rubber cable covers that are mentioned will not be used for this system.  Instead, rubber stall mats that are used for horse stalls will be used for this project.  These rubber mats have the ability to be shaped to fit the wires correctly through the use of cutting the mat(s).  Due to the mats being less expensive, the same amount of protection needed can be purchased at a lower cost.  Also, any material that is left over at the conclusion of this project, it can be used for other purposes in the Electrical and Computer Engineering Department at Tennessee Technological University such as future capstone projects, research projects, etc.  Total costs shown include extra mats to verify that system will have enough to account for any human errors made in shaping the mats for the inductive loops and lead-in connections.  Any material left over will be returned to the department as mentioned previously.*



# BOM
| Part | Part Number | Quantity | Price Per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Diablo Controls Inc. DSP-21 Vehicle Detector<sup>**</sup> | DSP-21-LV | 2 | $104.95 | $209.90 |
| Diablo 11 Pin Harness<sup>**</sup> | CBL-005 | 2 | $10.92 | $21.84 |
| 10FT Cord Cover Floor,Flexible Floor Cable Cover,Cord Hider Floor to Organize and Protect Wire,Floor Wire Covers Floor Cord Cover for Cords,for Home and Office (10ft, 5 Channel)<sup>**</sup> | B09YLJS37F | 18 | $22.99 | $413.82 |
| Unjacketed Wire<sup>*</sup> | 14 AWG | 285 ft. | $0.00 | $0.00 |
| Wire Connections<sup>*</sup> | N/A | N/A | $0.00 | $0.00 |
| Jacketed Wire, Two Conductor <sup>*</sup> | 14 AWG | 100 ft. | $0.00 | $0.00 |
| 4 ft. x 6 ft. Thick Rubber Stall Mat | 1202220 | 3 | $56.99 | $170.97 |
| 2 Pieces Signal Generator Kit, XR2206 Precise Function Signal Generator Frequency Module Signal Generator DIY Kit Sine Triangle Square Output Adjustable 1Hz-1MHz, 9-12V DC Input | B08LGV8ZKP | 2 | $17.99 | $35.98 |
| Total | ----- | ----- | ----- | $206.95 |

<sup>*</sup> These parts will be provided by the Department of Electrical and Computer Engineering at Tennessee Technological University.


<sup>**</sup> These parts will not be used in this system and the costs are not calculated into the total costs.  However, these parts will be mentioned for future reference in this system.

Note: The prices listed above do not include sales tax or shipping costs.

# References
1. “Chapter 2, Traffic Detector Handbook: Third edition-volume I,” FHWA, https://www.fhwa.dot.gov/publications/research/operations/its/06108/02.cfm (accessed Oct. 25, 2023). 
2. “Chapter 2, Traffic Detector Handbook: Third edition-volume I,” FHWA, https://www.fhwa.dot.gov/publications/research/operations/its/06108/02a.cfm (accessed Oct. 22, 2023). 
3. “The Federal Register,” Federal Register :: Request Access, https://www.ecfr.gov/current/title-47/chapter-I/subchapter-A/part-15/subpart-C/section-15.202 (accessed Oct. 24, 2023).
4. “ARRL,” Part 15 - Radio Frequency Devices, http://www.arrl.org/part-15-radio-frequency-devices#Technical (accessed Oct. 24, 2023). 
5.  “Wire gauge and current limits including skin depth and tensile strength,” American Wire Gauge Chart and AWG Electrical Current Load Limits table with ampacities, wire sizes, skin depth frequencies and wire breaking strength, https://www.powerstream.com/Wire_Size.htm (accessed Oct. 24, 2023). 
6. DSP 21 directional counting detector - diablocontrols.com, https://diablocontrols.com/wp-content/uploads/dsp21-man-f-5dbb54cf335d3.pdf (accessed Oct. 24, 2023).
7. Loop sizes and loop characteristics - affordable openers, https://www.affordableopeners.com/manuals/access_controls/diablo/dsp405/chart.pdf (accessed Oct. 24, 2023). 
8. “About US - 40-plus years leading the traffic and Access Industry,” Diablo Controls, https://diablocontrols.com/about-us/ (accessed Nov. 1, 2023).
9. Vehicle detection using inductive loops - dta0yqvfnusiq.cloudfront.net, https://dta0yqvfnusiq.cloudfront.net/diabl86536445/2018/05/Vehicle-Detection-Using-Inductive-Loops-2014-10-02-5afdb30e88c49.pdf (accessed Nov. 3, 2023). 
