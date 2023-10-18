## Function of the Subsystem

The Navigation System serves as the central control hub, responsible for directing the robot as it traverses its predefined course.
The navigation system will use an array of infrared avoidance sensors to detect the yellow line. These sensors output low on black and dark colors, and high on white and light colors. The array will output digital bits 

## Constraints

- IEC 61920 meaning the array has an operating wavelength of 750nm to 1mm and does not exceed this boundary. This will be controlled by using the datasheet for any purchased parts for the navigation system.
- The array must have sensors spaced apart closer than the width of the yellow line.

## Buildable Schematic

The image below shows the sensor array that will be used in the construction of the navigation system. 

![Alt text]()

The image below shows the connections of the sensor array to the rest of the robot. It outlines how the digital bits will be transfered to the main controller.

![Alt text]()

## Analysis

The schematics from Digital are shown below detailing the operation and analysis of the sensor system, showing all four possible combinations of the two inputs and what signals they will send to the main controller.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Analysis-Cross.jpg)
![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Analysis-Straight.jpg)
![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Analysis-Right.jpg)
![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Analysis-Left.jpg)

@@
|  Item  |  Description  | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|--------|---------------|-----------|-------------|--------------|----------|-------|-------------|
| IR Sensor | Sensor for the lines and navigation system | Navigation | SEN-13582 | Sparkfun | 1 | 34.50 | 9.88 |
