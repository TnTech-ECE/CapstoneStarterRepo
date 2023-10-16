##Function of the Subsystem

The Navigation System serves as the central control hub, responsible for directing the robot as it traverses its predefined course. Its operation begins with the reception of the start state signal from the micro-controller, signifying the system's readiness. Once initiated, the Navigation System tracks a distinctive yellow line across the course and sends a signal to the micro-controller. When the robot reaches a turn in the yellow line, it communicates with the micro-controller, directing the robot to execute the turn. The navigation system is continuously monitoring the line sensor to ensure precise completion of the maneuver. After the turn, the robot straightens itself for the next curve. At the first gap line, the Navigation System sends a signal to the cross-gap state of the micro-controller. Upon detecting the second gap line, the line sensor relays data, prompting the Navigation System to send signals back to the micro-controller: one for regular forward motion and the other to activate the 'Spirit State.' The robot continues its journey until it has navigated the entire course, receives a shutdown command, or runs out of line to read, ensuring precision and efficiency in its navigation tasks. This robust design framework lays the foundation for the successful execution of the robot's course traversal.

The navigation system will use 2 infrared avoidance sensors to detect the yellow line. These sensors output low on black and dark colors, and high on white and light colors. One sensor will be posistioned on the left side of the yellow line, and the other will be on the right. This is so the robot can tell which way it needs to turn to stay centered on the line. If the left sensor detects a line when the right sensor does not, the robot needs to turn left, and a signal will be sent to the main controller. If the right sensor detects a line when the left sensor does not, the robot needs to turn right, and a signal will be sent to the main controller. If both sensors detect a line, it will send a signal to the main controller to enter the cross gap state, or to exit the cross gap state depending on which time the cross gap state has been activated.

##Constraints

The navigation system is constrained in the following ways. It must have two sensors in order to detect each side of the line and navigate properly. The sensors must adhere to IEC 61920 and be classified according to this standard as IR receivers. This means they have an operating wavelength of 750nm to 1mm and does not exceed this boundary. This will be controlled by using the datasheet for any purchased parts for the navigation system.

##Buildable Schematic

The circuit diagram below shows how the sensors are designed and wired. The second image shows the finalized circuit construction of the sensor. 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Sensor%20Circuit%20Diagram.jpeg)
![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/IR%20Sensor.jpeg)

##Analysis

The schematics from Digital are shown below detailing the operation and analysis of the sensor system, showing all four possible combinations of the two inputs and what signals they will send to the main controller.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Analysis-Cross.jpg)
![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Analysis-Straight.jpg)
![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Analysis-Right.jpg)
![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Analysis-Left.jpg)
