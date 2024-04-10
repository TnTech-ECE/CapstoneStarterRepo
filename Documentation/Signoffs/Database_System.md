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
