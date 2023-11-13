# Charge Controller Subsystem

The purpose of the charge controller subsystem is to maximize the power output of the solar panel and send power to the system, specifically the Power Controller subsystem. The charge controller will send the power controller 12 V at 50 mA regardless of the output of the solar panel. If the power received from the panel is more than what is required by the system, the excess power will be used to charge the two backup batteries. Otherwise, the backup batteries will supplement the solar panel output until the required system power is met. 

# Constraints
| No. | Constraints | Origin |
| --- | ----------- | ------ |
| 1.  | Controller shall maximize the output power from the solar panel. | System Requirements |
| 2.  | Controller shall output 12 V at ??? mA with a 10% tolerance to the Power Controller. | System Requirements |
| 3.  | Controller shall prevent the batteries from discharging more than 50% of their maximal capacity. | Extend Life of Batteries    |
| 4.  | Controller shall prevent the batteries from being charged more than 95% of their maximal capacity.  | Extend Life of Batteries    |

1. The subsystem shall maximize the output power from the solar panel. Solar panels can only generate power when they are placed in sunlight. Sunlight, while abundant, only lasts for half of a day on a clear summer day. The other half of the day, or on a rainy day, no power is generated from the solar panel. While the solar panels are able to generate power from the sun, the power needs to be maximized to make up for being unable to generate power at other times. 
2. The subsystem shall output 12 V at 50 mA with a 10% tolerance to the Power Controller. 50 mA is required to power all of the subsystems. 12 V is used to match the voltage of the backup batteries. 
3. The subsystem shall prevent the batteries from discharging more than 50% of their maximum capacity. This constraint is to prevent the batteries from deep discharge. Deep discharge prematurley ages the battery. To ensure the batteries are able to be used for as long as possible, deep discharge protection is necessary.
4. The subsystem shall prevent the batteries from charging more than 95% of their maximum capacity. This constraint is to prevent the batteries from overcharging. Overcharging can cause the overheating and long term damage to the batteries. To ensure the batteries are able to be used for as long as possible, overcharge protection is necessary. 

*Figure 1. Charge Controller Schematic*

![ChargeControllerSchematic](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/c2b2df89-f01d-4235-8380-fac168b3c779)

# Analysis

| Part | Input Voltage Range (V) | Input Current Range (A) | Output Voltage Range (V) | Output Current Range (A) |
| ------------ | ------------- | --------- | -------- | ---------- |
| Arduino Nano | 0 to 5 | --- | 0 to 5 | --- |
| Solar Panel | --- | --- | 0 to 18 | 0 to 1.4 |
| Digital Potentiometer | 0.8 to 5 (Digital pins only) | --- | --- | ---|
| Current Sensor | --- | -5 to 5 | 0 to 8 | 0.003 to 0.010 |
| Buck Boost Converter | 4.5 to 36 | --- | 12 | 1.2 max |
| MOSFET | --- | -20 to 20 | --- | -20 to 20 | 
| Bidirectional current and power monitor | -40 to 40 | 0.005 | 0 to 5 | 0.010 |

### Solar Panel


### Battery
Two MightyMax Ml12-12 batteries will be used. The battery type is Sealed Lead Acid AGM. The sealed lead acid has a depth of discharge of 50%, and the battery's efficiency is 85 %. The two batteries will be connected in parallel to increase the global capacity of the battery, which is rated by amps per hour. The temperature factor is 1.19.

The batteries will be located outdoors; therefore, the discharge capacity according to the temperature should be considered. The discharge capacity for the battery being outdoors for 20 hours at a temperature of -15 C will reduce the battery capacity to 65%.

```math
Battery\ Capacity (Ah) = \ \frac{Daily\ Electrical\ Load\ \times\ Days\ of\ Autonomy\ \times\ Temperature\ Compensation\ }{Load\ Subsystem\ Efficiency\ \times\ Depth\ of\ Discharge\ \times\ Voltage}
```
```math
```
```math
Battery\ Capacity (Ah)= \ \frac{ 22.5 \times\ 3 \times\ 1.19 }{ 0.85 \times\ 0.5 \times\ 12}
```
```math
```
```math
Battery\  Capacity (Ah) =\ 15.75\ Ah
```
For a battery capacity of 15.75 Ah, increasing the battery capacity is considered a good practice when choosing battery capacity for a solar power system. Also, considering the depth of discharge and other loss power factors, the desired battery capacity will be 24 Ah, which means we will need two batteries with 12 V and 12 Ah in parallel. Since connecting a battery in parallel will increase the battery capacity, the battery capacity will increase to 24 Ah, and the battery voltage will remain the same at 12 V. 


### Arduino Nano
U6 is the Arduino Nano. It will receive inputs from U2, U4, U5, and a voltage read from a voltage divider. It will output to U1, U3, U5, Q1, and Q2. 

The input from U2, a current sensor to read output current from the solar panel,  and the voltage divider, to read output voltage from solar panel, will be used for the Maximum Power Point Tracking algorithm. The algorithm will send digital signals to U1, the digital potentiometer, to adjust the resistance of the solar panel output. This change of resistance will change the amount of power being output from the solar panel. The algorithm will continually change the resistance trying to find the maximum power output from the solar panel. 


### Current Sensors
U2 can output up to a maximum of 8 V. The Arduino is only able to read up to a maximum of 5 V. A voltage divider will be used on the output of the current sensor to change the output to have a maximum voltage of 5 V. 

Analysis of resistors required to divide 8 V down to 5 V (U2 and U4):

```math
Vout\ =Vin\times\frac{R1}{R1 + R2}
```
```math
5\ = 8\times\frac{10,000}{10,000 + R2} = 6 kΩ
```
R1 is arbitrarily chosen to be 10 kΩ. R2 is calculated to be 6 kΩ.

### Solar Output Voltage
To read the voltage being output from the solar panel, a voltage divider will be used to change the maximum output voltage of the solar panel, 18 V, to a voltage that the arduino can handle, 4.5 V. 

Analysis of resistors required to divide 18 V down to 4.5 V
```math
Vout\ =Vin\times\frac{R3}{R3 + R4}
```
```math
5\ = 18\times\frac{10,000}{10,000 + R4} = 30 kΩ
```
R3 is arbitrarily chosen to be 10 kΩ. R4 is calculated to be 30 kΩ. 

### BuckBoost Converter
The Buck boost, U3, will have a varying current output that will be measured by U4. The voltage output is set to 12 V to match the battery voltage. 

Analysis of components required to operate U3:

Vinmax = 18 V

Vout = 12 V

Vfb = 1.25 V (typical from datasheet)

ILmax = 1.2 A

%Iripple = 40%

Rfb2 is commonly set to 10 kΩ

Rfsw = 73.2 kΩ (datasheet) and is rounded to 75 kΩ

fsw = 400 kHz based on Rfsw (datasheet)

```math
Rfb1\ =Rfb2\times\frac{Vout}{Vfb} -Rfb2\ =\ 86 kΩ
```

```math
L_Buck\ =\frac{(Vinmax-Vout)Vout}{fsw\ \times\ ILmax\ \times\ \%Iripple\ \times\ Vinmax} =\ 208 μH
```

```math
Rc\ = 2π \times \ \frac{(Rcb \times Cout)}{gm \times\ (1 - Dboost)} \times\ \frac{(Rfb2 + Rfb1)}{Rfb2} =\ 13.92 kΩ
```


The current information from U3 is used to allow the MCU to regulate the current flowing in and out of the batteries through Q1 or Q2. 

### Overcharge and Deep Discharge Protection
MOSFET Q1 will be used to prevent deep discharge. When the Arduino reads that the battery is entering deep discharge range, the MOSFET will close and no more current will flow out of the batteries. This means that the system will not receive enough current to operate and will shut down due to lack of power. 

MOSFET Q2 will be controlled to allow excess current to flow to ground to prevent overcharge. 

Analysis of components required for Q1 AND Q2:

```math
Ic(sat)\ = \frac{Vcc - Vce(sat)}{Rc}
```
```math
Ib(min)\ = \frac{Ic(sat)}{βdc}
```
```math
Vrbjt\ = Vnano - Vbe(sat)
```
```math
Rbjt\ = \frac{Vrbjt}{Ib(min)}
```

### Battery Monitor
The batteries are connected to a bidirectional current and power monitor, U5. This will be used to keep track of the power being charged and discharged from the batteries. Having this information will allow the MCU to prevent the batteries from overcharging and deep discharging. 

Analysis of components required for U5:

Rshunt\ = 2 mΩ (Datasheet)

Rp1, Rp2, and Rp3 were arbitrarily chosen to be 1 kΩ as they are used for pull up resistors. 


# BOM
| Part | Part Number | Quantity | Price Per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Arduino Nano | ABX00028 | 1 | $13.70 | $13.70 |
| Buck-Boost Converter | MAX20040ATPA/VY+ | 1 | $2.48 | $2.48 |
| Digital Potentiometer | MAX5474 | 1 | $2.48 | $2.48 |
| Current Sensor | ACS712ELCTR-05B-T | 2 | $3.70 | $7.40 |
| Bidirectional Current and Power Monitor | INA226AIDGST | 1 | $3.33 | $3.33 |
| NPN Silicon medium power transistor | ZTX653 | 2 | |  | 
| Schottky Diode | | 3 | | |
| Total | ----- | ----- | ----- | $--.-- |

# References
Solar panel datasheet: https://m.media-amazon.com/images/I/C1dszUHMnaL.pdf

Digital potentiometer datasheet: https://www.analog.com/media/en/technical-documentation/data-sheets/MAX5471-MAX5475.pdf

BJT datasheet: [ZTX653_Datasheet.pdf](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/files/13336931/ZTX653_Datasheet.pdf)

Bidirectional current and power monitor datasheet: https://www.ti.com/lit/ds/symlink/ina226.pdf?ts=1699175796094&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FINA226%253Futm_source%253Dgoogle%2526utm_medium%253Dcpc%2526utm_campaign%253Dasc-null-null-GPN_EN-cpc-pf-google-eu%2526utm_content%253DINA226%2526ds_k%253DINA226%2BDatasheet%2526DCM%253Dyes%2526gclid%253DEAIaIQobChMIvurP68KsggMVYZKDBx2_egHxEAAYASAAEgIQ9PD_BwE%2526gclsrc%253Daw.ds

Arduino Nano datasheet: https://docs.arduino.cc/resources/datasheets/A000005-datasheet.pdf
