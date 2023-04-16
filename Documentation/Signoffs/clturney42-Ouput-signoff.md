# Processing Subsystem

<img width="570" alt="Screen Shot 2023-04-13 at 9 01 43 AM" src="https://user-images.githubusercontent.com/123997954/231783367-d7562533-fe29-4052-abbc-71808ca306b7.png">


## Function of the Subsystem

The goal of the output subsystem is to take the analog signal received from the processor, amplify the signal through a audio power amplifier, and drive it to the speaker so that it can be emitted. The power amplifier will need to amplify the analog signal to an appropiate level for the speaker to be able to output it into the room. The speaker and amplifier must have internal impedences that are compatible and the speaker needs to be able to have an efficiency and sound pressure level to adequately cover a certain portion of the room. 


## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | The power amplifier          | Device Constraint |

## Analysis
### Explanation of Components

#### pmod AMP2 - IC-SSM2377

The IC-SSM2377 chip is a filterless class-D audio amplifier. A class-D audio amplifier has the highest efficiency among amplifier classes with low distortion. Clear sound is imperative to noise cancellation therefore the best class of amplifier should be used. The SSM2377 can deliver 2.5W of power to a load of 4Ω, and around 1.4W of power to a load of 8Ω. It is capable of up to a 92% efficiency ratio and has very low total harmonic distortion meaning the sound is very clear. It also has a signal-to-noise ration of 101 which means the signal will come through with little to no distortion from background noise. The SSM2377 also makes use of 3 level delta-sigma modulation, which helps to achieve higher transmission efficiency by transmitting the changes in samples rather than the samples themselves. 

This chip is implemented through the pmod AMP2 from Digilent, INC. The pmod AMP2 takes the signal and amplifies it and drives it to a monophonic output using the SSM377 chip. It has the capability to switch between a gain of 6 dB and 12 dB allowing for more adaptability and accuracy in the outputted signal. The pmod also has a shutdown pin that allows the amplifier to be shutdown with very little power draw. According to the pmod’s reference manual as long the incoming data has a sample rate of at least 16 kHz. One of the constraints of this design is for the minimum sampling rate of analog-to-digital and digital-to-analog conversion be 40 kHz, meaning there will be no problem with the data sent to the pmod AMP2.

#### Output Speaker

A speaker with the proper characteristics must be chosen to interface properly with the audio amplifier. The pmod AMP2 can supply up to 2.5 watts of power to the speaker, so it’s ideal for the speaker to have a maximum power rating of 2 watts to ensure that the amplifier is able to properly supply the speaker, even in the case that the amplifier power output fluctuates.



## Buildable schematic 

<img width="820" alt="Screen Shot 2023-04-15 at 4 09 37 PM" src="https://user-images.githubusercontent.com/123997954/232253257-362a0e5e-6b52-43da-aee9-0ffa3ed7d06a.png">

### **Figure: Digilent pmod AMP2 schematic[2]**

The above schematic is taken directly from digilents pmod AMP2 product page. This schematic shows the various values for the reistors and capacitors used. This audio amplifer makes use of the IC-SSM2377 amplifier chip. 

For the purpose of the buildable schematic the pmod will be condensed to a single block with just its ports. 
## Analysis
### Explanation of Components

#### pmod AMP2 - IC-SSM2377

The IC-SSM2377 chip is a filterless class-D audio amplifier. A class-D audio amplifier has the highest efficiency among amplifier classes with low distortion. Clear sound is imperative to noise cancellation therefore the best class of amplifier should be used. The SSM2377 is capable of delivering 2.5W of power to a load between 4-8Ω. It is capable of up to a 92% efficiency ratio and has very low total harmonic distortion meaning the sound is very clear. It also has a signal-to-noise ration of 101 which means the signal will come through with little to no distortion from background noise. This chip is implemented through the pmod AMP2 from Digilent, INC. The pmod AMP2 takes the signal and amplifies it and drives it to a monophonic output using the SSM377 chip. It has the capability to switch betwen a gain of 6 dB and 12 dB allowing for more adaptability and accuracy in the outputted signal. The pmod also has a shutdwon pin that allows the amplifer to be shutdown with very little power draw.




#### Psuedo Code Flow Chart




### Output 

The digital output is then converted back to an analog stereo signal. Both channels of the system are equal and will be sent to a 2 speaker array. 

## BOM
| DEVICE            | Quantity | Price Per Unit | Total Price |
| ----------------- | -------- | -------------- | ----------- |
| Pmod AMP2: Audio Amplifier | 1        | $9.99        | $9.99     |

## References

[1] Analog Devices, "Filterless, High Efficiency, Mono 2.5 W Class-D Audio Amplifier" SSM2377 datasheet, 2011, https://www.analog.com/media/en/technical-documentation/data-sheets/SSM2377.pdf (accessed April 15th, 2023).

[2] “pmod AMP2 schematic,” pmodAMP2, 22-Dec-2011. [Online]. Available: https://reference.digilentinc.com/_media/reference/pmod/pmodamp2/pmodamp2_sch.pdf. [Accessed: 15-Apr-2023].  

[3] Analog Devices. "SigmaDSP Stereo, Low Power, 96 kHz, 24-Bit Audio Codec with Integrated PLL" ADAU1761 Datasheet, 2009-2018.

