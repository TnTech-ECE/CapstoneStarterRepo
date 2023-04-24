# Heartbeat/Respiratory Subsystem 

## Subsystem Function

The purpose of this subsystem is to measure the presence of a heartbeat as well as measure the respiratory rate of a person contactlessly. This subsystem will be composed of a singular radar that will perform both of these actions. The measuring of a person’s presence of a heartbeat as well as respiratory rate will be done by measuring the rise and fall rates of a person’s chest to measure the respiratory rate, and the rise and fall rates of the area around the heart to measure the presence of a heartbeat. A series of signals will be sent and received to measure these changes. The raw data will be put through an amplifier/filter and then be converted to a digital signal that is sent to a computing system to be put through a processing algorithm.

## Specs and Constraints			


| Description | Constraint | Source of Constraint |
|-------------|------------|----------------------|
| Heartbeat analysis | Must sense Beats per minute from 30 to 210 bpm (or frequencies from 0.5 Hz to 3.5 Hz)| From Conceptual Design, from Heartbeat/Respiratory System section[5][6]|
| Respiratory sensor |Must sense breaths per minute from 1 to 70bpm (or frequencies from 0.017 Hz to  1.17 Hz) | From Conceptual Design, from Heartbeat/Respiratory System section analyzed from START model |
| Distance | Must detect and measure heartbeat and breath rate from at least 1 meter away | From DARPA constraints |
| Weight | Entire system must weigh less than 6 pounds, this subsystem should weight 1.5 lbs or less | From DARPA constraints/ Conceptual design |
| Safety | Radar must not emit at a frequency over 10 GHz with a power density of 1000 W/m^2 in order to keep the radar skin and eye safe. | From World Health Organization (WHO) |
| Operational Amplifier | Radar input signal amplitude  must be increased by a gain of 6 in order to match the input range of the AD HATboard ADC module. Output voltage shall be limited to either -2.5 V to 2.5 V peak-to-peak or 0 V to 5 V peak-to-peak. Output current shall be limited to a maximum of 10 mA. | From further analysis of the radar and computing subsystems. |

## Wiring Schematics



![image](https://user-images.githubusercontent.com/79685126/232992358-859ff652-7a55-444c-bf29-dbeecf625869.png)


Figure 1. Wire Diagram for the total subsystem


![image](https://user-images.githubusercontent.com/79685126/233561981-93cf1e05-d0cd-404e-a7c9-d0cd66774b79.png)


Figure 2. Circuit schematic for active amplifier

![Noise](https://user-images.githubusercontent.com/123600489/233882469-8f5008a5-a848-43a9-b23d-65feedce9893.jpg)

Figure 3. Simulation results from circuit shown in figure 2


![image](https://user-images.githubusercontent.com/79685126/233561945-83ee2f3c-6468-4ec2-8b62-213f93e063a3.png)


Figure 4. Current output of circuit

## Analysis

1+2.) The 24 GHz doppler  radar functions by transmitting a signal described by the equation T(t) = Acos[2pift + theta(t)] This then hits the target and returns the function listed below:






![image](https://user-images.githubusercontent.com/79685126/232992094-7dc2fd16-dcfb-4401-b63e-387e4b1426c4.png)
 

*Equation taken from [2]

As shown by the datasheet and the pin layout of the NJR4262J this signal is put through a mixer to separate in-phase signal (I(t)) and the quadrature phase signal (Q(t)) as shown below:



![image](https://user-images.githubusercontent.com/79685126/232992034-c7c31b9a-62aa-4ef4-9b9b-e762a4baa5fc.png)

*Equation taken from [2]

In these equations the As stand for amplitude, the different thetas are for phase constants and phase shifts, the lambda  is the carrier wavelength, the d is the distance from the target, but most importantly x(t) correlates to the displacement in the human body surface [2]. This can be broken up into x(t) = xheart + xresp + everything else. To retrieve this information from the I/Q data the following equation can be used:


![image](https://user-images.githubusercontent.com/79685126/232991977-168c1a8c-fe42-40b3-9996-3786fdd53ab8.png)


*Equation taken from [2]

With this information the line of thinking for the algorithm to retrieve the heartbeat and respiratory data needed to conform to the listed constraints goes as follows. The baseband signal from the I and Q pins of the NJR4262J are sent through an amplifier circuit with a gain of 6 listed in Figure 2. The NJR4262 datasheet states a typical signal level of 0.8 Vp-p, with a gain of 6, this puts the output I and Q signals at a gain of 5 Vp-p which matches the input range of the AD HAT board ADC module. The digital signals can then be transmitted directly to the jetson for signal processing. The next step is to demodulate the I/Q data using the x(t) equation above and retrieve all the chest displacement data from the signal. With this data, a band pass filter can now be used to extract the specified constraint frequency data for both heart rate and respiratory rate. The combined frequency range needed and lower and upper frequency ranges of the pass band filter is 0.017 Hz - 3.5 Hz. 

With the heartbeat and respiratory rate data retrieved, a matched filter can then be used to maximize the signal-to-noise ratio separating the heartbeat and respiratory peaks from the noise. Once this signal is achieved the Fast Fourier Transform can be taken (FFT) to get the magnitude and frequencies found in the signal. The chest moves between 0.2-0.5 mm due to the heart beat while between 2 - 12.6 mm due to respiratory rate. This discrepancy in displacement will help differentiate the heartbeat data versus the respiratory data. The peaks can then be retrieved matching the respective frequency range and magnitude values for chest movement matching respiratory and heart rate values listed in constraints. 

As a proof of concept [2] [4] took a similar approach to the algorithm above and [2] got simulated data as follows:



![image](https://user-images.githubusercontent.com/79685126/232992160-1acdf0c3-772d-450e-9b55-3a3c6de23a00.png)


         

While [4] got data:


![image](https://user-images.githubusercontent.com/79685126/232992232-1fabe42b-6ea8-4639-9490-3359897e9b34.png)


In both cases taking out the harmonics there is a clear peak at the respective chest movement values and frequencies that match a heart beat rate and respiratory rate.

The above graphs show a respiratory peak at 0.2 Hz and heartbeat peak at around 1.4 Hz, these peaks do in fact fall between the range stated in the constraints, but it is also possible to achieve frequency displacement values at the 0.017 Hz and the 3.5 Hz edges. Working backwards a displacement signal to match the low and high range can be structured as a sinusoidal wave with the respective frequencies and displacement amplitudes of the heartbeat or respiratory movements, Arcos(2pift). So the lower range would be Arcos(0.1068t) and upper range Ahcos(22t). Plugging these into the x(t) equation you would get x(t) = Arcos(0.1068t) +  Ahcos(22t). Plugging into x(t) arctan equation and taking the tangent of both sides and graphing the result you get a graph like the one below: 

![image](https://user-images.githubusercontent.com/79685126/233289253-08e63076-ad1f-45a5-8405-61afeca7cd7a.png)

Figure 5. Graph of modulated signal (Amplitude vs Time)

This represents a modulated signal which is exactly what would be outputted by the Q(t) divided by I(t) signals. Although the exact numbers are not used, it is clear that along with other frequencies between this range and even others outside the range will be incorporated by the modulated signal found in the O(t)/I(t) signal data that can then be demodulated and filtered to retrieve the exact values of the individuals heartbeat and respiratory rate as stated by the proposed algorithm above.

3.) As stated by the NJR4262J datasheet states the typical radiated power to be 16 dBm or 40 mW. This allows for the sensor to function well over the 1 meter limit set by the constraint above. The exact valuation depends on the specific environment the radar will be functioning in, but as a comparison a radar with a 20 dBm radiated power (which happens to be the NJR4262J’s max power range) can reach 1 km range. 

4.) Once again as stated by the datasheets the NJR4262J weighs a max 7g or 0.0022 lb. The AD HAT Board weighs 19.96 g or 0.044 lb, and the two circuits are approximately 5g or 0.011 lb each. This brings the approx total to 31.96 g or 0.0704 lb which is well below the limit set by the weight constraint. This will allow some weight to be allotted to the more heavy subsystems such as the computing and power subsystem.

5.) WHO sets the power density safety limit at 1000 W/m^2 for radars over 10 GHz. With the  NJR4262J being a 24 GHz radar this would mean its power density must be under this value.  The datasheet sets the max radiated power of the radar at 100 mW. The unit’s dimensions are also 25 X 25 X 7.3 millimeters. This would put the power density at 160 W/m^2  ,which falls below the safety limit and confirms the final constraint listed above.

6.) In figure 3, it shows the simulation results of the operational amplifier circuit shown in figure 2 that must have a gain of 6 in order to take the 0.4 V amplitude from the output of the radar and to raise it to 2.4 V amplitude so the radar can be compatible with the analog to digital converter; since the analog to digital converter has a max input peak-to-peak voltage -2.5 V to 2.5 V, raising the voltage from the radar is a necessity. The current output from the operational amplifier circuit must also be regulated in order for the circuit to be compatible with the analog to digital converter. For the analog to digital converter, the maximum input current that it can take is 10 mA and a minimum input current of -10 mA. The current output of the operational amplifier circuit has a max current output of approximately 2.4 mA, and a minimum current output of -2.4 mA. This allows the circuit to be safely attached to the analog to digital converter since the maximum and minimum output currents fall within the input voltage range of the analog to digital converter. Noise can be simulated by the white function seen in the circuit, but the op amp manuals also dictate a noise change of micro volts which is not enough to put the signal out of the ADC input range. 

The range that a human heart can beat varies depending on the age, and other factors, of the person. A quick good way to estimate the maximum heart rate is to subtract the age by 220. The literature reviewed for this makes this estimation valid down to 10 year olds, so 210 bpm will be the maximum heart rate measured [5]. For the lower bound, typically anything below 60 is considered a low heart rate and could be dangerous. According to the literature reviewed, heart rates can reach down to 40 when sleeping as an extreme low, so 30 bpm will be the minimum heart rate measured [6]. 30bpm will give a 10 bpm buffer from the lowest heart rates possible by a human, this will ensure that we capture all low end heart rates.

The rate at which a human can breathe depends on multiple factors including age, physical activity or shock. To be in compliance with the start model, we must detect wether a heart rate is above or below 30bpm. The literature reviewed states that the fastest a human can breathe is 60bpm, so for this project a 10bpm buffer will be added to ensure all upper bound respiratory rates are captured. For the lower bound, the START model considers the person dead if they are not breathing, so 1bpm will be the lower bound scanned for breathing.


## BOM


| Name of Device | Cost |
|----------------|------|
| NJR4262 New Japan Radio Co, 24 GHz Doppler Sensor Module | $34.07 |
| High Precision AD HAT Board Waveshare ADC Module | $47.99 |
| 40k resistors X2 | $1.08 |
| 60k resistors X2 | $1.08 |
| Op-Amp X2 | $1.50 |
|Total | $85.72 |

## Sources

[1] “Radiation: Radar,” _World Health Organization_. [Online]. Available: https://www.who.int/news-room/questions-and-answers/item/radiation-radar#:~:text=Exposure%20to%20RF%20fields%20above,dangerous%20amounts%20of%20radio%20frequencies%3F. [Accessed: 28-Mar-2023]. 

[2] Y. Iwata, H. T. Thanh, G. Sun, and K. Ishibashi, “High accuracy heartbeat detection from CW-Doppler radar using singular value decomposition and matched filter,” _Sensors (Basel, Switzerland)_, 21-May-2021. [Online]. Available: https://www.ncbi.nlm.nih.gov/pmc/articles/PMC8196719/. [Accessed: 17-Apr-2023]. 

[3] “K-band Doppler Sensor Module - Mouser Electronics.” [Online]. Available: https://www.mouser.com/datasheet/2/294/NJR4262_rev00-02-1710760.pdf. [Accessed: 17-Apr-2023]. 

[4] J.-H. Park, Y.-J. Jeong, G.-E. Lee, J.-T. Oh, and J.-R. Yang, “915-mhz continuous-wave Doppler radar sensor for detection of vital signs,” MDPI, 20-May-2019. [Online]. Available: https://www.mdpi.com/2079-9292/8/5/561. [Accessed: 19-Apr-2023].

[5]DiGiacinto, Jessica. “Normal Heart Rate: Range, When It's Dangerous, and More.” _Healthline_, Healthline Media, 7 Jan. 2022, https://www.healthline.com/health/dangerous-heart-rate#maximum-heart-rate. 

[6]“Low Heart Rate: What It Is and When to Worry.” _Cleveland Clinic_, 17 Mar. 2023, https://health.clevelandclinic.org/is-a-slow-heart-rate-good-or-bad-for-you/#:~:text=Doctors%20consider%20a%20heart%20rate%20below%2060%20beats,below%2060%20even%20when%20you%E2%80%99re%20awake%20and%20active. 

