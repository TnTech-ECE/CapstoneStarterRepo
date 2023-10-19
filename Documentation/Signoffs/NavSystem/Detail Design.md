## Function of the Subsystem

The Navigation System serves as the central control hub, responsible for directing the robot as it traverses its predefined course.
The navigation system will use an array of infrared avoidance sensors to detect the yellow line. These sensors output low on black and dark colors, and high on white and light colors. The array will output digital bits 

## Constraints

- IEC 61920 meaning the array has an operating wavelength of 750nm to 1mm and does not exceed this boundary. This will be controlled by using the datasheet for any purchased parts for the navigation system.
- The array must have sensors spaced apart closer than the width of the yellow line.

## Buildable Schematic

The image below shows the sensor array that will be used in the construction of the navigation system. 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Sensor%20Array.jpg)

The sensor array will be connected to the main controller in order to recieve power and transmit the I2C data from the sensor to the main controller. It needs between 25mA and 180mA to operate, depending on the distance from the surfacce it will be sensing. This sensor array will be operating at 100mA to ensure it can sense the surface without the sensor dragging on the ground during the robot's traversal of the course. The image below shows how the IR sensor array will be connected to the power supply for the robot.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/IR%20Power%20Connection.png)

## Analysis

The control system for the navigation subsystem is shown below. This sytem is stable due to all the poles being in the left hand plane. This is shown in the second image below.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/IR%20Control%20Block.png)

![Alt text]()

## BOM

@@
|  Item  |  Description  | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|--------|---------------|-----------|-------------|--------------|----------|-------|-------------|
| IR Sensor | Sensor for the lines and navigation system | Navigation | SEN-13582 | Sparkfun | 1 | 34.50 | 34.50 |
