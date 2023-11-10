# Data Subsystem

## Function of the Subsystem
The data subsystem is responsible for the transmission and storage of data. Data will be collected by ESP WROOM 32E microcontrollers (one per pair of loops, two in total). The process of data collection involves signal processing and will be covered in another subsystem, the vehicle detector subsystem. The microcontrollers will transmit the data they have collected with RFM95W LoRa transceivers to the LoRaWAN gateway. The LoRaWAN gateway uses the Seeed Studio WM1302 LoRaWAN concentrator module to receive the LoRa packets. The concentrator module is connected to a Raspberry Pi 3 via the Seeed Studio WM1302 PiHAT, which sits atop the Raspberry Pi and is connected to the GPIO pins. The PiHAT passes LoRaWAN packets to the Raspberry Pi, which will act as the LoRaWAN gateway. The Raspberry Pi will accomplish this by using ChirpStack software. It will use ChirpStack Gateway Bridge to act as a LoRaWAN gateway and ChirpStack Network Server to act as the network server. Once the data is received by the gateway, we can find it in the network server interface. The system will use this data to calculate the total number of open parking spaces in the lot with a simple Python script that subtracts the deltas from the known value of total parking spaces in the lot. Then, the Python script will insert this data, as well as any other data the CS team needs, into a MySQL database that is also located in the Raspberry Pi. This database can be queried for use with the Firebase cloud server which serves the mobile app managed by the CS team.

## Constraints
| No. | Constraints                                                                                                                                     | Origin              |
|-----|-------------------------------------------------------------------------------------------------------------------------------------------------|---------------------|
| 1.  | Data shall be transmitted on the unlicensed 915 MHz ISM band bounded by 902 MHz and 928 MHz.                                                    | FCC Section 15.247  |
| 2.  | Data shall be transmitted according to the standards set by The LoRa Alliance that define the LoRa protocol.                                    | System Requirements |
| 3.  | The system shall be able to communicate effectively over a distance of at least 255 feet, which is a generous estimate of the straight line distance between the capstone lab and the furthest point the MCU may be located beside the lot entrance/exit. This distance must be achieved even when the signal has to pass through several layers of material that are part of Brown Hall. | System Requirements |

1. Data shall be transmitted on the unlicensed 915 MHz ISM band bounded by 902 MHz and 928 MHz. This constraint comes from the FCC standards for the 902 MHz to 928 MHz ISM band. The system will use LoRa to transmit data, and LoRa uses the 915 MHz band, therefore, the system is constrained to using this frequency band.
2. Data shall be transmitted according to the standards set by The LoRa Alliance that define the LoRa protocol. For the system to transmit data properly with LoRa, it must follow the standards that define LoRa. This includes how data must be encoded using Chirp Spread Spectrum modulation for LoRa. The LoRa concentrator module must receive data encoded in that manner to properly demodulate the chirps so the data can be collected from the LoRa packets.
3. The system shall be able to communicate effectively over a distance of at least 255 feet, which is a generous estimate of the straight line distance between the capstone lab and the furthest point the MCU may be located beside the lot entrance/exit. This distance must be achieved even when the signal has to pass through several layers of material that are part of Brown Hall. Reliable communication is a requirement for the system to function as intended. The calculation to approximate straight line distance from the capstone lab to the side of the road is: distance = sqrt(((num_floors*floor_height)^2)+(horizontal_distance^2)), num_floors being equal to 3, floor_height being equal to 15 ft, and horizontal_distance being equal to 250 ft. These values are purposely generous to account for any inaccuracy in the estimates, since the horizontal distance is based on a Google Maps measurement of 190ft, and the floor height is from an estimate based on average ceiling height plus the distance between floors (thickness of the floor). The signal will also have to be able to penetrate materials such as concrete, metal, and glass. The inability to penetrate these materials will mean an inability to transmit and receive data. The system must also be resilient to interference from the many 2.4GHz devices located across the entirety of Brown Hall.

## Schematics / Block Diagrams

![Basic block diagram Data Subsystem](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/c43f805b-1c6c-412f-835d-2dbf95f1ec6d)
<em>Figure 1. Block Diagram of Entire Subsystem</em>

![ESP32_Operation](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/38003323-e503-4745-a4c4-f8c044c9376d)
<em>Figure 2. ESP32 Block Diagram</em>

![Network_Block_Diagram](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/afadafb0-dcaf-43ec-a1ce-43f3f5a92893)
<em>Figure 3. Network Block Diagram</em>

![ESP32_Schematic-Dimensions_View](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/27146c5b-f9e3-4d8a-9bb0-b24fef99b645)
<em>Figure 4. Dimensions of ESP32 and RFM85W Breakout Board</em>

![ESP32_Schematic-Wiring_View](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/07d51866-1d7c-4f3a-9a28-a11da050b1f7)
<em>Figure 5. GPIO connections for ESP32</em>





## Analysis

### Data Transmission
Data will be transmitted from the ESP32 MCUs to the Raspberry Pi-based LoRaWAN gateway using LoRa protocol via RFM95W transceivers connected to the ESP32 MCUs' GPIO pins. Using the LoRa library for Arduino, the system should always follow the standards that define LoRa and as a consequence also the FCC 915 MHz ISM band standards. The RFM9X transceivers come in different regional variants. The RFM95W can be configured to operate at any frequency in the range 862-1020 MHz according to the datasheet. For the transceiver to meet constraint 1, the frequency must be set to 915 MHz. This can be done using the RadioHead RH_RF95 library public member function setFrequency(915.0). Nearly everything about the RFM95W is configurable with software. The MCUs will communicate with the transceivers via SPI protocol. The pin connections are shown in the table below. The transceiver will send the delta of vehicles in/out of the lot, which was previously determined by the MCU, in the form of a LoRa packet which is encoded in Chirp Spread Spectrum modulation. The WM1302 concentrator can receive and demodulate these LoRa packets so that our Raspberry Pi can understand the data contained in the LoRa packets. The Raspberry Pi is connected to the WM1302 gateway module via the WM1302 PiHAT which sits atop the Raspberry Pi and is connected via the Raspberry Pi's GPIO pins. The data from the PiHAT will be passed into ChirpStack software installed on the Raspberry Pi. ChirpStack Gateway Bridge has built-in support for Semtech SX1302-based concentrators (through the ChirpStack Concentratord backend), such as the WM1302 concentrator, so setup should be mostly painless. ChirpStack Gateway Bridge will route the packets it receives to ChirpStack Network Server, which is on the same Raspberry Pi. ChirpStack Network Server keeps a record of data it receives and is accessible over the internet, given the Raspberry Pi has an internet connection. LoRa protocol should meet the range and material penetration constraints. LoRa uses the 915 MHz frequency band which can effectively penetrate concrete, metal, and glass. With the addition of antennas attached to the RFM95W PCBs, the system should be able to easily reach the gateway from the roadside.

| ESP32 MCU Pin | RFM95W Transceiver Pin |
|---------------|------------------------|
| GND           | GND                    |
| 3.3V          | 3.3V                   |
| GPIO14        | RESET                  |
| GPIO5         | NSS                    |
| GPIO18        | SCK                    |
| GPIO23        | MOSI                   |
| GPIO19        | MISO                   |
| GPIO2         | DIO0                   |

### Data Storage
Data will be processed and stored on the Raspberry Pi. The Raspberry Pi will be running on Raspberry Pi OS installed on a microSD card and will have ChirpStack software installed. A Python script will take the current deltas contained in ChirpStack Network Server and subtract them from the known value of the total parking spaces in a lot. This will give the total number of parking spaces available in the lot. After the calculation, the number of spaces available as well as a timestamp will be stored in a MySQL database on the Raspberry Pi. Any other data the Computer Science team may need for the mobile app can be contained here as well. The Computer Science team can make use of this data for the Firebase cloud server that serves the mobile app. This can be accomplished with another Python script that will push a query of the database to the Firebase cloud server.

## BOM
| Part                                                                             | Part/Model Number                   | Quantity | Price Per Unit | Total Price |
|----------------------------------------------------------------------------------|-------------------------------------|----------|----------------|-------------|
| ESP32-WROOM-32E 4MB FLASH                                                        | ESP32-DEVKITC-32E                   | 2        | $10.00         | $20.00      |
| RFM95W LORA RADIO TRANSCEIVER BR                                                  | 1528-1667-ND                        | 2        | $19.95         | $39.90      |
| U.FL, IPEX Connector, SMT                                                        | IPXSM66AL (I-PEX P/N 20279-001E-03) | 2        | $0.75          | $1.50       |
| RAK Wireless Fiberglass Outdoor Antenna 3dBi N-Type to IPEX Connector 860-930MHz | N/A, RAK Wireless SKU: 915008       | 2        | $27.50         | $55.00      |
| RASPBERRY PI 4 MODEL B 8GB                                                       | SC0195(9)                           | 1        | $75.00         | $75.00      |
| 915MHz LoRa Antenna Omni 5dbi SMA Male + 15cm IPEX Extension Cable 2 Pcs         | TY-CSA23                            | 1        | $13.99         | $13.99      |
| RAK5146 PiHAT Kit for LoRaWAN US915 Without GPS                                  | N/A, RAK Wireless SKU: 816025       | 1        | $100.00        | $100.00     |
| Pilot Gateway Pro LoRa Enclosure Kit for Raspberry Pi 4 - RAK7244                | N/A, Adafruit PID: 5057             | 1        | $27.50         | $27.50      |
| SanDisk 128GB Ultra microSDXC                                                    | SDSQUAB-128G-GN6MA                  | 1        | $12.49         | $12.49      |
| CanaKit 3.5A Raspberry Pi 4 Power Supply (USB-C)                                 | N/A, ASIN: B07TYQRXTK               | 1        | $9.99          | $9.99       |
| TOTAL                                                                            |                                     |          |                | $355.37     |


## References
"Electronic Code of Federal Regulations," Title 47-Telecommunication, CHAPTER I-FEDERAL COMMUNICATIONS COMMISSION, SUBCHAPTER A-GENERAL, PART 15-RADIO FREQUENCY DEVICES, Subpart C-Intentional Radiators, Radiated Emission Limits, Additional Provisions, Section 15.247 Operation within the bands 902-928 MHz, 2400-2483.5 MHz, and 5725-5850 MHz. https://www.law.cornell.edu/cfr/text/47/15.247
