# Charge Controller Subsystem

The Charge Controller's purpose is to harness solar power and supply the rest of the system with power. The solar power will be used as the main source of power with two batteries as a secondary source of power. The solar panel's output will be used to both power the system and also charge the batteries. This will allow the system to be self-sufficient when it comes to power. 

This subsystem can input solar power from the range of 0 V to 24 V and will output 12 V. 

# Constraints
| No. | Constraints | Origin |
| --- | ----------- | ------ |
| 1.  | Controller shall maximize the output power from the solar panel. | Ethical Requirements |
| 2.  | Controller shall output 12 V with a 10% tolerance to the Power Controller. | System Requirements |
| 3.  | Controller shall prevent the batteries from being damaged due to over-charging  | Extend Life of Batteries    |

1. The subsystem shall maximize the output power from the solar panel. Solar panels can only generate power when they are placed in sunlight. Sunlight, while abundant during the daytime, is not present 24 hours of the day. During the times that the sun is present, its power received from the solar panels shall be maximized.
2. The subsystem shall output 12 V with a 10% tolerance to the Power Controller. 
3. The subsystem shall prevent the batteries from attempting to charge past its maximum charging capacity. Overcharging can cause the overheating and long term damage to the batteries. To ensure the batteries are able to be used for as long as possible, overcharge protection shall be used. 

*Figure 1. Main Schematic*

![ChargeControllerMainSchematic](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/2a748a91-0a83-4563-8bf3-aeebc676da00)

*Figure 2. Battery Charger Schematic*

![ChargeControllerBatteryChargerSchematic](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/5ad36d3c-03fd-482d-953a-e1e1622dd50b)

# Analysis

## Arduino Nano
The Arduino is in charge of controlling the amount of power that is generated from the solar panels to the battery chargers. This will be accomplished through a greedy algorithm utilizing pulse width modulation (PWM) on a power MOSFET. 

### Greedy Algorithm
The algorithm has one responsibility: send as much current to the battery chargers as possible without negatively affecting the output current to the system. 

*Figure 3. Greedy Algorithm*

![GreedyAlgorithmFlowChart](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/3c34bec7-9ece-4f0c-912a-553cb6658c08)


The Arduino will take two inputs to control the PWM rate: output current and the 12 V supplied from the solar panel MPPC BuckBoost. A current sensor at the system's output will be used to detect if the algorithm is taking away current from the system to try to supply the battery chargers. The output of the solar panel BuckBoost is used to validate that the algorithm has power to try to charge the batteries. 

### Current Sensor

The current sensor being used is the _ACS724LLCTR-05AU-T_. It has an analog output of up to Vcc + 0.5 V corresponding to the current levels from 0 A to 5 A. The maximal output voltage is 5.5 V which corresponds to 5 A. 

*Figure 4. Current Sensor*

![Current_Sensor](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/77c480b2-e3f3-470d-a903-46c6adff1ef6)

The Arduino nano can only handle analog voltages up to 5 V. 5.5 V can damage the Arduino's input pins. The system's current usage has been calculated to be less than an amp, which means that the output voltage from the current sensor is not going to reach 5.5 V. The Arduino's analog pins will not be damaged by the system's expected current usage. 

The capacitors connected to the current sensor are derived from the current sensor datasheet.

### MPPC Output Voltage Detection
The Solar Panel's MPPC Outvoltage will be read using one of the Arduino's analog pins. The maximum voltage for the MPPC Outputvoltage is 12 V and the maximum voltage that the Arduino can take on its analog pins is 5 V. The exact voltage is not important. What is important is if the MPPC BuckBoost is outputting _something_ so that the batteries can attempt to be charged.

A voltage divider using two resistors will be used to divide the voltage down from 12 V to 4.5 V. 4.5 V will be used to give 0.5 V of room for any ripple voltage from the BuckBoost. 

*Figure 5. MPPC Output Voltage Detection*

![MPPC_OutputVoltage_MCU](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/9da74e91-6231-459a-a25a-85d8d91f222f)

```math
V_{Arduino} = V_{BUCKBOOST} ( \frac{R_{15}}{R_{16} + R_{15}})
```

R_15 is arbitrarily set to 10 kΩ.

```math
=>4.5 = 12 ( \frac{10,000}{R_{16} + 10,000})
```
```math
```
```math
R_{15} = 16,666 Ω = 17 kΩ
```

### Pulse Width Modulation Control
Pin D10 on the Arduino Nano has been chosen due to its ability for PWM control according to the Nano's Datasheet.

The circuitry is discussed in the _Pulse Width Modulation_ section.

### Arduino Power Initialization
The Arduino is powered by the Power Controller Subsystem which this subsystem outputs to. This means that the Arduino will not be powered on during the initial start up of the system. This is acceptable as the batteries are not going to be charging during this time.


## Pulse Width Modulation

*Figure 6. Pulse Width Modulation Circuitry*
![PulseWidthModulationCircuit](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/f43bbd51-7e45-481e-98f0-0cb06c225042)


The Arduino will be controlling a power MOSFET that sends the MPPC BuckBoost output, 12 V, to both of the battery charger ICs. To achieve a voltage high enough to drive the MOSFET with a 12 V source, a Boost voltage regulator IC and a noninverting operational amplifier circuit will be used. 

### MOSFET
The MOSFET being driven is the _SI7272DP-T1-GE3_. It requires a gate threshold voltage of at least 1.2 V and to enter full saturation mode 2.5 V is required. 

### TPS6117 Boost IC
The boost IC will increase the MPPC Output voltage from 12 V to 16 V to ensure that the MOSFET is properly driven with 4 V between the gate and the source. The  _TPS61170DRVR_ boost IC has been chosen due to its minimalistic circuitry and applicable ratings.

*Figure 7. PWM Boost Schematic*
![BoostPWMCircuit](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/b4cdc252-34ae-443d-bc0f-fa34f01c6c57)

Output Voltage Programming:
```math
V_{out} = 1.229 ( \frac{R_{18}}{R_{17}} + 1)
```
V_out = 16 V

R_17 is arbitrarily set to 10 kΩ.

```math
=>16 = 1.229 ( \frac{R_{18}}{10,000} + 1)
```
```math
```
```math
R_{1} = 120.2 kΩ = 120 kΩ
```

The Inductor is recommended to be between 10 uH and 22 uH. A 15 uH Inductor will be used to match the inductor on the MPPC BuckBoost.

The compensation network resistor, R19, and capacitor, C15, are recommended to be 10 kΩ and 680 pF respectively. 

The output capacitor is recommended to be between the values of 1 uF and 10 uF. A 5 uF capacitor will be used. 

The input capacitor is recommended to be between the values of 1 uF and 4.7 uF. A 5 uF capacitor will be used to match the output capacitor.

### Operational Amplifer
The _TLV9361QDCKRQ1_ Operational Amplifier has been chosen for its supply range of 2.25 V to 20 V. 

*Figure 8. Noninverting Operational Amplifier Schematic*

![NonInvertingOpAmpSchem](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/d304539d-4012-425c-9054-18f5685a1f9b)

```math
V_{out} = V_{McuOut} ( \frac{R_{1} + R_{2}}{R_{2}})
```

R_2 is arbitrarily set to 10 kΩ.

```math
=>12 = 5 ( \frac{R_{1} + 10,000}{10,000})
```
```math
```
```math
R_{1} = 14 kΩ
```
## LT3120 MPPC BuckBoost Converter

*Figure 10. MPPC BuckBoost Schematic*

![MPPC_BuckBoost_Schematic](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/77c6b65d-4030-4f47-84da-bdd2f5ed8677)

The Maximal Power Point Control Buck-Boost will be activated at 5 V from the solar panel and will output 12 V. 

The output voltage is chosen to be 12 V to correspond with the 12 V batteries. This will allow the subsystem output to remain near 12 V whether it's the MPPC buckboost powering the system or if it's the batteries powering the system. 

The activiation voltage of 5 V has been derived from the diagram obtained from the datasheet below:

*Figure 11. MPPC BuckBoost Efficiency vs Output Current*

![MPPC_EN_V_CHART](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/29067efa-4bf9-4003-87b2-75b1e6abfbd5)

The highlighted portion of the chart shows that a 5 V input at 1 MHz switching frequency and 12 V output should be able to produce 1 A of current. This amount of current will be sufficient to power the system. 

This graph also shows that at 12 and 15 V inputs, 8 A of current can be drawn. When the solar panel is producing anywhere from 12 to 18 V, the MPPC Buckboost will be able to generate enough current to charge both batteries at a rate near their maximum charge current of 3.6 A each through the LTC4020 ICs.

### Datasheet Provided Values:
```math
C_{BST1}\ = 0.22 uF
```
```math
C_{BST2}\ = 0.22 uF
```
```math
C_{BST3}\ = 22 nF
```
```math
C_{VCC}\ = 4.7 uF (LowESRCeramicCapacitor)
```
```math
V_{FB} = 1.25 V 
```
### Desired Input and Output:
```math
V_{IN(max)} = 18 V
```
```math
V_{IN(min)} = 5 V
```
```math
V_{OUT} = 12 V
```
### Output Voltage Programming:
R_FB2 is nominally chosen to be 10 kΩ.
```math
V_{OUT} = 0.795\times(1+\frac{R_{FB1}}{ R_{FB2}})
```
```math
=>R_{FB1}\ = 12\times\frac{10,000}{0.795} - 10,000
```
```math
```
```math
R_{FB1}\ = 141 kΩ = 140 kΩ
```
```math
R_{FB1}\ = 10 kΩ
```
### Programming Custon Vin Enable thresholds:
```math
V_{th(rising)} = 1.205 \times\ \frac{R_{EN1} + R_{EN2}}{R_EN2}
```
R_en2 is arbitrarily set to 10 kΩ.
```math
=>R_{EN1} = 5 \times\ \frac{10,000}{1.205} - 10,000
```
```math
```
```math
R_{EN1} = 31,493 Ω = 30 kΩ
```
```math
R_{EN2} = 10 kΩ
```
### Programming Custom Vin Hysteresis:
```math
V_{HYST}\ = ((R_{HY} \times\ R_{EN1}) + (R_{HY}\times\ R_{EN2}) + (R_{EN1}\times\ R_{EN2})) \times\ \frac{0.25 \times\ 10^{-6}}{R_{EN2}} + (0.09 \times\ \frac{R_{EN1} + R_{EN2}}{R_{EN2}})
```
V_hyst is set to be 1 V
```math
=>1\ = ((R_{HY} \times\ 30,000) + (R_{HY}\times\ 10,000) + (30,000\times\ 10,000)) \times\ \frac{0.25 \times\ 10^{-6}}{10,000} + (0.09 \times\ \frac{30,000 + 10,000}{10,000})
```
```math
```
```math
R_{HY}\ = 632,500 Ω = 630 kΩ
```
### MPPC Programming:
Vmppc should be 75% of the solar panel's open circuit voltage, 16.8 V. R_mppc2 should be between 50 kΩ and 250 kΩ.
R_mppc2 is arbitrarily chosen to be 100 kΩ.
```math
V_{MPPC}\ = 0.795\times(1+\frac{R_{MPPC1}}{ R_{MPPC2}})
```
```math
=>R_{MPPC1}\ = 16.8\times\frac{100,000}{0.795} - 100,000
```
```math
```
```math
R_{MPPC1}\ = 2,014,150 Ω = 2 MΩ
```
```math
R_{MPPC2}\ = 100 kΩ
```

MPPC requires compensation to maintain stability of the input voltage regulation loop.
C_mppc and R_mppc3 are a zero-pole pair.

```math
C_{MPPC}\ = \frac{1}{2π \times\ R_{MPPC2} \times\ 360}
```
```math
=>C_{MPPC}\ = \frac{1}{2π \times\ 100,000 \times\ 360}
```
```math
```
```math
C_{MPPC}\ = 4.42 nF = 4 nF
```
```math
```
```math
R_{MPPC3}\ = \frac{C_{Vin}}{2π \times\ C_{MPPC}}
```
```math
=>R_{MPPC3}\ = \frac{100 \times\ 10^{-6}}{2π \times\ 4.42 \times\ 10^{-9}}
```
```math
```
```math
R_{MPPC3}\ = 3.6 kΩ
```
### Programming Switching Frequency:
```math
F_{sw}= \frac{100 \times\ 10^{9}}{8 + (1.2 \times\ R_{RT})}
```
Switching frequency is chosen to be 1 MHz.
```math
=>1,000,000= \frac{100 \times\ 10^{9}}{8 + (1.2 \times\ R_{RT})}
```
```math
```
```math
R_{RT} = 76.6 kΩ = 76.8 kΩ
```

### Inductor Selection:

The LT3120 Datasheet recommends inductors between the values of 1.5 uH and 15 uH for best performance.

A 15 uH inductor is chosen as the minimum voltage input, 5, is close enough to 12 to not cause a detrimental amount of ripple current in boost mode.

Inductor Ripple Current in Buck Mode:

```math
I_{Δ}= \frac{V_{OUT}}{L} \times\ \frac{V_{IN(max)} - V_{OUT}}{V_{IN(max)}} \times\ (\frac{1}{F_{sw}} - 70\times\ 10^{-9})
```
```math
=>I_{Δ}= \frac{12}{15\times\ 10^{-6}} \times\ \frac{18 - 12}{18} \times\ (\frac{1}{1,000,000} - 70\times\ 10^{-9})
```
```math
```
```math
I_{Δ}= 205 mA
```

Inductor Ripple Current in Boost Mode:

```math
I_{Δ}= \frac{V_{OUT}}{L} \times\ \frac{V_{OUT} - V_{IN(min)}}{V_{IN(min)}} \times\ (\frac{1}{F_{sw}} - 70\times\ 10^{-9})
```
```math
=>I_{Δ}= \frac{12}{15\times\ 10^{-6}} \times\ \frac{12- 5}{5} \times\ (\frac{1}{1,000,000} - 70\times\ 10^{-9})
```
```math
```
```math
I_{Δ}= 1.04 A
```
### Output Capacitor Selection:

The LT3120 Datasheet recommends a low ESR output capacitor to minimize output voltage ripple

I_load = 7.15 A

C_out is chosen to be 150 uF

Output Ripple Voltage in Buck Mode:

```math
V_{Δ}= \frac{I_{LOAD} \times\ 70 \times\ 10^{-9}}{ C_{OUT}}
```
```math
=>V_{Δ}= \frac{7.15 \times\ 70 \times\ 10^{-9}}{ 150 \times\ 10^{-6}}
```
```math
```
```math
V_{Δ}= 3.34 mV
```

Output Ripple Voltage in Boost Mode:

```math
V_{Δ}= \frac{I_{LOAD}}{(F_{SW} \times\ C_{OUT})} \times\ (V_{OUT} - V_{IN(min)} + \frac{70 \times\ 10^{-9} \times\ F_{SW} \times\ V_{IN(min)}}{V_{OUT}})
```
```math
=>V_{Δ}= \frac{7.15}{1,000,000 \times\ 150 \times\ 10^{-6}} \times\ (12 - 5 + \frac{70 \times\ 10^{-9} \times\ 1,000,000 \times\ 5}{12})
```
```math
```
```math
V_{Δ}= 29.2 mV
```
### Frequency Compensation Network:

R_Load = Vout / I_Load = 1.67 Ohms

Gcs = 13.6 A / V (Datasheet)

Eff = 80% (Datasheet)

Lowest Frequency for f_{RHPZ}

```math
f_{RHPZ} = \frac{V_{IN(MIN)}^{2} \times\ R_{LOAD}}{ V_{OUT}^{2} \times\ 2π \times\ L_{SW}}
```
```math
=>f_{RHPZ} = \frac{5^{2} \times\ 1.52}{ 12^{2} \times\ 2π \times\ (15 \times\ 10^{-6})}
```
```math
```
```math
f_{RHPZ} = 3100 Hz
```
The closed loop crossover frequency (fcc) should be sufficiently below the RHPZ frequency to account for variability of the internal components of the IC (Datasheet). A seventh of RHPZ will be chosen to match the example given in the datasheet.
```math
f_{CC} = \frac{1}{7} \times\ f_{RHPZ}
```
```math
```
```math
f_{CC} = 443 Hz
```
Phase contribution of RHPZ:
```math
Φ_{RHPZ} = -atan(\frac{fcc}{f_{FHPZ}})
```
```math
=>Φ_{RHPZ} = -atan(\frac{100}{700})
```
```math
```
```math
Φ_{RHPZ} = -8.13°
```
Effective Output Current Gain:
```math
G_{CS(OUT)} = G_{CS} \times\ \frac{V_{IN}}{2V_{OUT}} \times\ Eff
```
```math
=>G_{CS(OUT)} = 13.6 \times\ \frac{5}{2(12)} \times\ 0.8
```
```math
```
```math
G_{CS(OUT)} = 2.27 \frac{A}{V}
```
Output Load Pole
```math
f_{VC} = \frac{2}{2π \times\ R_{LOAD} \times\ C_{OUT}}
```
```math
=>f_{VC} = \frac{2}{2π \times\ 1.67 \times\ 150 \times\ 10^{-6}}
```
```math
```
```math
f_{VC} = 1270.7 Hz
```
Gain and Phase Contributions due to the Output Filter:
```math
G_{OUT} = G_{CS(OUT)} \times\ \sqrt{\frac{R_{LOAD}^{2}}{ (\frac{f_{CC}}{f_{VC}})^{2} + 1}}
```
```math
=>G_{OUT} = 2.27 \times\ \sqrt{\frac{1.67^{2}}{ (\frac{442}{1271})^{2} + 1}}
```
```math
```
```math
G_{OUT} = 3.78
```
```math
```
```math
Φ_{VC} = -atan(\frac{f_{CC}}{f_{VC}})
```
```math
=>Φ_{VC} = -atan(\frac{442}{1271})
```
```math
```
```math
Φ_{VC} = -19.18°
```
Required Phase Boost from the Compensation Network:
A Phase margin of 50° is chosen to match the example from the datasheet.
```math
Φ_{Z} = 50 - Φ_{VC} - Φ_{RHPZ} - 180
```
```math
=>Φ_{Z} = 50 - (-19.18) - (-8.13) - 180
```
```math
```
```math
Φ_{Z} = -102.69°
```
Compensation Network Gain:
```math
G_{COMP} = (\frac{0.795}{V_{OUT}} \times\ G_{OUT} )^{-1}
```
```math
=>G_{COMP} = (\frac{0.795}{12} \times\ 3.78 )^{-1}
```
```math
G_{COMP} = 3.99 = 4
```
```math
R_{VC} = \frac{G_{COMP}}{ 120 \times\ 10^{-6}}
```
```math
=>R_{VC} = \frac{4}{ 120 \times\ 10^{-6}}
```
```math
R_{VC} = 33,333Ω = 35 kΩ
```
```math
C_{VC} = \frac{tan(Φ_{Z})}{ 2π \times\ f_{CC} \times\ R_{VC}}
```
```math
=>C_{VC} = \frac{tan(-102.69)}{ 2π \times\ 442 \times\ 35,000}
```
```math
C_{VC} = 4.57 \times\ 10^{-8} = 50 pF
```
```math
```
```math
R_{VC} = 35 kΩ
```
```math
C_{VC} = 50 pF
```
## LTC4020 Battery Charger BuckBoost Analysis

*Figure 12. LTC4020 Schematic*

![BatteryChargerSchematic](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/c261d68d-fee7-4ad5-8a76-c2f6e054d151)

The _LTC4020_ IC has been chosen due to its ability to take in a range of input voltages from 4.5 V to 55 V and handle the different charging modes for sealed lead acid batteries. With this IC, the battery simply needs to be connected to the charge output to be charged instead of having to design different circuitry for each charging mode.

Two IC will be used for this subsystem, one for each battery. This is so that the batteries will be charged in the appropriate mode in the case that the two batteries have different charges. 

Due to having two _LTC4020_ circuits, a separate PCB has been designed from the other BuckBoost and circuitry. This will allow for a more modular design and increased flexibility for adding or removing batteries from the subsystem.

The ICs will take in 8 V from the MPPC Output voltage that is controlled by the Arduino's PWM.

### Overcharge Protection:

The _LTC4020_ handles all aspects of charging, including overcharge protection. This is done through the use of the different charging modes. Once the battery is deemed 'charged enough', float charge kicks in to place to maintain the battery at near full capacity. This is standard for sealed lead acid batteries. 

### Battery Charging Voltage Programming:
```math
V_{FLOAT} = 2.3125 \times\ (1 + \frac{R_{FB1}}{R_{FB2}})
```
The battery's required float charge voltage is in between 13.6 V and 13.8 V. A value of 13.7 V will be chosen to give room for 100 mV of error. 

R_fb2 is arbitrarily chosen to be 20 kΩ.

```math
=>13.7 = 2.3125 \times\ (1 + \frac{R_{FB1}}{20,000})
```
```math
```
```math
R_{FB1} = 98.5 kΩ
```
```math
R_{FB2} = 20 kΩ
```
The battery's cycle charge voltage range is from 14.5 V to 14.9 V. Using the above resistances, the absoption voltage is calculated as follows:
```math
V_{ABSORPTION} = 2.5 \times\ (1 + \frac{R_{FB1}}{R_{FB2}})
```
```math
=>V_{ABSORPTION} = 2.5 \times\ (1 + \frac{98,500}{20,000})
```
```math
```
```math
V_{ABSORPTION} = 14.8125
```
V_absorption is less than the maximal 14.9 V. The battery will be charged within its specifications.

### Battery Charging Current Programming:
The battery's maximum charging current is rated at 3.6 A.

```math
R_{CS} = \frac{0.05}{I_{CSMAX}}
```
```math
=>R_{CS} = \frac{0.05}{3.6}
```
```math
```
```math
R_{CS} = 0.014 Ω
```
### Output Voltage Programming:
```math
V_{OUT} = 2.75 \times\ (1 + \frac{R_{FBMAX1}}{R_{FBMAX2}})
```
The datasheet recommends the two output voltage programming resistors, R_fbmax1 and R_fbmax2, to match those of the battery charge voltage resistors, R_fb1 and R_fb2.
```math
=>V_{OUT} = 2.75 \times\ (1 + \frac{98,500}{20,000})
```
```math
```
```math
V_{OUT} = 16.29 V
```
This output voltage is unused.

### Programming Switching Frequency:
A switching frequency of 100 kHz is desired.
```math
R_{RT} = 100,000 \times (\frac{F_{0}}{250,000})^{-1.0695}
```
```math
=>R_{RT} = 100,000 \times (\frac{100,000}{250,000})^{-1.0695}
```
```math
```
```math
R_{RT} = 266,438 Ω ~= 270 kΩ
```
### Inductor Selection: 
Inductor selection when the primary operating mode is V_in < V_out:

Φ_L is the ratio of peak to peak ripple current to max average inductor current =  0.2
```math
L_{MIN} = \frac{V_{IN(MIN)} \times\ (1 - \frac{ V_{IN(MIN)}}{V_FBMAX})}{ F_{0} \times\ Φ_{L} \times\ I_{MAX}}
```
```math
=>L_{MIN} = \frac{2.5 \times\ (1 - \frac{ 2.5 }{2.75})}{ 100,000 \times\ 0.2 \times\ 3.6}
```
```math
```
```math
L_{MIN} = 3.156 uH = 3 uH
```

The _PA4339.701NLT_ 5 uH inductor will be used for its 4 A current rating.

### Inductor Current Sensing Selection:
The datasheet recommends that both sense resistors are of the same value.

```math
R_{SENSE} = \frac{0.05}{I_{MAX}}
```
```math
=>R_{SENSE} = \frac{0.05}{3.6}
```
```math
```
```math
R_{SENSE} = 0.014 Ω
```
```math
```
```math
C_{SENSEB} = \frac{10^{-9}}{R_SENSE}
```
```math
=>C_{SENSEB} = \frac{10^{-9}}{0.014}
```
```math
```
```math
C_{SENSEB} = 66.7 nF = 70 nF
```
### Input Supply Decoupling:
A high quality low ESR decoupling capacitor is recommended to minimize voltage glitches on the V_in supply.

Placing a smaller ceramic cap (0.1 u to 10 u) close to the IC in parallel with the input decoupling capacitor is recommended for high frequency noise reduction.

For boost operation: 
```math
C_{IN} = \frac{ I_{MAX}}{ V_{IN(MIN)} \times\ F_{0}}
```
```math
=>C_{IN} = \frac{ 3.6}{ 2.5 \times\ 100,000}
```
```math
```
```math
C_{IN} =14.4 uF = 14 uF
```
### Output Supply Decoupling:
A high quality low ESR decoupling capacitor is recommended to minimize voltage glitches on the V_out supply.

V_Δout is the acceptable output ripple voltage = 50 mV.

For boost operation:
```math
C_{OUT} >= \frac{ I_{MAX} \times\ (V_{FBMAX} - V_{IN(MIN)})}{ V_{FBMAX} \times\ F_{0} \times\ V_{ΔOUT}}
```
```math
=>C_{OUT} >= \frac{ 3.6 \times\ (2.75 - 2.5)}{ 2.75 \times\ 100,000 \times\ 0.05}
```
```math
```
```math
C_{OUT} >= 65 uF
```

## Battery Charging and Discharging Switching Logic

*Figure 13. Charge Controller Switching Logic*

![SwitchingLogicSchematic](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/d0d2b79f-e9f1-429a-b16f-d59f0f4ce858)

Batteries can not be charged and discharged at the same time. Relay circuity has been designed to switch the batteries from a disconnected orientation for charging to a parallel orientation for discharging. 

When the solar panel is generating power, the MPPC Output is outputting 12 V which causes the relays to switch to the normally open position connecting the batteries to the battery charging ICs. Otherwise the batteries will be connected to the output of the system by connecting to the normally closed position.

The _G6RN-1_ SPDT relay has been chosen due to its 8 A switching capability and a 12 V coil voltage. Its operational durability is dependent on the switching current. While charging, the switching current will be close to the amount of current required to charge the batteries plus the current required to run the battery charger IC, estimated to be 3.5 A. At 3.5 A, 100,0000 operations can be expected. Assuming that there are 50 operations a day, 50 times that the batteries and solar switch who is powering the system, the relays will last 2,000 days or nearly five and a half years. 

# BOM
| Part | Part Number | Quantity | Price Per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Arduino Nano | ABX00028 | 1 | $13.70 | $13.70 |
| MPPC Buck-Boost Converter | LT3120JV#PBF | 1 | $10.04  | $10.04 |
| Battery Charger Buck-Boost Converter | LTC4020EUHF#PBF | 1 | $12.51 | $12.51 |
| Boost Converter | TPS61170DRVR | 1 | $1.94 | $1.94 |
| Current Sensor | ACS712ELCTR-05B-T | 1 | $3.70 | $7.40 |
| Operational Amplifier | TLV9361QDCKRQ1  | 1 | $1.51 | $1.51 |
| SPDT Relay | G6RN-1-DC5 | 2 | $4.10 | $8.20 | 
| Dual N-Channel MOSFET | SI7272DP-T1-GE3 | 3 | $1.43 | $4.29 |
| P-Channel MOSFET | NVD5117PLT4G-VF01 | 1 | $1.97 | $1.97 |
| Schottky Diode | SBR0560S1Q-7 | 4 | $0.38 | $1.52 |
| Zener Diode | BZX84C6V2LT116 | 1 | $0.24 | $0.24 |
| Diode | RFN10BM3STL | 1 | $1.27 | $1.27 |
| 50 pF Capacitor | 12062A500KAT2A | 1 | $0.40 | $0.40 |
| 100 pF Capacitor | KGM31BCG1H101JT | 1 | $0.24 | $0.24 |
| 680 pF Capacitor | KGM31TCG2H681JU | 2 | $0.28 | $0.56 |
| 1 nF Capacitor | KGM31AR73D102KU | 1 | $0.71 | $0.71 |
| 4 nF Capacitor | 30LVD40-R | 1 | $1.66 | $1.66 |
| 10 nF Capacitor | KAM31GCG2J103JU | 1 | $0.99 | $0.99 |
| 22 nF Capacitor | KGM31BR71H223JT | 1 | $0.31 | $0.31 |
| 68 nF Capacitor | C1206C683J5GECAUTO7210 | 1 | $0.74 | $0.74 |
| 0.1 uF Capacitor | KGM31BCG1H101JT | 4 | $0.24 | $0.96 |
| 0.22 uF Capacitor | KAF31BR71H224KT | 2 | $0.44 | $0.88 |
| 0.33 uF Capacitor | KAM31NR81H334KU | 1 | $0.40 | $0.40 |
| 1 uF Capacitor | KGM31HR71E105KU | 2 | $0.33 | $0.66 |
| 2.2 uF Capacitor | KAF31GR71E225KU | 1 | $0.42 | $0.42 |
| 5 uF Capacitor | TE1202-E3 | 3 | $4.58 | $13.74 |
| 10 uF Capacitor | 870575873001 | 4 | $1.33 | $5.32 |
| 15 uF Capacitor | C3216X5R1V156M160AC | 2 | $0.99 | $1.98 |
| 68 uF Capacitor | C3216X5R0J686M160AB | 1 | $0.71 | $0.71 |
| 150 uF Capacitor | 870575574002 | 1 | $1.81 | $1.81 |
| 0.014 Ω Resistor | WSL2512R0140FEA18 | 3 | $1.03 | $3.09 |
| 100 Ω Resistor | SFR18EZPF1000 | 2 | $0.26 | $0.52 |
| 3.6 kΩ Resistor | CCF073K60JKE36 | 1 | $0.30 | $0.30 |
| 10 kΩ Resistor | CFR01SJ0103B00 | 6 | $0.033 per unit | $0.198 |
| 14 kΩ Resistor | ERA-8AEB1402V | 1 | $0.59 | $0.59 |
| 17 kΩ Resistor | MFR-12FTF52-17K | 1 | $0.10 | $0.10 |
| 20 kΩ Resistor | 3503G2B20KFTDF | 2 | $1.67 | $3.34 |
| 30 kΩ Resistor | CRCW251230K0JNEG | 1 | $0.32 | $0.32 |
| 33 kΩ Resistor | CFR01SJ0333B00 | 2 | $0.033 per unit | $0.066 |
| 76.8 kΩ Resistor | CCF5576K8FKE36 | 1 | $0.30 | $0.30 |
| 98.8 kΩ Resistor | TNPW120698K8BEEN | 2 | $0.88 | $1.76 |
| 100 kΩ Resistor | CFR01SJ0104B00 | 1 | $0.033 per unit | $0.033 |
| 120 kΩ Resistor | ERA-8KEB1203V | 1 | $0.82 | $0.82 |
| 140 kΩ Resistor | CRCW2512140KFKEG | 1 | $0.34 | $0.34 |
| 270 kΩ Resistor | ERA-8KEB2703V | 1 | $0.82 | $0.82 |
| 620 kΩ Resistor | CRCW2512620KJNEG1 | 1 | $0.32 | $0.32 |
| 2 MΩ Resistor | RCV12062M00FKEAAT | 1 | $0.35 | $0.35 |
| Total | ----- | ----- | ----- | $--.-- |
