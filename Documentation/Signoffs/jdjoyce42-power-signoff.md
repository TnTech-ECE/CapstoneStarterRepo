# Power Subsystem
 
## Function of the Subsystem

The purpose of this subsystem is to take the voltage supplied from a wall outlet and make it usable for the project. This will be done by supplying each subsystem with its respective DC voltages.


## Constraints

| No. | Constraints                                                                         | Origin            |
| --- | ----------------------------------------------------------------------------------- | ----------------- |
| 1   | System shall convert wall AC Voltage to a voltage that can range from 4.4V to 5.6V  | Design Constraint |
| 2   | Shall supply the required voltage and current to all of the devices that need to be powered in the system  | Design Constraint |
| 3   | System shall be powered by a standard wall outlet                                   | Design Constraint |
| 4   | System shall follow OSHA standard 1910.304 - 305                                    | OSHA Standard     |
| 5   | System shall follow Standard IEC 60950-1                                            | IEC Standard      |


<sup>1</sup> The system will need to convert 110 to 120 AC Voltage to 5V DC for each device to be functional. A small margin of error is expected due to unideal power supply ripple and other nonlinear effects.

<sup>2</sup> In order for all the subsystems to be powered, the power subsystem must be able to individually supply all the needed power to each subsystem. 


<sup>3</sup>  The system will be powered by a standard wall outlet to avoid the use of batteries and enable it to be used for longer periods.


<sup>4</sup>  The system shall follow OSHA standard 1910.304 - 305 which provides an in-depth guide for the safety and regulation of wired power.

<sup>5</sup>  The system shall follow IEC standard 60950-1 which deals with wired and battery-powered devices below 600V. This will assist in eliminating harm from electric shock, fire, and mechanical instability.




## Buildable schematic 

![image](https://github.com/CarsonDPope/Active-Noise-Control-With-Wall-Transmission-Detection/assets/123600399/818abf47-3dd7-4111-a9a9-87ca63c83764)

*Figure 1. Power Subsystem buildable schematic.*

The Error and Input will be wired by using jumper wires. 
The Main processor will be wired by using a USB 2.0 micro.


## Analysis
| DEVICE            | Maximum Required Voltage | Maximum Required Current |
| ----------------- | ------------------------ | ------------------------ | 
| Main Processor    | 5 V                      | 100 mA                   | 
| Input             | 5 V                      | 8.5 mA                   | 
| Error             | 5 V                      | 8.5 mA                   | 
| Output            | 12 V                     | xxxx mA                  | 

The above table describes the maximum required supply voltage and supply current for each subsystem. The input and error subsystems require an identical amount of power to function. There are the devices that need power in the input and error subsystems respectively. 

Main Processor


Input and Error
- The TS472 microphone preamplifier must be driven with a 5 VDC signal at a maximum supply current of 2.4 mA [6].
- The LM741 operational amplifier will be driven with a +5 VDC signal and a -5 VDC signal at a maximum supply current of 2.8 mA[7].
- The CMA-4544PF-W electret microphone will be driven with a 5 VDC signal at a maximum supply current of 0.5 mA [8]. 

Therefore, the total supply current will be 2.4 mA + 2(2.8 mA) + 0.5 mA = 8.5 mA. Since the LM741 requires two supply pins, the maximum supply current must be doubled. The total output power is $$P=VI=5 V*8.5 mA = 42.5 mW$$


The below equations show the amount of power required to operate.
~~~math
P_{Main Processor} = VI = (5V)(500mA) = 2.5W
~~~
~~~math
P_{Error} = VI = (5V)(8.5mA) = 0.0425W
~~~
~~~math
P_{Input} = VI = (5V)(8.5mA) = 0.0425W
~~~
~~~math
P_{Output} = VI =(12V)(1.33A) = 15.96W
~~~
The below equation shows the total amount of power needed from the buck converter for the Main processor, Input, and Error subsystems.
~~~math
P_{Buck Conveter Total} = (2.5W) + 2(8.5mA) = 2.585W
~~~
The below equation shows the power needed for the output subsystem.
~~~math
P_{Output Total} = 15.96W
~~~
The following equation shows the amount of power being delivered from the buck converter to supply 5V DC.
~~~math
P_{Buck Conveter} = (5V)(3A) = 15W
~~~

The efficiency of the buck converter is 92% so the power loss between input and outputs will be about percent. Taking the total output power (2.585W) and multiplying it by 8% equals 0.2068W. This means that the minimum power that the wall wart needs to supply is 2.585 ± 0.2068 W. The wall wart supplies 18 watts and the buck converter supplies 15 watts. This is well over the power requirement so there won't be any problems with power.
### Power
The system will require about 18 Watts of power. This system will utilize a wall wart to supply the DC power required.

The Chanzon 12V 1.5A wall mount (wall wart style) has a power supply rating for 100-240VAC input and 12 Volts VDC output at 1.5A. The cable is 6 feet long and has a dotted line on it to signify the negative connection within it. The center of the plug of this device is where the positive connection is located (center positive). This cable meets all the requirements of the group in terms of a proper power supply.

### Input

The input for this subsystem is the 100-240 VAC coming from the wall outlet.

### Output

This system will provide the correct power to each subsystem for the project. It will be connected to a power rail and then use a buck converter to step down the voltage provided by the wall wart to match the voltage required for the following subsystems: main processor, Input, and Error. These three subsystems require 5V DC. The output subsystem requires 12V so it won't need to be connected to the buck converter, instead, it will receive power from a separate wall wart.

The buck converter in use will be the LM2596. It can be set to out voltages from a range of 1.25V - 35V. The maximum output current it can provide is 3A.

#### Further connections

The end of the wallwart has a plug that will be removed to reveal the two-wire connection. The two wires are going to the power supply rail designed to supply the voltage across the entire system. They will be connected to their respective components with the negative wire being grounded and the positive being used to power each subsystem through the power supply rail. 


## BOM
| DEVICE            | Quantity | Price Per Unit | Total Price |
| ----------------- | -------- | -------------- | ----------- |
| Chanzon           | 2        | $11.99         | $11.99      |
| LM2596            | 1        | $5.49          | $5.49       |
| PS-SP11111        | 1        | $19.98         | $19.98      |

## References


[1] Sweetwater, “Wall wart,” inSync, 10-Jun-1998. [Online]. Available: https://www.sweetwater.com/insync/wall-wart/. [Accessed: 16-Apr-2023]. 

[2] Amazon.com: Chanzon 12V 1.5a UL listed 18w AC DC switching power supply ... (n.d.-b). https://www.amazon.com/Chanzon-Switching-100-240V-Transformer-Security/dp/B07G12L4SC 

[3] Amazon.com: #10Gtek# Buck Converter Step Down Module LM2596 DC to DC ... (n.d.-a). https://www.amazon.com/10Gtek-Voltage-Regulator-Converter-Step-Down/dp/B09LCNVB22 

[4] Home. Parts Express. (n.d.). https://www.parts-express.com/Sure-PS-SP11111-12-VDC-3A-Power-Adapter-320-312?quantity=1 

[5] LM2596S adjustable DC-DC step-down module. ProtoSupplies. (2023, March 19). https://protosupplies.com/product/lm2596s-adjustable-dc-dc-step-down-module/ 




[6] “TS472,” STMicroelectronics, https://www.st.com/en/audio-ics/ts472.html [Accessed: 31-Aug-2023].

[7] "LM741," Texas Instruments, https://www.ti.com/product/LM741?qgpn=lm741 [Accessed: 31-Aug-2023]

[8] “CMA-4544PF-W: Digi-Key Electronics,” Digikey, https://www.digikey.com/en/products/detail/cui-devices/CMA-4544PF-W/1869981 [Accessed: 9-Sept-2023].
