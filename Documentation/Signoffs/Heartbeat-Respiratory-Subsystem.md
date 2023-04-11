Heartbeat/Respiratory Subsystem 

Subsystem Function:

The purpose of this subsystem is to measure the presence of a heartbeat as well as measure the respiratory rate of a person contactlessly. This subsystem will be composed of a singular radar that will perform both of these actions. The measuring of a person’s presence of a heartbeat as well as respiratory rate will be done by measuring the rise and fall rates of a person’s chest to measure the respiratory rate, and the rise and fall rates of the area around the heart to measure the presence of a heartbeat. A series of signals will be sent and received to measure these changes. The raw data will be put through an algorithm that will output specific heart rate and respiratory rates and send them to be further analized.

Specs and Constraints table for signoff:			


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
   <td>Must sense frequencies from 0.13 Hz to 0.42 Hz
   </td>
   <td>From Conceptual Design, from Heartbeat/Respiratory System section
   </td>
  </tr>
  <tr>
   <td>Heartbeat detection
   </td>
   <td>Must sense frequencies from 0.45 Hz to 2.92 Hz
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
   <td>When combined with other subsystems as well as reference drone, must weigh below 20 lbs in total
   </td>
   <td>From DARPA constraints
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

<img width="645" alt="Heartbeat_Respiratory_Diagram_new" src="https://user-images.githubusercontent.com/123419455/231278499-d7205942-5ca0-4afa-a70c-6371a5994ff6.png">
Figure 1: Pictured above is the Buildable Wiring Schematic

<img width="624" alt="Jetson Nano Module" src="https://user-images.githubusercontent.com/123419455/231278530-c31598c8-3fec-422d-8ff8-a1e563d86ed8.png">
Figure 2: Pictured above is the Jetson Nano Module that the MR60BHA1 is connected to

<img width="445" alt="Image of MR60BHA1" src="https://user-images.githubusercontent.com/123419455/231278580-e9f1b73f-ed2f-4a88-8443-1d1be2cb46f2.png">
Figure 3: Pictured above is an image of the MR60BHA1

Analysis:

The radar that will be used to accomplish this subsystems function is the Speed MR60BHA1 60GHz mmWave Module. This radar sensor was built for the task of vital detection with the ability to measure heart in the range of 60-100 bpm and respiratory rate of up to 25 times per minute. As specified by the product description the typical accuracy of the breath rate is 90% and the accuracy of the heart rate is 95%. The sensor also allows for secondary development using UART communication protocol. It adheres to constraints as follows.

MR60BHA1 60GHz mmWave Module - Respiratory Heartbeat Detection | FMCW must be placed at a maximum distance of 2 meters away from the person’s body in order for the detection of a presence of a heartbeat and respiratory rate as shown in the datasheet [2].

MR60BHA1 60GHz mmWave Module - Respiratory Heartbeat Detection | FMCW wave emission of 10 dBm found in the powerpoint, which is safe for human tissue and also complies with the safety of the radar specified by DARPA [3].

For the MR60BHA1 60GHz mmWave Module - Respiratory Heartbeat Detection | FMCW, the specific weight of the component is not specified in the datasheet, but the size of the component is specified. The dimensions of the component are 30 x 35 mm, so it will be assumed that the component is light in weight due to its small size [4]. This conforms with the weight limit set by DARPA.

Here is a link to a video showing the radar being simulated and tested for accuracy on a stationary individual.



: [https://youtu.be/J1JDgFs_4iw](https://youtu.be/J1JDgFs_4iw) 

This link was found on the website referenced in source [2].

BOM:



*  MR60BHA1 60GHz mmWave Module - Respiratory Heartbeat Detection | FMCW - $45.00

Sources: 

[1] “Radiation: Radar,” _World Health Organization_. [Online]. Available: https://www.who.int/news-room/questions-and-answers/item/radiation-radar#:~:text=Exposure%20to%20RF%20fields%20above,dangerous%20amounts%20of%20radio%20frequencies%3F. [Accessed: 28-Mar-2023]. 

[2] Anonymous, “MR60BHA1 60GHz mmWave module - Respiratory Heartbeat detection: FMCW: Sync sense: Privacy protect,” _60GHz mmWave Radar Module - Respiratory Heartbeat Detection | FMCW | Sync Sense | Privacy Protect - Seeed Studio_, 07-Dec-2022. [Online]. Available: https://www.seeedstudio.com/60GHz-mmWave-Radar-Sensor-Breathing-and-Heartbeat-Module-p-5305.html. [Accessed: 04-Apr-2023]. 

[3] Seeed Studio, SEEED MMWAVE RADAR SENSOR, Powerpoint Slides, https://files.seeedstudio.com/wiki/mmWave-radar/Seeed-mmWave-sensor-series-V2.0.pptx

[4] Anonymous, “MR60BHA1 60GHz mmWave module - Respiratory Heartbeat detection: FMCW: Sync sense: Privacy protect,” _60GHz mmWave Radar Module - Respiratory Heartbeat Detection | FMCW | Sync Sense | Privacy Protect - Seeed Studio_, 07-Dec-2022. [Online]. Available: https://www.seeedstudio.com/60GHz-mmWave-Radar-Sensor-Breathing-and-Heartbeat-Module-p-5305.html. [Accessed: 04-Apr-2023]. 

[5] “60GHz mmwave module - respiratory heartbeat detection sensor user ...” [Online]. Available: https://files.seeedstudio.com/wiki/60GHzradar/new_res/MR60BHA1_user_manual-V1.9.pdf. [Accessed: 04-Apr-2023]. 
