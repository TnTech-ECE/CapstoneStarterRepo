# Controller System
## Function of the system

The goal of the system is to read the sensor values, compute the efficiency of the electrolyzer and output the rating to a display. The subsystem consists of a microcontroller that will perform the calculations, an energy metering IC to determine how much power the electrolyzer is using, and a flow rate sensor to determine gas content. The sensor readings and efficiency rating will then be output to a serial terminal where it can be viewed.
##### Psuedo Code Flowchart
<img src="/Documentation/Images/Controller_System/Conceptual/PseudoCodeFlowchart.PNG" width="40%" height="40%">


## Constraints
| No. | Constraints                                                                                   | Origin            |
| --- | --------------------------------------------------------------------------------------------- | ----------------- |
| 1   | Shall accurately measure the electrical efficiency of the electrolyzer                        | Design Constraint |
| 2   | Shall use sensors to measure gas output and electrical input                                  | Design Constraint |
| 3   | Shall output efficiency rating and sensor readings to a serial port                           | Design Constraint | 
| 4   | Display output shall be easy to read and simplistic.                                          | Ethics Constraint |

<sup>1</sup> Success of the subsystem requires that it is able to compute an efficiency rating of the electrolyzer. The computations are there to confirm if the methods of increasing the efficiency of electrolysis are successful.

<sup>2</sup> To compute an efficiency rating there will need to be a way to measure the energy input and output of the electrolyzer.

<sup>3</sup> For a user to view the efficiency rating and necessary sensor data there must be a way to view it. Using the serial port on a microcontroller the information can be viewed through an external device that can use a serial terminal.

<sup>4</sup> In order for the system to be accessible to the most amount of people the interface needs to be able to be easily understood.

## Buildable Schematic
<img src="/Documentation/Images/Controller_System/Buildable_Schematics/Controller_System_Schematic.PNG" width="90%" height="90%">

The above image showcases the full buildable schematic of the controller system. The schematic shows the required sensors as well as the way they connect to the other systems.

## Analysis

#### Input
The system will take inputs from the power system on how much power the system is using and from the electrolysis cell on how much gas the system is producing. 
#### Output
The system will output sensor data from the INA260 and SFM3003, as well as the calculations performed by the microcontroller.
#### INA260
The microcontroller will take input from the INA260. This sensor is responsible for determining how much power the system is using. The microcontroller will output this data to the serial terminal. [1]
#### SFM3003
The microcontroller will take input from the SFM3003. This is a sensor that will measure the flow rate of Brown's gas exiting the electrolysis cell, using the input from the sensor, the microcontroller can calculate how much gas is being generated. [2]
#### Arduino Uno Rev3
The Arduino Uno will be responsible for the sensor processing and efficiency calculations required for the system's success. [3]
#### Communications
The sensors and microcontroller will communicate through a communications protocol known as I^2C. This protocol is a bus interface connection that allows for multiple peripherals to communicate. The sensors and microcontroller will all be connected to D18 for the SDA port and D19 for the SCL port. [4]
#### Serial Terminal
The serial terminal will be how the microcontroller is able to communicate with a user. The terminal can be accessed using a laptop through Arduino's IDE in the Serial Monitor Tool. The Arduino IDE can be accessed with a Windows 10, Linux, or macOS operating system. [5]

## BOM
| Device | Quantity | Total Cost |
| ------ | -------- | -------------- |
| Arduino Uno Rev3 | 1 | $27.60 |
| Flowrate Sensor SFM3003 | 1 | $118.17 |
| Adafruit INA260 | 1 | $9.95  |

## References
[1] INA260 Precision Digital Current and Power Monitor, https://www.ti.com/lit/ds/symlink/ina260.pdf (accessed Oct. 29, 2023). 

[2] GF DS SFM3003-300 D3 - Mouser Electronics, https://www.mouser.com/datasheet/2/682/Sensirion_Mass_Flow_Meters_SFM3003_Datasheet-2492120.pdf (accessed Oct. 29, 2023). 

[3] Arduino® Uno R3, https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf (accessed Oct. 29, 2023). 

[4] I2C - SparkFun Learn, https://learn.sparkfun.com/tutorials/i2c/all (accessed Oct. 28, 2023). 

[5] “Software,” Arduino, https://www.arduino.cc/en/software (accessed Oct. 28, 2023). 

[6] Adafruit INA260 Current, Voltage, Power Sensor Breakout, https://cdn-learn.adafruit.com/downloads/pdf/adafruit-ina260-current-voltage-power-sensor-breakout.pdf (accessed Oct. 29, 2023). 

