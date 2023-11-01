## Function of the Subsystem

The Navigation System serves as the central control hub, responsible for directing the robot as it traverses its predefined course.
The navigation system will use an array of infrared sensors to detect the yellow line. These sensors output low on black and dark colors, and high on white and light colors. The array will output digital bits in an I2C format

## Constraints

| Constraint | Detail | Origin |
|------------|--------|--------|
| 1. IEC 61920 | The array has an operating wavelength of 1mm to 50um and does not exceed this boundary | IEC 61920 |
| 2. Array Spacing | The array must have sensors spaced apart closer than the width of the yellow line in order for the 2 central sensors to detect the line when centered | Sensor Specifications |
| 3. Sampling Rate | The array must be accessed at a rate of at least 20Hz in order for the robot to keep on the line | Sensor Specifications |
| 4. Color Sensing | The array must detect the yellow line against the black background | Competition Specifications |
| 5. Height From Ground | The array must be within 1/2 inch from the line it is detecting | Sensor Specifications |
| 6. Perpindicular Line Sensing | The array must be able to detect the white line at the start of the crater | Competition Specifications |
| 7. Placement on Chassis | The array must be in the center of the front of the chassis of the robot | Sensor Specifications |

## Buildable Schematic

The image below shows the sensor array that will be used in the construction of the navigation system. 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Sensor%20Array.jpg)

The following shows a numbered image of the sensor array. It is followed by a description of each number and its function.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Sensor_Overview_numbers.png)

| Number | Name | Description |
|--------|------|-------------|
| 1. | IR Brightness Control and Indicator | The potentiometer controls the strength of the IR LEDs, and the IR PWR LED shows that strength as a brightness level. The brighter the LED the more IR is emitted. |
| 2. | Polarity Marking | Shows the polarity of the movement of the line across the sensor. |
| 3. | Robot Vision Indicators | Light up when the IR sensors are outputting high. |
| 4. | Digital Interface | Has 4 pins. 5 Volts in, ground, I2C data out, I2C Clock in. These are connected directly to the main controller. |
| 5. | I2C Pull Option Jumper | Defaulted to 3.3 V pull-up, can be changhed to 5V if needed |
| 6. | Mounting Holes | General Purpose mounting holes |
| 7. | IR Transducers | These emit and detect IR radiation |
| 8. | I2C Address Selsection | Jumpers to be set in accordance with the following table to set the desired outpur address. |

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/I2C%20Address%20Table.png)



The sensor array will be connected to the main controller in order to recieve power and transmit the I2C data from the sensor to the main controller. It needs between 25mA and 180mA to operate, depending on the distance from the surfacce it will be sensing. This sensor array will be operating at 100mA to ensure it can sense the surface without the sensor dragging on the ground during the robot's traversal of the course. The image below shows how the IR sensor array will be connected to the power supply for the robot. The following image shows how the sensor array is connected to the main controller. The main controller in this schematic is a stand in, as the precise controller has not yet been designed.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/IR%20to%20MC%20Connections%20KiCad.png)

The following shows the connection of the sensor array to a potential controller. 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/Sensor%20Array%20Connections.jpg)

The following is a 3D model of where the sensor package will go on the robot. The sensor array is shown as the purple block on the underside of the robot chassis. The main controller is shown as the blue block, and the power system is the green block. The red wires are the main voltage supply, supplying 5 Volts to the sensor array, and the black wires are the ground connections. The yellow wire is the I2C data cable and the pink wire is the I2C clock data. The sensor array is bolted on to the chassis through the mounting holes on the sensor, as shown above in number 6.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/3D%20Model%20Nav%20Sys.png)

## Analysis

Constraint 1 Solution: 

The array must have an operating wavelength between 1mm and 50um. The sensor used in this design has an adjustable operating wavelength that averages 940nm. This can be seen on page 3 of the datasheet.

Constraint 2 Solution:

The sensor array must have two sensors detecting the yellow line when it is centered. The yellow line is 1 inch in width and the array has sensors spaced 1/2 inch apart. This ensures that the center two sensors are detecting the yellow line simultaneously when the robot is centered on the line. This allows for the main controller to know when the robot has shifted off center and is able to make adjustments accordingly.

Constraint 3 Solution:

The senor must be smapled at a frewuency of at least 20Hz. The sensor array has a sampling frequency of 4kHz, ensurring that when the micro controller accesses it it will have refreshed and have new information avaliable. This can be seen on the installation guide provided with the sensor array. The 20 Hz is sufficient because the drive train will not be able to adjust the robots position quicker than that, so the microcontroller is not overloaded with data from the sensor.

Constraint 4 Solution:

The array must be able to read the yellow line on a black background. The array outputs a high signal on dark colors and a low signal on light colors. This allows for the sensor to output a low signal from the sensors that see the line and a high signal from those that do not. The micro controller can read this information to determine the robot's position above the line.

Constraint 5 Solution:

The array must be within 1/2 inch of the yellow line. In order for the sensor array to read the line it must be within 1/4 to 3/4 inches from the line it is detecting. Mounting the sensor array on th eunderside of the robot and ensuring the chassis has a mounting point with only a 1/2 inch of clearance allows for this constraint to be met. As shown in the figure below, the sensor array will be mounted 1/2 inch above the surface of the board.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/NavSystem/3D%20Model%20Front.png)

Constraint 6 Solution:

The array must be able to detect the white perpidicular line at the start and end of the crater. This is accomplished becaues the entire array will output a low signal on the white colored line. Having all the sensors output low will signal the main controller that a white line has been reached.

Constraint 7 Solution:

The sensor must be in the center of the front of the chassis of the robot. This is to ensure that the robot stays centered over the yellow line whilst moving along the course. This is accomplised by having the sensor array 4 inches from each side of the robot chassis.

## BOM

|  Item  |  Description  | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|--------|---------------|-----------|-------------|--------------|----------|-------|-------------|
| IR Sensor | Sensor for the lines and navigation system | Navigation | SEN-13582 | Sparkfun | 1 | 34.50 | 34.50 |
