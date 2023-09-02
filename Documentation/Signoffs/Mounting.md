
# Required sections

Each signoff markdown file must contain the following sections and information:

## Function of the Subsystem

The mounting subsystem is the design for how all of the other subsystems will be mounted to fulfill the constraints outlined in the conceptual design.

## Constraints
| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1  |  The overall system delay must be less than or equal to 1.4 ms  | System Requirements |
| 2  |  System shall not impede movement and easy access throughout the room  | System Requirements |
| 3  |  The speaker output shall not be more than 0.5 m from window or wall being measured | System Requirements |
| 4  |  System shall have a mount or multiple mounts so that it can be installed in the classroom in an unfrequented area.| System Requirements |
| 5  |  Shall be easy to remove and setup in a different room | System Requirements |
| 6  |  System shall minimize its visual distraction | System Requirements |
| 7  |  System shall follow OSHA standard 1910.95 for occupational noise exposure.| OSHA standards |
| 8  |  System shall follow OSHA standard 1910.304-305 for wiring design and protection | OSHA standards |






## Buildable schematic 

The third section should show the buildable schematic directly embedded in the markdown file as a jpeg image. If the schematic is not clearly readable and appropriately sized, the supervisor will reject the signoff. 

The schematic must be appropriate to the design. ie. 3d model for a physical system or wiring schematic for a circuit. Further, the schematic(s) must contain every detail necessary for the design to be built by someone who has no knowledge of the design. Every relevant component value and measurement must be given.

The actual design artifacts (3d model, Cad files, gerber files, etc) must be uploaded to the documentation folder in the appropriate location.

## Analysis

A complete and relevant analysis of the design showing that it **should** meet the constraints and perform the desired function must be given. This analysis must be comprehensive and well explained so that it is convincing to the faculty supervisor. If the signoff request is not convincing either because the requirements and constraints are insufficient, unjustified, or not appropriately shown to be met by the design, then approval will not be given. Without approval, the components for the subsystem aren't allowed to be ordered. 

## BOM

A complete list of all components needed for the design must be given with the cost of each component and the total cost of the subsystem. The BOM should be a markdown table.
