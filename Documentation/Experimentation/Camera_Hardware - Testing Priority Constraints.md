# Testing Priority Constraints
## Experiment Description
### Summary
Bingus

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
1. Using the program developed by the [Camera Software System](https://github.com/mrnye42/S24_Team1_DroneTracker/blob/Experiments/Documentation/Signoffs/Camera_Software_System.md), create and run 5 pseudo-signals from the receiver system for the camera to "track"
2. Allow Program to capture and transmit images
3. Analyze images for drone/operator presence
4. Run and repeat test 5 times, analyzing each for subject's presence
5. Record success in table below

#### Image Quality
- Number of trials: 5
1. After running the above test, check each image for its quality
2. Verify each image is a png file with a minimum resolution of 1080px720p
3. Record successful attempts in table below
   
#### Servo Accuracy
- Number of trials: 10
1. Attach a 360° graduated circle to the moving arm of each servo motor.
2. Attach a yellow indicator piece of plastic to show where servo arm is currently pointing.
3. Create a program (aaronTest.cpp) to move the servos to pre-determined angles for testing.
4. Run and repeat test 10 times for each motor, using different angles and recording each result in the data table below.

#### Servo Speed
- Number of trials: 10
1. While running Servo Accuracy test, time how long it takes for the servo to reach the final angle requested
2. Record results and rough times in the table

#### Power Draw
- Number of trials: 10
1. For each servo test, analyze the voltage drop and current draw using a DMM
2. Record the highest values seen by testers in table

## Experimental Data
<!-- data tables or graph of the results (whichever is appropriate) -->
#### Image Capture

|  Image | Target Visible?| Operator Visible? | Acceptable?|
|--------|----------------|-------------------|------------|
|    1   |  xs            |  xs               |     y/n    |
|    2   |  xs            |  xs               |     y/n    |
|    3   |  xs            |  xs               |     y/n    |
|    4   |  xs            |  xs               |     y/n    |
|    5   |  xs            |  xs               |     y/n    |

Image1
Image2
Image3
Image4
Image5

#### Image Quality

|  Image | Image Resolution| Image Datatype | Acceptable?|
|--------|-----------------|----------------|------------|
|    1   |  xs             |  xs            |     y/n    |
|    2   |  xs             |  xs            |     y/n    |
|    3   |  xs             |  xs            |     y/n    |
|    4   |  xs             |  xs            |     y/n    |
|    5   |  xs             |  xs            |     y/n    |

Image1Properties
Image2Properties
Image3Properties
Image4Properties
Image5Properties

#### Servo Accuracy

##### Servo 1 Table

|  Trials | Set Angle| Recorded Angle| % Difference| Acceptable?|
|---------|----------|---------------|-------------|------------|
|    1    |  13°     |       x°      |      x%     |     y/n    |
|    2    |  62°     |       x°      |      x%     |     y/n    |
|    3    |  97°     |       x°      |      x%     |     y/n    |
|    4    |  176°    |       x°      |      x%     |     y/n    |
|    5    |  115°    |       x°      |      x%     |     y/n    |
|    6    |  16°     |       x°      |      x%     |     y/n    |
|    7    |  35°     |       x°      |      x%     |     y/n    |
|    8    |  87°     |       x°      |      x%     |     y/n    |
|    9    |  46°     |       x°      |      x%     |     y/n    |
|    10   |  69°     |       x°      |      x%     |     y/n    |


##### Servo 2 Table

|  Trial  | Set Angle| Recorded Angle| % Difference| Acceptable?|
|---------|----------|---------------|-------------|------------|
|    1    |  96°     |       x°      |      x%     |     y/n    |
|    2    |  266°    |       x°      |      x%     |     y/n    |
|    3    |  28°     |       x°      |      x%     |     y/n    |
|    4    |  162°    |       x°      |      x%     |     y/n    |
|    5    |  147°    |       x°      |      x%     |     y/n    |
|    6    |  248°    |       x°      |      x%     |     y/n    |
|    7    |  153°    |       x°      |      x%     |     y/n    |
|    8    |  198°    |       x°      |      x%     |     y/n    |
|    9    |  204°    |       x°      |      x%     |     y/n    |
|    10   |  82°     |       x°      |      x%     |     y/n    |

##### Servo Speed

*Disclaimer: These measurements, due to the difficulty of automation, are taken by hand and are therefore subject to human error.

##### Servo 1 Table

|  Trials | Start Time| End Time | Difference| Acceptable?|
|---------|-----------|----------|-----------|------------|
|    1    |  xs       |  xs      |    xs     |     y/n    |
|    2    |  xs       |  xs      |    xs     |     y/n    |
|    3    |  xs       |  xs      |    xs     |     y/n    |
|    4    |  xs       |  xs      |    xs     |     y/n    |
|    5    |  xs       |  xs      |    xs     |     y/n    |
|    6    |  xs       |  xs      |    xs     |     y/n    |
|    7    |  xs       |  xs      |    xs     |     y/n    |
|    8    |  xs       |  xs      |    xs     |     y/n    |
|    9    |  xs       |  xs      |    xs     |     y/n    |
|    10   |  xs       |  xs      |    xs     |     y/n    |


##### Servo 2 Table

|  Trials | Start Time| End Time | Difference| Acceptable?|
|---------|-----------|----------|-----------|------------|
|    1    |  xs       |  xs      |    xs     |     y/n    |
|    2    |  xs       |  xs      |    xs     |     y/n    |
|    3    |  xs       |  xs      |    xs     |     y/n    |
|    4    |  xs       |  xs      |    xs     |     y/n    |
|    5    |  xs       |  xs      |    xs     |     y/n    |
|    6    |  xs       |  xs      |    xs     |     y/n    |
|    7    |  xs       |  xs      |    xs     |     y/n    |
|    8    |  xs       |  xs      |    xs     |     y/n    |
|    9    |  xs       |  xs      |    xs     |     y/n    |
|    10   |  xs       |  xs      |    xs     |     y/n    |

##### Power Draw

##### System Table

|  Trials | Voltage| Current | Wattage| Acceptable?|
|---------|-----------|----------|-----------|------------|
|    1    |  xs       |  xs      |    xs     |     y/n    |
|    2    |  xs       |  xs      |    xs     |     y/n    |
|    3    |  xs       |  xs      |    xs     |     y/n    |
|    4    |  xs       |  xs      |    xs     |     y/n    |
|    5    |  xs       |  xs      |    xs     |     y/n    |
|    6    |  xs       |  xs      |    xs     |     y/n    |
|    7    |  xs       |  xs      |    xs     |     y/n    |
|    8    |  xs       |  xs      |    xs     |     y/n    |
|    9    |  xs       |  xs      |    xs     |     y/n    |
|    10   |  xs       |  xs      |    xs     |     y/n    |


## Conclusions
#### Interpretation of Data
<!-- explain what the results of the experiments mean and what conclusions you draw -->

#### Improvements and Future Work

- Finish the full system build, fully deploying and running camera system.
- Camera Module Improvements: connection method, auto-focusing, image recognition, etc.
- Add in methods to verify motor movement and enclosure conditions (humidity, temperature, pressure, etc.) for error-testing.
- Make system all-in-one instead of two seperate enclosures
#### Final Thoughts
<!-- Were constraints met? -->
Overall, the contraints being tested were/were not met for the following reasons. THE REASONS. Overall however, this subsystem shows strong promise, and with a bit of refinement and tuning, can be a strong prototype for a future permanent detection system for the TTU Campus.

| No.| Constraint | Constraint Met? |
| -- | --------- |--------|
|  1| System shall capture an image of the UAS in flight or the control station| Y/N|
|  2| System shall not take into consideration light levels or physical obstructions when capturing images|N/A|
|  3| Images captured by the system shall be transmitted to the database in either a RAW or PNG format with a minimum resolution of 1080px720p| Y/N|
|  4| Camera zoom, focus, and light sensitivity (ISO) are not required to be controlled by system software|N/A|
|  5| Servo motors shall be capable of reaching and maintaining angles required for image capture with a ± 10° range of accuracy | Y/N)|
|  6| Servo motors shall be capable of reaching required angles in a minimum time of 500 milliseconds after recieving the appropriate signal(s)| Y/N|
|  7| Camera system enclosure will meet minimum water resistance standard requirements of IP65 or greater to protect sensitive electronics| N/A|
|  8| Camera system shall not draw more than 50 Watts of power| Y/N|
|  9| Camera system shall utilize IEEE Standard 802.11[^1] and Tennessee Tech Policy 856 [^2]| N/A|
| 10| Camera system shall send a notification to the database if an error state persists beyond an acceptable limit|N/A|
| 11| Camera system shall not operate in environmental conditions exceeding a temperature range of (0 - 50)° C| N/A|
