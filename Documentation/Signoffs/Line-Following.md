# Line Following Signoff
## Functionality
The line following subsystem will provide the master control with usable data to control the robot. The subsystem will use a reflectance sensor array to detect changes. In the scope of this project, the reflectance sensor array will be used to detect changes in the line with respect to the arena floor color.

## Constraints
The following constraints are derived from formulated shall statements that the team must abide by:
<ul> 
	<li>C9: The robot shall travel inclines and declines up to 25 degrees.</li>
		<ul>
		<li>This constraint is applicable to the line following subsystem because the system must still produce valid data no matter what slope the robot faces.
		</ul>
	
	<li>C10: The robot shall turn 360 degrees left and right and move forwards and backwards based on sensor inputs.</li>
	<li>C11: The robot shall have a navigation system that controls movement.</li>
		<ul>
		<li>The line sensing subsystem will transmit data to the master control telling it where the robot is with respect to the sensed line.
		</ul>
	<li>C12: The robot shall know its location within a two-inch tolerance. </li>
		<ul>
		<li>This constraint holds the line sensing subsystem to a maximum of 2-inch tolerance. If the team is using the line sensing option for traversing the track, the two-inch tolerance will be calculated from the center of the desired line.
		</ul>
	<li>C14: The robot shall have a user manual that explains all functions and capabilities of the robot.</li>
		<ul> 
		<li>This constraint will require all detailed design decisions to be documented and explained. Not only will the design have to be explained, but the motives behind the design and the other options explored so that future SECON teams have an understanding of why the design was created in a certain manner.
		</ul>
</ul>

## Schematic
The schematic of the system is shown below.

The sensor schematic given in the datasheet is shown below.

## Analysis
According to the datasheet, each LED will draw 20-25 mA of current resulting in an overal current draw of 100 mA for the entire sensor. The sensor can operate on 3.3 V or 5 V. The weight of the sensor should not have an effect on the integrity of the system as it weighs just over 3 grams. The sensor is most accurate when it is 0.125" (3 mm) away from the surface it is sensing. The maximum sensing distance is 0.375" (9.5 mm).

## BOM
| Item | Quantity | Price/Item | Total Price | 
|-|-|-|-| 
| QTR-8RC | 1 | $9.95 | $9.95| 
