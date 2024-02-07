## Functionality
The Motor subsystem is the system that is the main drive train to the robot. The drivetrain will consist of two dc motors. The motors are driven off of a L298 Dual H Bridge Motor Speed Controller to allow individual speed and direction control of the motors. 

## Specifications and Restraints
| Number | Constraint | Constraint description | Origin |
|--------|----------------------|------------------------|--------|
| ~~1.~~ | ~~ISO 10218~~ | ~~The robot shall stay in compliance with ISO 10218.~~ | ~~Safety and Competition Specification~~ |
| 2. | Time |  The motor shall be able to obtain an average speed of 2 inches a second in order to reach a time goal of 1:30. Team constraint| Competition Specification |
| 3. | Circuit Protection |  The motors shall have the back EMF reduced to shield noise from the motor driver| Motor Shield Specifications |
| 4. | Torque |  The motors shall be able to support a torque load of at least 6.8 kg*cm to drive a max weight of 25lbs up a 22.5-degree incline.  | Competition Specification |
| 5. | Coupling  | The motor shall be able to couple to the 4 mm drive shaft on the treads of the chassis. Chassis specs | Chassis Specifications |
| 6. | Versatility | They will be functionally independent of each other, so that they can operate at different speeds and directions | Team constraint |

## Buildable Schematic

Simulink transfer function block model for a DC motor

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Simulink_Model.png)

Command window parameters for DC motor model

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Command_parameters.png)

First transfer function block parameters 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Transfer_block1.png)

Second transfer function block parameters

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Transfer_block2.png)

## Analysis

**Constraint Solution 1:**





**Constraint Solution 2:**

The motor shall have an average rotation speed of at least 28 RPM. This rpm will give us our minimum speed needed to reach the goal of at least 2 inches per second. This calculation was done based off the radius of the drive wheel which is 0.69 inches. Then finding the circumference using Circumference=2*pi*radius we find that that the circumference equals 4.335 inches. Then take the RPM speed of the motor and divide it by 60 to convert to rotations per second. After obtaining the RPS speed we multiply this number by our circumference and get our inches per second speed which is approximately 2.0230 inches per second. 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/RPM.png)

**Constraint Solution 3:**





**Constraint Solution 4:**


![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Torque.png)


**Constraint Solution 5:**


![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Current.png)

## BOM
| Item | Description | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-------------|--------------|----------|-------|-------------|
| Motors |  |  |  |  | | |
| Motor Shield | | | | | | |
| | | | | | | |
