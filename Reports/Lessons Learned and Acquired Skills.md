# Lessons Learned

This document should have a section for each team member. Each engineer should respond to these:

- Reflect on the project, both technical and organizational. What went well? What didn’t go well? 
- What unanticipated problems occurred? 
- What would you do differently if you were to do it over again? 
- What “best practices” have you identified? 
- What words of wisdom would you pass on to future students?
- What new knowledge or skills did you acquire throughout capstone.

Create a subsection addressing each of the above questions in your section of the document. 

## Conor Orr

1. The project went well technically and orginizationally over all, but there were a few issues. Orginizationally the electrical and mechanical sides of the project did not start effectively communicating until the second semster of capstone, and this put us at a disadvantage with design because we were lacking their input during the fall semester. Technically the project had to change a lot due to rule changes made by the competition at the last minute, and when at the competition the practice boards were all different.
   
2. There were a few unanticipated problems. The first being that our navigation sensor was scraping on the ground during the inclines due to the hieght requirements for it to work, this was solved by changing how the wheelie bars dropped that it was attached to. The second problem was that when we got to the competition, several rules changed, and we had not tested the robot crawling over the boxes, which really messed up or systems at first. Thirdly the team spirit system was too heavy for the robot and would cause it to tip over when installed. Lastly and most unanticipated was that the motors turned into generators on the downhill portions of the track, which elevated the ground plane and caused our microcontroller to brown out and reset the code.
   
3. If I were to do this over again, I would start communicating with the mechanicals from day 1, and have made all of our meetings mandatory for everyone instead of having one mechanical at the electrical meetings. I also would have checked the rules more regularly to be able to see the changes they made because the competition would update the rules and not announce it to anyone. I would have designed the power system to be more robust against the ground plane shifting instead of jury rigging a 9 volt battery to the microcontroller at the competition. Lastly I would have started all th edetail designs a week earlier to get them all signed off to have more time to build the robot.
   
4. It is best to involve the whole team in major discussions. It is also best to apply everyone to areas of strengths, and try and overlap strength sof one person with the weaknesses of others.
   
5. I have identified several things as best practices. The first being to ask everyone on the team for input, not just the electrical or the mechanicals. Secondly, if you are not sure how to do something, ask someone, because this is not a solo project. Ask the mechanicals, as they have great ideas. Design a point of failure, because if you do not, the universe will assign one for you, and it will not be where you like.
   
6. I acquired several new skills during capstone. I learned a lot about arduino coding in C. I also learned about torque calculations, and how to do motor sims in simulink.


## Adrin Jackson

1.Some of the organizational issues from the project was communication and assignment to detail design. There was change in who was assigned the motor detailed design in the second semester. A benefit to this though was it allowed for better time allocation for the team so people can put their time where it is needed in other subsystems. If we were able to communicate with the mechanical engineers better in the first semester then we wouldn't have had to rush for time in the second semester. Once we did start communicating better with the mechanical engineers the design, assembly, and the testing of the robot was done quite smoothly. 

2.When testing the robot, there were some issues where a wire came loose on the motor shield and shorted out the board. The board did not have any sort of protection to prevent the board from frying at the time. Since the motor shield was fried, we could not do any more testing until we got a new motor driver shield which delayed us about 3 days. For the push button subsystem, the arm would not deploy at the correct time or would deploy as soon as the Arduino had power. The issue was because servo motor gear was rotated before reattaching the arm to the servo gear, so this caused the homing position of the servos arm to be different rather than what the homing degree was set to in the program. This was fixed by taking a potentiometer to rotate the servo manually, and by returning and displaying the value of the position in degrees in the serial monitor that the servos arm was rotated to. We manually set the position to 0 degrees then changed the homing position of the servo in the program, and that fixed the early deployment issue. 
3.I would've included the mechanical engineers more on selecting the motors subsystem earlier because they were more efficient at finding the max load conditions based on the weight of the robot and the incline of the course. I would have also tried to learn some 3d modeling software before starting capstone 1 instead of spending hours researching and practicing how to do so while in capstone. I also would have consulted professors much sooner for help on understanding some theories I did not know much about for some subsystems.
4.If there is a subsystem that the team or an individual does not know much about, then go to professors’ office hours so that they can inform you more on how it works in theory. If you need to brush up on a skill that pertains to the project such as programming, then Udemy has courses that can cover these topics better than some YouTube tutorials. For power related subsystems there needs to be fuses implemented for preventing low operating current components from frying. The fuses also prevent reverse polarity protection when rewiring components for testing or changing out hardware. 
5.Start as soon as possible when getting assigned a project and recognize your team members skills and where their time can be best allocated. Communication is key, and to reduce any discrepancies between electrical and mechanical problems there needs to be at least one to two in person meetings a week to resolve any issues with everyone on both teams present. Getting familiar with MATLAB Simulink is a great tool for modeling complex electro-mechanical systems and practicing with this tool can greatly help with the detailed designs. Finally, I would suggest getting familiar some 3d modeling software because there was more modeling needed for the robot than I expected. 
6.Some of the skills I obtained from capstone was using Matlab Simulink, Blender, KiCad, and Arduino Programming. 
