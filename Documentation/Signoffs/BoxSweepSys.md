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
| 1. | The ruler, flexible skirt, and motor controller shall be either recycled parts or shared with another system to lessen the environmental impact of the robot. | Ethical Considerations |

## Buildable Schematic of Subsystem

## Analysis of Subsystem

## BOM of Subsystem 
| Item | Description | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-----------|-------------|--------------|----------|-------|-------------|
| Ruler | Acts as the arm of the box sweep | Box Sweep | N/a | N/a | 1 | Recycled | Recycled |
| Cutting board sheet | Acts as a flexible skirt for the arm to prevent boxes pushing their way under the arm | Box Sweep | N/a | N/a | 1 | Recycled | Recycled |
| Motor controller | Controls the DC motor | Box Sweep | pull from push | '' | 1 | Shared with Push Button Subsystem | Shared with Push Button Subsystem |

Servo
-rotate both ways
-slowly
-hub so not directly on ruler

Sweep
-strong enough to push boxes
-tall enough it wont have boxes 'jump' it
- long enough that it sweeps boxes against wall

-ideas: Ruler, skinny stiff brush, plastic sheet scoop, hook on the end?
