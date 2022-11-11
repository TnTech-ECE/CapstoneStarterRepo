## How to submit a signoff or update a signoff:

### Submitting Signoff
1. Create the signoff markdown file 
2. At the bottom of the page select "create a new branch for this commit and start a pull request"
3. Submit the changes 
4. Name the pull request branch "name-signoff-subsystem name"
5. The comment should be "requesting signoff for name of subsystem"
6. Submit the pull request
7. Wait for faculty supervisor feedback on the pull request

### Updating Signoff

1. Edit the signoff markdown file 
2. Add a description of how you have addressed the feedback from the faculty supervisor
3. At the bottom of the page select "commit directly to"
4. Submit the changes 

# Required sections

Each signoff markdown file must contain the following sections and information:

## Function of the Subsystem

You must explain clearly what role the subsystem will play in the first section. This should clearly explain what the system is expected to do (ie. its atomic purpose from the conceptual design).

## Constraints

The second section should contain the constraints for the subsystem. The reasoning behind the constraints must be given. As a few examples, constraints may exist due to physics based limitations or requirements, other subsystem requirements, standards, ethics, or socioeconomic reasons. 

Each subsystem must have at least one constraint arising from standards, ethics, or socioeconomic well being.

## Buildable schematic 

The third section should show the buildable schematic directly embedded in the markdown file as a jpeg image. If the schematic is not clearly readable and appropriately sized, the supervisor will reject the signoff. 

The schematic must be appropriate to the design. ie. 3d model for a physical system or wiring schematic for a circuit. Further, the schematic(s) must contain every detail necessary for the design to be built by someone who has no knowledge of the design. Every relevant component value and measurement must be given.

The actual design artifacts (3d model, Cad files, gerber files, etc) must be uploaded to the documentation folder in the appropriate location.

## Analysis

A complete and relevant analysis of the design showing that it **should** meet the constraints and perform the desired function must be given. This analysis must be comprehensive and well explained so that it is convincing to the faculty supervisor. If the signoff request is not convincing either because the requirements and constraints are insufficient, unjustified, or not appropriately shown to be met by the design, then approval will not be given. Without approval, the components for the subsystem aren't allowed to be ordered. 

## BOM

A complete list of all components needed for the design must be given with the cost of each component and the total cost of the subsystem. The BOM should be a markdown table.

