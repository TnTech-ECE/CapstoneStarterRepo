# Camera Hardware System
## Functionality
The Camera Hardware system will be responsible for taking an image of a drone in-flight or the drone's pilot and saving it to the tracker database for usage by campus police.

## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | Shall reliably capture an image of a drone in-flight or the pilot | Project Proposal|             
|  2 | Shall capture a quality image of the drone from X meters away to ensure image quality| Design Constraint|                          
|  3 | Shall track drone across contiguous airspace using Remote ID location data | Design Constraint|
|  4 | Shall resist weather and external conditions to a reasonable degree| Project Supervisor|

<sup>1</sup> Capturing an image of the drone is a large part of evidence collection and can assist campus police in stopping unauthorized drone flight from repeat offenders

<sup>2</sup> Limiting image capture to X meters ensures that images are sharp, clear, and properly utilize our data storage.

<sup>3</sup> Drone telemetry data is required to know when the drone is in range of the camera.

<sup>4</sup> To ensure reliability of system, environmental interference must be limited and mitigated by proper protective measures.

## Schematic

## Analysis
For this subsystem, the following atomic subsystems, with their justification, will be required.

### Servo Motor
For this subsystem, we have chosen to use servo motors for the pan and tilt control of our camera. Servo motors, compared to stepper motors, are much more precise and have higher holding torques [^1]. By using a Pulse-Width Modulated (PWM) signal, we can specify the servo angle to an almost exact number, with a feedback signal telling the controller when to stop.
### Camera
### Microprocessor


## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
| Digital Servo, 25 kg torque, 270 degrees Control Angle | DS3218| 1x4| $51.98| $51.98|
| Digital Servo, 25 kg torque, 180 degrees Control Angle| DS3225MG| 1x4| $54.89| $54.89|
| Arduino Mega R3 Microcontroller| ATmega 2560| 1x1| $29.99| $29.99|
| RunCam FPV Micro Drone Camera 5.8 GHz 160 degree FOV| Phoenix 2 SE| 1x1| $26.99| $26.99|
| Arduino Wifi Microcontroller Unit| ESP8266| 1x3| $16.39| $16.39|
| Camera Pan/Tilt Gimbal| 3D-Printed, Custom| 1x1| $-.--| $-.--|
| System Enclosure| 3D-Printed, Custom| 1x1| $-.--| $-.--|
|Total     |             |          |                | $180.24|

## References
<!-- This is how to do footnotes for the references: --> 
Here is a simple footnote[^1].
[^1]: Thin Thin Hlaing, Tin Tin Nwet, Soe Myat, "Overview of Differences between Servo and Stepper Motor Technology" - ISSN , https://tinyurl.com/mrd79fpb (Accessed April 10, 2024).
[^2]: Reference 2 
[^3]: Reference 3
<!--etc.-->
