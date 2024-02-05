 # Box Sweep Mechanism Detail Design
## Functionality of Subsystem
![BoxSweepBlock](https://github.com/cebttu/CapstoneTeam1/assets/100803345/013c3d94-bfd4-413d-9479-0ceecd064bfe)
<br /> Figure 1: Box Sweep Block Diagram
<br />
<br />
The Box Sweep Mechanism acts as the method of obtaining and moving the large boxes on the gameboard to their destination to receive additional points in the competition. Once the Start Sensor sends the signal to the main controller to begin the run, the main controller will pass this signal to the Box Sweep Subsystem to extend the sweep, the sweep will gather the large boxes while the robot moves forward, but once the navigation system detects that the robot will be making a turn a signal will be sent to the Box Sweep Subsystem to retract the sweep while traversing the corner to deposit the boxes at their destination in the first corner of the gameboard.

## Constraints of Subsystem
| Constraint no. | Description | Origin|
|----------------|-------------|-------|
| 1. | The ruler, flexible skirt, and Servo shall be recycled parts to lessen the environmental impact of the robot. | Ethical Considerations |
| 2. | The arm of the sweep shall not move faster than 1 inch per second. | ISO 10218 |
| 3. | The arm of the sweep shall not extend past the cubic foot requirement before the start sensor is triggered. | Competition Specifications |
| 4. | The arm of the sweep shall reach far enough to obtain the large boxes | Competition Specifications |



## Buildable Schematic of Subsystem
![BoxSweepWire](https://github.com/cebttu/CapstoneTeam1/assets/100803345/f4b8b9de-97ab-4256-9050-8eab1a528d14)
<br />Figure 2: Box Sweep Wiring Diagram
<br />
<br />
The FS90 Servo is a servo motor with 120 degrees of movement. This will be the point of motion for the sweep arm that will collect the boxes. The SG90 has three pins that control the function of the motor.

Pulse Width Modulation (PWM, orange wire): This pin shall be connected to a PWM Pin on the main controller. Code within the main controller will send the appropriate pulse through the PWM pin to lower the arm from 90 degrees to 180 degrees once the start signal is received by the main controller.
<br />
<br />
Vcc (red wire): This pin shall be connected to the output of the Power System to power the SG90 Servo. The SG90 requires a voltage between 4.8V - 6V to be properly powered. The servo shall pull __V so that the motor will not move faster than 1 inch per second.
<br />
<br />
Ground (GND, brown wire): This pin shall be connected to the ground of the power system. This shall properly ground the servo. 
<br />
<br />
## Under Construction -- switching to Blender, redesigning, and refining
![BoxSweep3D](https://github.com/cebttu/CapstoneTeam1/assets/100803345/81a46d01-d600-43d9-bf44-87c3ea941958)
<br /> Figure 1: Box Sweep 3D Model
<br />
<br />
The Servo unit and Servo Saver represented by the blue and orange block shall have the ruler, represented by the brown block, and the flexible skirt, represented by the purple block, attached to it. The Servo will begin with the ruler and skirt vertically upright at 90 degrees. However, once the start sensor is activated, the servo will lower the ruler and skirt to 180 degrees. This shall allow the sweep to reach the large boxes. The exact height from the bottom of the board is dependent on the height of the tracks as defined in the drive train system at a later date.


## Analysis of Subsystem
Constraint 1: 
<br />
To have the servo, skirt, and ruler sourced from recycled parts: the servo unit shall be salvaged from the SECON 2023 robot, the ruler shall be provided by a student within the team, and the flexible skirt shall use a cutting mat that is left over in the Capstone lab.
<br />
<br />
Constraint 2:
<br />
To have the sweep move at no greater than 1 inch per second: the voltage to the servo unit will be controlled so that the maximum speed of the sweep is no greater than 1 inch per second.
<br />
<br /> 
Constraint 3:
<br /> 
To fit the cubic foot requirement before the start signal is triggered: the arm of the sweep shall begin in the vertical upright position at 90 degrees, and the ruler and skirt will be trimmed to 8.5" long and 3.88" wide with the left side of the servo unit placed 4.2" from the far right side of the robot.
<br /> 
<br /> 
Constraint 4:
<br /> 
To have the arm of the sweep reach the large boxes the skirt is included to prevent boxes from sliding under the ruler, and the ruler is trimmed to the absolute maximum it can reach while still fulfilling the cubic foot requirement while upright (8.15".) 
<br /> 
<br /> 





## BOM of Subsystem 
| Item | Description | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-----------|-------------|--------------|----------|-------|-------------|
| Ruler | Acts as the arm of the box sweep | Box Sweep | N/a | N/a | 1 | Recycled | Recycled |
| Cutting board sheet | Acts as a flexible skirt for the arm to prevent boxes from pushing their way under the arm | Box Sweep | N/a | N/a | 1 | Recycled | Recycled |
| Servo | Moves the arm up and down slowly at appropriate times | Box Sweep | FS90 |	FEETECH | 1 | Recycled | Recycled |
| Servo Saver | Bearing to protect the servo from lateral torque | Box Sweep | B075F2ZT1Q | ETPNNASO | 1 | $9.99 | $9.99 |
|||||||| $9.99 |
