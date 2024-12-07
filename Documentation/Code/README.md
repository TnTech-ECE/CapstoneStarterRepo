This folder contains the implemented code and testing code for the drone tracker project.

Main3 is the camera software that communicates with the database, moves the camera, takes a picture, and sends an image.

Website.7z is what will be running the website, it pull data from the database, then display to a website where it promt a user to login.

imageTest.cpp is the final version for the database implementation that will interact with the MariaDB.
MariaDB, once you install MariaDB onto your device, you will need to create the following 4 tables:

1. drone_location
2. operator_location
3. priority_zone
4. images

The Tables have the following structure:

![DroneLocation](https://github.com/user-attachments/assets/8bb98072-675e-490d-aee0-af61edcd6fce)
![operator_location](https://github.com/user-attachments/assets/cd5923bb-72a1-4af6-a3f4-3986c2c47289)
![PriorityZone](https://github.com/user-attachments/assets/7649c844-d856-4d68-bab9-42821f5075df)
![image](https://github.com/user-attachments/assets/23e2b862-e652-4815-8f1e-31e50c067eb4)

