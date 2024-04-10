# Head On Position Sensor
## Functionality
The purpose of the head on position sensor is to determine the target's location relative to the interceptor. Sensing equipment shall be attached to the front of the interceptor facing the test bed. The sensor will then read in data and make the necessary calculations to determine the X, Y, and Z position of the target. Higher accuracy is expected in the X and Y direction rather than Z, as to get an accurate reading on depth a time of flight sensor would be required with a high sampling rate, and this would be difficult and expensive given the test bed is only 6 feet long [].
## Constraints
* C7: Design a sensor array that can detect approaching objects and relay their locations to the interceptor.
* C23: The head on position sensor shall have a maximum latency of 100ms and provide updates at least 10 times per second.
* C24: The head on position  sensor shall be able to detect the target with an accuracy of at least 2 inches from six feet away.
### Explanations for C23 and C24
The fastest the target can cross the game board is 910 ms. Therefore, in order to have a chance to intercept the target the time among subsystems must be properly managed. The following table shows the budgeted delay for all subsystems

| Subsystem    | Time |
| -------- | ------- |
| Networking  | 20ms    |
| Head on Position Sensor | 100ms     |
| Aiming    | 100ms    |
| Launching | 30ms |

As shown in the above table the total delay is 250ms which demonstrates that time is a limiting factor and deserves the most consideration going forward with the design.

The intention is to determine the target's location by image recognition. The head on positon sensor will be a camera connected to a Raspberry Pi facing the test bed. By using an image recognition algorithm, the relative X and Y position will be determined. By knowing the target's depth, camera resoloution, and camera's feild of view the X and Y location can be determined. The algorithm will also return the target's diameter allowing for an approximate calculation of its depth. This is possible in 100ms as shown in a demonstration by ... [] showing a ball that is tracked in real time with minimal delay. The goal with image processing is to have as low latency as possible and to maximize the number of updates per second. A major issue with an image processing algorithm is the possibility of a false positive where the controller reports the location of nonexistant target. A middle ground should be achieved by minimizing the complexity of the algorithm and maximizing its accuracy. 
## Algorithm Flowchart
![Algorithm Flowchart](https://github.com/JTJones73/Capstone2024-Team2/blob/Head-On-Sensor-Subsystem/Documentation/Images/Flowchart.png)
The above flow chart demonstrates how a frame is processed to determine the location of the target. This is repeated multiple times per second which C1 mandates at least 10 per second with a maximum of 90 times per second (maximum frame rate from selected camera see below). A consideration for improving detection is an adaptive threshold filter which would increment or decrement the threshold of for every pixel based on its brighness relative to the current threshold. The drawback to the system shown above is it is possible for it to have a false positive. However, by appropriately using algorithms, applying filters, and utilizing other sensors this drawback can be mitigated.    
## Analysis
### Algorithm
The image recognition algorithm works by applying a threshold filter to the camera thus rounding each pixel to either black or white. From here a moving window is scanned across the image counting the number of white pixels. The area with the highest number of white pixels is a possible location for the golf ball. This works by cross correlating the threshold filtered image with the desired signal of a white square. This shows the area of the image that has the highest concentration of white.
### Time Efficiency
To the constraint of a 100ms to report the relative location of the golf ball there must be at least 10 processed frames per second. The algorithm will be running alongside the aiming controller, therefore transmission time does not need to be accounted for. To enhance the speed of the algorithm the lowest possible resolution should be used. The computational time complexity of the algorithm relative to the image's resolution is O(n^2) demonstrating a reduction in resoloution results in a square reduction for time requirement.
## Bill of Materials
| Item | Description | Part Number | Brand | Quantity | Price | Total |
| --- | --- | --- | --- | --- | --- | --- | 
|Camera|Camera that connects to Raspberry Pi through the pcie port giving VGA video quality at 90 FPS|Raspberry Pi Camera V2|AdaFruit|1|$30.99|$30.99|
|Total| | | | | | |$30.99|

## Refrences
[]
[]
[]

