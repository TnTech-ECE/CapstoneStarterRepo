# Power Controller Subsystem

The purpose of this subsystem is to step down the voltages and feed the other subsystems with the needed voltages and current. A buck converter will be used to accomplish this task and step down the voltage. 
The power controller will power three subsystems with a constant DC voltage and current depending on the demanded voltages and currents. Moreover, the power controller will take responsibility for not overcurrent, overvoltage, or causing any damage to the components within each subsystem.   


# Constraints
| No. | Constraints | Origin |
| --- | ----------- | ------ |
| 1.  | The subsystem shall power each subsystem's demanded voltage and current with a 10% tolerance.  | System Requirements |
| 2.  | The subsystem output shall be connected to the other subsystems through three fuses.  | System Requirements |
| 3.  | The subsystem shall have a DC nominal voltage of 12V. | System Requirements    |

Table 1. Constraints and origins of the constraints.

1. Using a buck converter chip, The power controller will step down the DC voltage input 12V to the demanded voltage and current by each subsystem, according to Table 2. Also, to have a 10% tolerance due to power loss factors or input voltage drops.
2. Using fuses will protect the supplied subsystems from overcurrent, overvoltage, or damage to the components. The fuse selection is based on the demanded current by each subsystem, according to Table 2.
3. To get the desired output from the power controller, the nominal voltage input must be 12 V. To be able to do the selection and sizing for the buck converter components, such as inductors, capacitors, and resistors, the input and output voltage must be given.

| No. | Subsystem | Voltage | Current |
| --- | ----------- | ------ | ------ |
| a.  | Data interpretation, Transmission, and Storage | 5.5 V | 0.25 A |
| b.  | Charge Controller | 5.5 V | 0.25 A |
| c.  | Sensor | 9 V | 0.05 A |

Table 2.  Parameters for the demanded voltages and currents by each subsystem.

   
# Buildable schematic


![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/d623bbcf-d5a9-4744-912b-34ae3b8c1c46)


*Figure 1. Bcuk converter Kicad schematic. *

<img width="513" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/cb205683-d54e-452e-acd2-901814983d52">

*Figure 2. Bcuk converter LTspice circuit. *



<img width="378" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/9fab8b5c-5745-49ac-8c7c-5a9d863afe70">

*Figure 3. 3D model for Bcuk converter. *


<img width="359" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/3afbcac7-7a61-49d0-9408-2ae98eb4a2f8">

*Figure 4. PCB design and measurement. *


# Analysis
The selected buck converter datasheet can be found here [ https://www.analog.com/media/en/technical-documentation/data-sheets/3621fc.pdf ]
## Sizing and selection for Buck Converter


| No. | Subsystem | Voltage | Current |
| --- | ----------- | ------ | ------ |
| a.  | Data interpretation, Transmission, and Storage | 5.5 V | 0.25 A |
| b.  | Charge Controller | 5.5 V | 0.25 A |



```math
{\rm V}_{IN} = 10.8V  to  13.2V
```
```math
{\rm V}_{OUT} = 5.5V
```
```math
{\rm I}_{OUT(max)} = 0.25A
```
```math
{\rm I}_{OUT(min)} = 0.05A
```
```math
{\rm f}_{SW)} = 2.25MHz
```


Inductor Selection:
For starting point is to choose the ripple current to be %40 of I_out(max). To ensure that the ripple current does not exceed the specified maximum.
```math
L\ = \frac{V_{OUT}}{f\ \ast\ {\rm ∆I}_{L(max)}}\ \ast(1-\frac{V_{OUT}}{V_{IN(max)}})
```
```math
L\ =\ \ \frac{5.5V}{2.25MHz\ \ast\ (0.4\ (0.25A)}\ \ast(1-\frac{5.5V}{13.2V})
```
```math
L\ = 14.26 \mu H
```
Given this, a 14.26µH, we can pick the inductor as 15µH, which would suffice.


We can determine the value for the ripple current using the desired input and output voltage along with the operating frequency.

```math
{\rm ∆I}_{L} = \frac{V_{OUT}}{f\ \ast\ L}\ \ast(1-\frac{V_{OUT}}{V_{IN(max)}})
```
```math
{\rm ∆I}_{L} = \frac{5.5V}{(2.25MHz\ \ast\ 14.26 \mu H)} \ast(1-\frac{5.5}{13.2})
```
```math
{\rm ∆I}_{L} = 0.1A
```

Feedback resistors Selection:

Next, you can find the external resistive divider values for R_2. Considering selecting a high resistor value for R_1 to be 196kΩ.  
```math
V_{OUT}=\ 0.6V\ \ast(1 +\frac{R_{1}}{R_{2}})

```
```math
5.5V=\ 0.6V\ \ast(1 +\frac{196kΩ}{R_{2}})
```
```math
R_{2}= 24kΩ
```

Input Capacitor Selection:

According to the datasheet, the input capacitor is a 10µF ceramic capacitor, which is adequate for most applications. 
```math
I_{RMS}\cong\ I_{OUT(max)}\ast\ \frac{V_{OUT}}{V_{IN(max)}}\ast{(\frac{V_{IN(max)}}{V_{OUT}}-1)}^\frac{1}{2}
```

```math
I_{RMS}\cong\ 0.25A\ast\ \frac{5.5V}{13.2V}\ast{(\frac{13.2V}{5.5V}-1)}^\frac{1}{2}
```

```math
I_{RMS}\cong\ 0.123A
```


Output Capacitor Selection:


According to the datasheet for the output capacitor, a 22µF ceramic capacitor will be used based on the required EST to satisfy the output voltage ripple requirement and the bulk capacitance needed for loop stability. 








| No. | Subsystem | Voltage | Current |
| --- | ----------- | ------ | ------ |
| c.  | Sensor | 9 V | 0.05 A |

```math
{\rm V}_{IN} = 10.8V  to  13.2V
```
```math
{\rm V}_{OUT} = 9V
```
```math
{\rm I}_{OUT(max)} = 0.05A
```
```math
{\rm I}_{OUT(min)} = 0.04A
```
```math
{\rm f}_{SW)} = 2.25MHz
```


Inductor Selection:
The starting point is to choose the ripple current to be %40 of I_out(max). To ensure that the ripple current does not exceed the specified maximum.
```math
L\ = \frac{V_{OUT}}{f\ \ast\ {\rm ∆I}_{L(max)}}\ \ast(1-\frac{V_{OUT}}{V_{IN(max)}})
```
```math
L\ =\ \ \frac{9V}{2.25MHz\ \ast\ (0.4\ (0.05A)}\ \ast(1-\frac{9V}{13.2V})
```
```math
L\ = 63.63 \mu H
```
Given a 63.63µH, we can pick the inductor as 68µH, which would suffice.



We can determine the value for the ripple current using the desired input and output voltage along with the operating frequency.

```math
{\rm ∆I}_{L} = \frac{V_{OUT}}{f\ \ast\ L}\ \ast(1-\frac{V_{OUT}}{V_{IN(max)}})
```
```math
{\rm ∆I}_{L} = \frac{9V}{(2.25MHz\ \ast\ 68 \mu H)} \ast(1-\frac{9}{13.2})
```
```math
{\rm ∆I}_{L} = 0.019A
```

Feedback resistors Selection:

Next, you can find the external resistive divider values for R_2. Considering selecting a high resistor value for R_1 to be 196kΩ.  
```math
V_{OUT}=\ 0.6V\ \ast(1 +\frac{R_{1}}{R_{2}})

```
```math
9V=\ 0.6V\ \ast(1 +\frac{196kΩ}{R_{2}})
```
```math
R_{2}= 14kΩ
```


Input Capacitor Selection:

According to the datasheet, the input capacitor is a 10µF ceramic capacitor, which is adequate for most applications. 
```math
I_{RMS}\cong\ I_{OUT(max)}\ast\ \frac{V_{OUT}}{V_{IN(max)}}\ast{(\frac{V_{IN(max)}}{V_{OUT}}-1)}^\frac{1}{2}
```
```math
I_{RMS}\cong\ 0.05A\ast\ \frac{9V}{13.2V}\ast{(\frac{13.2V}{9V}-1)}^\frac{1}{2}
```

```math
I_{RMS}\cong\ 0.023A
```



Output Capacitor Selection:


According to the datasheet for the output capacitor, a 22µF ceramic capacitor will be used based on the required EST to satisfy the output voltage ripple requirement and the bulk capacitance needed for loop stability. 





### LTstice Simulations


1. Data interpretation, Transmission, and Storage.
<img width="591" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/2c84c5af-273f-4d3a-9f36-0606341da4ce">

<img width="591" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/3bce3e71-f4bd-41f6-a3e6-d5bbc17da826">

<img width="592" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/141133fd-5a81-4887-b7f8-b1b1cb6a3ff8">

  

2. Charge Controller
<img width="590" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/e674e08c-d9b4-4d1a-8d6a-fa1710c363e3">
<img width="590" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/cf0ff7f6-8f61-4e0c-aba3-4eb2af7cfb4f">
<img width="587" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/4dbf35bb-fd21-4d4a-863e-b9e899b19452">


3. Sensor
   
<img width="592" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/bf137a25-99d7-48b6-9135-7f6f06d4b3ac">




<img width="589" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/afcd198c-b484-4e31-a641-94203bef5584">



<img width="592" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/d2163bbe-c74e-4bca-a8ac-d0eaeb0d6857">

<img width="590" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/fe81aabd-3279-4adf-a038-f8796a42ed74">





# BOM
| Part | Part Number | Quantity | Price Per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Step down buck regulator | LTC3621 | 3 | $8.12 |  $24.36 |
| Resistor 196kΩ | ERJ-1GNF1963C | 3 | $0.1 | $0.3 |
| Resistor 24kΩ | ERJ-1GNF2402C | 3 | $0.1 | $0.3 |
| Resistor 14kΩ | ERJ-1GNF1402C | 3 | $0.1 | $0.3 |
| Inductor 15uH | XFL3012-153MEC | 2 | $2.08 | $4.16 |
| Inductor 68uH | MSS7348-683MEC | 1 | $2.62 | $2.62 |
| Capacitor 22pF| C3216CH2J221J060AA | 3 | $0.21 | $0.63 |
| Capacitor 1uF| C3216X8R1E105M160AA | 3 | $0.42 | $1.26 |
| Capacitor 10uF| C3216JB1E106M160AB | 3 | $0.56 | $1.68 |
| Capacitor 22uF| C3216JB1C226M160AB | 3 | $0.64 | $1.92 |
| Fixed Terminal Blocks 2P SIDE ENTRY| 282834-2 | 4 | $1.41 | $5.64 |
| Total | ----- | ----- | ----- | $35.31 













