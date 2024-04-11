# Power System for Camera System
## Functionality
The primary functionality for this system is to provide the required current and power for the camera subsystem.

## Constraints
| No.| Contraint | Origin |
| -- | --------- |--------|
|  1 |    The system shall be designed to minimize future maintenance.       |    Shall Statements    |              
|  2 |           |        |                          
|  3 |           |        |              

<sup>1</sup> Reason for contraint 1 and why it is important:<br />
Reducing maintenace is important to reduce the extra work for the function of the drone tracker system after the project is finished. For example, it is less likely for the system to be useful if a worker must constantly change the batteries.

<sup>2</sup> Reason for contraint 2 and why it is important

<sup>3</sup> Reason for contraint 3 and why it is important

## Schematic

## Analysis
| Component| Voltage (V) | Current (A)| Power (W)  |
| -------- | ------------| -------- |----------------|------------|
|    DS3218 Digital Servo|     5   |     0.005 - 2     |   0.024 - 13.6 |           
|   DS3225MG       |      5       |      0.005 - 2      |     0.024 - 13.6      |            
|    ATMega 2560      |     5        |      0.005 - 0.8      |   0.0135 - 4.4   |         
|     RunCam Phoenix 2 SE     |     5        |    0.2 - 0.08        |     1           |            
|   Arduino ESP8266    |     2.7 - 3.6        |     0.1     |   0.27 - 1.152    |            
|Total     |             |          |                |       1.3315 - 33.712     |




## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|          |             |          |                |            |
|          |             |          |                |            |
|          |             |          |                |            |
|          |             |          |                |            |
|          |             |          |                |            |
|Total     |             |          |                |            |

## References
5V Power Supply,PHEVOS AC110V to DC 5v 8A Universal Switching Power Supply for Raspberry PI Models,CCTV, Radio, Computer Project,WS2812B WS2811 WS2801 APA102 LED Strips Pixel Lights (5V8A):
Amazon: https://www.amazon.com/PHEVOS-Universal-Switching-Raspberry-Computer/dp/B07H5Q2PC2/ref=sr_1_11?dib=eyJ2IjoiMSJ9.70LwnEcC0D0htV7cwQ9AWl5z-6OhbA0f-ColGNtdxkd12N-eH17T2PaAk1yir11oNopfJFgPHl30Ih6wGobQHhJAbVdzOO3YU6csbCYStwwmxnihaO3NSxQGVfR38WV6ZKQN_bHfs7MeGwsOoIEFdnW6uUlHBC0kDQ5daE78FsK74SpAtQRgJ1iZhkvDYRsCu2eGAhqU9236Ao4GSOE3UA3t6iOVuj7K9OtuihkzYRs.cBZc33WqIKcGBduiEZnmNwlv6zOLtepdfgMpFvsSTM4&dib_tag=se&hvadid=557204579411&hvdev=c&hvlocphy=9013088&hvnetw=g&hvqmt=e&hvrand=6230799001586224967&hvtargid=kwd-389592846651&hydadcr=18889_13353593&keywords=5v%2B40w%2Bpower%2Bsupply&qid=1712809380&sr=8-11&th=1<br/>

RunCam Phoenix 2 SE V2: 
https://shop.runcam.com/runcam-phoenix-2-special-edition/<br/>

ELEGOO MEGA 2560 R3: 
https://m.media-amazon.com/images/I/91RAy+evkrL.pdf<br/>

DS3218 Waterproof Digital Servo: 
Amazon: https://www.amazon.com/dp/B07DHP2922?ref=emc_s_m_5_i_atc<br/>
Datasheet: https://images-na.ssl-images-amazon.com/images/I/81Lbgu+nG6L.pdf<br/>

DSSERVO DS3225MG 25KG Waterproof Metal Gear Digital Servo:
Amazon: https://www.amazon.com/DSSERVO-DS3225MG-Waterproof-Digital-Airplane/dp/B09SB8RMTT<br/>

HiLetgo ESP8266 NodeMCU CP2102 ESP-12E Development Board:
Amazon: https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B081CSJV2V/ref=sr_1_3?crid=22ZVTYZHJWASM&dib=eyJ2IjoiMSJ9.4xEr54v6vHUSws_RbogXUUQ0-qx0V7rAto5k-V99Mo3RCPWzfQoVDiMcgDrzHihKK3V39gLgH2gFeuij4f5anATMMh-R-mbHJHoAwtKgPiN7lrMi08rP29ln6B7Tz3a6Xe_Y4RwWp8b9oH3djqkfADgLv5HqSUZAFR9dRuPA7NWJDOxGZbnC-oxzJo0Yghs3qSQeRCbMzSwpoQVkGXoEj_a_R0TSWWdWQC7Ni-JtxNc.03igTz_umhPWpGiKHPjRKEVDTfFWYcY9-gAyTDQZwXk&dib_tag=se&keywords=ESP8266&qid=1712801491&sprefix=esp8266%2Caps%2C169&sr=8-3&th=1<br/>
<!-- This is how to do footnotes for the references: --> 
Here is a simple footnote[^1].
[^1]: Reference 1
[^2]: Reference 2 
[^3]: Reference 3
<!--etc.-->
