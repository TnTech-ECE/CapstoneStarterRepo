# Processing Subsystem

<img width="570" alt="Screen Shot 2023-04-13 at 9 01 43 AM" src="https://user-images.githubusercontent.com/123997954/231783367-d7562533-fe29-4052-abbc-71808ca306b7.png">


## Function of the Subsystem

The goal of the output subsystem is to take the analog signal received from the processor, amplify the signal through a audio power amplifier, and drive it to the speaker so that it can be emitted. The power amplifier will need to amplify the analog signal to an appropiate level for the speaker to be able to output it into the room. The speaker and amplifier must have internal impedences that are compatible and the speaker needs to be able to have an efficiency and sound pressure level to adequately cover a certain portion of the room. 


## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | The power amplifier          | Device Constraint |

### 1) The Audio amplifier shall be supplied a minimum of 2.5 V and maximum of 5.5 V from the power supply.     |Origin: Device specifications|
According to the SSM2377 datasheet [1], The Pmod AMP2 is capable of driving a 4-8Ω load as long as it is supplied a voltage range of 2.5-5.5 volts. With this in mind it is imperative that a constraint is included that ensures a correct amount of power is supplied to the amplifier.
## Buildable schematic 

<img width="820" alt="Screen Shot 2023-04-15 at 4 09 37 PM" src="https://user-images.githubusercontent.com/123997954/232253257-362a0e5e-6b52-43da-aee9-0ffa3ed7d06a.png">
### **Figure: Digilent pmod AMP2 schematic[2]**

The above schematic is taken directly from digilents pmod AMP2 product page. This schematic shows the various values for the reistors and capacitors used. This audio amplifer makes use of the IC-SSM2377 amplifier chip. 

The above image is a schematic of the BF706 processor, the schematic focuses on the most important aspects of this device with respect to the overall design goal. The schematic shows stereo input and output ports along with a micro USB input and the subsystems that will connected to this device.  
## Analysis

#### Psuedo Code Flow Chart




### Output 

The digital output is then converted back to an analog stereo signal. Both channels of the system are equal and will be sent to a 2 speaker array. 

## BOM
| DEVICE            | Quantity | Price Per Unit | Total Price |
| ----------------- | -------- | -------------- | ----------- |
| ADSP-BF706-EZMINI | 1        | $88.31         | $88.31      |

## References

[1] Analog Devices, "Filterless, High Efficiency, Mono 2.5 W Class-D Audio Amplifier" SSM2377 datasheet, 2011, https://www.analog.com/media/en/technical-documentation/data-sheets/SSM2377.pdf (accessed April 15th, 2023).

[2] “PMODAMP2™ reference manual - digilent,” pmodAMP2, 12-Dec-2011. [Online]. Available: https://digilent.com/reference/_media/reference/pmod/pmodamp2/pmodamp2_rm.pdf. [Accessed: 15-Apr-2023]. 

[3] Analog Devices. "SigmaDSP Stereo, Low Power, 96 kHz, 24-Bit Audio Codec with Integrated PLL" ADAU1761 Datasheet, 2009-2018.

