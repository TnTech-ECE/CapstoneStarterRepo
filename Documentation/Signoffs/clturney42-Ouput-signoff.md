# Output Subsystem

<p align="center">
<img width="1018" alt="Screen Shot 2023-04-16 at 6 12 58 PM" src="https://user-images.githubusercontent.com/123997954/232348587-a962e40f-7dd1-43ec-834e-d62ea83feeec.png">
<p>
  
#### **Figure 1: Output subsystem**


## Function of the Subsystem

The goal of the output subsystem is to take the analog signal received from the processor, amplify the signal through an audio power amplifier, and drive it to the speaker so that it can be emitted. The power amplifier will need to amplify the analog signal to an appropriate level for the speaker to be able to output it into the room. The speaker and amplifier must have internal impedances that are compatible, and the speaker needs to be able to have an efficiency and sound pressure level to adequately cover a certain portion of the room. 


## Constraints
  
| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | The Audio amplifier shall be supplied a minimum of 2.5 V and maximum of 5.5 V from the power supply.          | Device specifications |
| 2   | The audio amplifier and speaker shall be able to output at a minimum frequency range of 100Hz-17Khz.                   | Device constraints and human biology |
| 3   | The speaker shall have a minimum input impedance 4Ω                           | audio amplifier specifications |
| 4   | System shall have a primary output speaker that generates acoustic sounds based on its analog input from the system                                | Conceptual design and to fulfill goal of system |
| 5   | Speaker shall be capable of outputting at a sound pressure efficiency of at least 90 dB                                     | Constraints of room and device constraints |
| 6   | Speaker shall have an input power rating minimum of 1 watt and maximum of 2 watts                                     | Amplifier specifications and power insurance |
| 7 | Output system shall extend a maximum of 0.5 meters from the wall | Ethics and system delay |
| 8 | Output system shall have a maximum delay of 1.4ms | Device specifications and goal of system |

  
### 1) The Audio amplifier shall be supplied a minimum of 2.5 V and maximum of 5.5 V from the power supply.     |Origin: Device specifications|
According to the SSM2377 datasheet [1], The Pmod AMP2 can drive a 4-8Ω load as long as it is supplied a voltage range of 2.5-5.5 volts. With this in mind it is imperative that a constraint is included that ensures a correct amount of power is supplied to the amplifier.


### 2) The audio amplifier and speaker shall be able to output at a minimum frequency range of 100Hz-17Khz.    |Origin: Device constraints and human biology|
The frequency range that the human ear can hear is generally in the range of 20Hz-20Khz, this range is subject to change with age, but this is the minimum and maximum. With this in mind it would be ideal for the speaker to able to output at a frequency range that covers most of the values that the human ear can perceive. This also means that the audio amplifier should be able to take in and output this range of frequencies. Therefore, a constraint is set that ensures the speaker and audio amplifier can output at a range of 100Hz-17Khz, this range allows a bit more adaptability to the design but covers an appropriate range of necessary sounds that the device will encounter. 

### 3) The speaker shall have a minimum input impedance 4Ω |Origin: audio amplifier specifications|
When it comes to speaker, there is a built-in input impedance that the device has. The lower the impedance the higher the current draw since there is less resistance. This also means the lower the impedance the less voltage that is required. The audio amplifier used in this design in specified to be able to drive a 4-8Ω load [1][3]. If an amplifier tries to drive a speaker with a impedance that is lower than what is rated to be capable of, there is a high chance that the amplifier will overheat. [ref] Therefore, the speaker that will be used will have a minimum input impedance of 4Ω. This allows for a wider range of speakers and amplifiers to be used and ensures that a safe design choice is made, since speakers with impedances above the rated amplifier impedance can be used with minimal issues.

### 4) System shall have a primary output speaker that generates acoustic sounds based on its analog input from the system. |Origin: Conceptual design and to fulfill goal of system|
The processing portion of the system is going to process a signal and convert it to analog to be sent to the output. To properly make use of this analog input the output subsystem must be able to take in this analog signal and after amplifying it, output it as an acoustic sound wave that will attenuate noise. With this in mind, the output system is being designed in a way that allows the amplifier to take in an analog input and properly interface with the speaker to emit and appropriate output.

### 5) Speaker shall be capable of outputting at a sound pressure efficiency of at least 90 dB. |Origin: Constraints of room and device constraints|
Sound pressure level (SPL) is characterized as the difference between the pressure of a sound wave and the ambient pressure of the air that it is traveling through [5]. Speakers with an SPL of 84 decibels or lower are considered poor and inefficient while speakers with an efficiency of 92 or higher are considered clear and loud. With this in mind, a good middle ground that allows for a wide range of speakers that can output at an appropriate SPL to cover a portion of the room is a 90 dB SPL. 


### 6) Speaker shall have an input power rating minimum of 1 watt and maximum of 2 watts |Origin: Amplifier specifications and power insurance|
Due to the amplifier being able to supply a continuous power of 1.4 - 2.5W [1], an appropriate speaker must be selected so that the amplifier has enough power to drive it. A good rule of thumb is to have the amplifier used have an output power 1.5-2 times higher than the speakers power rating. With this in mind, the speaker that is used should have a power rating of 2 watts or less. This ensures that the amplifier will be able to consistently drive the speaker with enough power, even if there are slight fluctuations in the system.

### 7) Output system shall extend a maximum of 0.5 meters from the wall |Origin: Ethics and system delay|
### 8) Output system shall have a maximum delay of 1.4ms |Origin: Device specifications and goal of system|
## Buildable schematic 

<img width="1033" alt="Screen Shot 2023-04-24 at 3 25 53 PM" src="https://user-images.githubusercontent.com/123997954/234108774-1d8e2b08-e2fc-4628-8fe8-8a6270463427.png">


### **Figure 3: pmodAMP2 connected to speaker with appropriate specifications**

The above image is the buildable schematic for the output subsystem. As shown, the input of the subsystem will be connected to the output of the processing and receive an analog voltage signal. Connecting the gain pin to Vcc results in a 6 dB gain and connecting gain to ground results in a 12 dB gain. The shutdown pin will be connected to Vcc, resulting in a logical 1, meaning the shutdown feature will not be active. Vcc will be connected to the incoming power supply which will be supplying a power level between 2.5-5.5 Watts. The stereo 1/8" output J1 will be connected to 3.5mm male plug to bare wire aux cable so that the power and ground cables from the speaker can be connected.

## Analysis

#### pmod AMP2 - IC-SSM2377 [3][1]

 The SSM2377 can deliver 2.5W of power to a load of 4Ω, and around 1.4W of power to a load of 8Ω.  

**According to the pmod’s reference manual as long the incoming data has a sample rate of at least 16 kHz, the amplifier will be able to handle incoming data. One of the constraints of this design is for the minimum sampling rate of analog-to-digital and digital-to-analog conversion be 40 kHz, meaning there will be no problem with the data sent to the pmod AMP2.**

#### Output Speaker

[6]**The pmod AMP2 can supply up to 2.5 watts of power to the speaker, so it’s ideal for the speaker to have a maximum power rating of 2 watts to ensure that the amplifier is able to properly supply the speaker, even in the case that the amplifier power output fluctuates.** **As outlined in the constraints, the speaker should also be able to output at a minimum frequency range of 100Hz-17Khz to account for the range that the human ear is capable of hearing. To account for the size of the room and need to disperse audio over a relatively wide range, the speaker must have a sufficient sound pressure level (SPL) to adequately cover a portion of the room. Due to the amplifier being able to drive a load impedance of 4-8Ω, a speaker must be chosen that has an input impedance of 4Ω or greater.** 

#### Further connections

Due to the speakers that fall within the specified range not having built in stereo jack cables, a 3.5mm to bare wire cable must be used. The voltage and ground cables from the speaker will be connected to their respective wires on the aux cable, then the aux cable will be connected to the 3.5mm stereo jack on the pmod AMP2. This will allow a proper flow and connection between the amplifier circuit and the output speaker.




## BOM
| DEVICE            | Quantity | Price Per Unit | Total Price |
| ----------------- | -------- | -------------- | ----------- |
| Pmod AMP2: Audio Amplifier   | 1              | $9.99        | $9.99     |
| Speaker Selection | 1     | $1.20-$6.10  | $1.20-$6.10  |
|3.5mm male plug to bare wire| 1| $3.59 | $3.59|
## References

[1] Analog Devices, "Filterless, High Efficiency, Mono 2.5 W Class-D Audio Amplifier" SSM2377 datasheet, 2011, https://www.analog.com/media/en/technical-documentation/data-sheets/SSM2377.pdf (accessed April 15th, 2023).

[2] “pmod AMP2 schematic,” pmodAMP2, 22-Dec-2011. [Online]. Available: https://reference.digilentinc.com/_media/reference/pmod/pmodamp2/pmodamp2_sch.pdf. [Accessed: 15-Apr-2023].  

[3] “PMODAMP2™ reference manual - digilent,” PmodAMP2™ Reference Manual, 15-Apr-2016. [Online]. Available: https://digilent.com/reference/_media/reference/pmod/pmodamp2/pmodamp2_rm.pdf. [Accessed: 16-Apr-2023]. 

[4] “Digilent Pmod™ interface specification,” Digilent Pmod™ Interface Specification, 28-Oct-2020. [Online]. Available: https://digilent.com/reference/_media/reference/pmod/pmod-interface-specification-1_3_1.pdf. [Accessed: 16-Apr-2023]. 

[5] K. Koehler, “Understanding sound pressure level (SPL) and the decibel scale,” Pro Tool Reviews, 09-Sep-2021. [Online]. Available: https://www.protoolreviews.com/understanding-sound-pressure-level-spl-decibel-scale-db/. [Accessed: 16-Apr-2023]. 

[6] P. Brant, “Speaker Impedance Matching: Ohms &amp; Speakers explained,” Speaker Impedance Matching: Ohms &amp; Speakers Explained, 21-Feb-2023. [Online]. Available: https://www.the-home-cinema-guide.com/speaker-impedance-matching.html. [Accessed: 16-Apr-2023]. 
 
[7] “Benefits of delta-sigma analog-to-digital conversion,” NI, 04-Apr-2023. [Online]. Available: https://www.ni.com/en-us/shop/data-acquisition/benefits-of-delta-sigma-analog-to-digital-conversion.html. [Accessed: 16-Apr-2023].



