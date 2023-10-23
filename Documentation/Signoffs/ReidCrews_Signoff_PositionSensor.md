# Location Signoff

## Functionality

The location subsystem send data to the master control  to control and move the robot. The subsystem will use ultrasonic sensors to detect the arena's boundaries. The ultrasonic sensors will use to detected boundaries to determine the robot's phyiscal location. The transmitter will generate an ultrasonic wave, and the receiver will receive the reflected ultrasonic wave. This data will be sent to the master control to know the robot's location relative to the arena.

## Constraints
### Shall Statements

* C4: The robot shall contain modules that are plug-and-play adaptable for different IEEE competition requirements. 

    * This constraint allows future teams to replace or reallocate the chosen location sensor(s).

* C10: The robot shall turn 360 degrees left and right and move forwards and backwards based on sensor inputs.

* C11: The robot shall have a navigation system that controls movement.

	* This constraint will transmit data to the master control where the robot’s coordinates relative to the arena .
		
* C12: The robot shall know its location within a two-inch tolerance.
    
    *  This constraint holds the location subsystem to a maximum of 2-inch tolerance. The two-inch tolerance will be calculated from the desired arena coorinates.

### Broader Implications

* C14: The robot shall have a user manual that explains all functions and capabilities of the robot. 
	* This constraint was constructed to document the design process and motives of the location subsystem for future SECON teams.

## Buildable Schematic 


![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Electrical/Schematics/Sources/Position/PositionSensorSchematic.PNG "Figure 1: Ultrasonic Sensor Schematic")



The third section should show the buildable schematic directly embedded in the markdown file as a jpeg image. If the schematic is not clearly readable and appropriately sized, the supervisor will reject the signoff. 

The schematic must be appropriate to the design. ie. 3d model for a physical system or wiring schematic for a circuit. Further, the schematic(s) must contain every detail necessary for the design to be built by someone who has no knowledge of the design. Every relevant component value and measurement must be given.

The actual design artifacts (3d model, Cad files, gerber files, etc) must be uploaded to the documentation folder in the appropriate location.

## Analysis

A complete and relevant analysis of the design showing that it **should** meet the constraints and perform the desired function must be given. This analysis must be comprehensive and well explained so that it is convincing to the faculty supervisor. If the signoff request is not convincing either because the requirements and constraints are insufficient, unjustified, or not appropriately shown to be met by the design, then approval will not be given. Without approval, the components for the subsystem aren't allowed to be ordered. 

## BOM

| Item | Description | Quantity | Price | Total Price | 
|-|-|-|-|-| 
| SKU 101020010 | Ultrasonic Sensor | 4 | $11.32 | $45.28| 

