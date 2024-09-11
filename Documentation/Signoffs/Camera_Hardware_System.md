# Camera Hardware System <!--(Theory, Design, Analysis of Design, BOM)-->
## Functionality
The Camera Hardware System is responsible for the design of a 2 degree of freedom, steerable camera system capable of capturing images of in-flight Unmanned Aerial Systems (UAS) or their control stations and sending them to the database storage. This system will also monitor itself for errors and report them to the database when applicable.

## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1| System shall capture an image of the UAS in flight or the control station| Stakeholder Constraint|
|  2| System shall not take into consideration light levels or physical obstructions when capturing images|Stakeholder Constraint|
|  3| Images captured by the system shall be transmitted to the database in either a RAW or PNG format with a minimum resolution of 1080px720p| Design Constraint|
|  4| Camera zoom, focus, and light sensitivity (ISO) shall not be controllable by system software| Design Constraint|
|  5| Servo motors shall be capable of reaching and maintaining angles required for image capture with a ± 10° range of accuracy | Design Constraint and [Camera Software Constraint](Camera_Software_System.md)|
|  6| Servo motors shall be capable of reaching required angles in a minimum time of X milliseconds after recieving the appropriate signal(s)| Design Constraint|
|  7| Camera system enclosure will meet minimum water resistance standard requirements of IP65 or NEMA 4X to protect sensitive electronics| Environmental Constraint|
|  8| Camera system shall not draw more than 50 Watts of power<!--, with 5 - 7 Volts and X Amps being needed for the entire system-->| Design, Safety, and [Camera Power System Constraint](Power_System_Camera.md)|
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

## Design Theory

### Single-Board Computer (SPU)
For the control and communication aspects of this system, a Raspberry Pi 4B Single-Board Computer (or Single Processing Unit) will be utilized. This board, as specified in the datasheet[^3], contains many processing and peripheral support specifications that will enable this system to run at high speeds. Along with 4 USB 2.0 and 3.0 ports, there are also 16 General Purpose Input-Output (GPIO) pins, 2 of which will be used to host and communicate with the servo motors required for the project. The pinout for this SPU can be seen below.

<img src= "/Documentation/Images/Camera Hardware System/Raspberry_Pi_4B_GPIO_Pinout.png" width="509" height="293">

#### SPU - Use and Analysis
From the schematic, pins 32 and 33 from the sixteen available GPIO pins will be used to send PWM signals to the servo motors, while a Rasberry Pi Camera will be connected via the CSI port of the SPU. The generation and processing of signals for these devices, along with the generation of a system status monitoring signal, will be handled and defined by the [Camera Software System](Camera_Software_System.md).

### Servo Motors
For the pan and tilt control of this subsystem, brushless DC servo motors will be used due to their accuracy, high holding torques, and ease of control/wiring in comparison to a stepper motor.[^6]

#### Servo - Background Info
Servo motors are electric motors with an in-house microcontroller running a Process-Integral-Derivative (PID) control loop and a feedback potentiometer/absolute encoder used by the controller to generate the error signal for the PID control loop[^4]. Radio-Controlled servo motors utilize three pin wiring harnesses capable of supplying positive voltage, ground, and a Pulse-Width Modulated (PWM) signal to itself[^5]. While the power pins are typically terminated to an external power supply, the PWM pin is connected to a microcontroller's GPIO pin. This pin can then be programmed to pulse, forming a square wave with its duty cycle controlling the movement and position of the servo motor's horn.

#### Servo - Use And Analysis
The servos used in this system will be the ZOSKAY DS3218 20KG digital servo motors, with one having the traditional 180° range of motion (ROM) seen in many other servos, and the other having a 270° ROM. According to the schematic, the names Servo 0 and Servo 1 will be assigned to the 270° servo motor and 180° servo motor respectively. By attaching these to a bracket system as shown below, we will be able to have tilt and pan control of our camera.

<img src= "/Documentation/Images/Camera Hardware System/servo.jpg" width="400" height="334"> <img src= "/Documentation/Images/Camera Hardware System/servo_bracket.jpg" width="340" height="334">

These servo motors have a pulse-width range of 500 ~ 2500 micro-seconds (μs), alongside a deadband width of 3 μs. In other words, these servo motors will not respond to a change in pulse-width less than or equal to 3 μs, which can limit our angle resolution in niche cases where a small adjustment is needed to center the UAS or control station in center-frame of the camera. The minimum angle change attainable by a servo motor can be found in the equation below, where $t_{max}$ is the upper limit of the pulse duty cycle time, $t_{min}$ is the lower limit, and $\tau_{DBand}$ is the deadband limit from the spec sheet:

$\ \Delta\theta_{min} = \frac{(\theta_{max} - \theta_{min})}{t_{max} - t_{min}} * ( \tau_{DBand} + 1) $

This equation gives us a minimum angle change of 0.54° for Servo 0 and 0.36° for Servo 1. The chart below shows the range of motion for both devices.

<img src= "/Documentation/Images/Camera Hardware System/Servo_Angle_Chart.png" width="345" height="225">

### Camera
The camera selected for this application is a 12.3MP IMX477 with a pre-installed tripod mount a C/CS lens mount to increase the camera's image range and clarity. This camera has a base resolution of 4056 x 3040 pixels [^7][^8], allowing for pictures to be crisp and clear in almost all conditions. The chosen varifocal lens has a focal length ranging from [4-12 millimeters], allowing for the system to be tuned to a wider or more narrow view when installed. To communicate and control the camera shutter, the camera will be connected using a 3 ft (91.44 cm) Camera Serial Interface (CSI) ribbon cable to the respective port in the Raspberry Pi. This length was chosen to allow the camera to move as it wishes without risking damaging the connection or the cable. This cable will also be zip-tied as required to restrict excessive movement where it is not necessary.

<img src= "/Documentation/Images/Camera Hardware System/imx477.jpg" width="260" height="353"> <img src= "/Documentation/Images/Camera Hardware System/lens.jpg" width="233" height="353">

### Enclosures
To protect the sensitive electronics required for the control of this system, two polycarbonate enclosures will be utilized. The Raspberry Pi, along with the remainder of the system, will be enclosed within a fully opaque case, while the camera itself will be mounted inside an enclosure with a clear top, allowing for it to view the outside world and capture the UAS mid-flight as intended. These boxes will be rated to protect from water up to a rating of IP67, exceeding our initial constraint of IP65. On each box, two holes will be bored into the side to allow the installation of a vent and cable gland pieces to be installed. The gland will allow power and camera connections to pass through the enclosure, while the vent will be used to allow pressure buildup caused by temperature cycling to escape, keeping the system sealed. These add-ons will be followed up with caulk or RTV material to doubly ensure that the enclosures retain their IP67 water rating. Inside each enclosure will be a dessicant pack, made to also absorb any moisture that could potentially seep into the box.

[]image

### Error Checking
The system will use a network-driven status indicator system to check for any errors. A disconnected network connection, a powered-down SPU, communication issues between the camera and SPU, or lost power to either servo motor, will cause a boolean flag to be set high, prompting the responsible area to perform maintainence and troubleshooting to resolve the issue. This will be further defined in the [Camera Software System](Camera_Software_System.md).

## System Design and Construction
The system shall be built to provide protection from weather elements, while still allowing for communications and the camera to properly function.

### Design - Enclosure and Housings
To satisfy both the visual requirements of the camera, while also protecting the sensitive components, two seperate polycarbonate cases rated at a minimum of IP66 will be utilized. The first enclosure, labeled B0, will be used to both house the Raspberry Pi SPU, and terminate the electrical connections of the system. This enclosure, with exterior dimensions of (4.53 x 2.56 x 1.57) inches and interior dimensions of (4.21 x 2.24 x 1.38) inches, will be able to contain our SPU (3.46 x 2.28 x 0.77) inches along with any additional terminations. The ~1mm difference will ensure a snug fit, further protecting the SPU from movement and impact damage in the unlikely event of a failure in the mounting bolts. A CG-34 Cable Gland capable of handling 0.105 - 0.315 inch (2.7 - 8 mm) diameter wires will be installed to allow the SPU and servo motor power wires, the camera's CSI ribbon wire, and the PWM pins for the servos to enter/exit the enclosure. Along with this, a vent will be installed to allow excessive pressure to bleed out from the inside of the case. Both connections will be reinforced with electronics grade silicon sealant to ensure that no moisture can enter the electronic's case, and the enclosure will have desiccant packs to draw out any moisture that manages to get past these protections.

The second polycarbonate case, labeled B1, will be used to house the camera and its telephoto lens. This enclosure, with exterior dimensions of (4.40 x 4.40 x 4.33) inches and interior dimensions of (3.75 x 3.75 x 4.00) inches, will be able to contain our camera + lens assembly when installed vertically (1.50 x 1.50 x 2.42) inches. With it installed dead-center of the enclosure, along with having enough space for the CG-34 Cable Gland and UA-006 Pressure Vent, there will be more than enough space for a future upgrade of the camera module, along with the desiccant packs used to prevent any unintended moisture ingress from the environment.

For both enclosures, stainless steel screws will be used extensively throughout, allowing for solid electrical connections along with ample protection from environmental factors. For permanent mounting of the boxes to the deployment location, the fastener material will be dependant on the substrate present. Concrete, lumber, and various other material will have vastly different anti-corrosion requirements and must be evaluated on a case-by-case basis.

### Design - Electrical
<img src= "/Documentation/Images/Camera Hardware System/Schematic_CamHardware_Rev2.png" width="624" height="386">

### Construction

## Design Analysis
<!--Using this variety of metal ensures that the screws will still be removeable after being exposed to the elements over an extended period, while still being conductive enough to allow strong grounding and connection points when terminating wires.
Using EG silicon sealant will make service harder if fail-->

## BOM
| Item     | Part Number | Quantity (pkg x ordered) | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
| Raspberry Pi 4B, 8GB Memory| RPI4-MODBP-8GB| 1x1| $74.99| $74.99|
| Camera Pan/Tilt Servo Bracket| B0BYNBZHD1| 1x1| $9.99| $9.99|
| Digital Servo, 20 kg torque, 180 degrees Control Angle| DS3218| 1x1| $14.66| $14.66|
| Digital Servo, 20 kg torque, 270 degrees Control Angle | DS3218MG| 1x1| $14.66| $14.66|
| Raspberry Pi IMX477 12.3 MP High Quality Camera| SC1220| 1x1| $59.99| $59.99|
| Arducam 4-12mm Varifocal Camera Lens, C-Mount| LN048| 1x1| $49.99| $49.99|
| 3.28 ft / 100 cm CSI Flex Ribbon Cable| B087FDJ2RP| 1x1| $5.49| $5.49|
| Polycase Polycarbonate Enclosure| WP-21| 1x1| $14.28| $14.28|
| Polycase Polycarbonate Enclosure, Clear Cover| ZQ-040404-93| 1x1| $36.74| $36.74|
| Polycase Enclosure Vent Plugs, IP67| UA-006| 1x2| $3.89| $7.78|
| Polycase Enclosure Cable Gland, IP67| CG-31| 1x1| $2.23| $2.23|
| Polycase Enclosure Cable Gland, IP67| CG-34| 1x1| $5.67| $5.67|
| 20g Desiccant Packs| B09DSDX4P3| 15x1| $6.99| $6.99|
| Electronic Grade Silicon Caulk, 2.8oz| ASI 388| 1x1| $9.99| $9.99|
|Total     |             |          |                | $301.45|

## References
<!-- This is how to do footnotes for the references: FIX ME --> 
[^1]: “IEEE 802.11-2020: Collision avoidance in wireless networks,” American National Standards Institute, [Available:](https://blog.ansi.org/ieee-802-11-collision-avoidance-wireless-networks/) (Accessed Feb. 19, 2024).
[^2]: “856 data security and handling policy,” Tennessee Technological University, [Available:](https://www.tntech.edu/policies/) (Accessed May 2, 2024).
[^3]: Raspberry Pi, "raspberry-pi-4-product-brief,pdf", [Raspberry Pi 4B Documentation](https://datasheets.raspberrypi.com/rpi4/raspberry-pi-4-product-brief.pdf) (Accessed May 2, 2024)
[^4]: [What is a Servo?](https://www.electrical4u.com/what-is-servo-motor/) (Accessed May 2, 2024)
[^5]: [Hobbyist Servo Fundamentals](https://www.princeton.edu/~mae412/TEXT/NTRAK2002/292-302.pdf) (Accessed May 2, 2024)
[^6]: [What is a Stepper Motor?](https://www.princeton.edu/~mae412/TEXT/NTRAK2002/292-302.pdf) (Accessed May 2, 2024)
[^7]: [Sony IMX477 Datasheet](https://www.sony-semicon.com/files/62/pdf/p-13_IMX317CQC_Flyer.pdf) (Accessed Sept 4, 2024)
[^8]: [Arducam IMX477 Data and Information](https://www.arducam.com/sony/imx477/) (Accessed Sept 4, 2024)
[^9]: [Servo Datasheet](https://images-na.ssl-images-amazon.com/images/I/81Lbgu+nG6L.pdf) (Accessed May 2, 2024)
<!--etc.-->

