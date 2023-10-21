# Functions of the Subsystem

The ground based sensor subsystem is to sense vehicles passing above the sensor, allowing for the system to keep a count of the
number of cars that are in a specified parking lot on the campus of Tennessee Tech.  This system will be placed at parking lots
that have specified entrances/exits.  By using lots that have this constraint, it will allow the system to keep an accurate count
of the number of cars in a specific lot.

# Constraints
| No. | Constraints | Origin |
| --- | ----------- | ------ |
| 1.  | Subsystem shall detect vehicles entering and exiting a parking lot. | System Requirements |
| 2.  | Sensor shall function between 20 kHz and 100 kHz frequencies.       | System Requirements |
| 3.  | Vehicle detector shall cover a range of at least 50 &mu;H to &mu;H. | NEMA Standards      |

1. The system will need to detect vehicles that are in the detection area of the loop for determining whether a vehicle is entering a lot or exiting a lot.  For the parking lot in the Engineering Quad on the campus of Tennessee Tech University, there are two entrances/exits to access the parking lot.  This will require two loops at each entrance/exit with a Diablo DSP-15 Vehicle Detector controlling each loop.  This will require two Diablo DSP-15 Detectors for each entrance/exit.  One loop will be near the road that is in front of Brown Hall and the other loop will be at the exit of the parking lot for the entrance/exit.  The output of each loop will be connected to a microcontroller that is part of the Data Transmission subsystem.
2. The system will need to function between 20 kHz and 100 kHz frequencies to be within the frequency range of 10 kHz and 200 kHz that is stated by the U.S. Federal Highway Administration [1].  By using a frequency range that exceeds 20 kHz, we are able to detect vehicles passing over the loop by focusing on object detection.  Due to the goal of this project being able to detect the presence of a vehicle near the loop, it is not necessary to focus on the details of the vehicle, but rather the presence of a vehicle.
3. The vehicle detector system that will be used must be able to either manually tuned or automatically tuned to cover the given range of inductance values or greater [2].  When a vehicle passes over an inductive loop, the vehicle induces eddy currents in the loops.  The eddy currents then force the inductance of the loops to decrease, which leads to a change that is detected by the DSP-15 Vehicle Detector.  If inductance does not change, then a vehicle is not present within the detection range of the inductive loop.

# Buildable Schematic

# Analysis


# BOM
| Part | Part Number | Quantity | Price Per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Diablo Controls Inc. DSP-15 Vehicle Detector | DSP-15-T | 4 | $85.69 | $342.76 |

# References
1. “Chapter 2, Traffic Detector Handbook: Third edition-volume I,” FHWA, https://www.fhwa.dot.gov/publications/research/operations/its/06108/02.cfm (accessed Oct. 21, 2023). 
