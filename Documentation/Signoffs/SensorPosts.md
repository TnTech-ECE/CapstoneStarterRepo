
# Sensor Post Array Velocity and Acceleration Signoff
## Functionality 
 This portion of the sensor post array will be responsible for obtaining the velocity and acceleration of the practice golf ball as it travels down the fishing line twards the interceptor body. To accomplish this task this subsystem will take in the velocity and acceleration data from the mmWave Radar to do the calculations neccisary to acertain the velocity and acceleration. This subsystem will then wirelessly transmit the velocity and acceleration of the practice gold ball to the aiming subsystem for further use of this data.
## Constraints
* C8: Design a sensor array that operates on battery power
* C14: Design a system with a maximum sensor input delay of 100ms
* C15: The Interceptor project shall have solders that conform to the IPC-J-STD.
* C16: The Interceptor project shall have a safe wiring scheme for all components of the project.
* C19: The Design shall implement the best remote battery power solution to limit the interceptor's environmental impact.
* C22: 
## Schematics

## Analysis
### Detection distance
To find the maximum distance the radar will be able to detect the a few calculations where needed. The first being the Radar Cross Section (RCS) which is the equivalent area of the target preceived by the radar. To do this I used the online calculator [1] which uses the target having a sherical shape and the following formula.
$$ RCS = { 4* Pi * r^2 * Sr\over St } $$
Using 0.02124202 meters for the rarget radius gives an RCS estimation of 0.0014175 meters $^2$. Now that an RCS value has been found the max radar range calculator [2] can be used to find the maximum range the radar can be used to detect the golfball. This calculator uses the equation 
<p align = "center">
<img src = https://github.com/JTJones73/Capstone2024-Team2/blob/SensorPosts/Documentation/Images/RadarRange.png/>
</p>
In this equation plug in the Radar Output Power or Equivalent Transmit Power lower end of the range 9 dBm, operating frequency of 24 GHz the RCS of 0.0014175, since we do not have a data sheet we make assumptions for the two remaing unkowns. The antena gain is assumed to be 1.5 since it is common for antenas and the minimum detecitible signal is assumed to be -90 dBm. With these values we get a maximum detection distance of 1.188 m or 46.77 inches. 

## Implementation and Testing

### Bill of Materials (BOM)
<div align="center">
| Name of item | Description | Part Number | Manufacuer | Quantity | Price | Total |
|--------------|-------------|-------------|------------|----------|-------|-------|
<div>
### Refrences

[1]https://www.rfwireless-world.com/calculators/Radar-RCS-calculator.html
[2] https://www.pasternack.com/t-calculator-radar-range.aspx
