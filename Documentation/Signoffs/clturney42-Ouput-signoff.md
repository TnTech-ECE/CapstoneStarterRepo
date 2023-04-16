# Processing Subsystem

<img width="570" alt="Screen Shot 2023-04-13 at 9 01 43 AM" src="https://user-images.githubusercontent.com/123997954/231783367-d7562533-fe29-4052-abbc-71808ca306b7.png">

#### **Figure1: Output subsystem**


## Function of the Subsystem

The goal of the output subsystem is to take the analog signal received from the processor, amplify the signal through a audio power amplifier, and drive it to the speaker so that it can be emitted. The power amplifier will need to amplify the analog signal to an appropiate level for the speaker to be able to output it into the room. The speaker and amplifier must have internal impedances that are compatible and the speaker needs to be able to have an efficiency and sound pressure level to adequately cover a certain portion of the room. 


## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | The power amplifier          | Device Constraint |


### 1) The Audio amplifier shall be supplied a minimum of 2.5 V and maximum of 5.5 V from the power supply.     |Origin: Device specifications|
According to the SSM2377 datasheet [1], The Pmod AMP2 is capable of driving a 4-8Ω load as long as it is supplied a voltage range of 2.5-5.5 volts. With this in mind it is imperative that a constraint is included that ensures a correct amount of power is supplied to the amplifier.


### 2) The audio amplifier and speaker shall be able to output at a minimum frequency range of 100Hz-17Khz.    |Origin: Device constraints and human biology|
The frequency range that the human ear can hear is generally in the range of 20Hz-20Khz, this range is subject to to change with age but this is the minimum and maximum. With this in mind it would be ideal for the speaker to able to output at a frequency range that covers most of the values that the human ear can perceive. This also means that the audio amplifier should be able to take in and output this range of frequencies. Therefore a constraint is set that ensures the speaker and audio amplifier can output at a range of 100Hz-17Khz, this range allows a bit more adaptability to the design but covers an appropiate range of necessary sounds that the device will encounter. 

### 3) The speaker shall have a minimum input impedance 4Ω |Origin: audio amplifier specifications|
When it comes to speaker, there is a built in input impedance that the device has. The lower the impedance the higher the current draw since there is less resistance. This also means the lower the impedance the less voltage that is required. The audio amplifier used in this design in specified to be able to drive a 4-8Ω load. If a amplifier tries to drive a speaker with a impedance that is lower than what is rated to be capable of, there is a high chance that the amplifier will overheat.[ref] Therefore, the speaker that will be used will have a minimum input impedance of 4Ω. This allows for a wider range of speakers and amplifiers to be used and ensures that a safe design choice is made, since speakers with imoedences above the rated amplifier impedance can be used with minimal issues.

### 4) System shall have a primary output speaker that generates acoustic sounds based on its analog input from the system. |Origin: Conceptual design and to fulfill goal of system|
The processing portion of the system is going to process a signal and convert it to analog to be sent to the output. To properly make use of this analog input the output subsystem must be able to take in this analog signal and after amplifying it, output it as an acoustic sound wave that will attenuate noise. With this in mind, the output system is being designed in a way that allows the amplifier to take in an analog input and properly interface with the speaker to emit and appropiate output.

### 5) Speaker shall be capable of outputting at a sound pressure efficiency of at least 90 dB. |Origin: Constraints of room and device constraints|
Sound pressure level(SPL) is characterized as the difference between the pressure of a sound wave and the ambient pressure of the air that it is traveling through. Speakers with an SPL of 84 decibels or lower are considered poor and inefficent while speakers with an efficiency of 92 or higher are considered clear and loud. With this in mind, a good middle ground that allows for a wide range of speakers that can output at an appropiate SPL to cover a portion of the room is a 90 dB SPL. 




## Buildable schematic 

<img width="820" alt="Screen Shot 2023-04-15 at 4 09 37 PM" src="https://user-images.githubusercontent.com/123997954/232253257-362a0e5e-6b52-43da-aee9-0ffa3ed7d06a.png">

### **Figure: Digilent pmod AMP2 schematic[2]**

The above schematic is taken directly from digilents pmod AMP2 product page. This schematic shows the various values for the reistors and capacitors used. This audio amplifer makes use of the IC-SSM2377 amplifier chip. 

For the purpose of the buildable schematic the pmod will be condensed to a single block with just its ports.

Screen Shot 2023-04-16 at 4.56.03 PM<img width="678" alt="image" src="https://user-images.githubusercontent.com/123997954/232344786-31dc2d4d-c3bf-4c9f-93e2-5f7757014fa8.png">

### **Figure: pmodAMP2 connected to speaker with appropriate specifications**


The above image is the buildable schematic for the output subsystem. As shown, the input of the subsystem will be connected to the output of the processing and receive an analog voltage signal. Connecting the gain pin to Vcc results in a 6 dB gain, and connecting gain to ground results in a 12 dB gain. The shutdown pin will be connected to Vcc, resulting in a logical 1, meaning the shutdown feature will not be active. Vcc will be connected to the incoming power supply which will be supplying a power level between 2.5-5.5 Watts. The stereo 1/8" output J1 will be connected to 3.5mm male plug to bare wire aux cable so that the pwoer and ground cables from the speaker can be connected.

## Analysis
### Explanation of Components

#### pmod AMP2 - IC-SSM2377

The IC-SSM2377 chip is a filterless class-D audio amplifier. A class-D audio amplifier has the highest efficiency among amplifier classes with low distortion. Clear sound is imperative to noise cancellation therefore the best class of amplifier should be used. The SSM2377 can deliver 2.5W of power to a load of 4Ω, and around 1.4W of power to a load of 8Ω. It is capable of up to a 92% efficiency ratio and has very low total harmonic distortion meaning the sound is very clear. It also has a signal-to-noise ration of 101 which means the signal will come through with little to no distortion from background noise. This chip also has pop-and-click suppression, often when the output level and voltage of an amplifier quickly changes or shuts off, audible pops can be heard from the speaker. This is the result of voltage transients, but this suppression feature in the IC chips allows for a quitter activation and deactivation of the chip when shutdown or activated. The SSM2377 also makes use of 3 level delta-sigma modulation, which helps to achieve higher transmission efficiency by transmitting the changes in samples rather than the samples themselves. 

This chip is implemented through the pmod AMP2 from Digilent, INC. The pmod AMP2 takes the signal and amplifies it and drives it to a monophonic output using the SSM2377 chip. The pmod AMP2 already has built in resistors, capacitors, and inductors that satisfy the SSM2377 specifications for input capacitors and power supply decoupling. It has the capability to switch between a gain of 6 dB and 12 dB allowing for more adaptability and accuracy in the outputted signal. The pmod also has a shutdown pin that allows the amplifier to be shutdown with very little power draw. According to the pmod’s reference manual as long the incoming data has a sample rate of at least 16 kHz. One of the constraints of this design is for the minimum sampling rate of analog-to-digital and digital-to-analog conversion be 40 kHz, meaning there will be no problem with the data sent to the pmod AMP2.

#### Output Speaker

A speaker with the proper characteristics must be chosen to interface properly with the audio amplifier. The pmod AMP2 can supply up to 2.5 watts of power to the speaker, so it’s ideal for the speaker to have a maximum power rating of 2 watts to ensure that the amplifier is able to properly supply the speaker, even in the case that the amplifier power output fluctuates. As outlined in the constraints, the speaker should also be able to output at a minimum frequency range of 100Hz-17Khz to account for the range that the human ear is capable of hearing. To account for the size of the room and need to disperse audio over a relatively wide range, the speaker must have a sufficient sound pressure level (SPL) to adequately cover a portion of the room. Due to the amplifier being able to drive a load impedance of 4-8Ω, a speaker must be chosen that has an input impedance of 4Ω or greater. It is unclear what SPL should be used without having measured the ambient sound pressure of the room. So, it is important to know the range of values in which the speaker must be able to operate.






## BOM
| DEVICE            | Quantity | Price Per Unit | Total Price |
| ----------------- | -------- | -------------- | ----------- |
| Pmod AMP2: Audio Amplifier | 1        | $9.99        | $9.99     |

## References

[1] Analog Devices, "Filterless, High Efficiency, Mono 2.5 W Class-D Audio Amplifier" SSM2377 datasheet, 2011, https://www.analog.com/media/en/technical-documentation/data-sheets/SSM2377.pdf (accessed April 15th, 2023).

[2] “pmod AMP2 schematic,” pmodAMP2, 22-Dec-2011. [Online]. Available: https://reference.digilentinc.com/_media/reference/pmod/pmodamp2/pmodamp2_sch.pdf. [Accessed: 15-Apr-2023].  

[3] Analog Devices. "SigmaDSP Stereo, Low Power, 96 kHz, 24-Bit Audio Codec with Integrated PLL" ADAU1761 Datasheet, 2009-2018.

