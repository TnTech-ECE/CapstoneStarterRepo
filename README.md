# {Parking Lot Monitoring System: Ground Based Solution} - Your project should have a catchy and functional name

The descriptions and information in all readme files in the starter repo (including this one) must be edited. All section descriptions must be deleted. Any failure to remove the description information (like the statement that you are currently reading) will be heavily penalized!

## Executive Summary

Give the elevator pitch and abstract for the project. It should allow interested visitors to broadly understand the motivation for the project and what the project has accomplished.

This project is a continuation project from the 2022-23 academic year at Tennessee Technological University to monitor parking lots in a manner that allows students, faculty, staff, and campus visitors to find parking lots with availability in a timely manner. The previous team used cameras to monitor incoming and outgoing traffic in parking lots.  This solution will not work for many of the parking lots that do not have the infrastructure nearby to support cameras.  By using inductive loops to monitor designated entrances/exits of parking lots, more parking lots across campus can be monitored and students, faculty, etc. can find parking availability without having to search an entire parking lot in hopes of finding an open parking spot.

## Capabilities

Though this project is a continuation project, it deviates away from using cameras and instead uses a ground-based solution.  Each capability of the project is mentioned:

1. This project will detect vehicles and motorcycles entering/exiting parking lots that have designated entrances/exits.
2. This project will only detect vehicles and motorcycles that enter/exit a parking lot at a speed less than 20 mph.
3. This project will use LoRaWAN to transmit data from a designated entrance/exit of a parking lot to the Capstone Lab in Brown Hall for data interpretation and storage into the server.
4. For testing this project in the Engineering Quad Parking Lot (between the engineering buildings on the campus of Tennessee Tech University), one entrance/exit will use solar power, with a backup battery, to power the inductive loops and the transmitter for the data.  By using solar power, parking lots that are not located near buildings with wall outlets can generate power and function across the campus of Tennessee Tech.

Here explain in more detail (though not as much as will be given in the datasheet) what the version of this project in this repo is capable of doing.


## Salient Outcomes

1. This project will continue the work of creating an effective Parking Lot Monitoring System.
     a. As of September 2023, the Parking Lot Monitoring System is in the second year of the overall project.  This team has inherited a previous system that used cameras to do complete both static tracking (monitor parked cars) and dynamic tracking (cars entering and exiting lots) to efficiently monitor parking lots.  This method is a very efficient way to monitor parking lots; however, parking lots that are located away from campus buildings or do not have the infrastructure to support camera placement in the lots do not benefit from this method.  By using a ground-based solution to monitor parking lots with designated entrances/exits, more parking lots can be monitored across the campus of Tennessee Tech.
2. This project will implement the use of solar panels to efficiently power the system.
     a. Some parking lots across the campus of Tennessee Tech are not located near campus buildings.  To allow the system to work in these lots, solar panels will be used to power the system at these lots to efficiently monitor these lots so students, faculty, etc. know if there is parking availability at these specific lots.


Projects often have some outcomes that are more interesting than others. Here, highlight those things that you found interesting!


## Project Demonstration & Images

Give a link to a video of the project being demonstrated. The video should be hosted on the capstone youtube.

Below the video link show some well-taken, appropriately sized images of the project.


## About Us

### Team

Abdulrahman Alrudayan is a senior Electrical Engineering major at Tennessee Technological University.  His interests include power systems and digital design.  The main focus for Abdulrahman is designing the main power system that will distribute power to the entire system through the use of buck converters, step down transformers, etc.

Khalifah Altamimi is a senior Electrical Engineering major at Tennessee Technological University.  His interests include power systems, robotics, and digital design.  The main focus for Khalifah is designing the backup power system that will provide power to allow the system to continue working when a power outage has occurred on campus.  When the system is not being used, it will be charging and stay charged until backup power is needed for the system.

Brady Beecham is a senior Computer Engineering major at Tennessee Technological University.  His interests include

Kyle Plant is a senior Computer Engineering major with a minor in Computer Science at Tennessee Technological University.  His interests include programming, FPGA, VLSI, networks, embedded systems, artificial intelligence, automation, and more. He has had three internships during his time as an undergraduate. The first two were at Matheson, a producer of industrial, medical, and specialty gasses as well as gas handling equipment. His first internship at Matheson involved making user-friendly GUI dashboards to display graphs of gas purity or mixture ratio data as well as many other small projects. His second internship at Matheson involved performing general site IT duties as well as a few small projects. His third internship was with QMSI or Quality Manufacturing Systems, Inc. QMSI is an automation and systems integration company that specializes in automated pharmacy systems. At QMSI he worked with AutoCAD to make drawings for the conveyor lines and motor panels. The main focus for Kyle is designing a system to collect data from the loop detector, transmit data to a central computer, and store this data in a database within the central computer. This will involve microcontroller programming, wireless networking, and database management.

Michael Sisk is a senior Electrical Engineering major at Tennessee Technological University.  His interests include power systems, robotics, and automation.  He has spent eight months interning at Jack Daniels Distillery in Lynchburg, TN as an engineering maintenance intern.  He is also currently serving as the Engineering Joint Council (EJC) Representative for the student chapter of the Institute of Electrical and Electronics Engineers (IEEE).  The main focus for Michael Sisk is designing the ground-based sensor, which involves using a series of inductive loops to detect the presence of vehicles and determining whether a vehicle is entering or exiting a parking lot from the information given from the loops.



### Faculty Supervisor

Mr. Jesse Roberts - ECE Department

### Stakeholders

The primary customer for this project is the Naval Surface Warfare Center Dahlgren Division in Dahlgren, VA, that is under the command of the Naval Sea Systems Command (NAVSEA). 

One major stakeholder that will be affected by the project are commuter students.  Commuter students will use this system heavily as they must find parking in a timely manner in specific parking lots in order to be on time for class or extracurricular events on campus.

Another stakeholder that will be affected by the project are campus visitors.  For visitors that have come to Tennessee Tech University numerous times or for first time visitors, it will be extremely useful in locating parking lots that have availability to allow them more time to complete business they have on campus and not have to spend a significant amount of time finding places to park on campus.

Tell a bit about the customer for the project. Also discuss any other groups (specific or general) that are expected to be impacted by the project.

### Recognitions

Since this project is a continuation from the 2022-23 academic year, this team wants to recognize the previous Parking Lot Monitoring System team and their members: Kester Nucum, Aaron Wilhite, Gabriel Laboy, Genevieve Schreiber, and Reggie Garza.  This team consisted of three computer engineering students and two electrical engineering students.  With their knowledge and collaboration with the CSC team, they were successful in creating a server, sign, and cameras to detect and count the number of vehicles in a specified parking lot.  Due to their work, this team of three electrical engineering students and two computer engineering students was able to create a ground-based solution to assist the current camera system in detecting vehicles entering and leaving a parking lot and display an accurate number of available parking spots within a specific parking lot.

Use this space to recognize anyone that you feel has had an impact on the project. Be sure to recognize the work of previous teams if you referenced it for style or content. 

## Repo Organization

For the layout of the team's Github, it includes three main folders: Documentation, Reports, and Software.  The three folders are explained in the following subsections.

Give the layout of the repo and what can be found where. Make it easy on those who are interested by making the headings of the various things in this section clickable links to the relevant folder or file in the repo.


### Reports

In the Reports folder, it contains documents such as the Project Proposal, Conceptual Design, Experimentation, Final Report, Lessons Learned, etc.  All documentation that is in the form of a report is located in this folder.  This folder also contains a broad explanation of the project from beginning to end in the numerous documents provided in this folder.

In the reports section of this repository information about the individual expectations for the reports and how they should be housed is provided.

### Documentation

In the documentaion section information regarding the documentation that is required and how it should be organized is given.

### Software

In the software directory of the repo information regarding how each team is expected to document software can be found.
