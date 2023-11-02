## Functionality

![Alt text]()

The purpose of the team spirit subsystem is to create a luminous and undeniable representation of TTU at the SECON robotics competition. It receives a signal and creates a display of purple and yellow blinking lights which are meant to represent Tennessee Tech University. 

The team spirit subsystem is nonoperational prior to entry of the thruster assembly zone. Upon entry into the thruster assembly zone the lights receive a signal and begin blinking. The lights remain on displaying a blinking pattern until the robot is powered off.

## Constraints and Standards

## Buildable

The competition requires that the team spirit display be dynamic and highly visible to represent the team and university. The perimeter of the robot is 44 inches. Each side of the robot is eleven inches. The led light will line the rear and side outer panels of the robot. The front will not be lined due to interference with the IR sensors of the navigation system. The team spirit system will utilize 2 circuits with one circuit of thirty-three purple LED lights with series resistances, and another circuit of thirty-three yellow LED lights with series resistances. These two strips of LED lights will be present at 1-inch increments around the robot. The series resistance provides the LEDs with overcurrent protection and prevents potential damage to the components. The gold strip will be placed above the purple strip on the siding of the robot. This system requires two digital inputs from the microcontroller of the main controller system. These digital inputs will control both strips creating the blinking pattern. The frequency of the blinking will be controlled by a function being looped outputting to each strip 2 times each second, or at a rate of 30 Hz. This can be done by utilizing delays between steps in the looped program.

Purple LED:

The purple LED is a 5mm round model with attached wires and a series resistance to protect the LED. The connected wiring and series resistances to the LEDs reduce the risk of a failure. The LEDs operate at 4 ~ 6 V+. 

Yellow LED:

The yellow LED is a 5mm round model with attached wires and a series resistance to protect the LED. The connected wiring and series resistances to the LEDs reduce the risk of a failure. The LEDs operate at 4 ~ 6  V+. 
