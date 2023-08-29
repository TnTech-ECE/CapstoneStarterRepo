# Bluetooth Communication Subsystem

## Function of the Subsystem

The function of this subsystem is to connect the main processor subsystem to the machine learning subsystem wirelessly.

## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | System shall be powered by standard 60 Hz, 120 V wall outlets         | Design Constraint |
| 2   | Shall be able to transmit and receive FIR filter coefficients<br>with the machine learning subsystem through Bluetooth wireless signals| Design Constraint |
| 3   | Shall be able to send and receive serial audio samples<br> with the main processor subsystem through the SPI standard | Design Constraint |
| 4   | Shall hold at least 2 seconds of samples from the main processor subsystem                   | Design Constraint |
| 5   | Shall not store audio data after processing                           | Ethics Constraint |
| 6   | Shall encrypt any data sent wirelessly                                | Ethics Constraint |
| 7   | Must not add any physical obstructions through the walking area of the room       | Ethics Constraint |

<sup>1</sup> In order to create a system that can run for long periods of time, the system must be able to be powered by the 60 Hz, 120 V wall outlets in the room. This would eliminate the need for batteries which could drain.

<sup>2</sup> Each window will require at least one DSP board in order to allow speedy calculations. Since the machine learning aspect of the adapting algorithm is computationally expensive, data is passed between the main processor subsystem and the machine learning subsystem. The system therefore must send data to the machine learning subsystem through Bluetooth or WiFi.

<sup>3</sup> Each window will require at least one DSP board in order to allow speedy calculations. Since the machine learning aspect of the adapting algorithm is computationally expensive, data is passed between the main processor subsystem and . The bluetooth connection subsystem will have the function of connecting the DSP board to external peripherals through bluetooth. This will allow the DSP board to focus on the time dependent task of filtering and negating the input sound.

<sup>4</sup>The complete system operates using digital filters. These filters require arrays of previous samples in order to account for the acoustical impulse response of the room. Approximate impulse responses of the room were simulated which showed the majority of the impulse responses power should have decayed by 2 seconds [8]. *insert how we do the machine learning program.

<sup>5</sup> In order to create a system that does not invade the privacy of the students and teachers in the room, the system will not store any sound data after it is used in processing. This will prevent the system from possibly storing private conversations that could be breached.

<sup>6</sup> In order to create a system that does not invade the privacy of the students and teachers in the room, the system must encrypt any sound data sent wirelessly. This will help protect sound data from being easily broadcasted and received outside of the room.

<sup>7</sup> The system has to communicate with the machine learning subsystem wirelessly in order to eliminate any need for wires or cables across the room. This removes physical obstructions in the walking area. This satisfies the accessibility ethics constraint.

## Buildable schematic

![image](/Documentation/Images/BluetoothCommunication/Buildable-Schematics/)  

The above image is a schematic of the Arduino Uno WiFi REV2, the schematic focuses on the most important aspects of the device with respect to the overall design goal. The schematic also shows how the system connects to the main processor subsystem and power management subsystem. 

## Analysis

#### Main Processor Subsystem Connectivity
The Blackfin ADSP-BF70x EZ-KIT Mini is built for direct connectivity to an Arduino UNO or related board. The board has a corresponding through-hole for each input/output port of the Arduino UNO. It is able to directly stack on top using 0.1" header pins. The Arduino Uno WiFi Rev2 has the same pinout dimensions as the Arduino UNO R3. This will allow the main processing subsystem to communicate via SPI with the Bluetooth connection subsystem<sup>3</sup>.

#### Machine Learning Subsystem Connectivity {Will update when referenced Subsystem is complete}
The system is able to transmit and receive in both WiFi and Bluetooth<sup>2</sup>.

#### Power
The system can be powered through a USB connection or through the onboard barreljack connector[1]. <sup>1</sup>. The recommended input voltage and current rating for the external power supply are 7-12V and 1.5A [8]. The subsystem will use the included AC/DC adapter as it's power supply. Since the board needs to use the USB port in order to install the designed software, the subsystem will have to be programmed before being connected to the system's power supply to allow the subsystem to boot without being connected directly to a computer. 

#### Memory

#### Encryption

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
‌
[5] [Link to Main Proccessor Subsystem](/Documentation/Signoffs/Main_Processor.md)

[6] [Link to Machine Learning Subsytem {Broken Link until signoff is done}](/Documentation/Signoffs/)

[7] [Link to Power Management Subsytem {Broken Link until signoff is done}](/Documentation/Signoffs/)

[8] “Powering Alternatives for Arduino Boards | Arduino Documentation,” docs.arduino.cc. https://docs.arduino.cc/learn/electronics/power-pins

[9] [Link to Simulation Results](/Documentation/Images/Main-Processor/Simulation-Results/)
