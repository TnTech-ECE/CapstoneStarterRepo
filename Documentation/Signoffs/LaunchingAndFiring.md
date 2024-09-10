## Functionality
The Launching and Firing subsystem is the system that will fire the intercepting round when given a signal from the aiming subsystem. This system will also control the power to the brushed PMDC (Permanent Magnet Direct Current)[2] motor used to operate the firing mechanism and preload the launching apparatus so that each round may fire with minimum delay once the aiming subsystem has completed it's processes.

## Explanation of DC Motor Signal Control
This subsystem will use a 12-volt DC brushed motor along with a relay that will use a signal from the aiming subsystem as an input to allow the DC motor to operate. This signal will be sent for the amount of milliseconds that it will take the firing apparatus to fire a round, and return to the preloaded condition. This time will be found once the Mechancial Engineering team has finished constructing their design. Due to the nature of the ME team's design for the firing apparatus, once in preload, the motor will be in a state where there will be no load just before activation of the motor. Once activated by the aiming subsystem's signal the motor will then go through the firing cycle, resetting the interceptor. The final stage of this cycle, when the motor will be returning into the no load section of the firing cycle, will have a margin of error of 15 degrees in either direction (this number is a "safe" number the ME team provided based on their design, it is more likely the acceptable margin of error is higher than 15 degree in either direction but this number they felt safe with using) in which the position of the output shaft can come to rest.(The motor will be geared 30:1, more on this below) During testing and experimentation, the device will be honed in to stop as closely as possible to the most optimal position for the mechanism to function properly by using a proximity sensor and a bolt that will be placed along the rotationary wheel of the design. More on this in an added section below the proof for constraint 5.

## Specifications and Restraints
| Number | Constraint | Constraint description | Origin |
|------|--------------------|------------------------|------------|
| 1. | NEC 310.15(B)(16) | The Launching and Firing subsystem shall use appropriate wiring for all connections within the subsystem as according to the ampacity limits listed in the NEC 310.15(B)(16) table | NEC 310.15(B)(16) |
| 2. | Fire without human interaction | The Launching and Firing subsystem shall fire without any human interaction with the field of play or the launching apparatus itself | DEVCOM competition rulebook |
| 3. | Fit within a cubic foot of space | The Launching and Firing subsystem shall fit within a cubic foot of space (1 ft by 1 ft by 1 ft) along with the other subsystems that will be placed within that space. For this subsystem, the chosen motor to operate the firing mechanism shall have a length less than 3 inches not counting the shaft, and a diameter less than 3 inches. | DEVCOM competition rulebook |
| 4. | Motor Torque | The Launching and Firing Mechanism shall operate the firing mechanism on the launcher apparatus using a moto of at least 3.2 OZ-IN | Mechanical Engineering Team Specification |
| 5. |  Signal-to-Fire delay | The Launching and Firing subsystem shall fire a round within 80 ms after receiving the signal from the aiming subsystem. This is the amount of time left after accounting for all other subsystems to complete their processes during the worst case scenario until the projectile will be out of shooting range(passed our launcher). This time for signal-to-fire must also be repeatable so that wheather it be 20ms or 80ms delay, it is able to be added to the aiming system's calculation to accurately aim ahead of the ball far enough for each volley. | Team Specification |
| 6. | Preloading after firing | The Launching and Firing subsystem shall reset the preload condition after each round is fired within 0.79 seconds. | Team Specification | 


## Buildable Schematic
### Electrical Schematic 
![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/jlburke42-signoff-Launching-and-Firing/Documentation/Images/Electrical_Schematic_new.png)

As seen in the schematic above, the Adafruit relay will be powered off the 3.3V pin (PIN1) of the Raspberry Pi 5. While the GPIO pins are limited to 50mA, this pin can support 3.3V up to 500mA. The Adafruit 3191 relay only draws 100mA while operating. A signal will be sent from GPIO 6 (PIN31) which shall switch allow the relay to switch from connecting "COMM" and "Normally Connected" to connecting "COMM" to " Normally Closed" allowing the motor to be powered from the 12V bus from the Housing subsystem. This motor shall draw 9A upon startup and when reaching it's stall point and will be wired with 16 AWG wire from the Housing subsystem. Te Proximity sensor will draw 25mA at 12 volts when active and 15mA when on standby, not impeding on the headroom of power left available on the 12V system under the Housing subsystem, and sending a signal (or lack thereof) to GPIO 11 when activated to signal the firing motor to come to rest. 

## Analysis 

**Constraint Solution 1:**
The Launching and Firing subsystem shall use 16 AWG wire for the subsystems electrical connections. This wire has an ampacity rating of 10 amps over a distance of 12 inches. This wire size was selected by considering the largest ampacity draw that exists in the subsystem. For this the team decided to use the start/stall current (9.8 amps) of the 12V DC motor used in this subsystem to apply mechanical power to the firing mechanism. Using a table [4] that seems to simplify and directly quotes the NEC 310.15(B)(16), the team decided to use 14 AWG wire[5] than can handle over 15 Amps, leaving plenty of capacity in the wire, this wire will be sufficient to use for this application. 

**Constraint Solution 2:**
To allow the firing mechanism to operate without human interaction, a signal shall be generated from the Aiming subsystem when that subsystem has finished the aiming processes that will be used as a relay signal to operate the firing mechanism autonomously. The relay[3] will disconnect the 12-volt supply from the DC motor when the signal is not active, or low, and will connect the 12-volt supply to the DC motor when the signal is activated, or high, allowing the motor to operate. The relay will be connected to pin 1 of the Raspberry Pi 5 from the aiming subsystem and will pull 100mA at max (while operating) which is within the Raspberry Pi 5's ampacity limits for that pin. The relay, the Adafruit Power Relay FeatherWing G5LE-G is rated for 10 Amp resistive loads at 12 Volts DC. This is over the motor's stall ampacity and it also useful to consider that the team will be operating the motor at much ampacity than this at all times however this relay can handle 10 amps at 12 volts regardless. After the shot is and preloading sequence is completed, a proximity sensor (mounted by ME team) will sense a bolt during that part of the rotation cycle and will send a signal to the Raspberry Pi 5 GPIO 11 (Pin23) to disengage the PMDC motor allowing the motor to come to rest against the resistance of the cam in the ME team's design at a predetermined point each time.

Below is the charachteristics sheet of the Adafruit Featherwing Relay[3]:

![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/jlburke42-signoff-Launching-and-Firing/Documentation/Images/RelayCharachteristics.png)

Below is an image of an item in the Lascar Electronics Proximity Sensor family, however our model will have one less wire [6]:

![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/jlburke42-signoff-Launching-and-Firing/Documentation/Images/Prox_sensor_body.png)

**Constraint Solution 3:**
The Launching and Firing subsystem is required to fit within a cubic foot of space (1 ft by 1 ft by 1 ft) along with the other subsystems that will be placed within that space. For this constraint, the mechanical engineering team has allowed a space of 3 inches long (not counting the shaft length) with a 3 inch max diameter for the DC motor used. The DCM 1006 12V DigiKey DC motor[2] has a length of 2.64 inches and a diameter of 1.575 inches which will satisfy this requirement. The relay's placement within the cubic foot of space is much less critical and can fit well within the space allowed by DEVCOM.

Below is a graph of the DigiKey motor lengths

![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/jlburke42-signoff-Launching-and-Firing/Documentation/Images/Digimotorlength.png)

**Constraint Solution 4:**
The Launching and Firing subsystem shall use a 12V DC motor from DigiKey model number DCM 1006 [2] which exhibits the ability to operate the mechanism at an input torque of 3.5 OZ-IN at 4900 RPM nominally. 3.2 OZ-IN is the highest input torque required to operate the Fire-Preload sequence of the Launching and Firing subsystem. The DigiKey model number DCM 1006 12V DC motor shall satisfy this requirment.

Below is an image of the DigiKey motor:

![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/jlburke42-signoff-Launching-and-Firing/Documentation/Images/DCM1006image.png)

**Constraint Solution 5:**
The mechanical engineering team's current plan is to fire a round after a 10 degree rotation of the Launching and Firing DC motor. The rest of the rotation would be used to set the firing mechanism into a preload state, awaiting another signal from the aiming subsystem to fire the next round with a 10 degree turn and the following 350 degrees used to preload the mechanism and so on. Over the cycle of a full rotation, the input torque required will vary from no-load to a load of 3.2 OZ-IN from the mechanical engineering team's calculations. The first part of the rotation (which will fire the round) will have the lowest torque (to use a quote from the ME team, "right next to no-load". The DigiKey motor has a torque of 3.5 OZ-IN at 4900 RPM, which is equivalent to 81.7 rotations per second. The motor will be geared (gearing supplied by ME team) 30:1 meaning to rotate the first 10 degrees that would fire the round on the output shaft, the input shaft would need to rotate 0.8333 times. The motor will operate even faster at a no-load torque, but using the nominally loaded input torque of 3.5 OZ-IN at 4900 RPMs for this calulation as a second safety factor, we find that this motor can complete the 0.8333 rotations in 0.0102 seconds (0.0102 = 0.8333 * (1/(4900/60))). The Adafruit Relay[3] has a max operate time of 10ms and this time must also be taken under consideration. This motor will be able to complete 10 degrees of the rotation and release a single round after 21 ms at the given input torque of 3.2 OZ-IN which is within it's worst-case scenario time limit of 80 ms. Now to prove the reliability of this motor, first see the test results from a Fiat study below which tested PMDC motors and saw they kept their numbers true to their specifications.[1]

![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/jlburke42-signoff-Launching-and-Firing/Documentation/Images/pmdc_study.png)

Firstly, it is important know the firing motor motor will need to only rotate 10 degrees thanks to some furtherance in the ME team's design. The ME team will place a cam with enough resistance it will aid the team in stopping the firing motor after a preload cycle right against the cam, and with little enough resistance it will be able to quickly roll through this object. (It also common knowledge PMDC motors are able to produce very high starting torque capabilities, hence their use in situations where these types of torque-speed-startup ratios are needed) This cam along with the proximity switch in the design will stop the firing motor output shaft 10 degrees from the switch that will fire the round. As proven above, it will take 21ms if holding the motor to it's rated torque, and at no point in this torque cycle do we expect to ever reach that torque as our motor is rated for 3.5 OZ-IN and we have a max input torque required of 3.2 OZ-IN from the ME team's calculations. This means, realistically, we can expect an even smaller delay, this leaves lesser room for error. Lastly, as shown in the picture above, PMDC motors are astoundingly accurate with their RPM-torque numbers given in the spec sheet, so following these results showing multiple test runs right along the performance line, seeing that the real-world torque should be less than the number used for this calculations, and thirdly that we can reliably stop the shaft once the power is disconnected having a cam to aid in stopping it, as well as a proximity sensor (mounted by ME team) and a bolt (mounted by ME team) that will sense the bolt which will be placed at an opportune point along the rotationary gear and will send a signal to the Raspberry Pi 5 GPIO 11 (Pin23) to disengage the PMDC motor, we can accurately say that this motor will be able to stop appropriately once the launcher body is built. The team will find what portion of this cycle occurs before the round is fired and use this in the coding for the aiming subsystem to fire "this much time ahead" of the round by using it's acceleration and velocity numbers from other subsystems to calculate when to begin the firing cycle (although this time will be minimal).

Below is an image of the DigiKey motor data:

![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/jlburke42-signoff-Launching-and-Firing/Documentation/Images/MOTORDATA.png)


**Constraint Solution 6:**
The mechanical engineering team's current plan is to fire a round after a 10 degree rotation of the Launching and Firing DC motor. The rest of the rotation would be used to set the firing mechanism into a preload state, awaiting another signal from the aiming subsystem to fire the next round with a 10 degree turn and the following 350 degrees used to preload the mechanism and so on. Over the cycle of a full rotation, the input torque required will vary from no-load to a load of 3.2 OZ-IN from the mechanical engineering team's calculations. The DigiKey motor has a torque of 3.5 OZ-IN at 4900 RPM, which is equivalent to 81.7 rotations per second. The motor will be geared 30:1 meaning to complete a 350 degrees of the output cycle of the firing mechanism, or the last 350 degrees that would preload the next round, the input shaft would need to rotate 29.167 times.(29.167 =  30 * (350/360)) The motor will operate even faster at an input torque of 3.2 OZ-IN, but using the motor's nominally loaded input torque of 3.5 OZ-IN at 4900 RPMs for this calulation as a safety factor, we find that this motor can complete the 350 rotations in 0.357 seconds ( 0.357 = 29.167 * (1/(4900/60))) This motor will be able to complete 350 degrees of the rotation and preload a single round after 357 ms at the given input torque of 3.2 OZ-IN which is faster than the time required for the rest of the subsystems to detect and aim at the next incoming projectile (0.79 seconds from the aiming subsystem time chart) meaning that this work can be done concurrently to the rest of the system's processes without causing a time constraint on the system as a whole. 


## BOM
| Item | Description | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-------------|--------------|----------|-------|-------------|
| 12V DC Motor | Brushed DC motor used to operate firing mechanism | DCM 1006 | DigiKey | 1 | $72.00 | $72.00 |
| Power Relay FeatherWing | Takes the signal from the aiming subsystem and allows DC motor to operate or not | 3191 | Adafruit  | 1 | $9.95 | $9.95 |
| 14 AWG Copper Wire  | 3 ft red and 3 ft Black Flexible 14 AWG Stranded Tinned Copper Wire | ‎SW14G40008F3RB | BNTECHGO | 1 | $6.88 | $6.88 |
| Proximity Sensor | Sensor to detect distance | 2136-CTL-SW-MC-ND | DigiKey (Lascar Electronics) | 1 | $38.16 | $38.16 |
|      |                                             |     |             |   |       | $126.99 Total |


## References
[1] PMDC Motor Reliability study: [http://mtc-m16c.sid.inpe.br/col/sid.inpe.br/mtc-m18/2011/04.11.15.04/doc/LADC%202011_A_RELIABLE_COMPUTATIONAL_SYSTEM_FINAL_ENTREGA.pdf]

[2] PMDC Motor DCM 1006: [https://www.digikey.com/en/products/detail/multi-products-company-inc/DCM-1006/15668239]

[3] Adafruit Relay: [https://www.adafruit.com/product/3191#technical-details]

[4] Wire Size Calculator : [http://wiresizecalculator.net]

[5] 14 AWG Wire [https://www.amazon.com/BNTECHGO-Silicone-Flexible-Strands-Stranded/dp/B017U6PGLO/ref=sr_1_3?crid=1CARC34IQUV3C&dib=eyJ2IjoiMSJ9.7NHwddBxpP9ohul-VQ5JW-ot8hyUft8gY27w8Tiazbp_KPNX_Q_-tpVYQXg-GDaspyYwjz8YxACLmVWO7dr37psSS-rQDs3eNSk7kPiFs1OJJrx5pUxRBtY7IPUYDXQM6Jn_xADS4JwfL1PySMOZjK-_-qrIK_c2HMbwBrB3bVV39GOs0K3iI-o6cjP94wFnNwz0PklXo03qhmMMD3aTkRh5tOqnEyZqi0f2hZOvctXZTJlFMZzwCu7agP1UY7PCImlwGKoABNj1YlXtGUVGwnEEGNoPMwwEYMRs1oVs-M8.UzG9r-N0GhTA8gsx34GOLnMLXhCVnxxTo49A9A_oaiA&dib_tag=se&keywords=14+gauge+wire&qid=1714451115&sprefix=14+gauge+wire%2Caps%2C161&sr=8-3]

[6] Proximity Sensor [https://www.digikey.com/en/products/detail/lascar-electronics/CTL-SW-MC/16915888?s=N4IgTCBcDaIMIBUAyBaAygdRQWTiAugL5A]

[7] Porximity Sensor Data Sheet Link [https://mm.digikey.com/Volume0/opasdata/d220001/medias/docus/2499/CTL-SW%20Infrared%20Proximity%20Switch.pdf]
