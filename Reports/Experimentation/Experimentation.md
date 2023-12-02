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


## Results

### Constraint 1 - Send and receive 16-bit data with machine learning

This constraint is not traditionally experimental, but was met.

### Constraint 2 - Send and receive 16-bit data with main processor 

This constraint is not traditionally experimental, but was not met.

### Constraint 3 - Send audio data and receive filter data within 4 seconds 

Since constraint 2 was not met, this was not able to be tested.

### Constraint 4 - Bluetooth must reach anywhere in the room

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 5 - Microphone shall react to inputs from 20 Hz to 20 kHz

This constraint was not tested due to lack of time.

### Constraint 6 - Input and error subsystem's output shall be no higher than 3.3 Vpp

This constraint was not tested due to lack of time.

### Constraint 7 - Input and error subsystems' gain shall match each other

This constraint was not tested due to lack of time.

### Constraint 8 - Input and error delay shall be within 0.2 ms

This constraint was not tested due to lack of time.

### Constraint 9 - Main processor shall process and output within 1.4 ms

This constraint was not tested due to lack of time.

### Constraint 10 - Communicate FIR filter coefficients with Bluetooth connection subsystem

This constraint is not traditionally experimental and was not met.

### Constraint 11 - Main processor shall hold at least 2 seconds of samples per input signal

This constraint was not tested due to lack of time, but is not traditionally experimental.

### Constraint 12 - Speaker shall be within 0.5 m from the window being measured

Experimental Design
* As shown in our experimental setup, the speakers were attached to a wooden slab which was then attached to the door through Velcro command strips.
  
Conclusion
* Due to the nature of the experimental setup, the speakers did not protrude more than 0.5 meters away from the door being tested. Meaning that this constraint was satisfied.


### Constraint 13 - Shall be easy to remove and setup in a different room

Experimental Design
* Both the speakers and the mounting subsystem were attached the wall using velcro command strips. Which allow the components to be pulled off of the wall and reattached multiple times\

Results

| Trial | Damage (Qualitative)|
|-------|---------------------|
| 1| None|
| 2| None|
| 3| None|
| 4| None|

No damage was found.
  
Conclusion
* While the experimental setup used was not the one that was originally envisioned, it still allowed for easy removal and installation in multiple rooms. This constraint was satisfied.

### Constraint 14 - Mounting shall have a space for input, error, output, processing, and power subsystems

Experimental Design
* hi
  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 15 - The audio amplifier and speaker shall support a minimum frequency range of 1 kHz - 17 kHz

Experimental Design
* To test the frequency response of the speaker, a microphone was used to measure the outputted sound from the speaker as different frequencies were inputted from a waveform generator. These frequencies were stepped up from 1 Hz all the way to 20 kHz to obtain an accurate graph and data for the speakers frequency response. Analysis was made for 3dB as our corner frequencies.
  
Results
![Frequency_Response](https://github.com/CarsonDPope/Active-Noise-Control-With-Wall-Transmission-Detection/assets/123997954/2b59f3d0-11ce-473b-958a-6827894d9689)
#### **Figure: Speaker Average Frequenct Response (dBspl vs Frequency (Hz))**
* The above graph shows the speakers measured dBspl against the inputted frequency. As indicated by the orange the line, the speaker performs optimally in the range of 1 kHz - 17kHz. The sound pressure level was not calibrated prior to measurements, but this only introduces an offset. 
  
Interpretation of Results
* As shown in the frequency response graph obtained, the speaker performs optimally in the range of 1 kHz - 17 kHz. This constraint is satisfied.


### Constraint 16 - Audio amplifier shall deliver at least 10 W of continuous power at its output

Experimental Design
* The power system was successfully able to power each of the components together, and each rail had the correct amount of voltage that was needed. Due to time constraints and difficulties though, no additional testing was done.
  
Conclusion
* While not explicitly tested, the audio amplifier was successfully able to power the speakers and output an inputted signal. So, this constraint is considered satisfied.



### Constraint 17 - Speaker shall capable of outputting 90 dB and 90 dB SPL across the window

Experimental Design
* The speakers were able to successfully output when powered and a full frequency response was done, however, we were unable to test the SPL due to time constraints.
  
Conclusion
* While it is believed that the speaker was outputting above 90 SPL, no explicit testing was done , therefore this constraint was not fulfilled.



### Constraint 18 - Speakers shall have an input power rating maximum that matches the amplifier's maximum power output

Experimental Design
* The speaker and the amplifier were chosen according to their rated values for power, impedance, and output capabilities. The amplifier is rated to supply 16 W of power at its output, while the speaker needs 10 W of power at its input.
  
Conclusion
* The power that the amplifier is rated to supply is sufficient in what the speaker is rated to intake. This constraint is satisfied.




### Constraint 19 - Speakers shall be mounted to the wall without impeding movement or damaging the classroom

Experimental Design
* The speakers were screwed into a wooden slab, which was then attached to the door through command strips.  After removal of the experimental setup, there showed no signs of damage to the door or the wall. Nor did the speakers block the movement of those within the room.
  
Conclusion
* The mounting of the speakers neither damaged the wall nor impede movement. This constraint was satisfied.



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
The objective of this experiment was to prove that the system can operate with a maximum input ripple voltage of 400mV

This was tested by

  
Results
* bye
  
Interpretation of Results
* sigh


### Constraint 23 - Shall step down power supply to 5, 10, and 12 VDC

Experimental Design
*The objective of this experiment is to take the voltage from the wall wart and using it to provide 5VDC, 10VDC, and 12VDC

*This was tested by taking a oscilloscope on each output of the proto-board and taking samples of the DC voltage.

Results

|Sample | 5 Volt Rail Average Voltage | 10 Volt Rail Average Voltage | 12 Volt Rail Average Voltage |
|----|----|----|----|
| 1|7.18| 10.2 | 12.5|
| 2|7.20| 10.3 | 12.6|
| 3|7.19| 10.2 | 12.6|
| 4|7.19| 10.2 | 12.6|
| 5|7.20| 10.3 | 12.6|
| 6|7.19| 10.3 | 12.6|
| 7|7.19| 10.2 | 12.6|
| 8|7.20| 10.2 | 12.6|
| 9|7.19| 10.3 | 12.5|
|10|7.18| 10.2 | 12.4|
|11|7.19| 10.3 | 12.4|
|12|7.20| 10.2 | 12.4|
|13|7.19| 10.2 | 12.4|
|14|7.20| 10.2 | 12.5|
|15|7.21| 10.3 | 12.5|
|16|7.19| 10.2 | 12.6|
|Average|7.193|10.2375|12.535| 

For 5 Volt rail:

Null Hypothesis => $\mu$ = 5 V

Alt. Hypothesis => $\mu < 5 < \mu$ 

T-score = -1142.233481

T-Test = 1 

Did not achieve 5 V to wanted confidence level.

For 10 Volt rail:

Null Hypothesis => $\mu$ = 10 V

Alt. Hypothesis => $\mu < 10 < \mu$ 

T-score = -19.62311562

T-Test = 1 

Did not achieve 10 V to wanted confidence level.

For 12 Volt rail:

Null Hypothesis => $\mu$ = 12 V

Alt. Hypothesis => $\mu < 12 < \mu$ 

T-score = -121.8105832

T-Test = 1 

Did not achieve 12 V to wanted confidence level.

## Improvements and Future Work

* Redesign with better filtering, and the 3.3V regulator of Arduino in mind.
* Add safety features.

## Conclusion

Constraint was not met

### Constraint 24 - Attenuate targeted noises by at least 20 dB

#### Experimental Design

![Experimental Setup*](/brokenLink)


1. Setup a simulation of a classroom with outside noise coming in towards the input microphone and
through to the speakers which point to the error microphone
2. Record ten-second audio clips using a microphone at the error location with ambient noise three times
3. Record ten-second audio clips using a microphone at the error location with generated noise without
active noise cancellation three times
4. Record ten-second audio clips using a microphone at the error location with generated noise with
active noise cancellation three times
5. Save all results, process data with MATLAB

The graphs in "results" show instantaneous power vs time. They only encompass interesting points in that trial, for better visualization.
  

#### Results
| Trial | Noise Power Reduction |
|-------|-------------|
| 1     | -1.4852 dB  |
| 2     | -2.1379 dB  |
| 3     | -3.9413 dB  |

Average Noise Power Reduction = -2.4426 dB

![Trial 1: Noise](https://media.discordapp.net/attachments/1067941517798420532/1180284126805372949/Trial1_InstantaneousPower_vs_Time.png?ex=657cdc40&is=656a6740&hm=f4131c04feed5a8e39e8304ddd1db110a5f165afce2fd893517334c181493bc5&=&format=webp&quality=lossless&width=1280&height=9601image)

![Trial 2: Audio](/trial2image)

![Trial 3: Impulse](/trial3image)
  
#### Interpretation of Results

The system was not tested with strong rigor, and was an idealized setup. However, the system was still able to show some reduction. In each trial, a reduction was made with an average reduction of 2.4426 dB (signal power). This is still not to spec.

\* The picture above is not the exact setup as when the results were collected, but very similar. Differences include using benchtop power supplies and different microphones.

## Improvements and Future Work

* Optimize the Filtered-X LMS algorithm and include higher order FIR Filters
* Use Approximated Plant Responses
* Enable the use of the machine learning algorithm by fixing communication.

## Conclusion

The system was not able to meet the goal of -20 dB reduction. It is considered not met. However, some audio reduction was shown, and the team believes further research and better implementation could create a system that eventually achieves success.

| **ID** | **Constraint description**                                                                          | **Constraint Met?** |
|--------|-----------------------------------------------------------------------------------------------------|---------------------|
| 1      | Send and receive 16-bit data with machine learning                                                  |         yes            |
| 2      | Send and receive 16-bit data with main processor                                                    |         yes            |
| 3      | Send audio data and receive filter data within 4 seconds                                            |         N/A            |
| 4      | Bluetooth must reach anywhere in the room                                                           |         yes            |
| 5      | Microphone shall react to inputs from 20 Hz to 20 kHz                                               |         N/A            |
| 6      | Input and error subsystem's output shall be no higher than 3.3 Vpp                                  |         N/A            |
| 7      | Input and error subsystems' gain shall match each other                                             |         N/A            |
| 8      | Input and error delay shall be within 0.2 ms                                                        |         N/A            |
| 9      | Main processor shall process and output within 1.4 ms                                               |         N/A            |
| 10     | Communicate FIR filter coefficients with Bluetooth connection subsystem                             |         no            |
| 11     | Main processor shall hold at least 2 seconds of samples per input signal                            |         N/A            |
| 12     | Speaker shall be within 0.5 m from the window being measured                                        |     yes                |
| 13     | Shall be easy to remove and setup in a different room                                               |      yes               |
| 14     | Mounting shall have a space for input, error, output, processing, and power subsystems              |      no               |
| 15     | The audio amplifier and speaker shall support a minimum frequency range of 1 kHz - 17 kHz           |      yes               |
| 16     | Audio amplifier shall deliver at least 10 W of continuous power at its output                       |      yes               |
| 17     | Speaker shall capable of outputting 90 dB and 90 dB SPL across the window                           |         N/A            |
| 18     | Speakers shall have an input power rating maximum that matches the amplifier's maximum power output |   yes                  |
| 19     | Speakers shall be mounted to the wall without impeding movement or damaging the classroom           |       yes              |
| 20     | Power shall convert wall outlet AC to DC                                                            |          yes           |
| 21     | Power shall supply a minimum of 29 W                                                                |           N/A          |
| 22     | Power shall operate on a maximum input ripple voltage of 400 mV                                     |           yes          |
| 23     | Shall step down power supply to 5, 10, and 12 VDC                                                   |      no               |
| 24     | Attenuate targeted noises by at least 20 dB                                                         |         no            |


