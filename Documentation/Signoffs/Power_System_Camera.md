# Power System for Camera System
## Functionality
The primary functionality for the camera power system is to reliably meet the power requirements for the camera system's components. The system will supply 5 V to the camera system's microcontroller, motors, and camera.

## Constraints
| No.| Contraint | Origin |
| -- | --------- |--------|
|  1 | The system shall comply with ASTM B258-18 [2]. | Standards and Safety |
|  2 | The system shall be weather resitant to an IP67 rating [1].  | Standards and Safety |
|  3 | The system shall be able to supply enough power to the camera system for its full functionality | Design Team | 


      
<sup>1</sup> ASTM B258-18 is a standard for the proper wire gauge for electrical conductors. It is important to adhere to this standard to ensure the system is safe and avoid overheating, short circuits, and fires.  <br />

<sup>2</sup> The system will be located outdoors, so it is essential that the electrical components will be protected from environemental weather hazards and damage. The IP67 rating protect the system from cover rain, snow, dust, wind, and UV. <br />

<sup>3</sup> This statement is obviously the most important, because the power system must supply the proper power for the camera system to acheive its functionality for the project. <br />


## Schematic
<img width="1068" alt="Screenshot 2024-05-02 at 7 14 50 PM" src="https://github.com/mrnye42/Drone-Tracker-Project/assets/158224821/7252949e-e0d9-45f6-8259-16c696b38bbd">
<br />
Figure 1: Camera Power Schematic.<br />
The above schematic shows connections for the system. The schematic will be detailed with the signoff of the camera system, since the design of this power system will lag the camera system's design in case of changes required.




## Analysis
| Component| Voltage (V) | Current (A) | Power (W) |
| -- | --------- |--------|--------|
|  Raspberry Pi 4B 8GB w/ Wi-Fi | 5 | 2.5-3 | 12.5 - 15 |
|  Tilt Servo DS3218 180deg | 5-6.8 | 1.8-2.2 | 9 - 14.96 |
| Pan Servo DS3218mg 270deg  | 5 - 6.8 | 1.5-2.2 | 7.5 - 14.96|
|  ELP 4K USB Camera Manual Zoom 2.8-12mm Variable Focus USB2.0 Web Camera IMX317 8MP | 5 | 0.15 | 0.75 | 

Table 1: Power Requirements.<br />

For this system, five volts is required for all components, so the five volt power supplies will be able to provide power to all the components. The worst case power draw from the system is 45.67 W, so the chosen 100 W power supplies will meet those requirements with plenty of wattage to spare. The cost reduction from a lower wattage power supply is minimal, so we will have some extra power to account for additional functionality added to the camera system. <br />

16 AWG wire is required to comply with ASTM B258-18. Since the maximum amperage for 16 gauge wire is 3.7 A and the maximum amperage for our system is 3 A, the design is in compliance. <br />




## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|     DC 5 V 20 A 100 W Power Supply    |    B07Q2WQ8DS         |     2     |       $19.99         |     $39.98      |
|     Gratury Junction Box, IP67 Waterproof Plastic Enclosure    |    G         |     2     |       $22.94       |     $45.88      |
|     16 AWG Wire   |    NA         |     1     |       $15.88       |     $15.88      |
|Total     |             |          |                |     $101.74      |

## References

Parts List: <br/>
DC 5V 20A Power Supply 5 Volt 100W AC110/230V Transformer Converter <br/>
Amazon: https://www.amazon.com/Switching-Transformer-Converter-Security-Computer/dp/B07Q2WQ8DS/ref=sr_1_5?crid=2NNJALS4ZMRI&dib=eyJ2IjoiMSJ9.uA77Tyck60JatmmiSFg_ZrGXEYzgRCWIX5srcLycU6elgtIznaJgwRmeaF2wiPHy47c2EV4krnNqii1mwbK4pT8tRhv9_pHTd_-GuescktOfzqf2W6LATo3xOFW9KAltodAPYmEETAuiQeumS70tPAzpVhey-EMFCXzCEVr28ngGj8_dUj4wIbL60O3iO35QapcL_ZwR1mmlTFC5ZRgTFc1X_TWA8g1WLJNzXzg21c8.HBIs3HEtyGXW2VnYsJPwdNS65n-OxNkdoxW8B2LsSL8&dib_tag=se&keywords=5%2BV%2Bpower%2Bsupply%2B60%2BW&qid=1714691125&sprefix=5%2Bv%2Bpower%2Bsupply%2B60%2Bw%2Caps%2C156&sr=8-5&th=1<br/>

Gratury Junction Box, IP67 Waterproof Plastic Enclosure for Electrical Project, Hinged Grey Cover, Includes Mounting Plate and Wall Bracket 220×170×110mm (8.6"×6.7"×4.3")<br/>
Amazon: https://www.amazon.com/Gratury-Stainless-Waterproof-Electrical-290×190×140mm/dp/B08281V2RL/ref=sr_1_4?crid=LMQOP431K6NJ&dib=eyJ2IjoiMSJ9.mBk353sclXazbCevDTRupgAnYR4LoPZNXM82VDLejHAkZZhBihGzzSIPHEZ7VyvR2dwCGLaCZtSwFbcA7Ez9K8uovhESl5ULmJ0vOLIi951C07Gc7aK8CLQuCDeOODVOJ5hSfbXTqar76IERBoDECwXYaXLz5wbC7g83sBPWlUSKrOZAh5W-qVV30GRbj2wtLyauQ6l7Ijcn5NThkuDVg3xIlTF66X38ykmcbk4g1QhQw82UWXM0zwdELlYO-Be-ScS8HeW0MSriiczL3RZeL7zlOc7WEgWrwNUzFU2JslQ.ZC2gR9KkI_a1xzkicc4oTMWxYHqfe9ajQmNEM1wUL6w&dib_tag=se&keywords=NEMA%2Bip67%2Bbox&qid=1714691719&s=hi&sprefix=nema%2Bip67%2Bbox%2Ctools%2C208&sr=1-4&th=1<br/>

16 awg Silicone Electrical Wire 2 Conductor Parallel Wire line 60ft [Black 30ft Red 30ft] 16 Gauge Soft and Flexible Hook Up Oxygen Free Strands Tinned Copper Wire <br/>
Amazon: https://www.amazon.com/Silicone-Electrical-Conductor-Parallel-Flexible/dp/B07FMLVF84/ref=sr_1_8?dib=eyJ2IjoiMSJ9.2IdwD35CCLpenfFhIef8bFJRoAVClHHhYCeTX1FM6NKVCsAo_gm5ffLKvcndI2-sfKXhvQRM2T2qwS6ZTu1UB72TCH2vL2oiC1K26hOYacnuvWIZAHny2hhW-KgmAJZ3j3gEjDkIK_mviyK78LNrExJvlVd-nT7RaH3dacUpRfwhVGMP0Y5Eq38f8QO5Y6aYnRhtfhdVyoDk8g-415_Z67tJAWsJYYGin7ydtyyc2gx-hAAupkcEvgkIMBkOgvz1276c8qufbNsNUoRXAxo8xW7pChLhA1_Ikqd5Qn4ITyE.mBL16U3BJIIPIYnoN9O10hhO9Z6R1QkfBhchkv26ffY&dib_tag=se&hvadid=557204068733&hvdev=c&hvlocphy=9013088&hvnetw=g&hvqmt=e&hvrand=5511484594165708181&hvtargid=kwd-11038717084&hydadcr=18888_13353548&keywords=16+awg+copper+wire&qid=1714693636&sr=8-8
