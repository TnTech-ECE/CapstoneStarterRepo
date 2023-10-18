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
	receivers. The array with two emitters and receivers will be used at the back of the robot for reversing. Because reversing is most likely done
	in small intervals, the smaller module will suffice. The array with six LED emitter/receiver pairs will be used at the head of the robot for 
	forward movement about the line. The sensors will be powered by a 5 v regulated source coming from the power distribution subsystem. The sensor
	outputs will be read by an Arduino Mega. The digital pins 22-28, 30 will be used to conserve analog and PWM pins for future sensor implementation.

### Sensor Schematics
![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Line-Following/Line_Sensor_Connections.png)
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Line-Following/Pololu_QTR_8RC.png?raw=true"alt="Pololu QTR-8RC"/>
</p>
The sensor is created with LEDs and phototransistors. The LEDs emit a light, and the phototransistor receives the reflection off of the surface.
    Different color combinations of line and arena floor will generate different voltage readings. 

## Analysis
According to the datasheet, each LED will draw 20-25 mA of current resulting in an overal current draw of 100 mA for the entire sensor. This condition is for the highest sampling rate of 1 kHz. If the sampling rate is lowered, the supply current needed is lowered as well.
    For the scope of this project, 100 Hz should be sufficient in keeping the robot on the line. This lowers the total consumption to 10 mA and the individual LED consumption down to 1.25 mA. The sensor can operate on 3.3 V or 5 V. The weight of the sensor should not have an effect on the integrity of the system as it weighs just over 3 grams. The sensor is most accurate when it is 0.125" (3 mm) away from the surface it is sensing. The maximum sensing distance is 0.375" (9.5 mm).

## BOM
| Item | Quantity | Price/Item | Total Price | 
|-|-|-|-| 
| QTR-8RC | 1 | $9.95 | $9.95| 
