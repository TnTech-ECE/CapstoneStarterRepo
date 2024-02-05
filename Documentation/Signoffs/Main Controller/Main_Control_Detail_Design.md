# Main Control Design

## Function of the Subsystem
![MainCtrl](https://github.com/cebttu/CapstoneTeam1/assets/100803345/b6630717-3855-4901-84fc-6557652b8195) <br>
Figure 1: Main Control Block Diagram

The function of the main controller is to be the brain of the robot. It will read data from the sensors to determine where the robot is and what it should be doing at any given time during the robot's progression through the course. It will communicate with the drive train, the button push, the box sweep, and the team spirit systems by sending the appropriate signals at the appropriate times to make the other systems perform their functions properly.

## Constraints and Standards

| Number | Constraint Description | Origin |
|--------|------------------------|--------|
| 1. | Shall be powered separately from all other subsystems to limit boot time | Strategy Specifications |
| 2. | Shall be operated at a maximum of 16MHz | Component Specifications |
| 3. | Shall have enough GPIO pins to support all other subsystems | Other Subsystem Specifications |

## Buildable Schematic
![WorkingCircuitDiagram](https://github.com/cebttu/CapstoneTeam1/assets/100803345/2fbc8957-5ec6-4fab-8fdf-ab92ff29c93c) <br>
Figure 2: ATmega 2560 Circuit diagram


## Analysis

Constraint 1 Solution:
<br>
The main control shall be powered separately from all other subsystems to limit boot time. This is to streamline the operation of the robot at the start of each round, by having the main controller powered separately the chip does not need to boot up and waste precious time setting up to direct the other subsystems. 

Constraint 2 Solution:
<br>
The main controller will be powered at 5 Volts from the power supply to keep the clock speed at or below 16 MHz according to the datasheet for the ATMEGA 2560. Although overclocking is possible 16MHz is the default setting for the ATmega 2560 chip and will be plenty fast for the other subsystems to process signals to or from the main controller. 

Constraint 3 Solution:
<br>
| Power Subsystem | Type of Pins | Number |
|-----------------|--------------|--------|

| Drivetrain Subsystem | Type of Pins | Number |
|----------------------|--------------|--------|

| Navigation Subsystem | Type of Pins | Number |
|----------------------|--------------|--------|

| Start Sensor Subsystem | Type of Pins | Number |
|------------------------|--------------|--------|

| Team Spirit Subsystem | Type of Pins | Number |
|-----------------------|--------------|--------|

| Box Sweep Subsystem | Type of Pins | Number |
|---------------------|--------------|--------|

| Button Push Subsystem | Type of Pins | Number |
|-----------------------|--------------|--------|


## BOM

| Item | Description | Subsystem | Part Number | Manufacturer | Quantity | Price | Total Price |
|------|-------------|-----------|-------------|--------------|----------|-------|-------------|
| ATmega 2560 | Main Control | Main Control Unit | 2549Q–AVR–02/2014 | Atmel | 1 | Recycled | Recycled |
| | | | | | | | 0.00 |
