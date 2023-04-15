# Processing Subsystem

## Function of the Subsystem

##### Pseudo-Code Flowchart
<img src="https://user-images.githubusercontent.com/123997954/229912784-1174c224-1c0f-4fb9-8a78-3f503ecb81d3.png" width="60%" height="60%">

The goal of this subsystem is to process the input signal, and output an appropriate response to the ambient noise present in the room. The processing subsystem consists of an ADC converter which will take the input and convert it into digital samples which will be analyzed and processed by the adaptive filter algorithms. The output will then be converted using a DAC converter and outputted to the other parts of the system. The room will be sliced into sections of noise cancelling like the image below where the cyan represents an area of noise control..

<img src="https://github.com/CarsonDPope/Active-Noise-Control-With-Wall-Transmission-Detection/blob/CarsonDPope-patch-1/Documentation/Images/AreaOfEffect.png" width="60%" height="60%">

## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | System shall be powered by standard wall outlets                      | Spec Constraint   |
| 2   | Shall process and output with a max delay of 1.4 ms*                  | Design Constraint |
| 3   | Shall have a sample rate of at least 40 kHz                           | Spec Constraint   |
| 4   | Shall have at least 16-bit ADC and DAC                                | Spec Constraint   |
| 5   | Minimum of 2 input signal sources                                     | Design Constraint |
| 6   | Minimum of 1 output signals                                           | Design Constraint |
| 7   | Shall receive serial data from a general purpose computer**           | Design Constraint |
| 8   | Shall hold at least 2 seconds of samples per input signal***          | Design Constraint |
| 9   | Shall not store audio data after processing                           | Ethics Constraint |

\* The speaker has to output as soon as the targeted sound physically reaches it. In order to prevent the system from being in the impeding movement, the speakers will not be allowed to extend half of a meter away from the windows. Using this max distance and the speed of sound, the maximum delay allowed by the system can be found.

** Each window will require at least one DSP board in order to allow speedy calculations. Since the machine learning aspect of the adapting algorithm is computationally expensive, this subsystem will receive the ML processed data from a general purpose computer using a serial data interface. This will allow the DSP board to focus on the time dependent task of filtering and negating the input sound. 

*** The system operates using digital filters. These filters require arrays of previous samples in order to account for the acoustical impulse response of the room. Approximate impulse responses of the room were simulated which showed the majority of the impulse responses power should have decayed by 2 seconds. 

## Buildable schematic

![image](https://github.com/CarsonDPope/Active-Noise-Control-With-Wall-Transmission-Detection/blob/66765be4ab018f4d5479051bf008aac47a2c0ad8/Documentation/Images/DSPBOARD_REV1.png)
The above image is a schematic of the ADSP-BF706 EZ-KIT Mini, the schematic focuses on the most important aspects of ths device with respect to the overall design goal. The schematic shows stereo input and output ports along with a micro USB input and the subsystems that will be connected to this device.  

## Analysis

#### Input
The system will receive two analog signals through the stereo jack [5]. These signals are then sent to the ADAU1761 SigmaDSP low power stereo audio codec which features 24-bit stereo audio ADC and DAC [4]. The rated signal to noise ratio is >98 dB SNR. The system also samples at 48 kHz [3].The digital samples are then sent to the respective delay line. As each sample is received, the oldest sample in the processor is erased [9].

#### Power
The system has to be powered through a USB port connection. This will both power and send the data to the processor during boot. The system can be powered from wall power through a USB charger [1]. USB 2.0 interfaces run off of 5 volts and have a max current draw of 500 mA, for a max power draw of 2.5 Watts. To power the device through the USB connected to the processor, the jumper J2 needs to connect the 5V pin to the 706 pin. Since the board also needs to use the USB port in order to install the designed software, the system will have to be programmed using it's One Time Programmable (OTP) memory as to allow the system to boot without being connected directly to a computer. 

#### Speed and Memory
The system has the ADSP-BF706 Blackfin processor on board. This processor has a clock speed of 400 MHz, and a multiply-accumulate (MAC) instruction per second speed of 800 million at max clock speed. The ADSP-BF706 has 64 kB usable SRAM internally plus an additional 1 MB of SRAM. The ADSP-BF706 allows both 16-bit and 32-bit MAC instructions. The filtered-X least mean squares algorithm being used requires $IJ(K+1)L+JKM+Imax(L,M+1)+K$ words of memory. I is the number of inputs signals, J is the number of output signals, and K is the number of error signals. L is the control filter length and M is the length of the estimated Plant FIR Filter being recieved from the USB interface. Allowing L and M being roughly equal, we can find the maximum size of filters we can use using the internal memory. I,J, and K will be set to 1.

$$1064 \text{kB} /2 \text{Bytes} = 532000 \text{ 16-bit words } = 1(1+1) + M + M + 1 + 1 = 4 + 2 M $$

$$ M = 265998 \text{ samples } = L $$ 

265998 samples per filter allow us to have approximately 5.54 s for our acoustic response [8]. The number of MAC instructions needed by the algorithm is solved by $IJK(L+M)+K$ MACs per filter update. The 2 second minimum for the impulse response equates to 96000 samples. Using L equal to M equal to our minimum needed amount of samples gets:

$$ 1(2 \times 96000) + 1 = 192001 \text{ MACs } $$

$$192001 \text{ MACs/Coefficent Update } \times \frac{1 s}{800 \text{Million MACs}} = 240 \mu s $$

240 microseconds is below the 1.4 milliseconds before the next sample input [2]. This means the system could do an update in real time. Adding extra time for memory instructions, the system could still run close to real time, and below the max delay of 1.4 ms.

The digital output is then converted back to an analog stereo signal [6]. This allows two channels of output. Both channels of the system will be equal and will be sent to an array of speakers. 

## BOM
| DEVICE            | Quantity | Price Per Unit | Total Price |
| ----------------- | -------- | -------------- | ----------- |
| ADSP-BF706-EZMINI | 3        | $88.31         | $264.93     |

## References

Analog Devices, "Blackfin ADSP-BF70x Ultralow Power, Low Cost DSP Evaluation Platform ADSP-BF706 EZ-KIT Mini" ADSP-BF706 EZ-KIT Mini, 2015, https://www.analog.com/media/en/news-marketing-collateral/product-highlight/Blackfin-ADSP-BF706_MINI.pdf (accessed Apr. 4, 2023).

Analog Devices, "Blackfin+ Core Embedded Processor" Blackfin, Blackfin+, and the Blackfin logo are registered trademarks of Analog Devices, Inc. Blackfin+ Core Embedded Processor ADSP-BF700/701/702/703/704/705/706/707, February 2019.

Analog Devices. "SigmaDSP Stereo, Low Power, 96 kHz, 24-Bit Audio Codec with Integrated PLL" ADAU1761 Datasheet, 2009-2018.

“Room Impulse Response Simulation with Stochastic Ray Tracing - MATLAB & Simulink,” www.mathworks.com. https://www.mathworks.com/help/audio/ug/room-impulse-response-simulation-with-stochastic-ray-tracing.html (accessed Apr. 15, 2023).

S. Gaur and V. K. Gupta, “A Review on Filtered-X LMS Algorithm,” International Journal of Signal Processing Systems, vol. 4, no. 2, 2015, doi: https://doi.org/10.12720/ijsps.4.2.172-176.
‌
‌
