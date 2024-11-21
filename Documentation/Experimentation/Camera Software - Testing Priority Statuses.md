# Testing Priority Statuses
## Experiment Description
### Summary
<!-- Short summary of the experiment written after completing it -->

#### Subsystem(s) Involved:
Camera Software Subsystem

#### Constraints Tested:
- If the system receives data for the control station location, the system shall prioritize capturing a picture of the control station unless the corresponding UAS is in a high alert area as defined by the Tech Police. In that case, the system will prioritize capturing a picture of the UAS.
- Location prediction shall be performed when the UAS or control station is moving in a straight line, but is not required if the UAS or control station is moving in other trajectory.
 
#### Expected Result(s):
- When the camera system's rasberry pi receives data from the database with the priority area boolean high, the camera should face the direction of the UAS. If the priority area boolean is low, the camera should face the direction of the control station.
- When the database inputs indicate straight line motion, the code should output predicted location coordinates.

## Experimental Procedure
<!-- Description of what you did ideally in steps -->
- Number of trials: 2 trials each

High Priority Status Test
1. Set up the testing environment (consists of a sheet of paper underneath the camera to indicate sudo locations of the UAS and the control station)
2. Set up the database to output a constant UAS location and a constant control station location.
3. Set the priority status low.
4. Record the location of the camera.
5. Set the priority status high.
6. Record the location of the camera.


## Experimental Data
<!-- data tables or graph of the results (whichever is appropriate) -->

## Conclusions
#### Interpretation of Data
<!-- explain what the results of the experiments mean and what conclusions you draw -->

#### Final Thoughts
<!-- Were constraints met? -->
