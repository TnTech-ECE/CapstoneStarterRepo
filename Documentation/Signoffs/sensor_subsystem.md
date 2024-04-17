
# Sensor Subsystem

## **Function:**

The goal of this subsystem is to accurately and quickly gather several data points to determine the
distance, speed, and position of the target as it slides down the fishing line.

## **Constraints:**

| No. | Constraint                                                                                                                                     | Origin            |
|-----|------------------------------------------------------------------------------------------------------------------------------------------------|-------------------|
| 1   | The sensor shall be supplied 5 V via USB from the Jetson Nano processor                                                                        | System Constraint |
| 2   | The sensor shall be able to retrieve at least 2 data points within 1.95 s in order to calculate speed                                          | System Constraint |
| 3   | SOMETHING ABOUT RESOLUTION AND LINE DETECTION | Conceptual Design |
| 4   | The sensor shall have a range of at least 6 feet                                                                                               | Conceptual Design |
| 5   | The sensor shall be able to detect and track a golf ball-sized object from a maximum of 6 feet                                                 | System Constraint |
| 6   | The sensor shall have a field of view greater than 35.5°                                                                                       | Device Constraint |

1. The sensor requires a USB connection for both data and power therefore also requiring a direct connection to the Jetson Nano processor.

2. The fastest time recorded from DEVCOM is 1.95 s for the golf ball to reach the bottom of its trajectory. Therefore, the sensor must be able to retrieve data for at least 2 positions so that speed can be calculated.
3. The sensor must have a resolution great enough to be able to distinguish NOT FINISHED HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
4. The furthest point that the sensor must be able to track and detect is the starting point of each golf ball which is about 6 feet from the launcher
5. The sensor shall be able to detect and track a golf ball-sized object from a maximum of 6 feet
6. The fishing lines that the golf balls slide down extend from anchor 3, given in the rulebook, to anchor 2 at an angle of 35.5°, therefore the sensor must have a field of view larger than that in order to encompass the entirety of the starting point of each fishing line

## **Buildable Schematic**

![Schematic](../Images/Sensor_subsystem/schematic.png)

## **Analysis:**

To start off, the camera or sensor that will be used must have a field of view of at least 35.5°. this was found by using the measurements of the gameboard given in the rulebook from DEVCOM.

![Min FOV](../Images/Sensor_subsystem/fov.png)

### **Bill of Materials:**

| Device | Quantity | Price | Total |
| ------ | -------- | ----- | ----- |
| Intel RealSense D435i | 1 | $304.07 | $304.07 |

## **References:**


