This document should be a pdf that details all experiments which were conducted. The purpose of the experiment, a description of the experiment, the expected result of the experiment, and the number of trials (must be enough to establish statistically significant results) must be given for each of the experiments.

The document should be in IEEE format.

The results of the experiments should be in the proper format. Data that is best suited to graphs must be in a graph. The same is true of tables. Results should not be given in paragraph format. 

# Experimental Analysis Report

## Introduction
The purpose of this report is to check all requirements for the project  and detail the experimental procedures used for each one to validate results. The results will be compared against the measures of success (shown in various signoffs and conceptual design) to determine what parts of the project’s implementation were successful. This will also detail what needs to be improved or changed moving forward.

### Requirements Table
| **ID** | **Specification or Constraint**                                                                                               | **Applicable subsytems** |
|--------|-------------------------------------------------------------------------------------------------------------------------------|--------------------------|
| 1      | Shall be able to send and receive at least 16-bit data reliably with the machine learning subsystem through wireless signals  |Bluetooth Communication   |
| 2      | Shall be able to send and receive at least 16-bit data from the main processor subsystem                                      | Bluetooth Communication  |
| 3      | Shall be able to send audio data and receive filter data (a full cycle) within a 4-second frame                               | Bluetooth Communication  |
| 4      | Bluetooth's range must reach anywhere in the room                                                                             | Bluetooth Communication  |
| 5      | Microphone shall react to input frequencies from 20 Hz to 20 kHz.                                                             | Input, Error             |
| 6      | Output signal should not be higher than 3.3 Vpp to prevent clipping.                                                          | Input, Error             |
| 7      | The subsystems' gain shall match each other.                                                                                  | Input, Error             |
| 8      | The subsystem delay shall be less than or equal to 0.2ms.                                                                     | Input, Error             |
| 9      | Shall process and output with a max delay of 1.4 ms                                                                           | Main Processor           |
| 10     | Shall connect to and communicate FIR filter coefficients with the Bluetooth connection subsystem                              | Main Processor           |
| 11     | Shall hold at least 2 seconds of samples per input signal                                                                     | Main Processor           |
| 12     | The speaker output shall not be more than 0.5 m from the window or wall being measured                                        | Mounting                 |
| 13     | System shall minimize its visual distraction                                                                                  | Mounting                 |
| 14     | Shall be easy to remove and setup in a different room                                                                         | Mounting                 |
| 15     | System shall have space within its confines to fit the input, error, output, processing, and power subsystems                 | Mounting                 |
| 16     | The audio amplifier and speaker shall be able to output at a minimum frequency range of 1KHz-17KHz                            | Output                   |
| 17     | The audio amplifier shall be able to deliver at least 10.0 W of continuous power at its output                                | Output                   |
| 18     | Speaker shall be capable of outputting at a sound pressure level of at least 90 dB and 90 dB SPL across the window            | Output                   |
| 19     | Speaker shall have an input power rating maximum that matches the amplifier's maximum power output                            | Output                   |
| 20     | Speaker shall be mounted to the wall, and will not impede movement or damage the classroom                                    | Output                   |
| 21     | System shall convert wall AC Voltage to DC voltage                                                                            | Power                    |
| 22     | Shall be capable of supplying a minimum of 29 W                                                                               | Power                    |
| 23     | System shall be able to operate on a maximum input ripple voltage of 400 mV                                                   | Power                    |
| 24     | Shall be able to step down the power supply voltage to 5,10, and 12 VDC to supply other subsystems                            | Power                    |
| 25     | Shall attenuate targeted noises by at least 20 dB                                                                             | Project goals            |




### Descoped Requirements Table

| **Specification or Constraint**                                                                      | **Applicable Subsytems** | **Reason for Descoping**                       |
|------------------------------------------------------------------------------------------------------|--------------------------|------------------------------------------------|
| System shall output a warning signal if sounds reaching over 80 dB are outputted for 8 hours or more | Main Processor, Output   | Lack of time to implement                      |
| System shall adapt for small and significant changes in the acoustic response of the room            | Main Processor, Output   | Lack of time to implement                      |
| Device shall not reach 60°C (140°F)                                                                  | All subsystems           | Not necessary for functionality                |
| Shall have an accessible Power toggle                                                                | All subsystems           | Lack of time to implement                      |
| System shall follow the American National Standards Institute (ANSI) for safe use of lasers          | Input                    | Decided to remove lasers from the project idea |
| Shall encrypt any data sent wirelessly                                                               | Bluetooth Communication  | Lack of time to implement                      |
