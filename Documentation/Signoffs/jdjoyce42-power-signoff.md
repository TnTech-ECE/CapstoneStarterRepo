# Power Subsystem


  
 
## Function of the Subsystem

The purpose of this subsystem is to take the voltage supplied from a wall outlet and make it usuable for the project. Every component of our project requires our circuit to be DC. So we have reviewed ways to implement this as efficiently as possible. It is more efficient for us to use a wall wart for our project. Wall warts have seen widespread use in the last ten or so years due to their low cost, ease of manufacture, versatility, and sonic improvements; equipment with external power supplies are usually quieter (all other things being equal) than equipment with internal supplies.We have looked into building our own circuit on a breadboard and just connecting it to the rest of the project, but that causes us to not meet the constraint of it looking clean and not distracting as opposed to simply having a wall wart. The wall wart is essentially doing what is shown in Figure 1. The device will take in the AC current from the wall and convert it to DC so it can work properly with the rest of our devices.


## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | System shall convert wall AC Voltage to 5V DC Voltage         | Design Constraint |
| 2   | Shall be able to supply 5V DC and 500mA of current to main processor subsystem                   | Design Constraint |
| 3   | Shall be able to supply 5V DC and 3mA of current to Error subsystem                           | Design Constraint |
| 4   | Shall be able to supply 5V DC and 3mA of current to Input subsystem                                 | Design Constraint |
| 5   | Shall be able to supply 5V DC and 100mA of current to Output subsystem                                      | Design Constraint |
| 6   | Shall meet the IEC 60950-1 Standard                                   | Design Constraint |


<sup>1</sup> The system will need to convert 110 to 120 AC Voltage to 5V DC in order for each device to be functional. If this is not met it could damage something or cause it to just not work.

<sup>2</sup> The main processor subsystem requires 5V DC and 500mA of current in order for it to be functional. In order for the main system be

<sup>3</sup> The Error subsystem requires 5V DC and 3mA of current in order for it to be functional.This will allow the system to read errors efficiently.

<sup>4</sup> The Input Subsystem requires 5V DC and 3mA of current in order for it to be functional. This will allow the system to be able to receive inputs.


<sup>5</sup>  The Output subsystem requires 5V DC and 100mA of current in order for it to be functional. This will allow the sytem to produce a output.


<sup>6</sup> This standard that the subsystem will follow will allow the group to procede with testing and powering the system without the harm from electric shock, fire, and mechanical instability.




## Buildable schematic 
<img width="797" alt="Screen Shot 2023-04-23 at 5 49 00 PM" src="https://user-images.githubusercontent.com/123600399/233870336-950baad6-e783-4222-9fe7-68052d97cee2.png">
This above image is the schematic showing how the TR154 will be set up and imlemented into our system.



## Analysis
### Explanation of Components

#### TR154

The TR154 is a wall mount (wall wart style) power supply rated for 100-240VAC input and 5 VDC output at 2.5 amps. The 72 inch cable has tinned leads for use with products that have screw terminals for input power. The white line or printing on the insulation indicates negative polarity, while a red band indicates positive polarity. 
This wall mount power supply has a cable length of 72 inches. It is capable of taking 100-240 VAC and converting it into 5VDC. It meets all of the requirements that the group is looking for in terms of a proper power supply.



#### Further connections

The two wires are going to the power supply rail that will be designed to supply the voltage across the entire system. They will be connected to their respective components, with the red wire being for positive connection and black wire for negative connection.


## BOM
| DEVICE            | Quantity | Price Per Unit | Total Price |
| ----------------- | -------- | -------------- | ----------- |
| TR154   | 1              | $22.00        | 22.00     |


## References


[1] Sweetwater, “Wall wart,” inSync, 10-Jun-1998. [Online]. Available: https://www.sweetwater.com/insync/wall-wart/. [Accessed: 16-Apr-2023]. 

[2] “Wall Mount Power Supply, 100-240VAC to 5VDC @ 2.5A, tinned leads,” Sealevel, 21-Dec-2022. [Online]. Available: https://www.sealevel.com/product/5-vdc-12-5w-psu/. [Accessed: 16-Apr-2023]. 
