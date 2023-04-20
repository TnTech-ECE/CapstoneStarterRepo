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

<img src="/Documentation/Images/Error/XS3868-WIring-Guide.jpg" alt="CS3868 Wiring Guide" width="60%" height="60%">

*Figure 1. Pinout of the OVC3860*

<img src="/Documentation/Images/Error/OVC3868_Pins.jpg" alt="OVC3868 Pinout" width="60%" height="60%">

*Figure 2. Wiring diagram of the OVC 3860*

The purpose of this design is to provide a discrete method of transmitting information. This wiring diagram shown in Figure 2 shows one method of connecting this device, though many of the shown connections would be uncessary. The only required connections would be the audio pins (16-19) and power (29, 31). Communicating with the device would require connections of the rx and rt (43, 44) pins.  
## Analysis

The audio captured from a microphone will be inputted into the device. From there, it will be able to convert the information from analog to digital and transmit the information to the Bluetooth receiver. 

The output threshold that activates AGC is adjustable
through the use of an external resistive divider. Once
the divider is set, AGC reduces the gain to match the
output voltage to the voltage set at the TH input.

## BOM
| DEVICE                                       | Quantity | Price Per Unit | Total Price |
|----------------------------------------------|----------|----------------|-------------|
| CMA-4544PF-W Electret Microphone [1]         | 2        | $7.95          | $15.90      |


## References
[1] https://www.adafruit.com/product/1713

[2] https://cdn-shop.adafruit.com/datasheets/MAX9814.pdf
