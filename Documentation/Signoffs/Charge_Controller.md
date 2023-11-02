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
3. The subsystem shall prevent the batteries from discharging more than 50% of their maximum capacity. This constraint is to prevent the batteries from deep discharge. Deep discharge prematurly ages the battery. The maximum discharge percentage of 50% has been chosen TODO     To ensure the batteries are able to be used for as long as possible, deep discharge protection is necessary.
4. The subsystem shall prevent the batteries from charging more than 95% of their maximum capacity. This constraint is to prevent the batteries from overcharging. Overcharging can cause the overheating and long term damage to the batteries. The maximum charge of 95% has been chosen TODO    To ensure the batteries are able to be used for as long as possible, overcharge protection is necessary. 

*Figure 1. Charge Controller Block Diagram*


![Charge Controller Block Diagram](https://raw.githubusercontent.com/Brady-Beecham/Capstone-Team-PowerHouse/Charge_Controller_Signoff/Documentation/Images/ChargeControllerBlockDiagram.jpeg)



# BOM
| Part | Part Number | Quantity | Price Per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Arduino Nano | ABX00028 | 1 | $13.70 | $13.70 |
| Buck-Boost Converter | MAX20040ATPA/VY+ | 1 | $2.48 | $2.48 |
| Digital Potentiometer | MAX5474 | 1 | $2.48 | $2.48 |
| Current Sensor | ACS712ELCTR-05B-T | 2 | $3.70 | $7.40 |
| Dual Op Amp | TSB622IST | 1 | $1.54 | $1.54 |

