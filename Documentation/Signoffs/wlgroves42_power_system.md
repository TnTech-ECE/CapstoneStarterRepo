# Power Subsystem

## Function of the Subsystem

This subsystem's purpose is to allow power supplied from a wall outlet to be used in our device.


## Constraints

| No. | Constraints                                                                         | Origin            |
| --- | ----------------------------------------------------------------------------------- | ----------------- |
| 1   | The system shall convert wall AC Voltage to DC voltage | Design Constraint |
| 2   | The system shall comply with NFPA 70, in reference to all wiring and power consumption| Design Constraint/ NFPA 70 |
| 3   | The system shall not have fluctuations in voltage of greater or less than 10 volts compared to the rated voltage                          | Design Constraints |
| 4   | The system shall be able to power multpile different devices with different rated voltages | Design Constraint |

<sup>1</sup> All components will be powered with DC inputs, ensuring the system is more easily buildable, and more consistent between subsystems.

| Device          | Voltage |
| ----------------- | ------------------------ |
| Pulse Inverter (Capacitor Input)     | 12 V                    |
| Water Flow Valve             | 12 V                   |
| Water Flow Sensor             | 12 V                    |
| Power Sensor            |  5 V                  |
| Gas Flow Sensor           | 5 V                   |

The above table lists the rated voltages of each device.

<sup>2</sup> Different subsystems require different voltages. This introduces some chall

<sup>3</sup>  A standard wall outlet will be used to power the device to avoid the issue of nonstandardized outlets needed to be present in the home of the user



## Buildable schematic 



*Figure 1. Power Subsystem buildable schematic.*




## Analysis

| DEVICE            | Power |Total Power |
| ----------------- | ------------------------ | ------------------------ | 
| Pulse Inverter    | 2.5 W                    |                    | 
| Water Flow Valve         | 18 W                     |                    | 
| Water Level Sensor            | 60 mW                    |                    | 
| Power Sensor            | 1.55 mW                    |                   | 
| Gas Flow Sensor            | 19 mW                   |                   |
|            |                  |                   |


### Fulfilling Constraints


   There will be 2 seperate power systems: one running on 12 V, the other running on 5 V. The wall outlet will be split to 2 distinct transformers that step down to the appropriate voltages.

   To en


     

 The below equation was used for the power calculations for all devices.
~~~math
P = VI
~~~



### Power
The system will require about 18 Watts of power. This system will utilize a wall wart to supply the DC power required.


### Input

The input for this subsystem is the 100-240 VAC coming from the wall outlet.

### Output

This system will provide the correct power to each subsystem for the project. It will be connected to a power rail and then use a buck converter to step down the voltage provided by the wall wart to match the voltage required for the following subsystems: main processor, input, and error. These three subsystems require 5V DC. The output subsystem requires 12V so it will receive power from a separate wall wart.

The buck converter in use will be the LM2596 [10][3]. It can be set to out voltages from a range of 1.25V - 35V. The maximum output current it can provide is 3A. 

#### Further connections

The end of the wallwart has a plug that will be removed to reveal the two-wire connection. The two wires are going to the power supply rail on a soldered breadboard designed to supply the voltage across the entire system. The breadboard is 2"x4" and will have designated columns for each voltage required. The first column will be for the output and provide 12V DC, the second column will provide 5V DC for the main processor, and input and error will have the last column requiring 10V and 5V DC. They will be connected with the negative wire being grounded and the positive being used to power each subsystem.

## Ripple considerations

#### LM741
For each device that is powered using the 5 VDC or - 5VDC signal from the buck converter stage the PSRR or SVRR must be analyzed to ensure ripple is minimized. For the LM741 the minimum SVRR is 86 dB [6]. Assuming the input ripple is the maximum value that could be seen from the buck converter (400 mV) the expected output ripple voltage can be calculated using the following equation: $86 = 20log(0.4 V/Vripple)$ where Vripple is the ripple that is seen by the LM741. Solving this equation for Vripple yields a ripple voltage of 20.05 µV, this is a very small ripple voltage and can be considered negligible since the output voltage would only swing up or down by 20.05 µV <sup>6</sup>.
#### TS472
For the TS472 the PSSR observed at a supply voltage of 5 V and a bus ripple of 200 mV is at minimum 70 dB at 10 kHz or above [5]. This is the input ripple voltage the manufacturer uses to calculate the gain. Using this ripple voltage we can calculate the expected output ripple using the following equation: $70 = 20log(0.2 V/Vout)$ where Vout is the swing in the output voltage of the TS472, solving yields Vout = 63.24 µV.



## BOM
| DEVICE            | Quantity | Price Per Unit | Total Price |
| ----------------- | -------- | -------------- | ----------- |
| Chanzon           | 1        | $11.99         | $11.99      |
| LM2596            | 1        | $5.49          | $5.49       |
| SchmalzTech Double Sided ENIG Protoboard            | 1        | $4.49          | $4.49       |

## References


[1] Sweetwater, “Wall wart,” inSync, 10-Jun-1998. [Online]. Available: https://www.sweetwater.com/insync/wall-wart/. [Accessed: 16-Apr-2023]. 

[2] Amazon.com: Chanzon 12V 1.5a UL listed 18w AC DC switching power supply ... (n.d.-b). https://www.amazon.com/Chanzon-Switching-100-240V-Transformer-Security/dp/B07G12L4SC 

[3] Amazon.com: #10Gtek# Buck Converter Step Down Module LM2596 DC to DC ... (n.d.-a). https://www.amazon.com/10Gtek-Voltage-Regulator-Converter-Step-Down/dp/B09LCNVB22 

[4] LM2596S adjustable DC-DC step-down module. ProtoSupplies. (2023, March 19). https://protosupplies.com/product/lm2596s-adjustable-dc-dc-step-down-module/ 



[5] “TS472,” STMicroelectronics, https://www.st.com/en/audio-ics/ts472.html [Accessed: 31-Aug-2023].

[6] "LM741," Texas Instruments, https://www.ti.com/product/LM741?qgpn=lm741 [Accessed: 31-Aug-2023]

[7] “CMA-4544PF-W: Digi-Key Electronics,” Digikey, https://www.digikey.com/en/products/detail/cui-devices/CMA-4544PF-W/1869981 [Accessed: 9-Sept-2023].

[8] Sure Electronics, "AA-AB32231 2x8W 1x16W at 4 Ohm TPA3110 Class D Audio Amplifier Board" AA-AB32231 datasheet, 2011, (https://www.parts-express.com/pedocs/manuals/320-329--aa-ab32231-1-or-2-channel-configurable-16w-amp-board.pdf) (accessed September 9th, 2023).

[9] Installation, C. H. (2023, August 25). How do you balance performance, reliability, and cost when installing a power supply?. How to Install a Power Supply: Tips on Wattage, Efficiency, and Quality. https://www.linkedin.com/advice/0/how-do-you-balance-performance-reliability

[10] ONSEMI. (n.d.). LM2596 - 3.0 A, step-down switching regulator . LM2596 Datasheet. https://www.onsemi.com/pdf/datasheet/lm2596-d.pdf 

[11] Schmalztech double sided Enig protoboard, solderable breadboard ... (n.d.). https://www.amazon.com/SchmalzTech-Protoboard-Solderable-Breadboard-Electronic/dp/B0C3YYG6CV 

[12] https://www.ti.com/lit/ds/symlink/lm2596.pdf?ts=1696038261274&ref_url=https%253A%252F%252Fwww.google.com%252F

[13] https://www.mouser.com/datasheet/2/609/1529fb-3123515.pdf

[14] https://www.ti.com/lit/an/slyt202/slyt202.pdf
