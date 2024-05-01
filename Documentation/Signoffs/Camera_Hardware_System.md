# Camera Hardware System
## Functionality
The Camera Hardware System is responsible for the design of a 2 degree of freedom steerable camera system capable of capturing images of in-flight Unmanned Aerial Systems (UAS) or their control stations and sending them to the database storage.
## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1| System shall capture an image of the UAS in flight or the control station| Stakeholder Constraint|
|  2| Images captured by the system shall be transmitted to the database in either a RAW or PNG format with a minimum resolution of 1080px720p | Design Constraint|
|  3| Servo motors shall be capable of reaching and maintaining angles required for image capture with a ± X° range of accuracy [^x]| Design Constraint and [Camera Software Constraint](Camera_Software_System.md)|
|  4| Servo motors shall be capable of reaching required angles in a minimum time of X milliseconds after recieving the appropriate signal(s)| Design Constraint|
|  5| Camera system enclosure will meet minimum water resistance standard requirements of IPX6 or NEMA 4(X) to protect sensitive electronics| Design Constraint|
|  6| System Camera zoom and focus shall not be controllable by system software| Design Constraint|
|  7| Camera System shall be placed in an area for maintenance personel and locked with lecturn keys for tamper-resistance. | Security Constraint|
|  8| Camera System shall not draw more than X Watts of power, with 5 - 8 Volts and X Amps being needed for the entire system | Power Constraint|


<sup>1</sup> Tracking UAS systems while they are in-flight is essential for an accurate and clear image. Stakeholders did not specify whether or not we should account for visual obstructions such as light or physical structures in 100% of our pictures due to the importance placed on the Remote ID data being collected instead. This system is to serve as a supplementary system, collecting visual evidence to assist Tech Police in stopping non-authorized UAS pilots and building a visual evidence case against repeat offenders.

<sup>2</sup> By storing the photo in a RAW file format, we are able to preserve as much image quality as possible. Along with this, secondary image processing can convert this to a smaller format for long-term storage if and when required.

<sup>3</sup> The level of servo precision will become increasingly important for quality image capture as the zoom increases and the field of view (FOV) decreases.

<sup>4</sup> Rapid input response of servo motors ensures that the camera has a chance to capture the image before the UAS moves out of frame.

<sup>6</sup> Protection of sensitive electronics and exposed circuit wiring/contacts from incoming water is essential for ensuring the safety of the system, building, and personnel in proximity.


<!--|  1 | Shall capture an image of an Unmanned Aerial System (UAS) in-flight or the UAS pilot.  | Project Proposal|
|  2 | Shall capture a quality image of the drone from a maximum of X meters away to ensure image quality of 1080x720p, X ppi.| Design Constraint|                  
|  3 | Shall track drone across contiguous airspace using Remote ID location data, or will track the pilot if they are closer. | Concept Design|
|  4 | System shall resist weather and external conditions to an IPXX rating (temp) | Maintainence Constraint|
|  5 | Servo Motors shall be capable of tracking UAS entities up to speeds of x m/s 
|  6 | Camera images shall be stored in a raw format to be later saved as Jpeg by the database

<sup>1</sup> Capturing an image of the drone and/or the pilot is a large part of evidence collection and assists campus police in stopping unauthorized drone flight from repeat offenders.

<sup>2</sup> Limiting image capture to X meters ensures that images are sharp, clear, and properly utilize our data storage.

<sup>3</sup> Drone and control station telemetry data is required to know when the drone or pilot is in range of the camera.

<sup>4</sup> To ensure reliability of system, environmental interference must be limited and mitigated by proper protective measures.. -->

## Schematic
In Revision <!--![V1_rev0_Screenshot](https://github.com/mrnye42/Drone-Tracker-Project/assets/158204925/2343008d-0690-4712-a40f-2eaa0785611a)-->
## Analysis
For this subsystem, the following components and atomic-subsystems will be required.

### Microprocessor
The central processor chosen for this project is the Raspberry Pi 4B. This microcontroller, with a 4 core, 1.5 GHz ARM processor 8 GB of RAM and on-board wifi/bluetooth, will meet and exceed our parameters for processing speed, reliability, and data transmission[^1]. This board will be used to interface with each powered device in this subsystem, as well as sending a status monitioring package to the website for maintenance and security purposes. The contents of the status package will be defined in the [Camera Software System](Camera_Software_System.md), along with how often it is sent.<!--[More fluff here]-->

### Servo Motor
For this system, we have chosen to use servo motors for the pan and tilt control of our camera. Servo motors, compared to stepper motors, are much more precise and have higher holding torques [^2]. By using a Pulse-Width Modulated (PWM) signal, we can specify the servo angle to an almost exact number, with a feedback signal telling the controller when to stop. Servo motors contain a microcontroller and potentiometer to control the feedback and output response.

By feeding the motors a PWM signal proportional to the direction and altitude of the drone or user, we can direct the camera to point directly at the intended target and capture an image for Campus Police to utilize at their discretion.

### Camera
The camera selected for this application is an ELP 8MP camera containing a Sony IMX317 Camera sensor. The attached lens has variable manual zoom, focus, and ISO, with a focal length ranging from 2.8 - 12 mm 


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
[^1]: Raspberry Pi, "raspberry-pi-4-product-brief,pdf", [https://docs.arduino.cc/resources/datasheets/A000067-datasheet.pdf](https://datasheets.raspberrypi.com/rpi4/raspberry-pi-4-product-brief.pdf) (Accessed April 14, 2024)
[^2]: Thin Thin Hlaing, Tin Tin Nwet, Soe Myat, "Overview of Differences between Servo and Stepper Motor Technology" - ISSN , https://tinyurl.com/mrd79fpb (Accessed April 10, 2024).
<!--etc.-->

