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

<sup>2</sup> Stakeholders did not specify whether or not we should account for visual obstructions such as light or physical structures in 100% of our pictures due to the importance placed on the Remote ID data being collected instead. This system is to serve as a supplementary information collection, accumulating visual evidence to assist Tech Police in stopping non-authorized UAS pilots and building a visual evidence case against repeat offenders.

<sup>3</sup> By storing the photo in a RAW file format, we are able to preserve as much image quality as possible. Setting minimum resolution to 1080px720p ensures captured images are higher quality.

<sup>4</sup> Camera zoom, focus, and ISO will be set once upon install to ensure consistency in image quality with the surveyed area.

<sup>5</sup> Precise setting of servo angles ensures that drone is in the center of the image frame when a picture is captured.

<sup>6</sup> Rapid input response of servo motors ensures that the camera has a chance to capture a stable image before the UAS moves out of frame.

<sup>7</sup> Protection of sensitive electronics and exposed circuit wiring/contacts from incoming water is essential for ensuring the safety of the system, along with nearby personnel and property.

<sup>8</sup> Limiting power draw ensures that the power delivery system will be able to keep up with this system without overcurrent or brown-out incidents.

<sup>9</sup> IEEE standards help to decrease internet traffic and ensure appropriate data transfer rates. Tennessee Tech standards ensure that different security levels of data are appropriately protected.

<sup>10</sup> Sending an error status bit to the database ensures any repairs or maintainance is handled in a timely manner, increasing reliability of the system.

## Schematic
In Revision <!--![V1_rev0_Screenshot](https://github.com/mrnye42/Drone-Tracker-Project/assets/158204925/2343008d-0690-4712-a40f-2eaa0785611a)-->
## Analysis
For this subsystem, the following components and atomic-subsystems will be required.

### Single-Board Computer (SPU)
For the control and communication aspects of this system, a Raspberry Pi 4B Single-Board Computer will be utilized. With advanced control capabilities for periphrials, along with the ability to be loaded with any mainstream operating system necessary, this controller will be the center of this subsystem[^3].

#### SPU - Background Info
The Raspberry 4B, as specified in the datasheet[^3], contains many hardware specifications that will enable this system to run at high speeds. The presence of multiple   , will meet and exceed our parameters for processing speed, reliability, and data transmission.

#### SPU - Use and Analysis
This board will be used to interface with each powered device in this subsystem, as well as sending a status monitioring package to the website for maintenance and reliability purposes. The contents of the status package, along with all applicable data for the control of this system, will be defined in the [Camera Software System](Camera_Software_System.md), along with how often it is transcieved.<!--[More fluff here]-->

### Servo Motor
For the pan and tilt control of this subsystem, brushless DC servo motors will be used due to their accuracy, high holding torques, and ease of control/wiring in comparison to a stepper motor.[^6]

#### Servo - Background Info
Servo motors are electric motors with an in-house microcontroller running a Process-Integral-Derivative (PID) control loop and a feedback potentiometer/absolute encoder used by the controller to generate the error signal for the PID control loop[^4]. Radio-Controlled servo motors utilize three pin wiring harnesses capable of supplying positive voltage, ground, and a Pulse-Width Modulated (PWM) signal to itself[^5]. While the power pins are typically terminated to an external power supply, the PWM pin is connected to a microcontroller's GPIO pin. This pin can be programmed to pulse, forming a square wave with its duty cycle controlling the movement and position of the servo motor horn's position.

#### Servo - Use And Analysis
Gonna totally use it
<!--For this system, we have chosen to use servo motors for the pan and tilt control of our camera. Servo motors, compared to stepper motors, are much more precise and have higher holding torques [^2]. By using a Pulse-Width Modulated (PWM) signal, we can specify the servo angle to an almost exact number, with an internal feedback signal telling the controller when to stop. Servo motors contain a microcontroller and potentiometer to control the feedback and output response.

By feeding the motors a PWM signal proportional to the direction and altitude of the drone or user, we can direct the camera to point directly at the intended target and capture an image for Campus Police to utilize at their discretion.-->

### Camera
The camera selected for this application is an ELP 8MP USB 3.0 camera containing a Sony IMX317[^7] Camera sensor. The attached lens has variable manual zoom, focus, and ISO, with a focal length ranging from 2.8 mm - 12 mm and a field of view of

### Enclosure

### Error Checking


## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
| Raspberry Pi 4B, 8GB Memory| SC0195(9)| 1x1| $75.00| $75.00|
| Digital Servo, 25 kg torque, 270 degrees Control Angle | DS3218| 1x4| $51.98| $51.98|
| Digital Servo, 25 kg torque, 180 degrees Control Angle| DS3225MG| 1x4| $54.89| $54.89|
| ELP 8MP USB 3.0 Camera| ELP| 1x1| $106.00| $106.00|
| Camera Pan/Tilt Gimbal| 3D-Printed, Custom| 1x1| $-.--| $-.--|
| System Enclosure| 3D-Printed, Custom| 1x1| $-.--| $-.--|
|Total     |             |          |                | $180.24|

## References
<!-- This is how to do footnotes for the references: --> 
[^1]: “IEEE 802.11-2020: Collision avoidance in wireless networks,” American National Standards Institute, Available: https://blog.ansi.org/ieee-802-11-collision-avoidance-wireless-networks/ (Accessed Feb. 19, 2024).
[^2]: “856 data security and handling policy,” Tennessee Technological University, Available: https://www.tntech.edu/policies/ (Accessed May 2, 2024).
[^3]: Raspberry Pi, "raspberry-pi-4-product-brief,pdf", [Raspberry Pi 4B Documentation](https://datasheets.raspberrypi.com/rpi4/raspberry-pi-4-product-brief.pdf) (Accessed May 2, 2024)
[^4]: [What is a Servo?](https://www.electrical4u.com/what-is-servo-motor/) (Accessed May 2, 2024)
[^5]: [Hobbyist Servo Fundamentals](https://www.princeton.edu/~mae412/TEXT/NTRAK2002/292-302.pdf) (Accessed May 2, 2024)
[^6]: [What is a Stepper Motor?](https://www.princeton.edu/~mae412/TEXT/NTRAK2002/292-302.pdf) (Accessed May 2, 2024)
[^7]: [Sony IMX317 Datasheet](https://www.sony-semicon.com/files/62/pdf/p-13_IMX317CQC_Flyer.pdf) (Accessed May 2, 2024)
<!--etc.-->

