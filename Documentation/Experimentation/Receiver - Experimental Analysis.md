# Testing Receiver Range
## Experiment Description
### Summary
<!-- Short summary of the experiment written after completing it -->
The most important aspects of the receiver are being able to receive RID drone signals and to receive it from the worst case scenario distance with line of sight. The RID signal is emitted in the 5.8 GHz Wi-Fi and 2.4 GHz Wi-fi and Bluetooth bands. The worst case scenario is based on the RID signal being emitted as a Bluetooth signal at the minimum required strength of 5 dBm. Line of sight means that there are no obstructions in the way of the the receiver and the drone. If the receiver can pick up a Bluetooth signal from this distance then it should be able to receive a 2.4 GHz Wi-Fi signal from further away because it's required to emit signals at 15 dBm minimum. The 5.8 GHz Wi-Fi band is an optional output and not required. 
#### Subsystem(s) Involved:
Receiver Subsystem

#### Constraints Tested:
- Shall only need to receive packets within the 2.4 GHz Wi-Fi and Bluetooth frequency band
- Shall only interact with RID signal and ignore other signals
- Each receiver shall have a reception range at a minimum of 150 m
 
#### Expected Result(s):
- Since the receiver purchased is unable to receive signals at the 5.8 GHz frequency band the expected result is for the receiver to be unable to pick up RID signals outside of the 2.4 GHz range.
- When placed into an area with high internet traffic the receiver will ignore signals that are not related to the RID drone signal and receive RID drone signals.
- The receiver should be able to pick up a signal from 150 m in the worst case. However the receiver may be able to pick up signals from further away if interference is low. 

## Experimental Procedure
<!-- Description of what you did ideally in steps -->
- Number of trials: 5
  
1. Start at 150 m north of the receiver and move it closer or further away depending on if the receiver successfully receives the data or not. 
2. Start at 150 m northeast of the receiver and move it closer or further away depending on if the receiver successfully receives the data or not.
3. Start at 150 m east of the receiver and move it closer or further away depending on if the receiver successfully receives the data or not.
4. Start at 150 m southeast of the receiver and move it closer or further away depending on if the receiver successfully receives the data or not.
5. Start at 150 m south of the receiver and move it closer or further away depending on if the receiver successfully receives the data or not.
6. Start at 150 m southwest of the receiver and move it closer or further away depending on if the receiver successfully receives the data or not.
7. Start at 150 m west of the receiver and move it closer or further away depending on if the receiver successfully receives the data or not.
8. Start at 150 m northwest of the receiver and move it closer or further away depending on if the receiver successfully receives the data or not.

## Experimental Data
<!-- data tables or graph of the results (whichever is appropriate) -->
A scatter plot would be used to see how far away the signal was received during each trial. However currently the receiver does not receive RID data. 
## Conclusions
#### Interpretation of Data
<!-- explain what the results of the experiments mean and what conclusions you draw -->
If the signal is received from further away than the minimum we can come to the conclusion that the worst case scenario is not occuring. This means that there is little interference with the signal. This interference can range from weather or other outside circumstances adding noise to the signal. The drone could also be outputting the signal above the minimum required power output also being above the worst case scenario. If the signal is received from under the minimum then there is most likely a disturbance interfering with the signal outside of our control. 

#### Final Thoughts
<!-- Were constraints met? -->
- The receiver is able to receive 2.4 GHz Wi-Fi and Bluetooth and is unable to receive 5.8 GHz signals.
- The receiver is currently unable to receive RID drone signals so this constraint has not been met.
- Since the receiver is unable to receive RID data it can't receive a signal from the minimum distance and this constraint has not been met. 
