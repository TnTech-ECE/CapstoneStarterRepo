## Experimentation and Testing

In this document is contained the experimentation and testing of the robot, and an analysis of those results. 

### Start Sensor

The start sensor was tested 30 times, and the target success rate was 80% in under 3 seconds. The results of the tests along with the response time is recorded below. The start sensor needed to be within a certain range of the green LED as described in the detail design papers. This was tested in parallel with the start sensor starting the robot. The placement of the sensor was a lot less specific in testing then stated in the datasheets and detail design. This led to a higher success rate of the sensor starting the robot because the placement was not as important. This became especially clear after the removal of the shroud, leading to a 100% sucees rate in the sensor after the removal.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/347640dd-8cce-404f-bac4-75ec6ecef214)

As shown above, the start sensor worked 100% of the time, exceeding the required 80%. This also shows that the response time for the sensor was under 1 second, and was probably faster than the recorded time as the time was reliant on human reaction time. The start sensor percentage of successful starts was initially lower, then the shroud was removed from around the sensor.

### Navigation

The navigation subsystem was tested by what percentage of the time it was able to detect the first corner of the track when it successfully reached the first corner. This was decided because if the boxes knocked the robot off course the navigation system was unable to do anything to correct the robot if it was not over the line. The orange line on the graph shows the acceptable limit of success.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/b797fe52-b71d-49ee-bb75-8bd39f5c46ce)

The goal was to have the navigation subsystem detect the corner 80% of the time, and it successfully detected 86% of the time. This passes the benchmark required for successful deployment of the navigation sensors. This can be seen by the blue bar being over the orange line.

### Power

The power subsystem powered the robot 100% of the time, however there was one major issue with the power system that was discovered during the competition. This was that there was noise being fedback from the motors that would cause the power to the main controller to brownout and reset the code. This led to the motors being stuck in whatever drive mode they were in before the brown out. This was solved by connecting the microcontroller to a 9 Volt battery instead of the main power system, preventing noise to be fed from the motors. After this modification, the micro controller has not browned out, as shown in the table below.

![image](https://github.com/cebttu/CapstoneTeam1/assets/143427017/fd06b150-61d0-4539-b977-8105c2635710)

As shown, of 30 trials, the system did not brown out 30 times. This is exceeded the acceptible rate of 95% of the time, as shown by being over the orange line.

### Motors

The motors worked 100% of the time, and correctly executed the code given to them. Sometimes this code was wrong, but that was a fault in the micro controller, not the motors.

### Main Control

The main controller code needed to be able to complete the course at least 85% of the time. The table below shows the completion and percentage of course traversed if not completed.

| Trial No. | Completed | Percentage |
|-----------|----------|----------|
| 1 | Yes | 100 |
| 2 | Yes | 100 |
| 3 | No | 40 |
| 4 | Yes | 100 |
| 5 | Yes | 100 |
| 6 | Yes | 100 |
| 7 | Yes | 100 |
| 8 | Yes | 100 |
| 9 | Yes | 100 |
| 10 | Yes | 100 |
| 11 | No | 85 |
| 12 | Yes | 100 |
| 13 | Yes | 100 |
| 14 | Yes | 100 |
| 15 | Yes | 100 |
| 16 | Yes | 100 |
| 17 | Yes | 100 |
| 18 | Yes | 100 |
| 19 | No | 87 |
| 20 | Yes | 100 |
| 21 | Yes | 100 |
| 22 | Yes | 100 |
| 23 | Yes | 100 |
| 24 | Yes | 100 |
| 25 | No | 42 |
| 26 | Yes | 100 |
| 27 | Yes | 100 |
| 28 | Yes | 100 |
| 29 | Yes | 100 |
| 30 | Yes | 100 |

This shows that the code allowed the course to be completed 87% of the time, which is within the required parameters.

### Button Push

The button pusher deployed successfully every time the robot crossed the gap or reached the point in the code that deployed it, however it did not push the button every time it deployed. It needed to push the button 85% of the time. The table below shows the success rate of the button pusher.

| Trial | Pushed |
|-------|-----------|
| 1 | Yes |
| 2 | Yes |
| 3 | Yes |
| 4 | Yes |
| 5 | Yes |
| 6 | Yes |
| 7 | Yes |
| 8 | Yes |
| 9 | Yes |
| 10 | Yes |
| 11 | Yes |
| 12 | Yes |
| 13 | Yes |
| 14 | No |
| 15 | Yes |
| 16 | No |
| 17 | Yes |
| 18 | Yes |
| 19 | Yes |
| 20 | Yes |
| 21 | Yes |
| 22 | Yes |
| 23 | Yes |
| 24 | Yes |
| 25 | Yes |
| 26 | Yes |
| 27 | No |
| 28 | Yes |
| 29 | No |
| 30 | Yes |

This shows an 87% success rate of the button pusher, which is within the desired parameters.

### Team Spirit

The Team Spirit subsystem needed to blink at least 80% of the time. The table below shows the successful blinkage of the system.

| Trial | Blink |
|-------|-----------|
| 1 | Yes |
| 2 | Yes |
| 3 | Yes |
| 4 | No |
| 5 | Yes |
| 6 | Yes |
| 7 | Yes |
| 8 | Yes |
| 9 | Yes |
| 10 | No |
| 11 | Yes |
| 12 | Yes |
| 13 | Yes |
| 14 | Yes |
| 15 | Yes |
| 16 | Yes |
| 17 | Yes |
| 18 | No |
| 19 | Yes |
| 20 | Yes |
| 21 | Yes |
| 22 | Yes |
| 23 | Yes |
| 24 | Yes |
| 25 | No |
| 26 | Yes |
| 27 | Yes |
| 28 | No |
| 29 | Yes |
| 30 | Yes |

This shows that the team spirit system worked 82% of the time. However a major design flaw in the team spirit system was that it was too heavy fo rthe robot and caused the robot to tip over, so a significantnly smaller version was implemented for the competition.
