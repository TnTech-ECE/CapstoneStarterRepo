# Launcher Aiming Control Unit
## Functionality
The launch aiming control unit handles the different functions within the launcher. This includes controlling the signals for the motors for the launcher aiming subsystem, sending a signal for the buzzer to indicate that the launcher is about to fire, and sending a signal to the launcher firing subsystem indicating to fire.
## Constraints
C1: The launch aiming control unit shall have at least 7 GPIO pins, 2 Ground pins, 1 SCK pin, 1 MISO pin, 1 MOSI pin, 1 VCC pin, 1 Camera Ribbon Cable to connected to the launcher aiming control to supply the needed amount of pins for each subsystem. The needed pins for each subsystem in the launcher aiming control unit are listed below:
### Housing Subsystem
| Type of Pins | Number |
|--------------|--------|
| GPIO | 1 |
| GND | 1 |

### Aiming Subsystem
| Type of Pins | Number |
|--------------|--------|
| VCC | 1 |
| GPIO | 5 |
| SCK | 1 |
| MOSI | 1 |
| MISO | 1 |
| GND | 1 |
### Launching Subsystem
| Type of Pins | Number |
|--------------|--------|
| GPIO | 1 |
### Head-On Sensing Subsystem
| Type of Pins | Number |
|--------------|--------|
| Camera Ribbon Cable | 1 |
### Total Pins
| Type of Pins | Number |
|--------------|--------|
| Camera Ribbon Cable | 1 |
| GPIO | 7 |
| GND | 2 |
| SCK | 1 |
| MOSI | 1 | 
| MISO | 1 |
| VCC | 1 |

C2: The launcher aiming control unit shall have the ability to have network communication. This is to recieve data between the projectile path sensing and the velocity and acceleration sensing subsystems located on the sensor posts.

C3: The launcher aiming control unit shall play an alert noise before firing. This constraint originated from the DEVCOM Rulebook. According to a study published in the NIH journal, the minimum duration to modify human behavior is 200 ms [1]. In order to ensure bystanders are alerted, the minimum duration of the alert noise shall be 200 ms.

C4: The launcher aiming control unit shall control the pitch and yaw angles of the launcher and compute the time to fire for the launcher firing system. This system will utilize the projectile path sensing, head on sensing, and projectile velocity and accelartion sensing system.

## Electrical Schematic
![alt text](image-5.png)

## Analysis
### C1 Solution:
The Raspberry Pi 5 was chosen as the controller for the launcher aiming control unit. The pin types that are included on the controller vs the pins needed are listed in the table below:
#### Raspberry Pi 5
| Type of Pins | Pins Included | Pins Needed|
|--------------|--------|--------------|
| Camera Ribbon Cable | 1 | 1 |
| GPIO | 26| 7 |
| VCC | 2 | 1 |
| 3.3 V | 2 | 0 |
| GND | 8| 2 |
| ID EEPROM |2| 0 |
| SCK | 2| 1 |
| MOSI| 2| 1 |
| MISO| 2| 1 |

As seen in the table above, the raspberry pi 5 should have the sufficient pins for the to control each subsystem [2]

### C2 Solution:

The Raspberry Pi 5 can communicate wirelessly with the sensor post controllers using UDP packets. This is shown in a tutorial by AranaCorp [3]. 

### C3 Solution:

The fastest calculated time from first detection to interception is 530 ms as shown in the graphic below.The buzzer will be turned on at the first instance that the projectile path sensing signal is recieved and will be turned off before the the firing signal is sent. Given that the buzzer cannot alert after the launcher is fired and the maximum sensor delay for the path sensing is 30 ms, the maximum time for the buzzer to alert is 342 ms. This is a sufficient amount of time to meet the constraint.

![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/main/Documentation/Images/Timing_Chart.png)

  
### C4 Solution: 
#### Process Diagram
![alt text](<Launcher Aiming Control Block Diagram.png>)
#### Process Description
The launcher aiming system recieves inputs from the projectile path sensing system and the head-on sensing system to locate what fishing line the target is traveling on and at what height. Once the controller has determined the path and height, it sends signals to the stepper motor drivers to adjust the position of the launcher. The launcher aiming system is controlled by sending pulses to the STEP pin of the drivers and sending a signal to the DIR pin to indicate direction. It is important to note that the vendor of the stepper motor drivers explicitly states that the motor position can be controlled precisely without a feedback system in place [4]. Since each step signal corresponds to a degree step to the stepper motors for the launcher aiming system, the posistion of the launcher in reference to  the starting position can be determined based on the number of step pulses sent to the driver.

$$ \theta_{aim} = n_{steps}*\theta_{step} $$

To calculate the time to fire, the launcher aiming takes inputs from the projectile velocity and accelartion sensing and finds the time to fire in the equations below:

$$ x_{travel} = x_{target} - x_{intercept} $$

$$ t_{intercept} = \frac{-v_{target} + \sqrt{v_{target}^2-4a_{target}x_{travel}}}{2a_{target}} $$

$$ t_{fire} = t_{intercept } - t_{aim} - t_{process} - t_{sensordelay}-t_{launch}-t_{launchtravel} $$

Once the time to fire is up, it sends a signal to the buzzer to indicate it is about to fire and sends the signal is sent to the launcher firing mechanism to fire a projectile.

Once a projectile is fired, the launcher aiming motors move back to the starting reference point. To get back to the starting reference point, simply set the same sumber of pulses to the STEP pin and invert the DIR signal. 
## Bill Of Materials
* Components needed for this signoff have already been requested other signoffs
## References
[1] https://www.ncbi.nlm.nih.gov/pmc/articles/PMC4347839/#R26

[2] https://www.raspberrypi.com/documentation/computers/raspberry-pi.html#gpio-and-the-40-pin-header

[3] https://www.aranacorp.com/en/udp-communication-between-raspberry-pi-and-esp32/

[4] https://www.pololu.com/category/120/stepper-motor-drivers 
