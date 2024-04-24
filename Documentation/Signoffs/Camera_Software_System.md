# Camera Software System
## Functionality 
The camera software system will be reponsible for controlling the camera hardware system, ensuring that the system is able to take an image of an unmanned aircraft system (UAS) in-flight or the UAS pilot and save it to the database for usage by campus police.
## Constraints
| No.| Contraint | Origin |
| -- | --------- |--------|
|  1 | The only external inputs into the system shall be the location of UAS in the form of latitude and longitude, altitude of UAS, UAS speed, UAS direction of flight, location of the control station in the form of latitude and longitude, and authorization status of the UAS. | Design Constraint |
|  2 | The system shall not account for light levels and/or obstructions to the view of the UAS or control station when determining whether to take a picture. | Stakeholder Constraint | 
|  3 | The system shall not act upon the external data received if the data’s corresponding authorization status is true. | Tech Police |
|  4 | If the system receives data for both the control station location and the UAS location, the system shall prioritize capturing a picture of the control station unless the UAS is in a high alert area. | Tech Police |
|  5 | The system shall utilize the external inputs into the system and the known camera location to calculate the camera pointing angles to within one degree of accuracy at minimum. | Design Constraint |
|  6 | The system shall output camera motor controls based on the calculated camera pointing angles as accurately as the hardware allows. | Design Constraint and [Camera Hardware Constraint](Camera_Hardware_System.md)|
|  7 | The system shall accurately predict the location of the UAS or control station when the motion of the UAS or control station follows a straight line over a span of 3 data points. | Design Constraint |
|  8 | The system shall utilize the location prediction only when it is accurate to adjust the camera pointing angles depending on the average processing time delay. | Design Constraint | 
|  9 | The system shall output the picture taken to the database as either a raw file or PNG | Design Constraint | 

<sup>1</sup> All data will be transferred to the system through the database. Detailed description of the inputs can be found in the [analysis](#input-data). 

<sup>2</sup> The stakeholders for the project did not specify that the camera system must always capture an image of the unauthorized UAS or UAS user in 100% of pictures taken by the system because the most important information, as specified by the Tech Police, is the information contained in the RID signal and not the image captured. Therefore, the system will be not be constrained to determining the visibility of the UAS based on environmental factors before taking a picture, and cannot be held responsible for these factors obstructing the view of the UAS in pictures.

<sup>3</sup> The Tech Police will be able to authorize certain UASs for certain time periods through the [website](Website_System.md). A picture of an authorized UAS or control station is not useful as the police have already allowed their flight. 

<sup>4</sup> The Tech Police prefer a picture of the UAS control station over a picture of the UAS unless the UAS enters high alert areas that, so far, the Tech Police have specified to be dorm room buildings. Additionally, the UAS user location data is an optional addition to the RID signal [^2].

<sup>5</sup> This accuracy contraint arises from the camera pointing angle calculations in the [analysis](#camera-positioning) section. 

## Flowchart
<img src= "/Documentation/Images/Camera_Software_System/Full_Flowchart.png" width="500" height="800">

## Analysis
### Coding Language
Pending the Camera Hardware System signoff.

### Talking with the Database System
#### Input data
All RID data received from the database will be in the form of a floating point variable as specified by the [Database System](Database_System.md) detailed design markdown file.

- Required RID data:

| Data [^2] | Unit | Resolution | 
| --------- | ---- | ---------- |
| Drone Latitude | degrees * 10^7 | ~ 11 mm minimum |
| Drone Longitude | degrees * 10^7 | ~ 11 mm minimum | 
| Drone geodetic altitude | meters | 1 m minimum |
| Drone speed | m/s | 254.25 m/s maximum, 0.25 m/s minimum |
| Direction | 0-359 degrees expressed clockwise from true north | 1 degree minimum |

- Optional RID data:

| Data [^2] | Unit | Resolution | 
| ---- | ---- | ---------- |
| Control Station Location Latitude | degrees * 10^7 | ~ 11 mm minimum |
| Control Station Location Longitude | degrees * 10^7 | ~ 11 mm minimum |

- Other data:

Drone authorization status

#### Output Data
- Image captured from the camera
- Camera Power Status 


### Flowchart breakdown
<img src= "/Documentation/Images/Camera_Software_System/Parsed_Flowchart_1.png" width="300" height="100">

Following [constraint 2](#Constraints), the code will determine if the optional control station location data is usable before seeing if the required UAS location data is usable so that the presence of complete controller station location data will take precedance over UAS location data. This section of the flowchart also addresses a scenario where the data received from the Database System is incomplete or insufficient. If there is not enough data to take a picture, the software will not waste time analyzing the data and will instead wait to receive complete data before proceeding past this point. 

<img src= "/Documentation/Images/Camera_Software_System/Parsed_Flowchart_2.png" width="200" height="95">

This first block with the instruction "determine whether a picture should be taken", will contain code that is only concerned with two factors:
1. Is the UAS or control station close enough to the camera to take a quality picture? 
2. Does the system need to take another picture?

The first factor will utilize the minimum quality picture distance data from the [Camera Hardware System](Camera_Hardware_System.md) detailed design markdown file and the difference between the camera location and UAS or control station location. When the UAS or control station is too far away from the camera location, a picture should not be taken. 

The second factor will utilize how recent the last picture was taken and the location of the UAS or control station. If a picture was taken under 1 second ago (as that is the maximum time between RID transmissions[^1]) and the location of the UAS or control station is identical to the previous picture location then another picture should not be taken. This factor is an attempt to decrease the number of redundant pictures sent to the database.

<img src= "/Documentation/Images/Camera_Software_System/Parsed_Flowchart_3.png" width="175" height="80">

The code to determine the voltage that should be applied to the motor system so that the camera will face the UAS or control station will depend on the location of the UAS or control station, and the specs of the motor and camera as defined in the [Camera Hardware System](Camera_Hardware_System.md) detailed design markdown file.

<img src= "/Documentation/Images/Camera_Software_System/Parsed_Flowchart_4.png" width="200" height="95"> 

This second block with the instruction "determine whether a picture should be taken", will contain code that is only concerned with whether the UAS is still in view of the camera. This code will stop the system from taking a picture when the UAS or UAS user has moved out of scope of the camera in the time it takes the system to move the camera into the correct position. This block will utilize the information about the camera location and UAS or control station location as well as the specs of the motor and camera as defined in the [Camera Hardware System](Camera_Hardware_System.md) detailed design markdown file. This block will be followed by the instruction for the camera to take a picture.

### Camera Positioning



## References
[^1]: "190 unmanned aircraft systems," Tennessee Technological University, Available: https://tntech.navexone.com/content/dotNet/documents/ [Accessed Mar. 7, 2024].
[^2]: "Standard specification for remote ID and tracking designation - F3411 - 19," ASTM International, (2019). 



