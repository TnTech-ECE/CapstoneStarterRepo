# Box Sweep Mechanism Detail Design
## Functionality of Subsystem
![BoxSweepBlock](https://github.com/cebttu/CapstoneTeam1/assets/100803345/013c3d94-bfd4-413d-9479-0ceecd064bfe)
<br /> Figure 1: Box Sweep Block Diagram
<br />
The Box Sweep Mechanism acts as the method of obtaining and moving the large boxes on the gameboard to their destination to receive additional points in the competition. Once the Start Sensor sends the signal to the main controller to begin the run, the main controller will pass this signal to the Box Sweep Subsystem to lower the sweep, the sweep will gather the large boxes while the robot moves forward, but once the navigation system detects that the robot will be making a turn a signal will be sent to the Box Sweep Subsystem to raise the sweep while traversing the corner to deposit the boxes at their destination in the first corner of the gameboard.

## Constraints of Subsystem

## Buildable Schematic of Subsystem

## Analysis of Subsystem

## BOM of Subsystem 

Servo
-rotate both ways
-slowly
-hub so not directly on ruler

Sweep
-strong enough to push boxes
-tall enough it wont have boxes 'jump' it
- long enough that it sweeps boxes against wall

-ideas: Ruler, skinny stiff brush, plastic sheet scoop, hook on the end?
