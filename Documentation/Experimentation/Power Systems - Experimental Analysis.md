# Power Systems - Experimental Analysis
## Experiment Description

For the power systems, the most important experiment is to measure the voltages and currents with the actual loads 
to find the power instead of the simulation used in the minimal function prototype stage. For both experiments, the voltage and current
was measured. The purpose of the two tests was to calculate the power with the actual loads connected under typical operating modes 
to ensure that the power systems will supply adequate power for the Camera and Receiver subsystems to acheive their full functionality
without limitations due to insufficient power. The maximum power was already tested in the minimal function prototype testing, so the team did not deem it necessary to modify the system trying to obtain those maximum load values.


For the Power Camera system, a voltmeter and ammeter were connected while the Camera Hardware system which interfaced with the Camera Software,
Website, and Database systems to make various movements with both motors. We measured 20 individual turns of the motor to gather a
sufficient amount of data. 


For the Power Receiver system, the team used a USB test meter to measure the voltage and current supplied from the Waveshare module
while the receiver system ran the program used to transmit data to the database.


### Summary
<!-- Short summary of the experiment written after completing it -->
The team tested both the Power Camera and Power Receiver systems to find the voltage and current during typical functionality to ensure that the Camera and Receiver systems were able to acheieve full functionality without any limitations due to voltage drop. With 20 data points for both experiments, no voltage drop or functionality limtations were observed, so the team would consider both of the constraints met. 

#### Subsystems Involved:
- Power Camera System

- Power Receiver System

#### Constraints Tested:
- The system shall be able to supply 9 W to each servo motor, and 1.5 W to the camera for the system to acheive full functionality.
- The system shall be able to supply 1.25 W to the ESP32 and 0.7095 W to the ESP8266 for the receiever system to acheive full functionality.
 
#### Expected Result(s):
- The team expects the actual total wattage to be lower than 19.5 W for the servo motors and camera and lower than the 1.96 W for the ESP32 receiver and ESP8266 Wi-Fi module that were proposed in detail design. This is due to designing the Power systems for the max ratings in the worst case scenario to ensure that the systems would not be out of specification. This was done, because the team was not sure of what the actual load would be during the design process, and the cost difference of reducing the system's power output to the exact specification would be minimal while increasing the risk of functionality limitations in edge cases. 

## Experimental Procedure
<!-- Description of what you did ideally in steps -->
Power Camera Experiment

- Number of trials: 20

1. Connect the Power Camera system to the Camera Hardware system.
2. Connect two Rigol DM3058E Digital Multimeters to the system with one multimeter acting as a voltmeter and the other acting as a ammeter to measure the voltage and current.
3. Run a test that moves the motors at various angles and takes pictures with the camera.
4. Record the voltage and current readings for each movement and picture taken.

Power Receiver Experiment

- Number of trials: 20

1. Connect the Power Receiver system to the USB meter.
2. Connect the USB meter to the Receiver system.
3. Run the program for the ESP32 receiver and ESP8266 Wi-Fi module to transmit data to the database.
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

| Voltage (V) | Current (mA)| Power (W)|
|---------|---------|-------|
|    5.073     |    66.4     |    0.337   |
|     5.071    |    38.1     |  0.193     |
|     5.072    |    49.5     |    0.251   |
|    5.072     |    85.1     |   0.432    |
|    5.074     |     81.7    |    0.415   |
|     5.072    |    56.2     |    0.285   |
|    5.071     |    60.3     |   0.306    |
|    5.073     |   41.0      |   0.208    |
|    5.071     |    45.0     |   0.228    |
|     5.070    |    63.1     |    0.320   |
|     5.071    |    50.3     |   0.255    |
|     5.071    |    40.7     |   0.206    |
|    5.073     |   64.4      |    0.327   |
|    5.070     |    57.4     |   0.291    |
|    5.072     |    82.5     |   0.418    |
|    5.072     |     61.7    |    0.313   |
|    5.072     |    56.8     |   0.288    |
|    5.073     |    90.6     |   0.460    |
|     5.073    |    50.1     |   0.254    |
|     5.072    |   60.3      |    0.306   |

## Conclusions
#### Interpretation of Data
<!-- explain what the results of the experiments mean and what conclusions you draw -->
For both experiments, the wattages were much lower than what was specified in the constraint for detailed design. This was expected due to the constraint wattage numbers being derived from maximum load values, which is realistically not going to be achieved during standard operation of the systems. 

#### Final Thoughts
<!-- Were constraints met? -->
Yes, both constraints were met. The constraints were primarly about achieiving full functionality of the Camera and Receiver systems instead of the wattage numbers that were calculated using maximum load values. During both tests, the systems achieved full functionality. Also, the minimum function prototype testing used a simulated load to ensure that the power systems could maintain the rated voltages at the maximum load values used during detailed design. Since both aspects of the constraints were confirmed through testing, the team would consider both of these constraints met.
