# Receiver System 
## Functionality
The Receiver system will be responsible for receiving and sending the packed Remote ID (RID) over the network to the database subsystem. This subsystem shall be composed of 9 antennas placed across the contiguous Tennessee Tech University (TTU) campus. The receivers will be placed outside to minimize the power loss that would occur due to the RF signals going through a building. 
## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | Shall only need to receive packets within the 2.4 GHz WiFi and Bluetooth frequency band | Design Constraint|
|  2 | Shall only interact with RID signal and ignore other signals | Ethical Constraint       |                          
|  3 | Shall receive all RID data from remote ID emitting drones    |  Design Constraint |   
|  4 | Shall have a reception range that covers the contiguous campus and cover up to 20 m off the contiguous campus | TTU Police |
|  5 | Each receiver shall have a reception range at a minimum of 152 m | Design Constraint|

<sup>1</sup> According to research done on drone tracking and radio frequency emission, there are three different drone detection cases. In each case, the frequency band used was either between 2.4 Ghz or 5.8 Ghz ISM bands. The 5.8 GHz frequency band can be ommitted due to it being an optional transmission. The drone must emit a 2.4 GHz WiFi signal if a WiFi signal is being emitted, so this is the frequency band we will choose to focus on. This is due to the 5.8 GHz not being transmitted as far, so more receivers would be required to cover the contiguous campus and, therefore, raise the cost of the project. [^6].   

<sup>2</sup> If the receiver reads data that is not the RID signal, it could be considered a privacy concern. The information from those signals are also not applicable to the purpose of this project as they will not allow the receiver to obtain the RID data of a drone. 

<sup>3</sup> If the drone is not emitting the RID signal, the receiver will not be able to pick it up.

<sup>4</sup> Due to a higher density of students on the contiguous campus we have been asked to keep our scope smaller. This will also be easier for maintenance purposes of the subsystem in the future. The receivers will not be able to determine the distance of a signal. To cover the entire TTU campus, the detection radius of the receivers will slightly extend beyond the campus boundaries. Placement of the receivers will be used to minimize how far off campus the receivers will be able to receive signals. 

<sup>5</sup> Based on the calculations and assumptions, the receivers should be able to cover a greater range. However, to ensure an appropriate fade margin of 25 dB, the receivers need to cover a range of 152 meters to account for miscellaneous losses.

## Design

### Arduino Nano ESP32
This microcontroller has been picked due to the low receiver sensitivity of the wifi module and its ability to then program it to send the signal across the wifi to the database. Python code will be used for the receiver to know what signal to find and then relay the signal to be unpacked. Using a line to line link equation the receiver has been calculated to receive a signal from 152 m.

$$ P<sub>Rx</sub> = P<sub>Tx</sub> + G<sub>Tx</sub> - L<sub>fs</sub> + G<sub>Rx</sub> $$ 

The P<sub>Rx</sub> is the power of the signal when it reaches the receiver. The strength of the signal when it reaches the receiver can be calculated by the strength of the signal from the transmitter, P<sub>Tx</sub>. The gain of the transmitter G<sub>Tx</sub> and the receiver G<sub>Rx</sub> can also be used to extend how far the receiver can be from the transmitter. Path loss in free space L<sub>fs</sub> is a calculated with the following equation.

$$ L<sub>fs</sub> = 20log<sub>10<sub>(\frac{4\pi * d}{\lambda}) $$

### ESP8266
This wifi module has been selected due to low cost and so it can connect to the wifi to send the RID signal packet. It would be inefficient to have the arduino use its own ESP32 module to receive signals and then try to connect to the internet to send the packet. This would create a loss in data received because of the time required to reconnect to the internet. This would affect the whole system from being able to track the drone because it will miss signals sent by the drone. 

## Schematic

### Circuit
The circuit will be soldered onto perf board utilizing the following connections. 
<img src="/Documentation/Images/Receiver/Schematics/Receiver.png" width="60%" height="60%">

### Receiver Enclosure



## Analysis

### Receivers
The  receivers are designed to receive the RID drone signal and send the data to the database subsystem. The Arduino Nano ESP32 has a built in module used to receive and send Bluetooth and WiFi signals on the 2.4 GHz band. These secondary receivers will be placed around the contiguous campus for maximum reception coverage. The receivers will be placed outside to minimize power loss that can be caused by building and maximize the range that the receivers will be able to receive a signal. A resin 3D print will be created and spray prainted white and a protective spray that will help protect it from UV and water damage. This print will have a small opening for the power subsystem to get wires to power the arduino and the USB-C connector. The Arduino Nano ESP32 utilizes a NORA-W106 to receive Bluetooth and WiFi signals. The module has a receiver sensitivity of -98 dBm for and receiver gain of 3 dBi for Bluetooth. It also has a -97 dBm receiver sensitivity for Wifi and gain of 3 dBi. 
P<sub>Rx</sub> = P<sub>Tx</sub> + G<sub>Tx</sub> - L<sub>Tx</sub> - L<sub>fs</sub> + G<sub>Rx</sub> - L<sub>Rx</sub>
The receivers will utilize a ESP8266 (WiFi module) to conect the Arduino to the Tennessee Tech WiFi, EagleNet. The purpose of the WiFi module is to send the data received from the RID signal to the database over WiFi. This will allow the receivers to constantly receive the data and have a connection to the database subsystem to send the signal as quickly as possible. 
## BOM
#### All prices listed are in USD
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|Arduino Nano ESP32|ABX00083|9|$20.00|$180.00|
|ESP8266| WRL-17146|9|$7.95|$71.55|
|Enclosure with Knockouts, (3.70" x 2.56" x 2.24") ext, (3.36" x 2.22" x 1.76") int, IP66|SK-12-03|9|$14.18|$127.62|
|Gray Cable Glands, IP68, M20 Thread|CG-31|9|$2.23|$20.07|
|Mounting Feet Kit for SK Series Enclosures, 4pc|SK-99|9|$3.36|$30.24|
|Total     |             |   45     |                |   $429.48         |


## References and Links
[^1]: "Standard specification for remote ID and tracking designation - F3411 - 19," ASTM International, (2019).

[^2]: J. Marcel, “3 key factors that determine the range of bluetooth,” Bluetooth® Technology Website, https://www.bluetooth.com/blog/3-key-factors-that-determinethe-range-of-bluetooth/ (accessed Apr. 3, 2024). 

[^4]: S. Cerwin, Radio Propagation and Antennas: A Non-Mathematical Treatment of Radio and Antennas. Bloomington, IN: AuthorHouse, 2019. 

[^6]: D. Aouladhadj et al., “Drone detection and tracking using RF Identification Signals,” National Center for Biotechnology Information, https://www.ncbi.nlm.nih.gov/pmc/articles/PMC10490811/ (accessed Apr. 3, 2024). 

[^7]: “Arduino® Nano ESP32,” Arduino Online Shop, https://store-usa.arduino.cc/products/nano-esp32?selectedStore=us (accessed Apr. 5, 2024).

[^8]: ABX00083-datasheet.pdf, https://docs.arduino.cc/resources/datasheets/ABX00083-datasheet.pdf (accessed Apr. 5, 2024). 

[^9]: “Calculate area on map, Google Maps Area Calculator,” CalcMaps, https://www.calcmaps.com/map-area/ (accessed Apr. 5, 2024). 

[^10]: “WIFI module - ESP8266 (4MB Flash),” WRL-17146 - SparkFun Electronics, https://www.sparkfun.com/products/17146 (accessed Apr. 10, 2024). 
