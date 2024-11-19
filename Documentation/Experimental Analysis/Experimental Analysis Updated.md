# Experimental Analysis

## Introduction 
The purpose of this report is to verify the requirements for the project and explain the procedures used to validate results. The results will be compared against the measures of success outlined in the project proposal to determine if the project was successful. This will also detail what the next steps are moving forward.

### System Critical Constraints

| Item # | Constraint/Specification | Subsystem Affected | 
|-|-|-|
| 1 | Shall Create an interceptor capable of functioning on its own without outside interaction. | All Subsystems |
| 2 | The System shall be capable of sensing all 15 lines when a projectile is released.  | Projectile Path Sensor |
| 3 | All external sensors shall be capable of running on battery power.  | Projectile Path sensor and Velocity and Acceleration Sensor |
| 4 | The interceptor shall have a power system be capable of providing power to each component in the main housing. | Power & Housing | 
| 5 | The interceptor shall have a firing system capable of firing a projectile. | Firing | 
| 6 | The interceptor shall have a firing system capable of stopping the firing motor once a round has been fired. | Firing |
| 7 | The interceptor shall have an external sensor capeable of obtaining a distance measurements and time at multiple points across each path. | Velocity and Acceleration|
| 8 | The interceptor shall move into aiming position based on input gathered from sensor data. | Aiming |
| 9 | The interceptor shall move into aiming position before the projectile moves away from the interceptor's range | Aiming |
| 10 | The interceptor shall be able to detect and locate targets head on. | Head on Sensor |
| 11 | When the interceptor is sensing head on targets the maximum sensing latency shall not exceed 100ms. | Head on Sensor |
| 12 | The interceptor shall be able to wirelessly communicate with the sensor array. | Networking |
| 13 | The interceptor shall be able to wirelessly recieve information from no less than 6 devices at the same time. | Networking |

## Analysis
### Projectile Path Sensor
The system critical constraints that are met by the projectile path sensor are:
1. Shall Create an interceptor capable of functioning on its own without outside interaction.
2. The System shall be capable of sensing all 15 lines when a projectile is released.
3. All external sensors shall be capable of running on battery power.

To verify that these constraints are met by the system, the projectile path sensor will be powered on using a 9V battery and with no external interaction a ball will be dropped from all 15 lines to verify that the system can detect and transmit this information to the interceptor.

| Line Number | Projectile Detected |
|---|---|
| 1 | Yes |
| 2 | Yes |
| 3 | Yes |
| 4 | Yes |
| 5 | Yes |
| 6 | Yes |
| 7 | Yes |
| 8 | Yes |
| 9 | Yes |
| 10 | Yes |
| 11 | Yes |
| 12 | Yes |
| 13 | Yes |
| 14 | Yes |
| 15 | Yes |

### Velocity and Acceleration Sensor

### Head on Sensor
10. The interceptor shall be able to detect and locate targets head on.
11. When the interceptor is sensing head on targets the maximum sensing latency shall not exceed 100ms.

### Networking
12. The interceptor shall be able to wirelessly communicate with the sensor array.
13. The interceptor shall be able to wirelessly recieve information from no less than 6 devices at the same time.
### Power & Housing
The critical constraints that are met by the power and housing system are: 

4. The interceptor shall have a power system be capable of providing power to each component in the main housing.

To verify that this constraint is met each electronic device will be powered on the interceptor at the same time. Each component will then be analyzed to verify that it is receiving power. In addition the E-Stop will be tested to ensure that it will turn off the motors when pressed. 

Results: 

Each motor turned when receiving power at the same time as the others. Additionally the buzzer and the lighting in the housing remained on. Finally the Raspberry Pi and the Arduino continued to receive power. The E-Stop functioned correctly by disabling the motors when pressed. 

Link to the video of the experiment
https://youtu.be/wlUcXeGKP3k

### Aiming
The system critical constraints that are met by the aiming system are:
1. Shall Create an interceptor capable of functioning on its own without outside interaction.
8. The interceptor shall move into aiming position based on input gathered from sensor data.
9. The interceptor shall move into aiming position before the projectile moves away from the interceptor's range

To verify that these constraints are met by the system, the main aiming control unit will be powered and recieve data from the raspberry pi usb port and with no external interaction. To simulate position data being sent, the user will input the position data manually and show where the aiming system moves based on that input. This then will be timed based on the greatest number of steps that the aiming motors took to move into position and calulate the aiming duration based on the step speed of the motors. 
### Firing

The system critical constraints that are met by the firing system are:
1. Shall Create an interceptor capable of functioning on its own without outside interaction.
5. The interceptor shall have a firing system capable of firing a projectile.
6. The interceptor shall have a firing system capable of stopping the firing motor once a round has been fired.


To verify that these constraints are met by the system, the firing motor will be powered on using the housings 12-volt power supply. The main code will then be used to verify that when a signal is sent from the aiming subsystem, the motor turns on, releasing a single round, and will be powered off once the proximity sensor is in line with the timing piece. 






