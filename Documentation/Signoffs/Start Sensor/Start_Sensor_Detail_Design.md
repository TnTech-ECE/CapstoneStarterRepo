# Start Sensor System

## Function of the Subsystem

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/CazBilbrey-StartSensor-SignOff/Documentation/Signoffs/Start%20Sensor/Start%20Block%20Diagram.png)
Figure 1: Start Sensor Block Diagram

The Start Sensor System plays a pivotal role in launching the robot's predefined course. It employs an RGB color sensor programmed to identify a green LED, which marks the beginning of the robot's journey. Upon powering the sensor, if it detects the specified green color, it promptly communicates this information to the Main Controller, triggering the start state.

To ensure operational robustness and mitigate the risk of sensor malfunction, a fail-safe option is in place. This involves a manual button that can be pressed in the event of sensor failure or unexpected issues. This redundancy enhances the robot's reliability and resilience in practical applications.


## Constraints and Standards

| Number | Constraint Description | Origin |
|--------|------------------------|--------|
| 1. | The RGB Sensor shall detect a spectrum of green light from an LED | Competition Specifications |
| 2. | The RGB Sensor shall detect the light within 3 seconds of light being turned on | Strategy Specifications |
| 3. | The RGB Sensor shall be placed between 3.7 to 4.3 inches from the ground | Competition and Sensor Specifications |
| 4. | The RGB Sensor shall be located with in a length range of 0.5 inches of the Green Light LED location | Competition and Sensor Specifications |
| 5. | The RGB Sensor shall be located in a width range with in 3 inches from the wall to the middle of of the Green Light LED location | Competition and Sensor Specifications |

## Buildable Schematic

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/CazBilbrey-StartSensor-SignOff/Documentation/Signoffs/Start%20Sensor/newest%20Start%20System%20scematic.png)
Figure 2. Wiring Diagram for Start Sensor

The APDS-9960 is a digital RGB, ambient light, proximity, and gesture sensor that operates through I2C communication.  

GND (Ground): Pin 6 establishes the ground connection for the circuit, serving as a shared reference point for electrical signal.

VCC (Power Supply): Pin 8 is used to power the APDS-9960 sensor board. It requires a voltage supply between 2.4V and 3.6V. 

SDA (Serial Data Address): Pin 1 is part of the I2C communication interface. It's used to transfer data to and from the sensor when connected to a microcontroller. It is typically connected to the SDA pin on your microcontroller or I2C bus. 

SCL (Serial Clock Line): Pin 7 is the clock line for I2C communication. It provides the clock pulses necessary for synchronized data transfer. It's usually connected to the SCL pin on your microcontroller or I2C bus. 

INT (External Interrupt): Pin 2 serves as an external interrupt pin. It goes LOW during an interrupt event, which is often used to notify the microcontroller that a certain condition or gesture has been detected. 

To wire the APDS-9960 sensor to a microcontroller, you would typically connect the following pins: 

-Connect GND (Pin 6) to the ground (GND) of your microcontroller. 

-Connect VCC (Pin 8) to the power supply voltage within the specified range. 

-Connect SDA (Pin 1) to the I2C_data pin on your microcontroller or I2C bus. 

-Connect SCL (Pin 7) to the I2C_CLK pin on your microcontroller or I2C bus. 

-Connect INT (Pin 2) to an available external interrupt pin on your microcontroller. 

With this wiring setup and the appropriate code, you can use the APDS-9960 sensor to detect and process RGB colors, ambient light levels, proximity, and gestures, making it a versatile sensor for various applications like touchless interfaces and color detection.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/CazBilbrey-StartSensor-SignOff/Documentation/Signoffs/Start%20Sensor/over%20all%203d%20model.PNG)
Figure 3. Rough 3D Model of entire Robot

The figure above shows a rough 3D model of what the robot will look like with the Start Sensor System. In the picture above, the Green represents Power System, the blue represents the Navigation System, the Paint roller is the Button Push Mechanism, the Orange represents the Main Controller, the Yellow represents the Team Spirit System, the Brown stick on the back of the robot represents the Box Sweep System, and the Drivetrain is located underneath the robot. The start system includes both Gray rectangles near the back of the robot. The red marker is the push button, while the black marker is the color sensor, the perf board is represented with a purple area under the pushbutton. 

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/CazBilbrey-StartSensor-SignOff/Documentation/Signoffs/Start%20Sensor/3D%20Model%20Side.jpg)
Figure 4. Precise Height of Start Sensor

Figure 4 (above) shows the scale of how the Sensor and button will be located from a side view. You can see that the bottom of the sensor and button range from 3.7-4.3 inches due to the location of the Green LED placed on the course (Figures 6 & 7). The height of the tracks, once designed in the Drivetrain System, will adjust this height further, however the sensor must hit this range to properly read the green light that indicates the start of the run(Constaint 4).

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/CazBilbrey-StartSensor-SignOff/Documentation/Signoffs/Start%20Sensor/3D%20Model%20Top.png)
Figure 5. Precise location of Start Sensor

Figure 5 (above) shows where the Sensor will lay out on the Robot and a rough location of the button. You can read more about the button location in the analysis section. This does not include the perf board because it allows for a cleaner view of what is happening.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/CazBilbrey-StartSensor-SignOff/Documentation/Signoffs/Start%20Sensor/button%20with%20perf%20board.PNG)
Figure 6. Button and Sensor attached to Robot

Attaching to Chassis:

Figure 6 offers a rough visual representation of how the Button and Sensor are integrated into the robot. Our strategy involves employing a perf board for the button, which will be securely soldered into position, while the sensor will be affixed to the chassis using screw fastenings. This assembly method is designed for maximum stability and reliability in our robot's configuration, as exemplified by the corner bolts that secure the boards firmly in place.

## Analysis

Constraint 1 Solution:  The RGB Sensor shall detect a spectrum of green light from an LED. The RGB Sensor is configured to specifically detect the color green by setting both its red and blue sensors to a high state, allowing it to be sensitive to green light. The detailed explanation of how this configuration operates can be found in the Buildable Schematic Section, taking into account the specific characteristics of the LED's green light that it will be reading.

Constraint 2 Solution: The RGB Sensor shall detect the light within 3 seconds of light being turned on. The RGB Sensor is crucial for our competition performance as it's required to read and output within a strict 3-second timeframe. Failing to meet this time limit could result in us not earning points for that particular run of the competition. To mitigate this risk, we have a contingency plan in place – we can manually initiate the robot's start using the push button. This approach allows us to proceed with other tasks aimed at scoring points.

However, it's essential to emphasize the importance of adhering to the 3-second window. Any delay beyond this limit could potentially cost us points in other aspects of the competition. Therefore, precise timing and efficient sensor operation are key to our overall success in the competition.

Constraint 3 Solution: To optimize the performance of the RGB Sensor, it will be positioned at a specific height of approximately 4 inches from the ground, as depicted in Figures 3 and 5. This location, at the back and center of the robot, ensures proximity to the Green LED situated on the starting wall, illustrated in Figure 7. This positioning is essential because the sensor is most effective at detecting objects within the range of 0.0 to 0.8 inches. However, placing it parallel to the LED may lead to potential blockage or shadows caused by the sensor itself, hindering accurate readings.

By situating the sensor slightly lower, it allows for better light capture, enhancing its ability to detect the Green LED. The optimal placement range lies between 3.7 to 4.3 inches, and 4 inches serves as the middle ground within this range. The 'B' denoted on the Competition Board (Figure 8) indicates the precise location of the Green LED, offering a clear reference for positioning the RGB sensor appropriately. This positioning strategy aims to ensure consistent and reliable detection of the Green LED, a critical aspect of the robot's functionality.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/CazBilbrey-StartSensor-SignOff/Documentation/Signoffs/Start%20Sensor/Board%20Diagram.png)
Figure 7. Competition Board Layout  

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/CazBilbrey-StartSensor-SignOff/Documentation/Signoffs/Start%20Sensor/Board%20Diagram%202.png)
Figure 8. Exact Height of Start Sensor

Constraint 4 Solution: 
The placement of the RGB Sensor must be meticulously calibrated within a range of 0.5 inches of the Green Light LED location. It is imperative to position the RGB sensor in extremely close proximity to the Green Light LED, with an optimal range of 0.5 inches. This stringent requirement effectively confines the allowable distance to a tightly regulated 1-inch zone. This precision ensures that the sensor is strategically positioned to capture the maximum amount of green light, facilitating highly accurate detection of the Green Light LED.

The reason for this specific range is to guarantee that the sensor can consistently and reliably detect the Green Light LED. By positioning it within this 0.5-inch zone, we maximize the amount of green light entering the sensor, thereby enhancing its sensitivity and reliability in recognizing the LED's presence. This meticulous placement is crucial for the overall success and functionality of the robot in the intended tasks.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/CazBilbrey-StartSensor-SignOff/Documentation/Signoffs/Start%20Sensor/3D%20Model%20Top%202.png)
Figure 9. Exact location lengthwise of Start Sensor and green LED

Constraint 5 Solution: The RGB Sensor is to be precisely positioned within a width range, spanning a distance of 3 inches from the wall to the midpoint of the Green Light LED location. This targeted width range entails that the sensor must be situated within 3 inches from the wall and towards the midpoint of the sensor's own location.

In Figure 7, the illustration provides a clear perspective of this setup, demonstrating that the distance from the sensor's midpoint to the end of the robot measures approximately 1.3 inches or 3.3 cm. This specific placement range is meticulously chosen to ensure the sensor's proximity to the Green LED, optimizing its ability to detect the light and provide the expected output.

The rationale behind this range is to maintain the sensor's close proximity to the Green LED, thus enhancing its ability to read and respond to the light source accurately. This strategic positioning is critical for achieving the desired performance and functionality of the robot in its designated tasks. 

## BOM

| Item | Description | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-----------|-------------|--------------|----------|-------|-------------|
| RGB Sensor | Sensor to detect green LED | Start Sensor System | APDS-9960 | Avago Technologies | 1 | $7.50 | $7.50 |
| Push Button (20 pcs) | Failsafe Button | Start Sensor System | TS-D001, 5mm | CHANZON | 1 pk | $4.99 | $4.99 |  
| | | | | | | | $14.49 |
