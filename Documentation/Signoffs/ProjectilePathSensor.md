# Projectile Path Sensor Signoff

## Subsystem Function
The projectile Path sensor subsystem must detect when a projectile is launched and determine which of the 15 possible paths the projectile will take. This is expected to be the first sensor data sent to the interceptor. This data provides the required yaw angle to properly intercept the incoming projectiles. In order to complete this functionality An array of lasers will be placed over all projectile paths and when a ball breaks a laser beam that data will be received by a microcontroller.
## Constraints
| Constraint # | Description | Origin |
| ----- | ------------------------- | -------------------|
| 1 |  The Path Sensor Array shall be autonomous and will require no outside interference after initial startup. | The customer requires the interceptor and all external sensor posts must be autonomous after initial startup. |
| 2 | The Path Sensor Array shall be capable of detecting which of the possible 15 paths an approaching object is taking and relay this value to the interceptor. | This constraint was developed by the team, to have a sensor that can determine when a projectile has begun to move toward the interceptor and determine the path at which the projectile is taking. |
| 3 |  The Path Sensor Array shall be operated on battery power and must be capable of supplying power to the subsystem for 30 minutes. | This constraint originates from a customer and competition requirement, and the 30-minute requirement is to verify the system can operate during the entire competition |
| 4 | The Path Sensor Array shall limit the waste of batteries. | This constraint originates from the broader impacts of the current environmental impacts of disposing batteries. |
| 5 | The Path Sensor Array shall comply with the ANSI Z136.1 Standard for safety requirements for a Class 3R laser. This includes having no intentional ocular exposure and installation of a warning sign. | This constraint is required due to the use of lasers in the sensor array, and the need to meet this standard to keep all spectators safe. | 
| 6 | The Path Sensor Array shall implement a microcontroller that has 17 I/O pins, 15 Pin change interrupts, and a 5 Volt pin. All these pins are required to receive and send all sensor data. | The microcontroller must meet this constraint to read the sensor array data for all paths | 
| 7 | The Path Sensor Array shall be closer than .84 inches from each projectile path | This constraint originates from the size of the projectile, and to verify that the sensors will detect a projectile. |


## Schematic
![image](https://github.com/JTJones73/Capstone2024-Team2/assets/158105560/d90f4950-3756-487e-8ea4-bf54e7a5310c) 
The schematic above shows all electrical connections in this subsystem. All laser modules will be powered by a central terminal block at the end of the sensor post. Additionally, all photoresistors will be powered using a 5-volt terminal block that is powered by the Atmega 2560's 5-volt rail. All other components that are not required to be housed on the sensor post extension will be soldered in a separate housing on the sensor post to limit the wiring on the extension.\
<img src="https://github.com/JTJones73/Capstone2024-Team2/blob/Tkasubosk42-Signoff-ProjectilePathSensor/Documentation/Signoffs/ProjectilePathSensorImages/LaserHousingFront.jpg" width="500" height="500">
<img src="https://github.com/JTJones73/Capstone2024-Team2/blob/Tkasubosk42-Signoff-ProjectilePathSensor/Documentation/Signoffs/ProjectilePathSensorImages/LaserHousingBack.jpg" width="500" height="500">
The two 3D schematics above show the Ky-008 laser module and the housing that will be printed to properly attach the laser to the sensor post extension. The purpose of this housing is to properly mount the laser while also allowing for adjustment of the laser module location. The laser housing will slide through the sensor post-extension rail to guarantee the laser's distance from the extension while still allowing adjustability along the extension.\
<img src="https://github.com/JTJones73/Capstone2024-Team2/blob/Tkasubosk42-Signoff-ProjectilePathSensor/Documentation/Signoffs/ProjectilePathSensorImages/Photoresistor%201.jpg" width="333" height="500">
<img src="https://github.com/JTJones73/Capstone2024-Team2/blob/Tkasubosk42-Signoff-ProjectilePathSensor/Documentation/Signoffs/ProjectilePathSensorImages/Photoresistor%202.jpg" width="333" height="500">
<img src="https://github.com/JTJones73/Capstone2024-Team2/blob/Tkasubosk42-Signoff-ProjectilePathSensor/Documentation/Signoffs/ProjectilePathSensorImages/photoresistor%203.jpg" width="333" height="500">
The three 3D schematics above show the housing for the photoresistors. Similar to lasers the goal of this housing is to attach the photoresistors to the sensor-post extension. The housing has a constant distance from the extension and an adjustable distance along the extension. This housing and the laser housing increase the accuracy of the laser array by limiting the number of directions the sensors that must be adjusted.  

## Analysis 

### Autonomous System

According to the Atmega 2560 datasheet, the Atmega has 256K bytes of Flash memory on the chip for program storage [10]. This means after an initial program of the Atmega the program will automatically run on startup. Once the microcontroller is properly programmed the only step required to start the projectile path detection system is to turn on the power supply. Also, this functionality verifies that the microcontroller will also function autonomously even if there is a sudden restart of the Atmega.
### Object Detection 

For the sensor array to detect when an incoming projectile has been launched, the array will have a laser setup below each projectile path and a photoresistor above each projectile path. All photoresistors are powered by the Atmega 2560's 5-volt rail. Then all photoresistors are attached to a 100k ohm pull-down resistor. So, when the photoresistor has contact with the laser the photoresistor has a small resistance resulting in the voltage before the pull-down resistor is greater than 3 volts. On the other hand, when a projectile blocks the laser the photoresistor has a large resistance resulting in the voltage before the pull-down resistor is less than 3 volts.

To calculate the intensity of the lasers used the calculation required is $I = P / A$. For the Ky-008 laser with a diameter of 6mm and 5 mW, the intensity is 0.17687 mW/mm^2. This is also equal to 17.687 mW/cm^2. Finally, the equation to convert laser power into lumens is $V(x) = 1.019e^(-285.4(x-0.559)^2)$ where x is the wavelength of the laser in this case it is .650 [19]. In this case the amount of lumens = 0.9589 * 17.687. This means the total amount of lumens from this laser is calculated to be 1.696 lumens/cm^2. Finally, because photoresistors calculate resistance into flux the final conversion is from lumens/cm^2 to lumens/m^2. This means that the laser will produce 16,960 lux. To be conservative I can estimate half of this lux at 8480 lux.

To determine the lux of the photoresistor when the laser is being blocked by a projectile. Firstly, the photoresistor is expected to be placed inside a cylinder that has a hight of 6 inches and a radius of 1 inch. Also, there will be a hemisphere on top of the cylinder with a 5mm radius hole cut out of it. This results in a surface area of 43.9823 in^2 without the hole and 0.2435 in^2. If we take the ratio (0.2435/43.9823)*100 is 0.554 percent. This means we can roughly estimate that the amount of light that the photoresistor receives from ambient light is about 0.554 percent. Finally, according to Thorlux Lighting, the average classroom has a lux of 300 [19]. This means that the ambient lighting can roughly be expected to be 1.66 lux.

According to the atmega 2560's data sheet for an input pin to change from low to high the pin must read a value of at least 3 volts [10]. Using this voltage the required resistance to change the input is 66.667k ohms. According to the photo resistor's datasheet, the GL5539's resistance drops below 66.667k ohms at a lux between 5-25 [20]. This means that when the laser beam is not blocked the resistance will be less than 66.667k and when a projectile is blocking the laser it will be greater. An Atmega pin is connected between the photoresistor and pulldown resistor, and if a pin input changes value an interrupt will occur. Once that interrupt occurs the Atmega will determine which path the projectile is on, and this data will be transmitted to the launcher.


### Battery
One of the requirements of the Devcom interceptor competition is that all components that are not housed on the main interceptor body must be powered remotely. For this sensor array an Atmega 2560 and 15 KY-008 laser modules, and an array of resistors.

According to the Atmega 2560's datasheet, the recommended input voltage is 7-12 Volts and has a maximum current of 200 mA [10]. The Atmega will be responsible for supplying 5 volts to the photoresistor array. So, that will be accounted for in the maximum current draw of the Atmega. 

The source of the battery's current draw is the laser modules. According to the KY-008 datasheet, the current draw of one laser is 30 mA at 5 Volts [4]. 15 laser modules will require 450 mA at 5 volts. The Atmega2560 5V pin has a maximum output current of 200 mA [10]. Therefore, the Laser modules must be powered separately. To do this an adjustable buck converter will be used to step down 9 volts to 5. The buck converter according to the data sheet has a 88 percent efficiency rate. This is an additional power loss that must be calculated. The table below shows the total current draw of the system. 

The battery that was chosen to power this system is a 6LR61 9-volt battery. According to the datasheet, a constant current draw of 500 mA has a capacity of roughly 300 mAh. This capacity results in an operating time of over 30 minutes meeting the required constraint.

| Device | Current Draw |
| ------ | --------------- | 
| Laser Array | 450 mA at 5 Volts and ~ 250 mA at 9 Volts [4]| 
| Buck Converter| 88% efficency ~30 mA |
| Atmega 2560 | Maximum current 200 mA |
| Total | 480 mA |

### Broader impact of Battery

All common batteries have expensive and environmentally harmful materials because of this, the team has made the constraint to limit the battery waste created by the projectile path sensor array. To ensure this, batteries will only be used during the competition. For all testing, an AC to DC converter will be used to power the projectile path sensor. 


### Complying with Laser Saftey Standards

The Ky-008 sensor is marketed as a low-power laser with a 5 mW output power [3]. This is a continuous laser with a 650 nm wavelength [3], and that classifies this laser as a Class 3R [2]. Class 3R lasers are considered safe, but if exposed for a long period injury is possible. According to ANSI Z136.1, the use of a Class 3R laser does not require procedural and administrative controls, training, medical surveillance, and LSO [2]. Additionally, ANSI Z136.1 recommends an intrabeam viewing time of less than .25 seconds. With the design of the laser array, it is expected to have zero intrabeam viewing to keep all observers safe. Finally, because of the class 3R laser the sensor requires a warning label [3] the team will add this sign to the interceptor body.

### Microcontroller Verification

Current requirements of the microcontroller include the ability to create a 5-volt rail that each photoresistor connects to. Also, a ground rail is required to be connected to all pulldown resistors. According to the Atmega 2560 datasheet, the maximum current of an I/O pin is 20mA [10]. If 100k resistors are used for pulldown resistors the total resistance is 6.667 kOhms and even assuming 0 resistance from photoresistors the max current is 0.75 mA. Also, to read the voltage drop of the photoresistors 15 I/O ports are required. Additionally, 2 other I/O Rx and TX pins are required to output the incoming projectile path using serial communication. The Atmega 2560 has enough pins to support this amount of I/O pins [10]. Also, according to the Atmega 2560's datasheet, there is a total of 24 pin change interrupts meaning this constraint is also met [10]. Finally, multiple 5-volt and ground pins are available on the Atmega 2560 [10].

### Sensor Path Accuracy

According to the USGA a golf ball must be at least 1.68 inches in diameter [11]. Assuming that the golf balls will be directly in the center of the paths, each path sensor must be at least within  0.84 inches of the path. To meet this constraint housing will be 3d printed for the laser and photoresistor. These housings can be seen in the schematic section above, and finally the use of a rail for the laser and photoresistors will allow for nearly perfect accuracy.

## Bill of Materials

| Item | Part Number | Quantity | Price Per Unit | Total Cost |
| ----------------- | ---- | ----| ------| ------ |
| Elegoo Atmega 2560 [7] | EL-CB-002 | 1 | $20.99 | $20.99 | 
| Samsung 25R 18650 [11] | 25R | 2 | $3.75 | $7.50 |
| 18650 Battery Holder [6] | 114090053 | 1 | $1.49 | $1.49 |
| 8 pack of Lasers [1] | Ky-008 | 2 | $11.99 | $23.98 |
| Adjustable DC-DC Buck Converter [14] | DFR0379 | 1 | $4.90 | $4.90 |
| 100k Ohm Resistors 25 Pack [16] | 25EP514100K | 1 | $5.78 | $5.78 |
| 32Pcs of PCB board [17] | NA | 1 | $9.99 | $9.99 | 
| 20 Pcs Photoresistors [18] | GL5539 | 1 | $5.99 | $5.99 |
| 6 sets of Terminal Blocks [21] | NA | 1 | $13.99 | $13.99 |
| Total | | | | $94.61 |


## Refrences
[1] "8PCS 3 Pin 650nm 5V Laser Transmitter Sensor Module Board KY-008 Dot Diode Copper Head Sensor Module Diode Laser Mini laser head for Arduino Raspberry Pi Laser", Amazon.com. \ 
[2]  "American National Standard for Safe Use of Lasers" , ANSI Z136.1 , AMERICAN NATIONAL STANDARDS INSTITUTE, 2022. \
[3] ArduinoModules, “KY-008 laser transmitter module,” ArduinoModulesInfo, https://arduinomodules.info/ky-008-laser-transmitter-module/ (accessed Apr. 6, 2024). \
[4] AZ Delivery, "Ky-008 Laser Trasmitter Modul Datenblatt"m ky-008, 2017. \
[5] DFRobot, "20W Adjustable DC-DC Buck Converter with Digital Display", DFR0379, Feb, 2017. \
[6] “114090053,” Digikey, https://www.digikey.com/en/products/detail/seeed-technology-co.,-ltd/114090053/10451921?utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_Low%20ROAS%20Categories&utm_term=&utm_content=&utm_id=go_cmp-20243063506_adg-_ad-__dev-c_ext-_prd-10451921_sig-Cj0KCQjwn7mwBhCiARIsAGoxjaL8WD90igyFKSXdHxOkua8whupC5BGHClnKJqEKValV6_VOdacOF8caAilXEALw_wcB&gad_source=1&gclid=Cj0KCQjwn7mwBhCiARIsAGoxjaL8WD90igyFKSXdHxOkua8whupC5BGHClnKJqEKValV6_VOdacOF8caAilXEALw_wcB (accessed Apr. 4, 2024). 
[7] “ELEGOO MEGA R3 Board ATmega 2560 + USB Cable Compatible with Arduino IDE Projects RoHS Compliant,” Amazon.com.\
[8] "Laser Classification" , Weill Cornell Medicine. 
[9] "Mega 2560 Rev3," docs.arduino.cc, Available: https://docs.arduino.cc/hardware/mega-2560/#features. [accessed Apr. 4, 2024]. \
[10] Microchip, "ATmega640/V-1280/V-1281/V-2560/V-2561/V" , Atmega2560, Mar. 2025 [Revised May. 2020]. \
[11] “Golf ball regulations for diameter, weight and beyond,” Golf Ball Regulations for Diameter, Weight and Beyond Golflink.com, https://www.golflink.com/equipment/definition-golf-ball (accessed Apr. 20, 2024). 
[12] "Red Laser Transmitter Module KY-008" , DevoBOT. \
[13] 
[14] "DFR0379", Digikey, https://www.digikey.com/en/products/detail/dfrobot/DFR0379/7087190?utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_Low%20ROAS%20Categories&utm_term=&utm_content=&utm_id=go_cmp-20243063506_adg-_ad-__dev-c_ext-_prd-7087190_sig-Cj0KCQjwiMmwBhDmARIsABeQ7xQ9Pm6j-yGthw0P5K98s-lWMAjiXShgotcRxq3evbAAJfUBqy9iAugaAhN0EALw_wcB&gad_source=1&gclid=Cj0KCQjwiMmwBhDmARIsABeQ7xQ9Pm6j-yGthw0P5K98s-lWMAjiXShgotcRxq3evbAAJfUBqy9iAugaAhN0EALw_wcB. \
[15] Energizer, "Industrial (6LR61)", 6LR61.
[16] "25EP514100K 100k Ohm Resistors, 1/4 W, 5% (Pack of 25)" , Amazon.com. \
[17] "ELEGOO 32 Pcs Double Sided PCB Board Prototype Kit for DIY Soldering with 5 Sizes Compatible with Arduino Kits" , Amazon.com. \
[18] "Chanzon 5mm 5 Ω ohm Photoresistor LDR Resistor 5539 GL5539 Light-Dependent Photoconductor 20pcs Photo Light Sensitive", Amazon.com \
[19] "Light Emitting Diode Drivers Selection Guide" , ThorLabs. \
[20] "GL55 Series Photoresistor", GL5539. \
[21] "Terminal Block 10 Position, 12PCS 6 Set Terminal Block Strip & Ground Terminal Block, Screw Terminal Block with Cover, Pluggable PCB Terminal Blocks, Busbar Terminal Blocks 600V 15A Dual Row Insulated", Amazon.com.
