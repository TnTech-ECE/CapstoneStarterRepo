# Database System
## Functionality
The database subsystem will store the unpackaged drone remote ID from the receiver subsystem, send and receive requested data from the camera software subsystem and then send relevant data to the website subsystem.
## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | All data recevied shall be contained in cloud database storage. | TTU Campus Police |
|  2 | The database application used to store the drone remote ID shall handle real-time data streaming. | TTU Campus Police |    
|  3 | Application shall constantly request and receive data from the receiver subsystem. | Design Constraint |
|  4 | Application shall provide the data when requested by another subsystem. | Design Constraint |

<sup>1</sup> 
The TTU campus police requested all the obtained drone remote ID data to be stored in cloud storage.

<sup>2</sup> 
Other subsystems have inputs dependent on live information whenever a drone is detected whithin the campus area.

<sup>3</sup> 
Constantly requesting updates for drone detection will ensure that possible packet lost or poor network connection related issues are caught early. It will also ensure that the data supplied to the cloud is current. 

<sup>4</sup> 
The website and camera subsystem will request/pull data from the database subsystem whenever a drone is detected.

## Schematic
![image](https://github.com/mrnye42/Drone-Tracker-Project/assets/113947428/3ba8fc14-7e0f-4cbe-b26b-8a761d125e5b)
![image](https://github.com/mrnye42/Drone-Tracker-Project/assets/113947428/fab463f7-9778-4e9d-abe5-add71418a55c)

## Analysis
The following data will be pulled by the Website subsystem if available: Drone remote ID, location/Altitude, Velocity, control station location/elevation, operation time mark, emergency status, and Drone/Control station image. The Database system will be implemented using a SQL(Structured Query Language), python and c++. Test case senarios for the Database subsystem are provided below.

## SQL, python and C++
SQL will be used to format the data inside of the database storage, then, python or C++ code will be implemented to handle the data receiving/requesting.

## Test Case Senario
The database application will constantly request updates from the receiver subsystem whether a drone is detected or not.<br />  
When a drone is not detected: Wait a certain time period before requesting another update.<br /> 
When a drone is detected: Then the following information is stored: ID, location/altitude, velocity, control station location/elvation, time mark of operation, and emergency status.<br /><br />

When a drone is detected within the campus area, the application will forward an alert to the website subsystem that will ask TTU campus police to provide the drone authorization.<br />
When Drone operation authorization is provided: Update the drone operaton authorization status.<br /> 
When Drone operation authorization is not provided: Wait a certain period then reforward another alert.<br /><br />

When a drone is detected within the campus area, the following will happen based on the existance of a request from the camera software subsystem.<br />
When a drone is not detected: Reply with a negative boolean value.<br /> 
When a drone is detected: The following information is forwarded: drone location/altitude, drone velocity, and control station location/elvation.<br />

## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
| Cloud server | N/A | 1 | N/A | N/A |
|Total     |             |          |                |            |

## References
<!-- This is how to do footnotes for the references: --> 
[^1]: “ASTM F34111-22a,” Standard Specification for Remote ID and Tracking, https://cdn.standards.iteh.ai/samples/112830/71297057ac42432880a203654f213709/ASTM-F3411-22a.pdf (accessed Apr. 11, 2024). 
<!--etc.-->
