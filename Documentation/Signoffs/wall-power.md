# Wall power Subsystem:

My main wall power subsystem input 120v AC. The main wall power has a transformer convert AC to AC, then a buck converters DC to DC that is step down will output 5V DC and boost converters that will be a step up that output 15v DC. After that, it will feed the other two subsystems, the first subsystem needs a 5v DC, and the second subsystem needs a 15v DC. However, I have another subsystem, which is a backup battery. If the main wall power shuts down, a switch will activate the backup battery to feed the two subsystems. The main idea is to supply power to the device, building a circuit that will convert to DC and then distribute voltage to other subsystems.  
# Constraints
| No. | Constraints | Origin |
| --- | ----------- | ------ |
| 1.  | Voltage equivalence: The main wall power subsystem needs to protect devices from the damage caused by voltage and guarantee the safety of the electrical system, as well as preserve the whole subsystem.| System Requirements |
| 2.  | Transformer: A safe output voltage and the way to handle 120v AC input are requirements for the Transformer used to converter AC to AC.| System Requirements |
| 3.  | Must be A way to disconnect the power from the source.| System Requirements |
| 4.  | It should be within wire capabilities.| System Requirements |

1.	Mian Wall Power input 120V AC: The primary power source is the 120V AC mains supply. It is the electricity that can used to power many types of devices. Wall power has multiple uses, including lighting, running devices at home, and charging machines. That system offers it access to a conveniently available supply of electricity.
2.	Transformer: How does the Transformer raise voltage or lower voltage as we need it. So, the Transformer used to Converter from AC high voltage different AC low. That means doing step-down voltage.
3. Full wave bridge rectifier “FWR”: The FWR is a type of Full wave rectifier that uses four or more diodes in bridge a bridge circuit setup to effectively transform an alternating current AC into a direct current DC. Also, it shows that after converting, the current uses a single path. After the converter from AC to DC, we will get just the positive signals.
4. RC filter: Capacitor with Resister: Signal management and filtering are critical functions of electronic systems. Also, it will be smoothing the signals. 
5. Buck Converter: we use the buck to step down the voltage From DC to DC. We used the chip to do the process, and it was easy. For example, subsystem one needs 5v.  
6.	Boost: the step-up converter is a DC to DC that increases the voltage. That means DC voltage to another DC voltage. 
7.	Subsystem one: it needs to step down “Buck” for the Subsystem and its 5v dc, 50mA.
8.	Subsystem two: it needs to step up “Boost” for the Subsystem and its 15v dc, 50mA.

## Backup Battery Subsystem:
I am using the Backup Battery if the main wall power shuts down. However, that would make me do the Buck and Boost Converter to the battery a 15v, 50mA and 5v, 50mA. Also, inside the system, I have a kill switch. If something happens to the wall power, it will switch immediately to backup. The goal of the battery backup subsystem is to make sure that the first and second subsystems continue to function normally during power outages.

# Buildable Schematic:
![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/0aebbcb8-a28d-4c62-835a-21147e2b2240)
![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/cf989bcb-e552-427f-8fb7-f024b741f645)

# Analysis
Circuit explanation: 
1.  The input for wall power is 120v AC, 60 Hz. 
2. The output is needed to have two subsystems with an output of 15v DC, 50mA, And 5v DC, 50mA. 
3. Converter AC to AC 
4. Converter DC to DC 
5. Buck “step down the voltage” 
6.  Boost “Step up the voltage” 
7.  Back-Boots for Backup battery  

Calculations:
Input voltage = 120 V AC. 
Primary Voltage = 120 V AC,
Secondary Voltage = 120V * √(Lp/Ls) = 120V * √ (54/1) = 16.4 V
For the positive/negative cycle, two diodes are in conduction mode at a time, causing a voltage drop of 0.7*2=1.4 V
The output voltage across the R1 is (16.4-1.4) V DC = 15DC
![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/15c9f878-e6b5-41f9-ac4e-b48621441987)


 The circuit simulation was done by using KiCad software, as shown in Figure 1.

Figure 2: 


# BOM: 
| Part | Part Number | Quantity | Price per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Plug electric |  035-00101-2BP | 1 | $6.71 | $6.71 |
| Buck-Boost Converter | LTC3114-1  | 3 | $11.35 |$34.04 |
| Full wave Bridge Rectifier | TCT50-01E07AB | 1|$16.65 | $16.65 |
| Battery |ML12-12F2 |1| $27.99|$27.99|
| Resistor | R268|4| $0.10|$0.40|
| Resistor | R74|3| $0.10|$0.30|
| Total | ----- |-----| -----| $ 86.09 |

# References:
Power Electronics pdf, Daniel W. Hart Valparaiso University Valparaiso, Indiana

https://www.analog.com/media/en/technical-documentation/data-sheets/LTC3114-1.pdf?ADICID=SYND_WW_P682800_PF-spglobal?hkey=EF798316E3902B6ED9A73243A3159BB0

https://www.mouser.com/ProductDetail/Triad-Magnetics/TCT50-01E07AB?qs=b1anAsPanWyYuqQKXv%2FQQw%3D%3D

https://www.amazon.com/ML12-12-Battery-Terminal-Mighty-Product/dp/B00K53FG5Q/ref=sr_1_4?crid=2ENRDXKVGB5V8&keywords=ml12-12%2Bbattery&qid=1698983669&s=electronics&sprefix=ML12-12%2B%2Celectronics%2C153&sr=1-4&th=1

