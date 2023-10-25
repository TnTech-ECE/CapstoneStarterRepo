## Function of the Subsystem

The Navigation System serves as the central control hub, responsible for directing the robot as it traverses its predefined course.
The navigation system will use an array of infrared sensors to detect the yellow line. These sensors output low on black and dark colors, and high on white and light colors. The array will output digital bits in an I2C format

## Constraints

| Constraint | Detail | Adherance |
|------------|--------|-----------|
| 1. IEC 61920 | The array has an operating wavelength of 750nm to 1mm and does not exceed this boundary | This will be controlled by using the datasheet for any purchased parts for the navigation system |
| 2. Array Spacing | The array must have sensors spaced apart closer than the width of the yellow line | The array purchased will have the correct spacing |
| 3. Sampling Rate | The array must be accessed at a rate of at least 20Hz in order for the robot to keep on the line | The main controller will access the array to give input to the drive train |
| 4. Color Sensing | The array must detect the yellow line against the black background | The array will output a low signal on the yellow line and a high signal on the black. The main controller will look at where the low signals are in order for the drive train to make any neccessary adjustments |


## Buildable Schematic

The image below shows the sensor array that will be used in the construction of the navigation system. 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Sensor%20Array.jpg)

The sensor array will be connected to the main controller in order to recieve power and transmit the I2C data from the sensor to the main controller. It needs between 25mA and 180mA to operate, depending on the distance from the surfacce it will be sensing. This sensor array will be operating at 100mA to ensure it can sense the surface without the sensor dragging on the ground during the robot's traversal of the course. The image below shows how the IR sensor array will be connected to the power supply for the robot.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/IR%20Power%20Connection.png)

The following image shows how the sensor array is connected to the main controller. The main controller in this schematic is a stand in, as the precise controller has not yet been designed.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/IR%20to%20MC%20Connections.png)

The following is a 3D model of where the sensor package will go on the robot. The sensor array is shown as the purple block on the underside of the robot chassis. The main controller is shown as the blue block, and the power system is the green block. The red wires are the main voltage supply, supplying 5 Volts to the sensor array, and the black wires are the ground connections. The yellow wire is the I2C data cable and the pink wire is the I2C clock data. 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/3D%20Model%20Nav%20Sys.png)

## Analysis

The control system for the navigation subsystem is shown below. This sytem is stable due to all the poles being in the left hand plane. This is shown in the second image below. (I am still working on the analysis)

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/IR%20Control%20Block%202.png)

![Alt text]()

## BOM

@@
|  Item  |  Description  | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|--------|---------------|-----------|-------------|--------------|----------|-------|-------------|
| IR Sensor | Sensor for the lines and navigation system | Navigation | SEN-13582 | Sparkfun | 1 | 34.50 | 34.50 |
