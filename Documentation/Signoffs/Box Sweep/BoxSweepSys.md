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
| 1. | The sweep arm shall be recycled parts to lessen the environmental impact of the robot. | Ethical Considerations |
| 2. | The sweep servo shall not exceed an operating torque of 0.7 kg*cm.  | Servo Specifications |
| 3. | The arm of the sweep shall not extend past the cubic foot requirement before the start sensor is triggered. | Competition Specifications |
| 4. | The sweep system shall not interfere with the operation of the tracks. | Strategy Specfifications |



## Buildable Schematic of Subsystem
The box sweep shall use a servo to rotate the arm of the sweep system out and retract it back after the first corner. The arm will be attached directly to the servo, preventing the need of gears or bearings. The arm, designed by the mechanicla side of the capstone team, will be a tapered, flexible PLA beam. This makes the weight of the arm minimal, reducing the torque load on the servo. The arm will be 2 inches tall, 6.5 inches long, and a thickness of 1/4 inch tapered to an edge on both a hieght and a length edge. A 3 dimensional diagram is shown below.
<br />
<br />
![Box Sweep 3D model](https://github.com/cebttu/CapstoneTeam1/assets/143427017/46702d1e-ca21-405c-965e-da1f78810bdb)
<br /> Figure 1: Box Sweep 3D Model
<br />
<br />
The blue bubble represents the servo of the sweep system. The grey is the chassis, including the mounting point for the servo assembly that extends from the right hand side of the robot an inch out from the tracks, as shown in the model above, which will be designed and fabricated by the mechanical team. The red bar is the arm attached to the servo. Below is an electrical diagram of the servo connected to a buck converter to power the motor.
<br />
<br />
![Box Sweep Pinout](https://github.com/cebttu/CapstoneTeam1/assets/143427017/11aee153-4096-441c-984f-074d1cd05cbc)
<br /> Figure 2: Box Sweep Electrical Pinout
<br />
<br />

## Analysis of Subsystem
Constraint 1: 
<br />
To have the sweep arm from recycled parts: The PLA will be used from what is left over in the Capstone lab.
<br />
<br />
Constraint 2:
<br />
In order for the sweep system to not exceed the torque rating of the servo, a load calculation was performed using a significantly heavier arm attached to the servo. This analysis is shown below. The Newtons cannot exceed 5 Newtons of torque. The analysis is shown below, showing that the force on the servo will not exceed the torque rating of the servo.
<br />
![Lateral_Force_Calc](https://github.com/cebttu/CapstoneTeam1/assets/143427017/fa98f1bf-39c1-4020-b57f-75a3844d7086)
<br /> Figure 3: Force Calculation
<br /> 
Constraint 3:
<br /> 
To fit the cubic foot requirement before the start signal is triggered: the arm of the sweep shall begin each run parrallel to the tracks, and not extending beyond the back of the robot. The arm will not be long enough to extend beyond the length of the chassis.
<br /> 
<br /> 
Constraint 4:
<br /> 
The sweep system will not rotate back towards the chassis more than 90 degrees in order to prevent the arm from sticking into the tracks and jammming them up or breaking the arm of the sweep. This will be accomplished by setting the servo to only rotate 90 degrees maximum.
<br /> 
<br /> 

## BOM of Subsystem 
| Item | Description | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-----------|-------------|--------------|----------|-------|-------------|
| PLA | Acts as the arm of the box sweep | Box Sweep | N/a | N/a | 1 | Recycled | Recycled |
| Servo Motor | Rotates the arm assembly out and back | Box Sweep | MG995 |	Tower Pro | 1 | Recycled | Recycled |
|||||||| $0.00 |
