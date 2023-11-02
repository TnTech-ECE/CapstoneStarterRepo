# Data Subsystem

## Function of the Subsystem
The data subsystem is responsible for the collection, transmission, and storage of data. Data will be collected by ESP WROOM 32E microcontrollers (one per loop detector). The microcontrollers will transmit the data they have collected with RFM95W LoRa transceivers to the LoRaWAN gateway. The LoRaWAN gateway uses the RAK2287 concentrator module to receive the LoRa packets. The concentrator module is connected to a Raspberry Pi 4 Model B via the RAK5146 PiHAT, which sits atop the Raspberry Pi and is connected to the GPIO pins. The PiHAT sends LoRaWAN packets to the Raspberry Pi, which will act as the LoRaWAN gateway. The Raspberry Pi will accomplish this by using ChirpStack software. It will use ChirpStack Gateway Bridge to act as a LoRaWAN gateway and ChirpStack Network Server to act as the network server. Once the data is received in the gateway, we can find it in the network server interface. The system will use this data to calculate the total number of open parking spaces in the lot with a simple Python script that subtracts the deltas from the known value of total parking spaces in the lot. Then, the Python script will insert this data, as well as any other data the CS team needs, into a MySQL database that is also located in the Raspberry Pi. This database can be queried for use with the Firebase cloud server which serves the mobile app managed by the CS team.

## Constraints
| No. | Constraints                                                                                                                                     | Origin              |
|-----|-------------------------------------------------------------------------------------------------------------------------------------------------|---------------------|
| 1.  | Data shall be transmitted on the unlicensed 915 MHz ISM band bounded by 902 MHz and 928 MHz.                                                    | FCC Section 15.247  |
| 2.  | Data shall be transmitted according to the standards set by The LoRa Alliance that define the LoRa protocol.                                     | System Requirements |
| 3.  | The system shall locally store the current delta of vehicles that were detected to be entering or exiting the lot in the microcontroller's ROM. | System Requirements |
| 4.  | The system shall be able to determine if a vehicle has entered or exited a lot based upon which GPIO pin receives a 3.3V signal.                | System Requirements |

1. Data shall be transmitted on the unlicensed 915 MHz ISM band bounded by 902 MHz and 928 MHz. This constraint comes from the FCC standards for the 902 MHz to 928 MHz ISM band. The system will use LoRa to transmit data, and LoRa uses the 915 MHz band, therefore, the system is constrained to using this frequency band.
2. Data shall be transmitted according to the standards set by The LoRa Alliance that define the LoRa protocol. For the system to transmit data properly with LoRa, it must follow the standards that define LoRa. This includes how data must be encoded using Chirp Spread Spectrum modulation for LoRa. The LoRa concentrator module must receive data encoded in that manner to properly demodulate the chirps so the data can be collected from the LoRa packets.
3. The system shall locally store the current delta of vehicles that were detected to be entering or exiting the lot in the microcontroller's ROM. This constraint comes from a system requirement. The system must store the delta every time a vehicle is detected entering or exiting a lot to keep accurate data even if the LoRa gateway cannot be reached. For example, if the power goes out, the gateway will lose power and will therefore not be able to store the data transmitted by the microcontrollers. If the data was not stored in the microcontroller in this scenario, then there would be a loss of data ultimately leading to inaccurate data.
4. The system shall be able to determine if a vehicle has entered or exited a lot based upon which GPIO pin receives a 3.3V signal. This constraint is a system requirement. If the microcontrollers cannot determine whether a car has entered or exited a lot with a high degree of accuracy, then it is useless to the system.

## Schematics


## Analysis
### Data Collection

### Data Transmission

### Data Storage

## BOM


## References
"Electronic Code of Federal Regulations," Title 47-Telecommunication, CHAPTER I-FEDERAL COMMUNICATIONS COMMISSION, SUBCHAPTER A-GENERAL, PART 15-RADIO FREQUENCY DEVICES, Subpart C-Intentional Radiators, Radiated Emission Limits, Additional Provisions, Section 15.247 Operation within the bands 902-928 MHz, 2400-2483.5 MHz, and 5725-5850 MHz. https://www.law.cornell.edu/cfr/text/47/15.247
