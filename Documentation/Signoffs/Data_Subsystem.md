#Data Subsystem

##Function of the Subsystem
The data subsystem is responsible for the collection, transmission, and storage of data. Data will be collected by ESP WROOM 32E microcontrollers (one per loop detector). The microcontrollers will transmit the data they have collected with RFM95W LoRa transceivers to the LoRaWAN gateway. The LoRaWAN gateway uses the RAK2287 concentrator module to receive the LoRa packets. The concentrator module is connected to a Raspberry Pi 4 Model B via the RAK5146 PiHAT, which sits atop the Raspberry Pi and is connected with the GPIO pins. The PiHAT sends LoRaWAN packets to the Raspberry Pi, which will act as the LoRaWAN gateway. 

##Constraints


##Schematics


##Analysis


##BOM
