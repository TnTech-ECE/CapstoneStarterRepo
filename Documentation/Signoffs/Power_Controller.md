# Power Controller Subsystem

The purpose of this subsystem is to step down the voltages and feed the other subsystems with the needed voltages and current. To step down the voltage, a buck converter will be used to accomplish this task. 
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
| a.  | Data interpretation, Transmission, and Storage | 5 V | 0.25 A |
| b.  | Charge Controller | 5 V | 0.25 A |
| c.  | Sensor | 9 V | 0.06 A |

Table 2.  Parameters for the demanded voltages and currents by each subsystem.

   
# Buildable schematic

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/8b989135-5936-4303-bc17-c2979f02de09)

*Figure 1. Power controller schematic. *


![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/e66dc8a1-0d02-4da9-98a4-6e2ac69257a3)

*Figure 2. Bcuk converter for Data interpretation, Transmission, and Storage subsystem *

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/52a144c0-32bf-44c4-b660-c4d55845ca8a)

*Figure 3. Bcuk converter for Charge Controller subsystem. *

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/6a654343-ef61-46cf-ad8e-d7075d725dc4)

*Figure 4. Bcuk converter for Sensor subsystem. *

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/81bb2e38-37a6-48ad-9ef6-326acbdcaf97)

*Figure 5. Bcuk converter LTspice circuit. *


# Analysis

## Sizing and selection for Buck Converter


| No. | Subsystem | Voltage | Current |
| --- | ----------- | ------ | ------ |
| a.  | Data interpretation, Transmission, and Storage | 5 V | 0.25 A |
| b.  | Charge Controller | 5 V | 0.25 A |



```math
{\rm V}_{IN} = 10.8V  to  13.2V
```
```math
{\rm V}_{OUT} = 5V
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
L\ =\ \ \frac{5V}{2.25MHz\ \ast\ (0.4\ (0.25A)}\ \ast(1-\frac{5V}{13.2V})
```
```math
L\ = 13.8 \mu H
```
Given this, a 1.7µH or 3.3µH, >1.2A inductor would suffice


Using the desired input and output voltage along with the operating frequency, we can determine the value for the ripple current.

```math
{\rm ∆I}_{L} = \frac{V_{OUT}}{f\ \ast\ L}\ \ast(1-\frac{V_{OUT}}{V_{IN(max)}})
```
```math
{\rm ∆I}_{L} = \frac{5V}{(2.25MHz\ \ast\ 13.8\mu H} \ast(1-\frac{5}{13.2})
```
```math
{\rm ∆I}_{L} = 0.1A
```

Feedback resistors Selection:

Next, you can find the external resistive divider values for R_2. Considering selecting a high resistor value for R_1 to be 187kΩ.  
```math
V_{OUT}=\ 0.6V\ \ast(1 +\frac{R_{1}}{R_{2}})

```
```math
5V=\ 0.6V\ \ast(1 +\frac{187kΩ}{R_{2}})
```
```math
R_{2}= 25.5kΩ
```

Input Capacitor Selection:

According to the datasheet, the input capacitor is a 10µF ceramic capacitor, which is adequate for most applications. 
```math
I_{RMS}\cong\ I_{OUT(max)}\ast\ \frac{V_{OUT}}{V_{IN(max)}}\ast{(\frac{V_{IN(max)}}{V_{OUT}}-1)}^\frac{1}{2}
```

```math
I_{RMS}\cong\ 0.25A\ast\ \frac{5V}{13.2V}\ast{(\frac{13.2V}{5V}-1)}^\frac{1}{2}
```

```math
I_{RMS}\cong\ 0.121A
```


Output Capacitor Selection:
According to the datasheet for the output capacitor, a 22µF ceramic capacitor will be used based on the required EST to satisfy the output voltage ripple requirement and the bulk capacitance needed for loop stability. 



| No. | Subsystem | Voltage | Current |
| --- | ----------- | ------ | ------ |
| c.  | Sensor | 9 V | 0.06 A |

```math
{\rm V}_{IN} = 10.8V  to  13.2V
```
```math
{\rm V}_{OUT} = 9V
```
```math
{\rm I}_{OUT(max)} = 0.06A
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



Using the desired input and output voltage along with the operating frequency, we can determine the value for the ripple current.

```math
{\rm ∆I}_{L} = \frac{V_{OUT}}{f\ \ast\ L}\ \ast(1-\frac{V_{OUT}}{V_{IN(max)}})
```


Feedback resistors Selection:

Next, you can find the external resistive divider values for R_2. Considering selecting a high resistor value for R_1 to be ---kΩ.  
```math
V_{OUT}=\ 0.6V\ \ast(1 +\frac{R_{1}}{R_{2}})

```


Input Capacitor Selection:

According to the datasheet, the input capacitor is a 10µF ceramic capacitor, which is adequate for most applications. 
```math
I_{RMS}\cong\ I_{OUT(max)}\ast\ \frac{V_{OUT}}{V_{IN(max)}}\ast{(\frac{V_{IN(max)}}{V_{OUT}}-1)}^\frac{1}{2}
```




Output Capacitor Selection:
According to the datasheet for the output capacitor, a 22µF ceramic capacitor will be used based on the required EST to satisfy the output voltage ripple requirement and the bulk capacitance needed for loop stability. 





# BOM
| Part | Part Number | Quantity | Price Per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Step down buck regulator | LTC3621 | 2 | $7.38 |  $14.76 |
| Fuse | ---- | 3 | ---- | ----- |
| Resistor | ---- | 6 | ---- | ----- |
| Inductor | ---- | 3 | ---- | ----- |
| Capacitor | ---- | 9 | ---- | ----- |
| Total | ----- | ----- | ----- | $---- 













