# Sensor Post Array Velocity and Acceleration Signoff
## Functionality
 This portion of the sensor post array will be responsible for obtaining the velocity and acceleration of the practice golf ball (Projectile) as it travels down the fishing line towards the interceptor body. 
 To accomplish this task this subsystem will measure the golf balls distance from the chosen time of flight (ToF) sensor as it travels down the fishing line. By sampling the distances we can use the distance traveled over the amount of time to calculate the velocity of the practice golf ball. Using the calculated velocity and the time taken between measurements the acceleration of the practice golf ball can be calculated.

## Constraints
<div align="center">

|Constraint Number | Description | Origin |
|------------------|-------------|--------|
| 1 | The design shall be autonomous, and will require no outside interference after initial startup. | The customer requires the interceptor and all external sensor posts must be autonomous after initial startup. This means that this design should be able to operate on its own for the duration of the competition without any user input. |
| 2 | The design shall operate on battery power for a minimum of 30 minutes. | This comes from the requirements set forth in the rulebook by devcom, and is further constrained based on the power consumption of this subsystem.|
| 3 | The design shall have maximum sensor input delay of 100ms. | This comes from a timing contraint for intercepting the projectile. |
| 4 | The Design shall have an alternative power method to be used during testing. | This is a requirement for lessening enviornmental impact of our interceptor. |
| 5 | The design shall have a mimumum range for projectile detection of 45 inches from the point of placement. | This constraint arises from the range of detection for the projectile and time to obtain appropriate data within the time window. |

</div>

### Further Explanation
[3] The 100ms input delay is the time that was allocated for detection within the critical path time of 1.78 seconds.

[5] The constraint stated to have a minimum range of 45 inches. This is the maximim distance from the middle sensor post to the edge of the game board and this is the minimum distance away from the edge of the gameboard that the sensor would be loacated at. The measurments for the game board and competition rules can be found [10]. 


## Schematics
<p align = "center">
<img src = https://github.com/JTJones73/Capstone2024-Team2/blob/awmorrow42-signoff-SensorPost-VelocityAndAcceleration/Documentation/Images/VelocityAndAccelerationSchematic-1.png width='400'>
</p>

## Analysis
### Velocity and Acceleration Measurements
This device will fuction in multiple parts. One part is having two servo's for aiming the ToF sensor up/down and left/right based of the path  detected by the projectile path sensing subsystem. The resoning for this is due to the sensor having a feild of view of 25 degrees[3] so the sensor needs to be aimed in the general direction of the projectile for detection. Using the set path we can keep the sensor aimed in the projectiles direction as needed. After the mesurements are taken the sensor will be returned to its default position and await the next detected path. This will allow the device to operate without any input or intervention from user.
The next part of this subsystem is the velocity and acceleration calculations. The formula for Velocity is 
$$ Velocity = {\Delta Distance \over \Delta Time} $$
Where distance is the distance travled divided by the time it took to go that distance. Using this formula the following can be obtained
$$ Velocity = { |d_1 - d_2| \over |t_1 - t_2|}$$
In this formula the values for d will be the distance measurements from the time of flight sensors, and t will be the time stamps taken when those measurements are saved. Using the found velocities the acceleration of the projectile can be calculated by the following formula.
$$ Acceleration = {\Delta Velocity \over \Delta Time} $$
Breaking the formula down further 
$$ Acceleration = { |v_1 - v_2| \over |t_1 - t_2|}$$
The values for v will be the saved velocities calculated before and t will be the corilating times saved when calculated. 
Some notes about this approch it is assumed that the inital velocity of the projectile is 0 or close to it and is under a constant acceleration. These assumptions will allow for simpliar calculations and may be adjusted for futher accuracy if needed.

### Battery
To ensure that the battery will last greater than 30 minutes. 
The ToF Sensor 18 mA maximum operating current [7].
ESP32 has has an maximum operating current of 240 mA [3].
Rounding the ToF operating current up and adding the operating current of both devices together to get a maximum current consumption of 260 mA. 
Using the formula from the batter life calculator from [8]
$$ Battery Life = Battery Capacity / Load Current $$
We can rearage this to be 
$$ Battery Capacity = Battery Life * Load Current $$ 
Using this we can put in our desired batter life of half an hour and swap in the current consumption for load current to get 
$$ Battery Capacity = 0.5 * 260 mA $$ 
This will give a minimum battery capacity of 130 mAh. The 650 mAh batter chosen more than meets this minimum capacity and will give 2.5 hours of battery life for device operation.

### Microcontroller
The ESP32-E has a built in WiFi module allowing for wireless communication which reduces the amount of microcrontrollers that are needed.  This microcontroller is different than the ESP8266 that is being used in the networking subsystem but meets the requirements of using 802.11 WiFi to communicate in the same mannor as the other networking devices[2]. The ESP32 has been tested and the VL53L3CX ToF Sensor will be able to operate using this mircrocontroller[5].

## Implementation and Testing
### Testing
The ToF sensor will be tested by first placing the practice golf ball infront of the sensor first at 5 inches away and increasing the distance by 5 inches after every succesful measurement until 80 inches away which would be past the edge of the gameboard. This will allow for a baseline to be made for the accuracy of the measurement and detection of the golf ball. After this testing will begin with detecting the practice golf ball while moving down the fishing line. This testing is to find out how many and quickly we can get the measuremnts on the practice golf ball while it is moving. The next testing will be using the servo-motors to turn and aim the ToF sensor at the ball while it is moving making performace changes as needed.

### Bill of Materials (BOM)
<div align="center">

|Name of item               |Description                                  |Part Number  |Manufacuer          |Quantity  |Price  |Total  |
|---------------------------|---------------------------------------------|-------------|--------------------|----------|-------|-------|
|ESP32-E Microcontroller    |FireBeetle 2 ESP32-E IoT Microcontroller     |DFR1139      |DFRobot             |1         |$12.90 |$12.90 |
|Fermion VL53L3CX ToF Sensor|Fermion VL53L3CX ToF Sensor (25-3000mm)      |SEN0378      |DFRobot             |1         |$8.90  |$8.90  |
|3.7V Lipo Battery          |EEMB 3.7V 650mAh Li-Polymer Battery: 553450  |N\A          |EEMB                |1         |$6.99  |$6.99  |
|Adafruit Servomotor        |DC Servomotor 3-6V 3-PIN                     |1528-4326-ND |Adafruit Industries |2         |$5.95  |$11.90 |
|On/Off Button              |Pushbutton On/Off switch                     |545PB-ND     |Judco Manufacturing |1         |$2.01  |$2.01  |
|Total                      |                                             |             |                    |          |       |$42.70 |

</div>

### Refrences

[1] [FireBeetle 2 ESP32-E IoT Microcontroller][def1]: FireBeetle 2 ESP32-E (N16R2) Microcontroller (16MB Fl., Wi-Fi & Bluetooth).
[2] [ESP32-WROOM-E Datasheet][def2]: Espressif ESP-WROOM-E and ESP-WROOM-UE Datasheet.
[3] [ESP32 Series Datasheet][def3]: Espressif ESP series datasheet
[4] [FireBeetle 2 ESP32-E Wiki][def4]: Wiki made by DfRobot for the FireBeetle 2 ESP32-E.
[5] [Fermion: VL53L3CX ToF Sensor][def5]: Fermion VL53L3CX ToF Distance Ranging Sensor (25-3000mm).
[6] [VL53L3CX ToF Sensor Wiki][def6]: Wiki made by DfRobot for the VL53L3CX ToF sensor.
[7] [VL53L3CX Datasheet][def7] : Datasheet for the VVL53L3CX made by ST.
[8] [Battery Life Calculator][def8] : DigiKey battery life calculator.
[9] [Adafruit Servomotor][def9]: DC Servomotor 3-6V 3-PIN.
[10] [Paper Wad Intercepotor Rules][def10]: The rulebook for the comptetition.
[11] [3.7V Lipo Battery][def11]: EEMB 3.7V 650mAh Li-Polymer Battery

[def1]: https://www.dfrobot.com/product-2837.html
[def2]: https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32e_esp32-wroom-32ue_datasheet_en.pdf
[def3]: https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf
[def4]: https://wiki.dfrobot.com/FireBeetle_Board_ESP32_E_SKU_DFR0654
[def5]: https://www.dfrobot.com/product-2256.html
[def6]: https://wiki.dfrobot.com/DFRobot_VL53L3CX_ToF_Distance_Sensor_Breakout_Board_SKU_SEN0378
[def7]: https://www.st.com/resource/en/datasheet/vl53l3cx.pdf
[def8]: https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-battery-life
[def9]: https://www.digikey.com/en/products/detail/adafruit-industries-llc/4326/10419470
[def10]: https://github.com/JTJones73/Capstone2024-Team2/blob/awmorrow42-signoff-SensorPost-VelocityAndAcceleration/Documentation/CompetitionRules/PaperWodInterceptorChallenge_Rules_V4.1.pdf
[def11]: https://www.amazon.com/EEMB-Battery-Lithium-Rechargeable-Connector/dp/B09DPNVD8T/ref=sxin_16_pa_sp_search_thematic_sspa?content-id=amzn1.sym.fb16fbe4-bf7e-47a2-a56d-1e42bc2dbf4d%3Aamzn1.sym.fb16fbe4-bf7e-47a2-a56d-1e42bc2dbf4d&crid=3JFNMZFQS23XB&cv_ct_cx=3.7+V+lipo+battery&dib=eyJ2IjoiMSJ9.AaRESnG2KaFKBm4vGoJVUFTA2GWHHrxemugWyluwDTvpwC5avHFewEanEI3gfiByqOT-2cFK9atr6Lw4iGB_v7w7r26-kr8ZsZxv76lkbyQ.hQ4uIU_hyEmQYiJ7vxLKd7xG7zrCl8X3AIeOu2q2mT4&dib_tag=se&keywords=3.7+V+lipo+battery&pd_rd_i=B09DPNVD8T&pd_rd_r=cc29a523-6125-41a6-9528-c76f1f72b62d&pd_rd_w=8a9IJ&pd_rd_wg=wdk7t&pf_rd_p=fb16fbe4-bf7e-47a2-a56d-1e42bc2dbf4d&pf_rd_r=V6GE7YDG7ADW453MG7DN&qid=1724952951&s=electronics&sbo=RZvfv%2F%2FHxDF%2BO5021pAnSA%3D%3D&sprefix=3.7+v+lipo+battery%2Celectronics%2C157&sr=1-2-6024b2a3-78e4-4fed-8fed-e1613be3bcce-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9zZWFyY2hfdGhlbWF0aWM&psc=1
