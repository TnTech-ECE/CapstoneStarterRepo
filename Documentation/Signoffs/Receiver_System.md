# Receiver System 
## Functionality
The Receiver system will be responsible for receiving and unpacking Remote ID (RID) data to be sent by the network to the database. This sub-system shall be composed of a singular antenna along with a microprocessor and storage drive that will decode, package, and transmit/store the received data to the networked database to be used by the remainder of the system.
## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | Only needs to receive information within the frequency bands of 2.4 GHz and 5.8 GHz. | Design Constraint|
|  2 | Shall only unpack and read data from the RID signal | Ethical Constraint       |                          
|  3 | Shall store the data for 90 days    |  TTU Police  |   
|  4 | Shall receive data from RID emitting drones | Design Constraint |
|  5 | Shall track drones on the contiguous TTU campus | TTU Police |
|  6 | Shall receive signals from a minimum radius of 600 meters | Design Constraint |


<sup>1</sup> According to research done on drone tracking and radio frequency emission, there are three different drone detection cases. In each case, the frequency band used was either between 2.4 Ghz or 5.8 Ghz ISM bands [^1].   

<sup>2</sup> If the receiver reads data that is not the RID signal, it could be considered a privacy concern.

<sup>3</sup> TTU police would like the data to be stored for 90 days for records purposes.

<sup>4</sup> If the drone is not emitting the RID signal, the receiver will not be able to pick it up.

<sup>5</sup> The campus police are only concerned about drones flying on the contiguous Tech campus.

<sup>6</sup> The signal receiver has a minimum detection radius of 600 meters [^2].

## Schematic

## Analysis
### Antenna

### Microprocessor

### Storage Drive

## BOM
#### All prices listed are in USD
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|HackRF One         |3583             |1          |$339.95            |$339.95            |
|Raspberry Pi 5          |8GB-9028             |1          |$80.00                |$80.00            |
|microHDMI to HDMI cable          |633696492882            |1          |$8.95                |$8.95            |
|ANT-W63WS1-SMA          |712-ANT-W63WS1-SMA             |1          |$12.27                |$12.27            |
|INSERT STORAGE DRIVE HERE  |             |          |                |            |
|Total     |             |          |                |            |

Links\
HackRF One (https://www.adafruit.com/product/3583) \
Raspberry Pi 5(https://www.pishop.us/product/raspberry-pi-5-8gb/?src=raspberrypi) \
microHDMI to HDMI (2m) (https://www.pishop.us/product/micro-hdmi-to-standard-hdmi-a-m-2m-cable-black/) \
ANT-W63WS1-SMA (https://www.mouser.com/ProductDetail/TE-Connectivity-Linx-Technologies/ANT-W63WS1-SMA?qs=81r%252BiQLm7BRk7ZBsbgmcew%3D%3D&utm_source=octopart&utm_medium=aggregator&utm_campaign=712-ANT-W63WS1-SMA&utm_content=TE+Connectivity&TETID=LnmBpHNgVr)

## References
[^1]: D. Aouladhadj, E. Kpre, V. Kharchouf, C. Gransart, and C. Gaquiere, “Drone detection and tracking using rf identification signals,” Sensors(Basel), vol. 23, no. 17, p. 7650, 2023.
[^2]: 
