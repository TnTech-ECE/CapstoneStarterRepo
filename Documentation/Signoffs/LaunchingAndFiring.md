## Functionality
The Launching and Firing subsystem is the system that will fire the intercepting round when given a signal from the aiming subsystem. This system will also preload the launching apparatus so that each round may fire with minimum delay. This subsystem will use a 12-volt DC brushed motor along with a relay that will use a signal from the aiming subsystem as an input to allow the DC motor to operate. 

## Specifications and Restraints
| Number | Constraint | Constraint description | Origin |
|------|--------------------|------------------------|------------|
| 1. | NEC 310.15(B) | The  Launching and Firing subsystem shall use appropriate wiring for all connections within the subsystem as according to the ampacity limits listed in the NEC 310.15(B) table | NEC 310.15(B) |
| 2. | Fire without human interaction | The Launching and Firing subsystem shall fire without any human interaction with the field of play or the launching apparatus itself | DEVCOM competition rulebook |
| 3. | Fit within a cubic foot of space | The Launching and Firing subsystem is required to fit within a cubic foot of space (1 ft by 1 ft by 1 ft) along with the other subsystems that will be placed within that space | DEVCOM competition rulebook |
| 4. | Safe operating | The Launching and Firing subsystem shall comply with the DEVCOM safety constaints given in the DEVCOM rulebook | DEVCOM competition rulebook |
| 5. |  Signal-to-Fire delay | The Launching and Firing subsystem shall fire a round within XX ms after receiving the signal from the aiming subsystem. This is the amount of time left after accounting for all other subsystems to complete their processes during the worst case scenario. | Team Specification |
| 6. | Preloading after firing | The Launching and Firing subsystem will reset the preload condition after each round is fired. | Team Specification | 
| 7. | Motor Shaft Type | The Launching and Firing subsyetm shall use a motor that has an X type output shaft. | Mechanical Engineering Team Specification |
| 8. | Motor Torque | The Launching and Firing Mechanism shall operate firing mechanism on the launcher apparatus | Mechanical Engineering Team Specification |

## Buildable Schematic

Wiring Chart to come

## Analysis 

**Constraint Solution 1:**
Need Torque spec for 1, 5, 6, 7, 8, 9

**Constraint Solution 2:**
To allow the firing mechanism to operate without human interaction, a signal shall be generated from the Aiming subsystem when that subsystem has finished the aiming processes that will be used as a relay signal to operate the firing mechanism autonomously. The relay will disconnect the 12-volt supply from the DC motor when the signal is not active, or low, and will connect the 12-volt supply to the DC motor when the signal is activated, or high, allowing the motor to operate. 

**Constraint Solution 3:**
The Launching and Firing subsystem is required to fit within a cubic foot of space (1 ft by 1 ft by 1 ft) along with the other subsystems that will be placed within that space. For this constraint, the mechanical engineering team and the electrical engineering team will be working together to ensure that the total design remains within the cubic foot of space allowed. For the Launching and Firing subsystem, the mechanical engineering team constrained the DC motor choice to have no more than 3 inches in length to fit within their current design.

**Constraint Solution 4:**
Safety


## BOM
| Item | Description | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-------------|--------------|----------|-------|-------------|
| Motor | TBD  | N/A | TBD | 1 | $ | $ |
| Wiring needed? | Wires | N/A | 	TBD | 1 | $ | $ |
| Relay | For signal | TBD | TBD | 1 | $ | $ |
|      |                                             |     |             |   |       | $ Total |

