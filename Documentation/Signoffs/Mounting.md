
## Function of the Subsystem

The mounting subsystem will hold the input, output, error, power and processing subsystems in an unfrequented location.

## Constraints
| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1  |  The overall system length from input to speaker can be no greater than 1.575 ft  | System Requirements |
| 2  |  System shall not impede movement and easy access throughout the room  | American Disabilities Act |
| 3  |  The speaker output shall not be more than 0.5 m from window or wall being measured | System Requirements |
| 4  |  System shall be mounted in the classroom in an unfrequented area.| System Requirements |
| 5  |  System shall minimize its visual distraction | Stakeholder survey |




<sup>1</sup>	The overall system length from input to speaker can be no greater than 1.575 ft. [Origin: System Requirements]

The delay of the system must be less than the delay of the sound for the noise cancellation to be effective. This constraint is dependent on distance: if the velocity of sound in air is used (343 m/s), then the maximum distance from the input microphone to the error microphone is given by the following equation: d = v*t where d is the maximum distance, v is the velocity of sound and t is the maximum delay (1.4 ms). This equates to a distance of 0.4802 m or 1.575 ft, therefore the total length of the system can be no greater than 1.575 ft for correct operation.

<sup>2</sup> System shall not impede movement and easy access throughout the room. [Origin: American Disabilities Act]

This constraint is needed to ensure safety and minimize difficulty in navigating the classroom during the operation of the system. This constraint also will follow the American Disabilities Act allowing for individuals with limited mobility to easily navigate the room.


<sup>3</sup> The speaker output shall not be more than 0.5 m from window or wall being measured. [Origin: System Requirements]

This is to make sure the system is small and compact and does impede movement throughout the classroom while also meeting the delay requirements.

<sup>4</sup> System shall be mounted in the classroom in an unfrequented area. [Origin: System Requirements]

This will allow the system to perform its functionality without causing difficulty for students or faculty performing their required tasks.

<sup>5</sup> System shall minimize its visual distraction [Origin: Stakeholder Survey]

Classrooms should be distraction-free to allow students to learn new information effectively, therefore the system will not be distracting to students or faculty.




## Buildable schematic 
<img src="/Documentation/Images/Mounting/sideview_mounting.png" width= "40%" height = "40%" alt=" Buildable Schematic of mounting system top-down view">

*Figure 1.  Mounting system side view*


<img src="/Documentation/Images/Mounting/Mounting_Front_View.png" width = "40%" height = "40%" alt=" Buildable Schematic of mounting system front view">

*Figure 2. Buildable Schematic of mounting system front view*

The figures above show a side and front view of the mounting box that will utilized for the mounting system.




## Analysis

1.) 3D printed box

The box will be 3D printed by the team and will be 10 inches in length, 10 inches in width, and 5 inches in depth which will be mounted to the wall. The purpose of wall mounting is to keep the sensitive subsystems out of reach during normal use as it will not require input from users. This also ensures that the entire system will either be attached to the wall or on the window sill, minimizing the movement restrictions placed on the room to unfrequented areas. The wall shelf design helps follow constraints <sup>2</sup> and <sup>4</sup>.

There will be a sliding door attached from the bottom while mounted on the wall to minimize visual distraction. There are 14 holes in the design - 8 on the side walls and 6 inside the box - which are placed to allow for discrete wiring <sup>5</sup>. 

<img src="/Documentation/Images/Mounting/Mounting_Connection_Schematic.png" width= "40%" height = "40%" alt=" Buildable Schematic of mounting system top-down view">

*Figure 3. Buildable Schematic of the mounting subsystem with system connections*

The above figure depicts how each individual component will be physically placed in the room. This shows how the box mount is placed up above the desks in the room and high enough to be out of the way <sup>5</sup>. It also shows what the mount will look like with its sliding door covering the inside, minimizing distractions <sup>4 5</sup>. The post connected to the error microphone will be attached to the window sill with tape. The necessary wired connections can also be made using the internal and external holes through the box mount. The shown connections include from input subsystem to the input microphone, the error subsystem to the error microphone, and the output subsystem to the speaker. The wires will be taped flush and parallel to the wall to minimize the space utilized. 

Figure 2 shows each individual subsystem along with the corresponding shelf that the subsystem is on. There are four individual shelves inside the box which will contain all the required subsystems for system functionality. The top shelf on the left-hand side will contain the input subsystem and on the right-hand side will contain the error subsystem. The second shelf from the top will contain the speaker preamplifier, and the third shelf from the top will contain the processing subsystem. The power subsystem will be on the bottom shelf. The box will connected to the wall using command strips and the input mic will be connected to the window and wired to the input pre-amplifier using the holes in the box. The speaker will be placed on the windowsill to ensure the distance between the measurement point is less than the requirement <sup>3</sup>. 

The box will be placed in the room with the following connections as outlined in Figure 3. Figure 3 shows the wall to the left of the window where the box will be fastened using command strips. 

2.) Command strip details

The command strips that will be used will be the command black picture hanging strip mixed pack which is sold through Amazon. There are 8 pairs of X-large strips in this pack which will hold 20 lbs.

A stress analysis was performed on the 3D design in order to make sure that the box would withstand a total force under 20 pounds [2].



## BOM

| DEVICE                                           | Quantity | Price Per Unit | Total Price |
| -------------------------------------------------| -------- | ---------------| ----------- |    
| Command Black Picture Hanging Strip Mixed Pack   | 1        | $9.98          | $9.98       |


## References
1. [Command Strips]

[Command Strips]: https://www.amazon.com/dp/B09XJDQCG6/ref=redir_mobile_desktop?_encoding=UTF8&aaxitk=5bb9cc62e41d7067569bfbdbb3611e78&content-id=amzn1.sym.cd95889f-432f-43a7-8ec8-833616493f4a%3Aamzn1.sym.cd95889f-432f-43a7-8ec8-833616493f4a&hsa_cr_id=0&pd_rd_plhdr=t&pd_rd_r=3a3d188f-0701-494f-b07f-4e7c62285293&pd_rd_w=039JW&pd_rd_wg=H5pvQ&qid=1693773858&ref_=sbx_be_s_sparkle_mcd_asin_1_img&sr=1-2-9e67e56a-6f64-441f-a281-df67fc737124&th=1

2. [Stress Analysis]
   
[Stress Analysis]: https://cdn.discordapp.com/attachments/1069111379656724490/1152037040771321916/Mounting.ipt_Stress_Analysis_Report_9_14_2023.html


