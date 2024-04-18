## Experimentation and Testing

 This document contains the experimentation and testing of the robot and an analysis of those results. 

### Start Sensor

- Constraint to Test: The start sensor shall detect the start light in under 3 seconds at least 80% of the time.
- Experimental Process: The robot was placed in the start pad of the board within range of the start light, and the start light was lit. The amount of time until the robot begins movement was recorded. However, if the robot did not start within 3 seconds, it was recorded as a failure. This was repeated 30 times.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/347640dd-8cce-404f-bac4-75ec6ecef214)

- Analysis of Results:
<br> As shown above, in the 30 trials the start sensor worked 100% of the time, exceeding the required 80%. This also shows that the response time for the sensor was under 1 second, and was probably faster than the recorded time as the stopwatch was reliant on human reaction time. The start sensor percentage of successful tests was initially lower. Once modifications to the code were made during SECON and the shroud was removed from around the sensor, the sensor became much more responsive to the start light and was tested from scratch with the improved code, which resulted in a 100% success rate.

***

- Constraint to Test: The start sensor shall be placed close to 1" from the start light to guarantee functionality.
- Experimental Process: The robot was placed in the start pad of the board with the start sensor either at 1" or more than 1" from the start light and then the start light was lit. If the start sensor activated properly, then the distance was recorded. This was repeated 30 times with varying distances.
  
![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/ab4c1910-a1e7-4267-8429-1f1b4b3e1185)

- Analysis of Results:
<br> As shown above, in the 30 trials the start sensor activated all 30 times whether it was at exactly 1" or as far as 1.4" from the light. This indicates that although the estimation for the maximum functional distance was 1" the actual maximum functional distance was closer to 1.4". This allows some human error in the placement of the robot on the board, while still maintaining the functionality of the start sensor. Again this improved sensitivity of the sensor resulted from modifications to the sensor's code and removal of the shroud while at the SECON competition.

***
### Navigation

- Constraint to Test: The navigation sensors shall be able to detect the yellow line at least 80% of the time.
- Experimental Process: The robot was started and the amount of times that the first corner in the yellow line was detected properly was recorded. If the robot relied on the safety timer to make the first turn, then it was marked as a failure. This test was repeated 30 times.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/b797fe52-b71d-49ee-bb75-8bd39f5c46ce)

- Analysis of Results:
<br> The robot was able to detect the corner 86% of the time, or 26 times out of 30. The orange line represents the constraint of 80%, this shows that the navigation sensors work above the required functionality. However, if the sensors failed for any reason, the corner was made based on the safety timer, which went off after a certain amount of time guaranteeing that the robot had passed the corner, but did not detect it. This allowed a greater chance that the board could be completed even if the corner was missed by the navigation sensors. 

***
- Constraint to Test: The sensors shall be within 0.5" vertically of the line to help ensure detection of the line.
- Experimental Process: The robot was set in the start area of the board and the height of the sensor from the board was measured before activation, and the numbers were recorded. This experiment was run concurrently with the previous experiment to provide further context to success rates.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/67c7f410-a841-43b9-a30d-453d43f206fe)

- Analysis of Results:
<br> Although the sensor was within 0.5" each run, it failed to detect the line when it was above 0.25". This indicates that the sensor was less responsive than estimated and that a lower placement (within 0.25") would help ensure better detection. There was an additional failure of detection even when within 0.25", however, the cause of this specific failure was undeterminable and attributed to an expected failure rate as actuality does not align with ideal performance sometimes.

***
### Power

- Constraint to Test: The power system shall power the microcontroller consistently throughout the run of the board at least 95% of the time.
- Experimental Process: The robot was powered, set in the start area, and activated. The behavior of the microcontroller was observed as it moved about the board and marked if a brownout occurred.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/fd06b150-61d0-4539-b977-8105c2635710)

- Analysis of Results:
<br> As shown, in 30 trials, the power subsystem powered the microcontroller consistently 100% of the time. This test was developed in response to an issue discovered at the SECON competition where the movement of the robot going down the hills temporarily turned the motors into generators which then fed back power to the microcontroller, disrupted the voltage difference, and resulted in a brownout of the microcontroller which reset its program and inhibited the robot from behaving properly by locking the motors in the drive mode before power disruption. The solution to this problem was to stabilize the microcontroller's voltage difference by powering it through a 9V battery instead of the main power system that the motors were attached to, thus preventing the feedback of power. This significantly improved the functionality of the power system and the robot as a whole. Before the change, the microcontroller would brownout most runs once the hills were descended. Once the solution was implemented we achieved consistent power 100% of the time, which fulfills our constraint of 95% as shown by the orange line.

***
### Motors

- Constraint to Test: The motors shall move the tracks in a way that allows the robot to complete the course in under 90 seconds at least 90% of the time.
- Experimental Process: The robot was powered, set in the start area, and activated. The robot was timed as it made its way around the course, the time was stopped when it passed the button at the end of the course. This was repeated 30 times.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/fda5c17e-8859-43e8-a6a4-06c611938467)

- Analysis of Results:
<br> As shown, the robot was able to complete the course in under 45 seconds 100% of the time. This is significantly lower than our goal of 90 seconds. This speed would grant us the maximum amount of points for time completion while also allowing time for some minor errors or other tasks (button push/team spirit) to occur and delay the robot slightly while remaining under time. This demonstrates that the motors fulfill the constraint that they shall move the tracks in a way to allow the robot to complete the course in under 90 seconds at least 90% of the time.

***
### Main Control

- Constraint to Test: The main controller shall direct the robot so that it can complete the course at least 85% of the time.
- Experimental Process: The robot was powered, set in the start area, and activated. The robot traversed the course and if it did not reach the end then the percentage it reached was measured as a percentage. If it reached the end, it was marked as 100%. This was repeated 30 times.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/a8e9cd95-c6c8-4694-9917-4931f2e0640b)

- Analysis of Results:
<br> This shows that the main controller directed the robot to complete the course successfully 87% of the time. Which is above the required 85%. The times that it did not complete the course happened most frequently at ~40% and ~85%. The ~40% mark indicates that the robot would have trouble with the descent of the first hill and fail there. This was most likely due to the navigation sensor lifting off the board more than 0.25" before the descent of the hill, thus blinding the robot temporarily but long enough for the robot to get far enough off the line that it could not correct. The ~85% mark indicates that the robot failed at the gap. This was not due to not being able to cross the gap, but rather to not being oriented properly before crossing. The navigation sensor again would lift more than 0.25" off the board when ascending the ramp up to the gap and the robot would be off the line and not able to correct before crossing the gap and so it would run into the wall instead of crossing the gap properly. However, again 87% of the time the robot would be able to overcome these and any other errors and complete the course successfully.

***
### Button Push

- Constraint to Test: The button pusher must push the button 85% of the time.
- Experimental Process: The robot was powered, set in the start area, and activated. If it reached the zone after the gap, the button pusher was supposed to deploy and push the button. Once the robot reachd this stage of the course it was counted as a trial of the pusher.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/45f9c7a4-0510-457c-ad99-9dd19ae779ad)

-Analysis of Results:
<br> This shows that of the 26 times the robot reached the stage of the course to push the button, it did so 100% of the time. This proves that the servo was being triggered and the arm was positioned correctly as long as the robo made it to the end of the course iot could push the button.

***
### Team Spirit

- Constraint to Test: The team spirit subsystem will blink at a visible rate once the robot has crossed the gap.
- Experimental Process: The robot was powered, set in the start area, and activated. If it reached the zone after the gap, the team spirit was supposed to deploy and blink. Once the robot reachd this stage of the course it was counted as a trial of the team spirit.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/5f764108-d8af-4c67-8b90-d69f989f2182)

- Analysis of Results:
<br> This shows that of the 26 times the robot reached the deploymenmt zone, the team spirit blinked 100% of the time. The main issue with the team spirit system was its weight, as when the main system was connected to the robot it would tip over on the inclines, so a smaller version was devised for the competition.
