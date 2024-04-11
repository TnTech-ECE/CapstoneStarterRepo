# Power System for Camera System
## Functionality
The primary functionality for this system is to provide the required current and power for the camera subsystem.

## Constraints
| No.| Contraint | Origin |
| -- | --------- |--------|
|  1 |    The system shall be designed to minimize future maintenance.       |    Shall Statements    |              
      

<sup>1</sup> Reason for contraint 1 and why it is important:<br />
Reducing maintenace is important to reduce the extra work for the function of the drone tracker system after the project is finished. For example, it is less likely for the system to be useful if a worker must constantly change the batteries.

## Schematic
![5V-power-supply-circuit-diagram](https://github.com/mrnye42/Drone-Tracker-Project/assets/158224821/8b9796c8-cb32-4588-9f21-ac271578669a)<br/>
Figure 1: Example Circuit for 5 Volt Power Supply<br/>
<img width="435" alt="Screenshot 2024-04-10 at 11 56 02 PM" src="https://github.com/mrnye42/Drone-Tracker-Project/assets/158224821/538ddb11-8896-45e7-80e4-41b19938ef5f"> <br/>
Figure 2: 3.3 V Buck Converter Schematic




## Analysis

<img width="927" alt="Screenshot 2024-04-10 at 11 43 50 PM" src="https://github.com/mrnye42/Drone-Tracker-Project/assets/158224821/16aafaba-a298-4374-b1f2-70e1acb4ad17"> <br />
Table 1: Power Calculations

For this system, five volts is required for all components excluding the Arduino ESP8266, so the five volt power supply will be able to provide power to the najority of the components. A 3.3 output voltage buck converter will be used to step down the five volts to the required voltage range. 




## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|      5V Power Supply    |    B07H5Q2PC2         |     1     |       $14.99         |     $14.99       |
|     3.3V Output Buck Converter     |      B017C04KOM       |    1      |        $7.82        |     $7.82       |
|Total     |             |          |                |     $22.81       |

## References
Power Management IC Development Tools LM3671 3.3V Buck Converter Breakout - 3.3V Output 600mA Max (1 piece): <br/>
Amazon: https://www.amazon.com/Management-Development-LM3671-Converter-Breakout/dp/B017C04KOM<br/>
Datasheet: https://cdn-shop.adafruit.com/product-files/2745/P2745_Datasheet.pdf<br/>

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

