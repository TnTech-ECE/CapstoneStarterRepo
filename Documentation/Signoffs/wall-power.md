# Wall power Subsystem:

My main wall power subsystem input is 120v AC. The main wall power has an adapter Power Supply that converts AC to AC or AC to DC, then a buck converters DC to DC that is step down will output 5.5V DC and buck converters that will be a step down that output 9v DC. After that, it will feed the other two subsystems; the first subsystem needs a 5.5v DC, and the second subsystem needs a 9v DC. However, I have another subsystem, which is a backup battery. If the main wall power shuts down, a switch will activate the backup battery to feed the two subsystems. The main idea is to supply power to the device, building a circuit that will convert to DC and then distribute voltage to other subsystems.

# Constraints
| No. | Constraints | Origin |
| --- | ----------- | ------ |
| 1.  | Voltage equivalence: The main wall power subsystem needs to protect devices from the damage caused by voltage and guarantee the safety of the electrical system, as well as preserve the whole subsystem.| System Requirements |
| 2.  | During main power failures, power flow is controlled by the switch controller..| System Requirements |
| 3.  | Must be a kill switch to disconnect all the power from the source.| System Requirements |
| 4.  | It should be within wire capabilities.| System Requirements |

1.	Mian Wall Power input 120V AC: The primary power source is the 120V AC mains supply. It is the electricity that can used to power many types of devices. Wall power has multiple uses, including lighting, running devices at home, and charging machines. That system offers it access to a conveniently available supply of electricity. Also, For emergencies, I used a physical kill switch to shut down all the power if something happened. 

2.	The Adapter Power Supply is 120v AC to 12v DC, which means the adapter is a device with input and output. Inside the adapter are a transformer, a rectifier, and a filter. For example, for these inside the adapter, the transformer means the transformer raises voltage or lowers voltage, and we need high-voltage AC and low-voltage AC. That means step-down voltage. However, a rectifier has more diodes in a bridge circuit setup to effectively transform an alternating current AC into a direct current DC. Also, it shows that the current uses a single path after converting. We will get just the positive signals after the converter from AC to DC. In the end, a filter is Signal management, and filtering is a critical function of electronic systems. Also, it will be smoothing the signals. We must use it after the step-down voltage from DC to DC gets something single.
3.	Controller: We have two systems, and their "chips" are all buck converters. Firstly, it is a controller or master switch between the wall power and backup battery, and this controller manages the voltage between them. The input comes with the same voltage, and it's 12v DC. The idea for the controller is that if the main wall power shuts down, a switch will activate the backup battery to feed the two subsystems. Secondly, the other two subsystems will be the same chips and buck converter. Subsystem one: it needs to step down the "Buck converter" for the Subsystem and its 5.5v dc, 250mA. Subsystem two must step down the "Bcuk converters" for the Subsystem and its 9v dc, 50mA.

4.	Use the Backup Battery if the main wall power shuts down. Also, the battery connects to the kill switch. If something happens to the wall power, the subsystems will change the switch immediately to the backup battery. Between the backup battery and the main wall, have a switch "controller" to manage all power from subsystems. The battery backup subsystem aims to ensure that the first and second subsystems usually function during power outages. The backup battery type is a 12-volt 12AH sealed lead acid AGM.



# Buildable Schematic:

<img width="722" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/ac1fd0b7-1c75-403d-b98d-5fe164d41c73">

Figure 1. Kicad schematic.

<img width="741" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/26576c77-2787-4620-95d8-ef6c71cb1532">

Figure 2.Kicad schematic.


# Analysis
Circuit explanation: 
1.	The input for wall power is 120v AC, 60 Hz.
2.	Adapter Power Supply 120v AC to 12v DC 
3.	Buck converter: “Step down the voltages for Subsystem One and Subsystem Two.”
4.	The output needs to have two subsystems with an output of 9v DC, 60mA, And 5v DC, 250mA.

Calculations:

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


<img width="959" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/2f5794d4-8e9a-44a6-bdae-3d3b066a6541">



 1. LTspice circuit, 

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/ba7a7f10-b724-4868-b76a-b7c61bd0ff23) 

 
2. Buck converter for subsystem 5.5v

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/f2cf1a2d-a279-4222-b454-f5561ce36fdf) 

3. Buck converter for subsystem 9v

<img width="955" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/4b6eb468-48f5-4a7e-bef4-76bb4fc6b212"> 

4. subsystem one for The current 250mA. 

<img width="955" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/b8047f4f-d1b3-4a99-87f5-95b3ed001e6f">

5. subsystem Two for the current 50mA  



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
SPDT SW
# BOM: 
| Part | Part Number | Quantity | Price per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
|  Adapter Power Supply | 12V 3A Adapter Power Supply AC to DC Plug | 1 | $9.99 | $9.99 |
| Buck Converter | LTC3621  | 2 | $7.38 |$14.76 |
| Battery |ML12-12F2 | 1 | $27.99 | $27.99 |
| SPDT Switch |  G6RN-1-DC5  | 1 | $4.10 | $4.10 |
| Inductor 15uH | XFL3012-153MEC | 1 | $2.08 | $2.08 | 
| Inductor 68uH | MSS7348-683MEC | 1 | $2.62 | $2.62 |
| Resistor 270Ω | ERJ-U02D2700X | 1 | $0.10 | $0.10 |
| Resistor 196kΩ | ERJ-1GNF1963C | 1 | $0.1 | $0.10 |
| Resistor 24kΩ | ERJ-1GNF2402C | 1 | $0.1 | $0.10 |
| Resistor 140kΩ | CR0603-FX-1403ELF | 1 | $0.10 | $0.10 |
| Resistor 14kΩ | ERJ-1GNF1402C | 1 | $0.1 | $0.10 |
| capacitor 200uF | C2220C204KBGLCAUTO | 1 | $4.37 | $4.37 |
| capacitor 10uF | C3216JB1E106M160AB | 2 | $0.56 | $1.12 | 
| capacitor 10nF | KAM15AR72A103KM | 1 | $0.31 | $0.31 | 
| capacitor 1uF | C3216X8R1E105M160AA | 2 | $0.42 | $0.84 | 
| capacitor 22pF | C3216CH2J221J060AA | 2 | $0.21 | $0.42 | 
| capacitor 22uF | C3216JB1C226M160AB | 2 | $0.64 | $1.28 |
| Total | ----- |-----| -----| $73.04 |

# References:
1.Power Electronics pdf, Daniel W. Hart Valparaiso University Valparaiso, Indiana.

2. Buck Converter datasheet: https://www.analog.com/media/en/technical-documentation/data-sheets/3621fc.pdf

3. Adapter Power Supply AC to DC Plug  https://www.amazon.com/3000mA-Volts-Adapter-Power-Supply/dp/B08CZ7Z9TB/ref=asc_df_B08CZ7Z9TB/?tag=hyprod-20&linkCode=df0&hvadid=647103656310&hvpos=&hvnetw=g&hvrand=9662999191843388178&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9013670&hvtargid=pla-1950777511611&psc=1&mcid=685d49c72c873cfb88c5918053752121



4. Battery: https://www.amazon.com/ML12-12-Battery-Terminal-Mighty-Product/dp/B00K53FG5Q/ref=sr_1_4?crid=2ENRDXKVGB5V8&keywords=ml12-12%2Bbattery&qid=1698983669&s=electronics&sprefix=ML12-12%2B%2Celectronics%2C153&sr=1-4&th=1
   
5. Battery datasheet: [file:///C:/Users/abofa/Downloads/R08-002%20-%20Design%20and%20Sizing%20of%20Solar%20Photovoltaic%20Systems%20-%20US%20(1).pdf](https://www.cedengineering.com/courses/design-and-sizing-of-solar-photovoltaic-systems)https://www.cedengineering.com/courses/design-and-sizing-of-solar-photovoltaic-systems


  
