## Functionality

The push button subsystem will be the process of pushing the stop button to stop the time, which will denote the completion of the course. The system will consist of a servo motor, beveled gears, a shaft, a bearing block with bearing, a lateral arm, and a paint roller that will swing out on the arm perpendicular to the platform of the robot. The set of bevel gears will be driven by a 6-9 volt servo motor that will rotate the shaft of the paint roller to be fully extended. Once fully extended the paint roller will contour the right hand side of the wall until the end of the course to hit the stop button. 
## Specifications and Restraints


| Number | Constraint component | Constraint description | Origin |
|--------|----------------------|------------------------|--------|
| 1. | Arm/Shaft | Length of the arm shall not extend out before the start | Competition Specifications |
| 2. |  Arm/Shaft | The height of the paint roller will hang at most 2.5 inches off the ground to compress the stop button  | Competition Specifications |
| 3. | Arm/Shaft | The dimensions before the start of the arm shall not exceed 1 cubic ft. | Competition Specifications |
| 4. |  Arm/Shaft | Lenth of the arm shall be 11.25 inches at minimum when fully extended to reach the push button on the right hand of the wall   | Competition Specifications |
| 5. |  Servo motor | The stall torque of the motor is 0.7 kg*cm (the max torque that can be applied before the shaft quits rotating). |Servo Motor Specifications |
| 6. | Bevel Gears  | The teeth of the beveled gears shall endure enough torque to prevent the teeth from breaking under a load and will have a pressure angle of at least 20 degrees | AGMA Standard |
| 7. |  Bevel Gears  | Drive gear borehole diameter shall fit the diameter of the dc motor shaft down to 0.001 in. = 0.0254 mm.| AGMA Standard |

## Buildable Schematic

Control block diagram for pushbutton system

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Control%20Block%20Diagram.png)


Model of the electrical inductance and internal motor resistance for the DC motor to test and get torque values and loads under different conditions.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Electrical_LT.png)

Model of mechanical circuit that converts the electrical characteristics into the mechanical characteristics such as rpm and torque values.
The results of the LT Spice models will be in the "Analysis" section.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Mechanical_LT.png)


**Drive gear parameters for 3d modeling and printing using blender** 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Drive_Gear_Param..png
)

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Drive_R_C.png)



**Driven/Output gear parameters for 3d modeling and printing using blender**  

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Driven_Gear_Param.png
)

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Output_R_C.png)



## Analysis 

**Shaft\Arm description:** 

This shaft and arm will be printed using PLA material that way it gives us flexibility if we need to change diameter size or shape. The arm acts as the main support for the paint roller brush. When the paint roller hits the wall after being extended the brush will roll and contour with the wall so that way, we have a point of contact with the right side of the wall for the majority of the course and especially the end. The base of the arm is already mounted to the center body of the driven gear because it is 3-d printed to the driven gear. The base of the arm will have PVC tubing with a t-joint elbow with a 90-degree bend that slides over the top of the base that creates the perpendicular shaft to the to the base of the arm.  The shaft that is perpendicular to the base of the arm is what extends out to hit the pushbutton. 

**Connection of Bottom shaft to bearing**

![Alt text]()

**Shaft\Arm lateral force:**

To calculate the lateral force on the arm the speed of the robot needs to be known. To calculate the acceleration, we can use the graph of the dc motors speed with respect to time to find the acceleration. From the graph it takes the motors approximately 0.3 seconds to get to 60 RPM. Converting 60 RPM to meters/sec gives us 0.1101 meters/second. Acceleration is equal to dv/dt  so Acceleration=((0.1101 m/s-0 m/s))/(0.3 seconds)=0.367 m/s^2 . Assuming the robot is at max weight capacity of 11.34kG (25lbs) then we can calculate the force exertion from the robot which is 4.17N. Then assuming the robot moves at a 45-degree angle towards the right-hand side of the wall we can now calculate the total force exerted by the wall and robot on the arm. The calculation for the force is described below along with the speed of the motor graph that was used to determine the force exerted by the robot.

**Free Body diagram for lateral force on robot**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Images/FBD.png)


**Lateral Force Calculation**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Images/Lateral_Force_Calc.png)

**Mounting for Shaft/Arm**

The driven gear will be set within a bracket that has been bored out to allow the driven (output) gear to rotate. The borehole housing for the driven gear is 95mm (3.74 in) in diameter to allow enough clearence for the 70.2mm (2.76 in) driven gear diamter. The bottom of the driven gear will have a 10mm (0.4 in) shaft that will extrude out the bottom of the driven gear that is also 3-d printed into the body of the gear that will be placed within the inner race of a ball bearing. 
The ball bearing will be placed in the bracket where there is a housing for the outer race to squeeze into with a tolerance of 0.0254mm (0.001 in) which is a common standard for the “ABEC scale” that is used and accepted in most industries. The bearing I am wanting to use has a 10mm (0.40 in) inner race and the outer race is 30mm (1.1811 in). The bracket bearing housing diameter is 30.0254 mm (1.1821 in) which creates the minimum tolerance needed to prevent the outer race from slipping. The height of the bearing housing is near the same height as the bearing being used, which is 9mm (0.354 in.) and the bearing housing height is 9.03mm (0.355691 in). The figures below show the bracket and housing for the gears and bearing (visual dimensions in the dimensions section). The Bracket for the arm has mounting holes that will have screws that mount to the robots chassis platform. 

**Housing\Bracket for driven gear and bearing**

![Alt text]()


**Servo Motor description:** 



**Mating gear attachment on motor**
The mating gear will be attached to the motor’s shaft. The shaft of the motor fits tightly within the borehole of the mating gear. To prevent the gear from sliding off the motor’s shaft, there will be a small hole drilled into the shaft of the motor with a cotter pin placed into it.

**Fitment of gears, bearing block and  servo motor**

![Alt text]()

**DC Motor model:** 

The essential readings from the LT spice model labeled below as “Readings of LT spice dc motor model for rpm and torque” are the **I(Current_sensor_2)** and the Voltage at **V(node_3)**. The current reading in the **I(Current_sensor_2)** is the equivalent speed of the motor at 6 volts in rpm. The max output torque is equivalent to the voltage at V(node_3) which is in **N*m** and then you can convert that value to Kg*cm. I know this model works because from the specs of the dc motor because the torque and rpm speed match what the load torque and current are equivalent to. The figure labeled “Specs of DC motor” in the BOM section is the original datasheet for the geared dc motor. Our motor is the 100-rpm motor so in the “Specs of DC motor” figure look at the 5th column.

**Readings of LT spice dc motor model for rpm and torque**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/LT_Spice_results.png)

**L298N Driver description:**

The L298N is a directional and speed controller for DC motors. The reason for using this is because it will allow the arm/shaft with the paint roller to swing out and retract back in when desired. It can change directions because the L298N uses an H-Bridge which switches the polarity of the DC motor when specified, and when you switch the polarity of a DC motor it changes rotation. 

**L298N Driver wiring:**

For the wiring for our purpose, we do not need to use any PWM ports since we just want high and low signals to turn the arm/shaft. We can use any of the digital GPIO pins to turn off the motor or control the direction of our motor. One of the digital GPIO pins will connect to “input 1” and the other GPIO digital pin will connect into “input 2” of the L298N. Our external battery connection will need to have the positive terminal connected to the 12+ terminal and the negative terminal of the external battery will need to be connected into the GND pin of our L298N driver.  The positive terminals and the negative terminals of our DC motor will connect its positive terminal into the “Out 1” and the negative terminal will connect into the “Out 2” pin.  The figure below shows the visual connections. 

**Pinout of the microcontroller and the L298N driver**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Images/Schematic_2_L298N.png)

**Beveled gears description:**

The beveled gears are the mechanical system behind the pushbutton subsystem. They are used to transfer the work and energy of the dc motor to the arm/shaft with the paint roller attached to it. The reason they are beveled is to save surface area on the platform of the robot. 

**Connection of beveled gears**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Beveled_connection.png)

## Constraint Solutions

**Constraint Solution 1:**

The Arduino will send a logical High to “input 1” and a logical Low to “input 2” when the RGB sensor from the start subsystem sees the start light is green or when the backup pushbutton from the start subsystem is pressed.

**Constraint Solution 2:**

Since the stop buttons center is 2.5 inches from the bottom of the course the paint roller will overhang the tracks when it swings out. This can be achieved by having two consecutive perpendicular arms that force the paint roller to hang lower from the shaft connected to the secondary beveled gear on the robot’s base platform. The dimensions of where the button is located is in the first figure below and the part where the buttons general location on the gameboard is labeled “E” in the third figure below.

In order to reach the button the, shaft will need to reach out at least 5.9" that will be perpendicular to the tank trancks. This is because the width of the robot is is 9.24 inches and the platform width that the pushbutton system will be on is 6.1 inches. The total width of the course is 20.81 inches. If the robot is centered on the track the then the length from the platform to the other end of the wall is 11.57 inches total for both sides. If you divide this width by 2 then you can find the length from the right track side to the button which ends up being 5.8 inches. The decision to go with 5.9" is based off the fact that the paint roller foam will compress inward due the pressure of the wall. 

Since the length of the robot is 10 inches total in width due to the track size, then the arm of the push button will placed approximately 1.27 inches from the back right side of the robot. This is because the button is seven inches from the back wall and if the robot goes to the very end in worse case scenario then the arm will not be too far away to reach it. The math behind this is 10 inches of track length - 7 inches from back wall = 3 inches torwards the back end of the robot extends past the button. The platform is 8.27 inches in length so 10 inches - 8.27 inches gives a 1.73 inches. Then dividing this number by two gives the total extra length the track extends out past the platform for one end. So the amount the tracks extend out past the platform for one side is 1.73 in. / 2 = 0.865 inches from the platform to the end of the track. If the track extends past the button by 3 inches then the platform extends past the button by 2.135 inches (3 in. - 0.865 in.). So from this calculation the arm for the push button system needs to be at least 2.135 inches from the back right side of the robot or be placed up more towards the front. 

**Measurements of Pushbutton System**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Measurements.png)

**Stop button precise location**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Game_board_buttton.png)

**Stop button general location “E”**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Game_Board.png)

**Constraint Solution 3:**

When the arm/shaft of the push button subsystem is not active, the height and width of the arm/shaft will not exceed the leftover height of the robot and it will be flush with the platform before swinging in an outward motion. Since the height of the arm will be 3 inches tall and the height of the platform it sits on is 3.74 inches tall the robot will still be within 1 cubic foot. When the arm of the robot is retracted the arm with the paint roller can run parellel with the tracks. 

**Constraint Solution 4:**

The length of the shaft/arm needs to at least reach out approximately 12 inches for our robot being centered of the course. The course width from side to side is 23.25 inches. If our robot is approximately 1 foot in width, then our arm needs to be at least 11.25 inches when extended out from the side of the robot chassis. This is assuming we are in the center of the board. The figure below shows the total width of the board.

**Game board dimensions**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Game_Board_dimensions.png)

**Constraint Solution 5:**

The external battery supply voltage will be at least 9 volts since there is a 2-volt voltage drop across the L298N motor driver and because our geared dc motor requires at least 6 volts to operate.

**Constraint Solution 6:**

To help prevent the motor from reaching its max torque load, I have created my bevel gear model to have a high gear ratio of 1.25. This higher gear ratio increases the more output torque increases with less input torque from the dc motor. For beveled gears I had to change the pitch angle of the drive gear to 39 degrees and the driven gear to 50 degrees to get them to mesh properly.

**Constraint Solution 7:**

The bevel gear teeth will have a pressure angle of 20 degrees because this will reduce slippage in between the drive gear and the secondary gear. Gears with this pressure angle can endure higher torque loads on the teeth of the gear. To achieve this if you can install the add on for blender called “precision gears”. Once downloaded you can choose what type of gear you want, to do this click the “add” tab at the top then click “Mesh” then go to the very bottom and choose the “precision gears” tab. From there you will select the beveled gear and make sure your units are in metric. Then select the drive gear and click on the “object” tabs to the right in blender and you will see a section called “parameters” go to the option called “pressure angle” and enter 20 degrees. Then repeat the same steps for the driven gear.

**Depiction of pressure angles for gears**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Depiction_pressure_angle.png)

**Constraint Solution 8:**

To get the drive gear to fit without coming off the dc motor shaft, the borehole diameter needs to be slightly larger than the shaft diameter without being so much larger it comes off or causes slippage. An AGME standard is that the inner diameter of the borehole must be no larger than 0.001 in. if it will be housing the shaft of the motor. Since our dimensions of the gears are metric and in mm, our housing diameter of the drive gear will be no larger than 0.02mm. To do this select the drive gear and click on the “object” tab on the right panel and then scroll down to the option called “borehole” then select “round subtract” to cut out the center diameter of the gear and enter 1.51mm into the radius parameter of the borehole selection. This radius gives us a diameter of 3.02mm which is within the 0.0254 mm maximum clearance from the AGME standard, for our 3mm shaft. We will not need to do this for our driven gear because there will be no shaft going into the borehole.

## BOM

| Item | Description | Subsystem | Part Number | Manufacturer | QTY. | Price | Total Price |
|------|-------------|-----------|-------------|--------------|------|-------|-------------|
| Geared DC motor | Used to turn the shaft | Push button  | 6V-100RPM-150i | Greartisan | 1 | $11.99  | $11.99 |
| Paint roller | Used to compress button | Push button  | N/A | Mister Rui | 1 pk | $10.97  | $10.97 |
| Motor shield/driver | Controls the direction and speed of the geared dc motor | Push button  | L298N | N/A (Recycled) | 1 | $0.00  | $0.00 |
| PLA | Used for printing gears | Push button  | N/A | N/A | 1.7 cu in. | $0.00 | $0.00 |
|  |  |  |  |  |  |  | $22.96  |


**DC Motor dimensions:**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/DC_motor_dimensions.png)

**Specs of DC motor:**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Specs_DC_motor.png)


