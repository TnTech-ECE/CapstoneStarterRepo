# Charge Controller Subsystem

The purpose of the charge controller subsystem is to maximize the power output of the solar panel and send power to the system, specifically the Power Controller subsystem. The charge controller will send the power controller 12 V at 50 mA regardless of the output of the solar panel. If the power received from the panel is more than what is required by the system, the excess power will be used to charge the two back batteries. Otherwise, the backup batteries will supplement the solar panel output until the required system power is met. 
# Constraints
| No. | Constraints | Origin |
| --- | ----------- | ------ |
| 1.  | Controller shall maximize the output power from the solar panel. | System Requirements |
| 2.  | Controller shall output 12 V at 50 mA with a 10% tolerance to the Power Controller. | System Requirements |
| 3.  | Controller shall prevent the batteries from discharging more than 50% of their capacity. | Extend Life of Batteries    |
| 4.  | Controller shall prevent the batteries from being charged more than 90% of their capacity.  | Extend Life of Batteries    |



