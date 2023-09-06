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
| 8   |  The input subsystem and error subsystem will utilize the same components for more ease in comparison  | System Requirements |

       




 
 
 #### 1.)	Input microphone shall measure acoustic vibrations through the medium. [ Input subsystem functionality requirement]

The goal of the system is to cancel noise from the outside, in order for this to be accomplished, a device must be able to measure the sound vibrations through the physical medium. The electret microphone can read the sound vibrations through a medium. The electret microphone utilizes a diaphragm, capacitor, and JFET to generate a varying voltage which is then output to a pre-amplifier[2]. This input system will utilize the CMA-4544PF-W electret microphone from CUI Inc. [1].

#### 2.) The input microphone shall be able to measure input frequencies from 20 Hz to 20 kHz. [Origin: Device Constraints]

The frequencies a human can hear are in the range of 20 Hz – 20 kHz. The electret microphone CMA-4544PF-W from CUI Inc. [2]. meets these expectations by providing the ideal frequency range of 20 Hz – 20 kHz [1].

#### 3.) The output signal should not be higher than 3.3 Vp-p to prevent clipping. [Origin: Device Constraints]



#### 4.) System must be powered by standard wall outlets. [Origin: System Requirements]

In order to make powering the system less difficult, the team has decided using a standard wall-wart which converts 120 VAC to 5 VDC would be appropriate for this application. The system overall will be powered by the same 5 VDC signal.

#### 5.) The primary input sensor must output a continuous-time voltage signal. [Origin: System Requirements]

The input to the processing subsystem is designed to receive a continuous-time analog voltage signal, therefore in order for the processing subsystem to function as needed the output of the input subsystem must be a continuous-time analog voltage signal.

#### 6.) The preset gain must be set to 40 dB [Origin: Device Constraints]
In order for the input subsystem to properly be compared with the data from the error mic the gain on both devices should have the same preset, for the error mic subsystem the maximum gain possible is 40 dB, therefore the input subsystem must also have a gain of 40 dB.

#### 7.) The overall system delay must be less than or equal to 1.4 ms. [Origin: System Requirements]
In order for the system to properly function the targeted sound must be canceled within the maximum possible delay time. If the speaker is assumed to be 0.5 m away and the velocity of sound is assumed to be 343 m/s the maximum delay that the system can have is 1.4 ms. The processing subsystem takes a total of 1.2 ms in the worst case scenario to process, which leaves 0.2 ms for the rest of the system.

#### 8.) The input subsystem and error subsystem will utilize the same components for more ease in comparison. [Origin: System Requirements]
In order to ensure discrepancies caused by a different input subsystem does not occur between the input and error subsystems, it has been decided to utilize the same electrical design for the input subsystem that is used in the error subsystem.


# Buildable Schematic
![Schematic](https://github.com/CarsonDPope/Active-Noise-Control-With-Wall-Transmission-Detection/assets/123108478/cc9dcc09-5883-4b78-88fd-e7f5f3cbd2b3)
  



# Analysis

#### Component Details

##### CMA-4544PF-W (Electret Microphone)
The CMA-4544PF-W is the electret microphone used in the overall microphone amplifier circuit. This microphone has an SNR of 60 dBA with an operating voltage from 3 VDC to 10 VDC. The signal-to-noise ratio is relatively high, meaning there is very little noise in the output signal, which is heavily needed in a noise cancellation application [2].

##### TS472 Very Low Noise Microphone Amplifier
The TS472 microphone amplifier from ST microelectronics will amplify the voltage signal produced from the CMA-4544PF-W. The output of this amplifier is differential and consists of an OUT+ pin and an OUT- pin The TS472 very low noise microphone preamplifier from ST microelectronics satisfies constraint (4) by having a maximum supply voltage rating of 6 V while having a maximum current draw of 2.4 mA [4], therefore the microphone preamplifier can be driven by a standard 5 VDC input. The overall delay of the TS472 is 20 us, with the total alloted delay amount being 0.1 ms, this meets constraint (7). The TS472 will output a continuous time voltage signal to the LM741 circuit designed in differential configuration so it can accurately recieve the analog signal from the differential outputs on the TS472. The preset gain can be set to 40 dB by connecting 68 $\Omega$, matching the gain of the error subsystem.

#### TS472 Component calculations
The various required components that need to be connected to different pins on the TS472 must be calculated.
(Need to ask about R1,2 calculations i.e. IDSS = 0.5 mA at 3 Vdc Rl = 2.2 kiloohms)
In order to make sure that the frequency response is correct based on constraint (2) the capacitive elements must be designed to meet a lower cut off frequency of 20 Hz and a higher cut off frequency of 20 KHz. For C1 and C2 shown in the buildable schematic the manufacturer provides a method for calculating them based on the desired lower cutoff frequency the following equation is able to calculate this:
```math 
C_{in} = \frac{1} {2 π*F_{CL}*100*10^3}$ 
```
Where FCL is the desired lower corner frequency and Cin represents the values of C1 and C2 respectively, and 100*10^3 represents the 100 $k\Omega$ input impedance which acts like a high-pass filter [4].
Performing this calculation leads to the required capacitance values for C1 and C2 being 79.5 nF, 80 nF is the closest actual component value to this calculated value so a 80 nF capacitor will be utilized for C1 and C2.
The output capacitors (C5 and C6) can be calculated by using the required higher cut off frequency of 20 kHz. Using the following equation provided by the manufacturer:
 ```math
  F_{CH} =  \frac {1} {(2 π *40*10^3) * (C_{5,6}+100*10^{-12})}
 ```
Solving for C5 and C6 leads to a capacitance value of roughly 100 pF at 20 kHz, therefore the required component value for C5 and C6 is 100 pF.

##### LM741 Circuit in Differential Configuration


# Bill of Materials 
| DEVICE                                             | Quantity | Price Per Unit |  Price  | Total   |
|----------------------------------------------------|----------|----------------|---------|---------|
| STMicroelectronics TS472                           | 2        | $7.95          | $15.90  | $16.64  |
| Texas Instruments LM741                            | 2        | $0.37          | $0.74   |


# References

[1] Alldatasheet.com, “CMA-4544PF-W Datasheet(PDF) - CUI Inc.,” ALLDATASHEET.COM - Electronic Parts Datasheet Search. [Online]. Available: https://www.alldatasheet.com/datasheet-pdf/pdf/238630/CUI/CMA-4544PF-W.html. [Accessed: 16-Apr-2023]. 

[2] Swagatam, “How electret microphones work - full tutorial and Diagram,” Homemade Circuit Projects, 05-Apr-2020. [Online]. Available: https://www.homemade-circuits.com/how-electret-microphone-works/. [Accessed: 16-Apr-2023].  

[3] “Aluminum electrolytic capacitors UKL low leakage current - nichicon.co.jp.” [Online]. Available:          https://www.nichicon.co.jp/english/series_items/catalog_pdf/e-ukl.pdf. [Accessed: 22-Apr-2023]. 

[4] “TS472,” STMicroelectronics, https://www.st.com/en/audio-ics/ts472.html (accessed Aug. 31, 2023). 








