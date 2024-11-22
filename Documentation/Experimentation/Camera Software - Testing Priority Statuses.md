# Testing Priority Statuses
## Experiment Description
### Summary
<!-- Short summary of the experiment written after completing it -->
This experiment utilizes the camera and software system controlling it to prove that the priority area status boolean adequately sets the target of the camera. 

A video of this experiment can be found [here](https://www.youtube.com/watch?v=AOBYHYJI4ZE).

#### Subsystem(s) Involved:
Camera Software Subsystem

#### Constraint(s) Tested:
- If the system receives data for the control station location, the system shall prioritize capturing a picture of the control station unless the corresponding UAS is in a high alert area as defined by the Tech Police. In that case, the system will prioritize capturing a picture of the UAS.
 
#### Expected Result(s):
- When the camera system's rasberry pi receives data from the database with the priority area boolean high, the camera should face the direction of the UAS. If the priority area boolean is low, the camera should face the direction of the control station.

## Experimental Procedure
<!-- Description of what you did ideally in steps -->
- Number of trials: 2
  
1. Set up the testing environment (consists of a sheet of paper underneath the camera to indicate sudo locations of the UAS and the control station according to unit values)
2. Set up the database to output a constant UAS location and a constant control station location. The UAS location and control station locations sent through the database are equivalent to the sudo locations in the testing environment. For this experiment the UAS location is at latitude = 1 and longitude = -1 or (-1,2), and the control station location is at latitude = 1 and longitude = 1 or (1,1). The camera location is at (0,0). 
3. Set the priority status low.
4. Record the location of the camera.
5. Set the priority status high.
6. Record the location of the camera.


## Experimental Data
<!-- data tables or graph of the results (whichever is appropriate) -->

#### Output 1:

``` bash
tntech@raspberrypi:~/Documents/C2 $ sudo ./main2
Server listening on port 8080...
Connection established with client!
Data has been read

All Stored RID Data: 
Latitude: 1, Longitude: -1, Altitude: 1, Speed: 0, Direction: 0, Timestamp: 0, CS Latitude: 1, CS Longitude: 1, High Priority Area: No

Pointing Angles: 45 degrees, 35.2644 degrees
Generated square wave on GPIO pin 18 with pulse width 2.5 ms and duty cycle 28%
Generated square wave on GPIO pin 19 with pulse width 2.5 ms and duty cycle 30%
```

<img src= "/Documentation/Experimentation/Images/camerapointinguas.jpg" width="700" height="500">

#### Output 2:

``` bash
tntech@raspberrypi:~/Documents/C2 $ sudo ./main2
Server listening on port 8080...
Connection established with client!
Data has been read

All Stored RID Data: 
Latitude: 1, Longitude: -1, Altitude: 1, Speed: 0, Direction: 0, Timestamp: 0, CS Latitude: 1, CS Longitude: 1, High Priority Area: No

Pointing Angles: 45 degrees, 35.2644 degrees
Generated square wave on GPIO pin 18 with pulse width 2.5 ms and duty cycle 28%
Generated square wave on GPIO pin 19 with pulse width 2.5 ms and duty cycle 30%
```

<img src= "/Documentation/Experimentation/Images/camerapointingatuasreal.jpg" width="700" height="500">


#### Screenshot of terminal outputs after testing:

<img src= "/Documentation/Experimentation/Images/terminal.png" width="700" height="500">

## Conclusions
#### Interpretation of Data
<!-- explain what the results of the experiments mean and what conclusions you draw -->

The first terminal output shows that the high priority area boolean was low, therefore the camera should point at the control station.
The second terminal output shows that the high priority area boolean was high, therefore the camera should point at the UAS.
The results of this experiment indicate that the status of the priority area boolean successfully changes the target of the camera.


#### Final Thoughts
<!-- Were constraints met? -->
The contraint being tested was met.
