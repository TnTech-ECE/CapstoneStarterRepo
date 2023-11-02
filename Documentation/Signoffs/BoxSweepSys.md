 # Box Sweep Mechanism Detail Design
## Functionality of Subsystem
![BoxSweepBlock](https://github.com/cebttu/CapstoneTeam1/assets/100803345/013c3d94-bfd4-413d-9479-0ceecd064bfe)
<br /> Figure 1: Box Sweep Block Diagram
<br />
<br />
The Box Sweep Mechanism acts as the method of obtaining and moving the large boxes on the gameboard to their destination to receive additional points in the competition. Once the Start Sensor sends the signal to the main controller to begin the run, the main controller will pass this signal to the Box Sweep Subsystem to lower the sweep, the sweep will gather the large boxes while the robot moves forward, but once the navigation system detects that the robot will be making a turn a signal will be sent to the Box Sweep Subsystem to raise the sweep while traversing the corner to deposit the boxes at their destination in the first corner of the gameboard.

## Constraints of Subsystem
| Constraint no. | Description | Origin|
|----------------|-------------|-------|
| 1. | The ruler, flexible skirt, and Servo shall be recycled parts to lessen the environmental impact of the robot. | Ethical Considerations |
| 2. | The arm of the sweep shall not move faster than 1 inch per second. | ISO 10218 |
| 3. | The arm of the servo shall not extend past the cubic foot requirement before the start sensor is triggered. | Competition Specifications |
| 4. | The arm of the servo shall reach as close as possible to the edge of the board to obtain the large boxes | Competition Specifications |


## Buildable Schematic of Subsystem
![BoxSweepWire](https://github.com/cebttu/CapstoneTeam1/assets/100803345/49d00ecf-5d38-4079-bfce-1f7548c8ef04)
<br />Figure 2: Box Sweep Wiring Diagram
<br />
<br />
The SG90 Servo is a servo motor with 180 degrees of movement. This will be the point of motion for the sweep arm that will collect the boxes. The SG90 has three pins that control the function of the motor.

Pulse Width Modulation (PWM, orange wire): This pin shall be connected to a PWM Pin on the main controller. Code within the main controller will send the appropriate pulse to lower the arm from 90 degrees to 180 degrees once the start signal is received by the main controller.
<br />
<br />
Vcc (red wire): This pin will be connected to the 5V output of the Power System to power the SG90 Servo. The SG90 requires a voltage between 4.8V - 6V to be properly powered.
<br />
<br />
Ground (GND, brown wire): This pin shall be connected to the ground of the power system. This shall properly ground the servo. 
<br />
<br />
![BoxSweep3D](https://github.com/cebttu/CapstoneTeam1/assets/100803345/81a46d01-d600-43d9-bf44-87c3ea941958)
<br />
<br />
The Servo unit and Servo Saver represented by the blue and orange block shall have the ruler, represented by the brown block, and the flexible skirt, represented by the purple block, attached to it. The Servo will begin with the ruler and skirt vertically upright at 90 degrees. However, once the start sensor is activated, the servo will lower the ruler and skirt to 180 degrees. This shall allow the arm to reach the large boxes. The exact height from the bottom of the board is dependent on the height of the tracks as defined in the drive train system at a later date.


## Analysis of Subsystem
Constraint 1: 
<br />
The Servo unit shall be salvaged from the SECON 2023 robot. The ruler shall be provided by a student within the team. The flexible skirt shall use a cutting mat that is left over in the Capstone lab.
<br />
<br />
Constraint 2:
<br />




## BOM of Subsystem 
| Item | Description | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-----------|-------------|--------------|----------|-------|-------------|
| Ruler | Acts as the arm of the box sweep | Box Sweep | N/a | N/a | 1 | Recycled | Recycled |
| Cutting board sheet | Acts as a flexible skirt for the arm to prevent boxes from pushing their way under the arm | Box Sweep | N/a | N/a | 1 | Recycled | Recycled |
| Servo | Moves the arm up and down slowly at appropriate times | Box Sweep | SG90 |	DIYables | 1 | Recycled | Recycled |
| Servo Saver | Bearing to protect the servo from lateral torque | Box Sweep | B075F2ZT1Q | ETPNNASO | 1 | $9.99 | $9.99 |
|||||||| $9.99 |
