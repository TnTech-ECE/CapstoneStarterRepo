# Wireless Communication Subsystem

## Functionality- 
The function of the wireless communication subsystem is to wirelessly transport data from the computing system to the user interface subsystem quickly and over a long distance. 

## Constraints- 
| Constraint | Source |
|------------|--------|
| 1. The system shall be able to communicate with the computing subsystem from a minimum distance of 700-meters| Analyzed from DARPA's constraints |
| 2. The system shall send the results from the computing subsystem to user interface subsystem in close to real time | From DARPA's constraints [1] |
| 2. The system shall send results from the computing subsystem to user interface subsystem at a maximum time of two seconds | Analyzed from DARPA's constraints |
| The entire system shall weigh less than six pounds| From conceptual design |

## Schematic- 

![Schematic1024_1](https://user-images.githubusercontent.com/123600489/232377903-567137f6-7f32-414b-8319-172e8f5472d3.jpg)

## Analysis-
1. Within DARPA’s given constraints, they do not specify a minimum distance that the drone and sensing system can be away from the user interface. Since the distance is not specified by DARPA, the distance will be chosen based on how far and fast the drone chosen in the conceptual design will be able to travel in a specific area of space. While the drone has a max payload of six pounds, it has a battery life of thirty minutes and a max speed of approximately 10 meters per second while also taking wind resistance into consideration. Taking all of these factors into consideration, the maximum distance that the drone can be away from the command center or user interface while covering a large area and being able to return to the command center to recharge its batteries will be around 700 meters. This distance will be the chosen minimum distance that the sensing system can be away while still communicating with the user interface using wireless communication methods. The wireless communication method that will be chosen for this project shall be radio frequency. This will be accomplished by a radio frequency module that is compatible with the jetson nano, which will be the computing system of the project. The computing system will have a NRF24L01+ transceiver module attached to it. With an antenna which is provided, the range of this transceiver is 800+ meters line of sight, which fulfills the constraint of a minimum 700-meter distance [2].

2. Within DARPA’s given constraints, they do not specify a specific minimum time that the sensing subsystem can communicate with the user interface, all that is stated is that it must be close to real time [1]. The data that will be sent from the computing system to the user interface will be composed of measurements obtained from the sensing subsystem as well as a simple graphic that displays the START status of a person. This data will most likely hold a data size of at least several kilobytes. The radio frequency module chosen for this project has a minimum data rate of 250 kbps and a maximum data rate of 2 Mbps [2]. Using this radio frequency module with a minimum data rate of 250 kbps,  the data from the computing subsystem will be able to reach the user interface subsystem within the two second minimum time frame specified in the constraints.

3. One of DARPA’s constraints is that the entire sensing system and drone must weigh less than twenty pounds in total [1]. After choosing a specific drone and calculating the allotted weight that the team has, the entire sensing system as a whole must weigh less than six pounds. The weight of the NRF24L01+PA+LNA radio frequency module including the antenna that will be attached to the sensing system weighs 13.28 grams or 0.0293 pounds [2]. This light weight load of this component will have little affect on the overall weight of the system.

## BOM-

1. MakerFocus 2pcs NRF24L01+PA+LNA RF Transceiver Module 2.4G 1100m with Antenna - $9.99
2. Microchip Technology ADM00419-ND - $38.64
3. Laptop - $0 – provided

Total – approximately $50.00

## Sources- 

[1] “DARPA Triage Challenge,” Sam.gov. [Online]. Available: https://sam.gov/opp/9f3fdae8285e44aabdeb0a9c3dfd6c17/view. [Accessed: 28-Feb-2023]. 

[2] “MakerFocus 2pcs NRF24L01+PA+LNA RF transceiver module 2.4G 1100m with antenna,” MakerFocus. [Online]. Available: https://www.makerfocus.com/products/2pcs-nrf24l01-pa-lna-rf-transceiver-module-2-4g-1100m-with-antenna?_pos=1&_sid=d25c037e2&_ss=r. [Accessed: 13-Apr-2023]. 
