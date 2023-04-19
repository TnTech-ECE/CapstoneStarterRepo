# Heartbeat/Respiratory Subsystem 

## Subsystem Function

The purpose of this subsystem is to measure the presence of a heartbeat as well as measure the respiratory rate of a person contactlessly. This subsystem will be composed of a singular radar that will perform both of these actions. The measuring of a person’s presence of a heartbeat as well as respiratory rate will be done by measuring the rise and fall rates of a person’s chest to measure the respiratory rate, and the rise and fall rates of the area around the heart to measure the presence of a heartbeat. A series of signals will be sent and received to measure these changes. The raw data will be put through an amplifier/filter and then be converted to a digital signal that is sent to a computing system to be put through a processing algorithm,

## Specs and Constraints			


| Description | Constraint | Source of Constraint |
|-------------|------------|----------------------|
| Heartbeat analysis | Must sense Beats per minute from 27 to 200 bpm (or frequencies from 0.45 Hz to 3.33 Hz) | From Conceptual Design, from Heartbeat/Respiratory System section |
| Respiratory sensor | Must sense breaths per minute from 7.8 to 30 bpm (or frequencies from 0.13 Hz to 0.50 Hz) | From Conceptual Design, from Heartbeat/Respiratory System section |
| Distance | Must detect and measure heartbeat and breath rate from at least 1 meter away | From DARPA constraints |
| Weight | Entire system must weigh less than 6 pounds, this subsystem should weight 1.5 lbs or less | From DARPA constraints/ Conceptual design |
| Safety | Radar must not emit at a frequency over 10 GHz with a power density of 1000 W/m^2 in order to keep the radar skin and eye safe. | From World Health Organization (WHO) |


## Wiring Schematics



<p id="gdcalert1" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image1.jpg). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert2">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>


![alt_text](images/image1.jpg "image_tooltip")


Figure1. Wire Diagram for the total subsystem



<p id="gdcalert2" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image2.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert3">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>


![alt_text](images/image2.png "image_tooltip")


Figure 2. Circuit schematic for active pass band amplifier

**Analysis:**

1+2.) The 24 GHz doppler  radar functions by transmitting a signal described by the equation T(t) = 

<p id="gdcalert3" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: equation: use MathJax/LaTeX if your publishing platform supports it. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert4">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>

. This then hits the target and reutrns the function listed below.



<p id="gdcalert4" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image3.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert5">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>


![alt_text](images/image3.png "image_tooltip")
 

*Equation taken from [2]

As shown by the datasheet and the pin layout of the NJR4262J this signal is put through a mixer to separate in-phase signal (I(t)) and the quadrature phase signal (Q(t)) as shown below



<p id="gdcalert5" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image4.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert6">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>


![alt_text](images/image4.png "image_tooltip")


*Equation taken from [2]

In these equations the As stand for amplitude, the different 

<p id="gdcalert6" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: equation: use MathJax/LaTeX if your publishing platform supports it. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert7">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>

 are for phase constants and phase shifts, the 

<p id="gdcalert7" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: equation: use MathJax/LaTeX if your publishing platform supports it. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert8">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>

 is the carrier wavelength, the d is the distance from the target, but most importantly x(t) correlates to the displacement in the human body surface [2]. This can be broken up into x(t) = xheart + xresp + everything else. To retrieve this information from the I/Q data the following equation can be used 



<p id="gdcalert8" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image5.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert9">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>


![alt_text](images/image5.png "image_tooltip")


*Equation taken from [2]

With this information the line of thinking for the algorithm to retrieve the heartbeat and respiratory data needed to conform to the listed constraints goes as follows. The baseband signal from the I and Q pins of the NJR4262J are sent through an amplifier circuit with a gain of 3 listed in Figure 2. The NJR4262 datasheet states a typical signal level of 0.8 Vp-p, with a gain of 3, this puts the output I and Q signals at a gain of 2.4 Vp-p which matches the input range of the AD HAT board ADC module. The digital signals can then be transmitted directly to the jetson for signal processing. The next step is to demodulate the I/Q data using the x(t) equation above and retrieve all the chest displacement data from the signal. With this data, a band pass filter can now be used to extract the specified constraint frequency data for both heart rate and respiratory rate. The combined frequency range needed and lower and upper frequency ranges of the pass band filter is 0.13 Hz - 3.33 Hz. 

With the heartbeat and respiratory rate data retrieved, a matched filter can then be used to maximize the signal-to-noise ratio separating the heartbeat and respiratory peaks from the noise. Once this signal is achieved the Fast Fourier Transform can be taken (FFT) to get the magnitude and frequencies found in the signal. The chest moves between 0.2-0.5 mm due to the heart beat while between 2 - 12.6 mm due to respiratory rate. This discrepancy in displacement will help differentiate the heartbeat data versus the respiratory data. The peaks can then be retrieved matching the respective frequency range and magnitude values for chest movement matching respiratory and heart rate values listed in constraints. 

As a proof of concept [2] [4] took a similar approach to the algorithm above and [2] got simulated data as follows



<p id="gdcalert9" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image6.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert10">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>


![alt_text](images/image6.png "image_tooltip")


         

While [4] got data 



<p id="gdcalert10" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image7.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert11">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>


![alt_text](images/image7.png "image_tooltip")


In both cases taking out the harmonics there is a clear peak at the respective chest movement values and frequencies that match a heart beat rate and respiratory rate.

3.) As stated by the NJR4262J datasheet states the typical radiated power to be 16 dBm or 40 mW. This allows for the sensor to function well over the 1 meter limit set by the constraint above. The exact valuation depends on the specific environment the radar will be functioning in, but as a comparison a radar with a 20 dBm radiated power (which happens to be the NJR4262J’s max power range) can reach 1 km range. 

4.) Once again as stated by the datasheets the NJR4262J weighs a max 7g or 0.0022 lb. The AD HAT Board weighs 19.96 g or 0.044 lb, and the two circuits are approximately 5g or 0.011 lb each. This brings the approx total to 31.96 g or 0.0704 lb which is well below the limit set by the weight constraint. This will allow some weight to be allotted to the more heavy subsystems such as the computing and power subsystem.

5.) WHO sets the power density safety limit at 1000 W/m^2 for radars over 10 GHz. With the  NJR4262J being a 24 GHz radar this would mean its power density must be under this value.  The datasheet sets the max radiated power of the radar at 100 mW. The unit’s dimensions are also 25 X 25 X 7.3 millimeters. This would put the power density at 160 W/m^2  ,which falls below the safety limit and confirms the final constraint listed above.

  

## BOM:



*  NJR4262 New Japan Radio Co, 24 GHz Doppler Sensor Module - $34.07
* High Precision AD HAT Board Waveshare ADC Module - $47.99
* 40k resistors X2 - $1,08
* 60k resistors X2 - $1.08
* Op-Amp X2 -$1.50

## Sources: 

[1] “Radiation: Radar,” _World Health Organization_. [Online]. Available: https://www.who.int/news-room/questions-and-answers/item/radiation-radar#:~:text=Exposure%20to%20RF%20fields%20above,dangerous%20amounts%20of%20radio%20frequencies%3F. [Accessed: 28-Mar-2023]. 

[2] Y. Iwata, H. T. Thanh, G. Sun, and K. Ishibashi, “High accuracy heartbeat detection from CW-Doppler radar using singular value decomposition and matched filter,” _Sensors (Basel, Switzerland)_, 21-May-2021. [Online]. Available: https://www.ncbi.nlm.nih.gov/pmc/articles/PMC8196719/. [Accessed: 17-Apr-2023]. 

[3] “K-band Doppler Sensor Module - Mouser Electronics.” [Online]. Available: https://www.mouser.com/datasheet/2/294/NJR4262_rev00-02-1710760.pdf. [Accessed: 17-Apr-2023]. 

[4] J.-H. Park, Y.-J. Jeong, G.-E. Lee, J.-T. Oh, and J.-R. Yang, “915-mhz continuous-wave Doppler radar sensor for detection of vital signs,” MDPI, 20-May-2019. [Online]. Available: https://www.mdpi.com/2079-9292/8/5/561. [Accessed: 19-Apr-2023].
