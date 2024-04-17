## Experimentation and Testing

In this document is contained the experimentation and testing of the robot, and an analysis of those results. 

### Start Sensor

The start sensor was tested 30 times, and the target success rate was 80% in under 3 seconds. The results of the tests along with the response time is recorded below. The start sensor needed to be within a certain range of the green LED as described in the detail design papers. This was tested in parallel with the start sensor starting the robot. The placement of the sensor was a lot less specific in testing then stated in the datasheets and detail design. This led to a higher success rate of the sensor starting the robot because the placement was not as important. This became especially clear after the removal of the shroud, leading to a 100% sucees rate in the sensor after the removal.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/347640dd-8cce-404f-bac4-75ec6ecef214)

As shown above, the start sensor worked 100% of the time, exceeding the required 80%. This also shows that the response time for the sensor was under 1 second, and was probably faster than the recorded time as the time was reliant on human reaction time. The start sensor percentage of successful starts was initially lower, then the shroud was removed from around the sensor. Once the shroud was removed, the distance from the light to the sensor was greatluy increased, and those distances can be seen below.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/ab4c1910-a1e7-4267-8429-1f1b4b3e1185)

This shows the sensor did not need to be right next to the light in order to function once ambient light was allowed in without the shroud.

### Navigation

- Constraint to Test: The navigation sensors must be able to detect the yellow line at least 80% of the time.
- Experimental Process: The robot was run 30 times and the number of times the sensors detected the first corner was recorded. This resulted in the successes shown below, in whcih it successfully detected the line 86% of the time.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/b797fe52-b71d-49ee-bb75-8bd39f5c46ce)

- Constraint to Test: The sensors must be within a half inch of the line in order to detect the line.
- Experimental Process: The sensor was measured in relation to its hieght above the line before each run, and the numbers were recorded. As shown, it was under 0.5 inches each time, however it failed to detect the line when it was above 0.25 inches. It also failed one other time, but the cause of this failure was undetermined.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/67c7f410-a841-43b9-a30d-453d43f206fe)

### Power

The power subsystem powered the robot 100% of the time, however there was one major issue with the power system that was discovered during the competition. This was that there was noise being fedback from the motors that would cause the power to the main controller to brownout and reset the code. This led to the motors being stuck in whatever drive mode they were in before the brown out. This was solved by connecting the microcontroller to a 9 Volt battery instead of the main power system, preventing noise to be fed from the motors. After this modification, the micro controller has not browned out, as shown in the table below.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/fd06b150-61d0-4539-b977-8105c2635710)

As shown, of 30 trials, the system did not brown out 30 times. This is exceeded the acceptible rate of 95% of the time, as shown by being over the orange line.

### Motors

The motors worked 100% of the time, and correctly executed the code given to them. Sometimes this code was wrong, but that was a fault in the micro controller, not the motors. Below shows the table of the completion times of the robot through the course the times where it successfully navigated the course.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/fda5c17e-8859-43e8-a6a4-06c611938467)

This shows that the motors were more than sufficient to power the robot around the track in under a minute and 30 seconds.

### Main Control

The main controller code needed to be able to complete the course at least 85% of the time. The table below shows percentage of course traversed each trial.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/a8e9cd95-c6c8-4694-9917-4931f2e0640b)

This shows that the code allowed the course to be completed 87% of the time, which is within the required parameters. The main controller was also responsible for the timers for the second turn and the gap crossing triggers. This meant that the main control was also responsible for the deployment of the team spirit and button push subsystems. The trials for these subsystems were only accounted for when the robot reached those places, as the main control sometimes failed to complete the course, as shown above.

### Button Push

The button pusher deployed successfully every time the robot crossed the gap or reached the point in the code that deployed it, however it did not push the button every time it deployed. It needed to push the button 85% of the time. The table below shows the success rate of the button pusher.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/45f9c7a4-0510-457c-ad99-9dd19ae779ad)


This shows a 100% success rate of the button pusher, which is within the desired parameters. This is shown by of the 26 times the robot reached the button, the button was pushed all 26 times.

### Team Spirit

The Team Spirit subsystem needed to blink at least 80% of the time. The table below shows the successful blinkage of the system.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/5f764108-d8af-4c67-8b90-d69f989f2182)

This shows that the team spirit system worked 82% of the time. However a major design flaw in the team spirit system was that it was too heavy fo rthe robot and caused the robot to tip over, so a significantnly smaller version was implemented for the competition. The system, when it blinked, would blink at 5Hz, which is whithin the range of visibility to the human eye.
