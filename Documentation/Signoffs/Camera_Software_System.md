# Camera Software System
## Functionality 
The camera software system will be reponsible for controlling the camera hardware system, ensuring that the system is able to take an image of an unmanned aircraft system (UAS) in-flight or the UAS pilot and save it to the database for usage by campus police.
## Constraints
| No.| Contraint | Origin |
| -- | --------- |--------|
|  1 | The system shall not account for light levels and/or obstructions to the view of the UAS or control station when determining whether to take a picture | Stakeholder Constraint | 
|  2 | The system shall prioritize capturing a picture of the UAS user if the system obtains the location of the UAS user | Tech Police |  
|  3 | The ability of the system to capture a picture of the UAS or control station shall depend on the hardware constraint(s) defined in the [Camera Hardware System](Camera_Hardware_System.md) detailed design document | Design Constraint(s) | 

<sup>1</sup> The stakeholders for the project did not specify that the camera system must always capture an image of the unauthorized UAS or UAS user in 100% of pictures taken by the system because the most important information, as specified by the Tech Police, is the information contained in the RID signal and not the image captured. Therefore, the system will be not be constrained to determining the visibility of the UAS based on environmental factors before taking a picture, and cannot be held responsible for these factors obstructing the view of the UAS in pictures.   

<sup>2</sup> The Tech Police prefer a picture of the UAS control station over a picture of the UAS, however the UAS user location data is an optional addition to the RID signal [^2].

<sup>3</sup> Motor slew rate and camera lense resolution are examples of hardware constraints. 

## Flowchart
<img src= "/Documentation/Images/Camera_Software_System_Flowchart.png">

## Analysis
### Coding Language
The software system will utilized the arduino specified in the camera hardware system. Arduino uses a variant language of C++, therefore all code for this system will be in the C++ language using the arduino specific methods and functions as needed.
### Talking with the Database System
#### Input data
All data received from the database will be in the form of a floating point variable as specified by the [Database System](Database_System.md) detailed design document.

Required data:
| Data [^2] | Unit | Resolution | 
| --------- | ---- | ---------- |
| Drone Latitude | degrees * 10^7 | ~ 11 mm minimum |
| Drone Longitude | degrees * 10^7 | ~ 11 mm minimum | 
| Drone geodetic altitude | meters | 1 m minimum |
| Drone speed | m/s | 254.25 m/s maximum, 0.25 m/s minimum |
| Direction | 0-359 degrees expressed clockwise from true north | 1 degree minimum |

Optional data:
| Data [^2] | Unit | Resolution | 
| ---- | ---- | ---------- |
| Control Station Location Latitude | degrees * 10^7 | ~ 11 mm minimum |
| Control Station Location Longitude | degrees * 10^7 | ~ 11 mm minimum |
#### Output Data
Image captured from the camera
## References
[^1]: "190 unmanned aircraft systems," Tennessee Technological University, Available: https://tntech.navexone.com/content/dotNet/documents/ [Accessed Mar. 7, 2024].
[^2]: "Standard specification for remote ID and tracking designation - F3411 - 19," ASTM International, (2019). 



