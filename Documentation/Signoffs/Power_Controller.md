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
| a.  | Sensor | 9 V | 0.06 A |
| b.  | Data interpretation, Transmission, and Storage | 5 V | 0.25 A |
| c.  | Charge Controller | 5 V | 0.25 A |

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







# BOM
| Part | Part Number | Quantity | Price Per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Step down buck regulator | LTC3621 | 2 | $7.38 |  $14.76 |
| Fuse | ??? | ?? | ??? | ??? |
| Total | ----- | ----- | ----- | $91.97 













