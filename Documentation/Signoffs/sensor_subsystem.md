
# Sensor Subsystem

**Function:**

![Elaboration Photo](/images/conceptual)

Figure 1: Sensor Subsystem

The goal of this subsystem is to accurately and quickly gather several data points to determine the
distance, speed, and position of the target as it slides down the fishing line.

**Constraints:**

| No. | Constraint                                                          | Origin           |
|-----|---------------------------------------------------------------------|------------------|
| 1   | The sensors shall be wirelessly connected to the processor         | Conceptual Design|
| 2   | The sensors shall be powered by a 5-volt source                    | Device Constraint|
| 3   | A sensor shall fit within 1'x1'x1' area                            | Conceptual Design|
| 4   | Post sensor will be powered by a battery                           | Conceptual Design|
| 5   | Must be mounted to or from a sensor stand                          | Conceptual Design|
| 6   | Device sensor will be powered by the device                        | System Constraint|
| 7   | The sensor shall read ample data for a maximum golf ball speed of 6 m/s | Conceptual Design|
| 8   | The post sensors shall receive data to calculate height and wire position | Conceptual Design|
| 9   | The device sensors shall receive data to calculate the speed       | Conceptual Design|
| 10  | The sensors shall have range large enough to cover the gameboard   | Conceptual Design|
| 11  | The sensors shall be able to detect plastic                        | System Constraint|

1. The sensors shall be wirelessly connected to the processor [Conceptual Design]
The post sensors and the device sensors need to be wirelessly connected to the processor because they are
not close enough to be wired.
3. The sensors shall be powered by a 5 volt source [Device Constraint]
Needs to be powered by a 5-volt source, regardless of placement because that is what the board of the
sensor requires.
5. A sensor shall fit within 1'x1'x1' area [Conceptual Design]
There will be a sensor placed on the launcher itself therefore it needs to be small enough to fit.
6. Post sensor will be powered by a battery [Conceptual Design]
The sensor’s connected to the post will be battery powered because there are no available outlets for
power.
7. Must be mounted to or from a sensor stand [Conceptual Design]
The non device sensors will be mounted to the sensor posts.
8. Device sensor will be powered by the device [System constraint]
The device sensor will be connected to the device and therefore powered by that device.
9. The sensor shall read ample data for a maximum golf ball speed of 6 m/s [Conceptual Design]
The golf ball has a maximum calculated speed of 6 m/s. The sensor needs to track an ample number of
data points regardless of the speed.
10. The post sensors shall receive data to calculate height and wire position [Conceptual Design]
The post sensors will be responsible for acquiring the data necessary in determining which variable height
and which variable wire position the golf ball is traveling from. It is ideal for this sensor to assist with
acquiring speed data as well.
11. The device sensors shall receive data to calculate the speed [Conceptual Design]
The device sensors will be responsible for acquiring the data necessary in determining what the speed or
estimated speed of the golf ball to aid in firing. It is ideal for this sensor to assist with acquiring position
and height data as well.
12. The sensors shall have range large enough to cover the gameboard [Conceptual Design]
The sensors will need to have a range large enough to cover the 60 inches from the start of the board to
the device, the 64 inches side to side which is the width of the gameboard and must cover up to the
highest variable height.
13. The sensors shall be able to detect plastic [System Constraint]
The sensors have to be able to detect the plastic golf ball from about 4-6 feet away

**Analysis:**

Based on the constraints given, the team chose the VL53L8CX time of flight sensor. This sensor
was chosen because it is able to detect plastic, has a range of about thirteen meters, has a wide field of
view, has low power consumption requirements, has a sampling frequency that can take multiple
measurements of the ball’s trajectory, and can be used to determine distance for both height and location.
After determining the sensor, a SATEL-VL53L8 board was chosen to integrate with the sensor. This
board allows for integration with a microcontroller that will be used in the communication system to
transmit the data. It also provides its own power regulation for the sensor therefore only requiring a 5-volt
input from the battery or device power systems. The exact specifications and advantages of the device
that meet the project specifications and expected functionality will be further discussed.

The team plans on using two sensors to determine the golf ball’s height, line position, and speed.
One sensor will be located on the stand closest to where the golf ball starts its trajectory. This sensor can
be used to determine the height because it will be closest to the original height. It is important to do the
measurements for distance and height because the closer the sensor is to the ball’s location the higher the
accuracy. At about six feet, the approximation of worst-case scenario of distance to the fishing line, the
sensor has a four percent tolerance for eighty-eight percent reflective objects. This will provide a ±2.88
inch offset for where the golf ball may actually be which is fine because the gap between the fishing lines
is four inches horizontally and seven inches vertically. Since the offset is smaller than the gaps, the sensor
should detect enough change in distance for each line to tell them apart as well as which height level is
being used. This measurement also leaves enough room for the error to increase due to changed
conditions and still function. The second sensor will be placed on the interceptor device itself. This will
allow the sensor to have the same angle on the golf ball regardless of where the ball is on the fishing line.
This will be used to determine the speed using multiple samples from the sensor as the ball moves.
Ideally, the speed, position, and height will be confirmed by cross referencing the data both sensors get to
account for the four percent error. This error approximation comes from the datasheets provided
specifications when the sensor is acting in 4x4 resolution mode at 30 HZ which is ideal to obtain several
samples for location and speed calculations.

This system must be able to obtain several accurate samples within the time the golf ball is
dropped, to the time it enters the designated firing zone. The maximum length between the firing
mechanism and the start of the board is 60 inches. Because of this, it is imperative the VL53L8CX get
ample data within that 60-inch range. The VL53L8CX has a frame rate capability of 60 HZ. This
frequency gives a clock period of 16.67 ms. 

![Clock Period formula](/images/clock_period)

This means the VL53L8CX will receive another data sample every 16.67 ms. From the conceptual design
we can assume the max speed of the golf ball is 6 m/s. If the golf ball is traveling at this speed, it will go
236.448 inch/sec:

![Speed formula](/images/speed)

This means the golf ball will pass by the firing machine after .25376 seconds, or 253.76 ms. This will
allow for 14 samples to be taken before the projectile reaches the interceptor when operating at the
maximum frequency. However, the mode that the device will be operating on based off the information on
the datasheet will operate at 30 HZ. This will result in a clock period of 33.33 ms. This will halve the
number of samples to seven samples. However, only two samples are absolutely necessary for the sensing
to work as intended. Two samples will be needed to determine the speed of the golf ball. More samples
allow for better estimations and higher accuracy which is why seven samples is a good rate.

There are two different ways that the sensor can send and receive the data it is gathering, I2C
(Inter-Integrated Circuit) and SPI (Serial Peripheral Interface). Both of these options rely on serial data
transfer however, SPI runs at a much higher frequency at a maximum of 3 MHz as opposed to the
frequency of 1 MHz of I
2C. In order to run this board in SPI mode, the pins EXT_MOSI_SDA,
EXT_MISO, NCS, and EXT_MCLK_SCL are used for serial data in, serial data out, chip select, and
serial clock respectively. The board will also have to have the pins LPn and EXT_SPI_I2C_N have to be
set to a high logic level. Based on the schematic provided by the datasheet from the SATEL-VL53L8, it is
known that the pin LPn is set high by default because of the pull up resistor to IOVDD, however a
connection from the EXT_IOVDD pin to the EXT_SPI_I2C_N pin will be required because a pull down
resistor sets this pin to a low logic level.

**Buildable Schematic**

![Absolute Maximums](/images/maximums)

Based on the specification sheets for the LDK130 IC’s that are included in the board, the input voltage for
the voltage enable input can range from a low of -0.3v to a high of VI + 0.3. Therefore, in this case it
would be appropriate to use the 5v from the battery power system as seen below.

![Schematic](/images/schematic)

The functionality of the board itself and its individual pieces can be found in the data sheets in the
references section. These specific references are the data sheet for the SATEL-VL53L8 as well as
the data sheets for the vl53l8CX, and the LDK130 series chip.

**Bill of Materials:**

| Device | Quantity | Price | Total |
| ------ | -------- | ----- | ----- |
| SATEL-VL53L8 Board (2-pack)| 1 | $27.50 | $27.50 |

**References:**

[1] “Datasheet - VL53L8CX - low-power high-performance 8x8 ...,” STMicroelectronics,
https://www.st.com/resource/en/datasheet/vl53l8cx.pdf (accessed Apr. 4, 2024).

[2] “Data brief - satel-VL53L8 - breakout board based on the ...,” STMicroelectronics,
https://www.st.com/resource/en/data_brief/satel-vl53l8.pdf (accessed Apr. 4, 2024).

[3] “UM3109-A-GUIDE-FOR-USING-THE-VL53L8CX- ...,” STMicroelectronics,
https://www.st.com/resource/en/user_manual/um3109-a-guide-for-using-the-vl53l8cxlowpower-highperformance-timeofflight-multizone-ranging-sensor-stmicroelectronics.pdf
(accessed Apr. 4, 2024).

[4] “LDK130-300 mA low quiescent current very low noise LDO (automotive for SOT23-5L
package),” STMicroelectronics,
https://www.st.com/content/ccc/resource/technical/document/datasheet/29/10/f7/87/2f/66/4
7/f4/DM00076097.pdf/files/DM00076097.pdf/jcr:content/translations/en.DM00076097.pd
f (accessed Apr. 4, 2024).

[5] “Pull-up resistor and pull-down resistor explained,” Basic Electronics Tutorials,
https://www.electronics-tutorials.ws/logic/pull-up-resistor.html (accessed Apr. 3, 2024). 
