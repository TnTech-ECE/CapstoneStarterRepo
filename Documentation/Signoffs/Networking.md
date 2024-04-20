# Networking

## Functionality
The purpose of the networking subsystem is to allow the sensors to wirelessly communicate. This is a requirement as the sensor posts on may not be interconnected using wires and all connecvtivlity must be done wirelessly. The decision is to use UDP packets transmistted using ESP8266s. The packets shall handled over an access point which will be hosted on a Rapsberry Pi. This is a simple and cheap soloution that permits for low latency highspeed communication at a reasonable range.

# Constraints
* C7: The networking system shall permit the sensors in the sensor array to relay the target's detected location. 
* C13: The networking system shall have the ability to allow up to 6 input devices to communicate with each other.
* C14: The networking system shall ensure all sensors are able to communicate their data to the master device in under 100ms.
* C30: The networking system shall be robust ensuring reliable and quick connection times and minimized dropped packets. 
* C31: The networking system shall be able to work in standalone or in a master-slave configuration.
### Constraint Explanation
Up to six independent devices can be used in the design of the intercept which means one sensor per sensor post. Even though each transmission will be relatively short it is very important to ensure network can handle multiple devices sending data at nearly the same time.

Time must be strictly budgeted as the projectile can complete its path in as little as 1.78 seconds, and from here 100ms has been budgeted for networking. This constrain should be trivial as any modern communication protocol is able to communicate much faster than this. The main consideration to meet this contraint is making the master device poll the communication buffer often enough.

One difficulty in many low budget communication systems is its difficulty connecting and maintaining stability. Meeting this constraint will reduce risk, resulting from technical difficulties during connections, allow the team to resolve problems more efficently, as they would not have to repeatedly tend to the networking system. Ideally the networking system will be able to work silently and independently, and without the need for frequent intevention. 

# Analysis
## Specifications
| Recieved Signal | Bandwidth |
| -92 dbm | 11 Mbps |
| -75 dbm | 54 Mbps |

source: []

The possible bandwidht of the ESP 8266 is dependent on the recieved signal which depends on the transmitter power, distance, and signal noise. The stronger the signal more bandwidth is required.

| Subsystem | Number of tranmissions per intereption | Transmissions per second | Bytes per transmission | Bytes per second |

The ESP 8266 shall communicate using UDP packets over 802.11 WiFi. The packets will be handled through an access point hosted by the Raspberry Pi. The Raspberry Pi must support at least six devices to comply with C13. Raspberry Pi's can support 20-30 devices depending on the network's utilization [].


