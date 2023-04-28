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
| Operational Amplifier | Operational Amplifier must be able to handle a max 0.8 V peak-to-peak amplitude and a maximum 19.4 KHz frequency. | From further analysis of the radar and cimputing subsystems. |
| Operational Amplifier Circuit (Input) | Circuit must be able to filter out high frequencies with a corner frequency of around 19kHz while at least also amplifying the signals between 0.017Hz - 3.5Hz by a gain of 6. The corner frequency comes from satisfying nyquist value for a sample frequency of 38.4kHz as specified by the ADC datasheet.| From further analysis of the radar and computing subsystems. |
| Operational Amplifier Circuit (Output) | The gain of 6 comes from a 0.8 Vp-p input voltage of the radar as specified by the datasheet which needs to reach no more then 5 Vp-p output voltage as specified by the ADC datasheet. The frequency minimum of 0.017 Hz comes from the total bandwidth needed by heartbeat and respiratory rate frequencies. | From further analysis of the radar and computing subsystems. |

## Wiring Schematics



![image](https://user-images.githubusercontent.com/79685126/232992358-859ff652-7a55-444c-bf29-dbeecf625869.png)


Figure 1. Wire Diagram for the total subsystem



![Opamp](https://user-images.githubusercontent.com/123600489/234730931-13940bd6-ed75-4804-ab09-045ba9871d29.png)

Figure 2. Operational amplifier circuit diagram



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

6.) The CW-Doppler Radar such as the NJR4262 functions like the diagram below

![image](https://user-images.githubusercontent.com/79685126/234786336-ca0aacec-f6b3-4ad9-afbf-457053c9c566.png)

The local oscillator (LO) creates the frequency needed for transmission, this signal is mixed with the received radar signal (circle with an x) and also phase shifted and put through another mixer with the received signal in order to down convert the signal. These mixers demodulate the signal allowing for both BI(t) and BQ(t) to be at much lower frequencies. This is further evidenced by the equations in part 5. The R(t) signal as well as the T(t) signal have a “2pif” part in them. The f represents the carrier frequency, in NJR4262 radars case 24GHz. This part is no longer part of the BI(t) and BQ(t) equations, rather the frequency is controlled by x(t) which is the displacement frequency information. This means the input to an amplifier circuit is much lower frequencies than the 24 GHz carrier, and the input data can also be filtered to retrieve a smaller range of frequencies that incorporate the data needed for heartbeat and respiratory rate detection.   
This is why the amplifying circuit will also double as a pre-filter for the system. The ADC used for this subsystem can only sample at rate of 38.4 kHz (samples per sec), using nyquists principle that sampling frequency must be at least double the bandwidth (fs  >= 2B) to get an accurate conversion, the highest frequency that can be accurately converted is 19.4 kHz. The radar outputs many different frequencies due to displacement in the measured area. Due to the limitations of the ADC only frequencies under 19.4 kHz can be accurately represented meaning everything above becomes unusable and just noise. To take out all these high frequencies a low pass filter can be used, such as the one in figure 2. Using standard resistor and capacitor values the corner frequency of figure 2 is 19.41 kHz. 

The transfer function of figure 2 comes out to be H(s) = (0.00252s +1800)/(1.3776e-12s^2 +0.02711s +3000). The figure below plots the frequency response of the above transfer function.

![image](https://user-images.githubusercontent.com/79685126/234519148-3ac49142-b0cc-4e85-b27b-6cdffc2cf717.png)

As detailed by the plot all the unusable high frequencies are filtered out leaving the data for frequencies needed with the respective gain of about 15.5 dB which corresponds to a gain of 5.96. 

The input of the ADC can accept voltages of max 5 Vp-p. This means the input signal, which has a 0.8 V p-p, also needs to be amplified around a factor of 6 to optimize the ADC range. As detailed by the frequency response this is met by a wide range of frequencies, but more importantly as detailed by the constraint it needs to amplify at least 0.017 Hz - 3.5 Hz as these are the frequencies that will be used by the algorithm.  Below is the LTSpice simulation of the lower bound 0.017 Hz signal  

![image](https://user-images.githubusercontent.com/79685126/234519214-ca810c4c-f3a8-4d6b-bc71-800a6f7643a3.png)

While the next simulation looks at the upper bound of 3.5 Hz signal.

![image](https://user-images.githubusercontent.com/79685126/234519257-796e4e99-cad9-4774-9077-e7306fd7ebd5.png)

In both cases the gain is met while also staying under the 5 Vp-p limitation set by the ADC. The needed frequencies are amplified while unuseful high frequencies are also filtered out as specified by the constraint.

The OP7CSZ operational amplifier to be used in this circuit must be able to take an input of atleast 0.8 V peak-to-peak since that is the amplitude of the output of the radar. The OP7CSZ has a maximum input voltage of 22 V according to the datasheet, so the operational amplifier could handle this level of voltage output from the radar. Since the filter built before the operational amplifier is limited to a maximum of 19.4 kHz, the OP7CSZ has to be able to handle that frequency in order to function properly. According to the datasheet, the OP7CSZ has a closed-loop bandwidth of 0.6 MHz; this allows for the 19.4 kHz max input signal going into the operational amplifier to be easily amplified with no worries of a large distortion of the input signal. 


The range that a human heart can beat varies depending on the age, and other factors, of the person. A quick good way to estimate the maximum heart rate is to subtract the age by 220. The literature reviewed for this makes this estimation valid down to 10 year olds, so 210 bpm will be the maximum heart rate measured [5]. For the lower bound, typically anything below 60 is considered a low heart rate and could be dangerous. According to the literature reviewed, heart rates can reach down to 40 when sleeping as an extreme low, so 30 bpm will be the minimum heart rate measured [6]. 30bpm will give a 10 bpm buffer from the lowest heart rates possible by a human, this will ensure that we capture all low end heart rates.

The rate at which a human can breathe depends on multiple factors including age, physical activity or shock. To be in compliance with the start model, we must detect wether a heart rate is above or below 30bpm. The literature reviewed states that the fastest a human can breathe is 60bpm, so for this project a 10bpm buffer will be added to ensure all upper bound respiratory rates are captured. For the lower bound, the START model considers the person dead if they are not breathing, so 1bpm will be the lower bound scanned for breathing.


## BOM


| Name of item | Description | Part Number | Manufacturer | Quantity | Price | Total |
|--------------|-------------|-------------|--------------|----------|-------|-------|
| K-Band Doppler Sensor Module | 24 GHz Doppler Sensor Module | NJR4262J | JRC | 1 | $34.07 | $34.07 |
| High Precision AD HAT | High Precision AD HAT Board Waveshare ADC Module | ADS1263 | Waveshare | 1 | $47.99 | $47.99 |
| Op Amp | Perscision Amplifier | OP07CSZ | Texas Instruments | 2 | $2.31 | $4.62 |
| Resistor | 1k Ohm 5% 1/4W axial resistor | CF14JT1k00 | STackpole Electronics Inc | 2 | $0.10 | $0.20 |
| Resistor | 3k Ohm 5% 1/4W axial resistor | CF14JT3k00 | STackpole Electronics Inc | 2 | $0.10 | $0.20 |
| Resistor | 15k Ohm 5% 1/4W axial resistor | CF14JT15k0 | STackpole Electronics Inc | 2 | $0.10 | $0.20 |
| Capacitor | Mica 56 pF 5% 500V Radial | CD15ED560JO3F | Cornell Dubilier Electronics (CDE) | 2 | $2.61 | $5.22 |
| Capacitor | Mica 8200 pF 5% 500V Radial | CD30FD822JO3F | Cornell Dubilier Electronics (CDE) | 2 | $19.94 | $39.88 |
| PCB Board | 50 Pcs Double Sided PCB Board Prototype Kit | DLB01 | SINGARE | 1 | $13.97 | $13.97 |
| Solder | MAIYUM 63-37 Tin Lead Rosin Core Solder Wire for Electrical Soldering (0.8 mm 100g) | 43188-464408 | MAIYUM | 1 | $11.59 | $11.59 |
|Total |  |  |  |  |  | $157.94 |

## Sources

[1] “Radiation: Radar,” _World Health Organization_. [Online]. Available: https://www.who.int/news-room/questions-and-answers/item/radiation-radar#:~:text=Exposure%20to%20RF%20fields%20above,dangerous%20amounts%20of%20radio%20frequencies%3F. [Accessed: 28-Mar-2023]. 

[2] Y. Iwata, H. T. Thanh, G. Sun, and K. Ishibashi, “High accuracy heartbeat detection from CW-Doppler radar using singular value decomposition and matched filter,” _Sensors (Basel, Switzerland)_, 21-May-2021. [Online]. Available: https://www.ncbi.nlm.nih.gov/pmc/articles/PMC8196719/. [Accessed: 17-Apr-2023]. 

[3] “K-band Doppler Sensor Module - Mouser Electronics.” [Online]. Available: https://www.mouser.com/datasheet/2/294/NJR4262_rev00-02-1710760.pdf. [Accessed: 17-Apr-2023]. 

[4] J.-H. Park, Y.-J. Jeong, G.-E. Lee, J.-T. Oh, and J.-R. Yang, “915-mhz continuous-wave Doppler radar sensor for detection of vital signs,” MDPI, 20-May-2019. [Online]. Available: https://www.mdpi.com/2079-9292/8/5/561. [Accessed: 19-Apr-2023].

[5]DiGiacinto, Jessica. “Normal Heart Rate: Range, When It's Dangerous, and More.” _Healthline_, Healthline Media, 7 Jan. 2022, https://www.healthline.com/health/dangerous-heart-rate#maximum-heart-rate. 

[6]“Low Heart Rate: What It Is and When to Worry.” _Cleveland Clinic_, 17 Mar. 2023, https://health.clevelandclinic.org/is-a-slow-heart-rate-good-or-bad-for-you/#:~:text=Doctors%20consider%20a%20heart%20rate%20below%2060%20beats,below%2060%20even%20when%20you%E2%80%99re%20awake%20and%20active. 

