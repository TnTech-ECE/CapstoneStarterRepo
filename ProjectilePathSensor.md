# Projectile Path Sensor Signoff
## Subsystem Function
The projectile Path sensor subsystem must detect when a projectile is launched and determine which of the 15 possible paths the projectile will take. This is expected to be the first sensor data sent to the interceptor. This data provies the required yaw angle to properly intercept the incoming projectiles.
## Constraints
- Constrain 1: Create an interceptor capable of functioning on its own without outside interaction. 
  - Reasoning: Do to a constumer requirement the interceptor and all external sensor post must be autonomous after intial startup.
- Constraint 2: Design a sensor array that can detect approaching objects and relay their locations to the interceptor.
  - This constraint was developed to meet the requirement to have a sensor that has determines when a projectile has begun to move towards the interceptor.
