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

1. Some of the organizational issues from the project was communication and assignment to detail design. There was change in who was assigned the motor detailed design in the second semester. A benefit to this though was it allowed for better time allocation for the team so people can put their time where it is needed in other subsystems. If we were able to communicate with the mechanical engineers better in the first semester then we wouldn't have had to rush for time in the second semester. Once we did start communicating better with the mechanical engineers the design, assembly, and the testing of the robot was done quite smoothly.
 
2. When testing the robot, there were some issues where a wire came loose on the motor shield and shorted out the board. The board did not have any sort of protection to prevent the board from frying at the time. Since the motor shield was fried, we could not do any more testing until we got a new motor driver shield which delayed us about 3 days. For the push button subsystem, the arm would not deploy at the correct time or would deploy as soon as the Arduino had power. The issue was because servo motor gear was rotated before reattaching the arm to the servo gear, so this caused the homing position of the servos arm to be different rather than what the homing degree was set to in the program. This was fixed by taking a potentiometer to rotate the servo manually, and by returning and displaying the value of the position in degrees in the serial monitor that the servos arm was rotated to. We manually set the position to 0 degrees then changed the homing position of the servo in the program, and that fixed the early deployment issue. 

3. I would've included the mechanical engineers more on selecting the motors subsystem earlier because they were more efficient at finding the max load conditions based on the weight of the robot and the incline of the course. I would have also tried to learn some 3d modeling software before starting capstone 1 instead of spending hours researching and practicing how to do so while in capstone. I also would have consulted professors much sooner for help on understanding some theories I did not know much about for some subsystems.
   
4. If there is a subsystem that the team or an individual does not know much about, then go to professors’ office hours so that they can inform you more on how it works in theory. If you need to brush up on a skill that pertains to the project such as programming, then Udemy has courses that can cover these topics better than some YouTube tutorials. For power related subsystems there needs to be fuses implemented for preventing low operating current components from frying. The fuses also prevent reverse polarity protection when rewiring components for testing or changing out hardware.
   
5. Start as soon as possible when getting assigned a project and recognize your team members skills and where their time can be best allocated. Communication is key, and to reduce any discrepancies between electrical and mechanical problems there needs to be at least one to two in person meetings a week to resolve any issues with everyone on both teams present. Getting familiar with MATLAB Simulink is a great tool for modeling complex electro-mechanical systems and practicing with this tool can greatly help with the detailed designs. Finally, I would suggest getting familiar some 3d modeling software because there was more modeling needed for the robot than I expected.
   
6. Some of the skills I obtained from capstone was using Matlab Simulink, Blender, KiCad, and Arduino Programming. 


## Caz Bilbrey

1. Overall, the project went smoothly, but there were a few challenges along the way. Initially, there was a lack of effective communication between the electrical and mechanical teams until the second semester of the capstone, which affected the design process completely and made it easier for the EE team. Additionally, last-minute rule changes by the competition required significant adjustments to the project, and the practice boards used at the competition were not to the aspects that we were given. I also hope for a better outcome for our robot int the competition; however, there were very few rolls of the dice that would have ended the round early for us, and the rolls we got were just simply unlucky.

2. Several unexpected issues happened during the project. Firstly, the navigation sensor scraped on inclines due to height requirements, which was resolved by adjusting the wheelie bars. Secondly, rule changes at the competition caught the team off guard and honestly put a damper on the team's spirit. Thirdly, the team spirit system was too heavy for the robot, causing balance issues. Fourthly, the inaccurate boards played a large effect on our runs during the competition. Lastly, the motors acted as generators on downhill sections, leading to power supply problems for the microcontroller.

3. Reflecting on the project, improvements could have been made. Better communication between teams from the start which would allow less stress on our end, more regular rule checks, emailing the IEEE people to get accurate rules and understandings of rules, a better start on the presentation (earlier start), and a more robust power system design would have mitigated some challenges. Starting detailed designs earlier would have provided more time for adjustments.

4. Key takeaways include involving the entire team in discussions, leveraging everyone's strengths, and being proactive in seeking help when needed. Learning experiences from the project included gaining proficiency in Blender, understanding of RGB sensors, learning how everyone thinks differently, and utilizing Canva and Excel.

## Liam Counasse

1. The project was successful organizationally and technically with minor issues. Organizationally the project would have been more successful with more inclusion of the mechanical team. This is mainly due to the differing format of the capstone design programs of the mechanical and electrical engineering courses. Any technical issues that occurred were minor and resolved with intuitive programming solutions or further researched into the part in question.

2. The most unanticipated issue which occurred was not having the chassis developed first. Other unexpected issues would be low mechanical lifespans of Arduino relays and the functionality of the motors for the push button system.

3. If the opportunity arose to do it all over again the development of the chassis would be first, the development of the tracks would be second, the motors system would be more collaborative with the mechanical engineering team and prioritized third, the main controller would come last, and the power system would come second to last. Several systems are omitted from this change in order, however, the order of the completion of these systems does not majorly impact the overall success of the project.

4. The ”best practices” which may be identified from the project would be communicating with teammates, asking advice from the instructor and classmates, and researching the subject of the project from technical papers and textbooks.

5. Contact your instructors for assistance but choose instructors which specialize or teach courses over the subject. Review past projects if you find yourself at a loss of how to perform a task. Speak with graduate students as they have completed the course recently. Maintain communication with your team and keep a log of your work.

6. I have acquired skills such as: soldering, KICAD, Blender, importing and creating models in LTspice. I have acquired knowledge of creating analog and digital controls systems and developing PCB.

## Callie Battenfield

1. I think the project went well after a somewhat rough start. I think our team struggled with communication greatly during the first semester, both within the EE team and especially with the ME team. Once everyone was on the same page (which happened with some facilitation from the professor) everything went much smoother and we ended up with much better solutions and general work than previously designed/discussed. I think we did wonderful by making it within our incredibly strict timeline, although we had some delays that first semester, we more than made up for it this semester. I think technically our subsystems could've had some more collaboration between EE members, we all became a little overprotective of "our" subsystems and could've benefitted from some other perspectives throughout the design/build stages.

2. Our biggest unanticipated problem was the brownout issue that was caused by the main control being on the same power system as the motors. This issue was caused by the motors temporarily being turned into generators on the downslide of the hill and feeding back that excess power and would squash the voltage difference thus halting the function of the main controller. We also had some issues with the competition boards being not to spec and our robot struggled with that as well as lacking practice in navigating over the obstacles that we did not include on our practice board.

3. I would definitely start by getting the MEs involved as much as possible in the design phase. This would've saved a ton of work that ended up being redesigned anyway. I also would've chosen a pre-built chassis from the very start instead of hoping to build a custom one. This would have taken too much time/money and it slowed the design of other systems way down. The chassis also should've been our very first detail design instead of in the middle.
   
4. Best Practices:
   - Communicate with the entire team (EE and ME) as early and as often as possible and in person
   - Start and finish detail designs early early early so there is time for feedback and changes
   - Document everything: from meeting attendance to a changelog on designs, a paper trail can make or break a situation
   - Start with the detail design that affects the most subsystems (in our case: the chassis) FIRST
   - Have other knowledgeable students and professors look at your project (even if it's going well!) they may see something you haven't noticed
   - GET EVERYTHING ORDERED BEFORE WINTER BREAK IF AT ALL POSSIBLE, YOU NEED THE BUILD/TEST TIME
   
5. Words of Wisdom:
   - This class is hard but necessary. Just keep trying your best.
   - Get detail designs checked early and often, changes can be more complicated than initially thought
   - Be honest in your feedback about anything, lying to simply spare feelings helps no one. Be compassionate and helpful in your feedback but overall be honest.
   - Stay as flexible as possible when working in a team, things will go wrong, and panicking just wastes energy and time
   
6. Knowledge & Skills Acquired:
   - 3D Modeling
   - Complex Arduino Coding in C++
   - Power feedback issues and how to solve them
   - Leadership/Group Management
   - KICAD and circuit design
     
7. Courses that assisted me:
   - Intro to programming in C++
   - Mechatronics
   - Circuits I/II
   - Intro to digital systems (boolean logic)
   - Communicating in the Professions (Engineering Ver.)
   - Computer-Aided Engineering (MATLAB)
   - Microcomputer Systems
