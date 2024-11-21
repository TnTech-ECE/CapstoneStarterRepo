# Testing Priority Statuses
## Experiment Description
### Summary
<!-- Short summary of the experiment written after completing it -->
This experiment utilizes the camera and software system controlling it to prove that the priority area status boolean adequately sets the target of the camera.

#### Subsystem(s) Involved:
Camera Software Subsystem

#### Constraint(s) Tested:
- If the system receives data for the control station location, the system shall prioritize capturing a picture of the control station unless the corresponding UAS is in a high alert area as defined by the Tech Police. In that case, the system will prioritize capturing a picture of the UAS.
 
#### Expected Result(s):
- When the camera system's rasberry pi receives data from the database with the priority area boolean high, the camera should face the direction of the UAS. If the priority area boolean is low, the camera should face the direction of the control station.

## Experimental Procedure
<!-- Description of what you did ideally in steps -->
- Number of trials: 2 trials each
  
1. Set up the testing environment (consists of a sheet of paper underneath the camera to indicate sudo locations of the UAS and the control station)
2. Set up the database to output a constant UAS location and a constant control station location.
3. Set the priority status low.
4. Record the location of the camera.
5. Set the priority status high.
6. Record the location of the camera.


## Experimental Data
<!-- data tables or graph of the results (whichever is appropriate) -->
Terminal Output:

All Stored RID Data: 
Latitude: 5, Longitude: -5, Altitude: 2, Speed: 0, Direction: 0, Timestamp: 0, CS Latitude: 5, CS Longitude: 5, High Priority Area: No
Latitude: 5, Longitude: -5, Altitude: 2, Speed: 0, Direction: 0, Timestamp: 0, CS Latitude: 5, CS Longitude: 5, High Priority Area: No
Latitude: 5, Longitude: -5, Altitude: 2, Speed: 0, Direction: 0, Timestamp: 0, CS Latitude: 5, CS Longitude: 5, High Priority Area: No

Pointing Angles: 45 degrees, 15.7932 degrees
Generated square wave on GPIO pin 18 with pulse width 2.5 ms and duty cycle 28%
Generated square wave on GPIO pin 19 with pulse width 2.5 ms and duty cycle 21%
Server listening on port 8080...
Connection established with client!
Data has been read

Location of the camera:


<img src= "https://d82.camscanner.com/sync/download_resize_jpg?folder_name=CamScanner_Page&file_name=3aP0PVJ2V86dMFfBg4y2f4TL.jpg&pixel=200&_t=1732168295&token=73B9AC11302949C27K70D8rY02" width="700" height="500">

Terminal Output:

All Stored RID Data: 
Latitude: 5, Longitude: -5, Altitude: 2, Speed: 0, Direction: 0, Timestamp: 0, CS Latitude: 5, CS Longitude: 5, High Priority Area: No
Latitude: 5, Longitude: -5, Altitude: 2, Speed: 0, Direction: 0, Timestamp: 0, CS Latitude: 5, CS Longitude: 5, High Priority Area: No
Latitude: 5, Longitude: -5, Altitude: 2, Speed: 0, Direction: 0, Timestamp: 0, CS Latitude: 5, CS Longitude: 5, High Priority Area: Yes

Pointing Angles: 135 degrees, 15.7932 degrees
Generated square wave on GPIO pin 18 with pulse width 2.5 ms and duty cycle 55%
Generated square wave on GPIO pin 19 with pulse width 2.5 ms and duty cycle 21%

Location of the camera:


<img src= "https://d82.intsig.net/sync/share/download_resize_jpg?folder_name=CamScanner_Page&_t=1732167595&encrypt_id=MHgyZTkzZDU1ZTk1&device_id=&sid=AABFFE3613694B49YL9A8AA2US&pixel=1000&file_name=22dXNW4XSg8WP7Eh1Sd74P4V.jpg" width="700" height="500">



## Conclusions
#### Interpretation of Data
<!-- explain what the results of the experiments mean and what conclusions you draw -->

The first terminal output shows that the high priority area boolean was low, therefore the camera should point at the control station.
The second terminal output shows that the high priority area boolean was high, therefore the camera should point at the UAS.
The results of this experiment indicate that the status of the priority area boolean successfully changes the target of the camera.


#### Final Thoughts
<!-- Were constraints met? -->
The contraint being tested was met, and although the testing seemed arbitrary for a fully software system, the performance of the priority status is very important to the system.
