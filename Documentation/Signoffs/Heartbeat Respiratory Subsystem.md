# Heartbeat/Respiratory Subsystem 

## Subsystem Function

The purpose of this subsystem is to measure the presence of a heartbeat as well as measure the respiratory rate of a person contactlessly. This subsystem will be composed of a singular radar that will perform both of these actions. The measuring of a person’s presence of a heartbeat as well as respiratory rate will be done by measuring the rise and fall rates of a person’s chest to measure the respiratory rate, and the rise and fall rates of the area around the heart to measure the presence of a heartbeat. A series of signals will be sent and received to measure these changes. The raw data will be put through an amplifier/filter and then be converted to a digital signal that is sent to a computing system to be put through a processing algorithm,

## Specs and Constraints			


<table>
  <tr>
   <td>Description
   </td>
   <td>Constraint
   </td>
   <td>Source of Constraint
   </td>
  </tr>
  <tr>
   <td>Heartbeat analysis
   </td>
   <td>Must sense frequencies from 0.45 Hz to 2.92 Hz
   </td>
   <td>From Conceptual Design, from Heartbeat/Respiratory System section
   </td>
  </tr>
  <tr>
   <td>Respiratory sensor
   </td>
   <td>Must sense frequencies from 0.13 Hz to 0.50 Hz
   </td>
   <td>From Conceptual Design, from Heartbeat/Respiratory System section
   </td>
  </tr>
  <tr>
   <td>Distance
   </td>
   <td>Must detect and measure heartbeat and breath rate from at least 1 meter away
   </td>
   <td>From DARPA constraints
   </td>
  </tr>
  <tr>
   <td>Weight
   </td>
   <td>The drone specfiied in conceptual design had a max load of 2.7 kg. Seeing as 4 subsystems will be attached to the drone. The max weight must not exceed 675g.
   </td>
   <td>From DARPA constraints/ Conceptual design
   </td>
  </tr>
  <tr>
   <td>Safety
   </td>
   <td>Radar must not emit at a frequency over 10 GHz with a power density of 1000 W/m^2 in order to keep the radar skin and eye safe.
   </td>
   <td>From World Health Organization (WHO)
   </td>
  </tr>
</table>


## Wiring Schematics



![image](https://user-images.githubusercontent.com/79685126/232392017-0a4a7bd3-628c-4b52-a798-83140ca588d0.png)




Figure1. Wire Diagram for the total subsystem



![image](https://user-images.githubusercontent.com/79685126/232392095-e65df046-e09a-4af8-b261-0b63a7cdc06c.png)





Figure 2. Circuit schematic for active pass band amplifier

## Analysis

The amplifier/filter circuit is designed to have a passband frequency range of 0.13 Hz and 3.183 Hz as stated by [2}. This range encompasses the respiratory frequencies of 0.13 Hz and 0.50 Hz as well as the heartrate frequencies of 0.45 Hz and 2.92 Hz. This allows for high frequency noise to be taken out and the correct range of data to be converted to a digital signal and further processed by the main computing system

As stated by the NJR4262J datasheet states the typical radiated power to be 16 dBm or 40 mW. This allows for the sensor to function well over the 1 meter limit set by the constraint above. The exact valuation depends on the specific environemnt the radar will be functioning in, but as a comparison a radar with a 20 dBm radiated power (which happens to be the NJR4262J’s max power range) can reach 1 km range. 

Once again as stated by the datasheets the NJR4262J weighs a max 7g, the USB-6008 weighs 84 g with connectors, and the two circuits are approximately 5g each. This brings the approx total to 101g which is well below the limit set by the weight constraint. This will allow some weight to be transferred to the more heavy subsystems such as the computing system.

WHO sets the power density safety limit at 1000 W/m^2 for radars over 10 GHz. With the  NJR4262J being a 24 GHz radar this would mean its power density must be under this value.  The datasheet sets the max radiated power of the radar at 100 mW, the unit is also 25 X 25 X 7.3 mm dimensions. This would put the power density at 160 W/m^2 .which is below the safety limit presents and confirms to the final constraint listed above.

  

## BOM



*  NJR4262 New Japan Radio Co, 24 GHz Doppler Sesnor Module - $34.07
* USB-6008 National Instruments DAQ Device - $123.45
* 33uF Capacitors X 4 - From Lab Kit
* 40k resistors X2 - From Lab Kit
* 1k resistors X2 - From Lab Kit
* Op-Amp X2 - From lab Kit

## Sources 

[1] “Radiation: Radar,” _World Health Organization_. [Online]. Available: https://www.who.int/news-room/questions-and-answers/item/radiation-radar#:~:text=Exposure%20to%20RF%20fields%20above,dangerous%20amounts%20of%20radio%20frequencies%3F. [Accessed: 28-Mar-2023]. 

[2] Y. Iwata, H. T. Thanh, G. Sun, and K. Ishibashi, “High accuracy heartbeat detection from CW-Doppler radar using singular value decomposition and matched filter,” _Sensors (Basel, Switzerland)_, 21-May-2021. [Online]. Available: https://www.ncbi.nlm.nih.gov/pmc/articles/PMC8196719/. [Accessed: 17-Apr-2023]. 

[3] “K-band Doppler Sensor Module - Mouser Electronics.” [Online]. Available: https://www.mouser.com/datasheet/2/294/NJR4262_rev00-02-1710760.pdf. [Accessed: 17-Apr-2023]. 

[4] “Product documentation,” _NI_. [Online]. Available: https://www.ni.com/docs/en-US/bundle/usb-6008-specs/page/specs.html. [Accessed: 17-Apr-2023]. 
