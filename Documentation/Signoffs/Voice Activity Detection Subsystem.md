## Voice Activity Detection Subsystem ##

**Subsystem Function:**

The purpose of this subsystem is to detect an individual's responsiveness or cognition through the use of call and response techniques. The subsystem will activate once an individual heartbeat has been detected. The speaker will play a sound with an instruction to say something. Once the instruction is given, the microphone will begin transmitting audio to a computing system which will then run an algorithm to detect if a human voice responded or not allowing the total system to know if the individual being tested has cognition or not.

**Specs and Constraints**:			


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
   <td>Microphone
   </td>
   <td>Must sense frequencies from 300 Hz to 4000 Hz
   </td>
   <td>Frequency range of voice frequencies on the electromagnetic spectrum.
   </td>
  </tr>
  <tr>
   <td>Microphone
   </td>
   <td>Must sense a minimum decibel gain value between 20-30 dB.
   </td>
   <td>Volume level of a human whisper. Helps to detect those who can barely speak.
   </td>
  </tr>
  <tr>
   <td>Speaker
   </td>
   <td>Must play sound clips between 20 Hz- 20000 Hz 
   </td>
   <td>Frequency range an individual’s ear can hear
   </td>
  </tr>
  <tr>
   <td>Weight
   </td>
   <td>The drone specified in conceptual design had a max load of 2.7 kg. Seeing as 4 subsystems will be attached to the drone. The max weight must not exceed 675g.
   </td>
   <td>From DARPA constraints/ Conceptual design
   </td>
  </tr>
  <tr>
   <td>Safety
   </td>
   <td>Speaker output must not be louder than 70 dB
   </td>
   <td>Levels that prolonged exposure can lead to damage to an individual's hearing. Hearing Health Foundation
   </td>
  </tr>
</table>


**Wiring Schematics**



<p id="gdcalert1" ><span style="color: red; font-weight: bold">>>>>>  gd2md-html alert: inline image link here (to images/image1.png). Store image on your image server and adjust path/filename/extension if necessary. </span><br>(<a href="#">Back to top</a>)(<a href="#gdcalert2">Next alert</a>)<br><span style="color: red; font-weight: bold">>>>>> </span></p>


![alt_text](images/image1.png "image_tooltip")


Figure1. Wire Diagram for the total subsystem

**Analysis:**

The datasheet of the ML1-WS states a frequency range at 20 Hz -18 kHz which is between the threshold set by the constraints to capture human voice frequencies. This microphone will be able to capture the 300-4000 Hz range set by the constraint.

The ML1-WS datasheet also has a minimum sensitivity of -50 dB which is much more sensitive than the 20 -30 dB needed to capture a human whisper. This meets the constraint set above and will allow the system to capture an individuals cognition even if a faint sound is heard from the human.

The GikFun EK1725 speakers are full range and capture all the hard frequencies from 20 Hz - 20kHz set by the constraint above. But more importantly it will be able to produce sound between 2000 Hz through 5000 Hz which is the range most sensitive to the human ear. 

The total subsystem will consist of three parts. The microphone, converter, and speaker. The converter specification states a weight of 269.32 g, the speakers have a weight of 136.1 g, and the microphone has a weight of 22.68 g. This brings the total subsystem weight to 428.1 g which is under the 675 g constraint limit set above. This will allow for some extra weight to be included for other subsystems.

The Gikfun speaker datasheet puts the output gain limit at 80 dB which is greater than the 70 dB limit set in the constraint. But like most speakers this can be adjusted before sending any data to the speaker. This means that the jetson will control the input of the speakers to be under the 70 dB threshold set in the constraints.  

  

**BOM:**



* ML1-WS ETS Microphone - $42.00
* Anber-Tech Analog to Digital Audio Converter- $16.99
* Gikfun EK1725 2”4 Ohm 3 W Full Range Audio Speaker - $9.68
