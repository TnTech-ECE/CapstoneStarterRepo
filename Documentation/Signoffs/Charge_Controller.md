# Charge Controller Subsystem

The purpose of the charge controller subsystem is to maximize the power output of the solar panel and send power to the system, specifically the Power Controller subsystem. The charge controller will send the power controller 12 V at 50 mA regardless of the output of the solar panel. If the power received from the panel is more than what is required by the system, the excess power will be used to charge the two back batteries. Otherwise, the backup batteries will supplement the solar panel output until the required system power is met. 
# Constraints
| No. | Constraints | Origin |
| --- | ----------- | ------ |
| 1.  | Controller shall maximize the output power from the solar panel. | System Requirements |
| 2.  | Controller shall output 12 V at 50 mA with a 10% tolerance to the Power Controller. | System Requirements |
| 3.  | Controller shall prevent the batteries from discharging more than 50% of their maximal capacity. | Extend Life of Batteries    |
| 4.  | Controller shall prevent the batteries from being charged more than 95% of their maximal capacity.  | Extend Life of Batteries    |

1. The subsystem shall maximize the output power from the solar panel. Solar panels can only generate power when they are placed in sunlight. Sunlight, while abundant, only lasts for half of a day on a clear summer day. The other half of the day, or on a rainy day, no power is generated from the solar panel. While the solar panels are able to generate power from the sun, the power needs to be maximized to make up for being unable to generate power at other times. 
2. The subsystem shall output 12 V at 50 mA with a 10% tolerance to the Power Controller. 50 mA is required to power all of the subsystems. 12 V is used to match the voltage of the backup batteries. 
3. The subsystem shall prevent the batteries from discharging more than 50% of their maximum capacity. This constraint is to prevent the batteries from deep discharge. Deep discharge prematurley ages the battery. To ensure the batteries are able to be used for as long as possible, deep discharge protection is necessary.
4. The subsystem shall prevent the batteries from charging more than 95% of their maximum capacity. This constraint is to prevent the batteries from overcharging. Overcharging can cause the overheating and long term damage to the batteries. To ensure the batteries are able to be used for as long as possible, overcharge protection is necessary. 

*Figure 1. Charge Controller Schematic*
![ChargeControllerSchematic](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/70d331c8-993a-493d-aac8-c0ff65264913)

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

U6 is the Arduino Nano. It will receive inputs from U2, U4, U5, and a voltage read from a voltage divider. It will output to U1, U3, U5, and Q1. 

The input from U2, a current sensor to read output current from the solar panel,  and the voltage divider, to read output voltage from solar panel, will be used for the Maximum Power Point Tracking algorithm. The algorithm will send digital signals to U1, the digital potentiometer, to adjust the resistance of the solar panel output. This change of resistance will change the amount of power being output from the solar panel. The algorithm will continually change the resistance trying to find the maximum power output from the solar panel. 

U2 can output up to a maximum of 8 V. The Arduino is only able to read up to a maximum of 5 V. A voltage divider will be used on the output of the current sensor to change the output to have a maximum voltage of 5 V. 

To read the voltage being output from the solar panel, a voltage divider will be used to change the maximum output voltage of the solar panel, 18 V, to a voltage that the arduino can handle, 4.5 V. 

The Buck boost will have a varying current output that will be measured by U4. This information is use to allow the MCU to regulate the current flowing in or out of the batteries through a MOSFET.

The batteries are connected to a bidirectional current and power monitor, U5. This will be used to keep track of the power being charged and discharged from the batteries. Having this information will allow the MCU to prevent the batteries from overcharging and deep discharging. TODO: How will overcharging and deep discharging be prevented physically?

MOSFET input range: 
 continuous drain current-> 14 A
 gate source voltage-> -20 A to 20 A
 gate threshold voltage 2 V to 4 V

# BOM
| Part | Part Number | Quantity | Price Per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Arduino Nano | ABX00028 | 1 | $13.70 | $13.70 |
| Buck-Boost Converter | MAX20040ATPA/VY+ | 1 | $2.48 | $2.48 |
| Digital Potentiometer | MAX5474 | 1 | $2.48 | $2.48 |
| Current Sensor | ACS712ELCTR-05B-T | 2 | $3.70 | $7.40 |
| Bidirectional Current and Power Monitor | INA226AIDGST | 1 | $3.33 | $3.33 |
| MOSFET | BSC13DN30NSFD | 1 |$1.72 | $1.72 | 
| Schottky Diode | | 1 | | |
| Total | ----- | ----- | ----- | $--.-- |

# References
Solar panel datasheet: https://m.media-amazon.com/images/I/C1dszUHMnaL.pdf

Digital potentiometer datasheet: https://www.analog.com/media/en/technical-documentation/data-sheets/MAX5471-MAX5475.pdf

MOSFET datasheet: https://www.infineon.com/dgdl/Infineon-BSC13DN30NSFD-DS-v02_01-EN.pdf?fileId=5546d46259b0420a0159d5c940fc0d9a

Bidirectional current and power monitor datasheet: https://www.ti.com/lit/ds/symlink/ina226.pdf?ts=1699175796094&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FINA226%253Futm_source%253Dgoogle%2526utm_medium%253Dcpc%2526utm_campaign%253Dasc-null-null-GPN_EN-cpc-pf-google-eu%2526utm_content%253DINA226%2526ds_k%253DINA226%2BDatasheet%2526DCM%253Dyes%2526gclid%253DEAIaIQobChMIvurP68KsggMVYZKDBx2_egHxEAAYASAAEgIQ9PD_BwE%2526gclsrc%253Daw.ds

Arduino Nano datasheet: https://docs.arduino.cc/resources/datasheets/A000005-datasheet.pdf
