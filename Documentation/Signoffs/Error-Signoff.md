Reference link: https://www.ti.com/solution/professional-microphones-wireless-systems?variantid=34929&subsystemid=18462


# Error Subsystem
<img src="/Documentation/Images/Error/High_Level.png" alt="High Level Design">

*Figure 1. High-Level Design*

## Function of the Subsystem
The goal of this subsystem is to input the acoustic audio from the room, amplify the audio to a workable signal, and broadcast the signal to the main processor subsystem.

## Constraints
| No. | Constraints                                                                    | Origin             |
|-----|--------------------------------------------------------------------------------|--------------------|
| 1   | Microphone shall be placed within the noise control area.                      | Design Requirement |
| 2   | Microphone shall react to input frequencies from 20 Hz to 20 kHz.              | Design Constraint  |
| 3   | Output signal should not be higher than 3.3 Vpp to prevent clipping.           | Device Constraint  |
| 4   | System must be powered from a 120 V 60 Hz wall outlet.                         | System Requirement |
| 5   | The primary input sensor shall output a continuous-time analog voltage signal. | System Requirement |
| 6   | The subsystem's gain shall match the input subsystem's gain.                   | Device Constraint  |
| 7   | The subsystem delay shall be less than or equal to 0.2ms.                      | System Requirement |
| 8   | The microphone shall have a maximum SPL rating of 110 dB or higher             | Construction Noise Data |


<sup>1</sup> The premise of this subsystem is to collect information on the noise from the wall and the speaker for the main processor. This means that the placement would be most effective past the speaker where the noise and speaker would meet. Because this will be wired together and there is an overall goal to make the design discrete, it can still be placed close to the speaker.

<sup>2</sup> Because the goal of the device is to limit noise heard by humans, the range of 20 Hz to 20 kHz is necessary to cover the majority of human hearing that the system will operate in.  

<sup>3</sup> The processing subsystem works at 3.3 V<sub>pp</sub>, so the output of the error subsystem must stay within those values to prevent clipping and inaccurate data.

<sup>4</sup> This follows the rest of the system's ability to have a constant power supply and not have to worry about having batteries. This device will work as long as there is a power supply. 

<sup>5</sup> The error subsystem's output will be inserted into the main processing subsystem which requires a continuous analog voltage signal.

<sup>6</sup> The gain from the error and input subsystem must be the same to simplify the arithmetic from the processing subsystem. The agreed preset gain for this project was 20 dB.

<sup>7</sup> Given that the maximum processing time of the main processing subsystem is 1.2 ms and the total allowable delay is 1.4 ms, the worst-case delay of this subsystem is 0.2 ms. Staying within these parameters will allow the processor subsystem to use accurate data.

<sup>8</sup> In order to prevent the microphone output from distorting or clipping before it is sent to the preamplifier a specified maximum SPL (sound pressure level in dB) must be found. Assuming the construction noise is at least 50 ft away from the source, the maximum SPL that the microphone would receive is 110 dBA from an impact pile driver, dBA is a frequency weighted scale or A weighted scale that more closely resembles human hearing [5]. This is assuming impact devices are commonly used during construction at Tennessee Technological University. The construction noise will likely never reach a level this high, however for extra safety the system must have an SPL rating for extremely loud devices since 110 dB is equivalent to an extremely loud sound [5].

## Buildable Schematic
The image below is a buildable schematic using the TS472 Preamplifier, POM-5038P electret microphone, and OPA2863-Q1 operational amplifier.

<img src="/Documentation/Images/Error/Diagrams/Buildable_Schematic_6.png" width="75%" height="75%">

*Figure 2. Buildable Schematic*

## Analysis
### Power
To keep the error subsystem consistently powered, it will use the pinouts from the main processor subsystem to connect to Vdd and GND. The requirements of the TS472 need 2.2 V to 5.5 V at 1.8 mA, meaning the expected power range will be 3.96 mW - 9.9 mW. The typical power consumption of the op-amp is 100 mW. Connections to each component can be made with soldered wire. 

### Input 
The system will receive a single input from the omnidirectional electret microphone and amplify it with a constant gain of 20 dB.
According to the manufacturers of the POM-5038P, the electret microphone can operate within 20 Hz to 20 KHz and typically works with a max 10 V bias voltage, which will be supplied by the 5 Vdc from VCC. Below are the passive component details:
- R<sub>1,2</sub>
    - Given the microphone will operate at a bias voltage of 5 V and its maximum current consumption is 0.5 mA, the minimum total resistance would need to be 5 kΩ. The chosen value for each polarizing resistor will keep the microphone at a safe value.
 
- R<sub>3</sub>
    - 47 kΩ sets the gain of the TS472 to 20 dB
 
- R<sub>4,5,6,7</sub>
    - The equal resistor values set the op-amp as a differential to a single output with a gain of one.
- C<sub>1,2</sub>
    -  The lower cutoff frequency, defined by F<sub>CL</sub>, requires the equations to evaluate.
    ```math 
    C_{in} = \frac{1} {2 π*F_{CL}*100*10^3}$
    ```
    -  An 80 nF capacitor for C<sub>1,2</sub> gives roughly 20 Hz lower cutoff frequency, which stays within constraint 2.
- C<sub>3,4,7,8,9</sub>
    - Specified by the manufacturers, they act as decoupling capacitors.
- C<sub>5, 6</sub>
    - The Higher Cutoff Frequency, F<sub>CH</sub>, is defined by the manufacturers using the equation below.
    ```math
    F_{CH} =  \frac {1} {(2 π *40*10^3) * (C_{5,6}+100*10^{-12})}
    ```
    - 100 pF capacitors for C5 and C6 give about 20 kHz upper cutoff frequency, which stays within constraint 2. 
- Vcc
    - 5 V, this is within typical operating conditions defined by the manufacturer.    

### Output
The microphone has a typical sensitivity of -38 dB at conditions defined by: Frequency = 1 kHz, 1 Pa, 0 dB = 1 V/Pa.
The typical voltage output would be found with the equation: $$20 log(x) = -38$$ where x equates to 12.59 mV. The minimum and maximum sensitivities are -41 dB and -35 dB which equate to 8.91 mV and 17.78 mV respectively. Using the gain of 20 dB that the TS472 can achieve, we can expect the outputs to be within 
89.1 mV and 177.8 mV <sup>3</sup>. The POM-5038-C3310-R has a maximum SPL of 120 dB <sup>9</sup>.


The LM741 operational amplifier from Texas Instruments [3]. will be used to take the differential output from the TS472 and output a unity gain signal that will be sent to the processing system. An operational amplifier can be configured in a differential topology where the output voltage is represented by the following equation: $$V_{out} = \frac{R_{f}} {R_{1}}(V_{2}-V_{1})$$ The two input voltages will be OUT+ and OUT- from the TS472 chip respectively, where OUT+ is the positive differential voltage signal and OUT- is the negative differential voltage signal. The output voltage from the designed circuit will be an in-phase and unity gain version of (OUT+) - (OUT-).

<img src="/Documentation/Images/Error/Diagrams/differential_opAmp_Design.png" width="75%" height="75%">

*Figure 3. Differential to single op-amp design on LTSpice*


Figure 3 shows an LT Spice version of the design. The OUT-pin is set to a 1 kHz 1 V peak sine wave, while the OUT-pin is set to a 1 kHz 2 V peak sine wave. The output voltage therefore is expected to (OUT+) - (OUT-) 1 V peak at the same frequency. The output voltage should have unity gain and also be in phase with the inputs.

<img src="/Documentation/Images/Error/Diagrams/differential_opAmp_Graph.png" width="75%" height="75%">

*Figure 4. LTSpice simulation*

Figure 4 shows the voltage from the OUT+ pin and the output voltage from the differential amplifier. The output voltage as expected is 1 V peak at 1 kHz. The OUT+ voltage and the output voltage are also in phase. The example values were used to illustrate how the differential amplifier will work and in most cases OUT- will be the negative of the noninverting input, doubling the amplitude. The TS472 output within 50.1 mV and 79.4 mV will be doubled and input into the left side of the STEREO_IN defined in the main processor, within constraint 3.  

### Speed
According to the TS452 datasheet, the transient response of the component is 20 µs. The slew rate of the LM741 op-amp is 0.5 V/µs, which adds about 2 µs to its response. The microphone will be placed within 0.034 m of the speaker, adding 1 ms  making the total delay from the subsystem's input to output 22 µs, within constraint 7.

## BOM
| DEVICE                                               | Quantity | Price Per Unit | Total Price |
|------------------------------------------------------|----------|----------------|-------------|
| POM-5038P-C3310-R Electret Microphone                | 2        | $1.56          | $3.40       |
| TS472 Pre-amp                                        | 1        | $1.70          | $1.70       |
| LM741 Op-Amp                                         | 1        | $0.75          | $0.75       |
| Total                                                |          |                | $5.85       |


## References
[1] https://www.digikey.com/en/products/detail/pui-audio-inc/POM-5038P-C3310-R/9673319 (POM-5038P-C3310-R Electret Microphone)

[2] https://www.st.com/en/audio-ics/ts472.html (Pre-amp + Datasheet)

[3] https://www.ti.com/product/LM741?qgpn=lm741 (Op-Amp)

[4] https://www.st.com/resource/en/application_note/dm00133498-signal-conditioning-differential-to-single-ended-amplification-stmicroelectronics.pdf (Differential Op Amp Equation)

[5]  https://www.nrc.gov/docs/ML1225/ML12250A723.pdf (Construction Noise Impact Assessment)
