# Database System
## Functionality
The database subsystem will receive data from the receiver, website and camera subsystem, then store it locally. Website subsystem will be provided full access to the stored data. Data stored will containt the following: pre-authorized flight information, pre-marked geographical locations, images, camera health status, drone ID, drone speed and the location of the drone and control station. Whenever a drone is detected by the receiver, the database will check for pre-authorized access releated to the received drone ID. If not authorized or drone detected within any pre-marked geographical locations, then the drone location, drone speed and control station location will be sent to the camera subsystem.

## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | The database shall be stored locally and allow the website subsystem to edit the pre-authorized flight information, pre-marked geographical locations and have full access to view all other data. | Design Constraint |
|  2 | The system shall check for pre-authorized access for any drone's new flight session, if no pre-authroized acess found, then the Drone location, speed and Control station location will be sent to the camera subsystem. | Design Constraint |
|  3 | If a drone enter a pre-marked geographical locations, then the drone location, drone speed and control station location will be sent to the camera subsystem.  | Design Constraint |
|  4 | The system shall indicate the health status of Camera system | Design Constraint |
|  5 | The system shall store the data for at least 90 days | TTU Policy/Design Constraint |
|  6 | The system shall support data transfer over the network | Design Constraint |
|  7 | The Device used to host the database shall have a casing that prevents direct physical interaction with the hardware | Design Constraint |

<sup>1</sup> 
The following contain the list of data that will be stored inside the base, pre-authorized flight information, pre-marked geographical locations, images, camera health status, drone ID, drone speed and the location of the drone and control station.

<sup>4</sup> 
The health status of Camera is there to indicate when the camera system is not functioning but does not specificity the acutal problem of the camera.

<sup>5</sup>
Following TTU policy 856 [^7] disposal procedures of the data with its levels of data security. For public level information, all data must be erased using minimal procedures and security best practices.

<sup>6</sup>
This is to ensure wifi is accessable, so that it can receive data package from other subsystem.

<sup>7</sup>
Since the Device will be inside the building, the case will be used to prevents physical contact with it. However, it does not prevent the power supply from being disconnected by outside soruce.

## Flowchart
![image](https://github.com/user-attachments/assets/60f31ebf-705d-475a-8613-69898a57d2bc)

## Analysis
Looking at the theoretical Maximum performance of processing time it would take to store and retrieve data from the database, result will be calculated base on the CPU and RAM speed/configuration. The actual performance will be lower due to many system variables. To simulate the worst case senerios, system efficiency will be counted during calculation.

In the [Block Message section](#Block-Message), every block message received from the receiver subsystem will be 25 bytes. The actual stored data will be much smaller because not all data inside the block message will be stored in the database. The camera used in the camera subsystem have an image Sensor Resolution of 4056 x 3040 pixels, and each RGB pixel will contain 24 bits. A single image can contain maximum of 36.99 MB. According to the specification of the raspberry pi, it have a quad-core CPU that run at 2.4 GHz. We can calculate the theoretical data processing rate using the following equation: Data Processing Rate(Byte/s) = Data per cycle(Byte) × Clock speed x Instruction Per Cycle. Since 64-bit version of [MySQL](#MySQL-Setup) will be installed, which mean the CPU will be handlling 64 bits(8 Bytes) per cycle. Also, the instruction per cycle will be set to 1 since we are looking at the worst case scenarios. Performing the following calculation: Data Processing Bandwidth = 8 x (2.4x10^9) x 1, and the data rate will result in 19.2 GB/s for a single core process. The size of the message block is relatively small compare to the data processing rate, so, the CPU will have no problem unpacking the message block and store the relevant information inside database. For the image processing, even if the CUP data processing rate is running at 10% effiency, it can still handle 51 image per second.

Shifting the focus to RAM, the Raspberry pi 5 is using LPDDR4x-4267 SDRAM. The following equation can calculate the theoretical Maximum Memory Bandwidth[^4]: Memory Bandwidth(Bytes/s) = Memory frequency × Data Rate(# of channels) × Memory Bus Width(Bytes). Using the LPDDR4X/LPDDR4 SDRAM data sheet[^5], memory frequency, data rate can be obtained. The Ram will have frequece of 2133 MHz, 4 channels of Data Rate and the Memory Bus Width will be 8 bytes since the system is running on a 64-bits system. Substitute the values, the Maximum Memory Bandwidth will be 68.256 GB/s.

Since the Theoretical maximum Processing rate of RAM is much faster than the data processing rate of the CPU, the store and retrieval of data directly from the RAM should not be bottlenecked. However, the Raspberry pi 5 only support upto 8 GB of RAM capacity and the database will only be allocate 4 GB or less because the Website server is also running on the same device which will also take up RAM space. With 4 GB of RAM the database will only be able to hold 108 images, not counting other data stored inside the database. Therefor more storage capacity is needed. Follwing the [M.2 HAT+](#M.2-HAT+) section, storage capactiy can be expanded using M.2 SSD. Using a 256GB M.2 2242 SATA from Kingston[^6], according to their sepecifications, the M.2 SSD will perform up to 550 MB/s read and 510 MB/s write. Comparing the maximum speed of read and write to the CUP's data processing rate, the processing time of retrieving data from the M.2 SSD will increase as the database get larger.

## Raspberry pi 5 Setup
The Raspberry Pi will run the offical Raspberry Pi OS, following the [Raspberry pi OS documentation installation](https://www.raspberrypi.com/documentation/computers/os.html) guide.

## Network Access
Once the Raspberry Pi 5 OS is set up, on the upper right hand side and clicking on the following symbol will bring up a menu that let device connect to wifi. <br>
![image](https://github.com/user-attachments/assets/a47211ed-970c-4547-b426-8f3271b19deb) <br>
![image](https://github.com/user-attachments/assets/acb6334d-4ac3-475f-bbd2-cd429fb7491e) <br>


## MySQL Setup
Raspberry Pi officially suggested that "Advanced Package Tool (APT) is the recommended way to install, update, and remove software in Raspberry Pi OS."

## M.2 HAT+
Following the [M.2 HAT+ installation guide](https://www.raspberrypi.com/documentation/accessories/m2-hat-plus.html) will allow the Raspberry pi 5 to increase its storage capacity. The M.2 HAT+ will only support M.2 SSD 2230 or 2242 form factor.

## Raspberry pi 5 Connection breakdown
![image](https://github.com/user-attachments/assets/ed25a725-7c42-43eb-bb01-05748570be05) <br>
The picture below show the front side of the M.2 HAT+, the PCIe port circled in red will be used to connect the PCIe port on the Raspberry pi, and M.2 SSD drive will be installed in the NVME port circled in purple. <br>
![image](https://github.com/user-attachments/assets/5edb4456-225b-4b07-9067-6c477ec7b84e) <br>
The picture below show the USB-c Power jack which will be connected to a [27W USB-C Power Supply](https://datasheets.raspberrypi.com/power-supply/27w-usb-c-power-supply-product-brief.pdf), a power supply that output 5.1V. <br>
![image](https://github.com/user-attachments/assets/cdba1b4b-e40d-4b9a-826b-5a96c977f6b1)

## Block Message
Inside the data package from the receiver system, there will be multiple blocks of message. The block message is 25 bytes in length with a 1-byte header followed by 24 bytes of data. When the block message is decoded, the 1-byte message header will specify the message type, and it will contain the following data: Basic ID message(0x0), Location/Vector Message(0x1), and the rest is optional, Authentication Message(0x2), Self-ID Message(0x3), System Message(0x4), Operator ID(0x5), Message Pack(0xF)[1]. Only System Message will be decoded since the rest of the Optional message type does not provide any information for tracking.

Note: For all block messages, it will be in big-endian format, unless specified to be in little-endian (LE) format.

The Basic ID message will provide UAS ID, characterizes the type of ID, and identifies the type of UA.
| Byte(length)| Data Field | Data type | Detail |
| -- | --------- |--------|---------|
|  1 | [ID Type][UA Type] | [7..4][3..0] bits | UA type will not be stored in the database since it is not necessary for tracking. |
|  2..22(20) | UAS ID | [20 Byte(4 bits per character)] | UAS ID within the format of ID Type (Padded with nulls), explained below |    
|  23..24(3) | Reserved |  |  |


UAS ID consists of four options: Serial number(CTA-2063-A Serial Number format), Registration ID, UTM(UUID), and specific session ID.
0. None
1. According to ANSI(Approved American National Standards), the serial number have the following format, SN = [4 Character manufacturer(MFR) cdoe][1 Character length code][15 Character MFR's serial nmumber]. The MFR code includes a combination of digits and uppercase letters, except the letters O and I. The length code is a single character that ranges from 1 to 15, and A to F will correspond to 10 to 15 respectively. MFR's serial number length is determined by the character length code, which includes a combination of digits and uppercase letters, except the letters O and I, but may include all digits[^2].
2. Registration ID shall be in the following format: [ICAO Nationality Mark].[CAA Assigned ID], ASCII encoded. The ICAO Nationality Mark is only uppercase Letters(A), followed by a dot then digits(0-9), and the CAA Assigned ID will be in digits (0-9).
3. UTM will provide a 128-bit universal unique ID the length of the group is 8-4-4-4-12 which includes a combination of letters and digits (0-9), and the UUID is fixed length.
4. The specific session ID will be 20 bytes, with the first byte used as the unique identifier, and the remaining 19 bytes providing the session ID.


The Location/Vector Message type provides the location, altitude, direction, and speed of UA.
| Byte(length) | Data Field | Data type | Detail |
| -- | --------- |--------|---------|
| 1 | [Operational StatusStatus][Reserved][Height Type][Direction Segment][Speed multiplier] | [7..4][3][2][1] bits | bits(7..4) will provide the operational Status (table 1), bits(3) is Reserved, bits(2) identify the height type: 0 is above takeoff and 1 is above ground level, bits(1) provide the direction Segment: 0 is less than 180 degree and 1 is greater than or equal to 180, bits(0) provide the speed multiplier: 0 will multiply the speed by 0.25 and 1 will multiply the speed by 0.75. |
| 2 | Track Direction | Unsigned Int | data type is 0-359 Unsigned Int(Uint) if flag bits(1) are 1 then 180 will need to be added to the Encoded Value, otherwise the encoded value will be the final value. |
| 3 | Speed | Unsigned Int | If flag bits(0) is 0 the Value = EncodedValue * 0.25, if flag bits(0) is 1 then the Value = (EncodedValue * 0.75) + (255 * 0.25) |
| 4 | Vertical | Float | (Float) Value = EncodedValue * 0.5 |
| 5..8(4) | Latitude | Signed Int(double)(LE) | (double) Value = EncodedValue/(10^7) |
| 9..12(4) | Longitude | Signed Int(double)(LE) | (double) Value = EncodedValue/(10^7) |
| 13..14(2) | Pressure Altitude | Unsinged Int(Float)(LE) | (float) Value = (EncodedValue * 0.5) - 1000, If decoded Value = -1000, then real value is unknown |
| 15..16(2) | Geodetic Altitude | Unsinged Int(Float)(LE) | (float) Value = (EncodedValue * 0.5) - 1000, If decoded Value = -1000, then real value is unknown |
| 17..18(2) | Height | Unsinged Int(Float)(LE) | (float) Value = (EncodedValue * 0.5) - 1000, If decoded Value = -1000, then real value is unknown |
| 19 | [Vertical(Geodetic) Accuracy][Horizontal Accuracy] | [7..4][3..0] bits | Detail in Table 2 and 3 |
| 20 | [Baro Altitude Accuracy][Speed accuracy] | [7..4][3..0] bits | [7..4][3..0] bits | Baro Altitude accuracy is in detail in Table 2, and speed accuracy is in Table 4 |
| 21..22(2) | Timestamp | Unsigned Int(LE) | Value = Current UTC Data/time (Hour) + ValueTenths (of seconds) |
| 23 | [Reserved][Timestamp accuracy] | [7..4][3..0] bits | 0 to 15, A to F will correspond to 10 to 15 respectively. 0 will be unknown(NULL) |
| 24 | Reserved |  |  |


Pseudocode code For Timestamp for Location/Vector Message type: 
If Encoded Value > Tenths of seconds since the current hour at time of receipt <br>
then <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Value Tenths = tenths of seconds since previous hour <br>
else <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ValueTenths = tenths of seconds since current hour <br>


Table 1: Operational Status
| Decimal | Bits | Detail |
| -- | --------- |--------|
| 0 | 0000 | Undeclared |
| 1 | 0001 | Ground |
| 2 | 0010 | Airborne |
| 3 | 0011 | Emergency |
| 4 | 0100 | Remote ID System Failure |
| 5..15 | 0101..1111 | Reserved |


Table 2: Vertical Accuracy
| Decimal | Bits | Detail |
| -- | --------- |--------|
| 0 | 0000 | greater than or equal to 150 m or Unknown |
| 1 | 0001 | less than 150 m |
| 2 | 0010 | less than 45 m |
| 3 | 0011 | less than 25 m |
| 4 | 0100 | less than 10 m |
| 5 | 0101 | less than 3 m |
| 6 | 0110 | less than 1 m |
| 7..15 | 0111..1111 | Reserved |


Table 3: Horizontal Accuracy
| Decimal | Bits | Detail |
| -- | --------- |--------|
| 0 | 0000 | greater than or equal to 18.52 km (10 NM) or Unknown |
| 1 | 0001 | less than 18.52 km (10 NM) |
| 2 | 0010 | less than 7.408 km (4 NM) |
| 3 | 0011 | less than 3.704 km (2 NM) |
| 4 | 0100 | less than 1852 m (1 NM) |
| 5 | 0101 | less than 926 m (0.5 NM) |
| 6 | 0110 | less than 555.6 m (0.3 NM) |
| 7 | 0111 | less than 185.2 m (0.1 NM) |
| 8 | 1000 | less than 92.6 m (0.05 NM)|
| 9 | 1001 | less than 30 m|
| 10 | 1010 | less than 10 m |
| 11 | 1011 | less than 3 m |
| 12 | 1100 | less than 1 m |
| 13 | 1101..1111 |Reserved|


Table 4: Speed Accuracy
| Decimal | Bits | Detail |
| -- | --------- |--------|
| 0 | 0000 | greater than or equal to 10 m/s or Unknown |
| 1 | 0001 | less than 10 m/s |
| 2 | 0010 | less than 3 m/s |
| 3 | 0011 | less than 1 m/s |
| 4 | 0100 | less than 0.3 m/s |
| 5..15 | 0101..1111 | Reserved |


The System Message type provides the Operator Latitude, Operator Longitude, AreadCount, Area Radius, Area Ceiling, Area floor, UA classification, Operator Altitude, and Timestamp.
| Byte(length) | Data Field | Data type | Detail |
| -- | --------- |--------|---------|
| 1 | [Reserved][Classification Type][Operator Location/Altitude Source type] | [7..5][4..2][1..0] bits | For Classification Type, 0(000 bits) = Undeclared, 1(0001 bits) = European Union, 2..7(010..111 bits) = Reserved. For Operator Location/Altitude Source type, if 0(00 bits) = Take off, 1(01 bits) = Dynamic, 2(10 bits) = Fixed |
| 2..5(4) | Operator Latitude | Signed Int(double)(LE) | (double) Value = EncodedValue/(10^7) |
| 6..9(4) | Operator Longitude | Signed Int(double)(LE) | (double) Value = EncodedValue/(10^7) |
| 10..11(2) | AreaCount | Unsigned Int(LE) | default 1, but can have max up to 65,000. |
| 12 | Area Radius | Unsigned Int | Radius of cylindrical area of group or formation * 10 m (default 0) centered on Location/Vector Message position |
| 13..14(2) | Area Ceiling | Unsigned Int(float)(LE) | (float) Value = (EncodedValue * 0.5) - 1000, If decoded Value = -1000, then real value is unknown |
| 15..16(2) | Area Floor | Unsigned Int(float)(LE) | (float) Value = (EncodedValue * 0.5) - 1000, If decoded Value = -1000, then real value is unknown |
| 17 | UA Classification | [7..4][3..0] | will not be stored in the database since it is not necessary for tracking. |
| 18..19(2) | Operator Altitude | Unsigned Int(float)(LE) | (float) Value = (EncodedValue * 0.5) - 1000, If decoded Value = -1000, then real value is unknown |
| 20..23(4) | Timestamp | Unsigned Int(UInt32) | Time is in the following format =  00:00:00 01/01/1970 |
| 24 | Reserved |  |  |


## Interaction with the Website System
Whenever the data package is received, the database application will begin unpacking the data and storing it in the database then request the website for a drone operation access permission. The output return from the website shall be in Boolean which indicates if access is given or not.
| Data | Data type | Detail |
| -------- | ------------| -------- |
| Authorize Permission | Boolean | should return either a '0'(False) or '1'(True) |

If the user from the website system wants to access the data inside the SQL database, UAS ID will be provided with the associated data, latitude, Longitude, Geodetic Altitude, Speed, etc.

## Interaction with the Camera Software System
When drone operation permission is denied or when a drone is inside the priority zone pre-marked by the user, it will forward the following data to the Camera software system, and the Control Station latitude/longitude if available.
| Data | Data type | Detail |
| -------- | ------------| -------- |
| UAS latitude | Signed Int(Sint16_t)(double) |  |
| UAS Longitude | Signed Int(Sint16_t)(double) |  |
| UAS geodetic Altitude |Unsigned Int(Uint16_t)(double) |  |
| UAS speed |Unsigned Int(Uint8_t) | unit is m/s |
| UAS vertical speed | Signed Int(Uint8_t)(float) |  |
| Direction |Unsigned Int(Uint8_t) | 0-359(degree) |
| Control station latitude |Signed Int(Sint32_t)(double) |  |
| Control station Longitude |Signed Int(Sint32_t)(double) |  |
| Timestamp	| Unsigned Int(Uint8_t) | Hour + sescond |
| High priority area alert | Boolean | indication of drone within high priority area |
<br>
The following is the pseudocode code used to compare for the priority zone: <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;double matrix[256 = number of row][2 = number of Column]; {{min_latitude, min_longitude}...{max_latitude, max_longitude}} <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if(min_latitude< Drone_latitude < max_latitude) and if(min_longitude< Drone_Longitude < max_longitude) = TRUE; <br>
<br>

The received data from the camera are the following:
| Data | Data type | Detail |
| -------- | ------------| -------- |
| Image | raw file or PNG | There can be mulitple Image |
| Camera Health status | boolean | '0' indicate power is low |

## Coding language
The languages chosen to implement this program will be either Python or C++, Python will be mainly used for code to unpack the data package. C++ will be used if needed.

## Testing
To test the actual written code, a dummy data table fill with preset values will be created strictly for testing different scenarios.

## Case
Following show the size of the case <br>
![image](https://github.com/user-attachments/assets/d80729da-a689-467e-a400-b44025e74c8a) <br>
Comparing the physical specification[^3] of raspberry pi 5 to the case, the width of the case is 10mm wider and 7mm long than the raspberry pi 5.


## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
| Raspberry Pi 5 | B0CPWH8FL9(ASIN) | 1 | $89.99 | $89.99 |
| M.2 HAT+ | ‎B0D5CGDJLQ(ASIN) | 1 | $19.99 | $19.99 |
| KingSpec M.2 SATA SSD | ‎B01MR5O5YS(ASIN) | 1 | $23.39 | $23.39 |
| GeeekPi Metal Case for Raspberry Pi 5 | B0CMZ84GM8(ASIN) | 1 | $20.52 | $20.52 |
| JSAUX Micro HDMI to HDMI Adapter | ‎B09LYPXPH6(ASIN) | 1 | $7.19 | $7.19 |
|Total     |             |          |                |     $161.08    |

## References
<!-- This is how to do footnotes for the references: --> 
[^1]: “ASTM F34111-22a,” Standard Specification for Remote ID and Tracking, Available: https://cdn.standards.iteh.ai/samples/112830/71297057ac42432880a203654f213709/ASTM-F3411-22a.pdf (accessed Apr. 11, 2024). <br>
[^2]: “ANSI/CTA-2063-A,” Small Unmanned Aerial Systems Serial Numbers (accessed Apr. 24, 2024). <br>
[^3]: “Raspberry Pi 5,” Available: https://datasheets.raspberrypi.com/rpi5/raspberry-pi-5-product-brief.pdf (accessed Apr. 21, 2024). <br>
[^4]: "Theoretical Maximum Memory Bandwidth for Intel® Core™ X-Series Processors," Intel, Available: https://www.intel.com/content/www/us/en/support/articles/000056722/processors/intel-core-processors.html (accessed Sep. 12, 2024). <br>
[^5]: "LPDDR4x/LPDDR4 SDRAM," Micron, Available: https://www.mouser.com/datasheet/2/671/z4bm_embedded_lpddr4x_lpddr4-3193428.pdf?srsltid=AfmBOor0oFs9McWlLydE3Mhwnwi_MDB7D7KWG88pNntX05gi9FzJkEo0 (accessed Sep. 12, 2024). <br>
[^6]: "M.2 2242 SATA SSD," Kingston, Avaiable: https://www.kingston.com/en/industrial-ssd/m2-2242-sata?capacity=256gb&form%20factor=m.2%202242&interface=sata&nand=tlc&temperature=commercial (accessed Sep. 12, 2024). <br>
[^7]: “856 data security and handling policy,” Tennessee Technological University, Available: https://www.tntech.edu/policies/ [Accessed April. 29, 2024].
<!--etc.-->
