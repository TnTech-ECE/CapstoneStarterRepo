# Input Subsystem
![image](https://user-images.githubusercontent.com/123108478/232335159-9e5c57ee-099e-4713-ae00-44db177d7364.png)

  #### Figure 1: Diagram of input subsystem
  

The goal of the input subsystem is to accurately take in the noise input from the wall and transmit it to the processing subsystem.
# Constraints
| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1   | Input microphone shall measure acoustic vibrations through the medium.          | Input subsystem functionality requirement |
| 2   | The input microphone shall be able to measure input frequencies from 20 Hz to 20 kHz.                 | Device constraints|
| 3   | The output signal should not be higher than 3.3 Vp-p to prevent clipping.                          | Device Constraints |
| 4   | System must be powered from a 120 V 60 Hz wall outlet                        | System Requirements |
| 5   |  The primary input sensor shall output a continuous-time analog voltage signal   | System Requirements |
| 6   |  The preset gain must be set to 40 dB   | Device Constraints |
| 7   |  The overall system delay must be less than or equal to 1.4 ms  | System Requirements |

       




 
 
 #### 1.)	Input microphone shall measure acoustic vibrations through the medium. [ Input subsystem functionality requirement]

The goal of the system is to cancel noise from the outside, in order for this to be accomplished, a device must be able to measure the sound vibrations through the physical medium. The electret microphone can read the sound vibrations through a medium. The electret microphone utilizes a diaphragm, capacitor, and JFET to generate a varying voltage which is then output to a pre-amplifier[3]. This input system will utilize the CMA-4544PF-W electret microphone from CUI Inc. [2].

#### 2.) The input microphone shall be able to measure input frequencies from 20 Hz to 20 kHz. [Origin: Device Constraints]

The frequencies a human can hear are in the range of 20 Hz – 20 kHz. The electret microphone CMA-4544PF-W from CUI Inc. [2]. meets these expectations by providing the ideal frequency range of 20 Hz – 20 kHz [2].

#### 3.) The output signal should not be higher than 3.3 Vp-p to prevent clipping. [Origin: Device Constraints]

For the processing system to properly analyze the output signal from the input subsystem, there must be minimal clipping in the output signal. The Automatic gain control functionality in the amplifier utilized in the input subsystem fixes this issue. The amplifier used is the MAX9814 amplifier from Maxim Integrated [4]. The output voltage is preset to a certain value based on the gain, whenever the system experiences a gain that is larger than the preset value, the AGC in the MAX9814 will then reduce the gain back to the preset value in an appropriate amount of time to prevent excessive clipping [4]. This feature coupled with the fact the maximum amplitude on the output is at most 2 Vp-p [1],  leads to it meeting the 3.3 Vp-p limit on the processor board due to the power supply voltage of 3.3 V.

#### 4.) System must be powered by standard wall outlets. [Origin: System Requirements]

In order to make powering the system less difficult, the team has decided using a standard wall-wart which converts 120 VAC to 5 VDC would be appropriate for this application. The system overall will be powered by the same 5 VDC signal. The VDD pin which drives the MAX9814 amplifier has a VDD range of 2.7 VDC - 5.5 VDC [4]. This will allow the input subsystem to be easily powered.

#### 5.) The primary input sensor must output a continuous-time voltage signal. [Origin: System Requirements]

The input to the processing subsystem is designed to receive a continuous-time analog voltage signal, therefore in order for the processing subsystem to function as needed the output of the input subsystem must be a continuous-time analog voltage signal.

#### 6.) The preset gain must be set to 40 dB [Origin: Device Constraints]
In order for the input subsystem to properly be compared with the data from the error mic the gain on both devices should have the same preset, for the error mic subsystem the maximum gain possible is 40 dB and the MAX9814 amplifier has the capability to be set to a preset gain of 40 dB, therefore this gain will be utilized [4].

#### 7.) The overall system delay must be less than or equal to 1.4 ms. [Origin: System Requirements]


# Buildable Schematic
  

![image](https://user-images.githubusercontent.com/123108478/233858831-4fdc520f-1512-4737-b4ba-90fc9c4a7494.png)


  #### Figure 2: Planned connections utilized from pins on Adafruit AGC Electret Microphone Amplifier-MAX9814
  

The buildable schematic in Figure 2 utilizes the pins on the Adafruit Technologies AGC Electret Microphone Amplifier [1]. The first pin is the Attack/Release Ratio, which is the ratio between the attack time and the release time [4]. The output pin will be connected to the channel 1 stereo input and decoupled through a 1 uF capacitor from nichion [6]. An output capacitance range of 1 uF - 100 uF is specified by the manufacturer [1]. The gain pin will be connected to ground to allow for a 50 dB gain. The amplifier will be driven on the VDD pin by a 5 VDC signal, to allow it to be easily powered by a conventional wall-wart [5].

# Analysis

#### Component Details
The overall Adafruit Technologies AGC Electret Microphone Amplifier is broken into two main components, the electret microphone and the pre-amplifier.

##### CMA-4544PF-W (Electret Microphone)
The CMA-4544PF-W is the electret microphone used in the overall microphone amplifier circuit. This microphone has an SNR of 60 dBA with an operating voltage from 3 VDC to 10 VDC. The signal-to-noise ratio is relatively high, meaning there is very little noise in the output signal, which is heavily needed in a noise cancellation application [2].

##### MAX9814 (Microphone Amplifier chip)
The MAX9814 microphone amplifier from Maxim Integrated [4], is a cheap, high grade microphone amplifier which features automatic gain control (AGC) and a low-noise microphone bias.
The operating voltage (VDD) of the amplifier is 3.3 VDC to 5.5 VDC. The SNR is around 60 dB which means the output signal has a low noise value. The amplifier has three preset gains which are controlled by the user. The maximum gain preset (60 dB) is the default value and requires no connections. The second highest preset gain, (50 dB) is set by connecting the gain pin to ground. The lowest preset (40 dB) is set by connecting the gain pin to VDD. The gain will be set to 40 dB to meet constraint 6. The advantage of utilizing an amplifier with automatic gain control is the advantage of minimal to no clipping occuring on the output signal and not having to readjust the gain consistently. The A/R (Attack time to Release time ratio) is able to be set to 1:4000 (default no connection), 1:2000 (connected to VDD) and 1:500 (connected to GND). Attack time is defined as the time it takes for the AGC to reduce the gain after the gain has exceeded the preset level. A shorter attack time is much more advantageous for sudden spikes in gain (impulses) in the system. Release time is defined as the time it takes for the signal to fall below the level-defined preset gain after the hold time has ended. The hold time is the delay before the release time is initiated. A large A/R will lead to higher signal quality while sacrificing speed. A smaller A/R will lead to higher speed at the sacrifice of signal quality. Therefore, for our noise cancellation application using the default setting (1:4000) would be most appropriate since the signal quality will be acceptable and the speed will be relatively high [4]. The maximum supply current (IDD) is 6 mA [4], and the input impedance (Zin) is 100 $k\Omega$ [4]. The output impedance (Zout) is 50 $\Omega$.
# Bill of Materials 
| DEVICE                                             | Quantity | Price Per Unit |  Price  | Total   |
|----------------------------------------------------|----------|----------------|---------|---------|
| Adafruit AGC Electret Microphone Amplifier MAX9814 | 2        | $7.95          | $15.90  | $16.64  |
| Nichion Electrolytic Capacitor ( 1 uF)             | 2        | $0.37          | $0.74   |


# References

[1] L. Ada, “Adafruit AGC Electret microphone amplifier - MAX9814,” Adafruit Learning System. [Online]. Available: https://learn.adafruit.com/adafruit-agc-electret-microphone-amplifier-max9814. [Accessed: 16-Apr-2023]. 

[2] Alldatasheet.com, “CMA-4544PF-W Datasheet(PDF) - CUI Inc.,” ALLDATASHEET.COM - Electronic Parts Datasheet Search. [Online]. Available: https://www.alldatasheet.com/datasheet-pdf/pdf/238630/CUI/CMA-4544PF-W.html. [Accessed: 16-Apr-2023]. 

[3] Swagatam, “How electret microphones work - full tutorial and Diagram,” Homemade Circuit Projects, 05-Apr-2020. [Online]. Available: https://www.homemade-circuits.com/how-electret-microphone-works/. [Accessed: 16-Apr-2023]. 

[4] Maxim Integrated, “Available microphone amplifier with AGC and low-noise microphone bias.” [Online]. Available: https://www.digchip.com/datasheets/download_datasheet.php?id=8775171&part-number=MAX9814. [Accessed: 16-Apr-2023]. 

[5] L. Ada, “Adafruit AGC Electret microphone amplifier - MAX9814,” Adafruit Learning System. [Online]. Available: https://learn.adafruit.com/adafruit-agc-electret-microphone-amplifier-max9814/wiring-and-test. [Accessed: 16-Apr-2023]. 

[6] “Aluminum electrolytic capacitors UKL low leakage current - nichicon.co.jp.” [Online]. Available:          https://www.nichicon.co.jp/english/series_items/catalog_pdf/e-ukl.pdf. [Accessed: 22-Apr-2023]. 






