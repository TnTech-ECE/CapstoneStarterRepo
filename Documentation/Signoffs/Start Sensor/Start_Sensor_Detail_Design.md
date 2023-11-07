# Start Sensor System

## Function of the Subsystem

![Start Block Diagram](https://github.com/cebttu/CapstoneTeam1/assets/100803345/3065734b-7bd4-4b11-8a22-0d7dc8c595ce)
<br />
Figure 1: Start Sensor Block Diagram

The Start Sensor System plays a pivotal role in launching the robot's predefined course. It employs an RGB color sensor programmed to identify a green LED, which marks the beginning of the robot's journey. Upon powering the sensor, if it detects the specified green color, it promptly communicates this information to the Main Controller, triggering the start state.

To ensure operational robustness and mitigate the risk of sensor malfunction, a fail-safe option is in place. This involves a manual button that can be pressed in the event of sensor failure or unexpected issues. This redundancy enhances the robot's reliability and resilience in practical applications.


## Constraints and Standards

| Number | Constraint Description | Origin |
|--------|------------------------|--------|
| 1. | The RGB Sensor shall detect a spectrum of green light from an LED | Competition Specifications |
| 2. | The RGB Sensor shall detect the green light within 3 seconds of the green LED being turned on | Strategy Specifications |
| 3. | The RGB Sensor shall be placed within a vertical range of 0.8 inches below the center of the LED | Sensor Specifications |
| 4. | The RGB Sensor shall be located within a range of 0.5 inches to the left or right of the Green Light LED location | Sensor Specifications |
| 5. | The RGB Sensor shall be at most 1.5 inches from the LED when the robot is placed on the board| Sensor Specifications |

## Buildable Schematic

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/CazBilbrey-StartSensor-SignOff/Documentation/Signoffs/Start%20Sensor/newest%20Start%20System%20scematic.png)
<br />
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
<br />
Figure 3. Rough 3D Model of the entire Robot

The figure above shows a rough 3D model of what the robot will look like with the Start Sensor System. In the picture above, the Green represents the Power System, the blue represents the Navigation System, the Paint roller is the Button Push Mechanism, the Orange represents the Main Controller, the Yellow represents the Team Spirit System, the Brown stick on the back of the robot represents the Box Sweep System, and the Drivetrain is located underneath the robot. The start system includes both Gray rectangles near the back of the robot. The red marker is the push button, while the black marker is the color sensor, the perf board is represented with a purple area under the push button. 

![ChipFromWall](https://github.com/cebttu/CapstoneTeam1/assets/100803345/45fb78c1-9829-4a60-b00f-9874cf189764)
<br />
Figure 4. Precise Height of Start Sensor and Distance from LED

Figure 4 (above) shows the scale of how the Sensor shall be located from a side view. The chip is 0.5 inches below the center of the Green LED due to the optimal detection distance of the sensor. This means the chip must be 4 inches from the ground as the center of the LED is 4.5 inches from the ground, see Figure 7 (Exact Height of Start Sensor.) The chip shall also be 1 inch from the face of the LED, and the back wall of the board as it should be flush. This will place the middle of the chip 1.35 inches from the LED's face.


![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/CazBilbrey-StartSensor-SignOff/Documentation/Signoffs/Start%20Sensor/button%20with%20perf%20board.PNG)
<br />
Figure 5. Button and Sensor attached to Robot

Attaching to Chassis:
Figure 5 offers a rough visual representation of how the Button and Sensor are integrated into the robot. Our strategy involves employing a perf board for the button, which will be securely soldered into position, while the sensor will be affixed to the chassis using screw fastenings. This assembly method is designed for maximum stability and reliability in our robot's configuration, as exemplified by the corner bolts that secure the boards firmly in place. 

![Shroud](https://github.com/cebttu/CapstoneTeam1/assets/100803345/1b6439f0-add8-4d68-8b85-bc7182725e2c)
<br />
Figure 6. Shroud

To further aid in the capturing of the light from the LED, a shroud will be constructed and centered over the chip. This shroud shall be tall enough (0.8 inches) to reach above the LED, this will allow the maximum amount of light from the LED to enter the shroud, while still blocking much of the ambient light of the room. The inside of the shroud also will be lined with a reflective material, such as aluminum foil to further reflect the LED's light into the sensor.


## Analysis

Constraint 1 Solution:
<br />
To make the chip detect green, we must connect the APDS-9960 module to our microcontroller using the appropriate pins. The APDS-9960 has pins for power (VCC and GND), I2C communication (SDA and SCL), and interrupt pins (if required). We must ensure that the module receives the required power supply voltage (VCC) within its specified voltage range (usually 3.3V or 5V). We will use the I2C communication protocol to interface with the APDS-9960 chip. We'll need to write and read data over the I2C bus to configure the sensor and retrieve information from it. Then we will initialize the APDS-9960 module by setting the appropriate configuration parameters. We can set the sensor to operate in color sensing mode, enabling it to detect different colors, including green. The APDS-9960 uses a combination of red, green, and blue (RGB) photodiodes to detect color. When you place a green LED in front of the module, the green light emitted by the LED will be incident on the green photodiode. For green light, the APDS-9960 sensor is designed to detect light in the wavelength range typically associated with green light, which falls within the range of approximately 520 nanometers (nm) to 570 nm. This corresponds to the green part of the visible light spectrum. The photodiodes generate an electrical current in response to the detected light, and the module converts this current into a digital value representing the intensity of the detected color. Then it will read the color sensor data from the APDS-9960 module, our sensor starts to read in green light at 495 nm to 575 nm per the datasheet. The data will typically be in the form of digital values representing the intensity of the red, green, and blue light detected. You can use I2C commands to request this data from the module. 

In the main controller code, we can analyze the color sensor data to determine whether the detected color is green. The main controller will receive the percentages of light (Red, Green, and Blue) via the I2C bus. It will then compare these values to each other, once Green is established as the highest value, the main controller will send signals to other subsystems to begin their operation.

Constraint 2 Solution:
<br />
The RGB Sensor shall detect the light within 3 seconds of the green light being turned on. To aid this, the main controller and the start sensor will be powered on before the robot is placed on the start pad. The main controller will send signals via the I2C bus at this point to power on and enable the color detection process within the chip. At this point, the sensor shall begin taking in data and comparing it, however since the robot is not placed yet, the sensor can not accidentally read green and begin any other functions. To protect against this, black electrical tape will be placed over the opening of the shroud, this will block light from entering the sensor until it is removed. The tape shall only be removed once the robot is placed properly. This allows the sensor to boot up and perform the setup tasks before being placed, therefore omitting the time needed for setup and the sensor can begin detecting the LED's light immediately once the tape is removed. 

Once the tape is removed, the sensor will take in data from the LED, however, the LED will remain red until the judges start the clock. In the absolute worst case the LED will change to green in the middle of sending the data from the red light, this means that an entire data-sending cycle must complete and begin again and run to completion before the main controller will be able to compare the values of the green light. In standard mode which is the slowest, the I2C bus can transfer data at 100kbits/sec. A single data-sending cycle from requesting the information to sending all the values (red, green, blue, and clear) will take at least 145 bits in total. Under standard mode, this means this data can typically be sent in 1.45 ms. For two whole cycles to run to completion will take at least 2.9 ms. This gives plenty of extra time to allow for delay at any point in the detecting or sending process.

In case the sensor fails to read the start signal properly, we can manually initiate the robot's start using the push button after 3 seconds have passed. The signal passed by the button when pressed will be interpreted by the main controller as equivalent to the sensor detecting green, and so the main controller will then begin the rest of the run in a reasonable amount of time.

Constraint 3 Solution:
<br />
For ensuring the optimal performance of the RGB Sensor, it is imperative that the sensor be positioned within a specific vertical range of 0.8 inches from the center of the LED. The sensor's height above the ground should be precisely 4 inches or 0.5 inches below the LED's center, as illustrated in Figure 4. This precision is of paramount importance because the sensor's proficiency lies in detecting objects within the vertical span of 0.0 to 0.8 inches. However, placing the sensor in parallel with the Green LED poses a risk of casting shadows or causing obstructions that could disrupt its accuracy and impede the robot's functionality.  

To mitigate this issue, the sensor is strategically positioned 4 inches above the floor or 0.5 inches below the LED's center, thus maintaining its operation within the optimal detection range while avoiding parallel alignment with the LED.  

Regarding the APDS-9960, it employs an ambient light sensor with a photodiode array that is meticulously oriented for efficient light detection. The photodiodes are conventionally situated on the sensor module to receive light from the top surface of the chip. This configuration optimizes their responsiveness. Moreover, the photodiodes are shielded with a light-sensitive material and may include an optical window or cover to filter unwanted light and protect the sensor from external interference.  

Significant alterations in the direction of incident light can have a disruptive effect on the photodiodes' performance. Placing objects or barriers between the light source and the sensor can lead to improper light detection or attenuated responses. Similarly, exposing the sensor to light from a direction not aligned with its intended orientation can result in suboptimal functionality.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/CazBilbrey-StartSensor-SignOff/Documentation/Signoffs/Start%20Sensor/Board%20Diagram%202.png)
<br />
Figure 7. Exact Height of Start Sensor


Constraint 4 Solution: 
<br />
The RGB Sensor must be placed within a range of 0.5 inches to the left or right of the Green Light LED location. It is imperative to position the RGB sensor close to the Green Light LED, with an optimal range of 0.5 inches. This stringent requirement effectively confines the allowable distance to a tightly regulated 1-inch zone. This precision ensures that the sensor is strategically positioned to capture the maximum amount of green light, facilitating highly accurate detection of the Green Light LED. The sensor shall be centered on the robot so that it is equidistant from each side so that when the robot is set in the middle of the start pad and 1 inch from the wall, the sensor and the LED will be aligned.

The reason for this specific range is to guarantee that the sensor can consistently and reliably detect the Green Light LED. By positioning it within this 0.5-inch zone, we maximize the amount of green light entering the sensor, thereby enhancing its sensitivity and reliability in recognizing the LED's presence.

![Alt text](https://github.com/cebttu/CapstoneTeam1/blob/CazBilbrey-StartSensor-SignOff/Documentation/Signoffs/Start%20Sensor/3D%20Model%20Top%202.png)
<br />
Figure 8. Exact location lengthwise of Start Sensor and green LED

Constraint 5 Solution:
<br />
The RGB shall at most be 1.5 inches from the face of the LED. Placing the sensor within a range of 1.5 inches from the LED aids the sensor's ability to detect the presence of the Green LED with the highest degree of accuracy while minimizing the risk of any obstructions or shadows. In Figure 4, the sensor is shown to be placed 1 inch from the LED and therefore the wall and this places the midpoint of the chip at 1.35" from the LED. To obtain this distance, the chip shall then be placed as far to the back edge of the robot as possible, to allow at least 1 inch behind the robot's back edge for other Systems with very slight room for error while placing the robot on the start pad (0.15".)


## BOM

| Item | Description | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-----------|-------------|--------------|----------|-------|-------------|
| RGB Sensor | Sensor to detect green LED | Start Sensor System | APDS-9960 | Avago Technologies | 1 | $7.50 | $7.50 |
| Push Button (20 pcs) | Failsafe Button | Start Sensor System | TS-D001, 5mm | CHANZON | 1 pk | $4.99 | $4.99 |  
| | | | | | | | $14.49 |
