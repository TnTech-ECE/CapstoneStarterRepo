
## Function of the Subsystem

The mounting subsystem will hold the input subsystem, processing subsystem and error subsystem in a unfrequented location.

## Constraints
| No. | Constraints                                                           | Origin            |
| --- | --------------------------------------------------------------------- | ----------------- |
| 1  |  The overall system delay must be less than or equal to 1.4 ms  | System Requirements |
| 2  |  System shall not impede movement and easy access throughout the room  | American Disabilities Act |
| 3  |  The speaker output shall not be more than 0.5 m from window or wall being measured | System Requirements |
| 4  |  System shall have a mount or multiple mounts so that it can be installed in the classroom in an unfrequented area.| System Requirements |
| 5  |  System shall be easy to remove and setup in a different room | Broader Impacts |
| 6  |  System shall minimize its visual distraction | Stakeholder survey |
| 7  |  System shall follow OSHA standard 1910.95 for occupational noise exposure.| OSHA standards |
| 8  |  System shall follow OSHA standard 1910.304-305 for wiring design and protection | OSHA standards |
| 9  |  System shall follow the IEEE 518-1982 Guide for the Installation of Electrical Equipment to Minimize Electrical Noise Inputs to Controllers from External Sources. | IEEE standards |
| 10  |  Overall weight of mounting subsystem cannot exceed 17 lbs.| Weight requirement |
| 11  |  The width of the physical mount cannot exceed 49 in.| Window width measurements |




#### 1.)	The overall system delay must be less than or equal to 1.4 ms . [Origin: System Requirements]

The delay of the system must be less than the delay of the sound in order for the noise cancellation to be effective. This constraint is dependent on distance, if the velocity of sound in air is used (343 m/s), then the maximum distance from the input microphone to the error microphone is given by the following equation: d = v*t where d is the maximum distance, v is the velocity of sound and t is the maximum delay (1.4 ms), this equates to a distance of 0.4802 m or 1.575 ft, therefore the total length of the system can be no greater than 1.575 ft for correct operation.

#### 2.) System shall not impede movement and easy access throughout the room. [Origin: Americans Disabilities Act]

This constraint is needed to ensure safety and minimize difficulty navigating the classroom during the operation of the system. This constraint also will follow the American Disabilities Act allowing for individuals with limited mobility to easily navigate the room.


#### 3.) The speaker output shall not be more than 0.5 m from window or wall being measured. [Origin: System Requirements]

This is in order to make sure the system is small and compact and does impede movement throughout the classroom.

#### 4.) System shall have a mount or multiple mounts so that it can be installed in the classroom in an unfrequented area. [Origin: System Requirements]

This will allow the system to perform its functionality without causing difficulty for students or faculty performing
their required tasks.

#### 5.) System shall be easy to remove and setup in a different room. [Origin: Broader Impacts]

Other classrooms will experience noise and the ease in which the system can be moved is a large factor for how quickly noise in other rooms can be effectively canceled.

#### 6.)  System shall minimize its visual distraction [Origin: Stakeholder Survey]

Classrooms should be distraction free to allow students to learn new information effectively, therefore the system will not be distracting to students or faculty.

#### 7.) System shall follow OSHA standard 1910.95 for occupational noise exposure. [Origin: OSHA standards]

The mounting subsystem should be designed to ensure that the weighted average noise does not exceed 85 dB from the overall system to guarantee no hearing loss will occur.

#### 8.) System shall follow OSHA standard 1910.304-305 for wiring design and protection. [Origin: OSHA standards]

The mounting subsystem should be designed such that wires are easily identified and discerned from other conductors, for example the ground wire must be easily found when comparing it to live conductors. The wires must also be insulated and be in a proper location to minimize the probability of electrical shock occuring.

#### 9.) System shall follow the IEEE 518-1982 Guide for the Installation of Electrical Equipment to Minimize Electrical Noise Inputs to Controllers from External Sources. [Origin: IEEE standards]

The mounting subsystem needs to follow this guide to limit outside noise which could lower the effectiveness of the noise cancellation capability of the overall system.

#### 10.) Overall weight of mounting subsystem cannot exceed 17 lbs. [Origin: Weight requirement ]

The mounting subsystem cannot be physically drilled into the wall since this would damage Tennessee Tech property, therefore command strips will be utilized, these command strips are rated for 20 lbs. The system will add weight, therefore to compensate for the additional weight, the weight requirement will be lessened to a maximum amount of 17 lbs for the physical mount to prevent failure.
#### 11.) The width of the physical mount cannot exceed 49 in. [Origin: Window width measurements ]

The physical mount cannot be wider than the window in order to be fastened to the window. The measured width of the window in Brown 314 is 49 inches (4 feet 1 inch), therefore the selected physical mount must meet this requirement.






## Buildable schematic 
<img src="/Documentation/Images/Mounting/Top_Down.png" width= "80%" height = "80%" alt=" Buildable Schematic of mounting system top-down view">

*Figure 1. Buildable Schematic of mounting system top-down view*


<img src="/Documentation/Images/Mounting/Side_View.png" alt=" Buildable Schematic of mounting system side view">

*Figure 2. Buildable Schematic of mounting system side view*

## Analysis

1.) Physical mount details

The physical mount that will be utilized is the SRIWATANA floating shelf which can be purchased from Amazon. The weight of the shelf is 4.6 lbs which meets constraint (10). The width of the shelf is 16.5 in which meets constraint (11). The floating shelf will be mounted to the window by utilizing command strips rated for 20 lbs and the system components will be placed on the shelf. The length of the mount is 11.8 in.

2.) Command strip details

The command strips that will be used will be the command black picture hanging strip mixed pack which is sold through Amazon. There are 8 pairs of X-large strips in this pack which will hold 20 lbs. This will prevent damage to Tennessee Tech property while still allowing the physical mount to installed, which meets constraint (10).



## BOM

| DEVICE                                           | Quantity | Price Per Unit | Total Price |
| -------------------------------------------------| -------- | ---------------| ----------- |
| SRIWATANA Floating Shelves Wall Mounted Set of 2 | 1        | $49.33         | $49.33      |
| Command Black Picture Hanging Strip Mixed Pack   | 1        | $9.98          | $9.98       |


## References

1. [Amazon Shelf] 

2. [Command Strips]

[Amazon Shelf]: https://www.amazon.com/SRIWATANA-Floating-Shelves-Capacity-Weathered/dp/B07Q5RZVVW/ref=sr_1_7?crid=LOGA7RBQSXKH&keywords=large%2Bwall%2Bshelf&qid=1693771539&refinements=p_n_feature_eleven_browse-bin%3A23576958011&rnid=23576923011&s=furniture&sprefix=large%2Bwall%2Bshelf%2Caps%2C169&sr=1-7&th=1

[Command Strips]: https://www.amazon.com/dp/B09XJDQCG6/ref=redir_mobile_desktop?_encoding=UTF8&aaxitk=5bb9cc62e41d7067569bfbdbb3611e78&content-id=amzn1.sym.cd95889f-432f-43a7-8ec8-833616493f4a%3Aamzn1.sym.cd95889f-432f-43a7-8ec8-833616493f4a&hsa_cr_id=0&pd_rd_plhdr=t&pd_rd_r=3a3d188f-0701-494f-b07f-4e7c62285293&pd_rd_w=039JW&pd_rd_wg=H5pvQ&qid=1693773858&ref_=sbx_be_s_sparkle_mcd_asin_1_img&sr=1-2-9e67e56a-6f64-441f-a281-df67fc737124&th=1
