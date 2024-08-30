# Camera Software System
## Functionality 
The camera software system will be reponsible for using the data acquired by the receiver to generate signals that will control the camera hardware system's motor servos and camera activation status, ensuring that the system is able to take an image of an unmanned aircraft system (UAS) or the control station. The system will then acquire the image from the camera hardware, format it, and sent it to the database for usage by campus police. The system will also send an alert signal if there are detected errors in the system.    
## Constraints
| No.| Contraint | Origin |
| -- | --------- |--------|
|  1 | The system is not expected to capture an image of the UAS or control station if light levels and/or obstructions hinder the camera's view of the UAS or control station. | Stakeholder Constraint | 
|  2 | If the system receives data for the control station location, the system shall prioritize capturing a picture of the control station unless the corresponding UAS is in a high alert area as defined by the Tech Police. In that case, the system will prioritize capturing a picture of the UAS. | Tech Police |
|  3 | Location prediction shall be performed when the UAS or control station is moving in a straight line, but is not required if the UAS or control station is moving in other trajectory. | Design Constraint |
|  4 | The system shall use at least three data points to determine if the UAS or control station is moving in a straight line within a 5% error margin. | Design Constraint |
|  5 | The system shall output the picture taken to the database as either a raw file or PNG. | Design Constraint | 
|  6 | The system shall communicate with the database system according to IEEE standard 802.11 [^3] and Tennessee Tech Policy 856 [^4] | Standards |

<sup>1</sup> The stakeholders for the project did not specify that the camera system must always capture an image of the unauthorized UAS or UAS user in 100% of pictures taken by the system because the most important information, as specified by the Tech Police, is the information contained in the RID signal and not the image captured. Therefore, the system will be not be constrained to determining the visibility of the UAS based on environmental factors before taking a picture, and cannot be held responsible for these factors obstructing the view of the UAS in pictures.

<sup>2</sup> The Tech Police prefer a picture of the UAS control station over a picture of the UAS unless the UAS enters a high alert area. The Tech Police will be able to specify the location of high alert areas through the [website](Website_System.md). 

<sup>3</sup> Any motion other than straight line motion will be either too complex or impossible to predict. 

<sup>4</sup> Two data points alone do not provide enough information to accurately determine the motion of the UAS or control station. 

<sup>5</sup> Raw files and PNGs will help to maintain the quality of the image captured. 

<sup>6</sup> IEEE standards help to decrease internet traffic and ensure appropriate data transfer rates. Tennessee Tech standards ensure that different security levels of data are appropriately protected.   

## Flowchart and Coding Details
<img src= "/Documentation/Images/Camera_Software_System/Flowchart.png" width="600" height="1000">

### Flowchart breakdown
<img src= "/Documentation/Images/Camera_Software_System/Parsed1.png" width="250" height="150">

Following [constraint 2](#Constraints), the code will allow a UAS in a high alert area to take precedence over a control station location, but will attempt pictures of a control station if a UAS is not flying in a high alert area. This section of the flowchart also addresses the unlikely scenario where the data received from the [Database System](Database_System.md) is incomplete or insufficient. If there is not enough data to take a picture, the software will not waste time analyzing the data and will instead wait to receive complete data before proceeding past this point. 

<img src= "/Documentation/Images/Camera_Software_System/Parsed2.png" width="125" height="105">
This block will contain code that is only concerned with two factors:

1. Is the UAS or control station close enough to the camera to take a quality picture?
  
2. Does the system need to take another picture?

The first factor will utilize the minimum quality picture distance data from the [Camera Hardware System](Camera_Hardware_System.md) detailed design markdown file and the difference between the camera location and UAS or control station location. When the UAS or control station is too far away from the camera location, a picture should not be taken. 

The second factor will utilize how recent the last picture was taken and the location of the UAS or control station. If a picture was taken under 1 second ago (as that is the maximum time between RID transmissions[^1]) and the location of the UAS or control station is identical to the previous picture location then another picture should not be taken. This factor is an attempt to decrease the number of redundant pictures sent to the database.

<img src= "/Documentation/Images/Camera_Software_System/Parsed3.png" width="175" height="125">

This block contains code that will be associated with [constraint 4](#Constraints). The code will determine if the UAS or control station is moving in a straight line over a span of at least 3 points and will attempt to predict the next position if straight line motion was detected. This prediction as well as the average time delay of the system, and the UAS or control station velocity will be used to alter the camera pointing angles as needed. See the [associated section](#Predicting-UAS-or-Control-Station-Location) for mathematical calculations.  

<img src= "/Documentation/Images/Camera_Software_System/Parsed4.png" width="130" height="150">

The camera pointing angles will be calculated using the UAS or control station location and the location of the camera. See the [associated section](#Camera-Positioning) for mathematical calculations. After calculating the camera pointing angles, the code will instruct the motors to move as close to the pointing angles as the [hardware](Camera_Hardware_System.md) will allow. Then, the system will take a picture and send it to the database as a raw file or PNG according to [constraint 5](#Constraints). 

<img src= "/Documentation/Images/Camera_Software_System/Parsed5revised.png" width="130" height="130">

The code located in this block will utilize all available sensors or software feedback mechanisms to determine whether the system needs to send an alert to the Tech Police. 

### Coding Language
The microprocessor that will run the software is defined in the [Camera Hardware system](Camera_Hardware_System.md), and it is compatible with multiple different coding languages. Due to programmer's preference, either C++ or Python will be used. 

### Talking with the Database System
#### Input data
All data received from the database is in the form specified by the [Database System](Database_System.md) detailed design markdown file.

- Required RID data:

| Data [^2] | Unit | Resolution | Data Type | 
| --------- | ---- | ---------- | --------- | 
| UAS latitude | degrees * 10^7 | ~ 11 mm minimum | signed integer |
| UAS longitude | degrees * 10^7 | ~ 11 mm minimum | signed integer |
| UAS geodetic altitude | meters | 1 m minimum | unsigned integer |
| UAS speed | m/s | 254.25 m/s maximum, 0.25 m/s minimum | unsigned integer |
| Direction | 0-359 degrees expressed clockwise from true north | 1 degree minimum | unsigned int |

- Optional RID data:

| Data [^2] | Unit | Resolution |  Data Type |
| --------- | ---- | ---------- | ---------- |
| Control station location latitude | degrees * 10^7 | ~ 11 mm minimum | signed integer |
| Control station location longitude | degrees * 10^7 | ~ 11 mm minimum | signed integer |

- Other data:

| Data |  Data Type |
| ---- | ---------- |
| High priority area alert | boolean |

#### Output Data
| Data |  Data Type |
| ---- | ---------- |
| Image captured by the camera | raw file or PNG |
| Camera status | boolean |

### Key Variables


### Functions 
| Function Name |  Task(s) | Other specifications |
| ------------- | -------- | -------------------- |
| Receive_request | This function will receive a data transfer request from the database as an input and will approve the request | Will only be utilized if the [Database System](Database_System.md) specifies a need for authentication |
| Send_request | This function will recieve an input indicating that there is data to send. After receiving this input, the function will send a data transfer request to the database.| Will only be utilized if the [Database System](Database_System.md) specifies a need for authentication |
| Database_sender | This function will receive the image captured by the camera, the camera status boolean , and the output from the database stating whether the data is ready to be sent or not (only if utilized by the [Database System](Database_System.md)). Then, the system will send the image and camera status boolean to the database| -- |
| Store_data | This function will receive the RID data from the Database system. It will then store the data in an array. | This data array will contain  


### Camera Positioning
#### Horizontal Pointing Angle
<img src= "/Documentation/Images/Camera_Software_System/angle1.png" width="300" height="200">

$\ x = |\textrm{UAS longitude}|-|\textrm{Camera longitude}| $

$\ y = |\textrm{UAS latitude}|-|\textrm{Camera latitude}| $

$\ \theta_1 = \tan^{-1} (\frac{y}{x}) $

$\ \textrm{If x is a negative number: } \theta_1 = \theta_1 + 180 \degree $

#### Vertical Pointing Angle
<img src= "/Documentation/Images/Camera_Software_System/angle2.png" width="300" height="200">

$\ z = |\textrm{UAS altitude}|-|\textrm{Camera altitude}| $

$\ l = \sqrt{x^2+y^2} $

$\ \theta_2 = \tan^{-1} (\frac{z}{l}) $


### Predicting UAS or Control Station Location
#### Determining Straight Line Motion
Given 3 points:

$\ p_1 = (x_1 , y_1), p_2 = (x_2 , y_2), p_3 = (x_3 , y_3) $

The corresponding slope values between the points:

$\ m_1 = \frac{y_2 - y_1}{x_2 - x_1}, m_2 = \frac{y_3 - y_2}{x_3 - x_2} $

If 
$\ .95 \leq \frac{m_1}{m_2} \leq 1.05 $ 
is true, straight line motion exists within 5% error margines. 

#### Predicting Future Location
Given straight line motion, and the velocities:

$\ v_2 = \textrm{velocity value at point } p_2 $

$\ v_3 = \textrm{velocity value at point } p_3 $

Let the predicted location of the UAS or control station be 
$\ (x_p , y_p) $ 
where:

$\ x_p = x_3 + ((\frac{v_3}{v_2}) * (x_3 - x_2)) $

$\ y_p = y_3 + ((\frac{v_3}{v_2}) * (y_3 - y_2)) $

## Analysis

## BOM
none
## References
[^1]: "190 unmanned aircraft systems," Tennessee Technological University, Available: https://tntech.navexone.com/content/dotNet/documents/ [Accessed Mar. 7, 2024].
[^2]: "Standard specification for remote ID and tracking designation - F3411 - 19," ASTM International, (2019). 
[^3]: “IEEE 802.11-2020: Collision avoidance in wireless networks,” American National Standards Institute, Available: https://blog.ansi.org/ieee-802-11-collision-avoidance-wireless-networks/ [Accessed Feb. 19, 2024].
[^4]: “856 data security and handling policy,” Tennessee Technological University, Available: https://www.tntech.edu/policies/ [Accessed April. 29, 2024].



