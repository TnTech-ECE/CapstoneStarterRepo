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

To verify that these constraints are met by the system, the projectile path sensor will be powered on using a 9V battery and with no external interaction a ball will be dropped from all 15 lines to verify that the system can detect and transmit this information to the interceptor. This test will be ran twice to verify that the system did not have any false posisitives.

| Line Number | Projectile Detected Trial 1|Projectile Detected Trial 2|
|---|---| ---|
| 1 | Yes | Yes |
| 2 | Yes | Yes |
| 3 | Yes | Yes |
| 4 | Yes | Yes |
| 5 | Yes | Yes |
| 6 | Yes | Yes |
| 7 | Yes | Yes |
| 8 | Yes | Yes |
| 9 | Yes | Yes |
| 10 | Yes | Yes |
| 11 | Yes | Yes |
| 12 | Yes | Yes |
| 13 | Yes | Yes | 
| 14 | Yes | Yes |
| 15 | Yes | Yes |

With this test, we can verify all required constraints for the projectile path sensor are met. First, all 15 possible lines can be detected and this data wirelessly transmits to the main interceptor. Also, this test verifies that the entire sensor array is able to be powered. Finally, the entire subsystem is autonomous. With this test, we can conclude that the Projectile Path Sensor is complete and fully functioning.

### Velocity and Acceleration Sensor
The system critical constraints that are met by the Velocity and Acceleration Sensor system are:
1. Shall Create an interceptor capable of functioning on its own without outside interaction.
3. All external sensors are capable of running on battery power.
7. The interceptor shall have an external sensor capable of obtaining a distance measurement and time at multiple points across each path.

To verify that the constraint 7 is met by the system, the Velocity and Acceleration sensor will be set up on the center of the second sensor post like it will be for the competition and is to be tested in that positon. To test that the system is capable of obtaining a distance measurement and time at multiple points on each path and satisfies this constraint the sensor will be aimed at each line and a ball will be placed to verify that a distance measurement and time is able to be recorded at multiple places. Point 1 is 27 inches away from the sensor, point 2 is 25 inches away from the sensor, and point 3 is 23 inches away from the sensor.

Test Results:

| Line Number | Projectile Detected & Time Recorded Point 1 | Projectile Detected & Time Recorded Point 2 | Projectile Detected & Time Recorded Point 3 |
|---|---|---|---|
| 1  | Yes | Yes | Yes |
| 2  | Yes | Yes | Yes |
| 3  | Yes | Yes | Yes |
| 4  | Yes | Yes | Yes |
| 5  | Yes | Yes | Yes |
| 6  | Yes | Yes | Yes |
| 7  | Yes | Yes | Yes |
| 8  | Yes | Yes | Yes |
| 9  | Yes | Yes | Yes |
| 10 | Yes | Yes | Yes |
| 11 | Yes | Yes | Yes |
| 12 | Yes | Yes | Yes |
| 13 | Yes | Yes | Yes |
| 14 | Yes | Yes | Yes |
| 15 | Yes | Yes | Yes |

To verify that constraints 1 and 3 are met by the system, the Velocity and Acceleration sensor will be powered by a 3.7V LiPo battery and will be set up and have the same placement as in the previous test. To ensure the system is capable of operating without outside intervention and running on battery power the following test will be conducted. After the sensor is set up as previously described a ball will be dropped on line 1 to verify that the sensor will turn to the line to obtain the distance and time measurements and transmit this information to the interceptor. This will prove that the system is capable of operating without outside interaction and running on battery power.

Expected Results: 
Given that the networking subsystem has been proven to be working in the Projectile Path Sensor, the Velocity and Acceleration Sensor will meet constraints 1 and 3.
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






