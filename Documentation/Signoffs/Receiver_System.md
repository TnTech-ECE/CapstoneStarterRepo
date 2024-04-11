# Receiver System 
## Functionality
The Receiver system will be responsible for receiving and unpacking Remote ID (RID) data to be sent by the network to the database. This sub-system shall be composed of a singular antenna along with a microprocessor and storage drive that will decode, package, and transmit/store the received data to the networked database to be used by the remainder of the system.
## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | Shall only need to receive information within the frequency bands of 2.4 GHz | Design Constraint|
|  2 | Shall only utilize RID signal and ignore other signals | Ethical Constraint       |                          
|  3 | Shall receive data all data from remote ID emitting drones    |  Design constraint |   
|  4 | Shall track drones on the contiguous TTU campus | TTU Police |
|  5 | Shall give location of control station if the drone is over the contiguous campus, but the control station is not| TTU Police |
|  6 | Shall cover approximately 0.636594 km<sup>2</sup> | TTU Police|


<sup>1</sup> According to research done on drone tracking and radio frequency emission, there are three different drone detection cases. In each case, the frequency band used was either between 2.4 Ghz or 5.8 Ghz ISM bands. The 5.8 GHz can be ommitted due to it being an optional transmission and the drone must emit a 2.4 GHz WiFi signal. [^6].   

<sup>2</sup> If the receiver reads data that is not the RID signal, it could be considered a privacy concern. 

<sup>3</sup> If the drone is not emitting the RID signal, the receiver will not be able to pick it up.

<sup>4</sup> Due to a higher density of students on the contiguous campus we have been asked to keep our scope smaller. This will also be easier for maintenance purposes.

<sup>5</sup> The campus police are only concerned about drones flying on the contiguous Tech campus. The RID signal tranmits the location of the drone and control station, so if an RID emitting drone is illegally flying on campus then the TTU police will be able to locate the control station as well. 

<sup>6</sup> The contiguous campus is approximately 0.636594 km<sup>2</sup> in area and the receivers must be able to cover this area. 

## Schematic
![image](https://ibb.co/RNs7thm)





## Analysis
### Receivers
The  receivers are designed to receive the RID drone signal and send the data to the database subsystem. The Arduino Nano ESP32 has a built in module used to receive and send Bluetooth and WiFi signals on the 2.4 GHz band. These secondary receivers will be placed around the contiguous campus for maximum reception coverage. The receivers will be placed outside to minimize power loss that can be caused by building and maximize the range that the receivers will be able to receive a signal. A resin 3D print will be created and spray prainted white and a protective spray that will help protect it from UV and water damage. This print will have a small opening for the power subsystem to get wires to power the arduino and the USB-C connector. The Arduino Nano ESP32 utilizes a NORA-W106 to receive Bluetooth and WiFi signals. The module has a receiver sensitivity of -98 dBm for and receiver gain of 3 dBi for Bluetooth. It also has a -97 dBm receiver sensitivity for Wifi and gain of 3 dBi. 
P<sub>Rx</sub> = P<sub>Tx</sub> + G<sub>Tx</sub> - L<sub>Tx</sub> - L<sub>fs</sub> + G<sub>Rx</sub> - L<sub>Rx</sub>
The receivers will utilizes a Gravity: Nano I/O Shield (shield)to connect a Adafruit ATWINC1500 WIFI Breakout (WiFi module) WiFi module to conect the Arduino to the Tennessee Tech WiFi, EagleNet. The shield is an attachment so that the Arduino can connect to EagleNet using the WiFi module. The purpose of the WiFi module is to send the data received from the RID signal to the database over WiFi. This will allow the receivers to constantly receive the data and have a connection to the database subsystem to send the signal as quickly as possible. 
## BOM
#### All prices listed are in USD
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|Arduino Nano ESP32 [^7]        |ABX00083             |9        |$20.00           |$180            |
|ESP8266 [^10]         | WRL-17146            |9         |$7.95                |$71.55            |

|Total     |             |   18       |                |   $251.55         |


## References and Links
[^1]: "Standard specification for remote ID and tracking designation - F3411 - 19," ASTM International, (2019).

[^2]: J. Marcel, “3 key factors that determine the range of bluetooth,” Bluetooth® Technology Website, https://www.bluetooth.com/blog/3-key-factors-that-determinethe-range-of-bluetooth/ (accessed Apr. 3, 2024). 

[^4]: S. Cerwin, Radio Propagation and Antennas: A Non-Mathematical Treatment of Radio and Antennas. Bloomington, IN: AuthorHouse, 2019. 

[^6]: D. Aouladhadj et al., “Drone detection and tracking using RF Identification Signals,” National Center for Biotechnology Information, https://www.ncbi.nlm.nih.gov/pmc/articles/PMC10490811/ (accessed Apr. 3, 2024). 

[^7]: “Arduino® Nano ESP32,” Arduino Online Shop, https://store-usa.arduino.cc/products/nano-esp32?selectedStore=us (accessed Apr. 5, 2024).

[^8]: ABX00083-datasheet.pdf, https://docs.arduino.cc/resources/datasheets/ABX00083-datasheet.pdf (accessed Apr. 5, 2024). 

[^9]: “Calculate area on map, Google Maps Area Calculator,” CalcMaps, https://www.calcmaps.com/map-area/ (accessed Apr. 5, 2024). 

[^10]: “WIFI module - ESP8266 (4MB Flash),” WRL-17146 - SparkFun Electronics, https://www.sparkfun.com/products/17146 (accessed Apr. 10, 2024). 
