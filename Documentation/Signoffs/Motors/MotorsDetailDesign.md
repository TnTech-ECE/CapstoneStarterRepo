## Functionality
The Motor subsystem is the system that is the main drive train to the robot. The drivetrain will consist of two dc motors. The motors are driven off of a L298 Dual H Bridge Motor Speed Controller to allow individual speed and direction control of the motors. 

## Specifications and Restraints
| Number | Constraint | Constraint description | Origin |
|--------|----------------------|------------------------|--------|
| 1. | ISO 10218 | The robot shall stay in compliance with ISO 10218. | Safety and Competition Specification |
| 2. | Time |  The robot shall traverse the course in under 2 minutes.| Competition Specification |
| 3. | Circuit Protection |  The motors shall have the back EMF reduced to shield noise from the motor driver| Motor Shield Specifications |
| 4. | Torque |  The motors shall have enough torque to traverse the crater| Competition Specification |
| 5. |  |  |  |

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
