# Experimental Analysis

## Introduction 
The purpose of this report is to verify the requirements for the project and explain the procedures used to validate results. The results will be compared against the measures of success outlined in the project proposal to determine if the project was successful. This will also detail what the next steps are moving forward.

### Requirements

| Item | Constraint/Specification | Subsystem | 
|-|-|-|
| 1 | Shall Create an interceptor capable of functioning on its own without outside interaction. | All Subsystems |
| 2 | Shall Create an interceptor capable of wirelessly communicating with the sensor array. | Networking |
| 3 | Shall Create an interceptor capable of fitting inside a 1x1x1 foot box before powering on. | Housing |
| 4 | Shall Create an interceptor that poses no danger to spectators. | Mechanical Engineers |
| 5 | Shall Create an interceptor that includes a clearly marked power switch. | Housing |
| 6 | Shall Create an interceptor that includes clearly marked emergency stop option on the interceptor. | Housing |
| 7 | Shall Design a sensor array that can detect approaching objects and relay their locations to the interceptor.| Projectile Path Sensor and Velocity And Acceleration Sensor and Head On Position Sensor |
| 8 | Shall Design a sensor array that operates on battery power. | Projectile Path Sensor and Velocity And Acceleration Sensor |
| 9 | Shall Design an interceptor that complies with the safety checklist provided in the competition rules. | Housing |
| 10 | Shall Design an interceptor that has lights. | Housing |
| 11 | Shall Design an interceptor with decorations contributing to camouflaging of the device. | Housing |
| 12 | Shall Design an interceptor which plays an alert noise before firing. | Housing |
| 13 | Shall Design a network that has the capability to have up to six input devices. Due to having six sensor posts that must wirelessly communicate with the interceptor. | Networking |
| 14 | Shall Ensure the interceptor is wired correctly and consistently keeping uniform wire colors across devices. In order to ensure ease of troubleshooting. | All Subsystems |

## Results

### Constraint 1 - Autonomous
In order for this constraint to be met all subsystems must be able to run autonomously. Thus each subsystem must test and verify fully functioning while autonomous.
#### Projectile Path Sensor
The projectile path sensor was designed to determine when a ball has been dropped, determine the projectile line the ball was dropped, and wirelessly communicate this information to the Raspberry Pi. To test that this subsystem can work without outside interaction the subsystem will be tested 5 times by powering on the device dropping a ball and verifying that this subsystem can transmit the information to the Raspberry Pi.
| Trial Number | Determine Ball launched|
|---|---|
| 1 | Yes |
| 2 | Yes |
| 3 | Yes |
| 4 | Yes |
| 5 | Yes |

### Constraint 2 - Wirelessly communicating with the sensor array
#### Networking

### Constraint 3 - Fitting in a 1x1x1 foot box
#### Housing

### Constraint 4 - No Danger to Spectators

### Constraint 5 - Clearly marked power switch
#### Housing
To verify that the power switch is functioning properly the interceptor's power switch will be turned off and on 5 times to verify the system powers on.
| Trial Number | Interceptor Successfully Turned On |
|---|---|
| 1 | yes |
| 2 | yes |
| 3 | yes |
| 4 | yes |
| 5 | yes |

### Constraint 6 - Clearly marked emergency stop option
#### Housing

### Constraint 7 - Detect approaching objects and relay locations
#### Projectile Path Sensor
To verify that the Projectile Path Sensor can detect incoming projectiles from every possible line a ball will be dropped from every line to determine that the sensor can detect all possible lines for incoming projectiles. We conducted 3 trials to verify its success.
| Trial Number |Lines Properly Detected |
|---|---|
| 1 | 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15  |
| 2 |  |
| 3 |  |

### Constraint 8 - Sensor Array Battery Power
#### Projectile Path Sensor
To test that the Projectile sensor will function on battery power, the system will be properly powered with a battery the system will use a 9 Volt battery and will be tested every 5 minutes to verify the system is still functioning.
| Minutes | System Functionality |
|---|---|
| 0 |  |
| 5 |  |
| 10 |  |
| 15 | |
| 20 | |

### Constraint 9 - Saftey Checklist
#### Housing

### Constraint 10 - Lights
#### Housing

### Constraint 11 - Camouflage
#### Housing

### Constraint 12 - Firing alert
#### Housing

### Constraint 13 - Six input Capable Network
#### Networking

### Constraint 14 - Uniform Wireing


