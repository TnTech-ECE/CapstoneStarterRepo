# Processing Subsystem

<img width="570" alt="Screen Shot 2023-04-13 at 9 01 43 AM" src="https://user-images.githubusercontent.com/123997954/231783367-d7562533-fe29-4052-abbc-71808ca306b7.png">


## Function of the Subsystem

The goal of the output subsystem is to take the analog signal received from the processor, amplify the signal through a audio power amplifier, and drive it to the speaker so that it can be emitted. The power amplifier will need to amplify the analog signal to an appropiate level for the speaker to be able to output it into the room. The speaker and amplifier must have internal impedences that are compatible and the speaker needs to be able to have an efficiency and sound pressure level to adequately cover a certain portion of the room. 


## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | The power amplifier          | Device Constraint |

### 1) The Audio amplifier shall be supplied a minimum of 2.5 V and maximum of 5.5 V from the power supply.     |Origin: Device specifications|
The Pmod AMP2 is capable of driving a 4 &OMEGA
## Buildable schematic 


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

1] Analog Devices, "Blackfin ADSP-BF70x Ultralow Power, Low Cost DSP Evaluation Platform ADSP-BF706 EZ-KIT Mini" ADSP-BF706 EZ-KIT Mini, 2015, https://www.analog.com/media/en/news-marketing-collateral/product-highlight/Blackfin-ADSP-BF706_MINI.pdf (accessed Apr. 4, 2023).

[2] Analog Devices, "Blackfin+ Core Embedded Processor" Blackfin, Blackfin+, and the Blackfin logo are registered trademarks of Analog Devices, Inc. Blackfin+ Core Embedded Processor ADSP-BF700/701/702/703/704/705/706/707, February 2019.

[3] Analog Devices. "SigmaDSP Stereo, Low Power, 96 kHz, 24-Bit Audio Codec with Integrated PLL" ADAU1761 Datasheet, 2009-2018.

