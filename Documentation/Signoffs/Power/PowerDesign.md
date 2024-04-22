
## Functionality
The power subsystem is the system that will provide power to all the components of the other subsystems on the robot. The subsystem will also be responsible for hosting the emergency ON/OFF switch in case of an error occurring. The power supply for this subsystem will consist of two 7.4 volt, 5200 maH batteries connected in series. The batteries will be connected to a distribution board, and the distriution board allows a parallel branch for wires to be connected to all the components of the robot.

## Specifications and Restraints
| Number | Constraint | Constraint description | Origin |
|--------|----------------------|------------------------|--------|
| 1. | ASTM B258-18 | The power subsystem shall use wire that can host at least 6 amps as the battery is capable of providing 5.2 amps per hour to prevent overheating and possible fire. | ASTM B258-18 |
| 2. |  Emergency Switch | The power subsystem shall have an emergency off switch that will cut power to all components of the robot except for the main control | Competition Specifications |
| 3. | Accessibility | The power subsystem shall have easy accecibility to all of its it components and wires | Competition Specifications |
| 4. | Fuse | The power subsystem shall have fuses in place to protect subsystem components from overcurrent | IEC 60127 |
| 5. | Load Support | The power subsytem shall provide apporpriate voltage and current under max load conditions of every subsystem | Battery Specifications | 
| 6. | Noise Suppresion| The switching supply noise from the buck converters and the motors shall be mitigated to prevent signal and circuit interferences | Team Strategy Specification |


## Buildable Schematic

Wiring Chart

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Wiring_diagram.png)

Main Power Distribution

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/New_Main.png)

Arduino Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/MC_New.png)

The arduino has a buck converter connected to it because the recommended operating voltage is 7-12 volts, but can handle from 6-20 volts. The adjustable buck converter will step down the 14.8 volts from the main power supply to 12 volts. If 14.8 volts are applied directly to the arduino for long periods of time then the arduino will start to overheat. Applying too much voltage can also damage the on board voltage regulator.

Drive Train Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Drive_T.png)

The motor shield will have internal flyback diodes and noise shielding to help prevent back emf from the motors causing damage to the board and other nearby components. To ensure more noise reduction the wires for the DC motors will be winded together. 

Team Spirit Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Power_TS.png)

The NMOS MOSFET that is connected to the main power supply allows power isolation from the arduino digital signal pin. 

Navigation Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/NAVG.png)

Pushbutton Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/PB_Servo_schematic.png)

Box Sweep Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Box_Servo_schematic.png)

Start Sensor and Backup Push Button Switch Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Start_sensor_schematic.png)

Battery Placement on chassis

![ALt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Battery_placement.png)

The best location for storing the batteris would be undernath the chassis. If placed on the top platform of the chassis then it would interfere with the start sensor and the pushbutton subsystems. When placed on the bottom of the chassis the ground clearence of the robot will be reduced 0.98 inches as this is the thickness of the batteries. The total ground clearence after placing the batteries is 2.76 inches instead of 3.74 inches before. To hold the batteries to the bottom of the chassis, metal band strap will be used to bolt the batteries in place. 

Power bus/buck converters/emergency ON/OFF switch

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Power_board_dc_buck_converters.png)

To make room for the power distribution board, buck converters, and emergency ON/OFF switch, the power distribution board will be mounted 2 inches higher than the chassis platform. Since our total height is 3.74 inches, raising the power distribution board by 2 inches to 5.74 inches total allows the robot to stay well within 1 cubic foot. Having this extra heighth allows more room for the buck converters and emergency switch to be mounted as well. 


## Analysis 

**Constraint Solution 1:**
In order to prevent the wire from overheating from overcurrent draw from the battery, the power subsystem will use 16-gauge wires. This gauge of wire is capable of hosting up to 13 amps max. This wire was also chosen because the next smallest wire is 18-gauge wire, which can only hose 5 amps and out battery can supply 5.2-amp hours.

**Constraint Solution 2:**
The IEEE SECON competion requires that all competitors must have an emergency shut off switch for the safey concerns. In order to effectively cut power from all subsystems and not just cut power from the main controller is to implement a stop button or toggle switch that cuts power from the battery to the power distribution board. The power distribution board that will be used is a Evemodel PCB012 Power Distribution Board. This board has pins connected to implement a switch that cuts power from the battery to all ports of the distribution board. The main controller will not be connected to the main power distribution board. This is to prevent the main controller from getting turned off from the emergency ON/OFF switch that turns off power to all the other subystem components. To seperate power connections from the emergency ON/OFF switch, the battery wires will be split using a 1 in 2 out terminal block splice connector. This will allow two seperate wires for each of the positve end of the battery terminal and the negative end of the battery terminal. One pair of positive and negative wires will go to the power distribution board while the other pair will go to the main controller. 

Emergency Switch Connection to Power Distribution Board

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Emergency_Switch.png)

1 in 2 out splice

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Splice.png)

**Constraint Solution 3:** 
For organization and easier maintenance, wires from the the distribution board will be seperated using wire seperators. The wires will also have printed labeles that show what location the wire is coming from and what subsystem it is going to. The power susbystem connectors shall be mainly comprised of screw terminals to allow easy access for checking and maintaining the wires. The connection from the battery to the power distribution board will use Dean style connector. The connection from the power distribution board to the arduino will use a DC jack for supplying power to the board.

**Constraint Solution 4:**
The main control board that will be used is an Arduino Mega 2560. The max current the trace of the Arduino PCB can handle is 2 amps. The power supplied from all the subsystems being directly powered from the Arduino board will not exceed over 1 amp. To ensure that the current does not exceed over 2 amps there is a CC knob on the buck converter that can adjust the current down to 1 amp, and a 12 ohm resistor will be put in place to prevent overcurrent load to the arduino. As a fail safe, the Arduino will also have an inline blade fuse rated for 2 amps.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Fuse.png)

**Constraint Solution 5:** 
In order to select the correct battery, the max voltage and current draw conditions of every subsystems component was collected. The battery chosen supplies 5200mAH of current which provides an extra 620mAH if needed, compared to the max current load demand of the entire robot. When modeling the load demand of the system, all the components of every subsytem can modeled as a resistor using Ohm's Law by using the max voltage and current draw of each component. To model dc to dc step down buck converter voltages in LT-SPice, a zener diode was used, and to apply the correct step down voltage from the main power supply, the forward bias voltage was chosen based off of the previous node voltages. The results after running the simulation under max conditions was 4.58 Amps.

Representative Power Supply and Loads

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Representative_Power_circuit.png)

Total Load Results under Max Conditions

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Total_Load.png)


**Constrain Solution 6:**

**Noise from Buck Converters**

Since the buck converters have switching components in them, there will be some noise present feeding from the rails of the buck converter to the subsystem they supply. The buck converters that will be used are LM2596S. One of the causes for noise being supplied is due to the ripple voltage coming off the positive and negative terminals of the voltage rails due to the output capacitor. According to Texas Instruments data sheet, the switching frequency of the LM259s is 150kHz, the series inductance is 33uH and, the output capacitor 220uF. Using the ripple voltage equation for a buck converter we can calculate the output noise. The output ripple voltage is approximately 174mV peak-to-peak when applying 14.8 volts to the positive side and adjusting the output to 12 volts from the buck converter. The maximum output ripple voltage that the LM2596S can produces is approximately 200mV peak-to-peak according to the data sheet. The IR sensor uses a Kb33 voltage regulator chip which has a PSRR (Power Supply Ripple Rejection) of 0.5 Vpp which is well above the buck converters max ripple voltage noise output. Even though our output ripple voltage noise from the buck converter is lower as compared to the specifications of the IR sensor, the wires connected from the buck converter to the IR sensor will be twisted together to take extra precaution. 

Adjustable Buck Converter Maximum Output Ripple Noise

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Ripple_noise.png)


**Noise from Motors**

To help mitigate noise from the motors, pololu suggests that using capacitors are usually the most effective, and recommend soldering at least one capacitor across your motor terminals. Typically you will want to use anywhere from one to three 0.1 µF ceramic capacitors, soldered as close to the motor casing as possible. Since our motors are bidirectional, and we need bidirectional control, Pololu suggest that for our application that we do not use a polarized capacitor.

Connection of capacitors to motors

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Capacitor_connections.png)

**Arduino Input Noise**

The Arduino can handle an input voltage range of 6-20 volts. The voltage supplied from the buck converter output side is stepped down to 12 volts from the main power supply and connected to the Arduino. Since the buck converter outputs at maximum 200mV peak-to-peak of ripple voltage then the maximum input voltage the Arduino will undergo is 12.2 volts which is well within the range of 6-20 volts. As for the current supplied to the arduino, the maximum current that can be supplied is 2 amps with a minumum supply current of 500mA which our buck converter is capable of supplying. (Protection from overcurrent to the Arduino in constraint solution 4).

**Push Button and Box Sweep Input Noise/operating conditions**

Based off the MG996R servo data sheet, the servos for the Push button and the box sweep subsystem will be able to handle the output voltage from the buck converters. The buck converters output voltage for these two subsystems will be adjusted with the VC knob to be 6 volts. Considering that the maximum peak-to-peak voltage output noise from the buck converters are 200mV peak-to-peak, the max voltage range the servos will undergo is approximately 6.2 volts and 5.8 volts minimum which is well within the maximum input range of 4.8 – 7.2 volts. Since the MG996R servos are operating in approximately the 6-volt range, the operating current is 500mA -900mA, and the stall torque current is 2.5 amps which our buck converter is able to supply up to 5 amps, but the CC knob will be adjusted to under the 2.5-amp range to prevent shorting of the motor windings within the MG996R. 

**Start Sensor Input Noise/operating conditions**

The APDS-9960 RGB sensor data sheet states the operating voltage is 2.4-3.6 volts. The start sensor will be powered from the 3.3-volt output pin from the Arduino. The Arduinos internal power supply for the 3.3-volt pin uses a low noise LP2985 voltage regulator.  The output noise from the LP2985 according to the data sheet states it is 30u VRMS which is equivalent to 85u volts peak-to-peak which under max condition the sensor will undergo 3.300085 volts and under minimum operation the sensor will have 3.29991516 volts which is well within the range of 2.4-3.3 volts for the APDS-9960 RGB sensor.  According to the start sensor data sheet pin out, the sensor board does not need an external current limiting sensor when connected to the 3.3-volt pin on the Arduino and the minimum operation current for the board is approximately 0.2mA which the 3.3-volt pin is capable of supplying. 

**Team Spirit Input Noise/operating conditions**

The operation of the LEDs is from 3-6 volt and 5-25mA. Since the strip of LEDs are in parallel with each other the total current needed to supply the load is approximately 1.6 amps under max current draw and 0.32 amps at minimum current draw. The average current draw is at 1.28 amps. The buck converter will supply the voltage at 5 volts for nominal operation. Under max conditions the LEDs will undergo are 5.2 volts and for minimum conditions the LEDs will undergo 4.8 volts which is well within the specified range of the LEDs. The supply current on the buck converter will be adjusted for approximately 1.4 amps to supply enough current for operation for all the LEDs while 1.4 amps is not enough to burn out the parallel LEDs.





## BOM
| Item | Description | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-------------|--------------|----------|-------|-------------|
| Batteries | 7.4V Lipo Battery 2S 50C 5200mAh Lipos  | N/A | Zeee | 2 | $30.99 | $30.99 |
| Power distribution board | distributes parellel branch wires to other components | N/A | 	Evemodel | 1 | $16.99 | $16.99 |
| Buck Converters | Steps down voltage from main power | LM2596 | Valefod | 5 | $16.88 | $16.88 |
| Wire | 16AWG 100FT Electrical Wire Cable 2 Conductors Red Black | N/A | Askcable | 100 ft. | $15.19 | $15.19 |
| Emergency switch | Used to cut power to all systems| N/A | N/A | 1 | Recycled | Recycled |
|Band Strap| Holds battery pack in place to the chassis | N/A | N/A | 2 | Recycled | Recycled |
| Fuse | Protects the main control from over current | N/A | GNAWRISHING | 3 | $9.98 | $9.98 |
| Splicer | Allows seperation of power shut off from all other subsystem | B0B28GYYL2 | XALXMAW | 20 | $12.98 | $12.98 |
| Deans T Style connector | Allows connection from batteries to power distribution board | B07WHPD4KD | elechawk | 5 | $8.99 | $8.99 |
|0.1uF Capacitor | Used to mitigate noise from the motors | N/A | N/A | 2 | Recycled | Recycled |
|      |                                             |     |             |   |       | $112 |