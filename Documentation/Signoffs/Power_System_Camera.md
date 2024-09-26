# Power System for Camera System
## Functionality
The primary functionality for the camera power system is to reliably meet the power requirements for the camera hardware system's components. The system will supply 5 V to the camera system's Raspberry Pi 5 via a USB-C connection and 5 V to the Raspberry Pi HQ camera. The system will supply 5 V to both servo motors +5V DC and GND terminals.

## Constraints
| No.| Contraint | Origin |
| -- | --------- |--------|
|  1 | The system shall comply with NFPA 70 [1]. | Standards and Safety |
|  2 | The system shall be weather resitant to an IP67 rating [2].  | Standards and Safety |
|  3 | The system shall be able to supply 15 W to the Raspberry Pi, 9 W to each servo motor, and 1.5 W to the camera for the system to acheive full functionality | Design Team | 
|  4 | The system shall not be impacted by back EMF from the servo motors | Design Team | 
|  5 | The system shall contain a manual switch to individually cut off power supplied | Standards and Safety | 
|  6 | The system shall contain shock and overcurrent protections. | Standards and Safety | 

Table 1 : Constraints <br />

      
<sup>1</sup> NFPA 70 is a standard for ensuring safe electrical installtion. Chaper two of the code is most pertinent for this system for its inclusion of overcurrent protection; however, it is important to comply with all standards to ensure safety. Chapter two includes maximum current through a conductor ratings. It is important to adhere to this standard to ensure the system is safe and avoid overheating, short circuits, and fires. This is applicable due to the usage of 18 AWG copper wire.  <br />

<sup>2</sup> The system will be located outdoors, so it is essential that the electrical components will be protected from environemental weather hazards and damage. The IP67 rating protects the system from cover rain, snow, dust, wind, and UV. Using this NEMA box will improve the longevity and prevent damage of the system. <br />

<sup>3</sup> This constraint is most important for system functionality, because the power system must supply the rated power for the camera system to acheive full functionality without running into any under voltage scenarios that could impact system peformance. Refer to Table 2 for the full list of power requirements of the system.  <br />

<sup>4</sup> This constraint ensures that the power supply will not be damaged by an induced back EMF from the servo motors. 
<br />

<sup>5</sup> This constraint ensures safety of the system by providing a "kill switch" to immediately remove the power supplied to both power supplies in an emergency scenario.
<br />

<sup>6</sup> This constraint ensures the safety of the system's user and the location's property. Especially with the usage of wall power, safety measures must be taken to prevent hazards like shocks and fires. For shock protection, the system will need to be properly grounded and insulated for the user's safety from electric shock. For overcurrent proection, the system will include a fuse to prevent overheating and fires due to excessive current flow. 
<br />


## Schematic

<img width="866" alt="Screenshot 2024-09-26 at 3 02 30 PM" src="https://github.com/user-attachments/assets/e6252a6d-f2b8-4f60-a18c-c11e41bf7dba">

<br />
Figure 1: Camera Power Buildable Schematic.<br />
The above schematic shows the component connections for the system. We will be utilizing a wall outlet for this design then using a 15 ft two way extensions cord with switching functionality. One side of the extension powers the Raspberry Pi 5 V 15 W USB-C power supply while the other powers the DC 5 V 10 A 50 W power supply. The Raspberry Pi 5 V 15 W USB-C power supply provides power to the Raspberry Pi 4B then a CSI ribbon cable is used to provide power at 5 V from the Raspberry Pi 4B to the Raspberry Pi HQ camera. To prevent damage from back EMF produced by the servo motors, a 1N5400 diode is placed across the terminals of both motors. A 1 A 250 V Time Delay fuse is also included to provide overcurrent protection to the 50 W power supply.
<br />



## Analysis
For this system, five volts is required for all components, so the five volt power supplies will be able to provide power to all the components. The worst case power draw from the system is 34.5 W, so the chosen 50 W power supply will meet the motor requirements with plenty of wattage to spare. The cost reduction from a lower wattage power supply is minimal, so we will have some extra power to account for any additional functionality or errors in the camera system. The Raspberry Pi 5 V 15 W power supply will provide power to the Raspberry Pi 4B. This is the power supply designed by Raspbery Pi for the Raspberry Pi 4B, so it perfectly matches the power requirements of 15 W. <br /> 

| Component | Voltage (V)| Min Current (A)| Max Current (A)| Min Power (W)| Max Power (W)|
| --------- | ---------------| -------------- |----------------| -------------- | ------------ |
| Raspberry Pi 4B, 8 GB Memory| 5 | 2.5| 3.0| 12.5| 15.0|
| DS3218 Digital Servo| 5 | 0.004| 1.8 | 0.02| 9 |
| DS3218mg Digital Servo | 5 | 0.004| 1.8 | 0.02| 9 |
| Raspberry Pi HQ camera| 5 | 0.3| 0.3| 1.5| 1.5|
| Total     |                |   2.81 A         |  6.9 A         |  14.04 W        |  34.5 W     |

Table 2: Power Requirements.<br />


## MEAN WELL LRS-50-5 50W 5VDC 10A Single Ouput Switching Mode Power Supply
The maximum power requirements for the motors is 18 W at 5 V, so the 50 W power supply will easily cover that. At first glance, it may seem like overkill, but this power supply is very useful for meeting this subsystems's requirements. The power supply will be capable of powering both servo motors from the single output terminal. It also includes safety features such as short circuit, overload, and over voltage protections, and is safety compliant with IEC 60335-1 [3] and IEC 61558-1 [4]. This power supply also includes a robust datasheet and a useful user manual. An issue with design choice to use power supplies, is that it limits the design team's possible locations to house the Camera system. However, having more location flexibility with an alternate design such as a solar charged battery would be very expensive with the maximum power for the system nearing 40 W. The design team decided that the cost-benefit analysis would not be worth it to implement a solar solution for this subsystem. The power supply will also have overcurrent protection from a slow-burn 1 A 250 V fuse. We will also utilize a grounded power cord to provide shock protection. 
<br />

##  Gratury Junction Box, IP67 Waterproof Plastic Enclosure
The Gratury Junction Box, IP67 Waterproof Plastic Enclosure will provide protection to the system from the elements. This NEMA box is rated at IP67 which protects the system from rain, snow, dust, wind, and UV. The design team chose this option to ensure the safety of the many sensitive electrical components from a variety of weather conditions. This NEMA box is also similarly priced to competiors, but this product was the closest sized options for our need at the lowest price.
<br />

##   18 AWG Wire
18 AWG wire is required to comply with NFPA 70 [1], The standard for the safety, code compliance, and industry standerdization of electrical installation.  Since the maximum amperage for 18 gauge wire is 7 A and the maximum amperage for our system is 3 A, so the design is easily in compliance with the standard. It is also important to note that continous loads must not exceed 5.6 A. As previously stated, the 3 A maxiumum amperage will not exceed this standard. With the amount of wire purchased and the high rating, this wire can also for other subsystems in the project if needed, such as the receiver power system. <br />

##  Ces 1N5400 3 Amp Diode D3A
The design team is using a 1N5400 diode to protect the 50W 5VDC 10A Power Supply from a possible induced back EMF that could cause permanent damage to the power supply, which would need to be repaired or replaced for the motors to regain functionality. The diode's forward voltage is 1.2 V and maximum peak reverse voltage is 50 V with a forward current surge rating of 3 A. This diode is inexpensive and is rated well above the 1.8 A stall current listed by the DS3218 datasheet.
<br />

##   2 Way Extension Cord 15 ft
The 2 Way Extension Cord 15 ft allows the design team to power both the 50W 5VDC 10A Power Supply and the Raspberry Pi 15 W USB-C Power Supply from a single outlet. This is convenient, because it allows team to use minimal electrical equipment that may be needed by Tennessee Tech University Facilities. The extension cord is rated at a minimum of 10 A, so we will not face any safety or functionality issues due to overcurrent. This extension cord also has manual switches for both ways that can individually cut the supply of power to either or both power supplies, which is a good feature for safety and testing. The extension cord also provides a small amount more flexibility in location for the Camera system. 
<br />

##  Raspberry Pi 15 W USB-C Power Supply
The Raspberry Pi 15 W USB-C Power Supply is the power supply designed by Raspbery Pi for the Raspberry Pi 4 series. Since, it is designed for the component used it meets all the power requirements perfectly. The design team chose this option over cheaper power supplies for the reliability of this power supply. It also includes short circuit, overcurrent, and over temperature protections. As specified by the datasheet, these protections protect the system by limiting the current or shutting down if the current exceeds the ratings of 5 V, 3 A, and 15 W.
<br />

##  Raspberry Pi 5 27 W USB-C Power Supply
This component is an exception for this system. It is the power supply required for the database system's Raspberry Pi 5 as specified in their design documentation. As opposed to creating a new request, it will be included in this section and the bill of materials for the Camera Power system. It is the power supply designed by Raspberry Pi for their Raspberry Pi 5, so with access to a working wall outlet the power supply will sufficiently provide 27 Watts at 5V via a USB-C connection. For further justification, refer to the Database system documentation.
<br />

## Bussmann MDL-1 Glass Fuse 1 Amp 250 Volt Time Delay
This component will provide overcurrent protection to the MEAN WELL LRS-50-5 power supply. It will be connected to the AC L "hot wire" via a in-line fuse holder. The 1 A current rating will account for safety and efficieny margins of the power supply ensuring the fuse will not be blown in regular operation due to the roughly 0.6 A current. The usage of a time delay fuse will not allow inrush current to blow the fuse. This fuse will be housed in the Seachoice Waterproof in-Line Fuse Holder.


## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|     MEAN WELL LRS-50-5 50W 5VDC 10A Single Ouput Switching Mode Power Supply  |    B085QKVLB6         |     1     |       $15.08         |     $15.08      |
|     Gratury Junction Box, IP67 Waterproof Plastic Enclosure    |   B08281V2RL         |     1     |       $22.94       |     $22.94      |
|     16 AWG Wire   |    DGHY-GJX-BOX1        |     1     |       $14.99       |     $14.99      |
|    Ces 1N5400 3 Amp Diode D3A 10 Pack   |   1N5400        |     1     |       $3.95       |     $3.95      |
|     2 Way Extension Cord 15 ft |   B0BCP6H3QQ         |     1     |       $39.99       |     $39.99     |
|    Raspberry Pi 5 27 W USB-C Power Supply   |    B0CSMBR63K        |     1     |       $15.88       |     $15.88      |
|    Raspberry Pi 15 W USB-C Power Supply   |    B0CSMBR63K        |     1     |       $7.99      |     $7.99      |
|    Bussmann Time Delay Glass Fuse 5 Pack |    B00SU2I7YG       |     1     |       $10.59     |     $10.59     |
|   Seachoice in-Line Fuse Holder    |     B000N9PI32      |     1     |       $11.13      |     $11.13      |
|Total     |             |          |                |     $142.54     |

Table 3: Bill of Materials <br />

## References
[1] “NFPA 70 National Electric Code,” NFPA, https://www.nfpa.org/codes-and-standards/nfpa-70-standard-development/70 <br/>
[2] “NEMA Enclosure Types,” NEMA, https://www.nema.org/. <br/>
[3] "IEC 60335-1", IEC, https://webstore.iec.ch/en/publication/61880 <br/>
[4] "IEC 61558-1", IEC, https://webstore.iec.ch/en/publication/26261 <br/>

## Parts List: <br/>
MEAN WELL LRS-50-5 50W 5VDC 10A Single Ouput Switching Mode Power Supply  <br/>
Amazon: https://www.amazon.com/MEAN-WELL-LRS-50-5-Single-Switching/dp/B085QKVLB6
Datasheet: https://www.meanwell.com/Upload/PDF/LRS-50/LRS-50-SPEC.PDF

Gratury Junction Box, IP67 Waterproof Plastic Enclosure for Electrical Project, Hinged Grey Cover, Includes Mounting Plate and Wall Bracket 220×170×110mm (8.6"×6.7"×4.3")<br/>
Amazon: https://www.amazon.com/Gratury-Stainless-Waterproof-Electrical-290×190×140mm/dp/B08281V2RL/ <br/>

18 AWG Stranded Electrical Wire 18 Gauge Tinned Copper Wires <br/>
Amazon: https://www.amazon.com/Stranded-Electrical-Flexible-Silicone-Electric/dp/B09TK83NVP?source=ps-sl-shoppingads-lpcontext&ref_=fplfs&smid=A389NMY3J97V8S&th=1 <br/>

2 Way Extension Cord with On/Off Switch 3 Prong Outdoor Extension Cord Splitter, Heavy Duty Extension Cord with SJTW 14AWG 15A/125V and 18AWG 10A/125V(15 Ft, Black)
Amazon: https://www.amazon.com/Extension-Switch-Prong-Outdoor-Splitter/dp/B0BCP6H3QQ/ref=asc_df_B0B5DNT557/
<br/>

Official 27W USB Type-C Power Supply for Raspberry Pi 5 @XYGStudy (New Raspberry Pi 5 Official 27W PSU White US)
Amazon: https://www.amazon.com/Official-Type-C-Supply-Raspberry-XYGStudy/dp/B0CSMBR63K
<br/>

Raspberry Pi 15W USB-C Power Supply US - White
Amazon: https://www.amazon.com/Raspberry-Power-Supply-USB-C-Listed/dp/B07Z8P61DQ
<br/>

Ces 1N5400 3 Amp Diode D3A 10 Pack
Amazon: https://www.amazon.com/AMP-DIODE-D3A-10-PACK/dp/B0071DZVDU
Datasheet: https://media.digikey.com/pdf/Data%20Sheets/Diodes%20PDFs/RL201-207.pdf](https://www.vishay.com/docs/88516/1n5400.pdf
<br/>

Bussmann MDL-1 Glass Fuse 1 Amp 250 Volt Time Delay (Slo-blo) 3AG Set of 5
Amazon: https://www.amazon.com/Bussmann-MDL-1-Glass-Delay-Slo-blo/dp/B00SU2I7YG
<br/>

Seachoice in-Line Fuse Holder, Waterproof
Amazon: https://www.amazon.com/SEACHOICE-12731-Inline-Fuse-Holder/dp/B000N9PI32
<br/>
