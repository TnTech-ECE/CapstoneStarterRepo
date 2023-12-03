## Functionality

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/LiamCounasse-signoff-Team_Spirit/Documentation/Signoffs/Team_Spirit/spiritmech.png)

Figure 1: Block model of Team Spirit Subsystem

The purpose of the team spirit subsystem is to create a luminous and undeniable representation of TTU at the SECON robotics competition. It receives a signal and creates a display of purple and yellow blinking lights which are meant to represent Tennessee Tech University. 

The team spirit subsystem is nonoperational prior to entry of the thruster assembly zone. Upon entry into the thruster assembly zone the lights receive a signal and begin blinking. The lights remain on displaying a blinking pattern until the robot is powered off.

## Constraints and Standards
| No. |Constraint Description                                                                                                                                                      |Origin                   |
|-----|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------|
|  1  |The LEDs shall create a highly visible demonstration of Tennessee Tech University with purple and yellow lights.                                                            |Competition Specification|
|  2  |The system shall be dynamic by producing blinking lights at a frequencyof 4 Hz.                                                                                             |Competition Specification|
|  3  |The LEDs shall be spaced 0.5 inches apart on the rear and side panels of the robot for a total length of 22.64 inches for each color of LED's, and 64 total LED's.          |Design Specification     |
|  4  |The LEDs shall extrude from 6mm holes evenly spaced 8.5mm apart on the side panel of the robot.                                                                             |Design Specification     |
|  5  |Each LED shall be 6mm from the top or bottom edge of the robot.                                                                                                             |Design Specification     |
|  6  |The Gold LEDs shall be installed above the purple LEDs on the sidewall of the robot.                                                                                        |Design Specification     |
|  7  |The LEDs shall be secured on the back, and side panels of the robot and shall not be installed on the top, bottom, or on the front panel of the robot.                      |Design Specification     |
|  8  |The LED lights shall not tamper with the IR sensors of the navegation system.                                                                                               |Design Specification     |
## Buildable

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/LiamCounasse-signoff-Team_Spirit/Documentation/Signoffs/Team_Spirit/accurate%20measurments.PNG)

Figure 2: 3D model of the Team Spirit Subsystem with metric units

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/LiamCounasse-signoff-Team_Spirit/Documentation/Signoffs/Team_Spirit/measurements%20imperial%20units.PNG)

Figure 3: 3D model of the Team Spirit Subsystem with imperial units

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/LiamCounasse-signoff-Team_Spirit/Documentation/Signoffs/Team_Spirit/3d%20model.PNG)

Figure 4: 3D model Team Spirit System

The competition requires that the team spirit display be dynamic and highly visible to represent the team and university. The total perimeter of the chassis is 28.74 inches. The right and left sides of the chassis are each 8. The led light will line the rear and side outer panels of the robot. The front will not be lined due to interference with the IR sensors of the navigation system. The team spirit system will utilize 2 circuits with one circuit of 32 purple LED lights with series resistances, and another circuit of 32 yellow LED lights with series resistances. The LED's are horozontally placed 0.5 inches apart. The series resistance provided by the series resistors of the LEDs, provides the LED's with overcurrent protection and prevents potential damage to the components. The gold strip will be placed above the purple strip on the siding of the robot. This system requires two 5V digital inputs from the microcontroller to power the LEDs and create the blinking pattern. These pins will send 5V signals to the gate terminal of an n type MOSFET, allowing the strip to be powered by the power system at the drain terminal. The frequency of the blinking will be controlled by a function being looped outputting to each strip 4 times each second, or at a rate of 4 Hz. This can be done by utilizing delays between steps in the looped program and offesetting the blinking of one strip to alternate between purple and gold blinking lights. 

Purple LED:

The purple LED is a 5mm round model with attached wires and a series resistance to protect the LED. The connected wiring and series resistances to the LEDs reduce the risk of a failure. The LEDs operate at 4 ~ 6 V+. 

Yellow LED:

The yellow LED is a 5mm round model with attached wires and a series resistance to protect the LED. The connected wiring and series resistances to the LEDs reduce the risk of a failure. The LEDs operate at 4 ~ 6  V+. 

N - Channel MOSFET:

The N - Channel MOSFET can supply a max of 30 A of drain current. The switching time of the MOSFET is 128 ns. 

Drain:

The drain terminal of the MOSFET is connected to the positive terminal of the LED's. The drain terminal's maximum output characteristics from the D terminal are 30A, at 60V.

Source:

The source terminal of the MOSFET is connected to the common terminal of the circuit.

Gate:

The gate terminal of the MOSFET is controlled by a 5V signal from the microcontroller. The gate terminal controls current flow from the drain terminal of the MOSFET.


![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/LiamCounasse-signoff-Team_Spirit/Documentation/Signoffs/Team_Spirit/nmos.PNG)

Figure 5: The N - Channel MOSFET which acts as a relay for the Team Spirit Subsystem 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/LiamCounasse-signoff-Team_Spirit/Documentation/Signoffs/Team_Spirit/nmosmodel.PNG)

Figure 6: The circuit design of the Team Spirit Subsystem.
## Analysis

Analysis:

Constraint Solutions:

Constraint 1 Solution:  

The team spirit subsystem shall be a highly visible representation of Tennessee Tech University. The team spirit system utilizes purple and yellow LEDs which blink and are present on the rear and sides of the robot. The luminous emission of the LED lights highly visible within the bounds of the course to represent the university. The robot shall have gold and yellow paint, gold painted above purple, along the front border of the robot to compensate for constraint 8. 

Constraint 2 Solution: 

The system shall be dynamic by displaying lights which blink at a frequency people can see. This restricts the lights to blinking at frequencies that are visibly turning on and off as a function of time. The imposed rule reducing the frequency of the signal as a function of time defines it as a dynamic system. The system is capable of blink at a rate of 4Hz due to the capability of the relay to switch 10 times per second; or once every 100 ms.

Constraint 3 Solution:

The LEDs shall be spaced 0.5 inches apart around the sidewall of the robot for a total length of 22.64 inches per color, or 57.48 inches of lights. The spacing and positioning of the LEDs prevents the components from getting damaged on a moving part of another system. The spacing and positioning around the sidewall of the robot allows for maximum visibility to shine lights for the team spirit display. The LEDs will be secured into placed in the frame of the robot by drilling through the border of the platform and securing the LEDs in the sockets which are individually secured 0.5 inches apart from the closest point.

Constraint 4 Solution:

The LEDs shall extrude from holes 6mm in diameter 8.5mm apart vertically. Holes, 6mm in diameter, will be drilled through the chassis of the robot 8.5 mm apart and 8.5 mm from either edge to create positions which the LEDs can be embedded. These LEDs will then be connected properly and inserted in their proper extruded positions. This is a design specification for presentation purposes.

Constraint 5 Solution:

The LEDs shall be 6 mm from the top or bottom edge of the robot. This prevent potential damage to the edge of the frame while drilling holes to position the extruding LEDs. The holes will be drilled with centered positions marked 25 mm apart horozontally and 11.5 mm from the edge. The measurement for drilling 11.5 mm from either edge of the chassis side centeres the 6 mm drill bit on the designed location for the hole.

Constraint 6 Solution:

The Gold LEDs shall be installed above the purple LEDs on the sidewall of the robot. The gold LEDs will be installed in the extruding holes first creating the top row of lights. The second row of purple LEDs will then be installed into the extruding positions. These LEDs will be stored separately and tested prior to installaions to prevent accidents.

Constraint 7 Solution:

The LEDs shall be secured on the back, and side panels of the robot. The LEDs can safely be installed on the rear and side panels of the robot without the risk of interference with the sensors or movings parts of another system.The LEDs shall not be installed on the top, bottom, or on the front panel of the robot. The LEDs cannot be placed on the front of the robot due to potential intereference with the navegation system IR sensors.The LEDs cannot be placed on the bottom of the robot because the IR sensors are attatched under the front half of the robot.The LEDs cannot be on top of the robot due to the potential damage it can cause to the start recognition systems RGB sensor.

Constraint 8 Solution:

The LED lights shall not tamper with the IR sensors of the navegation system. The LED lights used in the team spirit subsystem emit purple and yellow blinking lights. These colored lights are reflected from the paint on the course to the IR sensors of the navegation system. These wavelengths of light tamper with the color of light which is being recieved by the IR sensors. This creates inconsistencies in the lines which would be percieved by the line following program. The solution to this issue is not placing the LED strips on the front of the robot. This prevents the light from refelcting onto the IR sensors. The LED lights being secured to the rear of the robot does not create issues with the IR sensors due to the angle of the emmitted light. This specifictaion restricts constraint 1 by restricting the represenation of the university. This is comepensated by painting a gold stripe above a purple stripe on the front border of the chassis.



## BOM

|Item                     |Description                                                        |Subsystem  |Part Number  |Manufacturer|Quantity|Price  |Total Price|
|-------------------------|-------------------------------------------------------------------|-----------|-------------|------------|--------|-------|-----------|
|5mm LEDs - Yellow        |Yellow 5mm LED attached to a wire and a series impedance of 0.25 W.|Team Spirit|W04127_3-US-1|DORHEA      |100     |$0.0799|$7.99      |
|5mm LEDs - Purple        |Purple 5mm LED attached to a wire and a series impedance of 0.25 W.|Team Spirit|‎W04127_6-US-1|DORHEA      |100     |$0.0799|$7.99      |
|N - Channel MOSFET       | 30 A,  60 V rated N channel MOSFET.                               |Team Spirit|RFP30N06LE   |FAIRCHILD   |1       |$7.99  |$7.99      | 
|                         |                                                                   |           |             |            |        |       |$23.97a    | 
 
