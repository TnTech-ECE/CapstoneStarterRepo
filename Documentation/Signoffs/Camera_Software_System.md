# Camera Software System
## Functionality 
The camera software system will be reponsible for controlling the camera hardware system, ensuring that the system is able to take an image of an unmanned aircraft system (UAS) in-flight or the UAS pilot and save it to the database for usage by campus police.
## Constraints
| No.| Contraint | Origin |
| -- | --------- |--------|
|  1 | If the data transmitted from the database to the camera system does not contain the UAS location and the UAS altitude, a picture will not be taken | Tech Police |
|  2 | The system shall not account for light levels and/or obstructions to the view of the UAS or UAS user when determining whether to take a picture | Stakeholder Constraint | 
|  3 | The system shall try and capture a picture of the UAS user if the system obtains the location of the UAS user | Tech Police | 
        
<sup>1</sup> This constraint accounts for situations where the RID signal does not contain all of the neccessary information or the data transfer encounters an error that corrupts the data. In both situations, the system should ignore the data and not take a picture, as that image will be unusable to the Tech Police. 

<sup>2</sup> The stakeholders for the project did not specify that the camera system must always capture a picture of the unauthorized UAS or UAS user because the most important information, as specified by the Tech Police, is the information contained in the RID signal and not the image captured. Therefore, the system will be not be constrained to determining the visibility of the UAS based on environmental factors, and cannot be held responsible for these factors obstructing the view of the UAS in pictures.   

<sup>3</sup> The Tech Police prefer a picture of the UAS user over a picture of the UAS. 

## Schematic
<img src= "/Documentation/Images/Camera_Software_System_Flowchart.png">

## Analysis
### Coding Language
The software system will utilized the arduino specified in the camera hardware system. Arduino uses a variant language of C++, therefore all code for this system will be in the C++ language using the arduino specific methods and functions as needed.
### Flowchart breakdown
algorithm and test cases
#### Input data
Possible input data into the system [^3]. 
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



