# Camera Software System
## Functionality
The camera software system will be reponsible for controlling the camera hardware system, ensuring that the system is able to accurately take an image of an UAS in-flight or the UAS pilot and save it to the database for usage by campus police.
## Constraints
| No.| Contraint | Origin |
| -- | --------- |--------|
|  1 | Shall reliably capture an image of an UAS in-flight or the UAS pilot | Project Proposal |
|  2 | Shall only attempt to capture a quality image of the UAS | Tech Police |
|  3 | Shall limit the number of redundant pictures taken | Design Constraint |  
|  4 | If information is limited or unfeasable, a picture will not be taken | Tech Police |
             
<sup>1</sup> Reliably capturing an image of the unauthorized UAS will assist the Tech Police in regulating Tech Policy 190 [^1].

<sup>2</sup> Image usability is important, and the Tech Police will not be able to use a low quality image.

<sup>3</sup> Reducing redundant pictures will save space in the database.

<sup>4</sup> This constraint accounts for situations where the RID signal does not contain all of the neccessary information or the data tranfer encounters an error that corrupts the data. In both situations, the system should ignore the data and not take a picture, as that image will be unusable to the Tech Police. 

## Schematic

## Analysis
### Coding Language
The software system will utilized the arduino specified in the camera hardware system. Arduino uses a variant language of C++, therefore all code for this system will be in the C++ language using the arduino specific methods and functions as needed.
### Flowchart breakdown
#### Input data
This data will be obtained from the RID signal if possible and sent to the camera system [^3]. 
- Drone Location
  - Latitude (deg * 10^7) with a minimum limit of ~ 11 mm
  - Longitude (deg * 10^7) with a minimum limit of ~ 11 mm
- Drone geodetic altitude (meters) with a minimum resolution of 1 m 
- Drone speed (m/s) with a maximum of 254.25 m/s and minimim resolution of 0.25 m/s
- Direction (0-359 degrees) expressed clockwise from true north with a minimum resolution of 1 degree.
- Control Station Location[^2] 
  - Latitude (deg * 10^7) with a minimum limit of ~ 11 mm
  - Longitude (deg * 10^7) with a minimum limit of ~ 11 mm
## References
[^1]: "190 unmanned aircraft systems," Tennessee Technological University, Available: https://tntech.navexone.com/content/dotNet/documents/ [Accessed Mar. 7, 2024].
[^2]: The control station location is an optional part of the UAS RID signal
[^3]: "Standard specification for remote ID and tracking designation - F3411 - 19," ASTM International, (2019).



