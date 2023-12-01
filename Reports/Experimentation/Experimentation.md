This document should be a pdf that details all experiments which were conducted. The purpose of the experiment, a description of the experiment, the expected result of the experiment, and the number of trials (must be enough to establish statistically significant results) must be given for each of the experiments.

The results of the experiments should be in the proper format. Data that is best suited to graphs must be in a graph. The same is true of tables. Results should not be given in paragraph format. 

# Experimental Analysis Report

## Introduction
The purpose of this report is to check all requirements for the project  and detail the experimental procedures used for each one to validate results. The results will be compared against the measures of success (shown in various signoffs and conceptual designs) to determine what parts of the project’s implementation were successful. This will also detail what needs to be improved or changed moving forward.

### Requirements Table
| **ID** | **Specification or Constraint**                                                                                               | **Applicable subsystems** |
|--------|-------------------------------------------------------------------------------------------------------------------------------|--------------------------|
| 1      | Shall be able to send and receive at least 16-bit data reliably with the machine learning subsystem through wireless signals  | Bluetooth Communication  |
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
| 13     | Shall be easy to remove and set in a different room                                                                           | Mounting                 |
| 14     | System shall have space within its confines to fit the input, error, output, processing, and power subsystems                 | Mounting                 |
| 15     | The audio amplifier and speaker shall be able to output at a minimum frequency range of 1 kHz - 17 kHz                        | Output                   |
| 16     | The audio amplifier shall be able to deliver at least 10.0 W of continuous power at its output                                | Output                   |
| 17     | Speaker shall be capable of outputting at a sound pressure level of at least 90 dB and 90 dB SPL across the window            | Output                   |
| 18     | Speaker shall have an input power rating maximum that matches the amplifier's maximum power output                            | Output                   |
| 19     | Speaker shall be mounted to the wall, and will not impede movement or damage the classroom                                    | Output                   |
| 20     | System shall convert wall AC Voltage to DC voltage                                                                            | Power                    |
| 21     | Shall be capable of supplying a minimum of 29 W                                                                               | Power                    |
| 22     | System shall be able to operate on a maximum input ripple voltage of 400 mV                                                   | Power                    |
| 23     | Shall be able to step down the power supply voltage to 5,10, and 12 VDC to supply other subsystems                            | Power                    |
| 24     | Shall attenuate targeted noises by at least 20 dB                                                                              | Project goals            |




### Descoped Requirements Table

| **Specification or Constraint**                                                                      | **Applicable Subsytems** | **Reason for Descoping**                       |
|------------------------------------------------------------------------------------------------------|--------------------------|------------------------------------------------|
| System shall output a warning signal if sounds reaching over 80 dB are outputted for 8 hours or more | Main Processor, Output   | Lack of time to implement                      |
| System shall adapt for small and significant changes in the acoustic response of the room            | Main Processor, Output   | Lack of time to implement                      |
| Device shall not reach 60°C (140°F)                                                                  | All subsystems           | Not necessary for functionality                |
| Shall have an accessible Power toggle                                                                | All subsystems           | Lack of time to implement                      |
| System shall follow the American National Standards Institute (ANSI) for safe use of lasers          | Input                    | Decided to remove lasers from the project idea |
| Shall encrypt any data sent wirelessly                                                               | Bluetooth Communication  | Lack of time to implement                      |


## Experimental Results

### Constraint 1 - Send and receive 16-bit data with machine learning

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh

### Constraint 2 - Send and receive 16-bit data with main processor 

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh

### Constraint 3 - Send audio data and receive filter data within 4 seconds 

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh

### Constraint 4 - Bluetooth must reach anywhere in the room

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 5 - Microphone shall react to inputs from 20 Hz to 20 kHz

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 6 - Input and error subsystem's output shall be no higher than 3.3 Vpp

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 7 - Input and error subsystems' gain shall match each other

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 8 - Input and error delay shall be within 0.2 ms
Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 9 - Main processor shall process and output within 1.4 ms

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 10 - Communicate FIR filter coefficients with Bluetooth connection subsystem

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 11 - Main processor shall hold at least 2 seconds of samples per input signal

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 12 - Speaker shall be within 0.5 m from the window being measured

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 13 - Shall be easy to remove and setup in a different room

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 14 - Mounting shall have a space for input, error, output, processing, and power subsystems

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 15 - The audio amplifier and speaker shall support a minimum frequency range of 1 kHz - 17 kHz

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 16 - Audio amplifier shall deliver at least 10 W of continuous power at its output

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 17 - Speaker shall capable of outputting 90 dB and 90 dB SPL across the window

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 18 - Speakers shall have an input power rating maximum that matches the amplifier's maximum power output

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 19 - Speakers shall be mounted to the wall without impeding movement or damaging the classroom

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 20 - Power shall convert wall outlet AC to DC

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 21 - Power shall supply a minimum of 29 W

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 22 - Power shall operate on a maximum input ripple voltage of 400 mV 

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 23 - Shall step down power supply to 5, 10, and 12 VDC

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 24 - Attenuate targeted noises by at least 20 dB

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh

## Improvements and Future Work


## Conclusion


| **ID** | **Constraint description**                                                                          | **Constraint Met?** |
|--------|-----------------------------------------------------------------------------------------------------|---------------------|
| 1      | Send and receive 16-bit data with machine learning                                                  |                     |
| 2      | Send and receive 16-bit data with main processor                                                    |                     |
| 3      | Send audio data and receive filter data within 4 seconds                                            |                     |
| 4      | Bluetooth must reach anywhere in the room                                                           |                     |
| 5      | Microphone shall react to inputs from 20 Hz to 20 kHz                                               |                     |
| 6      | Input and error subsystem's output shall be no higher than 3.3 Vpp                                  |                     |
| 7      | Input and error subsystems' gain shall match each other                                             |                     |
| 8      | Input and error delay shall be within 0.2 ms                                                        |                     |
| 9      | Main processor shall process and output within 1.4 ms                                               |                     |
| 10     | Communicate FIR filter coefficients with Bluetooth connection subsystem                             |                     |
| 11     | Main processor shall hold at least 2 seconds of samples per input signal                            |                     |
| 12     | Speaker shall be within 0.5 m from the window being measured                                        |                     |
| 13     | Shall be easy to remove and setup in a different room                                               |                     |
| 14     | Mounting shall have a space for input, error, output, processing, and power subsystems              |                     |
| 15     | The audio amplifier and speaker shall support a minimum frequency range of 1 kHz - 17 kHz           |                     |
| 16     | Audio amplifier shall deliver at least 10 W of continuous power at its output                       |                     |
| 17     | Speaker shall capable of outputting 90 dB and 90 dB SPL across the window                           |                     |
| 18     | Speakers shall have an input power rating maximum that matches the amplifier's maximum power output |                     |
| 19     | Speakers shall be mounted to the wall without impeding movement or damaging the classroom           |                     |
| 20     | Power shall convert wall outlet AC to DC                                                            |                     |
| 21     | Power shall supply a minimum of 29 W                                                                |                     |
| 22     | Power shall operate on a maximum input ripple voltage of 400 mV                                     |                     |
| 23     | Shall step down power supply to 5, 10, and 12 VDC                                                   |                     |
| 24     | Attenuate targeted noises by at least 20 dB                                                         |


