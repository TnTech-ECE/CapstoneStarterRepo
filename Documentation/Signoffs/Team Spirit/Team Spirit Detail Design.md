## Functionality

The team spirit system is made to show a representation of Tennessee Tech. It consists of two lines of LEDs that blink purple and yellow that are activated by the main controller.

## Constraints

| Constraint | Description | Origin |
|---------------|-----------------|---------|
| 1. TTU Spirit | The system must display TTU’s colors of purple and gold | Competition Specifications |
| 2. Dynamic System | The LEDs must blink at an interval of 5 Hz | Competition Specifications |
| 3. Spacing | The LEDs must be spaced one inch apart | Design Specifications |
| 4. Placement | The LEDs must be on the left, right, and rear of the robot | Design Specifications |

## Buildable Schematic

The LEDs will be made into two strips, one of purple and one of gold, each consisting of 33 LEDs of their respective colors in parallel. Each LED has a built-in overcurrent protecting resistor, as shown in the figure below. These two lines of LEDs share a common ground rail, but each have their own power rail. The power comes from the main controller and will be a square wave with a frequency of 5 Hz and an amplitude of 5V with a DC offset of 2.5V. This ensures that the LEDs are turned on completely and off completely without sending a negative voltage through the circuit and damaging the LEDs. The purple side will start high, and the yellow side will start low. This is to ensure that they alternate and blink. 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/Team%20Spirit/Spirit%20System%20Circuit.png)

The LEDs are shown in the two images below.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/Team%20Spirit/LED%20spec%20sheet.jpg)

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/aConorOrr-signoff-Navigation/Documentation/Signoffs/Team%20Spirit/LEDs.jpg)

The LEDs will be placed on the left, right, and rear sides of the robot, with each LED spaced 1 inch from the next LED in the line, and lines are one inch apart. The yellow line is on top of the side, and the purple line is on the bottom, as shown in the figure below.

![Alt text]()

## Analysis

Constraint 1 Solution:

The system must display Tech pride by showing the colors purple and gold. The LEDs used are purple and gold LEDs. This sufficiently displays Tech pride.

Constraint 2 Solution: 

The LEDs must blink at a rate of 5Hz for them to be considered a dynamic system. The signal from the main controller will be a 5Hz square wave as defined in the previous section. This ensures that they blink at a rate of 5Hz. 5Hz was chosen because the human eye can only see differences up to 30 to 60 Hz. 5Hz ensures that the blinking is visible and easily discernable.

Constraint 3 Solution:

The LEDs must be spaced 1 inch apart. This is to ensure that the sides of the robot are covered in a costly manner. The LEDs are spaced 1 inch apart in the buildable schematic.

Constraint 4 Solution:

The LEDs must be on the left, right, and rear of the robot. The LEDs will be placed on those sides to be seen from any viewing angle the judges may have. This ensures that the team receives the extra points given for displaying team spirit.

## BOM

| Item | Description | Manufacturer | Part Number | Quantity | Price | Total |
|--------|-----------------|-------------------|-------------------|-------------|--------|--------|
| Purple LED | Purple LED | DORHEA | W04127_6-US-1 | 1 pkg | $7.99 | $7.99 |
| Yellow LED | Yellow LED | DORHEA | W04127_3-US-1 | 1 pkg | $7.99 | $7.99 |
