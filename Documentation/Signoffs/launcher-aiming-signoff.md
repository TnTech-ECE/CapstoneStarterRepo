# Launcher Aiming
## Functionality
The Launcher Aiming subsystem will take in signals from the sensor post reciever and head on projectile sensor, determine the position of the target and adjust the launcher's position accordingly. This subsystem will also calculate the timing to fire the projectile and send a signal to the launcher firing subsystem. The launcher's position is controlled by two motors: one to adjust the yaw (turntable) and one to adjust the pitch (launch angle).
## Subsystem Constraints 
* C1: Launcher pitch and yaw shall be controllable to a precision of within 0.6 degrees
* C2: Time to move launcher into aiming position shall be less than 0.322 seconds.
* C3: The launcher pitch actuator shall have at least 0.68 Nm of torque to move the launcher turntable and the launcher yaw actuator must have 0.013 Nm of torque to move the launcher barrel. These values were provided by the mechanical engineering group.
## Explanations for C1 and C2
For C1, the precision of the actuators needs to be taken into account because the less precise that the angle of the launcher is, the less accurate the intercepting shot will be over a distance. In addition, the precision is crucial because the intercepting projectile will have a dispersion from the target associated with it. 
An experiment was conducted to determine the worst-case dispersion of an intercepting projectile. The specified projectile is a 3-inch long, half-inch diameter cylinder, with an exit velocity of approximately 30 feet per second. The launcher aims to intercept projectiles within 36 inches from the back of a blue square on the game board. Due to difficulty in building an exact launcher, a Nerf dart gun was used, matching the specified projectile size, shape, and velocity. The gun was fixed in position to control spread. Ten shots were fired at a target 36 inches away, with liquid chalk marking impacts. Maximum dispersion between shots was 1.25 inches in diameter. To significantly alter target direction, the center of the dart must hit the outer edge of the target. This is explained in the figure below:
![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/cjdrake42-Launcher-Aiming-Signoff-V3-1/Documentation/Images/ProjectileDispersion.png)
Factoring in the maximum dispersion diameter of 1.25 inches from the expirement, it was calculated that the maximum tolerance that the interceptor could have is +/- 0.74 degrees from 36 inches away. To be conservative the constraint will be 20 percent tighter allowing for around +/- 0.6 degrees of precision of the pitch and yaw actuators. 

DEVCOM provided drop times for C2 from their developed game board. The fastest recorded drop time was 1.98 seconds on line 8, height 2. Assuming a potential 15% increase in speed at a worst-case drop time of 1.78 seconds, the projectile path sensor, if placed at the front edge of the game board, would detect the target's path in about 0.74 seconds ($t_{firstdetection}$). It takes 1.27 seconds ($t_{targetdistance}$) to reach the longest interception point of 28 inches from the back of the blue square in the arena layout. 
![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/cjdrake42-Launcher-Aiming-Signoff-V3-1/Documentation/Images/Ball_travel_times.png)

This leaves 0.53 seconds ($t_{intercept}$) for processing, aiming, and launching the projectile shown in the equations below.
$$t_{intercept} = t_{first detection} - t_{target distance}$$
$$t_{intercept} = t_{launch} +t_{travel}+t_{sensordelay}+t_{process}+t_{aim}$$
Considering it takes 0.08 seconds to launch the projectile and 0.078 seconds for the launcher projectile to travel 28 inches away at 30 feet per second to intercept the target, with a 0.03-second delay in projectile path sensing and an estimated maximum processing time of 0.02 seconds, there's a maximum of 0.322 seconds to move the launcher to aim to the target. 

![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/cjdrake42-Launcher-Aiming-Signoff-V3-1/Documentation/Images/Timing_Chart.png)
    

## Buildable Schematics
### Electrical Scheamtic
![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/cjdrake42-Launcher-Aiming-V3/Documentation/Electrical/Schematics/image-2.png)

The electrical shematic shows the connections between the microcontroller [1], turntable motor driver [2], turntable motor [3], launch angle motor driver [4], and launch angle motor [5]. The microcontroller - Rasperry Pi 5, was chosen due to it having all the needed pins to drive the stepper motors while having ample processing power for the head-on sensing subsystem. The motors chosen was due to the torque requirements needed to move the launcher based on the launcher's weight and moment of inertia. The motor drivers were recommended by the motor purchasing website to control the motors based on the the motors' current rating.
## Analysis
### Aiming Speed
For the turntable motor, it's determined that the launcher's starting yaw angle will be perpendicular to the A-frame of the game board. The maximum yaw angle from this starting position is 62 degrees, ensuring a minimum launch distance of 12 inches from the farthest fishing line. A NEMA 23 class motor, with a recommended operating speed of 100 rpm[6], is chosen and can move 62 degrees in 0.103 seconds, meeting C2 requirements.

For the launch angle motor, the launcher's firing angle ranges from 10 to 60 degrees, with 35 degrees being its midpoint. The maximum vertical movement needed is 25 degrees. A NEMA 8 class motor, with a recommended maximum operating speed of 100 rpm, is selected. With a pulley system ratio of 3:2, the motor needs to move 37.5 degrees to adjust the launcher by 25 degrees. This movement takes 0.06 seconds, also meeting C2.
### Torque Requirements
The Mechanical Engineering group requried 0.68 Nm of torque from the turntable motor in order to move the weight of the turntable. The selected motor's torque has a maximum torque of 0.73 Nm shown in the graph below obtained from the datasheet [7] which satisfies the Mechanical Engineering group's torque requirement.
![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/cjdrake42-Launcher-Aiming-V3/Documentation/Electrical/Schematics/image-3.png)

For the launch angle motor, the Mechanical Engineers required 0.013 Nm of torque to move the launcher's barrel. The selected motor for should provide ample torque with a maximum torque of 0.14 Nm at 0.6 A shown in the graph below obtained from the datasheet [8].
![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/cjdrake42-Launcher-Aiming-V3/Documentation/Electrical/Schematics/image-4.png)
### Precision
Both stepper motors have a 1.8  degree step angle. Both drivers have capablility to have different step resolutions, including 1/2, 1/4, 1/8 steps. If selected to 1/4 step mode, the motors will have a precision of 0.45 degrees. The turntable motor will be directly connected to the turntable giving the turntable angle a precision of 0.45 degrees. The launch angle motor is connected to a pulley system with a ration of 3:2 yeilding a precision of 0.3 degrees for the pitch angle This is within the requirement the launcher aiming having a precision of 0.6 degrees in both motors.
### Motor Power Requirements
The turntable stepper motor requires 2.8 A of current to be driven. The driver for the turntable motor is rated for up to 4 A and has a SPI interface that controls the current limit programmatically. The launch angle stepper motor requires 0.6 A of current to be driven. The driver chosen is rated to supply up to 2 A of current which should be sufficient to power the motor. The current limit can be ajdusted by a potentiometer on the driver board and will need to be calibrated to reach the desired current output of 0.6 A. 
## Bill of Materials
| Name of Item   | Description                                                                  | Part Number     | Manufacturer     | Quantity     | Price      | Total   |
|----------------|------------------------------------------------------------------------------|-----------------|------------------|--------------|------------|---------|
| Turntable Motor | The turntable motor allows the launcher to turn left and right                 | 1478           | Polulu      | 1        | 47.95       |  47.95    |
| Turntable Motor Driver     | The motor driver supplies the voltage and current to the motor.                                   | 3730           | Polulu      | 1            |  28.95        |  28.95     |
| Launch Angle Motor          | The motors will allow the launcher to move the pitch up and down.                 | 2267            | Pololu           | 1            |  28.95       |  28.95   |
| Launch Angle Motor Driver    | The motor driver supplies the voltage and current to the motor.                           | 1182            | Pololu           | 1   |  13.95        |  13.95    |
| Microcontroller| The microcontroller communicates with the master control and motor drivers.  | Raspberry Pi 5 4 GB RAM | Adafruit          | 1            | 60.00       | 60.00    |
| Total          |                                                                              |                 |                  |              | Total Cost | $179.95 |
  
## References
[1]A. Industries, “Raspberry pi 5 - 4 GB RAM,” adafruit industries blog RSS.  [Online]. Available: https://www.adafruit.com/product/5812?gad_source=1&gclid=Cj0KCQjwzZmwBhD8ARIsAH4v1gXGg02jbP5Q13riRbMYuD5OUOXIthSaszyXwI7qs_mdn8cTXS-ut4QaAlArEALw_wcB. [Accessed: 08-Apr-2024] 

[2]“Pololu High-Power Stepper Motor Driver 36V4,” Pololu Robotics & Electronics.  [Online]. Available: https://www.pololu.com/product/3730. [Accessed: 08-Apr-2024] 

[3]“Pololu - Stepper Motor: Bipolar, 200 steps/REV, 57×56mm, 2.5V, 2.8 A/phase,” Pololu Robotics & Electronics.  [Online]. Available: https://www.pololu.com/product/1474. [Accessed: 08-Apr-2024] 

[4]“Pololu - A4988 Stepper Motor Driver Carrier,” Pololu Robotics & Electronics.  [Online]. Available: https://www.pololu.com/product/1182. [Accessed: 08-Apr-2024] 

[5]“Pololu - Stepper Motor: Bipolar, 200 steps/REV, 20×30mm, 3.9V, 0.6 A/phase,” Pololu Robotics & Electronics.  [Online]. Available: https://www.pololu.com/product/1204. [Accessed: 08-Apr-2024] 

[6]“What is the maximum speed (highest frequency) of the Stepper Motor?,” StepperOnline.  [Online]. Available: https://www.omc-stepperonline.com/support/what-is-the-maximum-speed-highest-frequency-of-the-stepper-motor. [Accessed: 08-Apr-2024] 

[7]SY57STH56-2804A.  [Online]. Available: https://www.pololu.com/file/0J674/SY57STH56-2804A.pdf. [Accessed: 08-Apr-2024] 

[8]SY20STH30-0604A.PDF - pololu robotics and electronics.  [Online]. Available: https://www.pololu.com/file/0J635/SY20STH30-0604A.pdf. [Accessed: 08-Apr-2024] 
