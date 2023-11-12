# Wall power Subsystem:

My main wall power subsystem input 120v AC. The main wall power has a transformer convert AC to AC, then a buck converters DC to DC that is step down will output 5V DC and boost converters that will be a step up that output 9v DC. After that, it will feed the other two subsystems, the first subsystem needs a 5v DC, and the second subsystem needs a 9v DC. However, I have another subsystem, which is a backup battery. If the main wall power shuts down, a switch will activate the backup battery to feed the two subsystems. The main idea is to supply power to the device, building a circuit that will convert to DC and then distribute voltage to other subsystems.

# Constraints
| No. | Constraints | Origin |
| --- | ----------- | ------ |
| 1.  | Voltage equivalence: The main wall power subsystem needs to protect devices from the damage caused by voltage and guarantee the safety of the electrical system, as well as preserve the whole subsystem.| System Requirements |
| 2.  | Transformer: A safe output voltage and the way to handle 120v AC input are requirements for the Transformer used to converter AC to AC.| System Requirements |
| 3.  | Must be A way to disconnect the power from the source.| System Requirements |
| 4.  | It should be within wire capabilities.| System Requirements |

1.	Mian Wall Power input 120V AC: The primary power source is the 120V AC mains supply. It is the electricity that can used to power many types of devices. Wall power has multiple uses, including lighting, running devices at home, and charging machines. That system offers it access to a conveniently available supply of electricity.
2.	Transformer: How does the Transformer raise voltage or lower voltage. So, We need to do the Converter from AC high voltage different AC low. That means doing step-down voltage.
3.	Full wave bridge rectifier “FWR”: The FWR is a type of Full wave rectifier that uses four or more diodes in a bridge circuit setup to effectively transform an alternating current AC into a direct current DC. Also, it shows that the current uses a single path after converting. After the converter from AC to DC, we will get just the positive signals.
4.	RC filter: Capacitor with Resister: Signal management and filtering are critical functions of electronic systems. Also, it will be smoothing the signals. However, we should use the Step-down voltage From DC to DC. After the RC filter, the input voltage will be 22.6v DC. We used the chip to do the process. The buck-boost converter gets what we need to get the output of 12v DC. Then, we have power subsystems. The input voltage will be the same, and it's 12v DC.
5.	Controller: We have three systems, and their "chips" " are all buck-boost converters. Firstly, it is a controller or master switch between the wall power and backup battery, and this controller manages the voltage between them. The input comes with the same voltage, and it's 12v DC. The idea for the controller is that if the main wall power shuts down, a switch will activate the backup battery to feed the two subsystems. Secondly, the other two subsystems will be the same chips and buck-boost converter. Subsystem one: it needs to step down "Buck" for the Subsystem and its 5v dc, 250mA. Subsystem two must step up "Boost" for the Subsystem and its 9v dc, 60mA.
6.	Use the Backup Battery if the main wall power shuts down. Also, the battery will be connected to the kill switch. If something happens to the wall power, the subsystems will change the switch immediately to the backup battery. Between the backup battery and the main wall, have a switch "controller" to manage all power from subsystems. The battery backup subsystem aims to ensure that the first and second subsystems usually function during power outages. The backup battery type is a 12-volt 12AH sealed lead acid AGM.



# Buildable Schematic:

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/d921c0f2-c3e3-4709-b1bf-cacd66c448a0)

Figure 1.

<img width="583" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/2bee2c6e-126c-49ae-a518-e64eea2e3d38">

Figure 2.

# Analysis
Circuit explanation: 
1.	The input for wall power is 120v AC, 60 Hz.
2.	Converter 120v AC to 24v AC 
3.	Converter 24v DC to 13.6v DC
4.	Buck “step down the voltage ”
5.	Boost “Step up the voltage”
6.	The output needs to have two subsystems with an output of 9v DC, 60mA, And 5v DC, 250mA.

Calculations: Input voltage = 120 V AC. Primary Voltage = 120 V AC, Secondary Voltage = 120V * √(Lp/Ls) = 120V * √ (13/1) = 13.6 V.


Transformer:
```math
Output \ Voltage \  =input\times\frac{ Turs\  secondary }{ Turs\ primary }
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
First Buck converter:
Used the step-down voltage from 20v DC to get 12v DC
Fs = 100KHz
T = 10ms

```math
Vout \ = D * Vin
```
```math
Duty\ Ratio  = \frac{ 12 } { 20} = 0.6
```
```math
Vs\ ={L}\times \frac{ I } { Tno} +{12}  
```
```math
20\ ={L}\times \frac{ 0.6 } { 6} +{12}  
```

```math
8  = \frac{L} { 10} 
```
```math
L = 80uH 
```
```math
C  = \frac{ D\ Io } {8Fs\ Vo} 
```
```math
C = 15 mF
```
###  Backup Battery
| No. | Subsystem | Voltage | Current | Rated Wattage[W]| Hours per day used [ h ] | Energy Consumption [ Wh ] |
| --- | -------- | ------ | ----- | ------------------------ | --------- | ------------------ |
| a. | Sensor | 9 V | 0.06 A | 9 * 0.06 = 0.45W | 24h | 10.8Wh |
| b. | Data interpretation, Transmission, and Storage | 5 V | 0.25A | 5 * 0.25 = 1.25W | 24h | 30Wh | 
| | | | | Total Rated Wattage = 1.7W | | Energy Consumption=40.8Wh |

The backup battery selection is going to be dependent on multiple aspects. Since we are using a power controller with an input voltage of 12 V DC. Therefore, the battery selected to be a 12V battery Seal lead acid. Moreover, the battery capacity ( Ah ) will be determined by applying these calculations.
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
| Buck-Boost Converter | LTC3114-1  | 3 | $11.35 |$34.04 |
| Transformer | TCT50-01E07AB | 1 | $18.87 | 18.87 |
| Full wave Bridge Rectifier | GBU404 | 1| $1.36 | $1.36 |
| Battery |ML12-12F2 |1| $27.99|$27.99|
| capacitor | ----- | ----- | ----- | $? | $? |
| Resistor | R268|4| $0.10|$0.40|
| Resistor | R74|3| $0.10|$0.30|
| Total | ----- |-----| -----| $89.76 |

# References:
1.Power Electronics pdf, Daniel W. Hart Valparaiso University Valparaiso, Indiana.

2. https://www.analog.com/media/en/technical-documentation/data-sheets/LTC3114-1.pdf?ADICID=SYND_WW_P682800_PF-spglobal?hkey=EF798316E3902B6ED9A73243A3159BB0

3. https://www.mouser.com/ProductDetail/Diodes-Incorporated/GBU404?qs=G5AQjGfRJcL0qZwbO1hCAw%3D%3D&mgh=1&gclid=Cj0KCQiAo7KqBhDhARIsAKhZ4uiLwH-geIVj7ENUvHTWf11hyNU4IoTfVOAK8-eMKpBxqfyngL2PZPkaAtnPEALw_wcB
4. https://www.mouser.com/ProductDetail/Triad-Magnetics/TCT50-01E07AB?qs=b1anAsPanWyYuqQKXv%2FQQw%3D%3D

5. https://www.amazon.com/ML12-12-Battery-Terminal-Mighty-Product/dp/B00K53FG5Q/ref=sr_1_4?crid=2ENRDXKVGB5V8&keywords=ml12-12%2Bbattery&qid=1698983669&s=electronics&sprefix=ML12-12%2B%2Celectronics%2C153&sr=1-4&th=1
   
6. [file:///C:/Users/abofa/Downloads/R08-002%20-%20Design%20and%20Sizing%20of%20Solar%20Photovoltaic%20Systems%20-%20US%20(1).pdf](https://www.cedengineering.com/courses/design-and-sizing-of-solar-photovoltaic-systems)https://www.cedengineering.com/courses/design-and-sizing-of-solar-photovoltaic-systems

  
