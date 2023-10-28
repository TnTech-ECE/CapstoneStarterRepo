# Safety System
## Function of the system
This system will shut-off power to the pulse inverter if the system becomes unsafe, halting any gas production. The system consists of a flame detector, pressure sensor, temperature sensor, and an emergency stop button. Normally open relay contacts will be connected to all components previously mentioned. In the event that any of these contacts are closed, the relay coil will be de-energised, and power to the pulse inverter will be disconnected.

## Constraints
| No. | Constraints                                                                                   | Origin                               |
| --- | --------------------------------------------------------------------------------------------- | ------------------------------------ |
| 1   | Shall contain an emergency-stop button                                                        | NFPA 79                              |
| 2   | Shall shutoff if pressure and temperature approach ignition conditions of Brown's gas         | Design Constraint                    |
| 3   | System monitors must be designed with redundancies                                            | Design Constraint                    |
| 4   | System shall not produce gas unless there is a flame present                              | Design Constraint

<sup>1</sup>
NFPA 79 states that when an emergency stop button is pressed, all dangerous actions will stop without creating new hazards. The system must contain an accesable emergency stop button. When pressed, power to the pulse inverter will be cut off.

<sup>2</sup>
In order to avoid any sort of explosion or uncontrolled fire, pressure and temperature sensors will cut off power to the pulse generator if their values approach ignition conditions of Brown's gas.

<sup>3</sup>
Failure of the safety system can be minimized by creating redundancies in the system. Redundancies will be created by including 2 relay contacts for each componant in the safety system.

<sup>4</sup>
Halting gas production when there is no flame present wnsures that there is no gas lingering in the system. This eleminates any hazard when the machine is not being used.

## Buildable Schematic



## Analysis



## BOM
| Device                                                | Quantity | Price per Unit | Total Cost |
| ----------------------------------------------------- | -------- | -------------- | ---------- |
| UV flame detector                                     | 1        | ??             | ??         |
| Pressure sensor                                       | 1        | ??             | ??         |
| Temperature sensor                                    | 1        | ??             | ??         |
| Emergency stop                                        | 1        | ??             | ??         |
| Relay                                                 | ??       | ??             | ??         |
