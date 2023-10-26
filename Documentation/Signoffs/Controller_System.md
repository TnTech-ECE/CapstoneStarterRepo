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

<sup>2</sup> To be able to compute an efficiency rating there will need to be a way to measure the energy input and output of the electrolyzer.

<sup>3</sup> For a user to view the efficiency rating and necessary sensor data there must be a way to view it. Using the serial port on a microcontroller the information can be viewed through an external device that can use a serial terminal.

<sup>4</sup> In order for the system to be accessible to the most amount of people the interface needs to be able to be easily understood.

## Buildable Schematic



## Analysis


## BOM
| Device | Quantity | Price per Unit | Total Cost |
| ------ | -------- | -------------- | ---------- |
| Microcontroller | 1 | ????? | ????? |
| Flowrate Sensor | 1 | ????? | ?????? | ?????? |
| Energy Metering IC ADE9153A | 1 | ???? | ????? |

## References
https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf
https://www.analog.com/en/products/ade9153a.html
https://www.renesas.com/us/en/document/dst/fs1012-datasheet
https://mm.digikey.com/Volume0/opasdata/d220001/medias/docus/307/Sensirion_Mass_Flow_Meters_SFM3300_Datasheet.pdf
