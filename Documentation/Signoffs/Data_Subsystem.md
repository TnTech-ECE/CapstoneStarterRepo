# Data Subsystem

## Function of the Subsystem
The data subsystem is responsible for the collection, transmission, and storage of data. Data will be collected by ESP WROOM 32E microcontrollers (one per vehicle detector). The microcontrollers will transmit the data they have collected with RFM95W LoRa transceivers to the LoRaWAN gateway. The LoRaWAN gateway uses the RAK2287 concentrator module to receive the LoRa packets. The concentrator module is connected to a Raspberry Pi 4 Model B via the RAK5146 PiHAT, which sits atop the Raspberry Pi and is connected to the GPIO pins. The PiHAT sends LoRaWAN packets to the Raspberry Pi, which will act as the LoRaWAN gateway. The Raspberry Pi will accomplish this by using ChirpStack software. It will use ChirpStack Gateway Bridge to act as a LoRaWAN gateway and ChirpStack Network Server to act as the network server. Once the data is received in the gateway, we can find it in the network server interface. The system will use this data to calculate the total number of open parking spaces in the lot with a simple Python script that subtracts the deltas from the known value of total parking spaces in the lot. Then, the Python script will insert this data, as well as any other data the CS team needs, into a MySQL database that is also located in the Raspberry Pi. This database can be queried for use with the Firebase cloud server which serves the mobile app managed by the CS team.

## Constraints
| No. | Constraints                                                                                                                                     | Origin              |
|-----|-------------------------------------------------------------------------------------------------------------------------------------------------|---------------------|
| 1.  | Data shall be transmitted on the unlicensed 915 MHz ISM band bounded by 902 MHz and 928 MHz.                                                    | FCC Section 15.247  |
| 2.  | Data shall be transmitted according to the standards set by The LoRa Alliance that define the LoRa protocol.                                     | System Requirements |
| 3.  | The system shall locally store the current delta of vehicles that were detected to be entering or exiting the lot in the microcontroller's ROM. | System Requirements |
| 4.  | The system shall be able to determine if a vehicle has entered or exited a lot based upon which GPIO pin receives a 3.3V signal.                | System Requirements |
| 5.  | The system shall be able to communicate effectively over a distance of at least 255 feet, which is a generous estimate of the straight line distance between the capstone lab and the furthest point the MCU may be located beside the lot entrance/exit. This distance must be achieved even when the signal has to pass through several layers of material that are part of Brown Hall. | System Requirements |

1. Data shall be transmitted on the unlicensed 915 MHz ISM band bounded by 902 MHz and 928 MHz. This constraint comes from the FCC standards for the 902 MHz to 928 MHz ISM band. The system will use LoRa to transmit data, and LoRa uses the 915 MHz band, therefore, the system is constrained to using this frequency band.
2. Data shall be transmitted according to the standards set by The LoRa Alliance that define the LoRa protocol. For the system to transmit data properly with LoRa, it must follow the standards that define LoRa. This includes how data must be encoded using Chirp Spread Spectrum modulation for LoRa. The LoRa concentrator module must receive data encoded in that manner to properly demodulate the chirps so the data can be collected from the LoRa packets.
3. The system shall locally store the current delta of vehicles that were detected to be entering or exiting the lot in the microcontroller's ROM. This constraint comes from a system requirement. The system must store the delta every time a vehicle is detected entering or exiting a lot to keep accurate data even if the LoRa gateway cannot be reached. For example, if the power goes out, the gateway will lose power and will therefore not be able to store the data transmitted by the microcontrollers. If the data was not stored in the microcontroller in this scenario, then there would be a loss of data ultimately leading to inaccurate data.
4. The system shall be able to determine if a vehicle has entered or exited a lot based upon which GPIO pin receives a 3.3V signal. This constraint is a system requirement. If the microcontrollers cannot determine whether a car has entered or exited a lot with a high degree of accuracy, then it is useless to the system.
5. The system shall be able to communicate effectively over a distance of at least 255 feet, which is a generous estimate of the straight line distance between the capstone lab and the furthest point the MCU may be located beside the lot entrance/exit. This distance must be achieved even when the signal has to pass through several layers of material that are part of Brown Hall. Reliable communication is a requirement for the system to function as intended. The calculation to approximate straight line distance from the capstone lab to the side of the road is: distance = sqrt(((num_floors*floor_height)^2)+(horizontal_distance^2)), num_floors being equal to 3, floor_height being equal to 15 ft, and horizontal_distance being equal to 250 ft. These values are purposely generous to account for any inaccuracy in the estimates, since the horizontal distance is based on a Google Maps measurement of 190ft, and the floor height is from an estimate based on average ceiling height plus the distance between floors (thickness of the floor). The signal will also have to be able to penetrate materials such as concrete, metal, and glass. The inability to penetrate these materials will mean an inability to transmit and receive data. The system must also be resilient to interference from the many 2.4GHz devices located across the entirety of Brown Hall.

## Schematics / Block Diagrams
<img width="1218" alt="Basic block diagram Data Subsystem" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/0370d95e-b63c-4620-a6a8-0f01a03bab97">
<em>Figure 1. Block Diagram of Entire Subsystem</em>

<img width="1226" alt="ESP32 block diagram" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/0bb3475e-d1ad-4ddd-a575-aecfe7b7a049">
<em>Figure 2. ESP32 Block Diagram</em>

<img width="1488" alt="Network Block Diagram" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/6d3b6970-f1ab-40bd-b1b9-77c46b6871d3">
<em>Figure 3. Network Block Diagram</em>

![ESP32_Schematic-Dimensions_View](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/27146c5b-f9e3-4d8a-9bb0-b24fef99b645)
<em>Figure 4. Dimensions of ESP32 and RFM85W Breakout Board</em>

![ESP32_Schematic-Wiring_View](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/07d51866-1d7c-4f3a-9a28-a11da050b1f7)
<em>Figure 5. GPIO connections for ESP32</em>





## Analysis
### Data Collection
Data will be collected via the ESP WROOM 32E microcontrollers. For each vehicle detector, there will be one MCU. The MCU will be powered via the 5V pin. The MCU has a built-in voltage regulator so voltages above 5V but below 12V are acceptable. Each MCU will be connected to the two output relays of the vehicle detector. The 3.3V source pin of the MCU will be connected to the common terminals of each relay, and the normally open terminals of the relays will be connected to separate GPIO pins on the MCU. These pins will be GPIO36 and GPIO39. These are input-only pins, but more importantly, they are RTC pins, which means they will be able to wake the MCU up from deep sleep. GPIO36 is RTC_GPIO0 and GPIO39 is RTC_GPIO3. The MCU will be able to tell which RTC pin woke it up from sleep with the function esp_sleep_get_ext1_wakeup_status(). With the vehicle detector in pulse mode, we can determine which direction the vehicle is going. Pulse mode works by detecting vehicle presence in one of the loops first, then the second loop detecting presence while the first is still detecting presence. This means the vehicle must have crossed the first loop before the second. The detector will send a pulse to the relay corresponding to the first loop in this case. The MCU will wake up and since it knows the GPIO pin connected to the first loop relay is what woke it up, we also know the direction of the vehicle. Knowing the direction of the vehicle is important for keeping the delta of cars entering and exiting the lot at the point where the inductive loops lay in the road. A positive delta means more vehicles have entered than exited, negative means more have exited than entered. The delta value will incremented for vehicles entering the lot and decremented for vehicles leaving the lot. This updated value for the delta will be transmitted using the RFM95W LoRa transceiver to the LoRaWAN gateway. The delta value will also be stored in nonvolatile storage so that the MCU can go back to deep sleep. With this in mind, the MCU should be in deep sleep the majority of the time, only waking up long enough to update the delta, transmit it, and store it. This will lead to a much lower power consumption compared to leaving the MCU in active mode at all times when it is not necessary.

### Data Transmission
Data will be transmitted from the ESP32 MCUs to the Raspberry Pi-based LoRaWAN gateway via LoRa protocol using RFM95W transceivers connected to the ESP32 MCUs' GPIO pins. Using the LoRa library for Arduino, the system should always follow the standards that define LoRa and as a consequence also the FCC 915 MHz ISM band standards. The MCUs will communicate with the transceivers via SPI. The pin connections are shown in the table below. The transceiver will send the delta previously determined by the MCU in the form of a LoRa packet which is encoded in Chirp Spread Spectrum modulation. The RAK2287 concentrator can receive and demodulate these LoRa packets so that our Raspberry Pi can understand the data contained in the LoRa packets. The Raspberry Pi is connected to the RAK2287 via the RAK5146 PiHAT which sits atop the Raspberry Pi and is connected via the Raspberry Pi's GPIO pins. The data from the PiHAT will be taken into ChirpStack software installed on the Raspberry Pi. ChirpStack Gateway Bridge has built-in support for the RAK2287 concentrator so setup should be easy. ChirpStack Gateway Bridge will route the packets it receives to ChirpStack Network Server, which is on the same Raspberry Pi. ChirpStack Network Server keeps a record of data it receives and is accessible over the internet, given the Raspberry Pi has an internet connection. LoRa protocol should meet the range and material penetration constraints. LoRa uses the 915 MHz frequency band which can effectively penetrate concrete, metal, and glass. With the addition of antennas attached to the RFM95W PCBs, the system should be able to easily reach the gateway from the roadside.

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
Data will be processed and stored on the Raspberry Pi. The Raspberry Pi will be running on Raspberry Pi OS installed on a microSD card and will have ChirpStack software installed. A Python script will take the current deltas contained in ChirpStack Network Server and subtract them from the known value of the total parking spaces in a lot. This will give the total number of parking spaces available in the lot. After the calculation, the number of spaces available as well as a timestamp will be stored in a MySQL database on the Raspberry Pi. Any other data the Computer Science team may need for the mobile app can be contained here as well. The Computer Science team can make use of this data for the Firebase cloud server that serves the mobile app. This can be accomplished with another Python script that will push a query to the Firebase cloud server.

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
| TOTAL                                                                            |                                     |          |                | $345.38     |


## References
"Electronic Code of Federal Regulations," Title 47-Telecommunication, CHAPTER I-FEDERAL COMMUNICATIONS COMMISSION, SUBCHAPTER A-GENERAL, PART 15-RADIO FREQUENCY DEVICES, Subpart C-Intentional Radiators, Radiated Emission Limits, Additional Provisions, Section 15.247 Operation within the bands 902-928 MHz, 2400-2483.5 MHz, and 5725-5850 MHz. https://www.law.cornell.edu/cfr/text/47/15.247
