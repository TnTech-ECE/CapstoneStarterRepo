# Input Subsystem
![image](https://user-images.githubusercontent.com/123108478/232335159-9e5c57ee-099e-4713-ae00-44db177d7364.png)

#### Figure 1: Diagram of input subsystem

The goal of the input subsystem is to accurately take in the noise input from the wall and transmit it to the processing subsystem.
# Constraints

#### 1.)	Input microphone shall measure acoustic vibrations through the medium. [Origin: Input subsystem functionality requirement]

The goal of the system is to cancel noise from the outside, in order for this to be accomplished, a device must be able to measure the sound vibrations through the physical medium. The electret microphone can read the sound vibrations through a medium. The electret microphone utilizes a diaphragm, capacitor, and JFET to generate a varying voltage which is then output to a pre-amplifier. This input system will utilize the CMA-4544PF-W electret microphone from CUI Inc.

#### 2.) The input microphone shall be able to measure input frequencies from 100 Hz to 17 kHz. [Origin: Device Constraints and Human Biology]

The frequencies a human can hear are in the range of 20 Hz – 20 kHz. Most humans, however, cannot hear 20 kHz; therefore, a more appropriate constraint is 100 Hz to 17 kHz. This covers most human hearing. The electret microphone CMA-4544PF-W from CUI Inc. exceeds these expectations by providing the ideal frequency range of 20 Hz – 20 kHz.
#### 3.) The output signal should not experience large clipping. [Origin: Device Constraints]

For the processing system to properly analyze the output signal from the input subsystem, there must be minimal clipping in the output signal. The Automatic gain control functionality in the amplifier utilized in the input subsystem fixes this issue. The amplifier used is the MAX9814 amplifier from maxim integrated. The output voltage is preset to a certain value based on the gain, whenever the system experiences a gain that is larger than the preset value, the AGC in the MAX9814 will then reduce the gain back to the preset value in an appropriate amount of time to prevent excessive clipping.

# Buildable Schematic

![image](https://user-images.githubusercontent.com/123108478/232346714-6ca250ec-df65-4506-99bc-fc4f5bf4eb51.png)

The buildable schematic above utilizes the pins on the Adafruit Technologies AGC Electret Microphone Amplifier. The first pin is the Attack/Release Ratio, which is the ratio between the attack time and the release time. The output pin will be connected to the processing subsystem and decoupled through a 1 uF to 100 uF capacitor. The gain pin will be connected to ground to allow for a 50 dB gain. The amplifier will be driven on the VDD pin by a 5V DC signal, to allow it to be easily powered by a conventional wall-wart.

# Analysis

#### Component Details
The overall Adafruit Technologies AGC Electret Microphone Amplifier is broken into two main components, the electret microphone and the pre-amplifier.

##### CMA-4544PF-W (Electret Microphone)
The CMA-4544PF-W is the electret microphone used in the overall microphone amplifier circuit. This microphone has an SNR of 60 dBA with an operating voltage from 3 V dc to 10 V dc. The signal-to-noise ratio is relatively high, meaning there is very little noise in the output signal, which is heavily needed in a noise cancellation application. 

###### MAX9814 (Microphone Amplifier chip)
The MAX9814 microphone amplifier is a cheap, high grade microphone amplifier which features automatic gain control (AGC) and a low-noise microphone bias.
The operating voltage (VDD) of the amplifier is 3.3 V dc to 5.5 V dc. The SNR is around 60 dB which means the output signal has a low noise value. The amplifier has three preset gains which are controlled by the user. The maximum gain preset (60 dB) is the default value and requires no connections. The second highest preset gain, (50 dB) is set by connecting the gain pin to ground. The lowest preset (40 dB) is set by connecting the gain pin to VDD. The advantage of utilizing an amplifier with automatic gain control is the advantage of minimal to no clipping occuring on the output signal and not having to readjust the gain consistently. The A/R (Attack time to Release time ratio) is able to be set to 1:4 (default no connection), 1:2 (connected to VDD) and 1:5 (connected to GND). Attack time is defined as the time it takes for the AGC to reduce the gain after the gain has exceeded the preset level. A shorter attack time is much more advantageous for sudden spikes in gain (impulses) in the system. Release time is defined as the time it takes for the signal to fall below the level defined preset gain after the hold time has ended. The hold time is the delay before the release time is initiated. A large A/R will lead to higher signal quality while sacrificing speed. A smaller A/R will lead to higher speed at the sacrifice of signal quality. Therefore, for our noise cancellation application using the default setting (1:4) would be most appropriate since the signal quality will be acceptable and the speed will be relatively high.

# References







