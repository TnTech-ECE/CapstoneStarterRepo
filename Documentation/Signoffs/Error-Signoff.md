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
 microphones are allowed the transmit at [1]. For these reasons, Bluetooth is ideal for long-term use. 

## Buildable Schematic
 
## Analysis

### Power
To keep the error subsystem consistently powered, it will use the power subsytem to connect to Vdd and GND. The requirements of the CMA-4544PF-W need 2.7 V to 5.5 V at 3 mA, meaning the expected range of power will be 8.1 mW - 16.5 mW. It also has a shutdown mode, bringing the current draw 0.01µA. It can be connected via soldered wire or with a breadboard. 

### Input
The system will receive a single input from the electret microphone and amplify it to with a variable gain of 60 dB, 50 dB, and 40 dB.
According to the manufacturors of the CMA-4544PF-W electret mircophone can operate within 20Hz - 20 KHz.


### Output
The output threshold that activates the automatic gain control (AGC) is adjustable through the use of an external resistive divider. Once the divider is set, AGC reduces the gain to match the output voltage to the voltage set at the TH input.

## BOM
| DEVICE                                               | Quantity | Price Per Unit | Total Price |
|------------------------------------------------------|----------|----------------|-------------|
| CMA-4544PF-W Electret Microphone [1]                 | 2        | $7.95          | $15.90      |
| Capacitor                                            | 2        | $              | $           |



## References
[1] https://www.adafruit.com/product/1713

[2] https://cdn-shop.adafruit.com/datasheets/MAX9814.pdf
