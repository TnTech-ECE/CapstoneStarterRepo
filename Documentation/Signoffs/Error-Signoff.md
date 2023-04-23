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
 
## Analysis

### Power
To keep the error subsystem consistently powered, it will use the power subsytem to connect to Vdd and GND. The requirements of the CMA-4544PF-W need 2.7 V to 5.5 V at 1.8 mA, meaning the expected range of power will be 4.86 mW - 9.9 mW. It also has a shutdown mode, bringing the current draw to 1 µA. Connections can be made with soldered wire or a breadboard. 

### Input
The system will receive a single input from the omnidirectional electret microphone and amplify it to with a variable gain of 0-40 dB in 10 db increments.
According to the manufacturors of the CMC-2742PBJ-A electret mircophone can operate within 100 Hz to 20 KHz and typically work with a 2 V bias voltage, which matches the bias voltage of the TS472. 


### Output
The output threshold that activates the automatic gain control (AGC) is adjustable through the use of an external resistive divider. Once the divider is set, AGC reduces the gain to match the output voltage to the voltage set at the TH input.

I'll have to do the math and formatting later, assuming this gets approved: 
Upper Cut-off Frequency = 1/( 2pi*40E3*(C1,2 + 100E-12))
100 pF gives 20kHz upper cutoff

Lower Cut-off Frequency = Fcl
Cin = 1 / (2pi * Fcl * 100E3)
Cout = 1/ (2pi * Fcl * Rout)
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
