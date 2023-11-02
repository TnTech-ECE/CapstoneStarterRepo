## Functionality

The push button subsystem will be the process of pushing the stop button to stop the time, which will denote the completion of the course. The system will consist of a dc motor, bevel gears, a shaft, a bearing, a L298N motor driver module, and a paint roller that will swing out on the arm perpendicular to the platform of the robot. The main bevel gear will be driven by the dc motor and the arm that the paint roller will be attached to will be connected to the secondary gear that turns anticlockwise from the main drive gear. This system will be activated after the RGB sensor that is a part of the start sensor subsystem indicates the green light and the microcontroller will then send power to the push button system to swing out the arm with the paint roller on it.

## Specifications and Restraints


| Number | Constraint component | Constraint description | Origin |
|--------|----------------------|------------------------|--------|
| 1. | Arm/Shaft | Length of the arm shall not extend out before the start | Competition Specifications |
| 2. |  Arm/Shaft | The height of the paint roller will hang at most 2.5 inches off the ground to compress the stop button  | Competition Specifications |
| 3. | Arm/Shaft | The dimensions before the start of the arm shall not exceed 1 cubic ft. | Competition Specifications |
| 4. |  Arm/Shaft | Lenth of the arm will not exceed nor be below the length of 12 inches when fully extended | Competition Specifications |
| 5. | DC motor | Operation voltage is 6V for 100 rpm for the dc geared reduction motor | DC motor specs |
| 6. |  DC motor | The stall torque of the motor is 0.7 kg*cm (the max torque that can be applied before the shaft quits rotating). | DC motor specs |
| 7. | Bevel Gears  | The teeth of the beveled gears shall endure enough torque to prevent the teeth from breaking under a load and will have a pressure angle of at least 20 degrees | AGMA Standard |
| 8. |  Bevel Gears  | Drive gear borehole diameter shall fit the diameter of the dc motor shaft down to 0.001 in. = 0.0254 mm.| AGMA Standard |

## Buildable Schematic

To drive the motors, we will use a L298N motor driver that can drive up to but not limited to two dc motors. The speed control pins ENA and ENB are used to turn on/off the motors and control their speed. To start the motion of the motor we will need to make sure the pins of ENA and ENB are pulled HIGH. If we want to change how fast the arm deploys, we can use PWM (Pulse width modulation) to control the speed of how fast the arm that is driven by the motor. 
The internal H–Bridge of the IC is responsible the operation of the motor, and the VS pin powers the IC’s internal H-Bridge which can handle 5V – 12V. The VSS provides power to the logic circuitry inside the L298N IC, with a voltage range of 5V to 7V. The output ports of the driver are OUT1 and OUT2 and OUT3 and OUT4 which can drive 5V to 12V dc motors and are connected to the positive and negative terminals respectively.  
The direction control ports are IN1 and IN2, which controls motor 1 and IN3 and IN4, which controls motor 2. These 4 input ports are controlled using digital HIGH and LOW signals that change the rotation of each motor connected to the L298N.

L298N Driver

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/L298N_2.png)

The truth table below shows the signals we want to send to change direction of the motor. This will be useful to us for when we want to reset the arm with the paint roller on it to pull in back into its original position. 

L298N Truth Table

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/L298N%20TT.png)

Control block diagram for pushbutton system

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Control%20Block%20Diagram.png)


Model of the electrical inductance and internal motor resistance for the DC motor to test and get torque values and loads under different conditions.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Electrical_LT.png)

Model of mechanical circuit that converts the electrical characteristics into the mechanical characteristics such as rpm and torque values.
The results of the LT Spice models will be in the "Analysis" section.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Mechanical_LT.png)


Digital Logic Circuit for L298N Driver

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Digital%20Logic%20for%20L298N.png)


H-Bridge circuit that is within the chip of the L298N chip

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/H_Bridge.png)


**Drive** gear parameters for 3d modeling and printing using blender

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Drive_Gear_Param..png
)


**Driven** gear parameters for 3d modeling and printing using blender 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Driven_Gear_Param.png
)

## Analysis 

**Shaft description:** 

This shaft and arm will be printed using PLA material that way it gives us flexibility if we need to change diameter size or shape. The arm acts as the main support for the paint roller brush. When the paint roller hits the wall after being extended the brush will roll and contour with the wall so that way, we have a point of contact with the right side of the wall for the majority of the course and especially the end. 

**DC Motor description:** 

The DC motor has a gear reduction ratio to increase torque. The reason for this is we need more torque than we do rotor/shaft speed so that it ensures the shaft for the button pusher is turned. To determine what our load torque is of the gears and shaft we can leave or input voltage as at least 6 volts and change the inertial from the shaft to a higher value that to see the max load inertia before reaching stalling torque. When this motor is enabled “Forward” it will rotate clockwise and when enabled to go “Backwards” it will rotate anticlockwise.

**DC Motor model:** 

The essential readings from the LT spice model labeled below as “Readings of LT spice dc motor model for rpm and torque” are the **I(Current_sensor_2)** and the Voltage at **V(node_3)**. The current reading in the **I(Current_sensor_2)** is the equivalent speed of the motor at 6 volts in rpm. The max output torque is equivalent to the voltage at V(node_3) which is in **N*m** and then you can convert that value to Kg*cm. I know this model works because from the specs of the dc motor because the torque and rpm speed match what the load torque and current are equivalent to. The figure labeled “Specs of DC motor” in the BOM section is the original datasheet for the geared dc motor. Our motor is the 100-rpm motor so in the “Specs of DC motor” figure look at the 5th column.

**Readings of LT spice dc motor model for rpm and torque**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/LT_Spice_results.png)

**L298N Driver description:**

The L298N is a directional and speed controller for DC motors. The reason for using this is because it will allow the arm/shaft with the paint roller to swing out and retract back in when desired. It can change directions because the L298N uses an H-Bridge which switches the polarity of the DC motor when specified, and when you switch the polarity of a DC motor it changes rotation. 

**L298N Driver wiring:**

For the wiring for our purpose, we do not need to use any PWM ports since we just want high and low signals to turn the arm/shaft. We can use any of the digital GPIO pins to turn off the motor or control the direction of our motor. One of the digital GPIO pins will connect to “input 1” and the other GPIO digital pin will connect into “input 2” of the L298N. Our external battery connection will need to have the positive terminal connected to the 12+ terminal and the negative terminal of the external battery will need to be connected into the GND pin of our L298N driver.  The positive terminals and the negative terminals of our DC motor will connect its positive terminal into the “Out 1” and the negative terminal will connect into the “Out 2” pin.  The figure below shows the visual connections. 

**Pinout of the microcontroller and the L298N drive**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Wiring_schematic_L298N.png)

**Beveled gears description:**

The beveled gears are the mechanical system behind the pushbutton subsystem. They are used to transfer the work and energy of the dc motor to the arm/shaft with the paint roller attached to it. The reason they are beveled is to save surface area on the platform of the robot.

**Connection of beveled gears**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Beveled_connection.png)

## Constraint Solutions

**Constraint Solution 1:**

The Arduino will send a logical High to “input 1” and a logical Low to “input 2” when the RGB sensor from the start subsystem sees the start light is green or when the backup pushbutton from the start subsystem is pressed.

**Constraint Solution 2:**

Since the stop buttons center is 2.5 inches from the bottom of the course the paint roller will overhang the tracks when it swings out. This can be achieved by having two consecutive perpendicular arms that force the paint roller to hang lower from the shaft connected to the secondary beveled gear on the robot’s base platform. The dimensions of where the button is located is in the first figure below and the part where the buttons general location on the gameboard is labeled “E” in the second figure below.

**Stop button precise location**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Game_board_buttton.png)

**Stop button general location “E”**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Game_Board.png)

**Constraint Solution 3:**

When the arm/shaft of the push button subsystem is not active, the height and width of the arm/shaft will not exceed the leftover height of the robot and it will be flush with the platform before swinging in an outward motion.

**Constraint Solution 4:**

The length of the shaft/arm needs to at least reach out approximately 12 inches for our robot being centered of the course. The course width from side to side is 23.25 inches. If our robot is approximately 1 foot in length, then our arm needs to be at least 11.25 inches assuming we are in the center of the board. The figure below shows the total width of the board.

**Game board dimensions**

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/Adrin11-signoff-PushButton/Documentation/Signoffs/PushButton/Game_Board_dimensions.png)

**Constraint Solution 5:**

The external battery supply voltage will be at least 9 volts since there is a 2-volt voltage drop across the L298N motor driver and because our geared dc motor requires at least 6 volts to operate.

**Constraint Solution 6:**

To help prevent the motor from reaching its max torque load, I have created my bevel gear model to have a high gear ratio of 1.25. This higher gear ratio increases the more output torque increases with less input torque from the dc motor. For beveled gears I had to change the pitch angle of the drive gear to 39 degrees and the driven gear to 50 degrees to get them to mesh properly.

**Constraint Solution 7:**

The bevel gear teeth will have a pressure angle of 20 degrees because this will reduce slippage in between the drive gear and the secondary gear. Gears with this pressure angle can endure higher torque loads on the teeth of the gear. To achieve this if you can install the add on for blender called “precision gears”. Once downloaded you can choose what type of gear you want, to do this click the “add” tab at the top then click “Mesh” then go to the very bottom and choose the “precision gears” tab. From there you will select the beveled gear and make sure your units are in metric. Then select the drive gear and click on the “object” tabs to the right in blender and you will see a section called “parameters” go to the option called “pressure angle” and enter 20 degrees. Then repeat the same steps for the driven gear.

**Depiction of pressure angles for gears**

![Alt text]()
