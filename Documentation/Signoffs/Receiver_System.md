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
![image](https://github.com/mrnye42/Drone-Tracker-Project/assets/113947428/0d1d1ad6-30ce-4065-8f34-d38c02ce6f21)





## Analysis
### Secondary Receivers

P<sub>Rx</sub> = P<sub>Tx</sub> + G<sub>Tx</sub> - L<sub>Tx</sub> - L<sub>fs</sub> + G<sub>Rx</sub> - L<sub>Rx</sub>
### Primary Receiver

## BOM
#### All prices listed are in USD
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|HackRF One [^9]        |3583             |1          |$339.95            |$339.95            |
|Raspberry Pi 5 [^10]         |8GB-9028             |1          |$80.00                |$80.00            |
|microHDMI to HDMI cable [^11]         |633696492882            |1          |$8.95                |$8.95            |
|ANT-W63WS1-SMA [^12]         |712-ANT-W63WS1-SMA             |1          |$12.27                |$12.27            |
|SanDisk 16GB Ultra USB 3.0 Flash Drive [^13]  |  SDCZ48-016G-GAM46    |     1     |   $8.40             |     $8.40       |
|Total     |             |   5       |                |   $449.57         |


## References and Links
[^1]: "Standard specification for remote ID and tracking designation - F3411 - 19," ASTM International, (2019).

[^2]: J. Marcel, “3 key factors that determine the range of bluetooth,” Bluetooth® Technology Website, https://www.bluetooth.com/blog/3-key-factors-that-determinethe-range-of-bluetooth/ (accessed Apr. 3, 2024). 

[^4]: S. Cerwin, Radio Propagation and Antennas: A Non-Mathematical Treatment of Radio and Antennas. Bloomington, IN: AuthorHouse, 2019. 

[^6]: D. Aouladhadj et al., “Drone detection and tracking using RF Identification Signals,” National Center for Biotechnology Information, https://www.ncbi.nlm.nih.gov/pmc/articles/PMC10490811/ (accessed Apr. 3, 2024). 

[^7]: “Arduino® Nano ESP32,” Arduino Online Shop, https://store-usa.arduino.cc/products/nano-esp32?selectedStore=us (accessed Apr. 5, 2024).

[^8]: ABX00083-datasheet.pdf, https://docs.arduino.cc/resources/datasheets/ABX00083-datasheet.pdf (accessed Apr. 5, 2024). 

[^9]: “Calculate area on map, Google Maps Area Calculator,” CalcMaps, https://www.calcmaps.com/map-area/ (accessed Apr. 5, 2024). 

[^10]: “Gravity: Nano I/O shield,” Arduino Online Shop, https://store-usa.arduino.cc/products/gravity-nano-i-o-shield (accessed Apr. 7, 2024). 

[^11]: Mouser, https://www.mouser.com/datasheet/2/891/0c_esp_wroom_02_datasheet_en-1365805.pdf (accessed Apr. 11, 2024). 
