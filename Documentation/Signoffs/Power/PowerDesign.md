
## Functionality
The power subsystem is the system that will provide power to all the components of the other subsystems on the robot. The subsystem will also be responsible for hosting the emergency off switch in case of an error occurring. The power supply for this subsystem will consist of two 7.4 volt, 5200 maH batteries connected in series. The batteries will be connected to a distribution board, and the distriution board allows a parallel branch for wires to be connected to all the components of the robot.

## Specifications and Restraints
| Number | Constraint | Constraint description | Origin |
|--------|----------------------|------------------------|--------|
| 1. | ASTM B258-18 | The power subsystem shall use wire that can host up to 6 amps as the battery is capable of providing 5.2 amps per hour to prevent overheating and possible fire. | ASTM B258-18 |
| 2. |  Emergency Switch | The power subsystem shall have an emergency off switch that will cut power to all components of the robot  | Competition Specifications |
| 3. | Accessibility | The power subsystem shall have easy accecibility to all of its it components | Competition Specifications |
| 4. | Fuse | The power subsystem shall have fuses in place to protect subsystem components from overcurrent | IEC 60127 |


## Buildable Schematic

Wiring Chart

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Wiring%20chart.PNG)

Main Power Distribution

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/MAIN.png)

Arduino Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/MC.png)

Drive Train Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Drive_T.png)

Team Spirit Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Team_S.png)

Navigation Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/NAVG.png)

Pushbutton Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Push_button_power.png)

Box Sweep Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Box_sweep.png)

Start Sensor and Backup Push Button Switch Power Connections

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoffs-Power/Documentation/Images/Powe-Images/Start.png)


## Analysis 

**Constraint Solution 1:**
In order to prevent the wire from overheating from overcurrent draw from the battery, the power subsystem will use 16-gauge wires. This gauge of wire is capable of hosting up to 10 amps max. This wire was also chosen because the next smallest wire is 18-gauge wire, which can only hose 5 amps and out battery can supply 5.2-amp hours.

**Constraint Solution 2:**
The IEEE SECON competion requires that all competitors must have an emergency shut off switch for the safey concerns. In order to effectively cut power from all subsystems and not just cut power from the main controller is to implement a stop button or toggle switch that cuts power from the battery to the power distribution board. The power distribution board that will be used is a Evemodel PCB012 Power Distribution Board. This board has pins connected to implement a switch that cuts power from the battery to all ports of the distribution board.

**Constraint Solution 3:** 
For organization and easier maintenance, wires from the the distribution board will be seperated using wire seperators. The wires will also have printed labeles that show what location the wire is coming from and what subsystem it is going to. The power susbystem connectors shall be mainly comprised of screw terminals to allow easy access for checking and maintaining the wires. The connection from the battery to the power distribution board will use Tamiya style connector. The connection from the power distribution board to the arduino will use a DC jack for supplying power to the board.

**Constraint Solution 4:**
The main control board that will be used is an Arduino Mega 2560. The max current the trace of the Arduino PCB can handle is 2 amps. The power supplied from all the subsystems being directly powered from the Arduino board will not exceed over 1 amp. To ensure that the current does not exceed over 2 amps there is a 12 ohm resistor in place to prevent overcurrent load to the arduino. If the voltage from the battery is 14.8V then we can use a 12 ohm resistor in order to keep keep a constant current supplied to the Arduino. Using Ohm's law the approximate constant current supplied to the Arduino would be around 1.233 amps. As a fail safe, the Arduino will have an inline blade fuse rated for 2 amps. 

## BOM
| Item | Description | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-------------|--------------|----------|-------|-------------|
| Batteries | 7.4V Lipo Battery 2S 50C 5200mAh Lipos Hard Case with | N/A | Zeee | 2 | $30.99 | $30.99 |
| Batteries | Power Supply | PCB012 Power Distribution Board Self-Adapt Distributor | 	Evemodel | 1 | $16.99 | $16.99 |
