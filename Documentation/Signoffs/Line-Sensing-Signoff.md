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
	
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Line-Following/2021_SECON_Board.png?raw=true"alt="Secon Board"/>
</p>

The last IEEE SECON Hardware competition arena with a line was in 2021. A small white line of 1" was used.
	The Pololu QTR-8RC module spans 2.95" without the separation of the 6 RC and 2 RC modules. Because the width of the module is larger
	than the line, it will be accurate in reading the white color vs the adjacent black color.
	The sensors will be powered by a 5 V regulated source coming from the power distribution subsystem. The sensor
	outputs will be read by an Arduino Mega. The digital pins 22-28, 30 will be used to conserve analog and PWM pins for future sensor implementation.

### Sensor Schematics
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Line-Following/Line_Sensor_Schematic.jpg?raw=true"alt="Sensor Schematic"/>
</p>
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Line-Following/Pololu_QTR_8RC.png?raw=true"alt="Pololu QTR-8RC"/>
</p>
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Line-Following/Separated_Sensor.png?raw=true"alt="Separated Sensors"/>
</p>

_**The schematics and images above are produced by the supplier**_

When the sensor is broken into two separate modules, a 100 ohm resistor must be included to maintain accuracy. 
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
	This lowers the total consumption to 10 mA and the individual LED consumption down to 1.25 mA. The sensor can operate on 3.3 V or 5 V. The weight of the sensor should not have an effect on the integrity of the system 
	as it weighs just over 3 grams. The sensor is most accurate when it is 0.125" (3 mm) away from the surface it is sensing. The maximum sensing distance is 0.375" (9.5 mm).
	
Pololu gives an oscillographic representation of the sensor working
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Line-Following/Line_Sensing_Oscillograph.png?raw=true"alt="Sensor Oscilloscope"/>
</p>

The example is when the one of the sensor modules detects a black line on a surface. The yellow curve is the sensor reading and the blue curve is the digital input to the microcontroller.
	Pololu states that meaningful results are available within 1 ms. The 1 ms added with the 100 hz sampling means data is read into the sensor microcontroller ever 11 ms. As stated above,
	the small latency will beneficial to the master control so that direction changes can be started before the next sensor reading. 

Sampling rate calculations:

Max robot speed: 2 ft/s 

Max distance per sample at 100 Hz: 2 ft/s x 0.011 s = 0.022 ft => 0.264 in

Max distance per sample at 500 Hz: 2 ft/s x 0.003 s = 0.006 ft => 0.072 in

Max distance per sample at 1000 Hz: 2 ft/s x 0.002 s = 0.004 ft => 0.024 in

Therefore, the sensor microcontroller will receive an update every 0.264 inches at maximum speed with the proposed sampling frequency.
	If the robot does not react well with the lower sampling rate, a higher sampling rate can be used with the tradeoff of increased current draw.
	As stated above, analysis and implementation description of code will be discussed in the microcontroller signoff.

## Robot Attachment
The sensor will be mounted on the robot by a 3-D printed mold. The mold will hold the sensor in place and allow it to raise/lower in height to meet the reading height requirements.
	A more detailed design and explanation of the sensor attachment will be included in a chassis signoff.

## BOM
| Item | Quantity | Price/Item | Total Price | 
|-|-|-|-| 
| QTR-8RC | 1 | $9.95 | $9.95| 

## References
Pololu QTR-8RC information: https://www.pololu.com/product/961/ (Accessed on 10/19/2023).

2021 IEEE SECON Board Layout: https://attend.ieee.org/southeastcon-2022/wp-content/uploads/sites/309/2022_SoutheastCon_HardwareRules.pdf.