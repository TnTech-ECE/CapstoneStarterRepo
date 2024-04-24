## Functionality
The Launching and Firing subsystem is the system that will fire the intercepting round when given a signal from the aiming subsystem. This system will also control the power to the DC motor used to operate the firing mechanism and preload the launching apparatus so that each round may fire with minimum delay once the aiming subsystem has completed it's processes. 

## Explanation of DC Motor Signal Control
This subsystem will use a 12-volt DC brushed motor along with a relay that will use a signal from the aiming subsystem as an input to allow the DC motor to operate. This signal will be sent for the amount of milliseconds that it will take the firing apparatus to fire a round, and return to the preloaded condition. This time will be found once the Mechancial Engineering team has finished constructing their design. Due to the nature of the ME team's design for the firing apparatus, once in preload, the motor will be in a state where there will be no load just before activation of the motor. Once activated by the aiming subsystem's signal the motor will then go through the firing cycle, resetting the interceptor. The final stage of this cycle, when the motor will be returning into the no load section of the firing cycle, will have a margin of error of 15 degrees in either direction (this number is a "safe" number the ME team provided based on their design, it is more likely the acceptable margin of error is higher than 15 degree in either direction but this number they felt safe with using) in which the position of the output shaft can come to rest.(The motor will be geared 30:1, more on this below) During testing and experimentation, the device will be honed in to stop as closely as possible to the most optimal position for the mechanism to function properly by changing the amount of time that the activation signal is sent to the relay controlling this subsystem's DC motor used to fire the interceptor.

## Specifications and Restraints
| Number | Constraint | Constraint description | Origin |
|------|--------------------|------------------------|------------|
| 1. | NEC 310.15(B)(16) | The Launching and Firing subsystem shall use appropriate wiring for all connections within the subsystem as according to the ampacity limits listed in the NEC 310.15(B)(16) table | NEC 310.15(B)(16) |
| 2. | Fire without human interaction | The Launching and Firing subsystem shall fire without any human interaction with the field of play or the launching apparatus itself | DEVCOM competition rulebook |
| 3. | Fit within a cubic foot of space | The Launching and Firing subsystem shall fit within a cubic foot of space (1 ft by 1 ft by 1 ft) along with the other subsystems that will be placed within that space. For this subsystem, the chosen motor to operate the firing mechanism shall have a length less than 3 inches not counting the shaft, and a diameter less than 3 inches. | DEVCOM competition rulebook |
| 4. | Motor Torque | The Launching and Firing Mechanism shall operate the firing mechanism on the launcher apparatus using a moto of at least 3.2 OZ-IN | Mechanical Engineering Team Specification |
| 5. |  Signal-to-Fire delay | The Launching and Firing subsystem shall fire a round within 80 ms after receiving the signal from the aiming subsystem. This is the amount of time left after accounting for all other subsystems to complete their processes during the worst case scenario. | Team Specification |
| 6. | Preloading after firing | The Launching and Firing subsystem shall reset the preload condition after each round is fired within 0.79 seconds. | Team Specification | 


## Buildable Schematic
### Electrical Schematic 
![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/jlburke42-signoff-Launching-and-Firing/Documentation/Images/CapstoneDrawing2.png)

As seen in the schematic above, the Adafruit relay will be powered off the 3.3V pin (PIN1) of the Raspberry Pi 5. While the GPIO pins are limited to 50mA, this pin can support 3.3V up to 500mA. The Adafruit 3191 relay only draws 100mA while operating. A signal will be sent from GPIO 6 (PIN31) which shall switch allow the relay to switch from connecting "COMM" and "Normally Connected" to connecting "COMM" to " Normally Closed" allowing the motor to be powered from the 12V bus from the Housing subsystem. This motor shall draw 9A upon startup and when reaching it's stall point and will be wired with 16 AWG wire from the Housing subsystem.

## Analysis 

**Constraint Solution 1:**
The Launching and Firing subsystem shall use 16 AWG wire for the subsystems electrical connections. This wire has an ampacity rating of 10 amps over a distance of 12 inches. This wire size was selected by considering the largest ampacity draw that exists in the subsystem. For this the team decided to use the start/stall current (9.8 amps) of the 12V DC motor used in this subsystem to apply mechanical power to the firing mechanism. Since the housing subsystem will have extra 16 AWG wire, that wire will be sufficient to use for this application. 

**Constraint Solution 2:**
To allow the firing mechanism to operate without human interaction, a signal shall be generated from the Aiming subsystem when that subsystem has finished the aiming processes that will be used as a relay signal to operate the firing mechanism autonomously. The relay will disconnect the 12-volt supply from the DC motor when the signal is not active, or low, and will connect the 12-volt supply to the DC motor when the signal is activated, or high, allowing the motor to operate. The relay will be connected to pin 1 of the Raspberry Pi 5 from the aiming subsystem and will pull 100mA at max (while operating) which is within the Raspberry Pi 5's ampacity limits for that pin.

Below is the charachteristics sheet of the Adafruit Featherwing Relay:

![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/jlburke42-signoff-Launching-and-Firing/Documentation/Images/RelayCharachteristics.png)

**Constraint Solution 3:**
The Launching and Firing subsystem is required to fit within a cubic foot of space (1 ft by 1 ft by 1 ft) along with the other subsystems that will be placed within that space. For this constraint, the mechanical engineering team has allowed a space of 3 inches long (not counting the shaft length) with a 3 inch max diameter for the DC motor used. The DCM 1006 12V DigiKey DC motor has a length of 2.64 inches and a diameter of 1.575 inches which will satisfy this requirement. The relay's placement within the cubic foot of space is much less critical and can fit well within the space allowed by DEVCOM.

Below is a graph of the DigiKey motor lengths

![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/jlburke42-signoff-Launching-and-Firing/Documentation/Images/Digimotorlength.png)

**Constraint Solution 4:**
The Launching and Firing subsystem shall use a 12V DC motor from DigiKey model number DCM 1006 which exhibits the ability to operate the mechanism at a torque of 3.5 OZ-IN at 4900 RPM nominally. 3.2 OZ-IN is the highest torque required to operate the Fire-Preload sequence of the Launching and Firing subsystem. The DigiKey model number DCM 1006 12V DC motor shall satisfy this requirment.

Below is an image of the DigiKey motor:

![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/jlburke42-signoff-Launching-and-Firing/Documentation/Images/DCM1006image.png)

**Constraint Solution 5:**
The mechanical engineering team's current plan is to fire a round after a 20 degree rotation of the Launching and Firing DC motor. The rest of the rotation would be used to set the firing mechanism into a preload state, awaiting another signal from the aiming subsystem to fire the next round with a 20 degree turn and the following 340 degrees used to preload the mechanism and so on. The electrical engineering team decided to use a safety designing factor of 2.0 and ensure the motor would have the ability to rotate 40 degrees to release the shot within the time allowed for the response of shooting a round after receiving the signal from the aiming subsystem. Over the cycle of a full rotation, the torque will vary from no-load to a load of 3.2 OZ-IN from the mechanical engineering team's calculations. The first part of the rotation (which will fire the round) will have the lowest torque (to use a quote from the ME team, "right next to no-load". The DigiKey motor has a torque of 3.5 OZ-IN at 4900 RPM, which is equivalent to 81.7 rotations per second. The motor will be geared 30:1 meaning to complete a ninth of the output cycle of the firing mechanism, or the first 40 degrees that would fire the round, the input shaft would need to rotate 3.333 times. The motor will operate even faster at a no-load torque, but using the nominally loaded torque of 3.5 OZ-IN at 4900 RPMs for this calulation as a second safety factor, we find that this motor can complete the 2.222 rotations in 0.041 seconds (0.0408 = 2.222 * (1/(4900/60))). The Adafruit Relay has a max operate time of 10ms and this time must also be taken under consideration. This motor will be able to complete 40 degrees of the rotation and release a single round after 51 ms at the given torque of 3.2 OZ-IN which is within it's worst-case scenario time limit of 80 ms. 

Below is an image of the DigiKey motor data:

![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/jlburke42-signoff-Launching-and-Firing/Documentation/Images/MOTORDATA.png)


**Constraint Solution 6:**
The mechanical engineering team's current plan is to fire a round after a 20 degree rotation of the Launching and Firing DC motor. The rest of the rotation would be used to set the firing mechanism into a preload state, awaiting another signal from the aiming subsystem to fire the next round with a 20 degree turn and the following 340 degrees used to preload the mechanism and so on. Over the cycle of a full rotation, thw torque will vary from no-load to a load of 3.2 OZ-IN from the mechanical engineering team's calculations. The DigiKey motor has a torque of 3.5 OZ-IN at 4900 RPM, which is equivalent to 81.7 rotations per second. The motor will be geared 30:1 meaning to complete a 340 degrees of the output cycle of the firing mechanism, or the last 340 degrees that would preload the next round, the input shaft would need to rotate 28.3 times.(28.33 =  30 * (340/360)) The motor will operate even faster at a torque of 3.2 OZ-IN, but using the nominally loaded torque of 3.5 OZ-IN at 4900 RPMs for this calulation as a safety factor, we find that this motor can complete the 340 rotations in 0.347 seconds ( 0.347 = 28.33 * (1/(4900/60))) This motor will be able to complete 340 degrees of the rotation and preload a single round after 347 ms at the given torque of 3.2 OZ-IN which is faster than the time required for the rest of the subsystems to detect and aim at the next incoming projectile (0.79 seconds from the aiming subsystem time chart) meaning that this work can be done concurrently to the rest of the system's processes without causing a time constraint on the system as a whole. 


## BOM
| Item | Description | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-------------|--------------|----------|-------|-------------|
| 12V DC Motor | Brushed DC motor used to operate firing mechanism | DCM 1006 | DigiKey | 1 | $72.00 | $72.00 |
| Power Relay FeatherWing | Takes the signal from the aiming subsystem and allows DC motor to operate or not | 3191 | Adafruit  | 1 | $9.95 | $9.95 |
|      |                                             |     |             |   |       | $81.95 Total |

