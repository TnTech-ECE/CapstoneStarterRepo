# Sensor Post Array Velocity and Acceleration Signoff
## Functionality 
 This portion of the sensor post array will be responsible for obtaining the velocity and acceleration of the practice golf ball as it travels down the fishing line towards the interceptor body. 
 To accomplish this task this subsystem will take in the projectiles location data from a mmWave Radar unit.
 This unit will detect the presense of an object and will do time of flight calculations to obtain the velocity and acceleration.
 This subsystem will then wirelessly transmit the values to the aiming subsystem for further use of this data.

## Constraints
<div align="center">

|Constraint Number | Description | Origin |
|------------------|-------------|--------|
| 1 | The design shall be autonomous, and will require no outside interference after initial startup. | The customer requires the interceptor and all external sensor posts must be autonomous after initial startup. This means that this design should be able to operate on its own for the duration of the competition without any user input. |
| 2 | The design shall operate on battery power for a minimum of 30 minutes. | This comes from the requirements set forth in the rulebook by devcom, and is further constrained based on the power consumption of this subsystem.|
| 3 | The design shall have maximum sensor input delay of 100ms. | This comes from a timing contraint for intercepting the projectile. |
| 4 | The Design shall have an alternative power method to be used during testing. | This is a requirement for lessening enviornmental impact of our interceptor. |
| 5 | The design shall have a mimumum range for projectile detection of 45 inches from the point of placement . | This constraint arises from the range of detection for the projectile and time to obtain appropriate data within the time window. |
| 6 | This design shall have a placement to put the radar beam angle within 100*40 $^{\circ}$ . | This constraint is derived from the beam angle specified by the mmWave Radar manufacturer |

</div>

### Further Explanation
[3] The 100ms input delay is the time that was allocated for detection within the critical path time of 1.78 seconds.

[5] The constraint stated to have a minimum range of 45 inches. This is to put the detection of the golf ball in the same area as the projectile path subsystem. This is done to reduce the time after the projectiles path has been detected and transmitted so the launcher body is not idle for an extended period of time waiting on the velocity and acceleration to come in to start performing its operations.

[6] The constraint referenced a radar beam angle within 100*40 $^{\circ}$ the radar beam angle is the area where the output can be returned to the anteana of the radar the 100 $^{\circ}$ is how wide in degrees an object can be detected, and 40 $^{\circ}$ is how big the angle up and down is.

## Schematics
<p align = "center">
<img src = https://github.com/JTJones73/Capstone2024-Team2/blob/awmorrow42-signoff-SensorPost-VelocityAndAcceleration/Documentation/Images/CapstoneSchematicV2.png width='400'>
</p>

## Analysis
### Radar Placement
<p align = "center">
<img src = https://github.com/JTJones73/Capstone2024-Team2/blob/awmorrow42-signoff-SensorPost-VelocityAndAcceleration/Documentation/Images/Horizontal.png width='400'>
</p>

The choice to bridge the center senor posts and place the radar system was done to account for the horizontal portion of the beam angle to cover the entirety of anchor 2 as seen above the 83 $^{\circ}$ is less than the maximum of 100 $^{\circ}$. This will also ensure that the maximum distance calulations are within limits for the worst case senerios of the ball being on the edges of the game board which will not be hapening. The minimum detectible distance comes from sensor post 1 being placed roughly 24 inches infrot of sensor post 2 (position picuted above) this would put the worst possible distance of the golf ball away at 40 inches. The distance is raised slightly because we want to detect the golf ball as soon as possible to allow for maximum time for aiming and firing. Also having the radar infront of the interceptor body reduces the cosine effect [10] on the radar giving us a more accurate velocity and acceleration.

<p align = "center">
<img src = https://github.com/JTJones73/Capstone2024-Team2/blob/awmorrow42-signoff-SensorPost-VelocityAndAcceleration/Documentation/Images/Vertical.png width='400'>
</p>

The vertical portion of the beam angle is so much of a problem as it is well withing the 40 $^{\circ}$. 
But we will mount the sensor where it is angled up at a 45 $^{\circ}$ angle to better encapulate the flight path of the golf ball. This angle will also allow for line sag as the tension of the lines may vary.

### Detection distance
To find the maximum distance the radar will be able to detect the projectile a few calculations are needed. 
The first being the Radar Cross Section (RCS) which is a measure of how reflective an object is to radar waves, and is related to the probability of the radars signal being returned to the radar after hitting the projectile. 
To do this I used the online calculator [1] which uses the target having a sherical shape and the following formula.

$$ RCS = { 4* P_i * r^2 * Sr\over S_t } $$

Using 0.02124202 meters (average radius of a golf ball) for the rarget radius gives an RCS estimation of 0.0014175 meters $^2$. 
Now that an RCS value has been found the max radar range calculator [2] can be used to find the maximum range the radar can be used to detect the golfball. 
This calculator uses the equation 

$$ Range = \sqrt[4]{p_r * \sigma * c^2 * G_r^2\over 4\pi^3 * f_o^2 * P_{min}} $$

In this equation plug in the Radar Output Power or Equivalent Transmit Power lower end of the range 9 dBm, operating frequency of 24 GHz the RCS of 0.0014175, since we do not have a data sheet we make assumptions for the two remaing unkowns. 
The antena gain is assumed to be 1.5 dB because that is the gain of a resonant dipole antenas[3] and the minimum detecitible signal is assumed to be -90 dBm. 
With these values we get a maximum detection distance of 1.188 m or 46.77 inches. 
By connecting the center sensor posts together and placing the radar apperatus in the center this maximum distance to the edge of the game board is 49.67 from where the radar will be operating from so at the worst case the radar will reach 95% of the way to the furthast edge in the worst case.

### Microcontroller
The ESP32-E in the Velocity and Acceleration sign off will be used as the micro controller for the mmWave radar. 

## Implementation and Testing
### Testing
The testing for this subsystem will be conducted with the assembled game board built by the Mechanical Enginneering team.
To properly test the subsystem sensor post will be setup in the appropriate place dictated the the rule book given by decom. 
The radar mounting and attacment will then be connected to the sensor post and the projectile will be launched down all possible paths, and the data for all paths is recorded by the microcontroller. 
After this data is analized adjustments will be made as needed, and the device will be retested until no adjustments are needed to caputre the projectile accurately.

### Bill of Materials (BOM)
<div align="center">

|Name of item              |Description                                 |Part Number  |Manufacuer  |Quantity  |Price  |Total  |
|--------------------------|--------------------------------------------|-------------|------------|----------|-------|-------|
|mmWave Radar 9m           |mmWave Radar by DFRobot 9m Range            |SEN0395      |DFRobot     |1         |$29.00 |$29.00 |
|Total                     |                                            |             |            |          |       |$29.00 |

</div>

### Refrences

[1] [RCS Calulator][def1]: Radar Cross Section calculator.

[2] [Radar Maximum Range Calculator][def2]: Radar max range calculator.

[3] [Dipole antena wikapidia][def3]: Wiki page on dipole antena.

[4] [Tutorial for mmWave Radar][def5]: mmWave Radar quick setup guides including pin connections.

[5] [mmWave Radar 9m range][def6]: mmWave radar 9m range purchase link.

[6] [cosine effect][def10]: The cosine effect reference.

[7] [Reference Data for Engineers Ninth Edition][def13]: Chapter 36 Radar

[8] [Velocity and Acceleration Signoff][def14]: Signoff for the Velocity and Acceleration using Time of Flight.

[def1]: https://www.rfwireless-world.com/calculators/Radar-RCS-calculator.html
[def2]: https://www.pasternack.com/t-calculator-radar-range.aspx
[def3]: https://en.wikipedia.org/wiki/Dipole_antenna#:~:text=Neglecting%20electrical%20inefficiency%2C%20the%20antenna,for%20a%20half%2Dwave%20dipole.
[def5]: https://wiki.dfrobot.com/mmWave_Radar_Human_Presence_Detection_SKU_SEN0395#target_8
[def6]: https://www.dfrobot.com/product-2282.html
[def10]: https://copradar.com/chapts/chapt2/ch2d1.html
[def13]: https://schematicsforfree.com/files/Theory%2C%20Education%20%26%20Reference/Reference/Reference%20Data%20for%20Engineers%20Ninth%20Ed.pdf
[def14]: https://github.com/JTJones73/Capstone2024-Team2/blob/awmorrow42-signoff-SensorPost-VelocityAndAcceleration/Documentation/Signoffs/VelocityAndAcceleration.md
