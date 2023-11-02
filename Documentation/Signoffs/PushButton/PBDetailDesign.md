## Functionality

The push button subsystem will be the process of pushing the stop button to stop the time, which will denote the completion of the course. The system will consist of a dc motor, bevel gears, a shaft, a bearing, a L298N motor driver module, and a paint roller that will swing out on the arm perpendicular to the platform of the robot. The main bevel gear will be driven by the dc motor and the arm that the paint roller will be attached to will be connected to the secondary gear that turns anticlockwise from the main drive gear. This system will be activated after the RGB sensor that is a part of the start sensor subsystem indicates the green light and the microcontroller will then send power to the push button system to swing out the arm with the paint roller on it.

## Specifications and Restraints


| Number | Constraint component | | Constraint description | Origin |
|--------|----------------------|-|------------------------|--------|
| 1. | Arm/Shaft | |Length of the arm shall not extend out before the start | Competition Specifications |
| 2. |  Arm/Shaft | The height of the paint roller will hang at most 2.5 inches off the ground to compress the stop button  | Competition Specifications |
| 3. | Arm/Shaft | The dimensions before the start of the arm shall not exceed 1 cubic ft. | Competition Specifications |
| 4. |  Arm/Shaft | Lenth of the arm will not exceed nor be below the length of 12 inches when fully extended | Competition Specifications |
| 5. | DC motor | Operation voltage is 6V for 100 rpm for the dc geared reduction motor | DC motor specs |
| 6. |  DC motor | The stall torque of the motor is 0.7 kg*cm (the max torque that can be applied before the shaft quits rotating). | DC motor specs |
| 7. | Bevel Gears  | The teeth of the beveled gears shall endure enough torque to prevent the teeth from breaking under a load and will have a pressure angle of at least 20 degrees | AGMA Standard |
| 8. |  Bevel Gears  | Drive gear borehole diameter shall fit the diameter of the dc motor shaft down to 0.001 in. = 0.0254 mm.
| AGMA Standard |

## Buildable Schematic

To drive the motors, we will use a L298N motor driver that can drive up to but not limited to two dc motors. The speed control pins ENA and ENB are used to turn on/off the motors and control their speed. To start the motion of the motor we will need to make sure the pins of ENA and ENB are pulled HIGH. If we want to change how fast the arm deploys, we can use PWM (Pulse width modulation) to control the speed of how fast the arm that is driven by the motor. 
The internal H–Bridge of the IC is responsible the operation of the motor, and the VS pin powers the IC’s internal H-Bridge which can handle 5V – 12V. The VSS provides power to the logic circuitry inside the L298N IC, with a voltage range of 5V to 7V. The output ports of the driver are OUT1 and OUT2 and OUT3 and OUT4 which can drive 5V to 12V dc motors and are connected to the positive and negative terminals respectively.  
The direction control ports are IN1 and IN2, which controls motor 1 and IN3 and IN4, which controls motor 2. These 4 input ports are controlled using digital HIGH and LOW signals that change the rotation of each motor connected to the L298N.
