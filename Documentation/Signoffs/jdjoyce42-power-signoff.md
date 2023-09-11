# Power Subsystem


  
 
## Function of the Subsystem

The purpose of this subsystem is to take the voltage supplied from a wall outlet and make it usable for the project. This will be done by supplying each subsystem with their respective DC voltagaes.


## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | System shall convert wall AC Voltage to a voltage that can range from 11.4V to 12.6V        | Design Constraint |
| 2   | Shall be able to supply 5V DC and 100mA of current to main processor subsystem                   | Design Constraint |
| 3   | Shall be able to supply 5V DC and 5.2mA of current to Error subsystem                           | Design Constraint |
| 4   | Shall be able to supply 5V DC and 5.2mA of current to Input subsystem                                 | Design Constraint |
| 5   | Shall be able to supply 12V DC and 100mA of current to Output subsystem                                      | Design Constraint |
| 6   | System shall be powered by a standard wall outlet                                 | Design Constraint |
| 7   | System shall follow OSHA standard 1910.304 - 305                                 | Design Constraint |
| 8   |  System shall follow Standard IEC 60950-1                                | Design Constraint |


<sup>1</sup> The system will need to convert 110 to 120 AC Voltage to 5V DC in order for each device to be functional. The only subsystem that doesnt need 5V DC is the Output subsystem which requires 12V If this is not met it could damage something or cause it to just not work.

<sup>2</sup> The main processor subsystem requires 5V DC and 100mA of current in order for it to be functional. In order for the main system be

<sup>3</sup> The Error subsystem requires 5V DC and 5.2mA of current in order for it to be functional.This will allow the system to read errors efficiently.

<sup>4</sup> The Input Subsystem requires 5V DC and 5.2mA of current in order for it to be functional. This will allow the system to be able to receive inputs.


<sup>5</sup>  The Output subsystem requires 12V DC and 100mA of current in order for it to be functional. This will allow the sytem to produce a output.


<sup>6</sup>  The system will be powered by a standard wall outlet in order to avoid the use of batteries and enable it to be used for longer periods of time.


<sup>7</sup>  The system shall follow OSHA standard 1910.304 - 305 which  provides a in depth guide for  safety and regulation of wired power.


<sup>8</sup>  The system shall follow IEC standard 60950-1 which deals with wired and battery powered devices below 600V. This will assist in elminating harm form electric shock, fire, and mechanical instability.




## Buildable schematic 
<img width="965" alt="Screen Shot 2023-04-24 at 5 25 58 PM" src="https://user-images.githubusercontent.com/123600399/234129961-edd41715-b2dc-486b-a249-67669e363180.png">
This above image is the schematic showing how the TR154 will be set up and imlemented into our system.



## Analysis

### Power
how much wattage it needs, and why i chose this wall wart. The system will require about 18 Watts for power. This system will utilize a wall wart in order to supply the DC power required.

The Chanzon 12V 1.5A wall mount (wall wart style) has a power supply rating for 100-240VAC input and 12 Volts VDC output at 1.5A. The cable is 6 feet long and has a dotted line on it to signify the negative connection within it. The center of the plug of this device is where the positive connection is located (center positive). This cable meets all the requirements of the group in terms of a proper power supply.

### Input

The input for this subsystem is the 100-240 VAC coming from the wall outlet.

### Output

This system will provide the correct power to each subsystem for the project. It will be connected to a power rail then use a buck converter to step down the voltage provided by the wall wart to match the voltage required for the following subsystems: main processor, Input, and Error. These three subsystems require 5V DC. The output subsystem requires 12V so it wont need to be connected to the buck converter.

The buck converter in use will be the LM2596. It can be set to out voltages from a range of 1.25V - 35V. The maximum output current it can provide is 3A.

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
