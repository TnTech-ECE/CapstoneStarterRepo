# Launcher Housing
## Functionality 
The launcher housing will provide power to the other subsystems connected to the main interceptor body, provide a functional E-Stop button, have a lighting system, and have a firing alarm. The power system will be made up of two power supplies, a 36 V to 12 V step down converter, a low level 5 V 2 channel relay, 4 power distribution blocks, and a latching twist to turn on push button. Lighting will be done with two 1 meter long LED strips in purple and gold colors. A 12 V buzzers will be used for the firing alarm.  
## Constraints 
* C3: Create an interceptor capable of fitting inside a 1x1x1 foot box before powering on.  
* C4: Create an interceptor that poses no danger to spectators.  
* C5: Include a clearly marked power switch on the interceptor.
* C6: Include a clearly marked emergency stop option on the interceptor.  
* C10: Design an interceptor that has lights.  
* C11: Design an interceptor with decorations contributing to camouflaging of the device.  
* C12: Design an interceptor which plays an alert noise before firing.  

## Buildable Schematics
### Electrical Schematic 
![alt text](https://github.com/JTJones73/Capstone2024-Team2/blob/arwatson42-Housing/Documentation/Signoffs/Housing_Schematic_Diagram.png)
The electrical schematic shows the connections between the wall and the power supplies [1] and [2] via the switching extension cord [3]. The schematic then shows the configuration of the E-stop [4] with and the connection to the DC-DC step down converter [5]. Connecting each of these to a bus enables the entire interceptor to be powered. The schematic also shows the connection between the Raspberry Pi 5, the relay [6], the LED strips [7] and [8], and the piezo buzzer [9]. The power 36V power supply was chosen in order to provide adequate power for the 30V steppers used in the aiming section while the 5V power supply was chosen in order to provide the raspberry pi with clean reliable power. The switching extension cord was chosen as it permits adequate current draw in addition to having switches which will sever as the interceptors power switches. The E-stop button was chosen in order to minimize potential points of failure within the E-Stop system by minimizing the amount of connections the E-Stop system will need. The DC-DC step down converter was chosen as it provides adequate current to all components on the 12V rail. The low level 5V relay was chosen as it allows the processor to easily control both the buzzer and LED systems. The buzzer was chosen since it emits an adequate sound to alert bystanders while the two LED strips were selected due to the relatively low power draw they have while also being fairly close to the colors of the school. 

## Analysis
### Power system 
The 5V 5.1A power supply [2] manufactured by raspberry pi was selected in order to provide noise free power to the Raspberry Pi 5. It will provide enough power to utilize all the features of the processor as it was designed specifically to power that unit. 

In order to provide power to the other subsystems on the main interceptor body a 36V 9.7A AC-DC power supply was selected [1]. This power supply can provide up to 350W if needed. Due to the turntable motor requiring 30V and up to 4A a power supply of at least 120 W was required to run the turntable motor in a worse case scenario. In order to convert from the 36V rail to the 12V rail the a 12V 10A DC-DC converted was selected. The selected converter has an efficiency of 90% meaning at max power draw it can draw up to 132W. This places the theoretical max power draw from the interceptor body at 252W. Due to common wattage values for 36V powers supplies jumping from 250W to 350W the 350W unit was selected in order to give headroom should the max power draw occur.  

In order to deliver AC power to the selected power supplies a power cord capable of conducting the needed voltage for the PSUs. Each PSU will run off of 120V AC as such the selected switching cord [3] is capable due to the 18 AWG and 16 AWG cables used. The selected cord also has two power switches which will serve to meet constraint 5.

### E-Stop
The E-Stop button requires a button capable of conducting up to 10A at 660V when the connection is closed. As such [4] was selected. Additionally the selected button is latching and normally closed. This adds an extra layer of protection by ensuring that the default state of the pressed E-Stop is to turn the motors off. 
### 12V Rail
To step down to 12V from 36V the 12V 10A DC-DC step down converter [5] was selected. This converted can supply up to 120W of power to the systems on the 12V rail. The power draw from the LED strips [7] and [8] is 14.8W per meter meaning to power the two LED strips at worse case will take 30W of power. The buzzer [9] has a max current draw of 22mA meaning at 12V the power draw from the buzzer would be 2.64W. The launch angle motor at worse case will draw up to 2A at 12V meaning a power draw of 24W. Finally the firing motor has a maximum current draw of 1.6A at 12V for a total power draw of 19W. This puts the total power draw of the 12V rail at 76W. As the selected converter can provide 120W maximum it will be more than sufficient to supply the 12V rail with headroom. 

### Relay
The relay module [6] can sustain two loads up to 30V 10A DC while needing only a 5V signal to operate. Given that the LEDs have a combined power draw of 30W and the buzzer only has a draw of 2.64W the relays have sufficient capacity. The module being a dual module is an effort to reduce cost as the combined module is cheaper than buying two separate lower power relays. 

### LEDs 
The lighting of the interceptor only needs to be visable to observers. To verify that the purple LED strip will be visable in brighter enviroments the video on the information page was used. At timestamp 3:31 the video shows the LED with brighter ambient light against a brighter background. The color of the LEDs can still be seen. 

The gold LED strip also has a video on its page. This video shows the gold LED strip powered on in a bright department store at timestamp 7:57. The color of the LED strip can be clearly seen both from the campera facing the strip and the reflection of the light produced seen on the other camera. 

### Buzzer 
The selected buzzer has a volume output of 68 dB at 60 CM when supplied with 10V. This noise level will increase at 12V. Refering to [13] a sound of 70 dB is considered loud. Given this the sound of the buzzer will be sufficiently loud enough to be an alarm. 

### Connections 
In order to connect the subsystems together wiring capable of carrying sufficient current was required. Additionally terminal blocks were used to create the voltage busses and a secure connection between the relays and the LED strips. The selected wire [10] is 16 AWG which can have 15.8A of current pushed at a distance of less than 1 foot. Due to the interceptor being a 1x1x1 foot square the longest wiring run would be 1 foot. Therefor 16 AWG wire is sufficient as it has a higher current rating than the output current of any of the power systems. The terminal blocks and jumpers [11] are rated for 15A . Again this is above the 10A output by any power system and therefor is sufficient. Finally 12-22 AWG crimp connectors [12] will be used to connect stranded wire to the terminal blocks to ensure safety. 

## Bill of Materials
| Name of Item   | Description                                                                  | Part Number     | Manufacturer     | Quantity     | Price      | Total   |
|----------------|------------------------------------------------------------------------------|-----------------|------------------|--------------|------------|---------|
| 350W Power Supply | Power supply for the 36V and 12V rails | LRS-350N2-36 | Mean Well USA Inc. | 1 |$40.02 | |
| 27W Power Supply | Power supply for the Raspberry Pi 5 | SC1153 | Raspberry Pi | 1 | $12.00 |  |
| Switching Extension Cord|  2-Way 3 Prong Extension Cord with ON/Off Switch | ----| STARELO | 1 | $17.99 | |
| E-Stop Button |SWITCH ESTOP PULL RESET 10A 660V | ----| mxuteuk | 1| $8.99 | |
| DC/DC Converter | DC/DC CONVERTER 12V 120W|FIT0170 | DFRobot| 1| $29.00| |
| 2 Channel relay| 5V Low Level 2 channel relay | TS0010D| SunFounder| 1|$6.12 | |
| Purple LED Strip| 1 m LED strip for lighting| 4117| iPixel LED Light Co. | 1| $13.95| |
| Warm White LED Strip|1 m LED strip for lighting | 3866| iPixel LED Light Co.| 1 | $13.95| |
| Buzzer | BUZZER PIEZO 42.98MM PNL MNT | SC648R| Mallory Sonalert Products Inc.| 1| $11.96| |
| 16 AWG Wire| CABLE 2COND 16AWG BLK/RED 1M| 30-02855| Tensility International Corp| 1|$5.24 | |
| Terminal Blocks & Jumpers| Terminal blocks and jumpers to make the voltage busses| ----| ElevsHome |1 |$12.99 | |
|16 AWG Crimp Connectors | Connectors to connect stranded wire to terminal blocks | 130014| TE Connectivity AMP Connectors| 20| $5.56 | |
| Total          |                                                                              |                 |                  |              | Total Cost | $177.77|

## References
[1] 350W Power Supply: https://www.digikey.com/en/products/detail/mean-well-usa-inc/LRS-350N2-36/21531512

[2] 27W Power Supply: https://www.digikey.com/en/products/detail/raspberry-pi/SC1153/21658276?utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_High%20ROAS%20Categories&utm_term=&utm_content=&gad_source=1&gclid=Cj0KCQjw5cOwBhCiARIsAJ5njub_RbX7oVqwdK9EKF0f0Dt8D7Kc9OGP2AeqPFMyzdD_JlyGdP7ucqYaAvCkEALw_wcB

[3] Switching Extension Cord: https://www.amazon.com/Extension-Switch-Prong-Outdoor-Splitter/dp/B0B5DNT557/ref=asc_df_B0B5DNT557/?tag=hyprod-20&linkCode=df0&hvadid=680405325051&hvpos=&hvnetw=g&hvrand=10259807044143612348&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9013674&hvtargid=pla-1960226653412&mcid=7c7057f75aba3adf93d1096345dfea5e&gad_source=1&th=1

[4] https://www.amazon.com/mxuteuk-Mushroom-Emergency-Warranty-HB2-BS542/dp/B07R4J2Z54/ref=asc_df_B07R4J2Z54/?tag=&linkCode=df0&hvadid=385401161937&hvpos=&hvnetw=g&hvrand=17234533040121678490&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1025954&hvtargid=pla-838156276780&mcid=b2580346654d317cab69a5ee91c65282&ref=&adgrpid=80249224042&gclid=Cj0KCQjwq86wBhDiARIsAJhuphletlr7kWpITR1lMhnkAoI73Gumfzjyz5JZzmfFfv808RJu31RnwMcaApSsEALw_wcB&th=1

[5] DC/DC Converter: https://www.digikey.com/en/products/detail/dfrobot/FIT0170/7067688

[6] 2 Channel Relay: https://www.digikey.com/en/products/detail/sunfounder/TS0010D/18668618?utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_Low%20ROAS%20Categories&utm_term=&utm_content=&utm_id=go_cmp-20243063506_adg-_ad-__dev-c_ext-_prd-18668618_sig-Cj0KCQjwn7mwBhCiARIsAGoxjaItUl1yjb_Qnv_kPcb1fu8AdnITr058gHNPCBow54C-SMXUWBwNeREaAqtQEALw_wcB&gad_source=1&gclid=Cj0KCQjwn7mwBhCiARIsAGoxjaItUl1yjb_Qnv_kPcb1fu8AdnITr058gHNPCBow54C-SMXUWBwNeREaAqtQEALw_wcB

[7] Purple LED Strip: https://www.adafruit.com/product/4117

[8] Warm white LED Strip: https://www.adafruit.com/product/3866

[9] Buzzer: https://www.digikey.com/en/products/detail/mallory-sonalert-products-inc./SC648R/1015001?utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_Low%20ROAS%20Categories&utm_term=&utm_content=&utm_id=go_cmp-20243063506_adg-_ad-__dev-c_ext-_prd-1015001_sig-Cj0KCQjwn7mwBhCiARIsAGoxjaLYf0d8tslIxz1JcTkl6kUYYvaEhtPPpV3vu-1nKILHhTEbzNazxU8aAisUEALw_wcB&gad_source=1&gclid=Cj0KCQjwn7mwBhCiARIsAGoxjaLYf0d8tslIxz1JcTkl6kUYYvaEhtPPpV3vu-1nKILHhTEbzNazxU8aAisUEALw_wcB

[10] 16 AWG Wire: https://www.digikey.com/en/products/detail/tensility-international-corp/30-02855/17139317?utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_Category_Cables%20and%20Wires&utm_term=&utm_content=&utm_id=go_cmp-20053924771_adg-_ad-__dev-c_ext-_prd-17139317_sig-Cj0KCQjwn7mwBhCiARIsAGoxjaIIbjvRHpg3YNG3rdQimQBAdoRmIRjevE2bzPZcZBuUrVkR-Q-mPp8aAupdEALw_wcB&gad_source=1&gclid=Cj0KCQjwn7mwBhCiARIsAGoxjaIIbjvRHpg3YNG3rdQimQBAdoRmIRjevE2bzPZcZBuUrVkR-Q-mPp8aAupdEALw_wcB

[11] Terminal Blocks & Jumpers: https://www.amazon.com/Terminal-Circuit-Positions-Insulated-Electrical/dp/B09QHSLJJ3/ref=asc_df_B08P46WVJX/?tag=hyprod-20&linkCode=df0&hvadid=475819747872&hvpos=&hvnetw=g&hvrand=7722148685346481880&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1025954&hvtargid=pla-1187918727069&mcid=059a30ce74dc30e7927ab0364c34a541&gclid=CjwKCAjwwr6wBhBcEiwAfMEQs8CeEoW6PLYqj9vyqKeFqVK2jKfl1_L9VXt6TA_K5W1TDNStIsNGAhoCmgQQAvD_BwE&th=1

[12] 16 AWG Crimp Connectors: https://www.digikey.com/en/products/detail/te-connectivity-amp-connectors/130014/1148802?utm_adgroup=General&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_Zombie%20SKUs&utm_term=&utm_content=General&utm_id=go_cmp-17815035045_adg-_ad-__dev-c_ext-_prd-1148802_sig-Cj0KCQjwn7mwBhCiARIsAGoxjaIiN3QXyjbh9_6Woh91eR4in8u1H5J6SfLKGBquQJ4INWWz_MRii0AaAi1ZEALw_wcB&gad_source=1&gclid=Cj0KCQjwn7mwBhCiARIsAGoxjaIiN3QXyjbh9_6Woh91eR4in8u1H5J6SfLKGBquQJ4INWWz_MRii0AaAi1ZEALw_wcB

[13] Noise level information: https://www.mdhearingaid.com/blog/decibel-chart/




