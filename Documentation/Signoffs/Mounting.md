
# Required sections

Each signoff markdown file must contain the following sections and information:

## Function of the Subsystem

The mounting subsystem is the design for how all of the other subsystems will be mounted to fulfill the constraints outlined in the conceptual design.

## Constraints
| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1  |  The overall system delay must be less than or equal to 1.4 ms  | System Requirements |
| 2  |  System shall not impede movement and easy access throughout the room  | American Disabilities Act |
| 3  |  The speaker output shall not be more than 0.5 m from window or wall being measured | System Requirements |
| 4  |  System shall have a mount or multiple mounts so that it can be installed in the classroom in an unfrequented area.| System Requirements |
| 5  |  System shall be easy to remove and setup in a different room | Broader Impacts |
| 6  |  System shall minimize its visual distraction | Stakeholder survey |
| 7  |  System shall follow OSHA standard 1910.95 for occupational noise exposure.| OSHA standards |
| 8  |  System shall follow OSHA standard 1910.304-305 for wiring design and protection | OSHA standards |
| 9  |  System shall follow the IEEE 518-1982 Guide for the Installation of Electrical Equipment to Minimize Electrical Noise Inputs to Controllers from External Sources. | IEEE standards |
| 10  |  Overall weight of mounting subsystem cannot exceed 17 lbs.| Weight requirement |
| 11  |  The width of the physical mount cannot exceed 49 in.| Window width measurements |




#### 1.)	The overall system delay must be less than or equal to 1.4 ms . [Origin: System Requirements]
The delay of the system must be less than the delay of the sound in order for the noise cancellation to be effective. This constraint is dependent on distance, if the velocity of sound in air is used (343 m/s), then the maximum distance from the input microphone to the error microphone is given by the following equation: d = v*t where d is the maximum distance, v is the velocity of sound and t is the maximum delay (1.4 ms), this equates to a distance of 0.4802 m or 1.575 ft, therefore the total length of the system can be no greater than 1.575 ft for correct operation.

#### 2.) System shall not impede movement and easy access throughout the room. [Origin: Americans Disabilities Act]
This constraint is needed to ensure safety and minimize difficulty navigating the classroom during the operation of the system. This constraint also will follow the American Disabilities Act allowing for individuals with limited mobility to easily navigate the room.


#### 3.) The speaker output shall not be more than 0.5 m from window or wall being measured. [Origin: System Requirements]
This is in order to make sure the system is small and compact and does impede movement throughout the classroom.

#### 4.) System shall have a mount or multiple mounts so that it can be installed in the classroom in an unfrequented area. [Origin: System Requirements]
This will allow the system to perform its functionality without causing difficulty for students or faculty performing
their required tasks.

#### 5.) System shall be easy to remove and setup in a different room. [Origin: Broader Impacts]
Other classrooms will experience noise and the ease in which the system can be moved is a large factor for how quickly noise in other rooms can be effectively canceled.

#### 6.)  System shall minimize its visual distraction [Origin: Stakeholder Survey]
Classrooms should be distraction free to allow students to learn new information effectively, therefore the system will not be distracting to students or faculty.

#### 7.) System shall follow OSHA standard 1910.95 for occupational noise exposure. [Origin: OSHA standards]
The mounting subsystem should be designed to ensure that the weighted average noise does not exceed 85 dB from the overall system to guarantee no hearing loss will occur.

#### 8.) System shall follow OSHA standard 1910.304-305 for wiring design and protection. [Origin: OSHA standards]
The mounting subsystem should be designed such that wires are easily identified and discerned from other conductors, for example the ground wire must be easily found when comparing it to live conductors. The wires must also be insulated and be in a proper location to minimize the probability of electrical shock occuring.

#### 9.) System shall follow the IEEE 518-1982 Guide for the Installation of Electrical Equipment to Minimize Electrical Noise Inputs to Controllers from External Sources. [Origin: IEEE standards]
The mounting subsystem needs to follow this guide to limit outside noise which could lower the effectiveness of the noise cancellation capability of the overall system.

#### 10.) Overall weight of mounting subsystem cannot exceed 17 lbs. [Origin: Weight requirement ]
The mounting subsystem cannot be physically drilled into the wall since this would damage Tennessee Tech property, therefore command strips will be utilized, these command strips are rated for 20 lbs. The system will add weight, therefore to compensate for the additional weight, the weight requirement will be lessened to a maximum amount of 17 lbs for the physical mount to prevent failure.
#### 11.) The width of the physical mount cannot exceed 49 in. [Origin: Window width measurements ]







## Buildable schematic 

The third section should show the buildable schematic directly embedded in the markdown file as a jpeg image. If the schematic is not clearly readable and appropriately sized, the supervisor will reject the signoff. 

The schematic must be appropriate to the design. ie. 3d model for a physical system or wiring schematic for a circuit. Further, the schematic(s) must contain every detail necessary for the design to be built by someone who has no knowledge of the design. Every relevant component value and measurement must be given.

The actual design artifacts (3d model, Cad files, gerber files, etc) must be uploaded to the documentation folder in the appropriate location.

## Analysis

A complete and relevant analysis of the design showing that it **should** meet the constraints and perform the desired function must be given. This analysis must be comprehensive and well explained so that it is convincing to the faculty supervisor. If the signoff request is not convincing either because the requirements and constraints are insufficient, unjustified, or not appropriately shown to be met by the design, then approval will not be given. Without approval, the components for the subsystem aren't allowed to be ordered. 

## BOM

A complete list of all components needed for the design must be given with the cost of each component and the total cost of the subsystem. The BOM should be a markdown table.
