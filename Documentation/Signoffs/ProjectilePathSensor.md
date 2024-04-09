# Projectile Path Sensor Signoff
## Subsystem Function
The projectile Path sensor subsystem must detect when a projectile is launched and determine which of the 15 possible paths the projectile will take. This is expected to be the first sensor data sent to the interceptor. This data provies the required yaw angle to properly intercept the incoming projectiles.
## Constraints
- Constrain 1: Create an interceptor capable of functioning on its own without outside interaction. 
  - Reasoning: Do to a constumer requirement the interceptor and all external sensor post must be autonomous after intial startup.
- Constraint 2: Design a sensor array that can detect approaching objects and relay their locations to the interceptor.
  - This constraint was developed to meet the requirement to have a sensor that has determines when a projectile has begun to move towards the interceptor. Also, the sensor will determine the path at which the projectile is heading towards to the interceptor.
- Constraint 3: Design a sensor array that operates on battery power.
  - All sensor posts must be powered with a standalone powersupply and must not receive power from a outlet. This originated from a constraint provided by the constumer.
- Constraint 4: The Design shall implement the best remote battery power solution to limit the interceptor’s environmental impact.
  - This constraint addresses the broader impacts of current enviromental impacts of disposing batteries.
- Constaint 5: Design a system that complies with the ANSI Z136.1 Standard
  - This constraint is required due to the use of laser sensors to determine when a projectile is launched. This Standards clasifies lasers as well as defines the required PPE while useing lasers.
- Constraint 6: Use a processing unit that has the capability to support all required sensors as well as ability to connect to a ESP device.
  - It is expected that 16 I/O ports are required to read the object detection sensor array. The Microprocessor must be capabile of suppling sufficent power. Also, another port to comunicate and power the ESP device required in the wireless communication subsystem.
## Schematic
![image](https://github.com/JTJones73/Capstone2024-Team2/assets/158105560/42a86054-733d-40ea-b6a5-a1acf12b2075)

## Analysis
### Autonomous System
According to the Atmega 2560 Datasheet the Atmega has 256K bytes of Flash memory on the chip for program storage [Must BE CITED]. This means after an intial program of the Atmega the program will automatically run on startup. Once the microcontroller is properly programed the only step required to start the projectile path detection system is to turn on the powersupply.
### Object Detection 
### Battery
Due to the constraint of having to use battery power all sensors, lasers, and microcontroller must be ran with a standalone battery power supply. The battery chosen is two Samsung 25R 18650 [2] in series. This results in a 7.2 Volt 2500 mAh battery. This voltage is chosen due to the reccomend voltage of the atmega 2560 being 7-12 Volts[1]. Do to battery voltages decreasing as they discharge, only the mAh before the voltage decreases past 3.5 volts is taken into calculations. According to the Samsumung 25R battery data sheet, the battery discharges 1700 mAh before the voltage reaches below 3.5 volts [3]. In the table below show the total battery consumption on the system. In this table we can conclude that the external battery selected can power the sensor array for roughly 3 hours.

###

| Device | Current Draw |
| ------ | --------------- | 
| Laser Array | 450 mA at 5 Volts and ~ 322 mA at 7 Volts [4]| 
| Buck Converter| 88% efficency ~39 mA |
| Atmega 2560 | Maximum current 200 mA |
| Total | 561 mA |

### Broader impact of Battery
The choice of a lithium ion battery was a multifactor choice. The first and most important factor was to have the capability to recharge and reuse the same batteries throughout the project. According to the battery's spreadsheet when the battery is discharged at 20A for 250 cycles the batteries capacity is still nearly 2000 mAh [13]. Due to the significantly less current being discharged from the battery, it is expected that the capacity will decrease less. However, even with using provided data, it is expected to still be able ot provide power to the system for atleast 30 minutes using the 1700 maH cutoff explained above. Another alternative battery solution would have been Alkaline batteries, but due to the single use nature of the batteries many would have to be disposed of during testing. For example a premium AA batter from duracell has a nominal voltage of 1.5 Volts and can last for roughly 3 hours at a constant current of 500 mA [15]. This means a total of 5 AA batteries would have to be disposed of every 3 hours. This decreases cost effiecny as well as increasing the tecnological waste.

### Complying with Laser Saftey Standards
The Ky-008 sensor is marketed as a low power laser with a 5 mW output power [3]. This laser is a continous with a 650 nm wavelength [3] , and that classifies this laser as a Class 3R [2]. Class 3R lasers are considered safe, but if exposed for a long period injury is possible. According to ANSI Z136.1 the use of a Class 3R laser no Prcedural and Administrative Controls, Training, Medical Surveillance, and LSO is required [2] , and additionally ANSI Z136.1 reccomends an intrabeam viewing time of less thaThn .25 seconds. With the design of the laser array it is expected to have zero intrabeam viewing in order to keep all observers safe.

### Microcontroller Verification
Current requirements of the microcontroller is the ability to send 5V rail to each photoresistor as well as a ground rail to all pulldown resistors. Also, the microcontroller must supply 3.3 Volts and ground to the esp wireless communicator. According to the atmega 2560 datasheet the maximum current an I/O pin is 20mA [10]. If 100k resistors are used for pulldown resistors the total resistance is 6.667 kOhms and even assuming 0 resistance from photoresistors the max current is 0.75 mA. Also, in order to read the voltage 15 I/O ports are required. Additionally, another I/O pin is required to output the incoming projectile path that was read from the detection sensor array. The Atmega 2560 has enough pins to support this amount of I/O pins [10]. 
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
| 20 Pcs Photoresistors [18] | GL5528 | 1 | $5.99 | $5.99 |
| Total | | | | $80.62 |


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
[11] “Samsung 25R 18650 2500mah 20A battery,” 18650BatteryStore.com, https://www.18650batterystore.com/products/samsung-25r-18650? utm_campaign=21017394957&utm_source=x_c&utm_medium=cpc&utm_content=&utm_term=_&adgroupid=&gad_source=4&gclid=Cj0KCQjwn7mwBhCiARIsAGoxjaIDVn2o2IZExphwsLASVktA_GrIyjrilURVrJArgcjTx32l40fdsE0aAlPREALw_wcB [accessed Apr. 4, 2024]. \
[12] "Red Laser Transmitter Module KY-008" , DevoBOT. \
[13] Samsung, "Introduction of INR18650-25R", INR18650-25R, OCT. 2013. \
[14] "DFR0379", Digikey, https://www.digikey.com/en/products/detail/dfrobot/DFR0379/7087190?utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_Low%20ROAS%20Categories&utm_term=&utm_content=&utm_id=go_cmp-20243063506_adg-_ad-__dev-c_ext-_prd-7087190_sig-Cj0KCQjwiMmwBhDmARIsABeQ7xQ9Pm6j-yGthw0P5K98s-lWMAjiXShgotcRxq3evbAAJfUBqy9iAugaAhN0EALw_wcB&gad_source=1&gclid=Cj0KCQjwiMmwBhDmARIsABeQ7xQ9Pm6j-yGthw0P5K98s-lWMAjiXShgotcRxq3evbAAJfUBqy9iAugaAhN0EALw_wcB. \
[15] Duracell, "Alkaline-Manganese Dioxide Battery", OP1500. \
[16] "25EP514100K 100k Ohm Resistors, 1/4 W, 5% (Pack of 25)" , Amazon.com. \
[17] "ELEGOO 32 Pcs Double Sided PCB Board Prototype Kit for DIY Soldering with 5 Sizes Compatible with Arduino Kits" , Amazon.com. \
[18] "Chanzon 5mm 1 Ω ohm Photoresistor LDR Resistor 5528 GL5528 Light-Dependent Photoconductor 20pcs Photo Light Sensitive", Amazon.com \
