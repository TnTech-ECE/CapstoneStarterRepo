# Sensor Post Array Velocity and Acceleration Signoff
## Functionality 
 This portion of the sensor post array will be responsible for obtaining the velocity and acceleration of the practice golf ball as it travels down the fishing line twards the interceptor body. To accomplish this task this subsystem will take in the velocity and acceleration data from the mmWave Radar to do the calculations neccisary to acertain the velocity and acceleration. This subsystem will then wirelessly transmit the velocity and acceleration of the practice gold ball to the aiming subsystem for further use of this data.
## Constraints
* C8: Design a sensor array that operates on battery power
* C14: Design a system with a maximum sensor input delay of 100ms
* C15: The Interceptor project shall have solders that conform to the IPC-J-STD.
* C16: The Interceptor project shall have a safe wiring scheme for all components of the project.
* C19: The Design shall implement the best remote battery power solution to limit the interceptor's environmental impact.
* C22: 
## Schematics
<p align = "center">
<img src = https://github.com/JTJones73/Capstone2024-Team2/blob/SensorPosts/Documentation/Images/CapstoneSchematicV1.pdf width='250'>
</p>
## Analysis
### Detection distance
To find the maximum distance the radar will be able to detect the a few calculations where needed. The first being the Radar Cross Section (RCS) which is the equivalent area of the target preceived by the radar. To do this I used the online calculator [1] which uses the target having a sherical shape and the following formula.

$$ RCS = { 4* Pi * r^2 * Sr\over St } $$

Using 0.02124202 meters (average radius of a golf ball) for the rarget radius gives an RCS estimation of 0.0014175 meters $^2$. Now that an RCS value has been found the max radar range calculator [2] can be used to find the maximum range the radar can be used to detect the golfball. This calculator uses the equation 
<p align = "center">
<img src = https://github.com/JTJones73/Capstone2024-Team2/blob/SensorPosts/Documentation/Images/RadarRange.png/ width='250'>
</p>
In this equation plug in the Radar Output Power or Equivalent Transmit Power lower end of the range 9 dBm, operating frequency of 24 GHz the RCS of 0.0014175, since we do not have a data sheet we make assumptions for the two remaing unkowns. The antena gain is assumed to be 1.5 because that is the gain of a resonant dipole antenas[3] and the minimum detecitible signal is assumed to be -90 dBm. With these values we get a maximum detection distance of 1.188 m or 46.77 inches. By connecting the center sensor posts together and placing the radar apperatus in the center this maximum distance to the edge of the game board is 49.67 from where the radar will be operating from so at the worst case the radar will reach 95% of the way to the furthast edge in the worst case.

### Radar Placement
The choice to bridge the center senor posts and place the radar system in the middle of the game board is to reduce the maximum distance from the edge of the gameboard from the radar. Also having the radar infront of the interceptor body reduces the cosign effect on the radar giving us a more accurate velocity and acceleration.

### Battery
To ensure that the battery will last greater than one hour. The operating current of the ESP8266 is 80 mA and the operating current for the radar is 90 mA, using the formula

$$ current * duration = mAh $$

since we have the mAh avalible of the battery and the current the microcontroller and mmWave Radar use we can rewrite the formula to 

$$ {mAh\over current} = duration $$

using this formula we get an best case operation time 14.7 hours. But as the battery drains the voltage of the batter will stop. Since best case operation time is roughly 14 times the desired operation accounting for the voltage drain is not needed in this case.

### Microcontroller
The ESP8266 has a built in WiFi module allowing for wireless communication. This micro controller also works with the mmWave radar chosen as shown by a tutorial[4]

## Implementation and Testing
### Bill of Materials (BOM)
<div align="center">

|Name of item              |Description                     |Part Number  |Manufacuer  |Quantity  |Price  |Total  |
|--------------------------|--------------------------------|-------------|------------|----------|-------|-------|
|FireBeetle ESP8266        |Microcontroller with WiFi       |DFR0489      |DFRobot     | 1        |$7.50  |$7.50  |
|mmWave Radar 9m           |mmWave Radar by DFRobot 9m Range|SEN0395      |DFRobot     |1         |$29.00 |$29.00 |
|Battery Holder            |Battery Holder - 1x18650        |PRT-12899    |ChinaDAIR   |1         |$1.15  |$1.15  |
|Samsung 25R 18650 2500mAh |2500mAh Litium Ion Battery      |N\A          |Samsung     |1         |$3.75  |$3.75  |
|Total                     |                                |             |            |          |       |$41.40 |

<div>

### Refrences

RCS Calulator
[def1]: https://www.rfwireless-world.com/calculators/Radar-RCS-calculator.html
Radar Maximum Range Calculator
[def2]: https://www.pasternack.com/t-calculator-radar-range.aspx
Dipole antena wikapidia
[def3]: https://en.wikipedia.org/wiki/Dipole_antenna#:~:text=Neglecting%20electrical%20inefficiency%2C%20the%20antenna,for%20a%20half%2Dwave%20dipole.  
micro controller
[def4]:https://www.dfrobot.com/product-1634.html
wiki 
[def5]: https://wiki.dfrobot.com/mmWave_Radar_Human_Presence_Detection_SKU_SEN0395#target_8
mmWave 9m
[def6]: https://www.dfrobot.com/product-2282.html
battery holder
[def6]: https://www.sparkfun.com/products/12899
FireBeetle Data sheet
[def7]: https://www.mouser.com/pdfdocs/DFR0489_Web.pdf
Samsung 2500mAh battery
[def8]: https://www.18650batterystore.com/products/samsung-25r-18650
