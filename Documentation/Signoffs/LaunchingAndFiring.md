## Functionality
The Launching and Firing subsystem is the system that will fire the intercepting round when given a signal from the aiming subsystem. This system will also continue to power the DC motor used to operate the firing mechanism and preload the launching apparatus so that each round may fire with minimum delay. This subsystem will use a 12-volt DC brushed motor along with a relay that will use a signal from the aiming subsystem as an input to allow the DC motor to operate. 

## Specifications and Restraints
| Number | Constraint | Constraint description | Origin |
|------|--------------------|------------------------|------------|
| 1. | NEC 310.15(B) | The Launching and Firing subsystem shall use appropriate wiring for all connections within the subsystem as according to the ampacity limits listed in the NEC 310.15(B) table | NEC 310.15(B) |
| 2. | Fire without human interaction | The Launching and Firing subsystem shall fire without any human interaction with the field of play or the launching apparatus itself | DEVCOM competition rulebook |
| 3. | Fit within a cubic foot of space | The Launching and Firing subsystem is required to fit within a cubic foot of space (1 ft by 1 ft by 1 ft) along with the other subsystems that will be placed within that space | DEVCOM competition rulebook |
| 4. | Safe operating | The Launching and Firing subsystem shall comply with the DEVCOM safety constaints given in the DEVCOM rulebook | DEVCOM competition rulebook |
| 5. | Motor Shaft Type | The Launching and Firing subsyetm shall use a motor that has an X type output shaft. | Mechanical Engineering Team Specification |
| 6. | Motor Torque | The Launching and Firing Mechanism shall operate firing mechanism on the launcher apparatus | Mechanical Engineering Team Specification |
| 7. |  Signal-to-Fire delay | The Launching and Firing subsystem shall fire a round within XX ms after receiving the signal from the aiming subsystem. This is the amount of time left after accounting for all other subsystems to complete their processes during the worst case scenario. | Team Specification |
| 8. | Preloading after firing | The Launching and Firing subsystem will reset the preload condition after each round is fired. | Team Specification | 


## Buildable Schematic

Wiring Chart to come

## Analysis 

**Constraint Solution 1:**
The Launching and Firing subsystem shall use xx AWG wire for the subsystems electrical connections. This wire has an ampacity rating of xx amps over a distance of xx inches. This wire size was selected by considering the largest ampacity draw that exists in the subsystem. For this the team decided to use the stall current of the xxxx DC motor used in this subsystem to apply mechanical power to the firing mechanism.

**Constraint Solution 2:**
To allow the firing mechanism to operate without human interaction, a signal shall be generated from the Aiming subsystem when that subsystem has finished the aiming processes that will be used as a relay signal to operate the firing mechanism autonomously. The relay will disconnect the 12-volt supply from the DC motor when the signal is not active, or low, and will connect the 12-volt supply to the DC motor when the signal is activated, or high, allowing the motor to operate. 

**Constraint Solution 3:**
The Launching and Firing subsystem is required to fit within a cubic foot of space (1 ft by 1 ft by 1 ft) along with the other subsystems that will be placed within that space. For this constraint, the mechanical engineering team and the electrical engineering team will be working together to ensure that the total design remains within the cubic foot of space allowed. For the Launching and Firing subsystem, the mechanical engineering team constrained the DC motor choice to have no more than 3 inches in length to fit within their current design.

**Constraint Solution 4:**
Safety

**Constraint Solution 5:**
The Launching and Firing subsystem shall use the xxxx DC motor which has an xxxx shaft which will make it an appropriate choice for the mechanical engineering team's current designs. 

**Constraint Solution 6:**
The Launching and Firing subsystem shall use the xxxx DC motor which exhibits the ability to operate the mechanism at a torque of xxxx N-m at xx RPM. XXX N-m is the highest torque required to operate the Fire-Preload sequence of the Launching and Firing subsystem.

**Constraint Solution 7:**
The mechanical engineering team's current plan is to fire a round after a 20 degree rotation of the Launching and Firing DC motor. The rest of the rotation would be used to set the firing mechanism into a preload state, awaiting another signal from the aiming subsystem to fire the next round with a 20 degree turn and the following 340 degrees used to preload the mechanism and so on. The electrical engineering team decided to use a safety designing factor of 2.0 and ensure the motor would have the ability to rotate 40 degrees to release the shot within the time allowed for the response of shooting a round after receiving the signal from the aiming subsystem. Over the cycle of a full rotation, thw torque will vary from no-load to a load of xxx N-m from the mechanical engineering team's calculations. However, the first part of the rotation (which will fire the round) will have the highest torque. The xxxx motor has a torque of xxxx N-m at xxxx RPM, which is equivalent to xxx rotations per second.
This motor will be able to complete 40 degrees of the rotation and release a single round after xxx ms at the given torque of xxx N-m which is within it's worst-case scenario time limit. 

**Constraint Solution 8:**
The mechanical engineering team's current plan is to fire a round after a 20 degree rotation of the Launching and Firing DC motor. The rest of the rotation would be used to set the firing mechanism into a preload state, awaiting another signal from the aiming subsystem to fire the next round with a 20 degree turn and the following 340 degrees used to preload the mechanism and so on. Over the cycle of a full rotation, thw torque will vary from no-load to a load of xxx N-m from the mechanical engineering team's calculations. However, the preload portion of the rotation will require a torque ranging from 0 N-m (no-load) to xxx N-m. The xxxx motor has a torque of xxxx N-m at xxxx RPM, which is equivalent to xxx rotations per second. This motor will be able to complete 340 degrees of the rotation and preload a single round after xxx ms at the given torque of xxx N-m which is faster than the time required for the rest of the subsystems to detect and aim at the next incoming projectile meaning that this work can be done concurrently to the rest of the system's processes without causing a time constraint on the system as a whole. 


## BOM
| Item | Description | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-------------|--------------|----------|-------|-------------|
| Motor | TBD  | N/A | TBD | 1 | $ | $ |
| Wiring needed? | Wires | N/A | 	TBD | 1 | $ | $ |
| Relay | For signal | TBD | TBD | 1 | $ | $ |
|      |                                             |     |             |   |       | $ Total |

