# Networking

## Functionality
The purpose of the networking subsystem is to allow sensors to wirelessly communicate. This is a requirement as the sensor posts on may not be interconnected using wires and all connectivity must be done wirelessly. The decision is to use UDP packets transmitted using ESP8266s. The packets shall be handled over an access point which will be hosted on a Raspberry Pi. This is a simple and cheap solution that permits for low latency highspeed communication at a reasonable range.

# Constraints
* C7: The networking system shall permit the sensors in the sensor array to relay the target's detected location. 
* C13: The networking system shall have the ability to allow up to 6 input devices to communicate with each other.
* C14: The networking system shall ensure all sensors are able to communicate their data to the master device in under 100ms.
* C30: The networking system shall be robust ensuring reliable and quick connection times and minimized dropped packets. 
* C31: The networking system shall be able to work in standalone or in a master-slave configuration.
   * If a subsystem requires another board or microcontroller the networking subsystem must be able to work seperate from the board using serial communication. To reduce cost if possible the networking system shall work on the same board the subsystem uses, for example, if a subsystem will operate on an ESP8266 or Raspberry Pi the networking subsystem will use this to its advantage to remove the requirement for another device.
### Constraint Explanation
Up to six independent devices can be used in the design of the interceptor which means one sensor per sensor post. Even though each transmission will be relatively short it is very important to ensure network can handle multiple devices sending data at nearly the same time.

Time must be strictly budgeted as the projectile can complete its path in as little as 1.78 seconds, and from here 100ms has been budgeted for networking. This constrain should be trivial as any modern communication protocol is able to communicate much faster than this. The main consideration to meet this constraint is making the master device poll the communication buffer often enough.

One difficulty in many low budget communication systems is its difficulty connecting and maintaining stability. Meeting this constraint will reduce risk, resulting from technical difficulties during connections, allow the team to resolve problems more efficiently, as they would not have to repeatedly tend to the networking system. Ideally the networking system will be able to work silently and independently, and without the need for frequent intervention. 
![image](https://github.com/JTJones73/Capstone2024-Team2/assets/100542084/4bf2f6ab-f234-4ca2-bb89-3e166833ee76)

The above schematic demonstrates the two configurations of the networking subsystem both in a standalone configuration and a master slave configuration. Another method of implementing the standalone configuration is with the Raspberry Pi. The Raspberry Pi implementation requires no wiring as it is handled in software. The main Raspberry Pi will host an access point that the other networking nodes will relay the data to the launcher subsystem which hosts an access point through the Raspberry Pi. UDP packets will be sent over the network containing the necessary data to determine the target's location.

# Analysis
## Specifications
| Received  Signal | Bandwidth |
| --- | --- | 
| -92 dBm | 11 Mbps |
| -75 dBm | 54 Mbps |

source: [1]

The ESP8266 shall communicate using UDP packets over 802.11 WiFi. The packets will be handled through an access point hosted by the Raspberry Pi. The Raspberry Pi must support at least six devices to comply with C13. Raspberry Pi's can support 20-30 devices depending on the network's utilization [2].

The possible bandwidth of the ESP 8266 is dependent on the received signal which depends on the transmitter power, distance, and signal noise. The stronger the signal more bandwidth is required.

Another consideration is transmission range. To comply with C13 the networking subsystem must be able to communicate with the other six sensors; and the chosen communication protocol must be able to reach across the game board to the different sensor posts. It has been reported that ESP8266's have a range of 90 meters with the stock printed antenna [3]. This is sufficient, and provides a large margin of error in the case of noisy background signal. The exact range cannot be confirmed as it depends on the noise floor, and according to the table above the received signal must have a power of -92 dBm to operate at 11 Mbps.


A UDP packet stands for User Datagram Protocol and it is a method of sending data over network. A UDP packet is a type of IP packet that contains the source, destination, checksum, and packet length. The IP packet length is 32 bits and the UDP packet metadata is 32 bits giving a total overhead of 64 bits. The following table shows the breakdown of a UDP Packet [4].

| Data Type | Length |
| --- | --- | 
| Source Port | 16 bits |
| Destination Port | 16 bits |
| Packet Length | 16 bits |
| Checksum | 16 bits | 
| Payload | 8 bits * Packet Length | 
| Total | 64 bits + Packet Length |

The above table shows the overhead of a UDP packet. Error detection is included but there is no forward error correction, and there is no packet confirmation; as these are known limitations of the UDP protocol. The networking subsystem shall be set up to reduce that risk of a packet not being delievered by developing a confirmation system.

| Subsystem | Number of transmissions per interception | Transmissions per second | Bytes per transmission | Average Bytes per second | Serial Delay | Transmission Time | Total Time |
| --- | --- | --- | --- | --- | --- | --- | --- | 
| Projectile Path Sensor | 1 | 0.56 | 2 | 5.62 | 138.9 us | 7.27 us | 146.2 us |
| Sensor Post Velocity Sensor | 4 | 2.25 | 8 | 8.99 | 555.6 us | 0 us | 555.6 us |

The above table shows the speed bottle neck is often the serial communication. Eventhough ESP8266's opersate serial at 115200 baud, this is significantly slower than the wireless protocol. This table also shows the wirless network can deliever data much fastere than needed giving a large amount of time to other subsystems, and reducing risk. Risk is reduced by increasing reliability and increasing a margin of error. To accomidate C14 the networking subsystem must be able to communicate in under 100 ms giving a factor of safet of around 180.

# Bill of Materials
| Item | Description | Number of Units | Cost per Unit | Total |
| --- | --- | --- | --- | ---| 
| ESP8266 | The ESP8266 is a microcontroller capable of networking [5] | 6 | $7.99 | $47.94 |
| **Total** | | | | $47.94 |

# References

[1] 	"ESP8266EX Datasheet," Espressif Systems, 2023.

[2] 	"Andyroo", "Raspberry Pi Forum," 24 05 2019. [Online]. Available: https://forums.raspberrypi.com/viewtopic.php?t=241223. [Accessed 24 04 2024].

[3] 	"Stavbodik", "ESP8266 Community Forum," 09 11 2016. [Online]. Available: https://www.esp8266.com/viewtopic.php?p=57884. [Accessed 24 04 2024].

[4] 	"User Datagram Protocol UDP," Geeks For Geeks, 26 02 2024. [Online]. Available: https://www.geeksforgeeks.org/user-datagram-protocol-udp/. [Accessed 24 04 2024].

[5]   "Amazon" [Online]. Available: https://www.amazon.com/HiLetgo-Internet-Development-Wireless-Micropython/dp/B010O1G1ES. [Accessed 24 04 2024].
