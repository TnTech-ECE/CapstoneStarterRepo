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

1. Data shall be transmitted on the unlicensed 915 MHz ISM band bounded by 902 MHz and 928 MHz. This constraint comes from the FCC standards for the 902 MHz to 928 MHz ISM band. The system will use LoRa to transmit data, and LoRa uses the 915 MHz band, therefore, the system is constrained to using this frequency band.
2. Data shall be transmitted according to the standards set by The LoRa Alliance that define the LoRa protocol. For the system to transmit data properly with LoRa, it must follow the standards that define LoRa. This includes how data must be encoded using Chirp Spread Spectrum modulation for LoRa. The LoRa concentrator module must receive data encoded in that manner to properly demodulate the chirps so the data can be collected from the LoRa packets.
3. The system shall locally store the current delta of vehicles that were detected to be entering or exiting the lot in the microcontroller's ROM. This constraint comes from a system requirement. The system must store the delta every time a vehicle is detected entering or exiting a lot to keep accurate data even if the LoRa gateway cannot be reached. For example, if the power goes out, the gateway will lose power and will therefore not be able to store the data transmitted by the microcontrollers. If the data was not stored in the microcontroller in this scenario, then there would be a loss of data ultimately leading to inaccurate data.
4. The system shall be able to determine if a vehicle has entered or exited a lot based upon which GPIO pin receives a 3.3V signal. This constraint is a system requirement. If the microcontrollers cannot determine whether a car has entered or exited a lot with a high degree of accuracy, then it is useless to the system.

## Schematics
<img width="1218" alt="Basic block diagram Data Subsystem" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/0370d95e-b63c-4620-a6a8-0f01a03bab97">
<em>Figure 1. Block Diagram of Entire Subsystem</em>

<img width="1226" alt="ESP32 block diagram" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/0bb3475e-d1ad-4ddd-a575-aecfe7b7a049">
<em>Figure 2. ESP32 Block Diagram</em>

<img width="1488" alt="Network Block Diagram" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/6d3b6970-f1ab-40bd-b1b9-77c46b6871d3">
<em>Network Block Diagram</em>



## Analysis
### Data Collection
Data will be collected via the ESP WROOM 32E microcontrollers. For each vehicle detector, there will be one MCU. Each MCU will be connected to the two output relays of the vehicle detector. The 3.3V source pin of the MCU will be connected to the common terminals of each relay, and the normally open terminals of the relays will be connected to separate GPIO pins on the MCU. These pins will be GPIO36 and GPIO39. These are input-only pins, but more importantly, they are RTC pins, which means they will be able to wake the MCU up from deep sleep. GPIO36 is RTC_GPIO0 and GPIO39 is RTC_GPIO3. The MCU will be able to tell which RTC pin woke it up from sleep with the function esp_sleep_get_ext1_wakeup_status(). With the vehicle detector in pulse mode, we can determine which direction the vehicle is going. Pulse mode works by detecting vehicle presence in one of the loops first, then the second loop detecting presence while the first is still detecting presence. This means the vehicle must have crossed the first loop before the second. The detector will send a pulse to the relay corresponding to the first loop in this case. The MCU will wake up and since it knows the GPIO pin connected to the first loop relay is what woke it up, we also know the direction of the vehicle. Knowing the direction of the vehicle is important for keeping the delta of cars entering and exiting the lot at the point where the inductive loops lay in the road. A positive delta means more vehicles have entered than exited, negative means more have exited than entered. The delta value will incremented for vehicles entering the lot and decremented for vehicles leaving the lot. This updated value for the delta will be transmitted using the RFM95W LoRa transceiver to the LoRaWAN gateway. The delta value will also be stored in nonvolatile storage so that the MCU can go back to deep sleep. With this in mind, the MCU should be in deep sleep the majority of the time, only waking up long enough to update the delta, transmit it, and store it. This will lead to a much lower power consumption compared to leaving the MCU in active mode at all times when it is not necessary.

### Data Transmission

### Data Storage

## BOM


## References
"Electronic Code of Federal Regulations," Title 47-Telecommunication, CHAPTER I-FEDERAL COMMUNICATIONS COMMISSION, SUBCHAPTER A-GENERAL, PART 15-RADIO FREQUENCY DEVICES, Subpart C-Intentional Radiators, Radiated Emission Limits, Additional Provisions, Section 15.247 Operation within the bands 902-928 MHz, 2400-2483.5 MHz, and 5725-5850 MHz. https://www.law.cornell.edu/cfr/text/47/15.247
