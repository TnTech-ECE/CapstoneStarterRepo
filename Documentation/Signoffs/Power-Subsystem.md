# Power Subsystem

## Functionality
This subsystem is responsible for powering all necessary devices that are present as part of the total sensing system.

## Constraints
| Description | Constraint | Source |
|-------------|------------|--------|
| Operation time | The system shall operate at full functionality for 15 to 60 minutes | Darpa[1] |
| Form of power | The system shall have a power system in the form of a battery | The system is being designed to eventually be attached to a drone which will require an independent, portable power supply. Darpa[1] |
| Weight | The entire project (drone + sensing system) must weigh less than 20 pounds. The team has allocated ___ lbs for the power system | Darpa[1] |
| Powering the Jetson Nano | The Jetson Nano requires a power supply of 5 V and maximum of 4.4 A continuous via a 2.1 mm DC barrel jack. The Jetson Nano has a maximum voltage rating of 5.5 V and a maximum current rating of 5 A | This constraint originates from the computing subsystem required for data processing and to operate the on-board sensors. The specifications come from the Jetson Nano datasheets [2][3] |

## Buildable Schematic

## Analysis
- The system must operate at full functionality for 15 to 60 minutes. The NP-F750 7.4 V 5600 mAh is estimated to power the Jetson Nano with a 4 A draw for approximatley one and a half hour which overshoots our constraint in a good way because the 15 to 60 minute run-time comes from Darpa and their testing simulations for the challenge, so it is better that our system operate for a longer duration. The sensors will use the power connections on the Jetson. The power consumption will have to be tested as the load is increased on the Jetson. Also, the team expects efficiency losses with the coupling of the battery and the buck converter/regulator.
- The form of power shall be a battery. The battery chosen to power the sensing system is a 2 cell lithium-ion battery pack that is rechargable, relativley small in size, and low in weight. It is definitely a mobile subsystem.  
-  The overall system including the drone must be under 20 lbs and the sensing system must be under ___ lbs, so the power system should be around ___ lbs. The power system is weighing in at just under 1 lb. This definitley design will absolutley comply with the weight constraint.
-  The Jetson Nano requires a specific power supply. The buck converter/regulator is going to step down the voltage from 7.4 V to 5.0 V and limits the current to a maximum of 5 A. The battery adapter plate is going to allow easy connection to the battery pack and the regulator. The system will require two 2.1 mm DC barrel jacks with loose leads to connect the batter to the input of the regulator and the second one to connect the output of the regulator to the power supply input of the Jetson Nano. This design makes for an easy setup and meets all specifications for the Jetson Nano. 

## BOM
| Product | Quantity | Price |
|---------|----------|-------|
| [2 Pack] DC-DC 5A Buck Converter 4-38V to 1.25-36V Step-Down Voltage Regulator High Power Module with LED Display | 1 | $13.99 |
| SmallRig NP-F Battery Adapter Plate Lite for Sony NP-F Battery, w/ 12V/7.4V Output Port, LED Low Battery Indicator - 3018 | 1 | $26.90 |
| Neewer NP-F750 2-Pack 5600mAh Li-ion Replacement Battery with USB Charger, Compatible with Sony NP-F550 570 750 770 930 950 FM55H FM500H QM71 QM91 QM71D LED Light, Monitor, Motorized Slider | 1 | $50.01 |
| Total | | $90.90 |

## Sources
[1] DARPA Triage Challenge. Available: https://triagechallenge.darpa.mil/.

[2] *Jetson Nano System-On Module Data Sheet*, NVIDIA, 2023. [Online]. Available: https://developer.download.nvidia.com/assets/embedded/secure/jetson/Nano/docs/JetsonNano_DataSheet_DS09366001v1.1.pdf?REUknfGz7IfV10-RdLQ98cHFQPpAdXr5VttLj0_tGdkvv42sXgadgKgZv27MCiRYODp_kan6OE2griI6iYqHedWU1sgatpyV_p-SF92JrLsEBBM1hc_9oL1lUGmf0Ez_LmEij8ieNlFXGno2qpo0KL1G5Ta7U-OwkOzp5u770tMk3Svs4rERrSNsRIp0jA==&t=eyJscyI6ImdzZW8iLCJsc2QiOiJodHRwczovL3d3dy5nb29nbGUuY29tLyJ9

[3] *Jetson Nano Develover Kit*, NVIDIA, 2020. [Online]. Available: https://developer.download.nvidia.com/assets/embedded/secure/jetson/Nano/docs/NV_Jetson_Nano_Developer_Kit_User_Guide.pdf?EJsH8ZYNz5pFvY3xfek_t8S719_1OlL2HyyEdrbWH7Cs4dW7W_T72B_ntKtwV55xuzUiQb5NFF1rIVcbmF7HqZH-PTEjKzl4Exc_hivvbH0cS7lEQrrqC8DaXltt33Db7GIt-2NOzTPLX7rsDxql2Vio-GiaGfss_qKMzmh3_SCBDiF2DB-_BsDl9ecCGWxQUxI=&t=eyJscyI6ImdzZW8iLCJsc2QiOiJodHRwczovL3d3dy5nb29nbGUuY29tLyJ9

