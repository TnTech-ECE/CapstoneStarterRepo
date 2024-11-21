# Power Systems - Experimental Analysis
## Experiment Description

For the power systems, the most important experiment is to measure the voltages and currents with the actual loads 
to find the power instead of the simulation used in the minimal function prototype stage. For both experiments, the voltage and current
was measured. The purpose of the two tests was to calculate the power with the actual loads connected under typical operating modes 
to ensure that the power systems will supply adequate power for the Camera and Receiver subsystems to acheive their full functionality
without limitations due to insufficient power. The maximum power was already tested in the minimal function prototype testing, so the team did not deem it necessary to modify the system trying to obtain those maximum load values.


For the Power Camera system, a voltmeter and ammeter were connected while the Camera Hardware system interfaced with the Camera Software,
Website, and Database systems to make various movements with both motors. We measured 20 individual turns of the motor to gather a
sufficient amount of data. 


For the Power Receiver system, the team used a USB test meter to measure the voltage and current supplied from the Waveshare module
while the receiver system ran the CHANGE THIS program.


### Summary
<!-- Short summary of the experiment written after completing it -->

#### Subsystem(s) Involved:
- Power Camera System

- Power Receiver System

#### Constraints Tested:
- The system shall be able to supply 9 W to each servo motor, and 1.5 W to the camera for the system to acheive full functionality.
- The system shall be able to supply 1.25 W to the ESP32 and 0.7095 W to the ESP8266 for the receiever system to acheive full functionality.
 
#### Expected Result(s):
- The team expects the actual total wattage to be lower than 19.5 W for the servo motors and camera and 1.96 W for the ESP32 and ESP8266 proposed in detail design. This is due to designing the Power systems for the max ratings in the worst case scenario to ensure that the systems would not be out of specification. This was done, because the team was not sure of what the actual load would be during the design process, and the cost difference of reducing the system's power output to the exact specification would be minimal.

## Experimental Procedure
<!-- Description of what you did ideally in steps -->
Power Camera Experiment

- Number of trials: 20

1. Connect the Power Camera system to the Camera Hardware system.
2. Connect two Rigol DM3058E Digital Multimeters to the system with one multimeter acting as a voltmeter and the other acting as a ammeter to measure the voltage and current.
3. Run a test that moves the motors at various angles and takes pictures with the camera.
4. Record the voltage and current readings for each movement.

Power Receiver Experiment

- Number of trials: 20

1. Connect the Power Receiver system to the USB meter.
2. Connect the USB meter to the Receiver system.
3. Run the program for the ESP32 and ESP8266 to transmit data to the database.
4. Record the voltage and current readings.

## Experimental Data
<!-- data tables or graph of the results (whichever is appropriate) -->
Table 1: Power Camera Experiment Results <br/>

| Voltage (V) | Current (mA) | Power (W) |
|---------|---------|-------|
|     5.073    |    44.057     |   0.224    |
|   5.074      |    15.531     |   0.079    |
|    5.073     |     68.914    |    0.350   |
|    5.073     |    75.358     |   0.382    |
|  5.073       |    47.821     |   0.243    |
|    5.073     |    49.369     |   0.250    |
|    5.073     |    43.420     |   0.220    |
|    5.073     |   83.461      |  0.423     |
|    5.073     |   42.641      |   0.216    |
|    5.073     |    48.107     |   0.244    |
|    5.074     |    15.531     |    0.788   |
|    5.073     |      74.486   |   0.378    |
|    5.073     |    44.079     |    0.224   |
|    5.073     |     50.286    |   0.255    |
|   5.073      |     43.386    |  0.220     |
|   5.074      |     34.575    |   0.175    |
|    5.073     |     76.441    |    0.388   |
|   5.073      |    45.009     |   0.228    |
|    5.073     |    45.931     |   0.233    |
|    5.074     |     16.711    |   0.084    |


Table 2: Power Receiver Experiment Results <br/>

| Voltage | Current | Power |
|---------|---------|-------|
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |
|         |         |       |

## Conclusions
#### Interpretation of Data
<!-- explain what the results of the experiments mean and what conclusions you draw -->

#### Final Thoughts
<!-- Were constraints met? -->
