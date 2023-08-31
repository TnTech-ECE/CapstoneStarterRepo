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
| 6   | The preset gain shall match the input subsystem's gain.                        | Device Constraint  |
| 7   | The subsystem delay shall be less than or equal to 0.2ms.                      | System Requirement |


<sup>1</sup> The premise of this subsystem is to collect information of the noise from the wall and the speaker for the main processor. This means that the placement would be most effective past the speaker where the noise and speaker would meet. Because this will be wired together and there is an overall goal to make the design discrete, it can still be placed close to the speaker.

<sup>2</sup> Because the goal of the device is to limit noise heard by humans, the range of 20 Hz to 20 kHz is necessary to cover the majority of human hearing that the system will operate in.  

<sup>3</sup> The processing subsystem works at 3.3 V<sub>pp</sub>, so the output of the error subsystem must stay within those values to prevent clipping and inaccurate data.

<sup>4</sup> This follows the rest of the system's ability to have a constant power supply and not have to worry about having batteries. This device will work as long as there is a power supply. 

<sup>5</sup> The error subsystem's output will be inserted into the main processing subsystem which requires a continuous analog voltage signal.

<sup>6</sup> The gain from the error and input subsystem need to be the same to simplify the arithmetic from the processing subsystem. The agreed preset gain for this project was 40 dB.

<sup>7</sup> Given that the maximum processing time of the main processing subsystem is 1.2 ms and the total allowable delay is 1.4 ms, the worst-case delay of this subsystem is 0.2 ms. Staying within these parameters will allow the processor subsystem to use accurate data.

## Buildable Schematic
The image below is a buildable schematic using the TS472 Preamplifier, CMA-4544PF-W electret microphone, and OPA2863-Q1 operational amplifier.

<img src="/Documentation/Images/Error/Diagrams/Buildable_Schematic_4.png" width="75%" height="75%">

*Figure 2. Buildable Schematic*

## Analysis
- R<sub>1</sub> and R<sub>2</pos>
    - Given the microphone will operate at a bias voltage of 5 V and its maximum current consumption is 0.5 mA, the minimum total resistance would need to be 5 kΩ. The chosen value for each polarizing resistor will keep the microphone at a safe value.
- R<sub>3</sub>
    - 68 Ω sets the gain of the TS472 to 40 dB
- C<sub>in+</sub>, C<sub>in-</sub>, C<sub>out+</sub>, andC<sub>out-</sub>
    -  The lower cutoff frequency, defined by F<sub>CL</sub>, requires the equations to evaluate.
    ```math 
    C_{in} = \frac{1} {2 π*F_{CL}*100*10^3}$ 
    ```
    -  An 80 nF capacitor for C<sub>1,2</sub> gives roughly 20 Hz lower cutoff frequency, which stays within constraint 2. The capacitors
    ```math  
    C_{out} = \frac{1} {2 π*F_{CL}*R_{out}}
    ```
    -  R<sub>out</sub> relates to the load it will be connected to. Since R<sub>out</sub> will be going into an operational amplifier, R<sub>out</sub> will effectively be high impedance making C<sub>out</sub> a very small value and insignificant for this circuit and not depicted on the buildable schematic.
- C3, C4, C7
    - Specified by the manufacturers, they act as decoupling capacitors.
- C5, C6
    - The Higher Cutoff Frequency, F_{CH}, is defined by the manufacturers using the equation below.
    ```math
    F_{CH} =  \frac {1} {(2 π *40*10^3 * (C_{5,6}+100*10^{-12})}
    ```
    - 100 pF capacitors for C5 and C6 give about 20 kHz upper cutoff frequency, which stays within constraint 2. 
- Vcc
    - 5 V, this is within typical operating conditions defined by the manufacturer.     


### Power
To keep the error subsystem consistently powered, it will use the pinouts from the main processor subsystem to connect to Vdd and GND. The requirements of the TS472 need 2.2 V to 5.5 V at 1.8 mA, meaning the expected range of power will be 3.96 mW - 9.9 mW. Connections can be made with soldered wire. 

### Input 
The system will receive a single input from the omnidirectional electret microphone and amplify it with a constant gain of 40 dB.
According to the manufacturers of the CMA-4544PF-W electret microphone can operate within 20 Hz to 20 KHz and typically works with a max 10 V bias voltage, which will be supplied by the 5 Vdc from VCC. 

### Output
The CMA-4544PF-W microphone has a typical sensitivity of -42 dB at conditions defined by: Frequency = 1 kHz, 1 Pa, 0 dB = 1 V/Pa.
The typical voltage output would be found with the equation: $$20 log(x) = -42$$ where x equates to 7.97 mV. The minimum and maximum sensitivities are -45 dB and -39 dB which equate to 5.62 mV and 11.2 mV respectively. Using the maximum gain of 40 dB that the TS472 can achieve, we can expect the outputs to be within 0.562 V and 0.112 V. This will be put into the left side of the STEREO_IN defined in the main processor.  

### Speed
According to the TS452 datasheet, the transient response of the component is 20 µs. The slew rate of the OPA2863-Q op-amp is 105 V/µs, which adds about 10 µs to its response, making the total delay from input to output 30 µs, below the 0.2 ms constraint.

## BOM
| DEVICE                                               | Quantity | Price Per Unit | Total Price |
|------------------------------------------------------|----------|----------------|-------------|
| CMC-2742PBJ-A Electret Microphone [1]                | 2        | $7.95          | $15.90      |
| TS472 Pre-amp [2]                                    | 2        | $1.38          | $2.76       |
| OPA2863-Q1 Differential Op-Amp                       | 2        | $2.12          | $4.24       |


## References
[1] https://www.digikey.com/en/products/detail/cui-devices/CMA-4544PF-W/1869981 (CMA-4544PF-W)

[2] https://www.st.com/en/audio-ics/ts472.html (Pre-amp + Datasheet)

[3] https://www.ti.com/product/OPA2863-Q1#product-details (Differential Op-Amp)
