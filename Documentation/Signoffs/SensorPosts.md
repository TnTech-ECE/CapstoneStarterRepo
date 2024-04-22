# Sensor Post Array Velocity and Acceleration Signoff
## Functionality 
 This portion of the sensor post array will be responsible for obtaining the velocity and acceleration of the practice golf ball as it travels down the fishing line towards the interceptor body. 
 To accomplish this task this subsystem will take in the projectiles location data from the mmWave Radar to do the calculations neccisary to obtain the velocity and acceleration. 
 This subsystem will then wirelessly transmit those values to the aiming subsystem for further use of this data.

## Constraints
<div align="center">

|Constraint Number | Description | Origin |
|------------------|-------------|--------|
| 1 | The design shall be autonomous, and will require no outside interference after initial startup. | The customer requires the interceptor and all external sensor posts must be autonomous after initial startup. |
| 2 | The design shall operate on battery power for a minimum of 30 minutes. | This comes from the requirements set forth in the rulebook by devcom, and is further constrained based on the power consumption of this subsystem.|
| 3 | The design shall have maximum sensor input delay of 100ms. | This comes from a timing contraint for intercepting the projectile. |
| 4 | The Design shall have an alternative power method to be used during testing. | This is a requirement for lessening enviornmental impact of our interceptor. |
| 5 | The design shall have a mimumum range of 45 inches from the point of placement. | This constraint arises from the range of detection for the projectile and time to obtain appropriate data within the time window. |
| 6 | This design shall have a placement to put the radar beam angle within 100*40 $^{\circ}$ . | This constraint is derived from the beam angle specified by the mmWave Radar manufacturer |

</div>

### Further Explanation
[5] The constraint stated to have a minimum range of 45 inches. This is to put the detection of the golf ball in the same area as the projectile path subsystem. This is done to reduce the time after the projectiles path has been detected and transmitted so the launcher body is not idle for an extended period of time waiting on the velocity and acceleration to come in to start performing its operations.

[6] The constraint referenced a radar beam angle within 100*40 $^{\circ}$ the radar beam angle is the area where the output can be returned to the anteana of the radar the 100 $^{\circ}$ is how wide in degrees an object can be detected, and 40 $^{\circ}$ is how big the angle up and down is.

## Schematics
<p align = "center">
<img src = https://github.com/JTJones73/Capstone2024-Team2/blob/awmorrow42-signoff-SensorPost-VelocityAndAcceleration/Documentation/Images/CapstoneSchematicV1-1.png width='400'>
</p>

## Analysis
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

### Radar Placement
The choice to bridge the center senor posts and place the radar system in the middle of the game board is to reduce the maximum distance from the edge of the gameboard from the radar. 
Also having the radar infront of the interceptor body reduces the cosine effect [10] on the radar giving us a more accurate velocity and acceleration.

### Battery
To ensure that the battery will last greater than 30 minutes. 
The operating current of the ESP8266 is 80 mA and the operating current for the radar is 90 mA, using the formula

$$ current * duration = mAh $$

The average capacity of a Alkiline AA battery is 2500mAh and the current consumed by the microcontroller and mmWave Radar is 170 mA we can rewrite the formula to be

$$ {mAh\over current} = duration $$

using this formula we get an best case operation time 14.7 hours. 
But as the battery drains the voltage of the batter will drop to be non-nominal. Since best case operation time is roughly 30 times the desired operation accounting for the voltage drain is not needed in this case.
To limit the envornmental impact of this subsystem the battery power will not be used during the device testing and will only be used during the competition.
To further reduce battery waste a common AA battery was chosen so that the leftover batteries can be repurposed after the cometition for future projects. 

### Microcontroller
The ESP8266 has a built in WiFi module allowing for wireless communication which reduces the amount of microcrontrollers that are needed. This microcontroller also works with the mmWave radar chosen as shown by DFRobot in a tutorial linked in reference [4]. This tutorial also serves to indicate a response time of 7ms when simply detecting motion.

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
|FireBeetle ESP8266        |Microcontroller with WiFi                   |DFR0489      |DFRobot     | 1        |$7.50  |$7.50  |
|mmWave Radar 9m           |mmWave Radar by DFRobot 9m Range            |SEN0395      |DFRobot     |1         |$29.00 |$29.00 |
|AA Battery Holder         |AA Battery Holder with on/off switch 2 pack |N\A          |LampVPath   |1         |$4.99  |$4.99  |
|Powermax AA battery       |AA alkaline battery 24 pack                 |N\A          |Powermax    |1         |$6.58  |$6.58  |
|Total                     |                                            |             |            |          |       |$48.07 |

</div>

### Refrences

[1] [RCS Calulator][def1]: Radar Cross Section calculator.

[2] [Radar Maximum Range Calculator][def2]: Radar max range calculator.

[3] [Dipole antena wikapidia][def3]: Wiki page on dipole antena.

[4] [FireBeetle ESP8266][def4]: ESP8266 purchase link.

[5] [Tutorial for mmWave Radar][def5]: mmWave Radar quick setup guides including pin connections.

[6] [mmWave Radar 9m range][def6]: mmWave radar 9m range purchase link.

[7] [AA battery holder][def7]: AA battery holder with on/off switch.

[8] [FireBeetle 8266 Data sheet][def8]: Firebeteel ESP8266 Datasheet.

[9] [Powermax AA battery][def9]: AA battery made by Powermax.

[10] [cosine effect][def10]: The cosine effect reference.

[11] [AA battery mAh][def11]: The mAh of different types of AA batteries.

[12] [AA bettery discharge][def12]: The discharge testing done on differnet types of AA batteries at different discharge ratings.

[def1]: https://www.rfwireless-world.com/calculators/Radar-RCS-calculator.html
[def2]: https://www.pasternack.com/t-calculator-radar-range.aspx
[def3]: https://en.wikipedia.org/wiki/Dipole_antenna#:~:text=Neglecting%20electrical%20inefficiency%2C%20the%20antenna,for%20a%20half%2Dwave%20dipole.
[def4]: https://www.dfrobot.com/product-1634.html
[def5]: https://wiki.dfrobot.com/mmWave_Radar_Human_Presence_Detection_SKU_SEN0395#target_8
[def6]: https://www.dfrobot.com/product-2282.html
[def7]: https://www.amazon.com/LAMPVPATH-Battery-Holder-Switch-Leads/dp/B09T9XZH5M/ref=sr_1_15?crid=1DI3RBEG4H98G&dib=eyJ2IjoiMSJ9.KWBinYDTTbc20vzN002vVchkbNXQp-5v2D86XI3-95p-VuMENoRHfeAidJct7OrxX06dXNvtv9hyKntX4qP5CN-KZ8H5xRj1I6tTFzYYqyR1YJ9W6d2fXQlQdLsDRrz32E79utVSN_qjE8CLlgv9-98gRtoJXYsaud59K_RaV3Im7bMHXzDxNSmgqzKkM3c1Tkq0eubcIW_KO0wIhEPNYkCmeX9sArhjskuAzPj5BlE.JboYqNlsYdeu1gtyeQLdX3owIwS9O69liRJc7nNwwSk&dib_tag=se&keywords=aa%2B3V%2Bbattery%2Bholder&qid=1713395804&sprefix=aa%2B3v%2Bbattery%2Bholder%2Caps%2C99&sr=8-15&th=1
[def8]: https://www.mouser.com/pdfdocs/DFR0489_Web.pdf
[def9]: https://www.amazon.com/Powermax-24-Count-Batteries-Recloseable-Packaging/dp/B0BFFNZLYY/ref=sr_1_6?crid=3MEXH5Z9P4WYJ&dib=eyJ2IjoiMSJ9.jt9Z96uuvYjXCPr3cbzKXVMIKk_c0AtfnBg_iW8RnIzdht0cJRFXvMc2ehsyFcojyHHLFEf2pXFSV8cEXS0e7q7huujhoOnV7YYaIN3CHzp8BQnFjiDEHLbmhEpPTTzzCRqjQNmmGc55s8Bd9CLH8C3lnhFJ6MnRMAED1Fch--2XAZgKbPCVdZ-_xPcERkGN2lycxTtxpFtPGAOLrTu5MKGgASBk-rORlfubsBadkYFCnJ0mgpWNlotAtjOgTekmecgXpdfLnoeebRGU3wGYsMK5JsAa3pVp39OK1TCnigA.zYYjypyXzoUN4Lu9K8irTiXmyX-xDlnXKUi-MSe-pFs&dib_tag=se&keywords=aa+batteries&qid=1713396567&sprefix=aa+batteries%2Caps%2C102&sr=8-6
[def10]: https://copradar.com/chapts/chapt2/ch2d1.html
[def11]: https://www.microbattery.com/blog/post/battery-bios:-everything-you-need-to-know-about-the-aa-battery/
[def12]: https://www.powerstream.com/AA-tests.htm
