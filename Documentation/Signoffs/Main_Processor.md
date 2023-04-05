# Processing Subsystem




Making tables for constraints and BOM will use Excel to Markdown here:
https://tabletomarkdown.com/convert-spreadsheet-to-markdown/

Example Signoff that was shown in class can be found here:
https://github.com/Hawk652/Capstone-Guidance-Robot/blob/main/Documentation/Signoffs/Power%20Subsystem.md

# Required sections


Each signoff markdown file must contain the following sections and information:

## Function of the Subsystem

<img width="728" alt="Screen Shot 2023-04-04 at 3 25 34 PM" src="https://user-images.githubusercontent.com/123997954/229912228-53e792c0-7cce-496a-ace8-6fa46197ea0d.png">

You must explain clearly what role the subsystem will play in the first section. This should clearly explain what the system is expected to do (ie. its atomic purpose from the conceptual design).

## Constraints

The second section should contain the constraints for the subsystem. The reasoning behind the constraints must be given. As a few examples, constraints may exist due to physics based limitations or requirements, other subsystem requirements, standards, ethics, or socioeconomic reasons. 

Each subsystem must have at least one constraint arising from standards, ethics, or socioeconomic well being.
| No. | Specifications and Constraints                     | Origin          |
| --- | -------------------------------------------------- | --------------- |
| 1   | Shall be powered from wall outlet                  | Specification   |
| 2   | Shall process and output information within 1.4 ms | Specification   |
| 3   | Shall process sounds at a rate of at least 40 kHz  | Specification   |
| 4   | Shall keep track of outputs reaching 80+ dB        | Greater Impacts |
| 5   | Shall minimize storage of classroom noise          | Ethics          |
| 6   | Shall have a safe power toggle                     | IEC 60950-1     |
| 7   | Shall not reach 60°C (140°F)                       | Safety          |

## Buildable schematic 

![image](https://github.com/CarsonDPope/Active-Noise-Control-With-Wall-Transmission-Detection/blob/jmvega52-patch-1/Documentation/Images/DSPBOARD.png)

The third section should show the buildable schematic directly embedded in the markdown file as a jpeg image. If the schematic is not clearly readable and appropriately sized, the supervisor will reject the signoff. 

The schematic must be appropriate to the design. ie. 3d model for a physical system or wiring schematic for a circuit. Further, the schematic(s) must contain every detail necessary for the design to be built by someone who has no knowledge of the design. Every relevant component value and measurement must be given.

The actual design artifacts (3d model, Cad files, gerber files, etc) must be uploaded to the documentation folder in the appropriate location.

## Analysis

#### Psuedo Code Flow Chart
![image](https://user-images.githubusercontent.com/123997954/229912784-1174c224-1c0f-4fb9-8a78-3f503ecb81d3.png)


### Input Processing

The Processing subsystem is going to receive digital values from the input and error subsystems. Processing of these values will be done through various adaptive agorithms and control filters.

### Input/Output Delay Line
The Input Delay line wil receive the converted digital signals from the input subsytem. These values will be temporarily stored in an array so that the there is enough data to properly convolute the signals. The size of the array is going to depend on the length of the filter in the input subsystem.

The erroy delay line is going to have similar functionality to the input delay line but it will be receiving data from the acoustic residual noise of the room after output, rather than values from the input subsystem. 

### 180 Degree Phase Shift

Phase Shift

 

## BOM

A complete list of all components needed for the design must be given with the cost of each component and the total cost of the subsystem. The BOM should be a markdown table.a
