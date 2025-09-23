# Testing Hardware Constraints
## Experiment Description
### Summary
Testing Procedures, Results, and Introspection of five Camera System constraints.

#### Subsystem(s) Involved:
Camera Hardware Subsystem

#### Constraints Tested:
- System shall capture an image of the UAS in flight or the control station.
- Images captured by the system shall be transmitted to the database in either a RAW or PNG format with a minimum resolution of 1080p x 720p.
- Servo motors shall be capable of reaching and maintaining angles required for image capture with a ± 10° range of accuracy.
- Servo motors shall be capable of reaching required angles in a minimum time of 500 milliseconds after recieving the appropriate signal(s).
- Camera system shall not draw more than 50 Watts of power.
 
#### Expected Result(s):
- Image of Drone or Operator to be taken and stored.
- A PNG or Raw Image type present in either the database or the computer running the database.
- An angle set by the running software to be met by the servo within a ± 10° range of accuracy (set 70. get anywhere from 60-80).<!-- - Servos reach the set angle within half a second -->
- In all states, system draws well below 50 Watts of power.

## Experimental Procedure
<!-- Description of what you did ideally in steps -->
#### Image Capture
- Number of trials: 5
1. Using the program developed by the [Camera Software System](https://github.com/mrnye42/S24_Team1_DroneTracker/blob/Experiments/Documentation/Signoffs/Camera_Software_System.md), create and run 5 pseudo-signals from the receiver system for the camera to "track".
2. Allow Program to capture and transmit images.
3. Analyze images for drone/operator presence.
4. Run and repeat test 5 times, analyzing each for subject's presence.
5. Record success in table below.

#### Image Quality
- Number of trials: 5
1. After running the above test, check each image for its quality
2. Verify each image is a png file with a minimum resolution of 1080px720p
3. Record successful attempts in table below
   
#### Servo Accuracy
- Number of trials: 10
1. Attach a marked 360° graduated circle to the moving arm of each servo motor.
2. Attach a yellow indicator piece of plastic to show where servo arm is currently pointing.
3. Create a program (aaronTest.cpp) to move the servos to pre-determined angles for testing.
4. Initialize program and set both servos to zero degrees.
5. Run and repeat test 10 times for each motor, using different angles and recording each result in the data table below.

#### Servo Speed
- Number of trials: 10
1. While running Servo Accuracy test, record video to time how long it takes for the servo to reach the final angle requested.
2. Step through video frame-by-frame, record number of frames from beginning of motion to end of motion, and estimate times from recorded video.

<!--- Number of Trials: 4
1. After Testing average response time of servos, find how long it takes for each motor to run from 0° position to max rotation, and then back to 0°.
2. Record results and estimate times from recorded video.-->

#### Power Draw
- Number of trials: 10
1. For each servo test, analyze the voltage drop and current draw using a DMM
2. Record the highest values seen by testers in table

## Experimental Data
<!-- data tables or graph of the results (whichever is appropriate) -->
*All quantitative measurements are subject to human error, and will be accounted for in concluding the system performance

#### Image Capture

|  Image | Target Visible?| Operator Visible? | Acceptable?|
|--------|----------------|-------------------|------------|
|    1   |  N             |  N                |     N      |
|    2   |  N             |  N                |     N      |
|    3   |  N             |  N                |     N      |
|    4   |  N             |  N                |     N      |
|    5   |  N             |  N                |     N      |

Image1

<img src= "/Documentation/Experimentation/Images/Camera_image1.png" width="320" height="240">

Image2

<img src= "/Documentation/Experimentation/Images/Camera_image2.png" width="320" height="240">

Image3

<img src= "/Documentation/Experimentation/Images/Camera_image3.png" width="320" height="240">

Image4

<img src= "/Documentation/Experimentation/Images/Camera_image4.png" width="320" height="240">

Image5

<img src= "/Documentation/Experimentation/Images/Camera_image5.png" width="320" height="240">

#### Image Quality

|  Image | Image Resolution| Image Datatype | Acceptable?|
|--------|-----------------|----------------|------------|
|    1   |   4056 x 3040   |      PNG       |      Y     |
|    2   |   4056 x 3040   |      PNG       |      Y     |
|    3   |   4056 x 3040   |      PNG       |      Y     |
|    4   |   4056 x 3040   |      PNG       |      Y     |
|    5   |   4056 x 3040   |      PNG       |      Y     |

File Property of each camera image

<img src= "/Documentation/Experimentation/Images/Camera_Image_Properties.png" width="640" height="167">

#### Servo Accuracy

Testing set-up for Testing angles of 180° Servo

<img src= "/Documentation/Experimentation/Images/Tilt_Home.jpg" width="320" height="427">

##### 180° Servo Table

|  Trials | Set Angle (°)| Recorded Angle (°)| Angle Difference (°)| Acceptable?|
|---------|----------|---------------|-------------|------------|
|    1    |  13°     |       11      |      2     |     Y    |
|    2    |  62°     |       59      |      3     |     Y    |
|    3    |  97°     |       95      |      2     |     Y    |
|    4    |  176°    |       170     |      6     |     Y    |
|    5    |  115°    |       110     |      5     |     Y    |
|    6    |  16°     |       12      |      4     |     Y    |
|    7    |  35°     |       20      |      15     |     N    |
|    8    |  87°     |       82      |      5     |     Y    |
|    9    |  46°     |       42      |      4     |     Y    |
|    10   |  69°     |       65      |      4     |     Y    |
|Average|  71.6°      |  66.6°     |  5°  |    90%    |


Testing set-up for Testing angles of 270° Servo

<img src= "/Documentation/Experimentation/Images/Pan_Home.jpg" width="320" height="427">

##### 270° Servo Table

|  Trial  | Set Angle (°)| Recorded Angle (°)| Difference (°)| Acceptable?|
|---------|----------|---------------|-------------|------------|
|    1    |  96°     |       95°     |      1°     |     Y    |
|    2    |  266°    |       250°    |     16°     |     N    |
|    3    |  28°     |       23°     |      5°     |     Y    |
|    4    |  162°    |       149°      |      13°     |     N    |
|    5    |  147°    |       135°      |      12°     |     N    |
|    6    |  248°    |       230°      |      18°     |     N    |
|    7    |  153°    |       140°      |      13°     |     N    |
|    8    |  198°    |       180°      |      18°     |     N    |
|    9    |  204°    |       185°      |      19°     |     N    |
|    10   |  82°     |       79°      |      3°     |     Y    |
|Average|    158.4   |   146.6    |  11.8  |    30%    |

##### Servo Speed

*These measurements are taken using video and frame-by-frame analysis/interpolation. Both videos were taken at 30 frames per second.

180° Servo Experimental [Video](/Documentation/Experimentation/Videos/Tilt_Motion_Test.mp4).

270° Servo Experimental [Video](/Documentation/Experimentation/Videos/Pan_Motion_Test.mp4).

##### 180° Servo Table, Average Run Times

|  Trials| Frame Count| Equivalent Time (s) | Distance Moved (°)| Acceptable?|
|---------|-----------|---------------------|-------------------|------------|
|    1    |  5        |    0.167            | 13                |     Y      |
|    2    |  12       |    0.400            | 49                |     Y      |
|    3    |  8        |    0.267            | 35                |     Y      |
|    4    |  13       |    0.433            | 79                |     Y      |
|    5    |  12       |    0.400            | 61                |     Y      |
|    6    |  15       |    0.500            | 99                |     Y      |
|    7    |  4        |    0.133            | 19                |     Y      |
|    8    |  13       |    0.433            | 52                |     Y      |
|    9    |  8        |    0.267            | 41                |     Y      |
|    10   |  6        |    0.200            | 23                |     Y      |
|Average  |   9.6     |     0.32            |   47.1            |   100%     |

##### 270° Servo Table, Average Run Times

|  Trials| Frame Count| Equivalent Time (s) | Distance Moved (°)| Acceptable?|
|---------|-----------|-----------------|---------------|------------|
|    1    |  15       |    0.500           | 96           |     Y    |
|    2    |  25       |    0.833           | 170          |     N    |
|    3    |  33       |    1.100           | 238          |     N    |
|    4    |  20       |    0.667           | 134          |     N    |
|    5    |  5        |    0.167           | 15           |     Y    |
|    6    |  17       |    0.567           | 101          |     N    |
|    7    |  15       |    0.500           | 95           |     Y    |
|    8    |  9        |    0.300           | 45           |     Y    |
|    9    |  3        |    0.100           | 6            |     Y    |
|    10   |  16       |    0.533           | 122          |     N    |
|Average  |  15.8     |    0.527           | 102.2        |    50%   |


##### Power Draw/Consumption

Numbers acquired from the [Power Camera Experiment Results](https://github.com/mrnye42/S24_Team1_DroneTracker/blob/Experiments/Documentation/Experimentation/Power%20Systems%20-%20Experimental%20Analysis.md) markdown file.

##### System Table
|Trials | Voltage (V) | Current (mA) | Power (W) | Acceptable?|
|-------|-------------|--------------|-----------|------------- 
|    1  |    5.073    |    44.057    |   0.224   |     Y   |
|    2  |    5.074    |    15.531    |   0.079   |     Y   |
|    3  |    5.073    |    68.914    |   0.350   |     Y   |
|    4  |    5.073    |    75.358    |   0.382   |     Y   |
|    5  |    5.073    |    47.821    |   0.243   |     Y   |
|    6  |    5.073    |    49.369    |   0.250   |     Y   |
|    7  |    5.073    |    43.420    |   0.220   |     Y   |
|    8  |    5.073    |    83.461    |   0.423   |     Y   |
|    9  |    5.073    |    42.641    |   0.216   |     Y   |
|   10  |    5.073    |    48.107    |   0.244   |     Y   |
|Average|    5.0731   |    51.8679   |   0.2631  |     Y   |

## Conclusions
#### Interpretation of Data
<!-- explain what the results of the experiments mean and what conclusions you draw -->
##### Image Capture and Quality
For these constraints, capturing an image of the drone or operator was not physically possible due to our receiver system being unable to detect and process the drone data at the time of testing. This portion of the system is working properly however, being capable of capturing and storing images when signaled with a simulated Remote ID Package. In theory, this system will be more than capable of capturing the drone or operator once pointed in the correct direction. Therefore, the image capture system currently does meet the constraint as defined.

The image quality constraint passes flawlessly however, with all captured images retaining a resolution of 4056 x 3040 pixels in a .png form factor. This constraint has been met and exceeded.

##### Servo Accuracy and Speed
For these two constraints, both servo motors performed differently. 

The 180° servo performed excellently with a 90% success rate of keeping a ±10° tolerance of the specified angle. This, with an average deviance of roughly 5°, is a reliable component and will perform excellently in the field. The second test showed a 100% success rate of keeping the travel time equal to or under 500 milliseconds, with an average travel time of 320 milliseconds over 10 tests.

On the other hand, the 270° servo motor performed slightly worse than desired by the constraints. With an average deviance of 11.8° across 10 tests, this motor is slightly less accurate than the ±10° specification. In long range setups, this tolerance gap can be greatly exacerbated, causing less precision as the target increases in distance from the system. The second test showed a similar deficit, with an average 527 millisecond time period required to travel from the previous point to the newly specified one. While a delay of 27 milliseconds is very minimal and relatively negligible, is it still out of our specified range.

For both constraints, we have met half of the desired requirements and tolerances.

##### Power Draw
For this system, a vast over-estimate of the system power requirements was developed due to concerns of locked or stalled rotor overcurrent. With a specified power supply capable of delivering 50 Watts, this system only draws an average of 263 milliwatts when both motors are turning at the maximum speed capable of a 5 volt system.

This constraint has been met and exceeded.

#### Improvements and Future Work

- Finish the full system build, fully deploying and running camera system.
- Camera Module Improvements: connection method, auto-focusing, image recognition, etc.
- Add in methods to verify motor movement and enclosure conditions (humidity, temperature, pressure, etc.) for error-testing.
- Make system all-in-one instead of two seperate enclosures
#### Final Thoughts
<!-- Were constraints met? -->
Overall, the contraints being tested were and were not met for the reasons denoted above. Overall however, this subsystem shows strong promise, and with a bit of refinement and tuning, can be a strong prototype for a future permanent detection system for the TTU Campus.

N/A Constraints were not tested due to being untestable (denoted with an *) at current subsystem progress or irrelevance on current system performance

| No.| Constraint | Constraint Met? |
| -- | --------- |--------|
|  1| System shall capture an image of the UAS in flight or the control station| N|
|  2| System shall not take into consideration light levels or physical obstructions when capturing images|N/A|
|  3| Images captured by the system shall be transmitted to the database in either a RAW or PNG format with a minimum resolution of 1080px720p| Y|
|  4| Camera zoom, focus, and light sensitivity (ISO) are not required to be controlled by system software|N/A|
|  5| Servo motors shall be capable of reaching and maintaining angles required for image capture with a ± 10° range of accuracy | Y and N|
|  6| Servo motors shall be capable of reaching required angles in a minimum time of 500 milliseconds after recieving the appropriate signal(s)| Y and N|
|  7| Camera system enclosure will meet minimum water resistance standard requirements of IP65 or greater to protect sensitive electronics| N/A*|
|  8| Camera system shall not draw more than 50 Watts of power| Y|
|  9| Camera system shall utilize IEEE Standard 802.11[^1] and Tennessee Tech Policy 856 [^2]| N/A*|
| 10| Camera system shall send a notification to the database if an error state persists beyond an acceptable limit|N/A*|
| 11| Camera system shall not operate in environmental conditions exceeding a temperature range of (0 - 50)° C| N/A|
