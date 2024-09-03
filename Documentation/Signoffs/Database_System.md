# Database System
## Functionality
The database subsystem will receive data from the receiver, website and camera subsystem, then store it locally. Data stored will containt the following: pre-authorized drone ID, pre-authorized flight information, pre-marked geographical locations, drone ID, and the location, Latitude, Longitude of the drone and control station. Whenever a drone is detected by the receiver, the database will check for pre-authorized access releated to the received drone ID. If not authorized, then a request will be sent to the website system that asks the user for an authorize request. If authorization denied or drone detected within any pre-marked geographical locations, then the Drone location, speed and Control station location will be sent to the camera subsystem. Also, the database subsystem will provide data access for the website subsystem.

## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | The system shall fulfill data requests from the website system | Design Constraint |
|  2 | The system shall check for pre-authorized access for any drone's new flight session  | Design Constraint |
|  3 | For any drone without access permission, the system shall request authorized access from the website system. If access permission is denied the system shall forward any tracking information to the camera system | Design Constraint |
|  4 | If a drone enters a pre-marked priority zone, the system shall forward any tracking information to the camera system  | Design Constraint |
|  5 | The system shall indicate the health status of Camera system | Design Constraint |
|  6 | The system shall store the data for at least 90 days and let the user specify the time limit | TTU Policy/Design Constraint |
|  7 | The database shall be encrypted using a password | Design Constraint |
|  8 | The system shall be able to send and receive data packages using 2.4/5 GHz wifi or Ethernet | Design Constraint |
|  9 | The Device used to host the database shall have a casing that prevents direct physical interaction with the hardware | Design Constraint |

<sup>1</sup> 
The database system will receive an access request when the user clicks on a link from the website, once the access request is received the requested item will be pulled from the database and sent to the website system.

<sup>2</sup> 
When a new data package is received from the receiver system, the database will take the UAS ID and check for pre-authorized access.

<sup>3</sup> 
When a drone is detected by the receiver if the drone does not have pre-authorized access, the database system will send a notification to the website system that asks for authorized access, if the user denies the access, then the Drone location, Drong speed, Control station location will be sent to the camera system.

<sup>4</sup> 
Regardless if a drone has authorized permission or not the Drone location, drone speed, and Control station location will be sent to the camera system.

<sup>5</sup> 
A status indication that provides a simple breakdown of the health of the camera.

<sup>6</sup> 
If no time limit is selected by the user, the database will only store the data for 90 days.

<sup>7</sup> 
The password is used for security reasons that prevent unwanted access to the database.

<sup>8</sup> 
The Raspberry Pi 5 supports both Dual-band 802.11ac Wi-Fi and Gigabit Ethernet[3]. Ethernet connection will be the priority option.

<sup>9</sup> 
Even though the Raspberry Pi is going to be inside the building, a case will be designed to prevent any direct physical contact. For example, the storage drive won't be easily accessed by random person.

## Schematic
![image](https://github.com/mrnye42/Drone-Tracker-Project/assets/113947428/01cd0112-f276-4ddb-9253-85a3b34842e7)
This Figure show the Hardware connection

![image](https://github.com/mrnye42/Drone-Tracker-Project/assets/113947428/802b122a-8783-4b42-816a-d7d858e90202)


## Analysis
Once the database system receives a data package from the receiver system, it will break down the Message Block inside the data package and store the relevant information inside the SQL database, then take the UAS ID and check for authority access, if none are found then forward an authority access request to the website system. If access is denied or the drone is within the priority zone pre-marked by the user, then data related to the Drone location, drone speed, and Control station location will be forwarded to the camera software system, and the camera software system will return an image. All data received from another system will be stored inside a SQL database which is implemented on Raspberry Pi using MySQL, and the rest of the code that takes care of transferring data will be implemented using either C/C++ or Python.

## Setting up the Raspberry Pi
The device will be powered by 5V/5A DC power via USB-C, a power supply is included in the kit, and an external monitor is needed to monitor the device.

## Database



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

## Testing
To test the actual written code, a dummy data table fill with preset values will be created strictly for testing different scenarios.

## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
| Raspberry Pi 5 | 2648-SC1112-ND | 1 | $80 | $80 |
| GeeekPi N04 M.2 NVMe to PCIe Adapter | B0CRK4YB4C(ASIN) | 1 | $14.39 | $14.39 |
| Patriot P300 M.2 128GB | ‎P300P128GM28 | 1 | $17.99 | $17.99 |
|Total     |             |          |                |     $112.38    |

## References
<!-- This is how to do footnotes for the references: --> 
[1] “ASTM F34111-22a,” Standard Specification for Remote ID and Tracking, https://cdn.standards.iteh.ai/samples/112830/71297057ac42432880a203654f213709/ASTM-F3411-22a.pdf (accessed Apr. 11, 2024). <br>
[2] “ANSI/CTA-2063-A,” Small Unmanned Aerial Systems Serial Numbers (accessed Apr. 24, 2024). <br>
[3] “Raspberry Pi 5,” https://datasheets.raspberrypi.com/rpi5/raspberry-pi-5-product-brief.pdf (accessed Apr. 27, 2024). <br>
<!--etc.-->