# Bluetooth Communication Subsystem

## Function of the Subsystem

##### Pseudo-Code Flowchart
<img src="/Documentation/Images/Bluetooth-Communication/Conceptual/ArduinoComm.png" width="60%" height="60%">

The function of this subsystem is to connect the main processor subsystem to the machine learning subsystem wirelessly.

## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | System shall be powered by standard 60 Hz, 120 V wall outlets         | Design Constraint |
| 2   | Shall be able to send and receive 16-bit data reliably with the machine learning <br>subsystem through wireless signals| Design Constraint |
| 3   | Shall be able to send and receive 16-bit data from the main processor subsystem | Design Constraint | 
| 4   | Bluetooth's range must reach anywhere in the room                     | Design Constraint |
| 5   | Shall not store audio data after processing                           | Ethics Constraint |
| 6   | Shall encrypt any data sent wirelessly                                | Ethics Constraint |
| 7   | Must not add any physical obstructions through the walking area of the room       | Ethics Constraint |

<sup>1</sup> In order to create a system that can run for long periods of time, the system must be able to be powered by the 60 Hz, 120 V wall outlets in the room. This would eliminate the need for batteries which could drain.

<sup>2</sup> Each window will require at least one DSP board in order to allow speedy calculations. Since the machine learning aspect of the adapting algorithm is computationally expensive, data is passed between the main processor subsystem and the machine learning subsystem. The system therefore must send the raw audio data (16 bit samples) to the machine learning subsystem and receive the trained filter coefficients (16 bits).

<sup>3</sup> The Bluetooth connection subsystem will have the function of connecting the DSP board to external peripherals. This will allow the DSP board to focus on the time dependent task of filtering and negating the input sound. Thus the Bluetooth Connection subsystem must be able to send and receive the same data as the machine learning subsystem.



<sup>5</sup> In order to create a system that does not invade the privacy of the students and teachers in the room, the system will not store any sound data after it is used in processing. This will prevent the system from possibly storing private conversations that could be breached.

<sup>6</sup> In order to create a system that does not invade the privacy of the students and teachers in the room, the system must encrypt any sound data sent wirelessly. This will help protect sound data from being easily broadcasted and received outside of the room.

<sup>7</sup> The system has to communicate with the machine learning subsystem wirelessly in order to eliminate any need for wires or cables across the room. This removes physical obstructions in the walking area. This satisfies the accessibility ethics constraint.

## Buildable schematic

![image](/Documentation/Images/Bluetooth-Communication/Buildable-Schematics/BluetoothCommSchematic.png)  

The above image is a schematic of the Arduino Uno WiFi REV2, the schematic focuses on the most important aspects of the device with respect to the overall design goal. The schematic also shows how the system connects to the main processor subsystem and power management subsystem. 

## Analysis

#### Power
The system can be powered through a USB connection or through the onboard barrel jack connector[1] <sup>1</sup>. The recommended input voltage and current rating for the external power supply are 7-12V and 1.5A [8]. The subsystem will use the included AC/DC adapter as its power supply. Since the board needs to use the USB port in order to install the designed software, the subsystem will have to be programmed before being connected to the system's power supply to allow the subsystem to boot without being connected directly to a computer. 

#### Bluetooth Capabilities
The Arduino Uno WiFi Rev2 is able to transmit and receive in WiFi and Bluetooth 4.2<sup>2</sup>. This is accomplished through the NINA-W102 Stand-alone Multiradio module [3]. Bluetooth 4.2 includes Bluetooth basic rate (BR) and enhanced data rate (EDR). Bluetooth EDR has a symbol rate of 1 
megasymbol per second (Ms/s) supporting a gross air bit rate of 2 or 3Mb/s (16,000,000 or 24,000,000 bits per second)[5]. Assuming the max 2 second delay lines and filter lengths of 187.5 kiB [6] each, each send or receive will be sending 187.5 kiB (or 1,536,000 bits). Therefore, at worst case scenario, Bluetooth EDR will be able to send a full delay in the first second, and receive a full filter in the last second. Bluetooth Basic Rate and Bluetooth Low Energy both send at 1 Mb/s (8,000,000 bits per second), which is still enough to send all data in the appropriate amount of time.

Since the subsystem is able to communicate wirelessly, the physical extent of the system resides at the window preventing any obstruction of pathways<sup>7</sup>. The room's dimensions are 34x24x11 feet. A worst case scenario (lower corner to opposite upper corner) is a distance of 43.05 ft (13.122 meters). The NINA-W102 has a typical Bluetooth transmit power of 5±1 dBm and a typical receiver sensitivity of -80±2 dBm for 3 Mbps mode. 3 Mbps mode has the worst receiver sensitivity. Using Bluetooth's range estimation calculator[10], the NINA-W102 has an estimated range indoors of 20 to 26 meters, which is greater than 13.122 meters<sup>4</sup>.

#### Main Processor Subsystem Connectivity
The Blackfin ADSP-BF70x EZ-KIT Mini is built for direct connectivity to an Arduino UNO or related board. The board has a corresponding through-hole for each input/output port of the Arduino UNO. It is able to directly stack on top using 0.1" header pins. The Arduino Uno WiFi Rev2 has the same pinout dimensions as the Arduino UNO R3. This will allow the main processing subsystem to communicate via SPI with the Bluetooth connection subsystem<sup>3</sup>. The Arduino SPI library will allow easier programming of the communication.

#### Encryption
The Arduino UNO WiFi Rev2 comes with the ATECC608 crypto chip accelerator [1][4]. It comes with hardware support for both symmetric and asymmetric encoding schemes <sup>6</sup>. After a full cycle, all data will be written over<sup>5</sup>.

## BOM
| DEVICE                | Quantity | Price Per Unit | Total Price |
| --------------------- | -------- | -------------- | ----------- |
| ARDUINO UNO WiFi REV2 | 2        | $53.80         |             |
| 9V 1.5A AC/DC ADAPTER | 2        | $12.99         | $133.58     |

## References

[1] “ARDUINO UNO WiFi REV2,” Arduino Online Shop. https://store-usa.arduino.cc/products/arduino-uno-wifi-rev2?selectedStore=us

[2] “ATmega4808/4809 ATmega4808/4809 Data Sheet.” Available: https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/ATmega4808-09-DataSheet-DS40002173C.pdf

[3] “NINA-W10 series Stand-alone Multiradio modules Data sheet.” Available: https://content.arduino.cc/assets/Arduino_NINA-W10_DataSheet_%28UBX-17065507%29.pdf

[4] “ATECC608A,” microchip. https://www.microchip.com/en-us/product/atecc608a#document-table (accessed Aug. 28, 2023).

[5] “Core Specification 4.2 – Bluetooth® Technology Website,” www.bluetooth.com. https://www.bluetooth.com/specifications/specs/core-specification-4-2/
‌
[6] [Link to Main Proccessor Subsystem](/Documentation/Signoffs/Main_Processor.md)

[7] [Link to Machine Learning Subsytem {Broken Link until signoff is done}](/Documentation/Signoffs/)

[8] [Link to Power Management Subsytem {Broken Link until signoff is done}](/Documentation/Signoffs/)

[9] “Powering Alternatives for Arduino Boards | Arduino Documentation,” docs.arduino.cc. https://docs.arduino.cc/learn/electronics/power-pins

[10] “Understanding Bluetooth Range,” Bluetooth® Technology Website. https://www.bluetooth.com/learn-about-bluetooth/key-attributes/range/
