## Functionality
The Motor subsystem is the system that is the main drive train to the robot. The drivetrain will consist of two dc motors which are driven off of a L298 Dual H Bridge Motor Speed Controller that allows the robot to travel at the needed speed to complete the course in a desirable time. This subsystem will allow the correction of the chassis position if the robot is not in the desired direction.

## Specifications and Restraints
| Number | Constraint | Constraint description | Origin |
|--------|----------------------|------------------------|--------|
| 1. | Time |  The motor shall be able to obtain an average speed of 2 inches a second in order to reach a time goal of 1:30 | Strategy Specifications |
| 2. | Circuit Protection |  The motors shall have the back EMF reduced to shield noise from the motor driver| Motor Shield Specifications |
| 3. | Torque |  The motors shall be able to support a torque load of at least 6.8 kg*cm to drive a max weight of 25lbs up a 22.5-degree incline.  | Competition Specification |
| 4. | Coupling  | The motor shall be able to couple to the 4 mm drive shaft on the treads of the chassis. | Chassis Specifications |
| 5. | Versatility | They will be functionally independent of each other, so that they can operate at different speeds and directions | Strategy Specifications |

## Buildable Schematic

Pinout Connections for DC Motors

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/New_Motor_Pinout.png)

Wires from motor pinout

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Wire_pinout.png)

The Encoder A Output and Encoder B Output are digital signals, and both encoders will be connected to one digital pin of the micrcontroller. For both motors there are a total of four digital pins connected to the microcontroller. The proof that the encoder A and encoder B outputs will work with the arduino are shown below because the HAL sensors on the encoder provide a digital signal that can be read as an input from the arduino pins.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Encoder_proof.png)

Code example for DC motors with CPR Encoder

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Arduino_motor_code_1.png)

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Arduino_motor_code_2.png)


## Analysis

**Constraint Solution 1:**

The motor shall have an average rotation speed of at least 28 RPM. This rpm will give us our minimum speed needed to reach the goal of at least 2 inches per second. This calculation was done based off the radius of the drive wheel which is 0.69 inches. Then finding the circumference using *Circumference=2*pi*radius* we find that that the circumference equals 4.335 inches. Then take the RPM speed of the motor and divide it by 60 to convert to rotations per second. After obtaining the RPS speed we multiply this number by our circumference and get our inches per second speed which is approximately 2.0230 inches per second. 

Code for calculating minimum speed required

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/MATLAB_command.png)

Results for minimum speed required

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/MATLAB_speed.png) 

**Constraint Solution 2:**

To reduce EMF noise from affecting the main control, a motor shield will be connected to both of the DC motors. When the motors are turned off there is a big change in the magnetic field around the motor windings. A voltage spike occurs from the this drastic change in magnetic field, but having the motor shield can redirect the spike back through the motors instead of the main control. The motor driver module has the capability to output up to 7 amps of current for each port the motors are connected to which is more than sufficient for what the DC motors need considering the stall torque of the motors is 1.8 amps at 12 volts. 

Motor Shield

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Motor_shield.png)

Motor Shield Specs

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Motor_Shield_Specs.png)

**Constraint Solution 3:**

The motor that is selected spec sheet shows the different conditions of operation of the speed, torque, current, and max efficiency of the motors selected. From observing the spec sheet we can see that the motor will be able to pull the weight in order to pull the weight of the robot up the 22.5 degree incline we need to be able to support 6.8 kg-cm. The yellow line in the graph below shows the torque, the 
purple line shows the RPM the motos will rotate at 6.8 kg-cm which is right around 28 RPM which is perfect for meeting our average RPM speed, and the brown line shows the current draw at 6.8 kg-cm which is about 0.65 amps of current at the max torque our motors will need to overcome. 

Selected Motors Data Sheet

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Graph_of_dc_motors.png)

Motor General Specs

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/General_Motor_Specs.png)


**Constraint Solution 4:**

The chassis of the robot has drive gears attached to the treads, and attached to the drive gear are the DC motor shafts. The coupling for the shaft to the drive gear requires that the motor shaft should be 4mm in diameter and have a D-cut slot on the shaft. The motor that has been selected also has a 4mm diameter shaft that has a D-cut slot for better connection between the coupler and the drive gear. 

DC motor dimensions for 172:1

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Motor_dimensions.png)

**Constraint Solution 5:**

In case of getting stuck, getting off course, or veering off from one motor rotating faster than the other, the motors will use a HAL effect encoder. This encoder allows determining position and speed control of the motors by using the output signal of the sensor. This sensor in conjuction with the motor shield can also allow the robot to back up to get back into correct position if needed.

Enoder

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/ConorOrr-Signoff-Motors/Documentation/Signoffs/Motors/Encoder.png)

## BOM
| Item | Description | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-------------|--------------|----------|-------|-------------|
| Motors | Metal gear DC motors used to drive robot chassis | 4868 | Pololu | 2 | $45.95 | $91.90 |
| Motor Shield | Protects main controller and allows more outputs | N/A | Drok | 1 | $15.99 | $15.99 |
| | | | | | | $107.89 |