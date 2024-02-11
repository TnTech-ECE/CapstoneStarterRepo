## Functionality

The push button subsystem will be the process of pushing the stop button to stop the time, which will denote the completion of the course. The system will consist of a servo motor, a pin release mechanism, a lateral arm that is spring loaded, and a paint roller. The arm of the robot will swing out perpendicular to the chassis of the platform once the servo opens the pin mechanism. Once released the paint roller will contour the right-hand side of the wall until the end of the course to hit the stop button.

## Specifications and Restraints


| Number | Constraint component | Constraint description | Origin |
|--------|----------------------|------------------------|--------|
| 1. |  Arm/Shaft | The height of the paint roller will hang at most 2.5 inches off the ground to compress the stop button  | Competition Specifications |
| 2. | Arm/Shaft | The dimensions of the arm before beginning the course shall not exceed 1 cubic ft. | Competition Specifications |
| 3. |  Arm/Shaft | Lenth of the arm shall be 11.25 inches at minimum when fully extended to reach the push button on the right hand of the wall   | Competition Specifications |
| 4. |  Servo motor | The stall torque of the motor is 20 kg*cm (the max torque that can be applied before the shaft quits rotating) | Servo Motor Specifications |
| 5. |  Servo motor | The servo motor shall fit the bracket for releasing spring loaded arm | Pin Release Bracket Specifications |


## Buildable Schematic

Control block diagram for pushbutton system

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/New_block_diagram.png)



**Pinout of servo motor**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/New_PB_schematic.png)



## Analysis 

**Shaft\Arm description:** 

The arm acts as the main support for the paint roller brush. When the paint roller hits the wall after being extended the brush will roll and contour with the wall so that way, we have a point of contact with the right side of the wall for the majority of the course and especially the end. The arm of the robot will have a return spring attached to it in order to allow the default position which is 90 degrees perpendicular to the chassis. 

**Servo Motor description:** 

The servo motor will be the main release mechanism for the arm. Since the arm of the robot has a return spring, the pin that is held from the servo will have a ring that slides in between the pin and bracket from the servo. 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Newest_Servo_drop.png)



**Shaft\Arm lateral force:**

To calculate the lateral force on the arm the speed of the robot needs to be known. To calculate the acceleration, we can use the graph of the dc motors speed with respect to time to find the acceleration. From the graph it takes the motors approximately 0.3 seconds to get to 60 RPM. Converting 60 RPM to meters/sec gives us 0.1101 meters/second. Acceleration is equal to dv/dt  so Acceleration=((0.1101 m/s-0 m/s))/(0.3 seconds)=0.367 m/s^2 . Assuming the robot is at max weight capacity of 11.34kG (25lbs) then we can calculate the force exertion from the robot which is 4.17N. Then assuming the robot moves at a 45-degree angle towards the right-hand side of the wall we can now calculate the total force exerted by the wall and robot on the arm. The calculation for the force is described below along with the speed of the motor graph that was used to determine the force exerted by the robot.

**Free Body diagram for lateral force on robot**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Images/FBD.png)


**Lateral Force Calculation**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Images/Lateral_Force_Calc.png)


**Housing\Bracket for driven gear and bearing**

For attaching the driven gear (the gear that lays flat on the chassis) there is a pillow bearing block mount that houses the bearing. The shaft that will be within the inner diameter of the bearing will hold the driven gear. The driven gear borehole will have a diamter of 8mm to have a tight fit on the shaft. 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Images/PB_pillow_bearing_block.png)



## Constraint Solutions


**Constraint Solution 1:**

Since the stop buttons center is 2.5 inches from the bottom of the course the paint roller will overhang the tracks when it swings out. This can be achieved by having two consecutive perpendicular arms that force the paint roller to hang lower from the shaft connected to the secondary beveled gear on the robot’s base platform. The dimensions of where the button is located is in the first figure below and the part where the buttons general location on the gameboard is labeled “E” in the third figure below.

In order to reach the button the, shaft will need to reach out at least 5.9" that will be perpendicular to the tank trancks. This is because the width of the robot is is 9.24 inches and the platform width that the pushbutton system will be on is 6.1 inches. The total width of the course is 20.81 inches. If the robot is centered on the track the then the length from the platform to the other end of the wall is 11.57 inches total for both sides. If you divide this width by 2 then you can find the length from the right track side to the button which ends up being 5.8 inches. The decision to go with 5.9" is based off the fact that the paint roller foam will compress inward due the pressure of the wall. 

Since the length of the robot is 10 inches total in width due to the track size, then the arm of the push button will placed approximately 1.27 inches from the back right side of the robot. This is because the button is seven inches from the back wall and if the robot goes to the very end in worse case scenario then the arm will not be too far away to reach it. The math behind this is 10 inches of track length - 7 inches from back wall = 3 inches torwards the back end of the robot extends past the button. The platform is 8.27 inches in length so 10 inches - 8.27 inches gives a 1.73 inches. Then dividing this number by two gives the total extra length the track extends out past the platform for one end. So the amount the tracks extend out past the platform for one side is 1.73 in. / 2 = 0.865 inches from the platform to the end of the track. If the track extends past the button by 3 inches then the platform extends past the button by 2.135 inches (3 in. - 0.865 in.). So from this calculation the arm for the push button system needs to be at least 2.135 inches from the back right side of the robot or be placed up more towards the front. 

**Mounting for Shaft/Arm depiction from ME group**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/PB_on_robot.png)

This depiction of the arm is when it is held in place by the servo motor and pin release bracket before releasing the arm to its default position of 90 degrees to the chassis.


**Stop button precise location**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Game_board_buttton.png)

**Stop button general location “E”**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Game_Board.png)

**Constraint Solution 2:**

When the arm/shaft of the push button subsystem is not active, the height and width of the arm/shaft will not exceed the leftover height of the robot and it will be flush with the platform before swinging in an outward motion. Since the height of the arm will be 3 inches tall and the height of the platform it sits on is 3.74 inches tall the robot will still be within 1 cubic foot. When the arm of the robot is retracted the arm with the paint roller can run parellel with the tracks. 

**Constraint Solution 3:**

The length of the shaft/arm needs to at least reach out approximately 12 inches for our robot being centered of the course. The course width from side to side is 23.25 inches. If our robot is approximately 1 foot in width, then our arm needs to be at least 11.25 inches when extended out from the side of the robot chassis. This is assuming we are in the center of the board. The figure below shows the total width of the board.

**Game board dimensions**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Game_Board_dimensions.png)


**Constraint Solution 4:**

To help prevent the motor from reaching its max torque load, I have created my bevel gear model to have a high gear ratio of 1.25. This higher gear ratio increases the more output torque increases with less input torque from the dc motor. For beveled gears I had to change the pitch angle of the drive gear to 39 degrees and the driven gear to 50 degrees to get them to mesh properly.





## BOM

| Item | Description | Subsystem | Part Number | Manufacturer | QTY. | Price | Total Price |
|------|-------------|-----------|-------------|--------------|------|-------|-------------|
| Servo Motor | Used to turn the shaft | Push button  | MG995 | Tower Pro | 1 | Recycled | Recycled |
| Paint roller | Used to compress button | Push button  | N/A | Mister Rui | 1 pk | $10.97  | $10.97 |
| PLA | Used for printing gears | Push button  | N/A | N/A | 1.7 cu in. | $0.00 | $0.00 |
|  |  |  |  |  |  |  | $10.97  |



