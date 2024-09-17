# Power System for Camera System
## Functionality
The primary functionality for the camera power system is to reliably meet the power requirements for the camera hardware system's components. The system will supply 5 V to the camera system's Raspberry Pi 5 via a USB-C connection and 5 V to the Raspberry Pi HQ camera. The system will supply 5 V to both servo motors +5V DC and GND terminals.

## Constraints
| No.| Contraint | Origin |
| -- | --------- |--------|
|  1 | The system shall comply with ASTM B258-18 [2]. | Standards and Safety |
|  2 | The system shall be weather resitant to an IP67 rating [1].  | Standards and Safety |
|  3 | The system shall be able to supply enough power to the camera system for its full functionality | Design Team | 
|  4 | The system shall not be impacted by back EMF from the servo motors | Design Team | 
|  5 | The system shall contain a manual switch to individually cut off power supplied | Standards and Safety | 


      
<sup>1</sup> ASTM B258-18 is a standard for the proper wire gauge for electrical conductors. It is important to adhere to this standard to ensure the system is safe and avoid overheating, short circuits, and fires.  <br />

<sup>2</sup> The system will be located outdoors, so it is essential that the electrical components will be protected from environemental weather hazards and damage. The IP67 rating protects the system from cover rain, snow, dust, wind, and UV. Using this NEMA box will improve the longevity and prevent damage of the system. <br />

<sup>3</sup> This constraint is most important for system functionality, because the power system must supply the rated power for the camera system to acheive full functionality without running into any under voltage scenarios that could impact system peformance. <br />

<sup>4</sup> This constraint ensures that the power supply will not be damaged by an induced back EMF from the servo motors. 
<br />

<sup>5</sup> This constraint ensures safety of the system by providing a "kill switch" to immediately remove the power supplied to both power supplies in an emergency scenario.
<br />

## Schematic
<img width="1068" alt="Screenshot 2024-05-02 at 7 14 50 PM" src="https://github.com/mrnye42/Drone-Tracker-Project/assets/158224821/7252949e-e0d9-45f6-8259-16c696b38bbd">
<br />
Figure 1: Camera Power Schematic.<br />
The above schematic shows connections for the system. The schematic will be detailed with the signoff of the camera system, since the design of this power system will lag the camera system's design in case of changes required.




## Analysis
| Component | Min Voltage (V)| Max Voltage (V)| Min Current (A)| Max Current (A)| Min Power (W)| Max Power (W)|
| --------- | ---------------| -------------- |----------------| -------------- | ------------ | ------------ |
| Raspberry Pi 4B, 8 GB Memory| 5| 5| 2.5| 3.0| 12.5| 15.0|
| Digital Servo, 20 kg torque, 180 degrees Control Angle| 5| 6.8| 0.004| 2.2| 0.02| 14.96|
| Digital Servo, 20 kg torque, 270 degrees Control Angle| 5| 6.8| 0.004| 2.2| 0.02| 14.96|
| Raspberry Pi HQ camera| 5| 5| 0.3| 0.3| 1.5| 1.5|
| Total     |                |                |  2.81 A         |  7.1 A         |  14.04 W        |  46.42 W     |

Table 1: Power Requirements.<br />

For this system, five volts is required for all components, so the five volt power supplies will be able to provide power to all the components. The worst case power draw from the system is 45.67 W, so the chosen 100 W power supplies will meet those requirements with plenty of wattage to spare. The cost reduction from a lower wattage power supply is minimal, so we will have some extra power to account for additional functionality added to the camera system. <br />

16 AWG wire is required to comply with ASTM B258-18. Since the maximum amperage for 16 gauge wire is 3.7 A and the maximum amperage for our system is 3 A, the design is in compliance. <br />




## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|     DC 5 V 20 A 100 W Power Supply    |    B07Q2WQ8DS         |     1     |       $19.99         |     $19.99      |
|     Gratury Junction Box, IP67 Waterproof Plastic Enclosure    |   B08281V2RL         |     2     |       $22.94       |     $45.88      |
|     16 AWG Wire   |    B07FMLVF84         |     1     |       $15.88       |     $15.88      |
|    Current Sensor Module   |   B09VL4TH23        |     2     |       $9.59       |     $19.18      |
|     2 Way Extension Cord 15 ft |   B0BCP6H3QQ         |     1     |       $39.99       |     $39.99     |
|    Raspberry Pi 5 27 W USB-C Power Supply   |    B0CSMBR63K        |     2     |       $15.88       |     $31.76      |
|Total     |             |          |                |     $172.68     |

## References

Parts List: <br/>
DC 5V 20A Power Supply 5 Volt 100W AC110/230V Transformer Converter <br/>
Amazon: https://www.amazon.com/Switching-Transformer-Converter-Security-Computer/dp/B07Q2WQ8DS/<br/>

Gratury Junction Box, IP67 Waterproof Plastic Enclosure for Electrical Project, Hinged Grey Cover, Includes Mounting Plate and Wall Bracket 220×170×110mm (8.6"×6.7"×4.3")<br/>
Amazon: https://www.amazon.com/Gratury-Stainless-Waterproof-Electrical-290×190×140mm/dp/B08281V2RL/ <br/>

16 awg Silicone Electrical Wire 2 Conductor Parallel Wire line 60ft [Black 30ft Red 30ft] 16 Gauge Soft and Flexible Hook Up Oxygen Free Strands Tinned Copper Wire <br/>
Amazon: https://www.amazon.com/Silicone-Electrical-Conductor-Parallel-Flexible/dp/B07FMLVF84/ <br/>

Current Sensor Module, Relay Shield Current Protection Sensor DC 5V/12V/24V 5A Over-Current Protecting Detection Sensor Module (5V)
Amazon: https://www.amazon.com/Current-Protection-Over-Current-Protecting-Detection/dp/B09VL4TH23?th=1
<br/>

2 Way Extension Cord with On/Off Switch 3 Prong Outdoor Extension Cord Splitter, Heavy Duty Extension Cord with SJTW 14AWG 15A/125V and 18AWG 10A/125V(15 Ft, Black)
Amazon: https://www.amazon.com/Extension-Switch-Prong-Outdoor-Splitter/dp/B0BCP6H3QQ/ref=asc_df_B0B5DNT557/
<br/>

Official 27W USB Type-C Power Supply for Raspberry Pi 5 @XYGStudy (New Raspberry Pi 5 Official 27W PSU White US)
Amazon: https://www.amazon.com/Official-Type-C-Supply-Raspberry-XYGStudy/dp/B0CSMBR63K
<br/>
