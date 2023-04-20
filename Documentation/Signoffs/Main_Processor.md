# Processing Subsystem

## Function of the Subsystem

##### Pseudo-Code Flowchart
<img src="/Documentation/Images/Main-Processor/Conceptual/MainSubsystemFlow.png" width="60%" height="60%">

The goal of this subsystem is to process the input signal, and output an appropriate response to the ambient noise present in the room. The processing subsystem consists of an ADC converter which will take the input and convert it into digital samples which will be analyzed and processed by the adaptive filter algorithms. The output will then be converted using a DAC converter and outputted to the other parts of the system. The room will be sliced into sections of noise cancelling like the image below where the cyan represents an area of noise control. In total, there will be 2 main processing subsystems which will account for the 2 outermost windows in Brown 314. 

<img src="/Documentation/Images/Main-Processor/Conceptual/AreaOfEffect.png" width="60%" height="60%">

## Constraints

| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | System shall be powered by standard 60 Hz, 120 V wall outlets         | Design Constraint |
| 2   | Shall process and output with a max delay of 1.4 ms                   | Design Constraint |
| 3   | Shall have a sample rate of at least 40 kHz                           | Design Constraint |
| 4   | Shall have at least 16-bit ADC and DAC                                | Design Constraint |
| 5   | Minimum of 2 input signal sources                                     | Design Constraint |
| 6   | Minimum of 1 output signal source                                     | Design Constraint |
| 7   | Shall connect to and communicate FIR filter coefficients with the bluetooth connection subsystem | Design Constraint |
| 8   | Shall hold at least 2 seconds of samples per input signal             | Design Constraint |
| 9   | Shall not store audio data after processing                           | Ethics Constraint |

<sup>1</sup> In order to create a system that can run for long periods of time, the system must be able to be powered by the 60 Hz, 120 V wall outlets in the room. This would elimate the need for batteries which could drain.

<sup>2</sup> The speaker has to output as soon as the targeted sound physically reaches it. In order to prevent the system from being in the impeding movement, the speakers will not be allowed to extend half of a meter away from the windows. Using this max distance and the speed of sound, the maximum delay allowed by the system can be found.

<sup>3</sup> Nyquist's theorem states a signal must be sampled at more than twice the highest frequency of the signal to prevent aliasing. The range of audible frequencies of a human's ear is 20 kHz. The system must therefore sample at a minimum rate of 40 kHz in order to be able to process all sounds a human can hear. 

<sup>4</sup> As bit depth increases, quantization noise decreases. In order to properly model and output the dynamic range of heavy machinery, at least 100 dB SPL [6] (sound pressure level) must be accounted for. The dynamic range minus the sensitivity of the mic gives us the quantization-noise. A decent approximation for the SQNR (signal-to-quantization-noise ratio) can be found using $4.77+6.02N-F(dB)$ where $F(dB)$ is the crest factor of a signal is decibels. Substituting 16 bits for $N$ and the crest factor for a sin wave (as is customary for microphone datasheets) a SQNR of 100 dB is acheived. This would allow the system to use lower sensitivity microphones.

<sup>5</sup> The filtered-x LMS (least mean square) algorithm is a common and popular algorithm for adaptive active noise control [7]. The algorithm requires the input signal being targeted along with an error signal. Therefore, at least 2 input signals are required. 

<sup>6</sup> In order to cancel the targeted sound, an acoustic response has to be played through a speaker that is the anti-noise. In order to output the processed data to the speaker, at least one output port has to be included on the board.

<sup>7</sup> Each window will require at least one DSP board in order to allow speedy calculations. Since the machine learning aspect of the adapting algorithm is computationally expensive, this subsystem will receive the ML processed data from the bluetooth connection subsystem. The bluetooth connection subsystem will have the function of connecting the DSP board to external peripherals through bluetooth. This will allow the DSP board to focus on the time dependent task of filtering and negating the input sound.

<sup>8</sup> The system operates using digital filters. These filters require arrays of previous samples in order to account for the acoustical impulse response of the room. Approximate impulse responses of the room were simulated which showed the majority of the impulse responses power should have decayed by 2 seconds [8]. 

<sup>9</sup> In order to create a system that does not invade the privacy of the students and teachers in the room, the system will not store any sound data after it is used in processing. This will prevent the system from possibly storing private conversations that could be breached.

## Buildable schematic

![image](/Documentation/Images/Main-Processor/Buildable-Schematics/DSPBOARD_REV3.png)

The above image is a schematic of the ADSP-BF706 EZ-KIT Mini, the schematic focuses on the most important aspects of ths device with respect to the overall design goal. The schematic shows stereo input and output ports along with a micro USB input and the subsystems that will be connected to this device.  

## Analysis

#### Input
The system will receive two analog signals through the stereo jack<sup>5</sup>. The two channels will be separated and wired to the measured input and error input subsystems [9][10]. These signals are then sent to the ADAU1761 SigmaDSP low power stereo audio codec which features 24-bit stereo audio ADC and DAC<sup>4</sup>. Each channel has it's own dedicated ADC and DAC allowing the signals to remain separate [11]. The rated signal to noise ratio is >98 dB SNR. The system also samples at 48 kHz<sup>3</sup>.The digital samples are then sent to the respective delay line. As each sample is received, the oldest sample in the processor is erased<sup>9</sup>.



#### Power
The system has to be powered through a USB port connection. The system can be powered from wall power through a USB charger<sup>1</sup>. USB 2.0 interfaces run off of 5 volts and have a max current draw of 500 mA, for a max power draw of 2.5 Watts. To power the device through the USB connected to the processor, the jumper J2 needs to connect the 5V pin to the 706 pin. Since the board also needs to use the USB port in order to install the designed software, the system will have to be programmed using it's One Time Programmable (OTP) memory as to allow the system to boot without being connected directly to a computer. 

#### Speed and Memory
The system has the ADSP-BF706 Blackfin processor on board. This processor has a clock speed of 400 MHz, and a multiply-accumulate (MAC) instruction per second speed of 800 million at max clock speed. The ADSP-BF706 has 64 kB usable SRAM internally plus an additional 1 MB of SRAM. The ADSP-BF706 allows both 16-bit and 32-bit MAC instructions. The filtered-X least mean squares algorithm being used requires $IJ(K+1)L+JKM+Imax(L,M+1)+K$ words of memory. I is the number of inputs signals, J is the number of output signals, and K is the number of error signals. L is the control filter length and M is the length of the estimated Plant FIR Filter being recieved from the USB interface. Allowing L and M being roughly equal, we can find the maximum size of filters we can use using the internal memory. I,J, and K will be set to 1.

$$1064 \text{kB} /2 \text{Bytes} = 532000 \text{ 16-bit words } = 1(1+1) + M + M + 1 + 1 = 4 + 2 M $$

$$ M = 265998 \text{ samples } = L $$ 

265998 samples per filter allow us to have approximately 5.54 s for our acoustic response<sup>9</sup>. The number of MAC instructions needed by the algorithm is solved by $IJK(L+M)+K$ MACs per filter update. The 2 second minimum for the impulse response equates to 96000 samples. Using L equal to M equal to our minimum needed amount of samples gets:

$$ 1(2 \times 96000) + 1 = 192001 \text{ MACs } $$

$$192001 \text{ MACs/Coefficent Update } \times \frac{1 s}{800 \text{Million MACs}} = 240 \mu s $$

240 microseconds is below the 1.4 milliseconds before the next sample input<sup>2</sup>. This means the system could do an update in real time. Adding extra time for memory instructions, the system could still run close to real time, and below the max delay of 1.4 ms.

The digital output is then converted back to an analog stereo signal<sup>6</sup>. This allows two channels of output. Both channels of the system will be equal and will be sent to an array of speakers. 

#### Bluetooth Connection Subsystem Connectivity {Will update when referenced Subsystem is complete}
The Blackfin ADSP-BF70x EZ-KIT Mini is built for direct connectivity to an arduino uno or related board. The board has a corresponding through-hole for input/output port of an arduino uno or related board. It is able to directly stack on top using 0.1" header pins. This will allow the main processing subsystem to communicate via SPI with the bluetooth connection subsystem<sup>7</sup>.

## BOM
| DEVICE            | Quantity | Price Per Unit | Total Price |
| ----------------- | -------- | -------------- | ----------- |
| ADSP-BF706-EZMINI | 2        | $88.31         | $176.62     |

## References

[1] Analog Devices, "Blackfin ADSP-BF70x Ultralow Power, Low Cost DSP Evaluation Platform ADSP-BF706 EZ-KIT Mini" ADSP-BF706 EZ-KIT Mini, 2015, https://www.analog.com/media/en/news-marketing-collateral/product-highlight/Blackfin-ADSP-BF706_MINI.pdf (accessed Apr. 4, 2023).

[2] Analog Devices, "Blackfin+ Core Embedded Processor" Blackfin, Blackfin+, and the Blackfin logo are registered trademarks of Analog Devices, Inc. Blackfin+ Core Embedded Processor ADSP-BF700/701/702/703/704/705/706/707, February 2019.

[3] Analog Devices. "SigmaDSP Stereo, Low Power, 96 kHz, 24-Bit Audio Codec with Integrated PLL" ADAU1761 Datasheet, 2009-2018.

[4] “Room Impulse Response Simulation with Stochastic Ray Tracing - MATLAB & Simulink,” www.mathworks.com. https://www.mathworks.com/help/audio/ug/room-impulse-response-simulation-with-stochastic-ray-tracing.html (accessed Apr. 15, 2023).

[5] S. Gaur and V. K. Gupta, “A Review on Filtered-X LMS Algorithm,” International Journal of Signal Processing Systems, vol. 4, no. 2, 2015, doi: https://doi.org/10.12720/ijsps.4.2.172-176.
‌
‌[6] [“Understanding microphone sensitivity,” Understanding Microphone Sensitivity | Analog Devices. [Online]. Available: https://www.analog.com/en/analog-dialogue/articles/understanding-microphone-sensitivity.html. [Accessed: 17-Apr-2023]. 

[7] S. C. Douglas, “Fast implementations of the filtered-x LMS and LMS algorithms for multichannel active noise control,” IEEE Transactions on Speech and Audio Processing, vol. 7, no. 4, pp. 454–465, 1999. 

[8] [Link to Simulation Results](/Documentation/Images/Main-Processor/Simulation-Results/)

[9] [Link to Error Subsystem {Broken Link until other signoffs are done}](/Documentation/Signoffs/)

[10] [Link to Input Subsytem {Broken Link until other signoffs are done}](/Documentation/Signoffs/)

[11] “ADAU1761,” Datasheet and Product Info | Analog Devices, 17-Sep-2010. [Online]. Available: https://www.analog.com/en/products/adau1761.html. [Accessed: 19-Apr-2023]. 
