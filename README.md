# Golf Ball Interceptor

The purpose of the project is to successfully track and intercept a golf ball. This is a senior design project for electrical engineers expecting to graduate in December 2024 at Tennessee Technological University. This project is funded by DEVCOM, and its purpose is to demonstrate the capabilities of projectile interception to prospective STEM students.

## Executive Summary

The golf ball interceptor is expected to track and intercept a golf ball traveling down predetermined trajectories. An interception occurs when a counterprojectile is fired, causing a notable change of trajectory. 


## Capabilities

1. Automatic operation without additional input
2. Reliably intercept an incoming target
3. Able to locate and predict the trajectory of the incoming target
4. Effective use of batteries with attention to environmental impact
5. Wireless sensor posts that work independently and wirelessly without the need of wires


## Salient Outcomes

Projects often have some outcomes that are more interesting than others. Here, highlight those things that you found interesting!
1. Redundant methods of tracking the incoming target
2. Image proccessing algorithm that is capable of tracking the projectile in 3-dimensions


## Project Demonstration & Images

Give a link to a video of the project being demonstrated. The video should be hosted on the capstone youtube.

Below the video link show some well-taken, appropriately sized images of the project.


## About Us

### Team

[Adam Morrow][def1] is a senior in computer engineering major at Tennessee Technological University. He is interested in computer hardware and embedded systems. Adam is responsible for the Sesoor Post Velocity and Acceleration subsystem.

[Allen Watson][def2] is an electrical engineering major at Tennessee Technological University. He is interested in power systems. Allen is responsible for the launcher housing subsystem. 

[Colby Drake][def3] is an electrical engineering major at Tennessee Tech. He has an interest in programming and power systems. Colby is responsible for the launcher aiming subsystem.

[Jonah Burke][def4] is an electrical engineering major at Tennessee Tech. He has an interest in power systems. Jonah is responsible for the launcher firing subsystem.

[Tyler Kasuboski][def5]

[James Jones][def6] is an electrical engineering major at Tennessee Tech. He has an interest in digital signal processing. James is responsible for the head on position subsystem, and the networking subsystem.

### Faculty Supervisor

Jesse Roberts

### Stakeholders

The stakeholder in this project is [DEVCOM][def7] - DEVCOM is the US Army Combat Capabilities Development Command, who are focused on empowering America's Soldiers.

### Recognitions

Use this space to recognize anyone that you feel has had an impact on the project. Be sure to recognize the work of previous teams if you referenced it for style or content. 

## Repo Organization

### Reports

[Project Proposal](https://github.com/JTJones73/Capstone2024-Team2/blob/main/Reports/Capstone%20Team%20Two%20Project%20Proposal.pdf)
  * [Revision](https://github.com/JTJones73/Capstone2024-Team2/blob/main/Reports/Project%20Proposal%20Revised-%20Correct%20Template.pdf)
  * The project proposal shows the team's initial thoughts, applicable constraints, and the formulated problem.

[Conceptual Design](https://github.com/JTJones73/Capstone2024-Team2/blob/main/Reports/Capstone%20Team%20Two%20Conceptual%20Design_FinalDraft.pdf)
  * This document shows the expectations of each subsystem and how they are expected to work together to achieve the goals outlined in the project proposal.

In the reports section of this repository information about the individual expectations for the reports and how they should be housed is provided.

### Documentation

[Housing](https://github.com/JTJones73/Capstone2024-Team2/blob/main/Documentation/Signoffs/Housing.md)
  * The launcher housing will provide power to the other subsystems connected to the main interceptor body, provide a functional E-Stop button, have a lighting system, and have a firing alarm.

[Projectile Path Sensor](https://github.com/JTJones73/Capstone2024-Team2/blob/main/Documentation/Signoffs/ProjectilePathSensor.md)
  * The projectile Path sensor subsystem must detect when a projectile is launched and determine which of the 15 possible paths the projectile will take.

[Launcher Aiming](https://github.com/JTJones73/Capstone2024-Team2/blob/main/Documentation/Signoffs/launcher-aiming-signoff.md)
  * The Launcher Aiming subsystem will take in signals from the main control unit, and adjust the launcher's position accordingly.

### Software

* OpenCV: This is the computer vision software used by the head on position subsystem to track the golf ball.
* Arduino IDE: This is the development  environment used to program the Arduino Mega for the projectile path subsystem and the ESP8266's for the networking subsystem.
* Raspberry Pi OS: The Linux operating system used to interface with the interceptor's controller, allowing for aiming, launching, and head on positoning calculations.


[def1]: https://www.linkedin.com/in/adam-morrow-7449a7238/
[def2]: https://www.linkedin.com/feed/
[def3]:https://www.linkedin.com/in/colby-drake-16379b1b9/
[def4]:https://www.linkedin.com/in/jonah-burke-a169a21a1/
[def5]:https://www.linkedin.com/in/tyler-kasuboski/
[def6]:https://www.linkedin.com/in/jtjones73/
[def7]: https://devcom.army.mil
