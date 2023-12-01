This document should be a pdf that details all experiments which were conducted. The purpose of the experiment, a description of the experiment, the expected result of the experiment, and the number of trials (must be enough to establish statistically significant results) must be given for each of the experiments.

The document should be in IEEE format.

The results of the experiments should be in the proper format. Data that is best suited to graphs must be in a graph. The same is true of tables. Results should not be given in paragraph format. 

# Experimental Analysis Report

## Introduction
The purpose of this report is to check all requirements for the project  and detail the experimental procedures used for each one to validate results. The results will be compared against the measures of success (shown in various signoffs and conceptual design) to determine what parts of the project’s implementation were successful. This will also detail what needs to be improved or changed moving forward.

### Requirements Table
| **ID** | **Specification or Constraint**                                                                                                  | **Applicable subsystems**    | **Reason for rescoping**                                                     |
|----|-------------------------------------------------------------------------------------------------------------------------------|-------------------------|--------------------------------------------------------------------------|
| 1  | Shall be able to send and receive at least 16-bit data reliably with the machine learning subsystem through wireless signals | Bluetooth Communication                       |                                                   |   |
| 2  | Shall be able to send and receive at least 16-bit data from the main processor subsystem                                      | Bluetooth Communication |                                                                          |
| 3  | Shall be able to send audio data and receive filter data (a full cycle) within a 4-second frame                               | Bluetooth Communication |                                                                          |
| 4  | Bluetooth's range must reach anywhere in the room                                                                             | Bluetooth Communication |                                                                          |
| 5  | Shall not store audio data after processing                                                                                   | Bluetooth Communication |                                                                          |
| 6  | Must not add any physical obstructions through the walking area of the room                                                   | Bluetooth Communication |                                                                          |
| 7  | Microphones shall be placed within the noise control area.                                                                    | Input, Error             |                                                                          |
| 8  | Microphone shall react to input frequencies from 20 Hz to 20 kHz.                                                             | Input, Error             |                                                                          |
| 9  | Output signal should not be higher than 3.3 Vpp to prevent clipping.                                                          | Input, Error             |                                                                          |
| 10 | The primary input sensor shall output a continuous-time analog voltage signal.                                                | Input, Error             | The Main Processor now has the role of converting from analog to digital |
| 11 | The subsystems' gain shall match each other.                                                                                  | Input, Error             |                                                                          |
| 12 | The subsystem delay shall be less than or equal to 0.2ms.                                                                     | Input, Error             |                                                                          |
| 13 | The microphone shall have a maximum SPL rating of 110 dB or higher                                                            | Input, Error             |                                                                          |
| 14 | Input microphone shall measure acoustic vibrations through the medium.                                                        | Input, Error             |                                                                          |
| 15 | Shall process and output with a max delay of 1.4 ms                                                                           | Main Processor          |                                                                          |
| 16 | Shall have a sample rate of at least 40 kHz                                                                                   | Main Processor          |                                                                          |
| 17 | Shall have at least 16-bit ADC and DAC                                                                                        | Main Processor          | 16-bits was calculated to be a satisfactory number for minimal loss      |
| 18 | Shall have a minimum of 2 input signal sources                                                                                | Main Processor          |                                                                          |
| 19 | Shall have a minimum of 1 output signal source                                                                                | Main Processor          |                                                                          |
| 20 | Shall connect to and communicate FIR filter coefficients with the bluetooth connection subsystem                              | Main Processor          |                                                                          |
| 21 | Shall hold at least 2 seconds of samples per input signal                                                                     | Main Processor          |                                                                          |
| 22 | Shall not store audio data after processing                                                                                   | Main Processor          |                                                                          |
| 23 | System shall not impede movement and easy access throughout the room                                                          | Mounting                |                                                                          |
| 24 | The speaker output shall not be more than 0.5 m from the window or wall being measured                                        | Mounting                |                                                                          |
| 25 | System shall be mounted in the classroom in an unfrequented area.                                                             | Mounting                |                                                                          |
| 26 | System shall minimize its visual distraction                                                                                  | Mounting                |                                                                          |
| 27 | Shall be easy to remove and setup in a different room                                                                         | Mounting                |                                                                          |
| 28 | System shall have space within its confines to fit the input, error, output, processing, and power subsystems                 | Mounting                |                                                                          |
| 29 | The audio amplifier and speaker shall be able to output at a minimum frequency range of 1KHz-17KHz                            | Output                  |                                                                          |
| 30 | The audio amplifier shall be able to deliver at least 10.0 W of continuous power at its output                                | Output                  |                                                                          |
| 31 | The speaker shall have a minimum input impedance 4Ω                                                                           | Output                  |                                                                          |
| 32 | System shall have a primary output speaker that generates acoustic sounds based on its analog input from the system           | Output                  |                                                                          |
| 33 | Speaker shall be capable of outputting at a sound pressure level of at least 90 dB and 90 dB SPL across the window            | Output                  |                                                                          |
| 34 | Speaker shall have an input power rating maximum that matches the amplifier's maximum power output                            | Output                  |                                                                          |
| 35 | Speaker shall be mounted to the wall, and will not impede movement or damage the classroom                                    | Output                  |                                                                          |
| 36 | System shall convert wall AC Voltage to DC voltage                                                                            | Power                   |                                                                          |
| 37 | Shall be capable of supplying a minimum of 29 W                                                                               | Power                   |                                                                          |
| 38 | System shall be able to operate on a maximum input ripple voltage of 400 mV                                                   | Power                   |                                                                          |
| 39 | Shall be able to step down power supply voltage to 5,10, and 12 VDC to supply other subsystems                                | Power                   |                                                                          |
| 40 | Shall attenuate tageted noises by at least 20 dB                                                                              | Project goals           |



### Descoped Requirements Table

| **Specification or Constraint**                                                                      | **Applicable Subsytems** | **Reason for Descoping**                       |
|------------------------------------------------------------------------------------------------------|--------------------------|------------------------------------------------|
| System shall output a warning signal if sounds reaching over 80 dB are outputted for 8 hours or more | Main Processor, Output   | Lack of time to implement                      |
| System shall adapt for small and significant changes in the acoustic response of the room            | Main Processor, Output   | Lack of time to implement                      |
| Device shall not reach 60°C (140°F)                                                                  | All subsystems           | Not necessary for functionality                |
| Shall have an accessible Power toggle                                                                | All subsystems           | Lack of time to implement                      |
| System shall follow the American National Standards Institute (ANSI) for safe use of lasers          | Input                    | Decided to remove lasers from the project idea |
| Shall encrypt any data sent wirelessly                                                               | Bluetooth Communication  | Lack of time to implement                      |
