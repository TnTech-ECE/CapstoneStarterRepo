# Bluetooth Communication Subsystem

## Function of the Subsystem

##### Pseudo-Code Flowchart
<img src="/Documentation/Images/Bluetooth-Communication/Conceptual/ArduinoComm.png" width="60%" height="60%">

The function of this subsystem is to connect the main processor subsystem to the machine learning subsystem wirelessly.

## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | System shall be powered by standard 60 Hz, 120 V wall outlets         | Design Constraint |
| 2   | Shall be able to send and receive at least 16-bit data reliably with the machine learning <br>subsystem through wireless signals| Design Constraint |
| 3   | Shall be able to send and receive at least 16-bit data from the main processor subsystem | Design Constraint | 
| 4   | Shall be able to send audio data and receive filter data (a full cycle) within a 2 second frame | Design Constraint |
| 5   | Bluetooth's range must reach anywhere in the room                     | Design Constraint |
| 6   | Shall not store audio data after processing                           | Ethics Constraint |
| 7   | Shall encrypt any data sent wirelessly                                | Ethics Constraint |
| 8   | Must not add any physical obstructions through the walking area of the room       | Ethics Constraint |

<sup>1</sup> In order to create a system that can run for long periods of time, the system must be able to be powered by the 60 Hz, 120 V wall outlets in the room. This would eliminate the need for batteries which could drain.

<sup>2</sup> Each window will require at least one DSP board in order to allow speedy calculations. Since the machine learning aspect of the adapting algorithm is computationally expensive, data is passed between the main processor subsystem and the machine learning subsystem. Thus, the 16-bit audio data and 16-bit filter data must be shared between the system. The machine learning subsystem can be anywhere within the room. Tt must be transmitted wirelessly therefore in order to not impede accessibility.

<sup>3</sup> The Bluetooth connection subsystem will have the function of connecting the DSP board to external peripherals. This will allow the DSP board to focus on the time dependent task of filtering and negating the input sound. Thus the Bluetooth Connection subsystem must be able to send and receive the same data as the machine learning subsystem.

<sup>4</sup> The machine learning subsystem's purpose is not to solve the "optimum" filter, but to choose from a set of pre-trained filters as a "good" starting point for the adaptive algorithm. "Good" is defined loosely as a filter approximately optimum such that the adaptive algorithm could reach theoretical optimum magnitudes faster than at the current filter starting point.

This subsystem is not held by the 1.4 ms time constraint of the main processing subsystem. This is because the adaptive filter is executed locally on the main processing subsystem. The machine learning subsystem receives samples from the current 2 second period, decides on the pre-trained filter, and sends the corresponding filter coefficients back to the main processing subsystem. In order to get the most up to date filter coefficients from the machine learning subsystem, the bluetooth subsystem must be able to complete a full cycle of data transfer within an arbitrary amount of seconds. The amount of time is a balance between accuracy and speed.

<sup>5</sup> Since the machine learning subsystem is ran on a personal laptop, the system must be in range to communicate. The laptop's location will be restricted to inside our target room.

<sup>6</sup> In order to create a system that does not invade the privacy of the students and teachers in the room, the system will not store any sound data after it is used in processing. This will prevent the system from possibly storing private conversations that could be breached.

<sup>7</sup> In order to create a system that does not invade the privacy of the students and teachers in the room, the system must encrypt any sound data sent wirelessly. This will help protect sound data from being easily broadcasted and received outside of the room.

<sup>8</sup> The system has to communicate with the machine learning subsystem wirelessly in order to eliminate any need for wires or cables across the room. This removes physical obstructions in the walking area. This satisfies the accessibility ethics constraint.

## Buildable schematic

![image](/Documentation/Images/Bluetooth-Communication/Buildable-Schematics/BluetoothComm_Schem_Rev2.PNG)  

The above image is a schematic of the Arduino UNO R4 WiFi, the schematic focuses on the most important aspects of the device with respect to the overall design goal. The schematic also shows how the system connects to the main processor subsystem and power management subsystem. 

## Analysis

#### Power
The system can be powered through a USB connection or through the onboard barrel jack connector[1]. The recommended input voltage for the external power supply is 6-24 V. The subsystem will use the included AC/DC adapter as its power supply. This adapter can be plugged into standard 120V 60Hz power<sup>1</sup>. Since the board needs to use the USB port in order to install the designed software, the subsystem will have to be programmed before being connected to the system's power supply to allow the subsystem to boot without being connected directly to a computer. 

#### Bluetooth Speed
The Arduino UNO R4 WiFi is able to transmit and receive in WiFi and Bluetooth 5 LE<sup>2</sup>. This is accomplished through the ESP32-S3-MINI[3]. Bluetooth 5.0 LE includes a PHY called LE 2M. This can support 2 Mb/s (2,000,000 bits per second). At the application layer, a data rate of up to approximately 1.4 Mb/s (1,400,000 bits per second) is possible[5]. Assuming the 2 second delay lines of 187.5 kiB [6], each send will be sending 187.5 kiB (or 1,536,000 bits). Therefore, Bluetooth 5 LE  will be able to send a full delay line in 1.10 seconds (1.536 Mb / 1.4 Mbps), and receive the filter index bits (also 187.5 kiB) in 1.10 seconds for a total of 2.20 seconds<sup>4</sup>.

#### Bluetooth Range
Since the subsystem is able to communicate wirelessly, the physical extent of the system resides at the window preventing any obstruction of pathways<sup>9</sup>. The room's dimensions are 34x24x11 feet. A worst case scenario (lower corner to opposite upper corner) is a distance of 43.05 ft (13.122 meters). The ESP32-S3-MINI has a typical Bluetooth transmit power of 0 dBm (but can be set higher) and a typical receiver sensitivity of -92 dBm. Using Bluetooth's range estimation calculator[10], the ESP32-S3-MINI has an estimated range in an office setting of 14 to 18 meters meters, which is greater than 13.122 meters<sup>5</sup>.

#### Main Processor Subsystem Connectivity
The Blackfin ADSP-BF70x EZ-KIT Mini is built for direct connectivity to an Arduino UNO or related board. The board has a corresponding through-hole for each input/output port of the Arduino UNO. It is able to directly stack on top using 0.1" header pins. The Arduino UNO R4 WiFi has the same pinout and form as the Arduino UNO R3. This will allow the main processing subsystem to communicate via SPI with the Bluetooth connection subsystem<sup>3</sup>. The Arduino SPI library will allow easier programming of the communication. 

#### Encryption
The Arduino UNO R4 WiFi uses the ESP32-S3[1]. It supports AES-XTS-based flash encryption, RSA-based secure boot, digital signature and HMAC<sup>7</sup>. After a full cycle, all data will be written over<sup>6</sup>.

## BOM
| DEVICE                | Quantity | Price Per Unit | Total Price |
| --------------------- | -------- | -------------- | ----------- |
| Arduino UNO R4 WiFi   | 1        | $27.50         |             |
| Arduino Shield Pins   | 1        | $1.75          | $29.25      |

## References

[1] “Arduino® Uno R4 WIFI,” Arduino Online Shop, https://store-usa.arduino.cc/products/uno-r4-wifi?selectedStore=us (accessed Sep. 9, 2023). 

[2] Renesas Electronics, "32-bit MCU, Renesas Advanced (RA) Family, Renesas RA4 Series," R7FA4M1AB3CFM#AA0 datasheet, Oct 2019.

[‌3] Espressif Systems, “ESP32-S3-MINI-1, ESP32-S3-MINI-1U,” ESP32-S3-MINI-1 datasheet, May. 2022 [Revised Mar. 2023].

[4] “Bluetooth® Core Specification version 5.0 feature enhancements,” Bluetooth® Technology Website, https://www.bluetooth.com/bluetooth-resources/bluetooth-5-go-faster-go-further/ (accessed Sep. 9, 2023). 

[5] [Link to Main Proccessor Subsystem](/Documentation/Signoffs/Main_Processor.md)

[6] [Link to Machine Learning Subsytem {Broken Link until signoff is done}](/Documentation/Signoffs/)

[7] [Link to Power Management Subsytem {Broken Link until signoff is done}](/Documentation/Signoffs/)

[8] “Powering Alternatives for Arduino Boards | Arduino Documentation,” docs.arduino.cc. https://docs.arduino.cc/learn/electronics/power-pins

[9] “Understanding Bluetooth Range,” Bluetooth® Technology Website. https://www.bluetooth.com/learn-about-bluetooth/key-attributes/range/

[10] Z. Luo, D. Shi and W. -S. Gan, "A Hybrid SFANC-FxNLMS Algorithm for Active Noise Control Based on Deep Learning," in IEEE Signal Processing Letters, vol. 29, pp. 1102-1106, 2022, doi: 10.1109/LSP.2022.3169428.

[11] Construction noise and vibration impact on sensitive premises, https://www.acoustics.asn.au/conference_proceedings/AAS2009/papers/p11.pdf (accessed Sep. 10, 2023). 

[12] R. V. Cox, S. F. De Campos Neto, C. Lamblin and M. H. Sherif, "ITU-T coders for wideband, superwideband, and fullband speech communication [Series Editorial]," in IEEE Communications Magazine, vol. 47, no. 10, pp. 106-109, October 2009, doi: 10.1109/MCOM.2009.5273816.
