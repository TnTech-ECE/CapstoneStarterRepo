# Processing Subsystem

## Function of the Subsystem

The goal of this subsystem is to process the input signal, and output an appropriate response to the ambient noise present in the room. The processing subsystem consists of an ADC converter which will take the input and convert it into digital samples which will be analyzed and processed by the adaptive filter algorithms. The output will then be converted using a DAC converter and outputted to the other parts of the system.

## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | Max power draw of 2.5 Watts from onboard USB connection port          | Device Constraint |
| 2   | Shall process and output with a max delay of 20.83 $\mu s$            | Spec Constraint   |
| 3   | Shall have a sample rate of 48 kHz                                    | Device Constraint |
| 4   | Shall have at least 16-bit ADC and DAC                                | Spec Constraint   |
| 5   | Maximum of 2 input signal sources                                     | Device Constraint |
| 6   | Maximum of 2 output signals                                           | Device Constraint |
| 7   | Shall receive serial data from a general purpose computer             | Design Constraint |
| 8   | Maximum of 1064 kB of usable internal memory                          | Device Constraint |
| 9   | Shall not store audio data for more than 200 ms                       | Ethics Constraint |
| 10  | Shall turn off if the system reaches 60°C (140°F)                     | Safety Constraint |

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

