Reference link: https://www.ti.com/solution/professional-microphones-wireless-systems?variantid=34929&subsystemid=18462


# Error Subsystem
<img src="/Documentation/Images/Error/High_Level.png" alt="High Level Design">

*Figure 1. High-Level Design*

## Function of the Subsystem
The goal of this subsystem is to input the acoustic audio from the room, amplify the audio to a workable signal, and broadcast the signal to the main processor subsystem.

## Constraints
| No. | Constraints                                                                 | Origin                    |
|-----|-----------------------------------------------------------------------------|---------------------------|
| 1   | Microphone shall be placed within the noise control area                    | Design Requirement        |
| 2   | Microphone shall be able to measure input frequencies from 100 Hz to 17 kHz | Design Constraint         |
| 3   | Shall output a signal's high values within  1.8 V to 3.65 V                 | Main Processor Constraint |

<sup>1</sup> The premise of this subsystem is to collect information of the noise from the wall and the speaker for the main processor. This means that the placement would be most effective past the speaker where the noise and speaker would meet. Because this will be wired together and there is an overal goal to make the design discrete, it can still be placed close to the speaker.

<sup>2</sup> Because the goal of the device is to limit noise heard by humans, the range of 100 Hz to 17 kHz is necessary to cover the majority of human hearing that the system will operate in.  

<sup>3</sup> The main processor will be using an ADC (ADAU1761 SigmaDSP) who's I/O works within 1.8 V to 3.65 V. In order to achieve these values, the pre-amp must be configured such that the highest voltage value allowable is within that range. This will allow the main processor to correctly understand the error subsystem's output.

## Buildable Schematic
<img src="Active-Noise-Control-With-Wall-Transmission-Detection/Documentation/Images/Error/Diagrams/Buildable_Schematic.png" width="60%" height="60%">


| Component         | Value | Unit |
|-------------------|-------|------|
| R<sub>pos</sub>   | 50    | kΩ   |
| R<sub>neg</sub>   | 50    | kΩ   |
| C<sub>in+</sub>   | 20    | nF   |
| C<sub>in-</sub>   | 20    | nF   |
| C3                | 1     | µF   |
| Cs                | 1     | µF   |
| C1                | 100   | pF   |
| C2                | 100   | pF   |
| C<sub>out+</sub>  | ~     |      |
| C<sub>out-</sub>  | ~     |      |
| Cb                | 1     | µF   |

## Analysis

### Component Details

- R<sub>pos</sub> and R<sub>neg</pos>
    - Given the microphone will operate at a bias voltage of 2 V and its maximum current consumption is 0.4 mA, the minimum total resistance would need to be 5 kΩ. The chosen value for each polarizing resistor will keep the microphone at a safe value.

- C<sub>in+</sub>, C<sub>in-</sub>, C<sub>out+</sub>, andC<sub>out-</sub>
    -  The lower cutoff frequency, defined by F<sub>CL</sub>, requires two equations to evaluate.
    ```math 
    C_{in} = \frac{1} {2 π*F_{CL}*100*10^3}$ 
    ```
    -  20 nF capacitor for C<sub>in</sub> give roughly 79.6 Hz lower cutoff frequency, which stays within constraint 2. 
    ```math  
    C_{out} = \frac{1} {2 π*F_{CL}*R_{out}}
    ```
    -  R<sub>out</sub> relates to the load it will be connected to. Since R<sub>out</sub> will be going into a GPIO as an input, R<sub>out</sub> will effectively be high impedence making C<sub>out</sub> a very small value and insignificant for this circuit.
- C3, Cs, Cb
    - Specified by the manufacturors 
- C1, C2
    - The Higher Cutoff Frequency is defined from the manufacturors using the equation below, assuming the circuit is configured as shown in the buildable schematic shown in Figure X.
    ```math
    F_{CH} =  \frac {1} {(2 π *40*10^3 * (C_{1,2}+100*10^{-12})}
    ```
    - 100 pF capacitors give about 19.9 kHz upper cutoff frequency, which stays within constraint 2. 





### Power
To keep the error subsystem consistently powered, it will use the power subsytem to connect to Vdd and GND. The requirements of the CMA-4544PF-W need 2.7 V to 5.5 V at 1.8 mA, meaning the expected range of power will be 4.86 mW - 9.9 mW. It also has a shutdown mode, bringing the current draw to 1 µA. Connections can be made with soldered wire or a breadboard. 

### Input
The system will receive a single input from the omnidirectional electret microphone and amplify it to with a variable gain of 0-40 dB in 10 db increments.
According to the manufacturors of the CMC-2742PBJ-A electret mircophone can operate within 100 Hz to 20 KHz and typically work with a 2 V bias voltage, which matches the bias voltage of the TS472. 


### Output

#### Higher Cutoff Frequency


#### Lower Cutoff Frequency

20 nF gives roughly 60 Hz lower cutoff. 

## BOM
| DEVICE                                               | Quantity | Price Per Unit | Total Price |
|------------------------------------------------------|----------|----------------|-------------|
| CMC-2742PBJ-A Electret Microphone [1]                | 2        | $7.95          | $15.90      |
| TS472 Pre-amp [2]                | 2        | $          | $      |
| Capacitor                | 9        | $          | $      |
| Resistor                 | 4        | $          | $      |


## References
[1] https://www.digikey.com/en/products/detail/cui-devices/CMC-2742PBJ-A/1869986 (Microphone)

[2] https://www.st.com/en/audio-ics/ts472.html (Pre-amp + Datasheet)

```math
C_{in} = \frac{1} {2 π*F_{CL}*100*10^3}
```


```math
C_{out} = \frac{1} {2 π*F_{CL}*R_{out}}
```

``` math
F_{CH} =  \frac {1} {(2 π *40*10^3 * (C_{1,2}+100*10^{-12})}
```
