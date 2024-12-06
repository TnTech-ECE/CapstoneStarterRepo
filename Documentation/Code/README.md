This folder contains the implemented code and testing code for the drone tracker project.

Main3 is the camera software that communicates with the database, moves the camera, takes a picture, and sends an image.

imageTest.cpp is the final version for the database implementation that will interact with the MariaDB.
MariaDB, once you install MariaDB onto your device, you will need to create the following 4 tables:

1. drone_location
3. operator_location
4. priority_zone
5. images

Website.7z is what will be running the website, it pull data from the database, then display to a website where it promt a user to login.
