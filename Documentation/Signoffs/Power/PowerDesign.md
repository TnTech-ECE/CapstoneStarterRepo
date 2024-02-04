
## Functionality
The power subsystem is the system that will provide power to all the components of the other subsystems on the robot. The subsystem will also be responsible for hosting the emergency ON/OFF switch in case of an error occurring. The power supply for this subsystem will consist of two 7.4 volt, 5200 maH batteries connected in series. The batteries will be connected to a distribution board, and the distriution board allows a parallel branch for wires to be connected to all the components of the robot.

## Specifications and Restraints
| Number | Constraint | Constraint description | Origin |
|--------|----------------------|------------------------|--------|
| 1. | ASTM B258-18 | The power subsystem shall use wire that can host at least 6 amps as the battery is capable of providing 5.2 amps per hour to prevent overheating and possible fire. | ASTM B258-18 |
| 2. |  Emergency Switch | The power subsystem shall have an emergency off switch that will cut power to all components of the robot  | Competition Specifications |
| 3. | Accessibility | The power subsystem shall have easy accecibility to all of its it components and wires | Competition Specifications |
| 4. | Fuse | The power subsystem shall have fuses in place to protect subsystem components from overcurrent | IEC 60127 |
| 5. | Load Support | The power subsytem shall provide apporpriate voltage and current under max load conditions of every subsystem | Battery Specifications | 


## Buildable Schematic

Wiring Chart

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Wiring_diagram.png)

Main Power Distribution

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/MAIN.png)

Arduino Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/MC_New.png)

The arduino has a buck converter connected to it because the recommended operating voltage is 7-12 volts, and the adjustable buck converter will step down the 14.8 volts from the main power supply to 12 volts. If 14.8 volts are applied directly to the arduino for long periods of time then the arduino will start to overheat. Applying too much voltage can also damage the on board voltage regulator.

Drive Train Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Drive_T.png)

The motor shield will have internal flyback diodes and noise shielding to help prevent back emf from the motors causing damage to the board and other nearby components. To ensure more noise reduction the wires for the DC motors will be winded together. 

Team Spirit Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Team_S.png)

The NMOS MOSFET that is connected to the main power supply allows power isolation from the arduino digital signal pin. 

Navigation Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/NAVG.png)

Pushbutton Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Push_button_power.png)

Box Sweep Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Box_sweep.png)

Start Sensor and Backup Push Button Switch Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Start.png)

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
The IEEE SECON competion requires that all competitors must have an emergency shut off switch for the safey concerns. In order to effectively cut power from all subsystems and not just cut power from the main controller is to implement a stop button or toggle switch that cuts power from the battery to the power distribution board. The power distribution board that will be used is a Evemodel PCB012 Power Distribution Board. This board has pins connected to implement a switch that cuts power from the battery to all ports of the distribution board.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Emergency_Switch.png)

**Constraint Solution 3:** 
For organization and easier maintenance, wires from the the distribution board will be seperated using wire seperators. The wires will also have printed labeles that show what location the wire is coming from and what subsystem it is going to. The power susbystem connectors shall be mainly comprised of screw terminals to allow easy access for checking and maintaining the wires. The connection from the battery to the power distribution board will use Dean style connector. The connection from the power distribution board to the arduino will use a DC jack for supplying power to the board.

**Constraint Solution 4:**
The main control board that will be used is an Arduino Mega 2560. The max current the trace of the Arduino PCB can handle is 2 amps. The power supplied from all the subsystems being directly powered from the Arduino board will not exceed over 1 amp. To ensure that the current does not exceed over 2 amps there is a 12 ohm resistor in place to prevent overcurrent load to the arduino. If the voltage from the battery is 14.8V then we can use a 12 ohm resistor in order to keep keep a constant current supplied to the Arduino. Using Ohm's law the approximate constant current supplied to the Arduino would be around 1.233 amps. As a fail safe, the Arduino will have an inline blade fuse rated for 2 amps. 

**Constraint Solution 5:** 
In order to select the correct battery, the max voltage and current draw conditions of every subsystems component was collected. The battery chosen supplies 5200mAH of current which provides an extra 620mAH if needed, compared to the max current load demand of the entire robot. When modeling the load demand of the system, all the components of every subsytem can modeled as a resistor using Ohm's Law by using the max voltage and current draw of each component. To model dc to dc step down buck converter voltages in LT-SPice, a zener diode was used, and to apply the correct step down voltage from the main power supply, the forward bias voltage was chosen based off of the previous node voltages. The results after running the simulation under max conditions was 4.58 Amps

Representative Power Supply and Loads

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Representative_Power_circuit.png)

Total Load Results under Max Conditions

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Total_Load.png)

## BOM
| Item | Description | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-------------|--------------|----------|-------|-------------|
| Batteries | 7.4V Lipo Battery 2S 50C 5200mAh Lipos  | N/A | Zeee | 2 | $30.99 | $30.99 |
| Power distribution board | distributes parellel branch wires to other components | N/A | 	Evemodel | 1 | $16.99 | $16.99 |
| Buck Converters | Steps down voltage from main power | LM2596 | Valefod | 5 | $16.88 | $16.88 |
| Wire | 16AWG 100FT Electrical Wire Cable 2 Conductors Red Black | N/A | Askcable | 100 ft. | $15.19 | $15.19 |
| Emergency switch | Used to cut power to all systems| N/A | N/A | 1 | Recycled | Recycled |
