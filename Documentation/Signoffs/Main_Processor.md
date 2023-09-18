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

![image](/Documentation/Images/Main-Processor/Buildable-Schematics/DSPBOARD_REV5.PNG)

The above image is a schematic of the ADSP-BF706 EZ-KIT Mini, the schematic focuses on the most important aspects of ths device with respect to the overall design goal. The schematic shows stereo input and output ports along with a micro USB input and the subsystems that will be connected to this device.  

## Analysis

#### Input
The system will receive two analog signals through the stereo jack<sup>5</sup>. The two channels will be separated and wired to the measured input and error input subsystems [9][10]. These signals are then sent to the ADAU1761 SigmaDSP low power stereo audio codec which features 24-bit stereo audio ADC and DAC<sup>4</sup>. Each channel has it's own dedicated ADC and DAC allowing the signals to remain separate [3]. The rated signal to noise ratio is >98 dB SNR. The system also samples at 48 kHz<sup>3</sup>.The digital samples are then sent to the respective delay line. As each sample is received, the oldest sample in the processor is erased<sup>9</sup>.



#### Power
The system has to be powered through a USB port connection. The system can be powered from wall power through a USB charger<sup>1</sup>. USB 2.0 interfaces run off of 5 volts and have a max current draw of 500 mA, for a max power draw of 2.5 Watts. To power the device through the USB connected to the processor, the jumper J2 needs to connect the 5V pin to the 706 pin. Since the board also needs to use the USB port in order to install the designed software, the system will have to be programmed using it's One Time Programmable (OTP) memory as to allow the system to boot without being connected directly to a computer. 

#### Speed and Memory

The main processing subsystem contains the ADSP-BF706 Blackfin DSP, which has an internal clock speed of 400 MHz. The multiply-accumulate (MAC) instruction is an integral part of digital signal processing. This instruction multiplies two operands and adds the result to a a running sum. These sets of actions can be used for the convolution of two time signals. The Blackfin architecture allows 16-bit and/or 32-bit MACs to be implemented in a single clock cycle, making it an ideal hardware for digital filtering. The BF706 can perform 800 million MACs per second at default clock speed [2]. 

The filtered-x LMS algorithm requires the current and previous samples for both the input and error signals. These samples are stored in arrays called delay lines. The size of these delay lines are determined by the acoustic impulse response of the room (that is the acoustical response of the room including reflections and diffusion). There are 96000 samples in 2 seconds at 48 kHz. Using 16-bit samples, this is equivalent to 187.5 kiB per delay line. 

An estimation of the number of MAC instructions needed per update by the filtered-x LMS algorithm can be found by the equation $IJK(L+M)+K$ [7]. I is the number of input channels, J is the number of output channels, and K is the number of error channels. In this case, all of the previous values are equal to 1. L and M are the control filter length and the length of the estimated acoustic impulse response respectively. Using an overestimation of L equal to M, the algorithm will approximately require 192001 MAC innstructions. At 800 millions MACs per second, this is equivalent to 240 microseconds of delay due to math operations.

A memory fetch clock cycle is 5 ns on the Blackfin. Assuming the same lengths of filters, memory fetching will cause approximately 960 microseconds of delay. This is assuming a memory fetch per filter coefficient. Implementing a circular buffer, where the write address of the incoming samples loops through the delay line, will bring the number of write instructions down to 1, one for the input sample as every other memory element will stay the same. The write delay is also 5 ns.

The delay for the ADC converter is shown to be 50 nanoseconds [3]. The delay for the DAC converter is shown to be 10 nanoseconds for setup and hold.

The overestimated total delay of the system will then be 240 $\mu s$ + 960 $\mu s$ + 50 $ns$ + 10 $ns$ + 5 $ns$ = 1.2 $ms$ which is below the 1.4 ms constraint<sup>2</sup>.

#### Bluetooth Connection Subsystem Connectivity {Will update when referenced Subsystem is complete}
The Blackfin ADSP-BF70x EZ-KIT Mini is built for direct connectivity to an arduino uno or related board. The board has a corresponding through-hole for input/output port of an arduino uno or related board. It is able to directly stack on top using 0.1" header pins. This will allow the main processing subsystem to communicate via SPI with the bluetooth connection subsystem<sup>7</sup>.

## BOM
| DEVICE            | Quantity | Price Per Unit | Total Price |
| ----------------- | -------- | -------------- | ----------- |
| ADSP-BF706-EZMINI | 2        | $88.31         | $176.62     |

## References

[1] Analog Devices, "Blackfin ADSP-BF70x Ultralow Power, Low Cost DSP Evaluation Platform ADSP-BF706 EZ-KIT Mini" ADSP-BF706 EZ-KIT Mini, 2015, https://www.analog.com/media/en/news-marketing-collateral/product-highlight/Blackfin-ADSP-BF706_MINI.pdf (accessed Apr. 4, 2023).

[2] Analog Devices, "Blackfin+ Core Embedded Processor" Blackfin, Blackfin+, and the Blackfin logo are registered trademarks of Analog Devices, Inc. Blackfin+ Core Embedded Processor ADSP-BF700/701/702/703/704/705/706/707, February 2019.

[3] “ADAU1761,” Datasheet and Product Info | Analog Devices, 17-Sep-2010. [Online]. Available: https://www.analog.com/en/products/adau1761.html. [Accessed: 19-Apr-2023]. 

[4] “Room Impulse Response Simulation with Stochastic Ray Tracing - MATLAB & Simulink,” www.mathworks.com. https://www.mathworks.com/help/audio/ug/room-impulse-response-simulation-with-stochastic-ray-tracing.html (accessed Apr. 15, 2023).

[5] S. Gaur and V. K. Gupta, “A Review on Filtered-X LMS Algorithm,” International Journal of Signal Processing Systems, vol. 4, no. 2, 2015, doi: https://doi.org/10.12720/ijsps.4.2.172-176.
‌
‌[6] [“Understanding microphone sensitivity,” Understanding Microphone Sensitivity | Analog Devices. [Online]. Available: https://www.analog.com/en/analog-dialogue/articles/understanding-microphone-sensitivity.html. [Accessed: 17-Apr-2023]. 

[7] S. C. Douglas, “Fast implementations of the filtered-x LMS and LMS algorithms for multichannel active noise control,” IEEE Transactions on Speech and Audio Processing, vol. 7, no. 4, pp. 454–465, 1999. 

[8] [Link to Simulation Results](/Documentation/Images/Main-Processor/Simulation-Results/)

[9] [Link to Error Subsystem {Broken Link until other signoffs are done}](/Documentation/Signoffs/)

[10] [Link to Input Subsytem {Broken Link until other signoffs are done}](/Documentation/Signoffs/)
