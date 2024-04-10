# Database System
## Functionality
The database subsystem will store the unpackaged drone remote ID from the receiver subsystem, then provide the camera software and website subsystem their requested data.

## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | All data recevied shall be contain in cloud database storage. | TTU Campus Police |
|  2 | The database application used to store the drone remote ID shall handle real-time data streaming. | TTU Campus Police |    
|  3 | Application shall constantly request and receive data from the receiver subsystem. | Design Constraint |
|  4 | Application shall provide the data when requested by other subsystem. | Design Constraint |

<sup>1</sup> Reason for contraint 1 and why it is important
TTU campus police requested all the obtained drone remote ID data to be store in a cloud storage.

<sup>2</sup> Reason for contraint 2 and why it is important
Other Subsystem's have inputs depended on live information whenever a drone is detected whithin the campus area.

<sup>3</sup> Reason for contraint 3 and why it is important
Constantly request update for drone detection that deal with packet lost or poor network connection.

<sup>4</sup> Reason for contraint 3 and why it is important
The website and camera subsystem will request/pull data from the database subsystem whenever a drone is detected.

## Schematic

## Analysis
The following data will be pull by Website subsystem if avaiable, Drone remote ID, location/Altitude, Veloctiy, control station location/elevation, operation time mark, emergency status, Drone/Control station image. Database system will be implmented using a SQL(Structured Query Language), python and c++, and test case senarios for the Database subsystem are provided below.

## SQL, python and C++
SQL will be used to format data inside the database storage, then python or C++ will be implemented to handle the data receiving/requesting.

## Test Case Senario
<td>
    The database application will constaly request update from the receiver subsystem whether a drone is detected.\<br />
    When a drone is not detected:\\<br /> 
        Wait a certain time period before requesting another update.<br /> 
    When a drone is detected:\<br /> 
        Then following information is stored, ID, location/altitude, velocity, control station location/elvation, time mark of operation, emergency status.<br /><br />
</td>

<td>
    <p>Once a drone is detected within the campus area, the application will forward a alert to the website subsystem that will ask TTU campus police to provide Drone authroization.<br />
    When Drone operation authroization is provided:<br /> 
        Update the drone operaton authorization status.<br /> 
    When Drone operation authroization is not provided:<br /> 
        Wait a certain period then reforward another alert.<br /><br />
</td>

<td>
    Once a drone is detected within the campus area, the follwing will happen base on the frequent request from the camera software subsystem.<br />
    When a drone is not detected:<br /> 
        Reply with a negative boolean value.
    When a drone is detected:<br /> 
        The following information is forwarded, drone location/alititude, drone velocity, control station location/elvation.<br />
</td>

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
<!-- This is how to do footnotes for the references: --> 
Here is a simple footnote[^1].
[^1]: Reference 1
[^2]: Reference 2 
[^3]: Reference 3
<!--etc.-->
