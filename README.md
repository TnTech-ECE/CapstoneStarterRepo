# Golf Ball Interceptor

The purpose of the project is to successfully track and intercept a golf ball. This is a senior design project for electrical and computer engineers at Tennessee Technological University expecting to be completed December 2024. This project is funded by DEVCOM, and its purpose is to demonstrate the capabilities of projectile interception to prospective STEM students.

## Executive Summary

The golf ball interceptor is expected to track and intercept a golf ball traveling down predetermined trajectories. An interception occurs when a counter projectile is fired, causing a notable change of trajectory. The success of this project is based on how effectively it can locate and intercept an incoming projectile. The system will work in three stages with the first being detection where the projectile is detected alerting the subsystems to begin locating the target. The next stage is locating where data from the various sensors are used to locate the incoming projectile. The final stage is interception where data from the previous steps is used to send a counter projectile to disrupt the projectile's path.

## Current Team Goals and Updates

The team is in the design phase of the project. This is midpoint of the senior design project, and the goal is complete the design of all subsystems soon which will bring the team to the next stage which is implementation and part ordering. 

## Known Difficulties and Limitations

The most difficult aspect of this project is time. The target is only in flight for as little as 1.78 seconds. This does not give the systems much time to locate and intercept the incoming target, and as a result, time is having to be budgeted very conservatively.

## Capabilities

1. Automatic operation without additional input
2. Reliably intercept an incoming target
3. Able to locate and predict the trajectory of the incoming target
4. Effective use of batteries with attention to environmental impact
5. Wireless sensor posts that work independently and wirelessly without the need of wires


## Salient Outcomes

1. Redundant methods of tracking the incoming target
2. Image processing algorithm that is capable of tracking the projectile in 3-dimensions


## Project Demonstration & Images

The project is still in the design stage, and there are currently no images or videos of demonstrations.


## About Us

### Team

[Adam Morrow][def1] is a senior in computer engineering major at Tennessee Technological University. He is interested in computer hardware and embedded systems. Adam is responsible for the Sensor Post Velocity and Acceleration subsystem.

[Allen Watson][def2] is an electrical engineering major at Tennessee Technological University. He is interested in power systems. Allen is responsible for the launcher housing subsystem. 

[Colby Drake][def3] is an electrical engineering major at Tennessee Tech. He has an interest in programming and power systems. Colby is responsible for the launcher aiming subsystem.

[Jonah Burke][def4] is an electrical engineering major at Tennessee Tech. He has an interest in power systems. Jonah is responsible for the launcher firing subsystem.

[Tyler Kasuboski][def5] is an electrical engineering major at Tennessee Technological University. He is interested in microcontrollers and power. Tyler is responsible for the projectile path sensor.

[James Jones][def6] is an electrical engineering major at Tennessee Tech. He has an interest in digital signal processing. James is responsible for the head on position subsystem, and the networking subsystem.

### Faculty Supervisor

Jesse Roberts

### Stakeholders

The stakeholder in this project is [DEVCOM][def7] - DEVCOM is the US Army Combat Capabilities Development Command, who are focused on empowering America's Soldiers.

### Recognitions

* The team would like to extend their appreciation to Professor Jesse Roberts at Tennessee Tech. Professor Roberts is an instructor at Tennessee Tech and he is pursuing his PHD focusing on Artificial Intelligence at Vanderbilt University. Professor Roberts gives the team his professional input holding us to a high standard of excellence.


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

### Subsystems in Progress

[Head on Position Sensor](https://github.com/JTJones73/Capstone2024-Team2/blob/Head-On-Sensor-Subsystem/Documentation/Signoffs/Head-On-Sensor.md)
 * The purpose of the head on position sensor is to determine the target's location relative to the interceptor by using cameras and an image processing algorithm.

[Networking](https://github.com/JTJones73/Capstone2024-Team2/blob/JTJones73-Networking-Subsytem/Documentation/Signoffs/Networking.md)
  * The purpose of the networking subsystem is to allow sensors to wirelessly communicate reliable with minimum setup and user input.

[Sensor Posts Velocity Sensor](https://github.com/JTJones73/Capstone2024-Team2/blob/awmorrow42-signoff-SensorPost-VelocityAndAcceleration/Documentation/Signoffs/SensorPosts.md)
 * This portion of the sensor post array will be responsible for obtaining the velocity and acceleration of the practice golf ball as it travels down the fishing line towards the interceptor body.
### Software

* OpenCV: This is the computer vision software used by the head on position subsystem to track the golf ball.
* Arduino IDE: This is the development  environment used to program the Arduino Mega for the projectile path subsystem and the ESP8266's for the networking subsystem.
* Raspberry Pi OS: The Linux operating system used to interface with the interceptor's controller, allowing for aiming, launching, and head on positioning calculations.
* KiCad: KiCad is an open source circuit design tool useful for designing PCB's and schematics.


[def1]: https://www.linkedin.com/in/adam-morrow-7449a7238/
[def2]: https://www.linkedin.com/feed/
[def3]:https://www.linkedin.com/in/colby-drake-16379b1b9/
[def4]:https://www.linkedin.com/in/jonah-burke-a169a21a1/
[def5]:https://www.linkedin.com/in/tyler-kasuboski/
[def6]:https://www.linkedin.com/in/jtjones73/
[def7]: https://devcom.army.mil
