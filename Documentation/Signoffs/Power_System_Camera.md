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

Table 1 : Constraints <br />

      
<sup>1</sup> ASTM B258-18 is a standard for the proper wire gauge for electrical conductors. It is important to adhere to this standard to ensure the system is safe and avoid overheating, short circuits, and fires.  <br />

<sup>2</sup> The system will be located outdoors, so it is essential that the electrical components will be protected from environemental weather hazards and damage. The IP67 rating protects the system from cover rain, snow, dust, wind, and UV. Using this NEMA box will improve the longevity and prevent damage of the system. <br />

<sup>3</sup> This constraint is most important for system functionality, because the power system must supply the rated power for the camera system to acheive full functionality without running into any under voltage scenarios that could impact system peformance. <br />

<sup>4</sup> This constraint ensures that the power supply will not be damaged by an induced back EMF from the servo motors. 
<br />

<sup>5</sup> This constraint ensures safety of the system by providing a "kill switch" to immediately remove the power supplied to both power supplies in an emergency scenario.
<br />

## Schematic

![Screenshot 2024-09-17 at 12 37 04 AM](https://github.com/user-attachments/assets/5a6c6241-79d9-4dab-8101-452bd22ecdc4)
<br />
Figure 1: Camera Power Buildable Schematic.<br />
The above schematic shows the component connections for the system. We will be utilizing a wall outlet for this design then using a 15 ft two way extensions cord with switching functionality. One side of the extension powers the Raspberry Pi 5 V 15 W USB-C power supply while the other powers the DC 5 V 20 A 100 W power supply. The Raspberry Pi 5 V 15 W USB-C power supply provides power to the Raspberry Pi 4B then a CSI ribbon cable is used to provide power at 5 V from the Raspberry Pi 4B to the Raspberry Pi HQ camera. The DC 5 V 20 A 100 W power supply's outputs go through two current sensor modules to prevent damage to the supply from back EMF. From the modules, 5 V are supplied to both motors.
<br />
![Electrical_Overview](https://github.com/user-attachments/assets/0ce5b3c5-ff64-4a7f-b42c-370840f1fc91)
<br />
Figure 2: Electrical Overview.
The above figure shows the simplified electrical module, providing 5 V to all components, and motor connections as detailed in the Camera Hardware system documentation. 




## Analysis
| Component | Min Voltage (V)| Max Voltage (V)| Min Current (A)| Max Current (A)| Min Power (W)| Max Power (W)|
| --------- | ---------------| -------------- |----------------| -------------- | ------------ | ------------ |
| Raspberry Pi 4B, 8 GB Memory| 5| 5| 2.5| 3.0| 12.5| 15.0|
| Digital Servo, 20 kg torque, 180 degrees Control Angle| 5| 6.8| 0.004| 2.2| 0.02| 14.96|
| Digital Servo, 20 kg torque, 270 degrees Control Angle| 5| 6.8| 0.004| 2.2| 0.02| 14.96|
| Raspberry Pi HQ camera| 5| 5| 0.3| 0.3| 1.5| 1.5|
| Total     |                |                |  2.81 A         |  7.1 A         |  14.04 W        |  46.42 W     |

Table 2: Power Requirements.<br />

For this system, five volts is required for all components, so the five volt power supplies will be able to provide power to all the components. The worst case power draw from the system is 45.67 W, so the chosen 100 W power supplies will meet those for the motors with plenty of wattage to spare. The cost reduction from a lower wattage power supply is minimal, so we will have some extra power to account for any additional functionality or errors in the camera system. This power supply also gives two outputs at 5 V, which was not common at this price point.  The Raspberry Pi 5 V 15 W power supply will provide power to the Raspberry Pi 4B. This is the power supply designed by Raspbery Pi for the Raspberry Pi 4B, so it perfectly matches the power requirements. <br /> 

##  DC 5 V 20 A 100 W Power Supply
The maximum power requirements for the motors is 29.92 W, so the 100 W power supply will easily cover that. At first glance, it may seem like overkill, but this power supply is very useful for meeting this subsystems's requirements. Power supplies with multiple 5 V output terminals are not common in the market, so this option allowed the design team to use a single power supply to provide power to both motors. Also, the price point on this power supply was very similar, if not cheaper, than other power supplies with only one 5 V output. It also includes safety features such as shortage, overload, and over voltage protections, and is safety compliant with CE, RoHS and FCC. An issue with design choice to use power supplies, is it limits the design team's possible locations to house the Camera system. However, having more location flexibility with an alternate design such as a solar charged battery would be very expensivewith the maximum power for the system nearing 50 W. The design team decided that the cost-benefit analysis would not be worth it to implement a solar solution for this subsystem.
<br />
##  Gratury Junction Box, IP67 Waterproof Plastic Enclosure
The Gratury Junction Box, IP67 Waterproof Plastic Enclosure will provide protection to the system from the elements. This NEMA box is rated at IP67 which protects the system from rain, snow, dust, wind, and UV. The design team chose this option to ensure the safety of the many sensitive electrical components from a variety of weather conditions. This NEMA box is also similarly priced to competiors, but this product was the closest sized options for our need at the lowest price.
<br />
##   16 AWG Wire
16 AWG wire is required to comply with ASTM B258-18, The standard for wire gauge size based on current through a conductor.  Since the maximum amperage for 16 gauge wire is 3.7 A and the maximum amperage for our system is 3 A, the design is in compliance with the standard. With the amount of wire purchased and the high rating, this wire can also for other subsystems in the project if needed, such as the receiver power system. <br />
##  Current Sensor Module
The design team is using a current sensor module to protect the DC 5 V 20 A 100 W Power Supply from a possible induced back EMF that could cause permanent damage to the power supply, which would need to be repaired or replaced for the motors to regain functionality. This same module is listed in many places, so the chosen option was by far the best price.
<br />
##   2 Way Extension Cord 15 ft
The 2 Way Extension Cord 15 ft allows the design team to power both the DC 5 V 20 A 100 W Power Supply and the Raspberry Pi 15 W USB-C Power Supply from a single outlet. This is convenient, because it allows team to use minimal electrical equipment that may be needed by Tennessee Tech Facilities. The extension cord is rated at a minimum of 10 A, so we will not face any safety or functionality issues due to overcurrent. This extension cord also has manual switches for both ways that can individually cut the supply of power to either or both power supplies, which is a good feature for safety and testing. The extension cord also provides a small amount more flexibility in location for the Camera system. 
<br />
##  Raspberry Pi 15 W USB-C Power Supply
The Raspberry Pi 15 W USB-C Power Supply is the power supply designed by Raspbery Pi for the Raspberry Pi 4 series. Since, it is designed for the component used it meets all the power requirements perfectly. The design team chose this option over cheaper power supplies for the reliability of this power supply. 
<br />
##  Raspberry Pi 5 27 W USB-C Power Supply
This component is an exception for this system. It is the power supply required for the database system's Raspberry Pi 5 as specified in their design documentation. As opposed to creating a new request, it will be included in this section and the bill of materials for the Camera Power system. It is the power supply designed by Raspberry Pi for their Raspberry Pi 5, so with access to a working wall outlet the power supply will sufficiently provide 27 Watts at 5V via a USB-C connection. For further justification, refer to the Database system documentation.
<br />







## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|     DC 5 V 20 A 100 W Power Supply    |    B07Q2WQ8DS         |     1     |       $19.99         |     $19.99      |
|     Gratury Junction Box, IP67 Waterproof Plastic Enclosure    |   B08281V2RL         |     2     |       $22.94       |     $45.88      |
|     16 AWG Wire   |    B07FMLVF84         |     1     |       $15.88       |     $15.88      |
|    Current Sensor Module   |   B09VL4TH23        |     2     |       $9.59       |     $19.18      |
|     2 Way Extension Cord 15 ft |   B0BCP6H3QQ         |     1     |       $39.99       |     $39.99     |
|    Raspberry Pi 5 27 W USB-C Power Supply   |    B0CSMBR63K        |     1     |       $15.88       |     $15.88      |
|    Raspberry Pi 15 W USB-C Power Supply   |    B0CSMBR63K        |     1     |       $7.99      |     $7.99      |
|Total     |             |          |                |     $164.79     |

Table 3: Bill of Materials <br />

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
Datasheet: http://www.chinalctech.com/m/view.php?aid=48
<br/>

2 Way Extension Cord with On/Off Switch 3 Prong Outdoor Extension Cord Splitter, Heavy Duty Extension Cord with SJTW 14AWG 15A/125V and 18AWG 10A/125V(15 Ft, Black)
Amazon: https://www.amazon.com/Extension-Switch-Prong-Outdoor-Splitter/dp/B0BCP6H3QQ/ref=asc_df_B0B5DNT557/
<br/>

Official 27W USB Type-C Power Supply for Raspberry Pi 5 @XYGStudy (New Raspberry Pi 5 Official 27W PSU White US)
Amazon: https://www.amazon.com/Official-Type-C-Supply-Raspberry-XYGStudy/dp/B0CSMBR63K
<br/>

Raspberry Pi 15W USB-C Power Supply US - White
Amazon: https://www.amazon.com/Raspberry-Power-Supply-USB-C-Listed/dp/B07Z8P61DQ
<br/>
