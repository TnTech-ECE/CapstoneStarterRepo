# Launcher Aiming
## Functionality
The Launcher Aiming subsystem will take in signals from the sensor post reciever and head on projectile sensor, determine the position of the target and adjust the launcher's position accordingly. This subsystem will also calculate the timing to fire the projectile and send a signal to the launcher firing subsystem. The launcher's position is controlled by two motors: one to adjust the yaw (turntable) and one to adjust the pitch (launch angle).
## Constraints 
* C1: Create an interceptor capable of functioning
on its own without outside interaction.
* C3: Create an interceptor capable of fitting inside
a 1x1x1 foot box before powering on.
* C20: Launcher pitch and yaw must be controllable to a precision of within 0.6 degrees
* C21: Time to move launcher into aiming position must be less than 0.40 seconds.
* Aiming speed will be calculated from worst-case torque requirements provided by the Mechanical Engineering group
## Explainations for C20 and C21
For C20, the precision of the actuators needs to be taken into account because the less precise that the angle of the launcher is, the less accurate the intercepting shot will be over a distance. In addition, the precision is crucial because the intercepting projectile will have a dispersion from the target associated with it. To find the dispersion of the intercepting projectile, an experiment was conducted to find worst-case dispersion of the intercepting projectile. The mechanical engineering group have specified that the intercepting projectile will be a 3-inch long, half inch diameter cylinder and the projectile exit velocity will be around 30 feet per second. It was also specified that the maximum distance that the the launcher would attempt to intercept a projectile would be around 36 inches from the back of the blue square of the game board. Given that it would be difficult to build an exact design of the launcher at this time, the expiriment uses a nerf dart gun which has a similar projectile size, shape and exit velocity as what was specified by the mechanical engineering group. To control the projectile spread, the gun was mounted in such a way that the position of the gun would not change from shot to shot. Once the gun was mounted, a target was set up 36 inches away given that would be the farthest desired distance to intercept. To keep track of where the dart hit the target, liquid chalk was applied to the dart so as it impacted it would show a mark indicating where it had hit the target. After firing 10 shots with this setup, it was determined that the maximum dispersion between shots was about 1.25 inches in diameter. It was then inferred that to noticably change the direction of the target, the center of the dart would have to hit the outer edge of the target. Factoring in the maximum dispersion diameter of 1.25 inches from the expirement, it was calculated that the maximum tolerance that the interceptor could have is +/- 0.74 degrees from 36 inches away. To be conservative the constraint will be 20 percent tighter allowing for around +/- 0.6 degrees of precision of the pitch and yaw actuators. 

For C21, DEVCOM gave the team a set of drop times from the game board that they developed. The fastest drop time recorded was 1.98 s on line 8 height 2. Assuming that the target has a potential to travel 15 percent faster at a worst-case drop time of 1.78 s, it could be determined that the projectile path sensor if placed at the front edge of the game board, the time it would take for the path of the target would be around 0.74 s. It will also take 1.27 s to reach the longest point of interception of 28 inches from the back of the blue square in the arena layout, leaving 0.53 s to process, aim the launcher, and launch the projectile to intercept. Given that it will take 0.08 s to launch the projectile and 0.078 s for the launcher to intercept a projectile from 28 inches away at 30 feet per second, the projectile path sensing has a delay of 0.03 s, and the maximum processing time is estimated to take 0.02 s, it leaves 0.40 s as the maximum time to move the launcher to the target.
    

## Buildable Schematics
### Electrical Scheamtic
![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/cjdrake42-Launcher-Aiming-V3/Documentation/Electrical/Schematics/image-2.png)
The electrical shematic shows the connections between the microcontroller [1], turntable motor driver [2], turntable motor [3], launch angle motor driver [4], and launch angle motor [5]. The microcontroller - Rasperry Pi 5, was chosen due to it having all the needed pins to drive the stepper motors while having ample processing power for the head-on sensing subsystem. The motors chosen was due to the torque requirements needed to move the launcher based on the launcher's weight and moment of inertia. The motor drivers were recommended by the motor purchasing website to control the motors based on the the motors' current rating.
## Analysis
### Aiming Speed
For the turntable motor, it has been determined that the launcher starting yaw angle will be perpendicular to the a-frame of the game board. It was determined that the largest yaw angle that the launcher would make from the starting angle would be 62 degrees assuming that the minimum launch distance would be 12 inches from the farthest fishing line from the interceptor. The motor chosen for the turn table is a NEMA 23 class motor mounted directly to the turntable. The NEMA 23 class motors have a recommended operating speed of 100 rpm [6]. To move 62 degrees at 100 rpm would take 0.103 s, well below the time needed to meet C21. For the launch angle motor, it was determined that the minimum angle from the ground that the launcher would fire from would be around 10 degrees and the maximum angle would be around 60 degrees to have a range from 12-36 inches from the middle of the blue square. The launcher itself would sit in the middle of this range at 35 degrees from the ground. Making the maximum vertical angle that the launcher would need to move to be around 25 degrees. The launch angle motor is attached to a pulley system that has a ratio of 3:2 meaning that the launch angle motor would have to move 37.5 degrees in order to move the launcher 25 degrees. The motor selcted is a NEMA 8 class motor. The recommended maximum operating speed for this class motor is around 100 rpm. To move 37.5 degrees, it would take the motor 0.06 s, which meets C21.
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
