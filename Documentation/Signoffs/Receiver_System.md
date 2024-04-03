# Receiver System 
## Functionality
The Receiver system will be responsible for receiving and unpacking Remote ID (RID) data to be sent by the network to the database. This sub-system shall be composed of a singular antenna along with a microprocessor and storage drive that will decode, package, and transmit/store the recieved data to the networked database to be used by the remainder of the system.
## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | Only needs to receive information within the frequency bands of 2.4 GHz and 5.8 GHz. | Design Constraint|
|  2 | Shall only unpack and read data from the RID signal | Ethical Constraint       |                          
|  3 | Shall store the data for 90 days    |  TTU Police  |   
|  4 | Shall receive data from RID emitting drones | Design Constraint |
|  5 | Shall track drones on the contiguous TTU campus | TTU Police |
|  6 | Shall recieve signals from a minimum radius of 600 meters | Design Constraint |


<sup>1</sup> According to research done on drone tracking and radio frequency emission, there are three difference drone detection cases. In each case, the frequency band used was either between 2.4 Ghz or 5.8 Ghz ISM bands [^1].   

<sup>2</sup> If the reciever reads data that is not the RID signal, it could be considered a privacy concern.

<sup>3</sup> TTU police would like the data to be stored for 90 days for records purposes.

<sup>4</sup> If a drone is not emitted the RID signal, the reciever will not be able to pick up a RID signal.

<sup>5</sup> The campus police are only concerned about drones flying on the contiguous Tech campus.

<sup>6</sup> The signal reciever has a minimum detection radius of 600 meters [^2].

## Schematic

## Analysis
### Antenna

### Microprocessor

### Storage Drive

## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|          |             |          |                |            |
|          |             |          |                |            |
|          |             |          |                |            |
|          |             |          |                |            |
|          |             |          |                |            |
|Total     |             |          |                |            |

## References
[^1]: D. Aouladhadj, E. Kpre, V. Kharchouf, C. Gransart, and C. Gaquiere, “Drone detection and tracking using rf identification signals,” Sensors(Basel), vol. 23, no. 17, p. 7650, 2023.
[^2]: 
