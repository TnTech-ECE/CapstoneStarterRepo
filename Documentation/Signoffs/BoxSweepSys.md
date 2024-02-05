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
| 1. | The ruler and flexible skirt shall be recycled parts to lessen the environmental impact of the robot. | Ethical Considerations |
| 2. | The sweep shall use the mechanism from the Push Button Subsystem and meet all constraints except number 2. | Push Button Functionality |
| 3. | The arm of the sweep shall not extend past the cubic foot requirement before the start sensor is triggered. | Competition Specifications |
| 4. | The sweep system shall not interfere with the operation of the tracks. | Strategy Specfifications |



## Buildable Schematic of Subsystem
The box sweep shall use the same mechanism as the button push subsystem, with only two changes. The first is that it will use a ruler and skirt instead of a paint roller, and the second is that it will be mounted upsidedown off the side of the robot to swing out the arm. The arm shall start parralel to the tracks, and when it recieves the signal from the main controller, will rotate 90 degrees to be perpendicular to the robot's direction of movement.
<br />
<br />
![Box Sweep 3D model](https://github.com/cebttu/CapstoneTeam1/assets/143427017/46702d1e-ca21-405c-965e-da1f78810bdb)
<br /> Figure 1: Box Sweep 3D Model
<br />
<br />
The blue bubble represents the servo system from the button push system, see that signoff for details. The grey is the chassis, including the mounting point for the servo assembly that extends from the right hand side of the robot an inch out from the tracks, as shown in the model above. The red bar is the ruler and the skirt that are attached to the servo assembly. The skirt is to be made of a flexible yet sturdy cutting board found in the capstone lab, which will be affixed to the bottom of the ruler in order for the blocks to be caught and dragged along.


## Analysis of Subsystem
Constraint 1: 
<br />
To have the skirt and ruler sourced from recycled parts: The ruler shall be provided by a student within the team, and the flexible skirt shall use a cutting mat that is left over in the Capstone lab.
<br />
<br />
Constraint 2:
<br />
In order for the sweep system to adhere to the constraints of the button push system it will use the exact same servo assembly as the button push. This is achievable as the weight of the ruler and skirt willbe significantly less than the weight of the paint roller. The paint roller weighs 5.3 ounces, whilst the ruler weighs 0.96 ounces and the skirt will weigh 2.1 ounces roughly. This means that the torque load will be significantly less than the load with the paint roller.
<br />
<br /> 
Constraint 3:
<br /> 
To fit the cubic foot requirement before the start signal is triggered: the arm of the sweep shall begin each run parrallel to the tracks, and not extending beyond the back of the robot. The ruler will be cut down to fit this length requirement, and the skirt cut to fit the ruler.
<br /> 
<br /> 
Constraint 4:
<br /> 
The sweep system will not rotate back towards the chassis more than 90 degrees in order to prevent the ruler from sticking into the tracks and jammming them up or breaking the ruler. This will be accomplished by setting the servo to only rotate 90 degrees maximum.
<br /> 
<br /> 





## BOM of Subsystem 
| Item | Description | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-----------|-------------|--------------|----------|-------|-------------|
| Ruler | Acts as the arm of the box sweep | Box Sweep | N/a | N/a | 1 | Recycled | Recycled |
| Cutting board sheet | Acts as a flexible skirt for the arm to prevent boxes from pushing their way under the arm | Box Sweep | N/a | N/a | 1 | Recycled | Recycled |
| Servo Assembly | Rotates the ruler assembly out and back | Box Sweep | N\a |	FN\a | 1 | Recycled | Recycled |
|||||||| $9.99 |
