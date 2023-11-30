# Data Subsystem

## Summary
From a high-level view, this subsystem performs two functions. It transmits data from the ground-based sensor to the Raspberry Pi and stores that data in a database on the Raspberry Pi. Also, after the previously mentioned functionality is implemented, it will have the capability to send this stored data to a Firebase cloud server so the mobile app can make use of the data.

## Function of the Subsystem
The data subsystem is responsible for the transmission and storage of data. Data will be collected by ESP WROOM 32E microcontrollers (one per pair of loops, two in total). The process of data collection involves signal processing and will be covered in another subsystem, the vehicle detector subsystem. The microcontrollers will transmit the data they have collected with RFM95W LoRa transceivers to the LoRaWAN gateway. The LoRaWAN gateway uses the Seeed Studio WM1302 LoRaWAN concentrator module to receive the LoRa packets. The concentrator module is connected to a Raspberry Pi 3 via the Seeed Studio WM1302 PiHAT, which sits atop the Raspberry Pi and is connected to the GPIO pins. The PiHAT passes LoRaWAN packets to the Raspberry Pi, which will act as the LoRaWAN gateway. The Raspberry Pi will accomplish this by using ChirpStack software. It will use ChirpStack Gateway Bridge to act as a LoRaWAN gateway and ChirpStack Network Server to act as the network server. Once the data is received by the gateway, we can find it in the network server interface. The system will use this data to calculate the total number of open parking spaces in the lot with a simple Python script that subtracts the delta of vehicles that have been detected to be going in or out of a lot from the known value of total parking spaces in the lot. Then, the Python script will insert this data, as well as any other data the CS team needs, into a MySQL database that is also located in the Raspberry Pi. This database can be queried for use with the Firebase cloud server which serves the mobile app managed by the CS team. Firebase integration will be considered after the core functionality of the subsystem is complete. Core functionality being successful data transmission from the microcontrollers to the gateway and storage in a local database.

## Constraints
| No. | Constraints                                                                                                                                     | Origin              |
|-----|-------------------------------------------------------------------------------------------------------------------------------------------------|---------------------|
| 1.  | Data shall be transmitted on the unlicensed 915 MHz ISM band bounded by 902 MHz and 928 MHz.                                                    | FCC Section 15.247  |
| 2.  | Data shall be transmitted according to the standards set by The LoRa Alliance that define the LoRa protocol.                                    | System Requirements |
| 3.  | The system shall be able to communicate effectively over a distance of at least 255 feet, which is a generous estimate of the straight line distance between the capstone lab and the furthest point the MCU may be located beside the lot entrance/exit. This distance must be achieved even when the signal has to pass through several layers of material that are part of Brown Hall. | System Requirements |
| 4.  | The system is constrained by the limited data rate that is inherent to the LoRaWAN protocol. Specifically, the bit rate can range between 0.3 kbps to 27 kbps depending on the spreading factor and bandwidth used. | LoRaWAN Protocol |
| 5.  | The system is constrained by the maximum payload size afforded by LoRaWAN. Depending on the spreading factor, the maximum payload size can range from 51 bytes to 222 bytes. | LoRaWAN Protocol |

1. Data shall be transmitted on the unlicensed 915 MHz ISM band bounded by 902 MHz and 928 MHz. This constraint comes from the FCC standards for the 902 MHz to 928 MHz ISM band. A license is required to operate in many other frequency bands, so those frequency bands must be avoided. Other frequency bands are reserved for certain applications, these must be avoided as well. The system will use LoRa to transmit data, and LoRa uses the 915 MHz ISM band, therefore, the system is constrained to using this frequency band.
2. Data shall be transmitted according to the standards set by The LoRa Alliance that define the LoRa protocol. For the system to transmit data properly with LoRa, it must follow the standards that define LoRa. This includes how data must be encoded using Chirp Spread Spectrum modulation for LoRa. The LoRa concentrator module must receive data encoded in that manner to properly demodulate the chirps so the data can be collected from the LoRa packets.
3. The system shall be able to communicate effectively over a distance of at least 255 feet, which is a generous estimate of the straight line distance between the capstone lab and the furthest point the MCU may be located beside the lot entrance/exit. This distance must be achieved even when the signal has to pass through several layers of material that are part of Brown Hall. Reliable communication is a requirement for the system to function as intended. The calculation to approximate straight line distance from the capstone lab to the side of the road is: distance = sqrt(((num_floors*floor_height)^2)+(horizontal_distance^2)), num_floors being equal to 3, floor_height being equal to 15 ft, and horizontal_distance being equal to 250 ft. These values are purposely generous to account for any inaccuracy in the estimates, since the horizontal distance is based on a Google Maps measurement of 190ft (center of Brown Hall to the far side of the road), and the floor height is from an estimate based on average ceiling height plus the distance between floors (thickness of the floor). The signal will also have to be able to penetrate materials such as concrete, metal, and glass. The inability to penetrate these materials will mean an inability to transmit and receive data. The system must also be resilient to interference from the many 2.4GHz devices located across the entirety of Brown Hall.
4. The system is constrained by the limited data rate that is inherent to the LoRaWAN protocol [11]. Specifically, the bit rate can range between 0.3 kbps to 27 kbps depending on the spreading factor and bandwidth used. A balance will have to be achieved between the spreading factor, bandwidth, range, battery life, and data rate. The spreading factor can range from SF7 to SF12. A higher spreading factor means more range, slower data rate, and shorter battery life. The inverse is true for lower spreading factors.
5. The system is constrained by the maximum payload size afforded by LoRaWAN [11]. Depending on the spreading factor, the maximum payload size can range from 51 bytes to 222 bytes. Determined by data rate. Max payload size increases with the data rate.

## Schematics / Block Diagrams

![Block Diagram](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/8d9a5715-6e17-4905-b8ca-53e408e95aed)
<em>Figure 1. Block Diagram</em>

![ESP32_Schematic-Dimensions_View](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/27146c5b-f9e3-4d8a-9bb0-b24fef99b645)
<em>Figure 2. Dimensions of ESP32 and RFM85W Breakout Board</em>

![ESP32_Schematic-Wiring_View](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/8af4485d-a49f-4b8b-96bb-51c6164fa201)
<em>Figure 3. GPIO connections for ESP32</em>





## Analysis

### Data Transmission
Data will be transmitted from the ESP32 MCUs to the Raspberry Pi-based LoRaWAN gateway using LoRa protocol via RFM95W transceivers connected to the ESP32 MCUs' GPIO pins. Using the LoRa library for Arduino, the system should always follow the standards that define LoRa and as a consequence also the FCC 915 MHz ISM band standards. The RFM9X transceivers come in different regional variants. The RFM95W can be configured to operate at any frequency in the range 862-1020 MHz according to the datasheet. For the transceiver to meet constraint 1, the frequency must be set to 915 MHz. This can be done using the RadioHead RH_RF95 library public member function setFrequency(915.0). Nearly everything about the RFM95W is configurable with software. The MCUs will communicate with the transceivers via SPI protocol. The pin connections are shown in the table below and in Figure 3. The table shows the pin names of the actual transceiver PCB according to the datasheet, and Figure 3 shows the breakout board the transceiver is mounted on. The breakout board provides labels for the pins and an easy way to attach an antenna. An antenna is vital in getting the most range possible out of the RFM95W transceiver. The transceiver will send the delta of vehicles in/out of the lot, which was previously determined by the MCU, in the form of a LoRa packet which is encoded in Chirp Spread Spectrum modulation. The WM1302 concentrator can receive and demodulate these LoRa packets so that our Raspberry Pi can understand the data contained in the LoRa packets. The Raspberry Pi is connected to the WM1302 gateway module via the WM1302 PiHAT which sits atop the Raspberry Pi and is connected via the Raspberry Pi's GPIO pins. The data from the PiHAT will be passed into ChirpStack software installed on the Raspberry Pi. ChirpStack Gateway Bridge has built-in support for Semtech SX1302-based concentrators (through the ChirpStack Concentratord backend), such as the WM1302 concentrator, so setup should be mostly painless. ChirpStack Gateway Bridge will route the packets it receives to ChirpStack Network Server, which is on the same Raspberry Pi. ChirpStack Network Server keeps a record of data it receives and is accessible over the internet, given the Raspberry Pi has an internet connection. LoRa protocol should meet the range and material penetration constraint. LoRa uses the 915 MHz frequency band which can effectively penetrate concrete, metal, and glass. With the addition of antennas attached to the RFM95W PCBs, the system should be able to easily reach the gateway from the roadside.

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

### Why These Pins on the ESP32?
- GND, 3.3V
  - These are power supply pins used for powering the RFM95W
- GPIO14 for RESET
  - This is simply a GPIO that is not reserved for anything else the system may need to use. This can be changed if necessary.
- GPIO5 for NSS (Chip Select)
  - This is the dedicated VSPI_CS pin
- GPIO18 for SCK
  - This is the dedicated VSPI_CLK pin
- GPIO23 for MOSI
  - This is the dedicated VSPI_MOSI pin
- GPIO19 for MISO
  - This is the dedicated VSPI_MISO pin
- GPIO2 for DIO0 (RFM95W GPIO)
  - This is simply a GPIO that is not reserved for anything else the system may need to use. This can be changed if necessary.

### Addressing Constraints
- Constraint 1
  - This constraint will be addressed by configuring all devices that will be transmitting and receiving LoRa packets to only do so on the 915 MHz frequency band. This is simply a parameter in software that will need to be specified. For the Raspberry Pi gateway, this is not necessary as the WM1302 LoRaWAN concentrator that has been selected for this project is made to operate exclusively on the US915 frequency band. For the RFM95W transceiver modules, the frequency band can be specified with the RadioHead RH_RF95 library public member function setFrequency(915.0).


- Constraint 2
  - This constraint will be addressed by using the LoRa library for Arduino. The ESP32 microcontrollers will use this library to transmit data with the RFM95W transceivers. The Raspberry Pi will meet this constraint by using ChirpStack software which is intended to work with LoRa exclusively and thus will require no additional configuration (pertaining to selecting the transmission protocol).

 
- Constraint 3
  - This constraint will be addressed by choosing parts such as antennas with adequate gain and parameters in the code to maximize the range of the network. The TX power of the RFM95W can be reduced from the 20 dBm mode to a lower setting to conserve power if necessary. This will be determined via testing. To show that the system is capable of meeting the minimum range constraint, the Ericsson propagation model is used as a pessimistic estimate of the range for LoRaWAN. Compared to the required 255 feet in constraint 3, the model predicts a range in the order of kilometers. This is clearly well in excess of the minimum required distance and would likely be enough to cover the entirety of campus.
  - The Ericsson propagation model was derived from the Hata model, which was itself developed based on urban area data collected in Tokyo [10]. This is clearly a more challenging environment than the comparatively less dense Tennessee Technological University campus and the city of Cookeville. Thus, we should expect better performance from the system than what the model predicts. The Ericsson model and the values chosen for the simulation are as follows.

   - The Ericsson Propagation Model: $L = a₀ + a₁ log₁₀(d) + a₂ log₁₀(h_b) + a₃ log₁₀(h_b) \times \log₁₀(d) - 3.2 \log₁₀(11.75hᵣ)² + g(f)$
    Where $L$ is the path loss, $a₀$ - $a₃$ are environment constants, $h_b$ is the base station antenna height, in our case the gateway, $h_r$ is the end device antenna height, in our case the ESP32 microcontrollers with RFM95W transceivers, $d$ is the distance between the base station and the end device, and $g(f)$ which is the frequency correction factor described as $g(f) = 44.49 log₁₀(f) - 4.78 log₁₀(f)²$, where $f$ is carrier frequency.
    The values chosen for the simulation are as close to the expected true values as possible, taking into account the valid ranges for the model. The model is only accurate for certain values. The valid range for carrier frequency is 150 Mhz to 2 GHz, 915 MHz was used. The valid range for base station antenna height ($h_b$) is 20 to 200 m, the minimum of 20 m was used. The valid range for end device antenna height ($h_r$) is 1 to 5 m, the minimum of 1 m was used. The valid range for distance ($d$) is 0.2 to 100 km, a range of distances was used for the plot. The environment constants were chosen to represent the values for an urban environment, they were specified in the simulation as follows: $a_0 = 36.2$, $a_1 = 30.2$, $a_2 = -12$, $a_3 = 0.1$. The simulated plot of path loss vs distance and link budget vs distance is below.

  ![EricssonModelSim](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/ae5a141c-50e4-490c-8482-ebf9dfe14a14)
   <em>Figure 4. Path Loss vs Distance and Link Budget vs Distance for Ericsson Model</em>


- Constraint 4
  - This constraint will be addressed by adjusting the parameters of the RFM95W to suit the needs of the system. The data rate can be changed by modifying the value for the spreading factor in the range SF7 to SF12. A smaller spreading factor means a higher data rate and vice versa with a fixed bandwidth and coding rate [12]. We will always use a coding rate 4/5, which is the default. The data rate can also be changed by modifying the bandwidth. We can choose 125 kHz, 250 kHz, or 500 kHz for bandwidth. With a fixed spreading factor and coding rate, doubling the bandwidth doubles the data rate [12]. Since higher spreading factors mean lower battery life due to longer time on air [12], the system will aim to use a lower spreading factor.

- Constraint 5
  - This constraint will be addressed if necessary. The system will likely only send packets with a payload smaller than the minimum max payload size. This is because the ESP32 microcontrollers will only be sending the delta of vehicles entering or exiting the lot as a two to three-digit integer number. The max payload size is determined by the spreading factor and bandwidth. A higher data rate correlates with a higher max payload size [13].
 

### Data Storage
Data will be processed and stored on the Raspberry Pi. The Raspberry Pi will be running on Raspberry Pi OS installed on a microSD card and will have ChirpStack software installed. A Python script will take the current deltas contained in ChirpStack Network Server and subtract them from the known value of the total parking spaces in a lot. This will give the total number of parking spaces available in the lot. After the calculation, the number of spaces available as well as a timestamp will be stored in a MySQL database on the Raspberry Pi. Any other data the Computer Science team may need for the mobile app can be contained here as well. For example, location data could also be included. The Computer Science team can make use of this data with the Firebase cloud server that serves the mobile app. This can be accomplished with another Python script that will push a query of the database to the Firebase cloud server. Firebase integration will be considered after the subsystem is fully functional by itself.

## BOM
| Part                                                                             | Part/Model Number                   | Quantity | Price Per Unit | Total Price |
|----------------------------------------------------------------------------------|-------------------------------------|----------|----------------|-------------|
| ESP32-WROOM-32E 4MB FLASH                                                        | ESP32-DEVKITC-32E                   | 2        | $10.00         | $20.00      |
| RFM95W LORA RADIO TRANSCEIVER BR                                                 | 1528-1667-ND                        | 2        | $19.95         | $39.90      |
| U.FL, IPEX Connector, SMT                                                        | IPXSM66AL (I-PEX P/N 20279-001E-03) | 2        | $0.75          | $1.50       |
| 915MHz LoRa Antenna Omni 5dbi SMA Male + 15cm IPEX Extension Cable 2 Pcs         | TY-CSA23                            | 1        | $13.99         | $13.99      |
| Long Range Indoor Antenna Kit; 860-930MHz; 3dBi; 295mm                           | N/A, Seeed Studio SKU: 110991765    | 1        | $14.90         | $14.90      |
| Tenmory UFL to SMA Mini PCI U.FL to RP-SMA Female Ipex Connector Pigtail Antenna Extension Cable (6 inch (2 Pcs))      | N/A, ASIN: B07T85B3LN | 1 | $5.99 | $5.99|
| WM1302 Raspberry Pi Hat                                                          | N/A, Seeed Studio SKU: 113100022    | 1        | $19.90         | $19.90      |
| Wio-WM1302 LoRaWAN Gateway Module (SPI) - US915 - M                              | WM1302-SPI-US915-M                  | 1        | $25.00         | $25.00      |
| SanDisk 64GB Ultra microSDHC                                                     | SDSQUA4-064G-GN6MA                  | 1        | $8.99          | $8.99       |
| Raspberry Pi 3*                                                                  | N/A                                 | 1        | $0.00          | $0.00       |
| TOTAL                                                                            |                                     |          |                | $150.17     |

<sup>*</sup> The Raspberry Pi 3 will be provided by the department from a past project.


## References
1. "Electronic Code of Federal Regulations," Title 47-Telecommunication, CHAPTER I-FEDERAL COMMUNICATIONS COMMISSION, SUBCHAPTER A-GENERAL, PART 15-RADIO FREQUENCY DEVICES, Subpart C-Intentional Radiators, Radiated Emission Limits, Additional Provisions, Section 15.247 Operation within the bands 902-928 MHz, 2400-2483.5 MHz, and 5725-5850 MHz. https://www.law.cornell.edu/cfr/text/47/15.247

2. The ChirpStack Project documentation: https://www.chirpstack.io/docs/index.html

3. RadioHead RH_RF95 library for RFM95W LoRa transceiver: https://www.airspayce.com/mikem/arduino/RadioHead/classRH__RF95.html#a854c2eaa2f3cf9583453ff09f15e1099

4. LoRa Arduino library: https://github.com/sandeepmistry/arduino-LoRa

5. "RFM95/96/97/98(W) - Low Power Long Range Transceiver Module" Datasheet: https://cdn.sparkfun.com/assets/learn_tutorials/8/0/4/RFM95_96_97_98W.pdf

6. Semtech SX1302 LoRa Core™ Digital Baseband Chip for LoRaWAN network gateways documentation: https://semtech.my.salesforce.com/sfc/p/#E0000000JelG/a/2R000000Hkyg/U8CIV3e9yI9T_aILFMxuzLNs_6_0Io1WIaksrNYyCMQ

7. ESP32 Technical Reference: https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_en.pdf

8. ESP WROOM 32E pinout: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/_images/esp32-devkitC-v4-pinout.png

9. F. Adelantado, X. Vilajosana, P. Tuset-Peiro, B. Martinez, J. Melia-Segui and T. Watteyne, "Understanding the Limits of LoRaWAN," in IEEE Communications Magazine, vol. 55, no. 9, pp. 34-40, Sept. 2017, doi: 10.1109/MCOM.2017.1600613.

10. M. Stusek et al., "Accuracy Assessment and Cross-Validation of LPWAN Propagation Models in Urban Scenarios," in IEEE Access, vol. 8, pp. 154625-154636, 2020, doi: 10.1109/ACCESS.2020.3016042.

11. F. Adelantado, X. Vilajosana, P. Tuset-Peiro, B. Martinez, J. Melia-Segui and T. Watteyne, "Understanding the Limits of LoRaWAN," in IEEE Communications Magazine, vol. 55, no. 9, pp. 34-40, Sept. 2017, doi: 10.1109/MCOM.2017.1600613.

12. The Things Network LoRaWAN Documentation, Spreading Factors: https://www.thethingsnetwork.org/docs/lorawan/spreading-factors/

13. The Things Network LoRaWAN Documentation, Regional Parameters: https://www.thethingsnetwork.org/docs/lorawan/regional-parameters/us915/
