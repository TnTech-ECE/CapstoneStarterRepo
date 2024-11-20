# Power Systems - Experimental Analysis
## Experiment Description

For the power systems, the most important experiment is to measure the voltages and currents with the actual loads 
to find the power instead of the simulation used in the minimal function prototype stage. For both experiments, the voltage and current
was measured. The purpose of the two tests was to calculate the power with the actual loads connected under typical operating modes 
to ensure that the power systems will supply adequate power for the Camera and Receiver subsystems to acheive their full functionality
without limitations due to insufficient power. 


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
- The system shall be able to supply 15 W to the Raspberry Pi for the system to acheive full functionality(Maybe delete this one).
- The system shall be able to supply 1.25 W to the ESP32 and 0.7095 W to the ESP8266 for the receiever system to acheive full functionality.
 
#### Expected Result(s):
- The team expects the actual total wattage to be lower than 19.5 W for the servo motors and camera, 15W for the Raspberry Pi, and 1.96 W for the ESP32 and ESP8266 proposed in detail design. This is due to overdesigning the Power systems for the max ratings to ensure that the systems would not be out of specification. This was done, because the team was not sure of what the actual load would be during the design process.

## Experimental Procedure
<!-- Description of what you did ideally in steps -->
- Number of trials:
  
1. Step 1
2. Step 2

## Experimental Data
<!-- data tables or graph of the results (whichever is appropriate) -->

## Conclusions
#### Interpretation of Data
<!-- explain what the results of the experiments mean and what conclusions you draw -->

#### Final Thoughts
<!-- Were constraints met? -->
