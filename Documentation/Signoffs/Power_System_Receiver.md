# Power System for Receiver System
## Functionality
The functionality for the receiver power system is to reliably meet the power requirements for the receiver system's components. The system will supply 5 V to the receiver system's Arduino Nano ESP32 and 3.3 V to the ESP 8266 WiFi module. This will be done using the Waveshare Solar Power Management Module. This module will provide power to the Receiver system's Arduino Nano ESP32 and ESP8266 WiFi module via a USB-C connection and the 3.3 V output respectively. The Waveshare module will contain a lithium-ion battery that is recharged using solar energy. Since this system will be located outdoors, the components of this system, excluding the solar panel, will be protected by a NEMA box.

## Constraints



| No.| Contraint | Origin |
| -- | --------- |--------|
|  1 | The system shall be able to supply enough power to the receiver system for its full functionality   |  Design Team    |
|  2 | The system shall comply with ASTM B258-18 [2]. | Standards and Safety |
|  3 | The system shall be weather resitant to an IP67 rating [1].  | Standards and Safety |
|  4 | The system shall be designed to minimize future maintenance. | Broader Implications  |
       

<sup>1</sup> This constraint is essential, because the power system must supply adequate power for the receiver system to achieve full functionality. Without the data acquired by the receiver system, the other subsystems would not have the information required for operation. This makes it very important to avoid any disruptions due to insufficient power.  <br />

<sup>2</sup> ASTM B258-18 is a standard for the proper wire gauge for electrical conductors. It is important to adhere to this standard to ensure the system is safe by avoiding overheating, short circuits, and fires due to improper wire gauges.  <br />

<sup>3</sup> The system will be located outdoors, so it is essential that the electrical components will be protected from environemental weather hazards and damage. The IP67 rating protect the system from cover rain, snow, dust, wind, and UV. This will be acheived by using a NEMA box to house the system's components. <br />

<sup>4</sup> Reducing maintenace is important to reduce the workload for the continuing function of the drone tracker system after the project is completed. For example,the system will be less useful if a worker must constantly change the discharged batteries, so solar generation will be used to recharge batteries that will last for at least two years. <br />



## Schematic

![Screenshot 2024-09-15 at 10 01 20 PM](https://github.com/user-attachments/assets/9f17ad2f-213b-4fd7-9dec-69144ef72f60)<br />
Figure 1: Electrical Schematic<br />
The above schematic details the connections and voltages for the system. The solar panel (A) is connected to the Waveshare module (B) Solar In postive and negative terminals at 12 V. This allows the solar panel to recharge the 14500 2500 mAH 3.7 V lithium-ion battery (C) connected to the Waveshare module. The battery is also chargeable using a Micro-USB input, which will be useful for testing purposes. The Waveshare module will power the Arduino Nano ESP32 (D) through the USB out port via a USB-A to USB-C 5 V connection. The module will also power the ESP8266 WiFi module (E) through the 3.3 V output terminals. For this schematic, the full pinout is not detailed for the Arduino Nano ESP32 and the ESP8266 WiFi module. The excluded details are not vital to the functionality of this subsystem; for those details refer to the receiver system documentation or the datasheets provided in the refernces section. <br />

<img width="984" alt="Screenshot 2024-04-10 at 9 43 25 PM" src="https://github.com/mrnye42/Drone-Tracker-Project/assets/158224821/e893c923-8836-458a-af27-fb9d5f76ec00"> <br />
Figure 2: Waveshare Power Management Module Schematic<br />
The above figure details the electronics and circuitry found in the Waveshare Power Management Module. The functionality of the Waveshare module is essential to this subsystems design. The various safety features such as over charge and over discharge will also ensure that the design meets safety requirements and improves the longevity of the system and its components. <br />


## Analysis

## Power Requirements
| Component | Min Voltage (V)| Max Voltage (V)| Min Current (A)| Nax Current (A)| Min Power (W)| Max Power (W)|
| --------- | ---------------| -------------- |----------------| -------------- | ------------ | ------------ |
| Arduino Nano ESP32 | 4.8| 5.5 | 0.003 | 0.25 | 0.0144 | 1.375 |
| ESP8266 WiFi Module | 3.3 | 3.3 | 0.015 | 0.215 | 0.0495 | 0.7095 |
| Total     |                |                |  0.018 A         |  0.465 A         |  0.0639 W        |  2.0845 W     |  <br />

## Arduino Nano ESP32
The Arduino® Nano ESP32 can be powered with 5 V through a USB-C connector or an input voltage of 6-21 volts through the VIN pin. For this design, the team will be using the 5 V USB-C port, because this gives the microcontroller additional functionality that may be utilized in the receiver system's design by allowing the usage of the VBUS 5 V output. This will also allow the output terminals to be free power the ESP8266 WiFi module if required. Since the ESP32's output voltage is 3.3 V, it can also be used to power the ESP8266. The best design decision in this case will likely be determined during the testing period, and having two different options for connection is beneficial for design flexibility. The decision to use this component was decided by the receiver system design team.  <br />
## ESP8266 WiFi Module
The ESP8266 can be powered through VIN pin at 3.3 V. This component allows the receiver system to connect to WiFi and communicate with the database system. The decision to use this component was decided by the receiver system design team.<br />
## Waveshare Solar Power Management Module
<br />
## ACOPOWER 5 W 12 V Solar Panel
To reduce maintenace, the team will be utlizing solar panels to recharge the 3.7 V lithium-ion battery in the Waveshare Solar Power Management Module.
<br />
## Joinfworld 6x6x4 Outdoor Electrical Box
<br />
## CONMDEX USB A to USB C Cable
<br />
## Official 27W USB Type-C Power Supply for Raspberry Pi 5
<br />






## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
| Waveshare Solar Power Management Module|       B07PBRK8KG      |   9     |  $13.99              |     125.91       |
| 5W-Solar-Battery-Trickle-Charger-Maintainer 12V-Solar-Panel   |     B01M0UEP4W        |    9      |      $18.90          |      $170.10      |
| USB A to USB C 2 Pack  |    ‎B09R7NPWQR       |     5     |        $10.00        |      $50.00     |
| 14500 Rechargeable Battery 2500mAh 3.7Volt Li-ion Batteries Button Top 4 Pack | ‎B0CW1T99D1  | 3 | $15.99 | 47.97 |
| Joinfworld 6x6x4 Outdoor Electrical Box Weatherproof Junction Box | ‎ BG595935T | 9 | $19.99 | 179.91 |
| Official 27W USB Type-C Power Supply for Raspberry Pi 5 | B0CSMBR63K  | 1 | $20.49 | 20.49 |
|Total     |             |          |                |      $594.38   |

## References
[1] “NEMA Enclosure Types,” NEMA, https://www.nema.org/. <br />
[2] “Standard specification for standard nominal diameters and cross-sectional areas of AWG sizes of solid round wires used as electrical conductors,” ASTM International, https://www.astm.org/b0258-18.html. <br />
[3] "Climate and Average Weather Year Round in Cookeville," Weather Spark, https://weatherspark.com/y/15151/Average-Weather-in-Cookeville-Tennessee-United-States-Year-Round#:~:text=The%20length%20of%20the%20day,hours%2C%2037%20minutes%20of%20daylight. <br />
[4] "Design and Sizing of Solar Photovoltaic Systems," CED Engineering, https://www.cedengineering.com/courses/design-and-sizing-of-solar-photovoltaic-systems. <br />




## Part List: <br />
Arduino® Nano ESP32: <br />
Datasheet: https://docs.arduino.cc/resources/datasheets/ABX00083-datasheet.pdf<br />

WiFi module - ESP8266: <br />
Datasheet: https://nurdspace.nl/images/e/e0/ESP8266_Specifications_English.pdf <br />

Waveshare Solar Power Management Module: <br />
Amazon: https://www.amazon.com/Waveshare-Management-Protection-Low-Power-Environmental/dp/B094FWZVFH<br />
Datasheet: https://www.waveshare.com/wiki/Solar_Power_Manager <br />

CONMDEX Android Auto USB C Cable 10Gbps [2ft, 2-Pack] USB 3.1 Gen 2 USB A to USB C Cable, Short 3A Type C Charger Fast Charging Data Transfer Cord for iPhone 15 Plus 15 Pro Samsung Galaxy S23, Black<br />
Amazon: https://www.amazon.com/Upgrade-CONMDEX-Android-Charging-Samsung/dp/B09R7NPWQR/ <br />

14500 Rechargeable Battery 2500mAh 3.7Volt Li-ion Batteries Button Top 4 Pack<br />
Amazon: https://www.amazon.com/Rechargeable-Battery-Batteries-Headlamp-Flashlight/dp/B0CW1T99D1/
<br />

5W-Solar-Battery-Trickle-Charger-Maintainer 12V-Solar-Panel -Charger Waterproof Built-in Blocking Diode Small Solar Panels.<br />
Amazon: https://www.amazon.com/ACOPOWER-Solar-Panel-Battery-Charging/dp/B01M0UEP4W <br /> 

Joinfworld 6x6x4 Outdoor Electrical Box Weatherproof Junction Box.<br />
Amazon: https://www.amazon.com/Joinfworld-Clear-Cover-Electrical-Boxes/dp/B0CHHJ49QN?th=1 <br />

Official 27W USB Type-C Power Supply for Raspberry Pi 5. <br />
Amazon: https://www.amazon.com/Official-Type-C-Supply-Raspberry-XYGStudy/dp/B0CSMBR63K <br /> 



