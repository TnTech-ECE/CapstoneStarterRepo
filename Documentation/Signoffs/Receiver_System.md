# Receiver System 
## Functionality
The Receiver system will be responsible for receiving and unpacking Remote ID (RID) data to be sent by the network to the database. This sub-system shall be composed of a singular antenna along with a microprocessor and storage drive that will decode, package, and transmit/store the received data to the networked database to be used by the remainder of the system.
## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | Shall only need to receive information within the frequency bands of 2.4 GHz and 5.8 GHz. | Design Constraint|
|  2 | Shall only unpack and read data from the RID signal | Ethical Constraint       |                          
|  3 | Shall store the data for 90 days    |  TTU Police  |   
|  4 | Shall receive data from RID emitting drones | Design Constraint |
|  5 | Shall track drones on the contiguous TTU campus | TTU Police |
|  6 | Shall receive signals from a minimum radius of 600 meters | Design Constraint |


<sup>1</sup> According to research done on drone tracking and radio frequency emission, there are three different drone detection cases. In each case, the frequency band used was either between 2.4 Ghz or 5.8 Ghz ISM bands [^6].   

<sup>2</sup> If the receiver reads data that is not the RID signal, it could be considered a privacy concern.

<sup>3</sup> TTU police would like the data to be stored for 90 days for records purposes.

<sup>4</sup> If the drone is not emitting the RID signal, the receiver will not be able to pick it up.

<sup>5</sup> The campus police are only concerned about drones flying on the contiguous Tech campus.

<sup>6</sup> The signal receiver has a minimum detection radius of 600 meters.

## Schematic
![image](https://github.com/mrnye42/Drone-Tracker-Project/assets/113947428/0d1d1ad6-30ce-4065-8f34-d38c02ce6f21)





## Analysis
### Antenna
The software defined radio (SDR) we will be utilizing is the HackRF One and purchasing an ANT-W63WS1-SMA as an antenna for the device. We need an SDR that is compatible with GNU Radio because GNU is open source, free, and the team has familiarity with it. GNU also needs to be used to amplify weaker signals to increase the Rx gain of the receiver subsystem and tell the radio what signals to receive. The HackRF One is the cheapest SDR available that is compatible with GNU Radio and is able to receive the maximum RF frequency output by the drone, 5.8 GHz WiFi [^7]. The HackRF One is also able to pick up the minimum frequency emitted by the drone at 2.4 GHz Wifi and Bluetooth [^8]. The ANT-W63WS1-SMA is the antenna picked for the SDR because its designed for receiving both WiFi frequency signals and the Bluetooth frequency [^2]. This means the antenna is also omnidirectional and its other specifications are sufficient for the price [^4]. Based on the data gathered on the transmitted signal, we were able to find a minimum dBm gain transmitted by the drone for all three signal types [^1]. Other assumptions had to be made about the gain of the Tx antenna gain and the receiver sensitivity of the antenna based on the standard practice. Based on these assumptions and link budget calculations this design will be able to cover the maximum range of 600 m on the contiguous campus.
P<sub>Rx</sub> = P<sub>Tx</sub> + G<sub>Tx</sub> - L<sub>Tx</sub> - L<sub>fs</sub> + G<sub>Rx</sub> - L<sub>Rx</sub>
### Microprocessor
The microprocessor being used will be a Raspberry Pi 5 because of its low cost and speed. The Raspberry Pi is compatible with GNU Radio and will be able to run a python script continuously. We will be using Python to decide what is done with the data received by the SDR. The Python script will decide what to do with the signals received by verifying the way the RID signal is packaged. RID signals may have the same frequency as Bluetooth and WiFi, but the way the data is packaged is different [^1]. An if statement will then send the data over to the camera and database subsystems for the drone to be considered detected. 
### Storage Drive
The amount of data being transmitted in the RID package is 25 bytes in length. The RID signal is broadcasted by the drone at a minimum rate of 1 Hz [^1]. If the data must be stored for a maximum of 90 days, a 16 Gb flash drive will be able to handle storing the RID data from 15 drones continously emmitting the RID signal at a 5 Hz rate. Since a 16 Gb flash drive is cheap and capable it is the chosen method of ensuring that the RID data is available for the Tech police for up to 90 days.

## BOM
#### All prices listed are in USD
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|HackRF One [^9]        |3583             |1          |$339.95            |$339.95            |
|Raspberry Pi 5 [^10]         |8GB-9028             |1          |$80.00                |$80.00            |
|microHDMI to HDMI cable [^11]         |633696492882            |1          |$8.95                |$8.95            |
|ANT-W63WS1-SMA [^12]         |712-ANT-W63WS1-SMA             |1          |$12.27                |$12.27            |
|SanDisk 16GB Ultra USB 3.0 Flash Drive [^13]  |  SDCZ48-016G-GAM46    |     1     |   $8.40             |     $8.40       |
|Total     |             |   5       |                |   $449.57         |


## References and Links
[^1]: "Standard specification for remote ID and tracking designation - F3411 - 19," ASTM International, (2019).

[^2]: J. Marcel, “3 key factors that determine the range of bluetooth,” Bluetooth® Technology Website, https://www.bluetooth.com/blog/3-key-factors-that-determinethe-range-of-bluetooth/ (accessed Apr. 3, 2024). 

[^4]: S. Cerwin, Radio Propagation and Antennas: A Non-Mathematical Treatment of Radio and Antennas. Bloomington, IN: AuthorHouse, 2019. 

[^6]: D. Aouladhadj et al., “Drone detection and tracking using RF Identification Signals,” National Center for Biotechnology Information, https://www.ncbi.nlm.nih.gov/pmc/articles/PMC10490811/ (accessed Apr. 3, 2024). 

[^7]: M. Ossmann, “Greatscottgadgets/hackrf: Low cost software radio platform,” GitHub, https://github.com/greatscottgadgets/hackrf (accessed Apr. 3, 2024). 

[^8]: “Welcome to hackrf’s documentation!,” Welcome to HackRF’s documentation! - HackRF documentation, https://hackrf.readthedocs.io/en/latest/ (accessed Apr. 3, 2024). 

[^9]: https://www.adafruit.com/product/3583
[^10]: https://www.pishop.us/product/raspberry-pi-5-8gb/?src=raspberrypi
[^11]: https://www.pishop.us/product/micro-hdmi-to-standard-hdmi-a-m-2m-cable-black/
[^12]: https://www.mouser.com/ProductDetail/TE-Connectivity-Linx-Technologies/ANT-W63WS1-SMA?qs=81r%252BiQLm7BRk7ZBsbgmcew%3D%3D&utm_source=octopart&utm_medium=aggregator&utm_campaign=712-ANT-W63WS1-SMA&utm_content=TE+Connectivity&TETID=LnmBpHNgVr
[^13]: https://www.amazon.com/SanDisk-256GB-Ultra-Flash-Drive/dp/B081QSX1M5/ref=asc_df_B081QSHG1K/?tag=hyprod-20&linkCode=df0&hvadid=459410835726&hvpos=&hvnetw=g&hvrand=9423232362259022858&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1025954&hvtargid=pla-890104531595&mcid=a47a478b7c513e0f85caae62028ebb4b&gclid=CjwKCAjw_LOwBhBFEiwAmSEQAQtWChgfWAVDCBFGj-Oq49ku2rOxcPK86G5gFl3ynmqLBhmZR-aUABoCx60QAvD_BwE&th=1
