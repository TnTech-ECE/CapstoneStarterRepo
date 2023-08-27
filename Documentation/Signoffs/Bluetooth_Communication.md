# Processing Subsystem

## Function of the Subsystem

The goal of this subsystem is to 

## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | System shall be powered by standard 60 Hz, 120 V wall outlets         | Design Constraint |
| 2   | Shall be able to transmit and receive FIR filter coefficients<br> with the machine learning subsystem through Bluetooth wireless signals| Design Constraint |
| 3   | Shall be able to send and receive serial FIR filter coefficients<br> with the main processor subsystem through the SPI standard | Design Constraint |
| 4   | Shall hold at least 2 seconds of samples from the main processor subsystem                   | Design Constraint |
| 5   | Shall not store audio data after processing                           | Ethics Constraint |

<sup>1</sup> In order to create a system that can run for long periods of time, the system must be able to be powered by the 60 Hz, 120 V wall outlets in the room. This would elimate the need for batteries which could drain.

<sup>2</sup>

<sup>3</sup>

<sup>4</sup>

<sup>5</sup>


## Buildable schematic

![image](/Documentation/Images/Main-Processor/Buildable-Schematics/)  

The above image is a schematic of the Arduino Uno WiFi REV2, the schematic focuses on the most important aspects of the device with respect to the overall design goal. The schematic also shows how the system connects to the main processor subsystem. 

## Analysis

#### Main Processor Subsystem Connectivity

#### Machine Learning Subsystem Connectivity {Will update when referenced Subsystem is complete}

#### Power
The system can be powered through USB connection or supplied to the Vin port. The system can be powered from wall power through the power supply subsystem to the Vin pin.<sup>1</sup>. USB 2.0 interfaces run off of 5 volts and have a max current draw of 500 mA, for a max power draw of 2.5 Watts. Since the board needs to use the USB port in order to install the designed software, the subsystem will have to be programmed before being connected to the system's power supply to allow the subsystem to boot without being connected directly to a computer. 

## BOM
| DEVICE                | Quantity | Price Per Unit | Total Price |
| --------------------- | -------- | -------------- | ----------- |
| ARDUINO UNO WiFi REV2 | 2        | $53.80         | $107.6      |

## References

[1] “ARDUINO UNO WiFi REV2,” Arduino Online Shop. https://store-usa.arduino.cc/products/arduino-uno-wifi-rev2?selectedStore=us

[2] “ATmega4808/4809 ATmega4808/4809 Data Sheet.” Available: https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/ATmega4808-09-DataSheet-DS40002173C.pdf

[3] “NINA-W10 series Stand-alone Multiradio modules Data sheet.” Available: https://content.arduino.cc/assets/Arduino_NINA-W10_DataSheet_%28UBX-17065507%29.pdf

[10] [Link to Main Proccessor Subsystem](/Documentation/Signoffs/Main_Processor.md)

[10] [Link to Machine Learning Subsytem {Broken Link until signoff is done}](/Documentation/Signoffs/)
