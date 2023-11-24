# Chassis Design

## Function of the Subsystem

![Chassis_Kit](https://github.com/cebttu/CapstoneTeam1/assets/100803345/c138d1fd-b654-46b5-a523-94a4c27e750c)
<br />
Figure 1: Pre-built Chassis Kit

The chassis serves as the foundational element upon which every system depends for dimensions and functionality. Ensuring adherence to competition guidelines in terms of length, width, height, and weight is vital to being able to participate in the competition. The motors and other electrical components included in this kit, will not be used as they will not perform sufficiently for this project. Thus, this design only considers the structure of this chassis kit.


## Constraints and Standards

| Number | Constraint Description | Origin |
|--------|------------------------|--------|
| 1. | The entire robot shall fit inside of 1 cubic foot. | Competition Specifications |
| 2. | The entire robot shall not weigh more than 25 lbs. | Competition Specifications |
| 3. | The chassis shall provide enough room for other subsystems to be attached as one unit. | Strategy Specifications |
| 4. | The tracks shall not significantly impact the speed of the robot. | Strategy Specifications |


## Buildable Schematic
Most of the listed dimensions of the Chassis kit from its various listings online were incorrect and virtually impossible given the dimensions of the mounting plate and how it was centered on the unit. Therefore, a 3D model was built and more appropriate dimensions were deduced from the mounting plate dimensions and track width.

![MountingPlate](https://github.com/cebttu/CapstoneTeam1/assets/100803345/4cdc8dab-dd50-4adb-a247-21912385123e)
<br />
Figure 2: Mounting Plate Dimensions

![Track](https://github.com/cebttu/CapstoneTeam1/assets/100803345/57f6b988-5436-445d-974f-a1cbb6cadc99)
<br />
Figure 3: Track Dimensions

![ChassisWH](https://github.com/cebttu/CapstoneTeam1/assets/100803345/50ec92f1-ca23-4e2f-ba5e-5cb4ad51be48)
<br />
Figure 4: Width and Height of Chassis Unit

![ChassisL](https://github.com/cebttu/CapstoneTeam1/assets/100803345/8f423aea-76e1-42a5-a6ef-ed8528be223e)
<br />
Figure 5: Length of Chassis Unit

## Analysis

Constraint 1 Solution:
<br />
As demonstrated by the 3D Model in Figures 4 and 5, the length, width, and height result in an area of 358.71 cubic inches (0.208 cubic ft.) This is significantly smaller than the 1 cubic ft requirement, leaving plenty of room for any other subsystems that may extend from the robot in any direction.

Constraint 2 Solution:
<br />
The weight listed for the Chassis kit is 1.1kg or 2.4251 lbs. This weight includes the DC Motors that will not be installed and will instead be replaced with different motors, as defined in the Drive Train Design. Even if the new DC Motors weigh more than those included in this kit, the chassis will weigh in at a very small fraction of the maximum weight restriction of 25 lbs, leaving plenty of leftover weight for the other subsystems to use.

Constraint 3 Solution:
<br />
The mounting plate included with the chassis provides 50.45 square inches of room for other subsystems. However, the back and the front of the plate will have extensions added so that they are even with the front and back of the tracks. This will allow an extra 15.62 square inches split between the front and the back of the plate, for a total of 66.07 square inches of room for other subsystems. If needed, a replica of the mounting plate can be built above the original plate, adding another 50.45 square inches. This shall provide plenty of room for the other subsystems.

Estimation of other subsystems' footprints resulted in needing 62 square inches to fit all subsystems on the top surface of the chassis, considering the roughly 66 square inches available and the fact that some subsystems will be mounted in areas other than on the top surface of the mounting plate or extensions, there will be plenty of room for all subsystems to be accommodated on this chassis.

Constraint 4 Solution:
<br />
Tread length = 31.1 inches 
<br />
Required Speed = 2.03 inches/sec
<br />
Gear Ratio = 1.42     (GR = # of teeth on Driven Gear / # of teeth on Driving Gear)  
<br />
Motor Speed = ((2.03 * 1.42) / 31.1 inches)*(60 s) = 5.586 rpm minimum. 
<br /> 

When calculating the speed of the tracks with this rpm for the motor, we get around 2.022 inches/sec for the tracks.
<br />
Efficiency loss = (1-(2.022/2.03)*100 = 0.39% loss 
<br />

This is not an incredibly detrimental loss and this could be overcome.

## BOM

| Item | Description | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-----------|-------------|--------------|----------|-------|-------------|
| Chassis Kit | Chassis and Tracks to mount subsystems to and move the robot| Chassis Design | US02TS100 | SmaringRobot | 1 | $59.99 | $59.99 |
| | | | | | | | $59.99 |
