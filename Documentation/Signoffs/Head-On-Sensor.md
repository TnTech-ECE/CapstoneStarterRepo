# Head On Position Sensor
## Functionality
The purpose of the head on position sensor is to determine the target's location relative to the interceptor. Sensing equipment shall be attached to the front of the interceptor facing the test bed. The sensor will then read in data and make the necessary calculations to determine the X, Y, and Z position of the target. Higher accuracy is expected in the X and Y direction rather than Z, as to get an accurate reading on depth a time of flight sensor would be required with a high sampling rate, and this would be difficult and expensive given the test bed is only 6 feet long [1].
## Constraints
* C7: The sensor apparatus shall detect approaching objects and relay the target's location to the interceptor
   * This subsystem will act in conjunction with other position sensors to be able to effectively track the target in three dimensions. Even though the head on position sensor is connected to the interceptor, and does not require wireless communication, to comply with this constraint it must have a method of relaying the target's position to the aiming subsystem.
* C23: The head on position sensor shall have a maximum latency of 100ms and provide updates at least 10 times per second.
  * This is to comply with a project wide constraint that each sensing system shall be able to report its location in less than 100ms after the event took place. More explanation is given below about how time is budgeted to ensure a successful target interception.
* C24: The head on position sensor shall be able to detect the target at a range of 6 feet to 2 feet away with an accuracy of 1.5 inches in the horizontal direction and 3.5 inches in the vertical direction. This subsystem is not expected to provide useful information about the target's depth.
  * There are a total of 30 lines the target can be on arranged in two rows of 15 strings. At a distance of 4 feet which is the intended locating zone there are four inches between each line and seven inches between each row. Therefore, at the detection distance of four feet the reported location can be off by 2 inches left or right and 3.5 inches up and down. If the measured location is outside this window it will be closer to another string causing the system to report and incorrect string. The radius of the target is 0.78 inches, so if the reported location is off by more than 1.56 inches then it must be having a false reading as this would mean the target is outside of the scanned area, however by implementing motion detection in the image processing it is possible to extend this area allowing for easier detection at further distances.

Horizontal Error = $\sqrt{{(x_{\text{reported}} - x_{\text{actual}})^2 + y_{\text{actual}}^2 + z_{\text{actual}}^2}}$

Vertical Error = $\sqrt{{x_{\text{actual}}^2 + (y_{\text{reported}} - y_{\text{actual}})^2 + z_{\text{actual}}^2}}$

Note: in both equations $x_{\text{actual}}$ and $y_{\text{actual}}$ are adjusted to account for the distance the target is from the interceptor. Although this subsystem may be useful for depth detection it is not this subsystem's expectation to provide useful depth information.
### Explanations for C23 and C24
The fastest the target can cross the game board is 1.78 seconds as given by the customer. Therefore, in order to have a chance to intercept the target the time among subsystems must be properly managed. The following table shows the budgeted delay for all subsystems.

| Subsystem    | Time |
| -------- | ------- |
| Networking  | 20ms    |
| Head on Position Sensor | 100ms     |
| Aiming    | 100ms    |
| Launching | 30ms |

As shown in the above table the total delay is 250ms which demonstrates that time is a limiting factor and deserves the most consideration going forward with the design.

The intention is to determine the target's location by using image recognition. The head on position sensor will be a camera connected to a Raspberry Pi facing the test bed. By using an image recognition algorithm, the relative X and Y position will be determined. By knowing the target's depth, camera resolution, and camera's field of view the X and Y location can be determined. The algorithm will also return the target's diameter allowing for an approximate calculation of its depth. This is possible in 100ms as shown in a demonstration by Adrian Rosebrock [2] showing a ball that is tracked in real time with minimal delay. The goal with image processing is to have as low latency as possible and to maximize the number of updates per second. A major issue with an image processing algorithm is the possibility of a false positive where the controller reports the location of nonexistent target. A middle ground should be achieved by minimizing the complexity of the algorithm and maximizing its accuracy. 

The selected camera's horizontal field of view is 62.2 degrees and has a horizontal resoloution of 640 pixels. At a distance of 6 feet with an angle of 62.2 degrees the camera would detect 325 inches horizontally. Divide this over 640 pixles and this shows that each pixel translates to 0.508 inches horizontally. To meet constraint 24 the algorithm would be required to report the golf ball's location within 3 pixles horizontally.
The camera has a vertical field of view of 48.8 degrees, and at a distance of six feet this translates to 382 inches vertically. This distance divided over 480 pixles shows each pixel represents 1.25 inches meaning to comply with C24 the image processing needs to be less than three pixels off to be able to correctly report the target's location. 
## Electrical Schematic
<p align="center">
  <img src="https://github.com/JTJones73/Capstone2024-Team2/blob/Head-On-Sensor-Subsystem/Documentation/Electrical/Schematics/PI_CAM_Schematic_REV2.JPG"
>
</p>
The wiring schematic for this subsystem is simple as the camera's wiring is contained within its ribbon cable. Four pins from the ribbon cable do connect to the normal GPIO header. GPIO0 and GPIO1 are used for the serial connection between the camera and the Raspberry Pi; GPIO2 and GPIO 3 are used for the camera's enable and webcam activity pins. The ribbon cable provides power, ground, and data. The data interface is a camera serial interface also known as MIPI CSI. The Raspberry Pi 5 supports 15 pin 2 lane MIPI-CSI allowing the camera to send two streams of image data to the Pi simultaneously [3]. The camera draws up to 250mA at 3.3 volts [4]. The camera's ribbon cable is 610mm and can be extended with a 15-pin flex cable extender with 1mm pitch.

### Mounting
The camera will be mounted on the interceptor facing the test bed giving a frontal point of view to detect incoming targets. The camera must be in a stationary location so that all reported locations are consistent, permitting the camera to track the target in three dimensions. The Pi Camera V2 has four mounting holes that accept M2 mounting screws which would permit the camera to be securely mounted on the interceptor. 
## Analysis

### Algorithm
The image recognition algorithm works by applying a threshold filter to the camera thus rounding each pixel to either black or white. From here a moving window is scanned across the image counting the number of white pixels. The area with the highest number of white pixels is a possible location for the golf ball. This works by cross correlating the threshold filtered image with the desired signal of a white square. This shows the area of the image that has the highest concentration of white.

### Algorithm Flowchart
<p align="center">
  <img src="https://github.com/JTJones73/Capstone2024-Team2/blob/Head-On-Sensor-Subsystem/Documentation/Images/Flowchart.png"
>
</p>

The above flow chart demonstrates how a frame is processed to determine the location of the target. This is repeated multiple times per second which C23 mandates at least 10 per second with a maximum of 90 times per second (maximum frame rate from selected camera see below). A consideration for improving detection is an adaptive threshold filter which would increment or decrement the threshold of for every pixel based on its brightness relative to the current threshold. 

### Known Limitations
The drawback to the system shown above is that it is possible for it to have a false positive. It is also possible to have a false negative, as locations that are naturally lighter will have a reduced sensitivity; it is possible that the target may not contrast enough with the background to allow the algorithm to properly locate it. Even if more complicated convoloution based algorithms are used they can still fall victim to interference. However, the team is permitted to configure the environment of the interceptor. By avoiding strange patterns, white backgrounds, and sources of light, the likelihood of an error can be mitigated. By using a properly setup environment, searching algorithms that predict the target's expected trajectory, and alternate signals to reconcile with the head on position sensor, the threat of false positives and negatives can be diminished. 
### Time Efficiency
For the constraint of a 100ms to report the relative location of the golf ball there must be at least 10 processed frames per second. The algorithm will be running alongside the aiming controller, therefore transmission time does not need to be accounted for. To enhance the speed of the algorithm the lowest resolution should be used that provides adequate location accuracy. The computational time complexity of the algorithm relative to the image's resolution is O(n^2) demonstrating a reduction in resolution results in a square reduction for time requirement.
## Bill of Materials
| Item | Description | Part Number | Brand | Quantity | Price | Total |
| --- | --- | --- | --- | --- | --- | --- | 
|Camera|Camera that connects to Raspberry Pi through the Raspberry Pi camera port giving VGA video quality at 90 FPS and a resoloution of 480 x 640 [5]|Raspberry Pi Camera V2|AdaFruit|1|$30.99|$30.99|
|Total| | | | | | $30.99  | $30.99 |

## References
[1]  “S3I Paper Wad Interceptor Challenge 2024 V3.3.”

[2]  A. Rosebrock, "Ball Tracking with OpenCV," 14September 2015. [Online]. Available:https://pyimagesearch.com/2015/09/14/ball-tracking-with-opencv/. [Accessed 09 04 2024].

[3] 	A. Allan, "Raspberry Pi About the Camera Modules," 2024 20 02. [Online]. Available: https://www.raspberrypi.com/documentation/accessories/camera.html. [Accessed 2024 14 04].

[4] 	"LizUpton", "Rasbperry Pi - Documentation - rpicam_apps_getting_started," 17 01 2024. [Online]. Available: https://github.com/raspberrypi/documentation/blob/4ef432ca21ffe4c0aa3da3276ad39665f7e6a95b/documentation/asciidoc/computers/camera/rpicam_apps_getting_started.adoc#L70. [Accessed 2024 14 04].

[5]  Techinn, “Raspberry Pi Camera V2 Green | Techinn,” tradeinn. https://www.tradeinn.com/techinn/en/raspberry-pi-camera-v2/137489672/p?utm_source=google_products&utm_medium=merchant&id_producte=10405867&country=us&srsltid=AfmBOoq27xq9YAKxXr5o72__pFO3w7NJPo-mX6B66ac9EpWs7bKzp9HcMUc [Accessed Apr. 10, 2024].

