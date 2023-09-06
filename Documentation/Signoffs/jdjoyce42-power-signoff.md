# Power Subsystem


  
 
## Function of the Subsystem

The purpose of this subsystem is to take the voltage supplied from a wall outlet and make it usable for the project. Every component of our project requires our circuit to be DC. So we have reviewed ways to implement this as efficiently as possible. It is more efficient for us to use a wall wart for our project. Wall warts have seen widespread use in the last ten or so years due to their low cost, ease of manufacture, versatility, and sonic improvements; equipment with external power supplies are usually quieter (all other things being equal) than equipment with internal supplies.We have looked into building our own circuit on a breadboard and just connecting it to the rest of the project, but that causes us to not meet the constraint of it looking clean and not distracting as opposed to simply having a wall wart. The wall wart is essentially doing what is shown in Figure 1. The device will take in the AC current from the wall and convert it to DC so it can work properly with the rest of our devices.


## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | System shall convert wall AC Voltage to 5V DC Voltage         | Design Constraint |
| 2   | Shall be able to supply 5V DC and 100mA of current to main processor subsystem                   | Design Constraint |
| 3   | Shall be able to supply 5V DC and 5.2mA of current to Error subsystem                           | Design Constraint |
| 4   | Shall be able to supply 5V DC and 5.2mA of current to Input subsystem                                 | Design Constraint |
| 5   | Shall be able to supply 12V DC and 100mA of current to Output subsystem                                      | Design Constraint |
| 6   | Shall meet the IEC 60950-1 Standard                                   | Design Constraint |


<sup>1</sup> The system will need to convert 110 to 120 AC Voltage to 5V DC in order for each device to be functional. The only subsystem that doesnt need 5V DC is the Output subsystem which requires 12V If this is not met it could damage something or cause it to just not work.

<sup>2</sup> The main processor subsystem requires 5V DC and 100mA of current in order for it to be functional. In order for the main system be

<sup>3</sup> The Error subsystem requires 5V DC and 5.2mA of current in order for it to be functional.This will allow the system to read errors efficiently.

<sup>4</sup> The Input Subsystem requires 5V DC and 5.2mA of current in order for it to be functional. This will allow the system to be able to receive inputs.


<sup>5</sup>  The Output subsystem requires 12V DC and 100mA of current in order for it to be functional. This will allow the sytem to produce a output.





## Buildable schematic 
<img width="965" alt="Screen Shot 2023-04-24 at 5 25 58 PM" src="https://user-images.githubusercontent.com/123600399/234129961-edd41715-b2dc-486b-a249-67669e363180.png">
This above image is the schematic showing how the TR154 will be set up and imlemented into our system.



## Analysis
### Explanation of Components

#### Chanzon

The Chanzon 12V 1.5A wall mount (wall wart style) has a power supply rating for 100-240VAC input and 12 Volts VDC output at 1.5A. The cable is 6 feet long and has a dotted line on it to signify the negative connection within it. The center of the plug of this device is where the positive connection is located (center positive). This cable meets all the requirements of the group in terms of a proper power supply.

### LM2596
The LM2596 is a buck converter that will be used to take the voltage from the wall wart and step it down to a voltage that the subsystems will need. It can be set to out voltages from a range of 1.25V - 35V. The maximum output current it can provide is 3A.

#### Further connections

THe end of the wallwart has a plug that will be removed to reveal the two wire connection. The two wires are going to the power supply rail that will be designed to supply the voltage across the entire system. They will be connected to their respective components with the negative wire being grounded and the positive being used to power each subsystem through the power supply rail. 


## BOM
| DEVICE            | Quantity | Price Per Unit | Total Price |
| ----------------- | -------- | -------------- | ----------- |
| Chanzon   | 1              | $11.99        | 11.99     |
| LM2596   | 1              | $5.49        | 5.49     |


## References


[1] Sweetwater, “Wall wart,” inSync, 10-Jun-1998. [Online]. Available: https://www.sweetwater.com/insync/wall-wart/. [Accessed: 16-Apr-2023]. 

[2] Amazon.com: Chanzon 12V 1.5a UL listed 18w AC DC switching power supply ... (n.d.-b). https://www.amazon.com/Chanzon-Switching-100-240V-Transformer-Security/dp/B07G12L4SC 

[3] Amazon.com: #10Gtek# Buck Converter step Down Module LM2596 DC to DC ... (n.d.-a). https://www.amazon.com/10Gtek-Voltage-Regulator-Converter-Step-Down/dp/B09LCNVB22 
