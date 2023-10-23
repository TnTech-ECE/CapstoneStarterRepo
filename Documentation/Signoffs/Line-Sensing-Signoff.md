# Line Following Signoff
## Functionality
The line following subsystem will provide the master control with usable data to control the robot. The subsystem will use a reflectance sensor array to detect changes. In the scope of this project, the reflectance sensor array will be used to detect changes in the line with respect to the arena floor color. When the direction of the line changes, it shifts from the center receiver of the reflectance sensor array to one of the outside receivers. This data will be transmitted back to the master control so the robot remains on track with the line. To achieve forward and reverse movements, two sets of reflectrance sensor arrays will be used: one in the front and one in the back.

## Constraints

### Derived from Shall Statements

- C9: The robot shall travel inclines and declines up to 25 degrees.
	- This constraint is applicable to the line following subsystem because the system must still produce valid data no matter what slope the robot faces.
* C10: The robot shall turn 360 degrees left and right and move forwards and backwards based on sensor inputs.
* C11: The robot shall have a navigation system that controls movement.
	* The line sensing subsystem will transmit data to the master control telling it where the robot is with respect to the sensed line.
		
- C12: The robot shall know its location within a two-inch tolerance.
	- This constraint holds the line sensing subsystem to a maximum of 2-inch tolerance. If the team is using the line sensing option for traversing the track, the two-inch tolerance will be calculated from the center of the desired line.

### Derived from Broader Implications
	
- C14: The robot shall have a user manual that explains all functions and capabilities of the robot. 
	- This constraint will require all detailed design decisions to be documented and explained. Not only will the design have to be explained, but the motives behind the design and the other options explored so that future SECON teams have an understanding of why the design was created in a certain manner.
		
	
	
## Schematics

### System Schematics

![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Line-Following/Line_Sensor_Connections.png)
The schematic of the system is shown above. There will be two reflectance sensor arrays used. 
    The Pololu QTR-8RC module has a perforation in the board that allows for two of the eight sensors to be broken
	off. This leaves one reflectance sensor array with two LED emitters and receivers and one reflectance sensor array with six LED emitters
	receivers. 
	The array with six LED emitter/receiver pairs will be used at the head of the robot for 
	forward movement about the line.
	The array with two emitters and receivers will be used at the back of the robot for reversing. Because reversing is most likely done
	in small intervals, the smaller module will suffice. Reversing will never be the first robot movement, so the front sensor set will be active
	before the smaller module. This means that the robot will be centered in reference to the line before moving backwards. As a result, the smaller module
	will be inately centered, allowing for less precision.
	The last IEEE SECON Hardware competition arena with a line was in 2021. The line was black with the arena floor being white. The line was 16" in width. The black
	line also had a smaller white line in the middle, acting like the middle line separating two lanes on a road.
	The Pololu QTR-8RC module spans 2.95" without the separation of the 6 RC and 2 RC modules. The sensor set has the capabilities to keep the robot on the black line. If being
	centered on the line is important, the robot can sense the smaller white strip.
	The sensors will be powered by a 5 v regulated source coming from the power distribution subsystem. The sensor
	outputs will be read by an Arduino Mega. The digital pins 22-28, 30 will be used to conserve analog and PWM pins for future sensor implementation.

### Sensor Schematics
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Line-Following/Line_Sensor_Schematic.jpg?raw=true"alt="Sensor Schematic"/>
</p>
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Line-Following/Pololu_QTR_8RC.png?raw=true"alt="Pololu QTR-8RC"/>
</p>
The sensor is created with LEDs and phototransistors. The LEDs emit a light, and the phototransistor receives the reflection off of the surface.
    Different color combinations of line and arena floor will generate different voltage readings. 
	
The code for the project will be discussed in detail in the microcontroller signoff. On a high level,
    the code will read sensor data in at a determined sampling rate (around 100 Hz, disccussed in analysis). 
	A generalized code block diagram is shown below. The sensor has Arduino libraries for customer download to help with implementation.
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Line-Following/Line_Sensing_Software_Flowchart.png?raw=true"alt="Code Block Diagram"/>
</p>

## Analysis
According to the datasheet, each LED will draw 20-25 mA of current resulting in an overal current draw of 100 mA for the entire sensor. This condition is for the highest sampling rate of 1 kHz. If the sampling rate is lowered, the supply current needed is lowered as well.
    For the scope of this project, 100 Hz should be sufficient in keeping the robot on the line.
	Pololu recommends this value for their 3pi robot that has line-sensing capabilities. Sampling every 10 ms should allow the master control enough time to change direction, but fast enough to produce a fluent maneuver.
	This lowers the total consumption to 10 mA and the individual LED consumption down to 1.25 mA. The sensor can operate on 3.3 V or 5 V. The weight of the sensor should not have an effect on the integrity of the system as it weighs just over 3 grams. The sensor is most accurate when it is 0.125" (3 mm) away from the surface it is sensing. The maximum sensing distance is 0.375" (9.5 mm).
	
Pololu gives an oscilographic representation of the sensor working
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Line-Following/Line_Sensing_Oscilograph.png?raw=true"alt="Sensor Osciloscope"/>
</p>

The example is when the one of the sensor modules detects a black line on a surface. The yellow curve is the sensor reading and the blue curve is the digital input to the microcontroller.
	Pololu states that meaningful results are available within 1 ms. The 1 ms added with the 100 hz sampling means data is read into the sensor microcontroller ever 11 ms. As stated above,
	the small latency will beneficial to the master control so that direction changes can be started before the next sensor reading. 

As stated above, analysis and implementation description of code will be discussed in the microcontroller signoff.

## BOM
| Item | Quantity | Price/Item | Total Price | 
|-|-|-|-| 
| QTR-8RC | 1 | $9.95 | $9.95| 

## References
Pololu QTR-8RC information: https://www.pololu.com/product/961/ (Accessed on 10/19/2023)
2021 IEEE SECON Board Layout: https://attend.ieee.org/southeastcon-2022/wp-content/uploads/sites/309/2022_SoutheastCon_HardwareRules.pdf