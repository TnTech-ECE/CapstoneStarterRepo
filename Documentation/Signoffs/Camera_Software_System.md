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
| Timestamp	| Hours + Seconds | .01 second minimum | unsigned integer |

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
| Variable Name | Data Type | Minimum Size | Other specifications |
| ------------- | --------- | ------------ | -------------------- |
| Rid_data | array variable | 27 indexes | The RID_data array should be able to hold three seperate RID data packages from the database because computing the future UAS positioning requires knowing data from three points in time. |
| pic_timestamp | array variable | 5 indexes | The pic_timestamp array will hold the date and time at which the last picture was taken where index 0 - index 4 will contain the month, day, year, military hour, and millisecond respectively. | 
| take_picture | boolean variable | -- | When the take_picture boolean is high, the system will take a picture. When the boolean is low, the system will not take a picture. This boolean will be set high by the AnalyzeData function and set low after a picture is taken |
| picture_subject | boolean variable | -- | The picture_subject variable is high when the system should attempt to take a picture of the UAS and is low when the system should attempt to take a picture of the control station. The staus of this boolean is determined by the AnalyzeData function |
| slm | boolean variable | -- | When the slm boolean is high, the system has detected that there is straight line motion within 5% error margins and the future location of the UAS or control station should be determined. When the boolean is low, no future location calculations will take place. |
| can_send | boolean variable | -- | The can_send boolean tells the SendData function that the database is ready to collect data from the system |
| can_receive | boolean variable | -- | The can_receive boolean tells the StoreData function that the RID data package from the database is ready to be collected and analyzed |
| new_angles | boolean variable | -- | The new_angles boolean is set high by the PredictLocation function when the the function has successfully predicted the location and changed the location values in the Rid_data array. | 
| new_data | boolean variable | -- | The new_data boolean is set high by the SendData function when new data is collected by the system. |
| theta_h | signed integer | -- | The theta_h integer is determined by the DetermineAngles function and holds the value of the horizontal camera pointing angle |
| theta_v | signed integer | -- | The theta_v integer is determined by the DetermineAngles function and holds the value of the vertical camera pointing angle |
| camera_status | boolean variable | -- | The camera_status boolean will be set high when the CheckSystem function determines that there is an error in the system. |
| camera_set | boolean variable | -- | The camera_set boolean will be set high by the MoveCamera function when the camera has been moved into the calculated position and is ready to capture an image |

### Functions 
| Function Name |  Task(s) | Other specifications |
| ------------- | -------- | -------------------- |
| ReceiveRequest | This function will receive a data transfer request from the database as an input and will approve the request. | Will only be utilized if the [Database System](Database_System.md) specifies a need for authentication |
| SendRequest | This function will recieve the new_data boolean. If new_data is high, the function will send a data transfer request to the database. If the function then receives an approval from the database, the can_send boolean will be set high.| Will only be utilized if the [Database System](Database_System.md) specifies a need for authentication |
| SendData | This function will receive the image captured by the camera, and the camera status boolean, and the can_send boolean. The system will set new_data high if new data is collected. Then, once the can_send boolean is set high by the SendRequest Function, this function will send the image and camera status boolean to the database| -- |
| StoreData | This function will receive the RID data from the Database system. It will then store the data in the RID_data array. The can_receive boolean controls the ability of the function to receive another RID data package from the database. | -- |
| AnalyzeData | This function will look at the RID_data array and determine if the data is sufficient, whether the system should focus on the UAS or control station and if the system should attempt to capture a picture. Inputs into this function will be the RID_Data arra and the pic_timestamp array. The first output will be either setting the take_picture boolean high or keeping it low. The second output will indicate which subject the system should attempt to take a picture of by using the picture_subject boolean. | Sufficient data contains, at minimum, all of the required RID data |
| DetermineSlm | This function will utilize the RID_data array to determine whether the UAS or control station, depending on the value of the function's input boolean picture_subject, is moving in straight line motion within a 5% error margin. If straight line motion is determined, the function will set the predict_location boolean high. This function will only execute its calculations when the take_picture boolean is high. | See [associated section](####Determining-Straight-Line-Motion) for the math associated with this function. |
| PredictLocation | This function will utilize the RID_data array to determine the future location of the UAS or control system, depending on the value of the picture_subject boolean. This function will only execute when the slm boolean is set high by the DetermineSlm function. | See [associated section](####Predicting-Future-Location) for the math associated with this function. |
| DetermingAngles | This function will determine the pointing angles for the motor servos. It will execute when the the values of the take_picture boolean is high and both the slm and new_angles booleans are high. The output of this function are the theta_v and theta_h signed integers. After calculating the pointing angles, the function will set the slm and new_angles booleans low. | See [associated section](####Camera-Positioning) for the math associated with this function. | 
| MoveCamera | This function uses the camera pointing angles and determines the voltage levels to apply to the servo motors. After applying the voltages, MoveCamera will set the camera_set boolean high | -- |
| TakePicture | This function controls the image capturing capabilities of the camera. It will capture a picture when the camera_set boolean is high, save the time at which the picture is taken in the picture_timestamp array, save the captured image, and set the camera_set and take_picture booleans low. | -- |
| CheckSystem | This function will receive system inputs such as power status and will use the inputs to determine what the status of the entire camera software system is. If a problem is detected, CheckSystem will set the camera_status boolean high. | -- |

#### Functions Flowchart 
<img src= "/Documentation/Images/Camera_Software_System/FunctionsFlowchart.png" width="750" height="450">

### Camera Positioning
#### Horizontal Pointing Angle
<img src= "/Documentation/Images/Camera_Software_System/angle1.png" width="300" height="200">

$\ x = \textrm{UAS longitude}-\textrm{Camera longitude} $

$\ y = \textrm{UAS latitude}-\textrm{Camera latitude} $

$\ \theta_1 = \tan^{-1} (\frac{y}{x}) $

$\ \textrm{If x is a negative number: } \theta_1 = \theta_1 + 180 \degree $

#### Vertical Pointing Angle
<img src= "/Documentation/Images/Camera_Software_System/angle2.png" width="300" height="200">

$\ z = \textrm{UAS altitude}-\textrm{Camera altitude} $

$\ l = \sqrt{x^2+y^2} $

$\ \theta_2 = \tan^{-1} (\frac{z}{l}) $


### Predicting UAS or Control Station Location
#### Determining Straight Line Motion
Given 3 points:

$\ p_1 = (x_1 , y_1, z_1), p_2 = (x_2 , y_2, z_2), p_3 = (x_3 , y_3, z_3) $

The two directional vectors are:

$\ \overrightarrow{P_1P_2} = (x_1 - x_2, y_1 - y_2, z_1 - z_2) $

$\ \overrightarrow{P_2P_3} = (x_2 - x_3, y_2 - y_3, z_2 - z_3) $


And their magnitudes:

$\ |\overrightarrow{P_1P_2}| = \sqrt{(x_1 - x_2)^2+(y_1 - y_2)^2+(z_1 - z_2)^2} $

$\ |\overrightarrow{P_1P_2}| = \sqrt{(x_2 - x_3)^2+(y_2 - y_3)^2+(z_2 - z_3)^2} $


If equations 1, 2, and 3, below are all true, straight line motion exists within 5% error margines. 

1.
$\ (\frac{x_1-x_2}{|\overrightarrow{P_1P_2}|} * .95) \leq \frac{x_2-x_3}{|\overrightarrow{P_2P_3}|} \leq (\frac{x_1-x_2}{|\overrightarrow{P_1P_2}|} * 1.05) $ 

2.
$\ (\frac{y_1-y_2}{|\overrightarrow{P_1P_2}|} * .95) \leq \frac{y_2-y_3}{|\overrightarrow{P_2P_3}|} \leq (\frac{y_1-y_2}{|\overrightarrow{P_1P_2}|} * 1.05) $ 

3.
$\ (\frac{z_1-z_2}{|\overrightarrow{P_1P_2}|} * .95) \leq \frac{z_2-z_3}{|\overrightarrow{P_2P_3}|} \leq (\frac{z_1-z_2}{|\overrightarrow{P_1P_2}|} * 1.05) $ 


#### Predicting Future Location
Given straight line motion, and the velocities:

$\ v_2 = \textrm{velocity value at point } p_2 $

$\ v_3 = \textrm{velocity value at point } p_3 $

Let the predicted location of the UAS or control station be 
$\ (x_p , y_p, z_p) $ 
where:

$\ x_p = x_3 + ((\frac{v_3}{v_2}) * (x_3 - x_2)) $

$\ y_p = y_3 + ((\frac{v_3}{v_2}) * (y_3 - y_2)) $

$\ z_p = z_3 + ((\frac{v_3}{v_2}) * (z_3 - z_2)) $

## Analysis
### Proving Camera Pointing Angle Accuracy
  Utilizing the 3D plot function of MATLAB, a simulation of a target in flight and a camera were created. The Figure below shows this simulation where the blue line represents the path of the target, the black circle represents the location of the camera, the yellow circles on the blue path line represent the point in space that the camera is attempting to point to and the dotted lines representing the camera vectors which visually help make it clear that in theory the math is capable of orienting the camera towards the target given its x, y, and z coordinates. The path of the target was chosen arbitrarily with the only requirement being that it traveled in all quadrants around the camera. The location of the camera was also specifically chosen to not lie at the origin to ensure a degree of realism. The MATLAB code and figures are as follows:

<img src= "/Documentation/Images/Camera_Software_System/Pointing angles matlab graph.png" width="500" height="400">

<img src= "/Documentation/Images/Camera_Software_System/Pointing angles matlab graph xy.png" width="500" height="400">

<img src= "/Documentation/Images/Camera_Software_System/Pointing angles matlab graph yz.png" width="500" height="400">

The MATLAB code analyzes the simulated path of the target, uses the derived [equations](####Camera-Positioning) to calculate the pointing angles. Then, utilizing only those pointing angles, the code reverse engineers the point on the path that the camera will be focussing on and the vector from the camera to that point for intervals along the target's path. 

```Matlab
clear

%defining path of the UAS or control station
t = -10:.001:10;
x = 2.*t.*cos(t);
y = sin(t).*t.^2+3.*t+5;

%camera coordinates
cx = -5;
cy = 4;
cz = -3;

%plotting path
p = plot3(x,y,t);
p.Color = [0.3 0.5 0.8];
p.LineWidth = 1.5;

hold on

%plotting camera
c = plot3(cx,cy,cz,'o');
c.Color = "black";
c.LineWidth = 5;

t1 = -10:.5:10;
x1 = 2.*t1.*cos(t1);
y1 = sin(t1).*t1.^2+3.*t1+5;

%calculating pointing angles
xp = (x1) - (cx);
yp = (y1) - (cy);
theta_1 = atand(yp./xp);

for i = 1:length(t1)
    if xp(i) < 0 
        theta_1(i) = theta_1(i) + 180;
    end
end    

tp = (t1) - (cz);
l = sqrt((xp.^2)+(yp.^2));
theta_2 = atand(tp./l);

r = sqrt((xp.^2)+(yp.^2)+(tp.^2));

%Reverse engineering the pointing angles to prove accuracy:

%polar to cartestian conversions
xc = (r .* cosd(theta_1) .* cosd(theta_2)) + cx;
yc = (r .* sind(theta_1) .* cosd(theta_2)) + cy;
zc = (r .* sind(theta_2)) + cz;

%plotting camera points
d = plot3(xc,yc,zc,'o');
d.LineWidth = 1;

%plotting camera vectors
for i = 1:length(t1)

    a = xc(i);
    b = yc(i);
    c = zc(i);

    k = (xc(i) - cx);
    m = (yc(i) - cy);
    n = (zc(i) - cz);
        
    xl = cx:k/1000:a;
    yl = cy:m/1000:b;
    zl = cz:n/1000:c;
    
    
    if k == 0
        xl = ones([1 1001]).*cx;
    end

    if m == 0
        yl = ones([1 1001]).*cy;
    end

    if n == 0
        zl = ones([1 1001]).*cz;
    end

    plot3(xl,yl,zl,'--');
end
```
### Proving Straight Line Motion Predictions
## BOM
none
## References
[^1]: "190 unmanned aircraft systems," Tennessee Technological University, Available: https://tntech.navexone.com/content/dotNet/documents/ [Accessed Mar. 7, 2024].
[^2]: "Standard specification for remote ID and tracking designation - F3411 - 19," ASTM International, (2019). 
[^3]: “IEEE 802.11-2020: Collision avoidance in wireless networks,” American National Standards Institute, Available: https://blog.ansi.org/ieee-802-11-collision-avoidance-wireless-networks/ [Accessed Feb. 19, 2024].
[^4]: “856 data security and handling policy,” Tennessee Technological University, Available: https://www.tntech.edu/policies/ [Accessed April. 29, 2024].



