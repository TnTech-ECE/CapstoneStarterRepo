# Camera Hardware System <!--(Theory, Design, Analysis of Design, BOM)-->
## Functionality
The Camera Hardware System is responsible for the design of a 2 degree of freedom, steerable camera system capable of capturing images of in-flight Unmanned Aerial Systems (UAS) or their control stations and sending them to the database storage. This system will also monitor itself for errors and report them to the database when applicable.

## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1| System shall capture an image of the UAS in flight or the control station| Stakeholder Constraint|
|  2| System shall not take into consideration light levels or physical obstructions when capturing images|Stakeholder Constraint|
|  3| Images captured by the system shall be transmitted to the database in either a RAW or PNG format with a minimum resolution of 1080px720p| Design Constraint|
|  4| Camera zoom, focus, and light sensitivity (ISO) are not required to be controlled by system software| Design Constraint|
|  5| Servo motors shall be capable of reaching and maintaining angles required for image capture with a ± 10° range of accuracy | Design Constraint and [Camera Software Constraint](Camera_Software_System.md)|
|  6| Servo motors shall be capable of reaching required angles in a minimum time of 500 milliseconds after recieving the appropriate signal(s)| Design Constraint|
|  7| Camera system enclosure will meet minimum water resistance standard requirements of IP65 or greater to protect sensitive electronics| Environmental Constraint|
|  8| Camera system shall not draw more than 50 Watts of power| Design, Safety, and [Camera Power System Constraint](Power_System_Camera.md)|
|  9| Camera system shall utilize IEEE Standard 802.11[^1] and Tennessee Tech Policy 856 [^2]| Standard|
| 10| Camera system shall send a notification to the database if an error state persists beyond an acceptable limit| Reliability and Maintainance Constraint|
| 11| Camera system shall not operate in environmental conditions exceeding a temperature range of (0 - 50)° C| Reliability, Maintance, Design Constraint|

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

<sup>11</sup> Attempting to operate the system in temperature ranges exceeding the devices' temperature limits may cause permanent, irreprable damages to the electronics

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

#### Servo - Usage
The servos used in this system will be the ZOSKAY DS3218 20KG digital servo motors, with one having the traditional 180° range of motion (ROM) seen in many other servos, and the other having a 270° ROM. According to the schematic, the names Servo 0 and Servo 1 will be assigned to the 270° servo motor and 180° servo motor respectively. By attaching these to a bracket system as shown below, we will be able to have tilt and pan control of our camera component.

<img src= "/Documentation/Images/Camera Hardware System/servo.jpg" width="400" height="334"> <img src= "/Documentation/Images/Camera Hardware System/servo_bracket.jpg" width="340" height="334">

### Camera
The camera selected for this application is a 12.3MP IMX477 with a pre-installed tripod mount a C/CS lens mount to increase the camera's image range and clarity. This camera has a base resolution of 4056 x 3040 pixels [^7][^8], allowing for pictures to be crisp and clear in almost all conditions. The chosen varifocal lens has a focal length ranging from [4-12 millimeters], allowing for the system to be tuned to a wider or more narrow view when installed. To communicate and control the camera shutter, the camera will be connected using a 3 ft (91.44 cm) Camera Serial Interface (CSI) ribbon cable to the respective port in the Raspberry Pi. This length was chosen to allow the camera to move as it wishes without risking damaging the connection or the cable. This cable will also be zip-tied as required to restrict excessive movement where it is not necessary.

<img src= "/Documentation/Images/Camera Hardware System/imx477.jpg" width="260" height="353"> <img src= "/Documentation/Images/Camera Hardware System/lens.jpg" width="233" height="353">

### Enclosures
To protect the sensitive electronics required for the control of this system, two polycarbonate enclosures will be utilized. The Raspberry Pi, along with the remainder of the system, will be enclosed within a fully opaque case, while the camera itself will be mounted inside an enclosure with a clear top, allowing for it to view the outside world and capture the UAS mid-flight as intended. These boxes will be rated to protect from water up to a rating of IP66, exceeding our initial constraint of IP65. On each box, two knockout holes will be used to allow the installation of both a vent and cable gland. The gland will allow power and camera connections to pass through the enclosure, while the vent will be used to allow pressure buildup caused by temperature cycling to escape, keeping the system sealed. These add-ons will be followed up with caulk to ensure that the enclosures retain the IP66 water rating. Inside each enclosure will be a dessicant pack, made to absorb any residual moisture that could potentially seep into the box. 

<!--fuuuuuuuu<img src= "/Documentation/Images/Camera Hardware System/SPU_Case.jpg" width="260" height="353"> <img src= "/Documentation/Images/Camera Hardware System/Cam_Case.jpg" width="260" height="353">-->
<!--<img src= "/Documentation/Images/Camera Hardware System/Cable_Gland.jpg" width="260" height="353"><img src= "/Documentation/Images/Camera Hardware System/Case_Vent.jpg" width="260" height="353">-->

### Error Checking
The system will use a network-driven status indicator system to check for any errors. A disconnected network connection, a powered-down SPU, communication issues between the camera and SPU, or lost power to either servo motor, will cause a boolean flag to be set high, prompting the responsible area to perform maintainence and troubleshooting to resolve the issue. This will be further defined in the [Camera Software System](Camera_Software_System.md).

## System Design and Construction
The system shall be built to provide protection from weather elements, while still allowing for communications and the camera to properly function.

### Design - Enclosure and Housings
To satisfy both the visual requirements of the camera, while also protecting the sensitive components, two seperate polycarbonate cases rated at a minimum of IP66 will be utilized. The first enclosure, an SK-16 model, will be used to both house the Raspberry Pi SPU and terminate the electrical connections of the system. This enclosure (labled B0), with exterior dimensions of (5.12" x 5.12" x 2.95") inches and interior dimensions of (4.78" x 4.78" x 2.45") inches, will be able to contain our SPU (3.46" x 2.28" x 0.77") inches along with a 6 circuit terminal block. A CG-32 Cable Gland, capable of handling (0.170 - 0.450) inch (4.318 - 11.43 mm) diameter wires, will be installed to allow the SPU, servo motor wires and the camera's CSI ribbon wire to enter/exit the enclosure. Along with this, a vent will be installed to allow excessive pressure to bleed out from the inside of the case. All thru-hole components will be reinforced with electronics grade silicon sealant to ensure that no moisture can enter the electronic's case, and the enclosure will have three 20 g desiccant packs to draw out any moisture that manages to get past these protections. These desiccant packs are typically reported to be capable of continuous usage for 1 - 3 years [^10], with ideal conditions increasing this to the higher end of the spectrum. However, our enclosure will not live within these conditions, so we will expect these to be replaced once per year at minimum, with more frequent changes leading to more system reliability.

The second polycarbonate case, labeled B1, will be used to house the camera and its telephoto lens. This enclosure is an SK-25-03 model, with exterior dimensions of (3.70" x 2.56" x 3.10") inches and interior dimensions of (3.36" x 2.22" x 2.71") inches, will be able to contain our camera + lens assembly (1.50" x 1.50" x 2.42") inches when installed vertically. With it installed dead-center of the enclosure, along with having enough space for the CG-34 Cable Gland and UA-006 Pressure Vent, there will be enough space for both a potential future upgrade of the camera module and the desiccant packs used to prevent any unintended moisture ingress from the environment.

For both enclosures, stainless steel screws and polymer PCB standoff kits will be used, allowing for solid electrical connections, stable components, and ample protection from environmental factors such as corrosion and weathering. For permanent mounting of the boxes to the deployment location, the fastener material will be dependant on the substrate present. Concrete, lumber, and various other material will have vastly different anti-corrosion requirements and must be evaluated on a case-by-case basis.

<!--<img src= "/Documentation/Images/Camera Hardware System/Enclosure_1.jpg" width="260" height="353"><img src= "/Documentation/Images/Camera Hardware System/Enclosure_2.jpg" width="260" height="353">-->

### Design - Electrical
<img src= "/Documentation/Images/Camera Hardware System/Schematic_CamHardware_Rev2.png" width="624" height="386">
To satisfy the power requirements of the system, while also protecting the electronics and physical safety of surrounding personnel and property, this system must be properly grounded and rated to conduct the full load amperage (FLA) in the scenario of max power draw. A C-type connector will be required to deliver power to the Raspberry Pi, while the Servo motors will require terminations of +5 VDC and a ground in order to recieve power. The camera will draw power from the CSI ribbon cable connection, but will likely require the Raspberry Pi to draw its full rated amperage in order to make the system work. 

To make the terminations, all powered wires will be inter-connected via a screw-terminal distribution block located inside of the PI enclosure B0. This connection method will require a wire connector to be crimped and heat-shrink wrapped to each wire landed onto the terminal connections. The main power line coming in from the Camera Power System will be pulled into the enclosure via the cable gland installed into the side of the cabinet. The +5 VDC power wire (Black) will be terminated onto the first terminal of the distribution block. Given that we need to make three wire terminations, with one being the Raspberry Pi's power cable and the other two belonging to the servo motors, we will keep them on seperate terminals in an effort to minimize disruptions caused by servo motor noise. To accomplish this, small jumper wires will be included to jump to two more connections. A similar setup will be created for the ground wires.

The wires for the servo signal connections will be comprised of a 3 conductor, 22 ga. stranded cable connected to the native wires on the servos. To connect to the servo motor wires, the original wires will be cut, stripped, soldered, and heat-shrunk with dielectric grease in order to protect the bare connection. Using two traditional Dupont wiring pin-connectors that comes with the Raspberry Pi, this will be connected to the appropriate pins of the Raspberry Pi in order to transmit the PWM signals. The power wires will have a terminal connector to land onto the distribution block, while the PWM pins will be soldered and heat-shrink wrapped in order to connect to the Raspberry Pi GPIO pins. These cable conneections are then routed to the servo mounted externally to the control unit.
<!--The colored schematic will be shown below
image[]-->

### Construction
The full physical schematics, along with a mock-up of the full system assembly, is displayed below.

Construction will begin with setting the internal mounting plates into the enclosure, and securing with the provided screws. This will serve as the mounting surface for our components, allowing us to install self-tapping fasteners and PCB standoffs to ensure the components do not move. After this is set into place, installation of the cable glands and vent plugs will proceed. The chosen enclosures come with M16/M20 knockout plugs, allowing us to install the glands and plugs without compromising the waterproofing rating. After taking a screwdriver to knock out the plug holes and deburring any polymer that leaves a sharp edge, EG silicon will be applied to the exterior and interior mating surfaces of the bore hole. Once placed, the components will be installed and allowed to cure, ensuring that a small amount spills out to the sides of the components to fill in any gaps from potential defects.

Once completed, installation of the system electrical components can begin. For the Pi and camera units, four PCB standoff kits will be utilized. For the terminal block, a  To attach them to the mounting surface, these standoffs come with a small piece of 3M adhesive pad, enabling the securing of the PCB without drilling or potentially damaging the PCB. To install, isopropyl alchohol will be used to wipe down the aluminum mounting surface, removing grease, dirt and debris to ensure a solid connection. The kits will be pushed into the four holes of the Pi and camera unit, and will then be installed. Once installed, (securing the PI and terminal block with the proper screws), the wires for supplying the SPU and servo motors with power can be brought in and terminated onto the first half of the terminal block, while the ground wires will be terminated onto the second half.



## Design Analysis

### Camera
The camera selected for this system will be capable of taking images in a RAW12/10/8 or COMP8 (JPEG format) at a resolution of 12.3 Megapixels, and an ADC resolution of 10 - 12 bits [^8]. This gives 1024 grey levels, or storage areas to range the incoming wavelengths of light from pure black to pure white. The more levels present, the more "crisp" the image will appear. This rating is also known as the bit depth. To find the average image size of a picture taken, we can use the equation below [^12]:

$\ S_i = R_i * B_d / 8000$ [^13]

Where Image Size is equal to Image Resolution times Bit Depth divided by 8000. The resultant number can then be converted to the proper SI unit for the number of bytes. For the camera chosen, most images will be at a minimum size of 196.8 Kilobytes and an expected maximum size of 787.2 Kilobytes. This file size will be able to be processed, locally stored, and transmitted by the processor in a matter of milliseconds. The exact time however will be dependant on the wi-fi signal strength of the SPU, which must be determined when the install is conducted.

//
### Processor
The Raspberry Pi 4B selected for this design will contain a 64 bit quad core processor capable of clock speeds up to 1.5 GHz, 8 GB of LPDDR4 RAM, and the option to slot up to a 2 TB microSD card for storage with a transfer rate capped at 50 MB/s [^11].

#### Temperature limits
Both the processor and the camera have a temperature operating range of 0° C to 50° C (32° F to 122° F), severely limiting the capabilities of the system. To mitigate this, while also retaining the waterproof rating of the enclosure, heatsinks are provided with the SPU to be applied to the CPU and the USB controller chip, reducing temperatures onboard and enabling the pi to run constantly. Another mitigation, especially in the intense heat experienced in the southern states, will be to install the system in an area where it can remain in perpetual shade, keeping the system cooler than typically seen in direct sunlight. Mitigations in the cold weather become harder, as temperatures can fall into the negative °F ranges in the winters. So, for especially cold and especially hot conditions, this system will be rendered inoperable and will need to be shut down.

### Servos and System Power
These servo motors have a pulse-width range of 500 ~ 2500 micro-seconds (μs), alongside a deadband width of 3 μs. In other words, these servo motors will not respond to a change in pulse-width less than or equal to 3 μs, which can limit our angle resolution in niche cases where a small adjustment is needed to center the UAS or control station in center-frame of the camera. The minimum angle change attainable by a servo motor can be found in the equation below, where $t_{max}$ is the upper limit of the pulse duty cycle time, $t_{min}$ is the lower limit, and $\tau_{DBand}$ is the deadband limit from the spec sheet:

$\ \Delta\theta_{min} = \frac{(\theta_{max} - \theta_{min})}{t_{max} - t_{min}} * ( \tau_{DBand} + 1) $

This equation gives us a minimum angle change of 0.54° for Servo 0 and 0.36° for Servo 1. The chart below shows the range of motion for both devices.

<img src= "/Documentation/Images/Camera Hardware System/Servo_Angle_Chart.png" width="345" height="225">

The system, with the servo motors and raspberry Pi pulling power directly from the [Camera Power System](Camera_Power_System.md) and a camera drawing power from the Pi's camera connection, will be expected to draw approximately 46.42 Watts at peak power consumption. This can be calculated by multiplying the voltage by the current drawn, and adding the result for a full system draw. The full table can be seen below.

| Component | Min Voltage (V)| Max Voltage (V)| Min Current (A)| Nax Current (A)| Min Power (W)| Max Power (W)|
| --------- | ---------------| -------------- |----------------| -------------- | ------------ | ------------ |
| Raspberry Pi 4B, 8 GB Memory| 5| 5| 2.5| 3.0| 12.5| 15.0|
| Digital Servo, 20 kg torque, 180 degrees Control Angle| 5| 6.8| 1.8| 2.2| 9| 14.96|
| Digital Servo, 20 kg torque, 270 degrees Control Angle| 5| 6.8| 1.5| 2.2| 7.5| 14.96|
| Raspberry Pi HQ camera| 5| 5| 0.3| 0.3| 1.5| 1.5|
| Total     |                |                |  6.1 A         |  7.1 A         |  30.5 W        |  46.42 W     |

By supplying a power supply capable of delivering 50 Watts in the event of every component pulling the maximum current at 5 V, we will increase the system reliability and prevent undercurrent events with our Pi processor. One concern can be drawn from seeing the servo motor potentially drawing 6.8 volts in a 5 volt system, but this will not be a concern to worry about here, as the servo motors chosen are designed to run at 5 volts, but can run at a higher voltage if a system is capable of supplying it.


### 
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
| CSI Flex Ribbon Cable, 3.28 ft / 100 cm | B087FDJ2RP| 1x1| $5.49| $5.49|
| Polycase Polycarbonate Enclosure| SK-16| 1x1| $26.93| $26.93|
| Aluminum Mounting Plate for SK-16| SK-16K| 1x1| $11.21| $11.21|
| Polycase Polycarbonate Enclosure, Clear Cover| SK-25-03| 1x1| $16.84| $16.84|
| Aluminum Mounting Plate for SK-25| SK-12K| 1x1| $7.80| $7.80|
| Mounting Kit for Sk Series enclosures, 4pc.| SK-99| 1x2| $3.36| $6.72|
| Polycase Enclosure Cable Gland, IP68, M20| CG-32| 1x2| $2.86| $5.72|
| Polycase Enclosure Vent Plugs, IP67| UA-006| 1x2| $3.89| $7.78|
| 6 Ckt. Terminal Block + 24 pc crimp connectors| B09VSYYD66| 2x1| $6.99| $6.99|
| Cable, 3 Conductor, 22 GA., 16.5 ft, PVC Insulation| B0CDLS4NQ1| 1x1| $8.98| $8.98|
| PCB 0.25" Adhesive Standoffs| B0C7QQ97GG| 24x1| $6.29| $6.29|
| 20g Desiccant Packs| B09DSDX4P3| 15x1| $6.99| $6.99|
| Electronic Grade Silicon Caulk, 2.8oz| ASI 388| 1x1| $9.99| $9.99|
|Total     |             |          |                | $340.04|

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
[^10]: [Desiccant FAQ Page](https://dryndry.com/pages/faqs) (Accessed Sept 13, 2024)
[^11]: [Tom's Hardware Review of RBPi 4B](https://www.tomshardware.com/reviews/raspberry-pi-4) (Accessed Sept 13, 2024)
[^12]: [Image Size Calculator](https://www.calculatoratoz.com/en/image-file-size-calculator/Calc-36784) (Accessed Sept 13, 2024)
[^13]: [Bit Depth, Full Well, and Dynamic Range](https://www.photometrics.com/learn/camera-basics/bit-depth) (Accessed Sept 13, 2024)
<!--etc.-->

