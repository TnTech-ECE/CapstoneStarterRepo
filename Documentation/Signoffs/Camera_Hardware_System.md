# Camera Hardware System
## Functionality
The Camera Hardware System is responsible for the design of a 2 degree of freedom steerable camera system capable of capturing images of in-flight Unmanned Aerial Systems (UAS) or their control stations and sending them to the database storage. This system will also monitor itself for errors and report them to the database when applicable.

## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1| System shall capture an image of the UAS in flight or the control station| Stakeholder Constraint|
|  2| System shall not take into consideration light levels or physical obstructions when capturing images|Stakeholder Constraint|
|  3| Images captured by the system shall be transmitted to the database in either a RAW or PNG format with a minimum resolution of 1080px720p| Design Constraint|
|  4| Camera zoom, focus, and light sensitivity (ISO) shall not be controllable by system software| Design Constraint|
|  5| Servo motors shall be capable of reaching and maintaining angles required for image capture with a ± X° range of accuracy [^x]| Design Constraint and [Camera Software Constraint](Camera_Software_System.md)|
|  6| Servo motors shall be capable of reaching required angles in a minimum time of X milliseconds after recieving the appropriate signal(s)| Design Constraint|
|  7| Camera system enclosure will meet minimum water resistance standard requirements of IPX6 or NEMA 4(X) to protect sensitive electronics| Environmental Constraint|
|  8| Camera system shall not draw more than 40 Watts of power, with 5 - 7 Volts and X Amps being needed for the entire system| Design, Safety, and [Camera Power System Constraint](Power_System_Camera.md)|
|  9| Camera system shall utilize IEEE Standard 802.11[^1] and Tennessee Tech Policy 856 [^2]| Standard|
| 10| Camera system shall send a notification to the database if an error state persists beyond an acceptable limit| Reliability and Maintainance Constraint|

<sup>1</sup> Tracking UAS systems while they are in-flight is essential for an accurate and clear image.

<sup>2</sup> Stakeholders did not specify whether or not we should account for visual obstructions such as light or physical structures in 100% of our pictures due to the importance placed on the Remote ID data being collected instead. This system is to serve as a supplementary information collector, accumulating visual evidence to assist Tech Police in stopping non-authorized UAS pilots and building up evidence against repeat offenders.

<sup>3</sup> By storing the photo in either a RAW or PNG file format, we are able to preserve as much image quality as possible. Setting minimum resolution to 1080px720p ensures captured images are higher quality.

<sup>4</sup> Camera zoom, focus, and ISO will be set once upon install to ensure consistency in image quality with the surveyed area.

<sup>5</sup> Precise setting of servo angles ensures that drone is in the center of the image frame when a picture is captured.

<sup>6</sup> Rapid input response of servo motors ensures that the camera has a chance to capture a stable image before the UAS moves out of frame.

<sup>7</sup> Protection of sensitive electronics and exposed circuit wiring/contacts from incoming water is essential for ensuring the safety of the system, along with nearby personnel and property.

<sup>8</sup> Limiting power draw ensures that the power delivery system will be able to keep up with this system without overcurrent or brown-out incidents.

<sup>9</sup> IEEE standards help to decrease internet traffic and ensure appropriate data transfer rates. Tennessee Tech standards ensure that different security levels of data are appropriately protected.

<sup>10</sup> Sending an error status bit to the database ensures any repairs or maintainance is handled in a timely manner, increasing reliability of the system.

## Schematic
<img src= "/Documentation/Images/Camera Hardware System/Schematic_CamHardware_Rev2.png" width="624" height="386">

## Analysis
For this subsystem, the following components and atomic-subsystems will be required.

### Single-Board Computer (SPU)
For the control and communication aspects of this system, a Raspberry Pi 4B Single-Board Computer will be utilized. This board, as specified in the datasheet[^3], contains many processing and peripheral support specifications that will enable this system to run at high speeds. Along with 4 USB 2.0 and 3.0 ports, there are also 16 General Purpose Input-Output (GPIO) pins, 2 of which will be used to host and communicate with the servo motors required for the project. The pinout for this SPU can be seen below.

<img src= "/Documentation/Images/Camera Hardware System/Raspberry_Pi_4B_GPIO_Pinout.png" width="509" height="293">

#### SPU - Use and Analysis
From the schematic, pins 32 and 33 from the sixteen available GPIO pins will be used to send PWM signals to the servo motors, while a<!-- Rasberry Pi Camera will be connected via the CSI port of the SPU --> USB 3.0 port will be used to communicate with the camera. The generation and processing of signals for these devices will be handled and defined by the [Camera Software System](Camera_Software_System.md). This Unit will also be capable of generating and sending a status monitioring package to the website for maintenance and reliability purposes.

### Servo Motor
For the pan and tilt control of this subsystem, brushless DC servo motors will be used due to their accuracy, high holding torques, and ease of control/wiring in comparison to a stepper motor.[^6]

#### Servo - Background Info
Servo motors are electric motors with an in-house microcontroller running a Process-Integral-Derivative (PID) control loop and a feedback potentiometer/absolute encoder used by the controller to generate the error signal for the PID control loop[^4]. Radio-Controlled servo motors utilize three pin wiring harnesses capable of supplying positive voltage, ground, and a Pulse-Width Modulated (PWM) signal to itself[^5]. While the power pins are typically terminated to an external power supply, the PWM pin is connected to a microcontroller's GPIO pin. This pin can be programmed to pulse, forming a square wave with its duty cycle controlling the movement and position of the servo motor's horn.

#### Servo - Use And Analysis
The servos used in this system will be the ZOSKAY DS3218 20KG digital servo motors, with one having the traditional 180° range of motion (ROM) seen in many other servos, and the other having a 270° ROM. According to the schematic, the names Servo 0 and Servo 1 will be assigned to the 270° servo motor and 180° servo motor respectively. These servo motors have a pulse-width range of 500 ~ 2500 micro-seconds (μs), alongside a deadband width of 3 μs. In other words, these servo motors will not respond to a change in pulse-width less than or equal to 3 μs, which can limit our angle resolution in niche cases where a small adjustment is needed to center the UAS or control station in center-frame of the camera. The minimum angle change attainable by a servo motor can be found in the equation below, where $t_{max}$ is the upper limit of the pulse duty cycle time, $t_{min}$ is the lower limit, and $\tau_{DBand}$ is the deadband limit from the spec sheet:

$\ \Delta\theta_{min} = \frac{(\theta_{max} - \theta_{min})}{t_{max} - t_{min}} * ( \tau_{DBand} + 1) $

This equation gives us a minimum angle change of 0.54° for Servo 0 and 0.36° for Servo 1.


<img src= "/Documentation/Images/Camera Hardware System/Servo_Angle_Chart.png" width="345" height="225">

### Camera
The camera selected for this application is an<!-- Arducam 5MP OV5647 Camera with a resolution of 2592 x 1944 pixels. The 23mm focusing lens has a focal length of  --> ELP 8MP USB 3.0 camera containing a Sony IMX317[^7] Camera sensor. The attached lens has variable manual zoom, focus, and ISO, with a focal length ranging from 2.8 mm - 12 mm and the field of view ranging from unspecified values. In the team's experience, these cameras tend to have an FOV rating of X degrees

### Enclosure


### Error Checking


## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
| Raspberry Pi 4B, 8GB Memory| RPI4-MODBP-8GB| 1x1| $75.00| $75.00|
| Digital Servo, 20 kg torque, 270 degrees Control Angle | DS3218MG| 1x1| $14.66| $14.66|
| Digital Servo, 20 kg torque, 180 degrees Control Angle| DS3218| 1x1| $14.66| $14.66|
| ELP 8MP USB 3.0 Camera| ELP-USB4KHDR01-UFV| 1x1| $106.00| $106.00|
| Camera Pan/Tilt Servo Bracket| Generic| 1x1| $9.99| $9.99|
| System Enclosure| 3D-Printed, Custom| 1x1| $-.--| $-.--|
|Total     |             |          |                | $220.31|

## References
<!-- This is how to do footnotes for the references: --> 
[^1]: “IEEE 802.11-2020: Collision avoidance in wireless networks,” American National Standards Institute, Available: https://blog.ansi.org/ieee-802-11-collision-avoidance-wireless-networks/ (Accessed Feb. 19, 2024).
[^2]: “856 data security and handling policy,” Tennessee Technological University, Available: https://www.tntech.edu/policies/ (Accessed May 2, 2024).
[^3]: Raspberry Pi, "raspberry-pi-4-product-brief,pdf", [Raspberry Pi 4B Documentation](https://datasheets.raspberrypi.com/rpi4/raspberry-pi-4-product-brief.pdf) (Accessed May 2, 2024)
[^4]: [What is a Servo?](https://www.electrical4u.com/what-is-servo-motor/) (Accessed May 2, 2024)
[^5]: [Hobbyist Servo Fundamentals](https://www.princeton.edu/~mae412/TEXT/NTRAK2002/292-302.pdf) (Accessed May 2, 2024)
[^6]: [What is a Stepper Motor?](https://www.princeton.edu/~mae412/TEXT/NTRAK2002/292-302.pdf) (Accessed May 2, 2024)
[^7]: [Sony IMX317 Datasheet](https://www.sony-semicon.com/files/62/pdf/p-13_IMX317CQC_Flyer.pdf) (Accessed May 2, 2024)
[^8]: [Servo Datasheet](https://images-na.ssl-images-amazon.com/images/I/81Lbgu+nG6L.pdf) (Accessed May 2, 2024)
<!--etc.-->

