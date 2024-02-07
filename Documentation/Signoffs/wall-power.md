# Wall power Subsystem:

My main wall power subsystem input 120v AC. The main wall power has a transformer convert AC to AC, then a buck converters DC to DC that is step down will output 5.5V DC and boost converters that will be a step up that output 9v DC. After that, it will feed the other two subsystems, the first subsystem needs a 5.5v DC, and the second subsystem needs a 9v DC. However, I have another subsystem, which is a backup battery. If the main wall power shuts down, a switch will activate the backup battery to feed the two subsystems. The main idea is to supply power to the device, building a circuit that will convert to DC and then distribute voltage to other subsystems.

# Constraints
| No. | Constraints | Origin |
| --- | ----------- | ------ |
| 1.  | Voltage equivalence: The main wall power subsystem needs to protect devices from the damage caused by voltage and guarantee the safety of the electrical system, as well as preserve the whole subsystem.| System Requirements |
| 2.  | Transformer: A safe output voltage and the way to handle 120v AC input are requirements for the Transformer used to converter AC to AC.| System Requirements |
| 3.  | Must be A way to disconnect the power from the source.| System Requirements |
| 4.  | It should be within wire capabilities.| System Requirements |

1.	Mian Wall Power input 120V AC: The primary power source is the 120V AC mains supply. It is the electricity that can used to power many types of devices. Wall power has multiple uses, including lighting, running devices at home, and charging machines. That system offers it access to a conveniently available supply of electricity.
2.	Transformer: How does the Transformer raise voltage or lower voltage? So, We need to do the Converter from AC high voltage different AC low. That means doing step-down voltage.
3.	Full wave bridge rectifier “FWR”: The FWR is a type of Full wave rectifier that uses four or more diodes in a bridge circuit setup to effectively transform an alternating current AC into a direct current DC. Also, it shows that the current uses a single path after converting. After the converter from AC to DC, we will get just the positive signals.
4.	RC filter: Capacitor with Resister: Signal management and filtering are critical functions of electronic systems. Also, it will be smoothing the signals. However, we should use the Step-down voltage From DC to DC. After the RC filter, the input voltage will be 20v DC. We used the chip to do the process. The buck-boost converter gets what we need to get the output of 12v DC. Then, we have power subsystems. The input voltage will be the same, and it's 12v DC.
5.	Controller: We have three systems, and their "chips" " are all buck-boost converters. Firstly, it is a controller or master switch between the wall power and backup battery, and this controller manages the voltage between them. The input comes with the same voltage, and it's 12v DC. The idea for the controller is that if the main wall power shuts down, a switch will activate the backup battery to feed the two subsystems. Secondly, the other two subsystems will be the same chips and buck converter. Subsystem one: it needs to step down "Buck" for the Subsystem and its 5.5v dc, 250mA. Subsystem two must step down "Bcuk" for the Subsystem and its 9v dc, 50mA.
6.	Use the Backup Battery if the main wall power shuts down. Also, the battery will be connected to the kill switch. If something happens to the wall power, the subsystems will change the switch immediately to the backup battery. Between the backup battery and the main wall, have a switch "controller" to manage all power from subsystems. The battery backup subsystem aims to ensure that the first and second subsystems usually function during power outages. The backup battery type is a 12-volt 12AH sealed lead acid AGM.



# Buildable Schematic:

<img width="554" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/fd44d2a2-c110-43f6-b50a-bfd37c17dc03">

Figure 1. Kicad schematic.


<img width="565" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/10b6a241-da31-40f5-92b7-01cc5ed3fb99">

Figure 2.Kicad schematic.

<img width="682" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/2e106e42-a74c-4504-aafa-09c2f7e3c4d4">

Figure 3.  LTspice circuit.

# Analysis
Circuit explanation: 
1.	The input for wall power is 120v AC, 60 Hz.
2.	Transformer from 120v AC to 24v AC 
3.	Full wave bridge rectifier 24v DC to 13.6v DC
4.	Boost-Buck converter  to get the output 12v
5.	Buck converter: “Step down the voltages for Subsystem One and Subsystem Two”
6.	The output needs to have two subsystems with an output of 9v DC, 60mA, And 5v DC, 250mA.

Calculations:

Transformer:
```math
Output \ Voltage \  =input\times\frac{ Turns\  secondary }{ Turns\ primary }
```
```math
Output \ Voltage \  =120\times\frac{ 200 }{ 1000 } = 24
```
Bridge Rectifier: 
The process for Bridge Rectifier from 120v to 24v
```math
Output \ Voltage \  ={2}{π}\times\ (vm)- (vr\times\ π )
```
```math
Output \ Voltage \  ={2}{π}\times\ (24\sqrt{2})- (0.7\ π )
```

```math
Output \ Voltage \  = 20v\ DV
```
| No. | Subsystem | Voltage | Current |
| --- | ----------- | ------ | ------ |
| 1  | Buck-Boost converter | 17 V | 0.3 A |

```math
{\rm V}_{IN} =  17V \  to \  21.03V
```
```math
{\rm V}_{OUT} = 12v
```
```math
{\rm Maximum \ I}_{OUT} \ (boost \ mode) = 0.7A
```
```math
{\rm R}_{LOAD(min)} = \frac{ 12 } { 0.7} = 17.1 Ω
```
```math
{\rm Maximum \ I}_{OUT} \ (buck \ mode) = 1A
```
```math
{\rm R}_{LOAD(min)} =  12 
```

```math
{\rm L} = 10uH 
``` 
```math
{\rm Inductance \ L} = 68uH
```
```math
{\rm f}_{SW} = 1.2MHz
```
```math

{\rm Switch \ pin \ minimum \ low \ t}_{low} = 0.05us
```

Inductor Selection:
From the datasheet, input 4.7uH, which performs best with an inductor.
```math
 {\rm ∆I _{L}}_{p-p(BUCK)}\ = \frac{V_{OUT}} {L\ }\  \ast\ (\frac{V_{IN}-{V_{OUT}}}{V_{IN}}) \ast\ (\frac{1}{f}-{t_{low}}) Amps
```
```math
 {\rm ∆I _{L}}_{p-p(BUCK)}\ = \frac{12} {68uH\ }\  \ast\ (\frac{{V22.03v}-{12v}}{22.03v}) \ast\ (\frac{1}{1.2MHz}-{0.05us}) Amps
```
```math
 {\rm ∆I _{L}}_{p-p(BUCK)}\ = 0.01228 \ Amps
```

Feedback voltage input:

```math
Vout  = 1+ \frac{Rtop} { Rbot} 
```
```math
12  = 1+ \frac{ 190k } {Rbot} 
```
```math
Rbot  \ (R4) = 17k
```


Input and Output Capacitor Selection:

From the datasheet, the input for Capacitor 10uH  and the output for Capacitor 44uF, which is the best performance with an inductor.

| No. | Subsystem | Voltage | Current |
| --- | ----------- | ------ | ------ |
| 2  | Data interpretation and Storage | 5.5 V | 0.25 A |
```math
{\rm V}_{IN} =  12V
```
```math
{\rm V}_{OUT} = 5.5v
```
```math
{\rm I}_{OUT} =  0.25A
```
```math
{\rm f}  = 2.25MHz 
```
Inductor Selection:
```math
L\ = \frac{V_{OUT}}{f\ \ast\ {\rm ∆I}_{L(max)}}\ \ast(1-\frac{V_{OUT}}{V_{IN(max)}})
```
```math
L\ =\ \ \frac{5.5V}{2.25MHz\ \ast\ (0.4\ (0.25A)}\ \ast(1-\frac{5.5V}{12V})
```
```math
L\ = 13.2 \mu H
```
So, the nearest for L is 15uH, and it fits well in the datasheet.

For the operating frequency, expected input and output voltages, and other information, can define the value of the ripple current.

```math
{\rm ∆I}_{L} = \frac{V_{OUT}}{f\ \ast\ L}\ \ast(1-\frac{V_{OUT}}{V_{IN(max)}})
```

```math
{\rm ∆I}_{L} = \frac{5.5V}{(2.25MHz\ \ast\ 13.2 \mu H)} \ast(1-\frac{5.5v}{12v})
```
```math
{\rm ∆I}_{L} = 0.100A
```
Feedback resistors Selection:
As given from the Datasheet, we can select a high resistor value for R6 to be 196kΩ.

```math
V_{OUT}=\ 0.6V\ \ast(1 +\frac{R_{6}}{R_{7}})

```
```math
5.5V=\ 0.6V\ \ast(1 +\frac{196kΩ}{R_{7}})
```
```math
R_{6}= 24kΩ
```

Input Capacitor :

As given in the Datasheet, the Input Capacitor is 10uF. This is enough for most uses.

```math
I_{RMS}\cong\ I_{OUT(max)}\ast\ \frac{V_{OUT}}{V_{IN(max)}}\ast{(\frac{V_{IN(max)}}{V_{OUT}}-1)}^\frac{1}{2}
```

```math
I_{RMS}\cong\ 0.25A\ast\ \frac{5.5V}{12V}\ast{(\frac{12V}{5.5V}-1)}^\frac{1}{2}
```

```math
I_{RMS}\cong\ 0.1245A
```
Output Capacitor:
As given in the Datasheet, the Input Capacitor is 22uF. This is best for use. The practical series establishes the quantity of bulk capacitance required to ensure the control loop is stable and the choice of C OUT resistance (ESR) necessary to reduce voltage ripple and load step transients.


| No. | Subsystem | Voltage | Current |
| --- | ----------- | ------ | ------ |
| 3  | Sensor | 9 V | 0.05 A |

```math
{\rm V}_{IN} =  12V
```
```math
{\rm V}_{OUT} = 9v
```
```math
{\rm I}_{OUT} =  0.5A
```

```math
{\rm f}  = 2.25MHz 
```

Inductor Selection:

```math
L\ = \frac{V_{OUT}}{f\ \ast\ {\rm ∆I}_{L(max)}}\ \ast(1-\frac{V_{OUT}}{V_{IN(max)}})
```
```math
L\ =\ \ \frac{9V}{2.25MHz\ \ast\ (0.4\ (0.05A)}\ \ast(1-\frac{9V}{12V})
```
```math
L\ = 50 \mu H
```
So, the nearest for L is 68uH, and it fits well in the datasheet.

For the operating frequency, expected input and output voltages, and other information, can define the value of the ripple current.

```math
{\rm ∆I}_{L} = \frac{V_{OUT}}{f\ \ast\ L}\ \ast(1-\frac{V_{OUT}}{V_{IN(max)}})
```

```math
{\rm ∆I}_{L} = \frac{9V}{(2.25MHz\ \ast\ 50 \mu H)} \ast(1-\frac{9v}{12v})
```
```math
{\rm ∆I}_{L} = 0.02A
```
Feedback resistors Selection:
As given in the Datasheet, I select the resistor value for R8 to be 140kΩ.

```math
V_{OUT}=\ 0.6V\ \ast(1 +\frac{R_{8}}{R_{9}})

```
```math
9V=\ 0.6V\ \ast(1 +\frac{140kΩ}{R_{9}})
```
```math
R_{9}= 9.5kΩ
```
Input Capacitor :

As given in the Datasheet, the Input Capacitor is 10uF. This is enough for most uses.

```math
I_{RMS}\cong\ I_{OUT(max)}\ast\ \frac{V_{OUT}}{V_{IN(max)}}\ast{(\frac{V_{IN(max)}}{V_{OUT}}-1)}^\frac{1}{2}
```

```math
I_{RMS}\cong\ 0.25A\ast\ \frac{9V}{12V}\ast{(\frac{12V}{9}-1)}^\frac{1}{2}
```

```math
I_{RMS}\cong\ 0.021A
```
Output Capacitor:

As given in the Datasheet, the Input Capacitor is 22uF. This is best for use. The practical series establishes the quantity of bulk capacitance required to ensure the control loop is stable and the choice of C OUT resistance (ESR) necessary to reduce voltage ripple and load step transients.
###  Ltspice simulations 
![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/85826a38-8647-45ef-94c7-22370cb69d43)
1. The Transformer

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/a22ae370-b5f8-4171-8fbe-c28a07cba32c)
2. The RC filter

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/75ef5c70-0ff6-4185-ae2e-67f3c96b0512)
Buck-boost converter

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/ba7a7f10-b724-4868-b76a-b7c61bd0ff23)
3. Buck converter for subsystem 5.5v

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/f2cf1a2d-a279-4222-b454-f5561ce36fdf)
4. Buck converter for subsystem 9v

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/f81d0f1a-620e-4a7e-a5b0-fd45ca79a210)

5. Final result

###  Backup Battery
| No. | Subsystem | Voltage | Current | Rated Wattage[W]| Hours per day used [ h ] | Energy Consumption [ Wh ] |
| --- | -------- | ------ | ----- | ------------------------ | --------- | ------------------ |
| a. | Sensor | 9 V | 0.06 A | 9 * 0.06 = 0.45W | 24h | 10.8Wh |
| b. | Data interpretation, Transmission, and Storage | 5 V | 0.25A | 5 * 0.25 = 1.25W | 24h | 30Wh | 
| | | | | Total Rated Wattage = 1.7W | | Energy Consumption=40.8Wh |

The backup battery selection is going to be dependent on multiple aspects. since we are using a power controller with an input voltage of 12 V DC. Therefore, the battery selected to be a 12V battery Seal lead acid. Moreover, the battery capacity ( Ah ) will be determined by applying these calculations.
Referring to the Table [ ]

```math
Total\ amp-hour\ demand\ per\ day = \frac{Total\ energy\ demand\ per\ day }{ Battery\ Voltage }
```

```math
Total\ amp-hour\ demand\ per\ day = \frac{40.8Ah }{ 12h }
```

```math
Total\ amp-hour\ demand\ per\ day = {3.4 Ah} 
```
The days of storage are desired to be three days ( Autonomy ). Also, the allowable depth of discharge limit is 0.8.
Using the given values, we will be able to calculate the required battery capacity ( Ah)
```math
Required\ battery\ capacity (Ah)  = \frac{ amp -  hour\ demand\ per\ day \ \times\ Days\ of\ Autonomy } { Depth\ of\   discharge }
```

```math
Required \ battery \ capacity \ (Ah)  = \frac{ 3.4Ah \ \times\  3\ days } { 12V }
```
```math
Required \ battery \ capacity \ (Ah) = {12.75 Ah} 
```
The required battery capacity is 12.75 Ah therefore, increasing the battery capacity would be more convenient. The battery capacity ( Ah ) was selected to be 14 Ah. 

From using the calculation form datasheet[6]

# BOM: 
| Part | Part Number | Quantity | Price per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Plug electric |  035-00101-2BP | 1 | $6.71 | $6.71 |
| Buck-Boost Converter | LTC3114-1  | 1 | $11.35 |$11.35 |
| Buck Converter | LTC3621  | 2 | $7.38 |$14.76 |
| Transformer | TCT50-01E07AB | 1 | $19.99 | $19.99 |
| Full wave Bridge Rectifier | GBU404, MB12S-TP | 1| $1.36 | $1.36 |
| Battery |ML12-12F2 | 1 | $27.99 | $27.99 |
| Inductor 10uH | DFE201210U-R47MP2 | 1 | $0.32 | $0.32 | ----- |
| Inductor 15uH | XFL3012-153MEC | 1 | $2.08 | $2.08 | ----- |
| Inductor 68uH | MSS7348-683MEC | 1 | $2.62 | $2.62 | ----- |
| Resistor 270Ω | ERJ-U02D2700X | 1 | $0.10 | $0.10 |
| Resistor 20kΩ | RC0603FR-0720KL | 1 | $0.10| $0.10 |
| Resistor 56.2kΩ | CRCW201056K2FKEF | 1 | $0.29 | $0.29 |
| Resistor 190Ω | WSL2512R0190FEA18 | 1 | $0.10 | $0.10 |
| Resistor 17kΩ | RMCF0402FT16K9 | 1 | $0.10 | $0.10 |
| Resistor 196kΩ | ERJ-1GNF1963C | 1 | $0.1 | $0.10 |
| Resistor 24kΩ | ERJ-1GNF2402C | 1 | $0.1 | $0.10 |
| Resistor 140kΩ | CR0603-FX-1403ELF | 1 | $0.10 | $0.10 |
| Resistor 14kΩ | ERJ-1GNF1402C | 1 | $0.1 | $0.10 |
| capacitor 200uF | C2220C204KBGLCAUTO | 1 | $4.37 | $4.37 | ----- |
| capacitor 10uF | C3216JB1E106M160AB | 3 | $0.56 | $1.68 | ----- |
| capacitor 68uF | MSS7348-683MEC | 2 | $2.62 | $4.52 | ----- |
| capacitor 33nF | 1206CC333KAT2A | 1 | $0.71 | $0.71 | ----- |
| capacitor 10pF | KGQ05FCG1H100GH | 1 | $0.24 | $0.24 | ----- |
| capacitor 10nF | KAM15AR72A103KM | 1 | $0.31 | $0.31 | ----- |
| capacitor 4.7uF | C1608X5R1E475K080AC | 1 | $0.32 | $0.32 | ----- |
| capacitor 44uF | C1812C444K5GLCAUTO | 1 | $3.47| $3.47 | ----- |
| capacitor 1uF | C3216X8R1E105M160AA | 2 | $0.42 | $0.84 | ----- |
| capacitor 22pF | C3216CH2J221J060AA | 2 | $0.21 | $0.42 | ----- |
| capacitor 22uF | C3216JB1C226M160AB | 2 | $0.64 | $1.28 | ----- |
| Total | ----- |-----| -----| $139.73 |

# References:
1.Power Electronics pdf, Daniel W. Hart Valparaiso University Valparaiso, Indiana.

2. Buck-Boost Converter datasheet: https://www.analog.com/media/en/technical-documentation/data-sheets/LTC3114-1.pdf?ADICID=SYND_WW_P682800_PF-spglobal?hkey=EF798316E3902B6ED9A73243A3159BB0

3. Bridge Rectifier: https://www.mouser.com/ProductDetail/Diodes-Incorporated/GBU404?qs=G5AQjGfRJcL0qZwbO1hCAw%3D%3D&mgh=1&gclid=Cj0KCQiAo7KqBhDhARIsAKhZ4uiLwH-geIVj7ENUvHTWf11hyNU4IoTfVOAK8-eMKpBxqfyngL2PZPkaAtnPEALw_wcB
4. Bridge Rectifier:[ https://www.digikey.com/en/products/detail/micro-commercial-co/MB12S-TP/2075331](https://goodarksemi.com/docs/datasheets/schottky_bridge_rectifiers/MB12S-MB110S.pdf)
5. Transformer datasheet: https://www.mouser.com/ProductDetail/Triad-Magnetics/TCT50-01E07AB?qs=b1anAsPanWyYuqQKXv%2FQQw%3D%3D

6. Battery: https://www.amazon.com/ML12-12-Battery-Terminal-Mighty-Product/dp/B00K53FG5Q/ref=sr_1_4?crid=2ENRDXKVGB5V8&keywords=ml12-12%2Bbattery&qid=1698983669&s=electronics&sprefix=ML12-12%2B%2Celectronics%2C153&sr=1-4&th=1
   
7. Battery datasheet: [file:///C:/Users/abofa/Downloads/R08-002%20-%20Design%20and%20Sizing%20of%20Solar%20Photovoltaic%20Systems%20-%20US%20(1).pdf](https://www.cedengineering.com/courses/design-and-sizing-of-solar-photovoltaic-systems)https://www.cedengineering.com/courses/design-and-sizing-of-solar-photovoltaic-systems
8. Buck Converter datasheet: https://www.analog.com/media/en/technical-documentation/data-sheets/3621fc.pdf
9. Fiada 24V 40VA Control Transformer, UL Certified Primary 120, 208, 240V Secondary 24V, HVAC Furnace Transformer Multi Tap(1 Pack) https://a.co/d/bubQZsQ
https://a.co/d/bubQZsQ  
  
