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
| 6   |  The preset gain must be set to 20 dB   | Device Constraints |
| 7   |  The overall system delay must be less than or equal to 1.4 ms  | System Requirements |
| 8   |  The input subsystem and error subsystem will utilize the same components for more ease in comparison  | System Requirements |

       




 
 
 #### 1.)	Input microphone shall measure acoustic vibrations through the medium. [ Input subsystem functionality requirement]

The goal of the system is to cancel noise from the outside, in order for this to be accomplished, a device must be able to measure the sound vibrations through the physical medium. The electret microphone can read the sound vibrations through a medium. The electret microphone utilizes a diaphragm, capacitor, and JFET to generate a varying voltage which is then output to a pre-amplifier[2]. This input system will utilize the CMA-4544PF-W electret microphone from CUI Devices sold through Digi-Key. [1].

#### 2.) The input microphone shall be able to measure input frequencies from 20 Hz to 20 kHz. [Origin: Device Constraints]

The frequencies a human can hear are in the range of 20 Hz – 20 kHz, therefore the frequency range of the noise cancellation devices should match this range.

#### 3.) The output signal should not be higher than 3.3 Vp-p to prevent clipping. [Origin: Device Constraints]
In order for the processing subsystem to not experience clipping the output signal from the input subsystem should be no greater than 3.3 Vpp due to the supply voltage of 3.3 V on the processing subsystem.


#### 4.) System must be powered by standard wall outlets. [Origin: System Requirements]

In order to make powering the system less difficult, the team has decided using a standard wall-wart which converts 120 VAC to 5 VDC would be appropriate for this application. The system overall will be powered by the same 5 VDC signal.

#### 5.) The primary input sensor must output a continuous-time voltage signal. [Origin: System Requirements]

The input to the processing subsystem is designed to receive a continuous-time analog voltage signal, therefore in order for the processing subsystem to function as needed the output of the input subsystem must be a continuous-time analog voltage signal.

#### 6.) The preset gain must be set to 20 dB [Origin: Device Constraints]
In order for the input subsystem to properly be compared with the data from the error mic the gain on both devices should have the same preset, for the error mic subsystem the maximum gain possible is 20 dB, therefore the input subsystem must also have a gain of 20 dB.

#### 7.) The overall system delay must be less than or equal to 1.4 ms. [Origin: System Requirements]
In order for the system to properly function the targeted sound must be canceled within the maximum possible delay time. If the speaker is assumed to be 0.5 m away and the velocity of sound is assumed to be 343 m/s the maximum delay that the system can have is 1.4 ms. The processing subsystem takes a total of 1.2 ms in the worst case scenario to process, which leaves 0.2 ms for the rest of the system.

#### 8.) The input subsystem and error subsystem will utilize the same components for more ease in comparison. [Origin: System Requirements]
In order to ensure discrepancies caused by a different input subsystem does not occur between the input and error subsystems, it has been decided to utilize the same electrical design for the input subsystem that is used in the error subsystem.


# Buildable Schematic
<img src="/Documentation/Images/input/image.png" width="75%" height="75%">

*Figure 1: Buildable Schematic for Input subsystem*



# Analysis

#### Component Details

##### CMA-4544PF-W (Electret Microphone)
The electret microphone CMA-4544PF-W from CUI Devices meets constraint (2) by providing the ideal frequency range of 20 Hz – 20 kHz [1]. The operating supply voltage range for the microphone is 3 VDC to 10 VDC. The microphone will be supplied from the power subsystem with a 5 VDC input. The CMA-4544PF-W microphone has a typical sensitivity of -44 dB at conditions defined by: Frequency = 1 kHz, 1 Pa, 0 dB = 1 V/Pa.
The typical voltage output would be found with the equation: $$20 log(x) = -44$$ where x equates to 6.31 mV. The minimum and maximum sensitivities are -46 dB and -42 dB which equate to 5.01 mV and 7.94 mV respectively. Using the maximum gain of 20 dB that the TS472 can achieve, we can expect the outputs to be within 50.1 mV and 79.4 mV. This will be put into the right side of the STEREO_IN defined in the main processor.   

##### TS472 Very Low Noise Microphone Amplifier
The TS472 microphone amplifier from ST microelectronics will amplify the voltage signal produced from the CMA-4544PF-W. The output of this amplifier is differential and consists of an OUT+ pin and an OUT- pin The TS472 very low noise microphone preamplifier from ST microelectronics satisfies constraint (4) by having a maximum supply voltage rating of 6 V while having a maximum current draw of 2.4 mA [3], therefore the microphone preamplifier can be driven by a standard 5 VDC input. The overall delay of the TS472 is 20 us, with the total alloted delay amount being 0.1 ms, this meets constraint (7). The TS472 will output a continuous time voltage signal to the operational amplifier circuit designed in differential configuration so it can accurately recieve the analog signal from the differential outputs on the TS472 [4]. The preset gain can be set to 20 dB by connecting 47 $k\Omega$, matching the gain of the error subsystem [3]. The maximum supply current for the TS472 is 2.4 mA, at 5 VDC the total output power that will have to be provided by the power subsystem is 12 mW.

#### TS472 Component calculations
The various required components that need to be connected to different pins on the TS472 must be calculated.
In order to make sure that the frequency response is correct based on constraint (2) the capacitive elements must be designed to meet a lower cut off frequency of 20 Hz and a higher cut off frequency of 20 KHz. For C1 and C2 shown in the buildable schematic the manufacturer provides a method for calculating them based on the desired lower cutoff frequency the following equation is able to calculate this:
```math 
C_{in} = \frac{1} {2 π*F_{CL}*100*10^3}$ 
```
Where FCL is the desired lower corner frequency and Cin represents the values of C1 and C2 respectively, and 100*10^3 represents the 100 $k\Omega$ input impedance which acts like a high-pass filter [3].
Performing this calculation leads to the required capacitance values for C1 and C2 being 79.5 nF, 80 nF is the closest actual component value to this calculated value so a 80 nF capacitor will be utilized for C1 and C2.
The output capacitors (C5 and C6) can be calculated by using the required higher cut off frequency of 20 kHz. Using the following equation provided by the manufacturer:
 ```math
  F_{CH} =  \frac {1} {(2 π *40*10^3) * (C_{5,6}+100*10^{-12})}
 ```
Solving for C5 and C6 leads to a capacitance value of roughly 100 pF at 20 kHz, therefore the required component value for C5 and C6 is 100 pF.

##### LM741 Circuit in Differential Configuration
The LM741 operational amplifier from Texas Instruments [4]. will be used to take the differential output from the TS472 and output a unity gain signal that will be sent to the processing system. An operational amplifier can be configured in a differential topology where the output voltage is represented by the following equation: $$V_{out} = \frac{R_{f}} {R_{1}}(V_{2}-V_{1})$$ [5]. R1 and Rf will be 1 $k\Omega$ to allow the gain (Rf/R1) to be equal to 1, the other required resistances in the circuit will also be equal to 1 $k\Omega$.  The two input voltages will be OUT+ and OUT- from the TS472 chip respectively, where OUT+ is the positive voltage signal and OUT- is the negative voltage signal [4]. The output voltage from the designed circuit will be in phase and unity gain version of (OUT+) - (OUT-). The maximum power consumption is 100 mW [4], which can be supplied by the power subsystem.

![image](https://github.com/CarsonDPope/Active-Noise-Control-With-Wall-Transmission-Detection/assets/123108478/eea79e97-25b2-4ab5-a34a-39b72bc1b45b)
*Figure 2: LT Spice design for LM741 amplifier*

The figure above shows an LT Spice version of the design. The OUT- pin in this case is set to a 1 kHz 1 V peak sine wave, while the OUT + pin is set to a 1 kHz 2 V peak sine wave. The output voltage therefore is expected to (OUT+) - (OUT-) 1 V peak at the same frequency. The output voltage should have unity gain and also be in phase with the inputs. 

![image](https://github.com/CarsonDPope/Active-Noise-Control-With-Wall-Transmission-Detection/assets/123108478/cdcd70a9-bfa2-49b5-b433-d2dd52a4c9ab)
*Figure 3: Out+ (red) vs. Vout (blue)*

The figure above shows the voltage from the OUT+ pin and the output voltage from the differential amplifier. The output voltage as expected is 1 V peak at 1 kHz. The OUT+ voltage and the output voltage are also in phase. The example values were used to illustrate how the differential amplifier will work and in most cases OUT- will be close to zero, therefore the differential amplifier then acts like a unity gain amplifier.


# Bill of Materials 
| DEVICE                                             | Quantity | Price Per Unit |  Price  | Total   |
|----------------------------------------------------|----------|----------------|---------|---------|
| STMicroelectronics TS472                           | 2        | $1.70          | $3.40   | $6.40   |
| LM741 Op-Amp                                       | 2        | $0.75          | $1.50   |         |
| CMA-4544PF-W Electret Microphone                   | 2        | $0.75          | $1.50   |         |



# References

[1] “CMA-4544PF-W: Digi-Key Electronics,” Digikey, https://www.digikey.com/en/products/detail/cui-devices/CMA-4544PF-W/1869981 [Accessed: 9-Sept-2023]. 

[2] Swagatam, “How electret microphones work - full tutorial and Diagram,” Homemade Circuit Projects, 05-Apr-2020. [Online]. Available: https://www.homemade-circuits.com/how-electret-microphone-works/. [Accessed: 16-Apr-2023].  

[3] “TS472,” STMicroelectronics, https://www.st.com/en/audio-ics/ts472.html (Accessed Aug. 31, 2023). 

[4] https://www.ti.com/product/LM741?qgpn=lm741 (Op-Amp)

[5] https://electronics.stackexchange.com/questions/537367/how-to-derive-the-differential-amplifier-equation 
    (Differential Op Amp Equation)








