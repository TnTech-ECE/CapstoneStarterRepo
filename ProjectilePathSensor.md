# Projectile Path Sensor Signoff
## Subsystem Function
The projectile Path sensor subsystem must detect when a projectile is launched and determine which of the 15 possible paths the projectile will take. This is expected to be the first sensor data sent to the interceptor. This data provies the required yaw angle to properly intercept the incoming projectiles.
## Constraints
- Constrain 1: Create an interceptor capable of functioning on its own without outside interaction. 
  - Reasoning: Do to a constumer requirement the interceptor and all external sensor post must be autonomous after intial startup.
- Constraint 2: Design a sensor array that can detect approaching objects and relay their locations to the interceptor.
  - This constraint was developed to meet the requirement to have a sensor that has determines when a projectile has begun to move towards the interceptor. Also, the sensor will determine the path at which the projectile is heading towards to the interceptor.
- Constraint 3: Design a sensor array that operates on battery power.
  - All sensor posts must be powered with a standalone powersupply and must not receive power from a outlet. This originated from a constraint provided by the constumer.
- Constraint 4: The Design shall implement the best remote battery power solution to limit the interceptor’s environmental impact.
  - This constraint addresses the broader impacts of current enviromental impacts of disposing batteries.
- Constaint 5: Design a system that complies with the ANSI Z136.1 Standard
  - This constraint is required due to the use of laser sensors to determine when a projectile is launched. This Standards clasifies lasers as well as defines the required PPE while useing lasers.
