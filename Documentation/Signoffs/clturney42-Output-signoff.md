
# Output Subsystem

<p align="center">
<img width="1018" alt="Screen Shot 2023-04-16 at 6 12 58 PM" src="https://user-images.githubusercontent.com/123997954/232348587-a962e40f-7dd1-43ec-834e-d62ea83feeec.png">
<p>

#### **Figure 1: Output subsystem**


## Function of the Subsystem

The goal of the output subsystem is to take the analog signal received from the processor, amplify the signal through an audio power amplifier, and drive it to the speaker so that it can be emitted. The power amplifier will need to amplify the analog signal to an appropriate level for the speaker to be able to output it into the room. The speaker and amplifier must have internal impedances that are compatible, and the speaker needs to be able to have an efficiency and sound pressure level to adequately cover a certain portion of the room. 



## Constraints
  
| No. | Constraints                                                                                           | Origin                               |
| --- | ------------------------------------------------------------------------------------------------------| ---------------------                |  
| 1   | The Audio amplifier shall be supplied a minimum of 8.0 V and maximum of 18 V from the power supply  | Device specifications                |
| 2   | The audio amplifier and speaker shall be able to output at a minimum frequency range of 1KHz-17KHz  | Device constraints and human biology|
| 3   | The audio amplifier shall be able to deliver at least 10.0 W of continuous power at its output        | Device constraints and speaker constraints |
| 4   | The speaker shall have a minimum input impedance 4Ω                                                   | audio amplifier specifications       |
| 5   | System shall have a primary output speaker that generates acoustic sounds based on its analog input from the system                                                                                                                                    | Conceptual design and to fulfill goal of system |
| 6   | Speaker shall be capable of outputting at a sound pressure level of at least 90 dB               | Constraints of room and device constraints |
| 7   | Speaker shall have an input power rating maximum of 15 watts                     | Amplifier specifications and power insurance |
| 8 | Output system shall extend a maximum of 0.5 meters from the wall                                        | Ethics and system delay              |
| 9| Output system shall be positioned close enough to wall to reduce delay enough to eliminate echo in sound                                                           | Device specifications and goal of system |
|10| Speaker shall be mounted to the wall, and will not impede movement or damage the classroom  | Ethics and Device constraints|
|11| Speakers shall maintain a minimum of 90 dB SPL across the entire window |Derived Contraint from window|

  
### 1) The Audio amplifier shall be supplied a minimum of 8.0 V and maximum of 15 V from the power supply.     |Origin: Device specifications|
According to the AA-AB32231 [1], The audio amplifier can drive a 4Ω load as long as it is supplied a voltage range of 8-18 volts, with the typical amount being 12 volts. With this in mind it is imperative that a constraint is included that ensures a correct amount of power is supplied to the amplifier.


### 2) The audio amplifier and speaker shall be able to output at a minimum frequency range of 1KHz-17Khz.    |Origin: Device constraints and human biology|
The frequency range that the human ear can hear is generally in the range of 20Hz-20Khz, this range is subject to change with age, but this is the minimum and maximum. With this in mind it would be ideal for the speaker to able to output at a frequency range that covers most of the values that the human ear can perceive. This also means that the audio amplifier should be able to take in and output this range of frequencies. Therefore, a constraint is set that ensures the speaker and audio amplifier can output at a range of 1KHz-17Khz, this range allows a bit more adaptability to the design but covers an appropriate range of necessary sounds that the device will encounter. 
  
### 3) The audio amplifier shall be able to deliver at least 10.0 W of continuous power at its output     |Device constraints and speaker constraints|
To properly drive the speaker in which it is outputting to, the audio amplifier needs to be able to supply at least the input rated power of the speaker. To provide the most efficiency there should also be room for error, in the case that the power from the amplifier fluctuates. This constraint will follow closesly with the constraint for the input power of the speaker and is included to ensure enough power to the speaker is supplied.

### 4) The speaker shall have a minimum input impedance 4Ω |Origin: audio amplifier specifications|
When it comes to speaker, there is a built-in input impedance that the device has. The lower the impedance the higher the current draw since there is less resistance. This also means the lower the impedance the less voltage that is required. The audio amplifier used in this design in specified to be able to drive a 4-8Ω load [1][3]. If an amplifier tries to drive a speaker with a impedance that is lower than what is rated to be capable of, there is a high chance that the amplifier will overheat. [ref] Therefore, the speaker that will be used will have a minimum input impedance of 4Ω. This allows for a wider range of speakers and amplifiers to be used and ensures that a safe design choice is made, since speakers with impedances above the rated amplifier impedance can be used with minimal issues.

### 5) System shall have a primary output speaker that generates acoustic sounds based on its analog input from the system. |Origin: Conceptual design and to fulfill goal of system|
The processing portion of the system is going to process a signal and convert it to analog to be sent to the output. To properly make use of this analog input the output subsystem must be able to take in this analog signal and after amplifying it, output it as an acoustic sound wave that will attenuate noise. With this in mind, the output system is being designed in a way that allows the amplifier to take in an analog input and properly interface with the speaker to emit and appropriate output.

### 6) Speaker shall be capable of outputting at a sound pressure level of at least 90 dB. |Origin: Constraints of room and device constraints|
Sound pressure level (SPL) is characterized as the difference between the pressure of a sound wave and the ambient pressure of the air that it is traveling through [5]. The sound pressure level of the speaker will need to be higher than the sound that it is trying to cancel in order for it to effecitvely cancel the sound. With this in mind, a good middle ground that allows for a wide range of speakers that can output at an appropriate SPL to cover a portion of the room is a 90 dB SPL. 

### 7) Speaker shall have an input power rating maximum of 16 watts |Origin: Amplifier specifications and power insurance|
Due to the amplifier being able to supply a continuous power of 16 W [1], an appropriate speaker must be selected so that the amplifier has enough power to drive it. A good rule of thumb is to have the amplifier used have an output power appropriately higher than the speakers power rating. With this in mind, the speaker that is used should have a power rating of 15 watts or less. This ensures that the amplifier will be able to consistently drive the speaker with enough power, even if there are slight fluctuations in the system. 

### 8) Output system shall extend a maximum of 0.5 meters from the wall |Origin: Ethics and system delay|
To satisfy the ethical constraints of movement impedence and reduce delay as much as possible in the system, the speaker will extend a maximum of 0.5 meters from the wall. This distance will likely be less but this constraint is set to make sure that the speaker is never in the way of individuals within the room. This distance constraint is also necessary due to the delay associated with the speed of sound and distance of the speaker from the sound source. The speaker cannot have too much delay else the anti-noise will not be in sync with outside noise.
  
### 9) Output system shall be positioned close enough to wall to reduce delay enough to eliminate echo in sound |Origin: Device specifications and goal of system|
  
An ideal noise cancellation device would have no delay however, that is impossible to do when the signal is being processed and traveling through different hardware. With this in mind, the delay of the device needs to be set so that there is as minimal as possible disparity between the inputted signal and outputted noise. This can be verified and changed based on the distance the speaker is positioned from the wall.
  
### 10) Speaker shall be mounted, and will not impede movement or damage the classroom

The speaker will be fitted into an enclosure that matches the dimensions of the speaker. This enclosure will then be mounted to the wall in an optimal position for noise cancellation. To fit this constraint, the position in which the speaker is placed will not impede movement or damage the classroom. This can be verified by confirming the placement of the speaker does not block the classroom or damage the walls or windows within the classroom.

### 11) Speakers shall maintain a minimum of 90 dB SPL across the entire window |Origin: Derived Contraint from window|

The sound that we are trying to cancel will be coming in through the classroom window, therefore, we want a speaker arrangement that will be sufficient in covering the entire window and maintaining a minimum sound pressure level at every point. To ensure that this constraint is fulfilled, the radiation/directivity pattern of the speaker must be analyzed and the speakers must be placed in a way that ensures maximum coverage and sound pressure level before overlap. Due to the nature of the sound that we are convering, construction noises, maintaining a sound pressure level and coverage minimum of 90 dB across the entire window will be sufficient.

  

## Buildable schematic 

<img width="1287" alt="Screen Shot 2023-09-10 at 1 13 08 PM" src="https://github.com/CarsonDPope/Active-Noise-Control-With-Wall-Transmission-Detection/assets/123997954/9382a2a9-fe0b-4a97-b8be-2d37acaadc13">


### **Figure 3: Audio Amplifier AA-AB32231 connected to speaker with appropriate specifications**

The above image is the buildable schematic for the output subsystem. As shown, the input of the subsystem J8 will be connected to the output of the processing and receive an analog voltage signal. The amplifier can be powered either through the J1 terminal block or the J3 DC power adapter socket with a supply of 8-18V. To run the amplifier in mono mode the speaker will be connected to J5 and J7 with OUT2 +/- short circuited to as the postive speaker output and OUT1 +/- short circuited as the negative speaker output. 

## Analysis

### Fulfilling Constraints 
  
> 1) The Audio amplifier shall be supplied a minimum of 8.0 V and maximum of 18.0 V from the power supply
  
  The design for the power system will ensure that a minimum of 8.0 Volts will be supplied to the system. According to the datasheet for the AA-AB32231[1], the amplifier can operate off a single supply voltage from 8.0 - 18.0 Volts. The typical power used is 12 volts and that will be the amount that the amplifier is operated at for this design.

> 2) The audio amplifier and speaker shall be able to output at a minimum frequency range of 1KHz-17Khz
  
  The CSS-10246-304 speaker has an operating range of 110Hz-20Khz [8] and the AA-AB32231 has an operating range of 20Hz-20Khz [3]. Both of these specifications fit the constraint and will allow the output system to account for the wide    range of potential sounds that will come through the wall.
  
  >3) The audio amplifier shall be able to deliver at least 10.0 W of continuous power at its output
  According the data sheet of the AA-AB32231 amplifier[1], it is able to deliver a continuous power of 16 W mono to a load of 4Ω. The selected speaker has an input impedence of 4Ω and a input power rating of 10 W, with its max being 15 W, meaning this amplifier well fulfills the constraint required by the speaker. 

> 4) The speaker shall have a minimum input impedance 4Ω 
  
   The AA-AB32231 amplifier is capable of driving a 4Ω load from a 8-18V power supply, and the CSS-10246-304 speaker has an input impedence of 4Ω, meaning the system will easily be able to drive the speaker.
  
> 5) System shall have a primary output speaker that generates acoustic sounds based on its analog input from the system
  
  As explained in the rest of the analysis, The speaker and amplifier have had their specifications matched so in theory sound should be outputted. Further verification will be done during physical testing of the device.
  
> 6) Speaker shall be capable of outputting at a sound pressure level of at least 90 dB
  
   According the data sheet of the CSS-10246-304, the speaker has an SPL value of 91 dB when driven with 1 W, and and SPL value of up to 100 dB when driven with 10 W. This is over the derived constraint and will provide an excellent sound level that will sufficiently permeate the room.

> 7) Speaker shall have an input power rating maximum of 15 watts 
  
  The CSS-10246-304 speaker has an input power requirement of 2 watts meaning that the the 2.5 watts of power that the SSM2377 is able to deliver will be sufficient in power the speaker.
  
> 8) Output system shall extend a maximum of 0.5 meters from the wall
  
  To make sure that the speaker is not in a place that will impede the movement of those within the classroom, a constraint of 0.5 meters from the wall max has been placed. 
  
> 10) Speaker shall be mounted to the wall and will not impede movement or damage the classroom

  The speaker will be fitted into an enclosure that will be made with a 3d printer. A front cavity and a rear cavity will be created that match the 102mm x 102mm x 46mm dimensions of the CSS-10246-304 speaker. The rear cavity will be designed to have a depth equal to the diameter of the speaker, which is 102mm. The speakers within their enclosures will then be mounted to the wall using a command strip. The rectangular shape of the enclosure will allow for an easy application of a command strip, and the adhesive of the command strip will allow for simple connection to the mounting subsystem used for the rest of the system. Whether this be on a pcb box or to the window sill or wall. More testing will be done to find the best position for the speaker to be placed on the wall to cancel noise. The command strips will allow much maneuverability and will not damage the wall since there will be no drilling or nails.

> 11) Speakers shall maintain a minimum of 90 dB SPL across the entire window

  To effectively cancel out the noise in a room, it is important to have a speaker that has an effective enough sound pressure level. This means that the sound pressure level of the emitted noise should be equal to or higher than the sound pressure level of the sound where the signal originated from ]9]. Most noises such as conversation or light rainfall will range less than 60 dB while sounds such as constuction noise can range 80 dB or higher when directly next to the source. Distance of course will decrease this sound pressure level and materials such as the window and the wall of the classroom will decrease it as well. The CSS-10246-304 speaker is capable of emitting a 100 dB sound pressure level when supplied with 10 W of power, which means it will be very sufficient in cancelling out loud noises like contruction or quieter noises as well. 

It is important to measure the efficiency and radiation/directivity pattern of a speaker as well, to ensure that even with distance the speaker will still maintain a sound pressure level capable of cancelling the desired noise. The CSS-10246-304 speaker has a size of 102mm x 102mm x 46mm (L x W x H). When finding the radiation pattern of a speaker, or the way in which it emits sound at different frequencies, it is important to take into account the size and material of the speaker, as well as the the frequency of incoming sound [10]. Due to the datasheet of the CSS-10246-304 not including a polar plot or off-axis frequency response graph, a different speaker with a similar size and frequency response was used to estimate the directivity of the CSS-10246-304. The R 10 S TE - 4 Ohm speaker.


<img width="1235" alt="Screen Shot 2023-10-12 at 4 02 39 PM" src="https://github.com/CarsonDPope/Active-Noise-Control-With-Wall-Transmission-Detection/assets/123997954/4ca0cb7e-0b95-4c09-9b73-8c51227b7545">


<img width="1085" alt="Screen Shot 2023-10-12 at 4 02 59 PM" src="https://github.com/CarsonDPope/Active-Noise-Control-With-Wall-Transmission-Detection/assets/123997954/3bf981f6-2464-40c9-b0f8-d17be4943c42">

### **Figure 4 & 5: Frequency response of R 10 S TE - 4 Ohm speaker (Top)[], Frequency response of CSS-10246-304 speaker (Bottom)**

As shown in figures 4 and 5, the frequency responses are similar between the two speakers, maintaining similar SPL values in the 100-2000 Hz range. The R 10 S TE - 4 Ohm speaker datasheet [] includes a polar plot that shows how the speakers sound is maintained at different angles off the speakers axis and at different frequencies. 

<img width="682" alt="Screen Shot 2023-10-12 at 4 12 28 PM" src="https://github.com/CarsonDPope/Active-Noise-Control-With-Wall-Transmission-Detection/assets/123997954/6045916b-59c4-40df-b312-afb76a787449">

### **Figure 6: Radiation/Directivity pattern of R 10 S TE - 4 Ohm speaker**


<!--- The parameters of the room Brown 314 are 34 x 24 x 11 (in feet). In meters this is 10.3632 x 7.3152 x 3.3528.-->
The CSS-10246-304 speaker has an efficiency of 10 W / 0.5 m. The general rule of thumb with sound pressure level (SPL) is whenever the wattage supplied is doubled the SPL increases by 3 dB and whenever the distance is doubled the SPL decreases by 6 [9]. If we take the SPL of the speaker to be 97 dBA at 10 watts at 0.5 meters, then the SPL distrubuted over distance looks like this.

| Power (W)                  | Distance (Meters) | Sound Pressure Level (dB) | 
| -----------------          | --------          | --------------            | 
| 10 W                       | 0.5 m             | 97 dB |
| | 1 m | 91 dB |
| | 2 m | 85 dB |
| | 4 m | 79 dB |
| | 8 m | 73 dB |

As seen from the table, the speaker is able to maintain a relatively good SPL across the bounds of the classroom. Taking into account the walls/windows of the classroom and the distance from construction as well, the noise should stay well within the bounds of what the speaker can handle and emit. This means that theoretically, the speaker is strong enough to cancel out the desired noise across an appropriate distance when supplied with sufficient power from the amp. Quality of sound coverage will not be the same in each area of the classroom, and with more speakers means better coverage, but with the current design positive effects should be seen from multiple areas of the classroom.

  


## BOM
| DEVICE                       | Quantity | Price Per Unit | Total Price |
| -----------------            | -------- | -------------- | ----------- |
| Sure Electronics AA-AB32231 2x8W 1x16W at 4 Ohm TPA3110 Class D Audio Amplifier Board    | 1        | $16.98          | $16.98     |
| CSS-10246-304 Speaker        | 1        | $7.91          | $7.91      |


## References

[1] Sure Electronics, "AA-AB32231 2x8W 1x16W at 4 Ohm TPA3110 Class D Audio Amplifier Board" AA-AB32231 datasheet, 2011, (https://www.parts-express.com/pedocs/manuals/320-329--aa-ab32231-1-or-2-channel-configurable-16w-amp-board.pdf) (accessed September 9th, 2023).

[2] “2*10 watt @ 8ohm, D-class Audio Amplifier Board - EUA3110” , AA-AB32231 , 21-June-2011. [Online]. https://www.parts-express.com/pedocs/tech-diagrams/320-329-parts-express-technical-diagram.pdf. [Accessed: 09-Sep-2023].  

[3] “Sure Electronics AA-AB32231 2x8W 1x16W at 4 Ohm TPA3110 Class D Audio Amplifier Board” AA-AB32231 Product Webpage, [Online]. Available: https://www.parts-express.com/Sure-AA-AB32231-2x8W-at-4-Ohm-TPA3110-Class-D-Audio-Amplifier-Board-Only-320-329?quantity=1. [Accessed: 10-Sep-2023]. 

[4] CUI Devices. (n.d.). CSS-10246-304. CSS-10246-304 | Standard (41 mm~205 mm) | Speakers. https://www.cuidevices.com/product/audio/speakers/standard-(41-mm~205-mm)/css-10246-304 

[5] K. Koehler, “Understanding sound pressure level (SPL) and the decibel scale,” Pro Tool Reviews, 09-Sep-2021. [Online]. Available: https://www.protoolreviews.com/understanding-sound-pressure-level-spl-decibel-scale-db/. [Accessed: 16-Apr-2023]. 

[6] P. Brant, “Speaker Impedance Matching: Ohms &amp; Speakers explained,” Speaker Impedance Matching: Ohms &amp; Speakers Explained, 21-Feb-2023. [Online]. Available: https://www.the-home-cinema-guide.com/speaker-impedance-matching.html. [Accessed: 16-Apr-2023]. 
 
[7] “Benefits of delta-sigma analog-to-digital conversion,” NI, 04-Apr-2023. [Online]. Available: https://www.ni.com/en-us/shop/data-acquisition/benefits-of-delta-sigma-analog-to-digital-conversion.html. [Accessed: 16-Apr-2023].
  
[8] CUI Devices, "SERIES: CSS-10246-304 | DESCRIPTION: SPEAKER" CSS-10246-304 datasheet, 08-May-2022, https://www.cuidevices.com/product/resource/css-10246-304.pdf (accessed September 10th, 2023).

[9] Longman, J., &amp; LongmanHello, J. (2023, April 4). Speaker sensitivity explained. AudioReputation. https://www.audioreputation.com/speaker-sensitivity-explained/ 

[10] 7. sound radiation and measurement, http://msp.ucsd.edu/syllabi/170.13f/course-notes/node7.html#:~:text=The%20dependence%20of%20the%20strength,that%20was%20worked%20out%20here (accessed Oct. 12, 2023). 



