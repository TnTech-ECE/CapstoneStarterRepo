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
  - It is expected that 30 I/O ports are required to power the laser sensor array. The Microprocessor must be capabile of suppling sufficent power. Also, another port to comunicate and power the ESP device required in the wireless communication subsystem.
## Schematic
## Analysis
### Battery
Due to the constraint of having to use battery power all sensors, lasers, and microcontroller must be ran with a standalone battery power supply. The battery chosen is two Samsung 25R 18650 [2] in series. This results in a 7.2 Volt 2500 mAh battery. This voltage is chosen due to the reccomend voltage of the atmega 2560 being 7-12 Volts[1]. Do to battery voltages decreasing as they discharge, only the mAh before the voltage decreases past 3.5 volts is taken into calculations. According to the Samsumung 25R battery data sheet, the battery discharges 1700 mAh before the voltage reaches below 3.5 volts [3]. In the table below show the total battery consumption on the system.

## Refrences
[1] "Mega 2560 Rev3," docs.arduino.cc, Available: https://docs.arduino.cc/hardware/mega-2560/#features. [accessed Apr. 4, 2024].
[2] “Samsung 25R 18650 2500mah 20A battery,” 18650BatteryStore.com, https://www.18650batterystore.com/products/samsung-25r-18650?utm_campaign=21017394957&utm_source=x_c&utm_medium=cpc&utm_content=&utm_term=_&adgroupid=&gad_source=4&gclid=Cj0KCQjwn7mwBhCiARIsAGoxjaIDVn2o2IZExphwsLASVktA_GrIyjrilURVrJArgcjTx32l40fdsE0aAlPREALw_wcB [accessed Apr. 4, 2024]. 
[3] Samsung, "Introduction of INR18650-25R", INR18650-25R, OCT. 2013.
