 # Box Sweep Mechanism Detail Design
## Functionality of Subsystem
![BoxSweepBlock](https://github.com/cebttu/CapstoneTeam1/assets/100803345/013c3d94-bfd4-413d-9479-0ceecd064bfe)
<br /> Figure 1: Box Sweep Block Diagram
<br />
<br />
The Box Sweep Mechanism acts as the method of obtaining and moving the large boxes on the gameboard to their destination to receive additional points in the competition. Once the Start Sensor sends the signal to the main controller to begin the run, the main controller will pass this signal to the Box Sweep Subsystem to lower the sweep, the sweep will gather the large boxes while the robot moves forward, but once the navigation system detects that the robot will be making a turn a signal will be sent to the Box Sweep Subsystem to raise the sweep while traversing the corner to deposit the boxes at their destination in the first corner of the gameboard.

## Constraints of Subsystem
(Perfect this before analysis)
| Constraint no. | Description | Origin|
|----------------|-------------|-------|
| 1. | The ruler and flexible skirt shall be recycled parts to lessen the environmental impact of the robot. | Ethical Considerations |
| 2. | The arm of the sweep shall not move faster than 1 inch per second. | ISO 10218 |


## Buildable Schematic of Subsystem
![BoxSweepWire](https://github.com/cebttu/CapstoneTeam1/assets/100803345/49d00ecf-5d38-4079-bfce-1f7548c8ef04)
<br />Figure 2: Box Sweep Wiring Diagram
<br />
<br />
The SG90 Servo is a servo motor with 180 degrees of movement. This will be the point of motion for the sweep arm that will collect the boxes. The SG90 has three pins that control the function of the motor.

Pulse Width Modulation (PWM, orange wire): This pin shall be connected to a GPIO Pin on the main controller. Code within the main controller will send the appropriate pulse to lower the arm from 90 degrees to 180 degrees once the start signal is received by the main controller.
<br />
Vcc (red wire): This pin will be connected to the 5V output of the main controller to power the SG90 Servo. The SG90 requires a voltage between 4.8V - 6V to be properly powered. This also allows the main controller to control if the servo is powered or not.
<br />
Ground (GND, brown wire): This pin shall be connected to the ground pin on the main controller that will ultimately be connected to the ground of the power system. This shall properly ground the servo. 

(3D Model - at least include start signal and estimated tracks)
(Explanation of the 3D Model)

## Analysis of Subsystem
(Perfect Constraints before touching this)


## BOM of Subsystem 
| Item | Description | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-----------|-------------|--------------|----------|-------|-------------|
| Ruler | Acts as the arm of the box sweep | Box Sweep | N/a | N/a | 1 | Recycled | Recycled |
| Cutting board sheet | Acts as a flexible skirt for the arm to prevent boxes from pushing their way under the arm | Box Sweep | N/a | N/a | 1 | Recycled | Recycled |
| Servo | Moves the arm up and down slowly at appropriate times | Box Sweep | SG90 |	DIYables | 1 | $7.49 | $7.49 |
|||||||| $7.49 |
