# Power Subsystem


  
 
## Function of the Subsystem

The purpose of this subsystem is to take the voltage supplied from a wall outlet and make it usuable for the project. Every component of our project requires our circuit to be DC. So we have reviewed ways to implement this as efficiently as possible. It is more efficient for us to use a wall wart for our project. Wall warts have seen widespread use in the last ten or so years due to their low cost, ease of manufacture, versatility, and sonic improvements; equipment with external power supplies are usually quieter (all other things being equal) than equipment with internal supplies.We have looked into building our own circuit on a breadboard and just connecting it to the rest of the project, but that causes us to not meet the constraint of it looking clean and not distracting as opposed to simply having a wall wart. The wall wart is essentially doing what is shown in Figure 1. The device will take in the AC current from the wall and convert it to DC so it can work properly with the rest of our devices.


## Constraints

### 1) Standard IEC 60950-1 deals with wired and battery powered devices below 600 V
Standard IEC 60950-1 deals with wired and battery powered devices below 600 V. This device will make use of wall power so this standard will be followed to eliminate harm from electric shock, fire, and mechanical instability.


### 2) OSHA standard 1910.304-30
 This provides an in depth guide for safety and regulation of wired power. Whether this be from a battery or through the wall these standards include safe regulations to follow and implement. This system will be dealing with power from a wall outlet so it is important that these standards are followed.



## Buildable schematic 
<img width="499" alt="Screen Shot 2023-04-16 at 6 13 06 PM" src="https://user-images.githubusercontent.com/123600399/232348604-822c1af6-c6a6-4e7a-9731-5389d5561697.png">

### **Figure 1: Full-Wave Bridge Rectifier Transformer**

The above figure is a visual representaion of a general Full-wave bridge rectifier. This is essentially what is inside devices such as wall warts and is also what is built on breadboards to conver AC voltage to DC voltage.



## Analysis
### Explanation of Components

#### TR154

The TR154 is a wall mount (wall wart style) power supply rated for 100-240VAC input and 5 VDC output at 2.5 amps. The 72 inch cable has tinned leads for use with products that have screw terminals for input power. The white line or printing on the insulation indicates negative polarity, while a red band indicates positive polarity. 
This wall mount power supply has a cable length of 72 inches. It is capable of taking 100-240 VAC and converting it into 5VDC. It meets all of the requirements that the group is looking for in terms of a proper power supply.



#### Further connections

The two wires are going to the power supply rail that will be designed to supply the voltage across the entire system. They will be connected to their respective components, with the red wire being for positive connection and black wire for negative connection.


## BOM
| DEVICE            | Quantity | Price Per Unit | Total Price |
| ----------------- | -------- | -------------- | ----------- |
| TR154   | 1              | $22.00        | 22.00     |


## References

[1] Last Minute Engineers, “The full-wave bridge rectifier,” Last Minute Engineers, 15-May-2022. [Online]. Available: https://lastminuteengineers.com/the-full-wave-bridge-rectifier/. [Accessed: 16-Apr-2023].

[2] Sweetwater, “Wall wart,” inSync, 10-Jun-1998. [Online]. Available: https://www.sweetwater.com/insync/wall-wart/. [Accessed: 16-Apr-2023]. 

[3] “Wall Mount Power Supply, 100-240VAC to 5VDC @ 2.5A, tinned leads,” Sealevel, 21-Dec-2022. [Online]. Available: https://www.sealevel.com/product/5-vdc-12-5w-psu/. [Accessed: 16-Apr-2023]. 
