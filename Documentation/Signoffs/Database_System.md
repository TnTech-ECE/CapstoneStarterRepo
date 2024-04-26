# Database System
## Functionality
The database subsystem will receive the drone remote ID package capture by the receiver subsystem, then it will forward the necessary data to the camera software and website subsystem depending on the user input from the website subsystem.

## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | The system shall breakdown any received data package and organize it in a structured format for usability | Design Constraint |
|  2 | The system shall complete the user's requet from the website subsystem | Design Constraint |
|  3 | The system shall request authorized drone operation access from the website subsystem if a drone signal is received from the receiver subsystem  | Design Constraint |
|  4 | The system shall forward the necessary datas to the camera software subsystem if authrozied access is denied | Design Constraint |
|  5 | The system shall forward the necessary datas to the camera software subsystem if a drone is detected inside of priority zones selected by the user | Design Constraint |

<sup>1</sup> 
When a data package is received from the receiver, website or camera subsystem, it shall store all the infomration in a structured format so it can be easily accesss when datas is being request by user.

<sup>2</sup> 
Whenever the user open a link to observe datas, the database subsystem shall be able to provide the specified requested datas from the website.

<sup>3</sup> 
When data package is received, and drone is within the contiguous campus area it should alert authority and request a drone operation acess permission.

<sup>4</sup> 
If drone operation acess permission is denied by authority, then information related to the UA or UA pilot shall be send to the camera software system.

<sup>5</sup> 
If a drone enter a pority zone selected by the user, then information related to the UA or UA pilot shall be send to the camera software system.

## Schematic
![image](https://github.com/mrnye42/Drone-Tracker-Project/assets/113947428/5b6f99ab-53b6-4579-a206-89b2a3e235b2)


## Analysis
Once the database subsystem receive a data package from the receiver subsystem, it will break the Message Block inside the datapackage and store inside the SQL database, and request drone operation access authority from the website subsystem and forward UID and control station data to the camera software subsystem, then camera softerware subsystem will return a image. All data will be store inside a SQL database which is implemented on Raspberry Pi using MySQL which will act as a local storage, and this coding language used to implement this will be Structured Query Language (SQL), and rest the code that take care of transferring the data will be implemented using either C/C++ or python.

## Block Message
If a drone remote ID signal is captured by the receiver system, database subsystem will receive a packaged data from the receiver system, inside the package there are multiple block message, the block message is 25 bytes in length with a 1 byte header followed by 24 bytes of data. When the block message is decoded, the 1 byte message header will specify the message type, and it could contain the following datas: Basic ID message(0x0), Location/Vector Message(0x1), and the following is optional, Authentication Message(0x2), Self-ID Message(0x3), System Message(0x4), Operator ID(0x5), Message Pack(0xF)[^1].

Note: For all block message, it will be in big endian format, unless specify to be little endian(LE) format.

The Basic ID message will provides UAS ID, and characterizes the type of ID, and identifies the type of UA.
| Byte(length)| Data Field | Data type | Detail |
| -- | --------- |--------|---------|
|  1 | [ID Type][UA Type] | [7..4][3..0] bits | UA Type detail will be in table 1. |
|  2..22(20) | UAS ID | [20 Byte(4 bits per character)] | UAS ID within the format of ID Type (Padded with nulls) |    
|  23..24(3) | Reserved |  |  |


UAS ID consists of four options: Serial number(CTA-2063-A Serial Number format), Registration ID, UTM(UUID), specific session ID.
0. None
1. According to ANSI(Approved American National Standards), the serial number have the following format, SN = [4 Character manufacturer(MFR) cdoe][1 Character length code][15 Character MFR's serial nmumber]. The MFR code include a combination of digits and uppercase letters, except the letters O and I. The length code is a single character that range from 1 to 15, A to F will correspond to 10 to 15 respectively. MFR's serial number length is determine by the charcter length code, which include combination of digits and uppercase letters, except the letters O and I, but may include all digits[^2].
2. Registration ID shall be in the following format: [ICAO Nationality Mark].[CAA Assigned ID], ASCII encoded. The ICAO Nationality Mark is only uppercase Letters(A-Z), follow by a dot then digits(0-9) and CAA Assigned ID will be in digits (0-9).
3. UTM will provide a 128-bits universal unique ID the length of group is 8-4-4-4-12 that include a combination of letters and digit (0-9), and the UUID are fixed length.
4. specific seesion ID will be 20 byte, with the the first byte used as the unique identifier, and the remaining 19 bytes provide the session ID.


Table 1: UA Type
| Decimal | Bits | Detail |
| -- | --------- |--------|
| 0 | 0000 | None/Not Declared |
| 1 | 0001 | Aeroplane |
| 2 | 0010 | Helicopter (or Multirotor) |
| 3 | 0011 | Gyroplane |
| 4 | 0100 | Hybrid Lift |
| 5 | 0101 | Ornithopter |
| 6 | 0110 | Glider |
| 7 | 0111 | Kite |
| 8 | 1000 | Free Ballon|
| 9 | 1001 | Captive Ballon |
| 10 | 1010 | Airship (such as a blimp) |
| 11 | 1011 | Free Fall/Parachute (unpowered) |
| 12 | 1100 | Rocket |
| 13 | 1101 | Tethered Powered Aircraft |
| 14 | 1110 | Ground Obstacle |
| 15 | 1111 | Other |


The Location/Vector Message type provides the location, altitude, direction, and speed of UA.
| Byte(length) | Data Field | Data type | Detail |
| -- | --------- |--------|---------|
| 1 | [Operational StatusStatus][Reserved][Height Type][Direction Segment][Speed multiplier] | [7..4][3][2][1] bits | bits(7..4) will provide the operational Status (table 1), bits(3) is Reserved, bits(2) identify the height type: 0 is above takeoff and 1 is above ground level, bits(1) provide the direction Segment: 0 is less than 180 degree and 1 is greater than or equal to 180, bits(0) provide the speed mulitiplier: 0 will multiply the speed by 0.25 and 1 will multiply the speed by 0.75. |
| 2 | Track Direction | Unsigned Int | data type is 0-359 Unsigned Int(Uint) if flag bits(1) is 1 then 180 will need be added to the Encoded Value, other wise the encoded value will be the final value. |
| 3 | Speed | Unsigned Int | If flag bits(0) is 0 the Value = EncodedValue * 0.25, if flag bits(0) is 1 then the Value = (EncodedValue * 0.75) + (255 * 0.25) |
| 4 | Vertical | Float | (Float) Value = EncodedValue * 0.5 |
| 5..8(4) | Latitude | Signed Int(double)(LE) | (double) Value = EncodedValue/(10^7) |
| 9..12(4) | Longitude | Signed Int(double)(LE) | (double) Value = EncodedValue/(10^7) |
| 13..14(2) | Pressure Altitude | Unsinged Int(Float)(LE) | (float) Value = (EncodedValue * 0.5) - 1000, If decoded Value = -1000, then real value is unknown |
| 15..16(2) | Geodetic Altitude | Unsinged Int(Float)(LE) | (float) Value = (EncodedValue * 0.5) - 1000, If decoded Value = -1000, then real value is unknown |
| 17..18(2) | Height | Unsinged Int(Float)(LE) | (float) Value = (EncodedValue * 0.5) - 1000, If decoded Value = -1000, then real value is unknown |
| 19 | [Vertical(Geodetic) Accuracy][Horizontal Accuracy] | [7..4][3..0] bits | Detail in Table 3 and 4 |
| 20 | [Baro Altitude Accuracy][Speed accuracy] | [7..4][3..0] bits | Baro Altitude accuracy is in detail in Table 3, and speed accuarcy is in Table 5. |
| 21..22(2) | Timestamp | Unsigned Int(LE) | Value = Current UTC Data/time (Hour) + ValueTenths (of seconds) |
| 23 | [Reserved][Timestamp accuracy] | [7..4][3..0] bits | 0 to 15, A to F will correspond to 10 to 15 respectively. 0 will be unknown(NULL) |
| 24 | Reserved |  |  |


Sudo code For Timestamp: 
If Encoded Value > Tenths of seconds since the current hour at time of receipt <br>
then <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Value Tenths = tenths of seconds since previous hour <br>
else <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ValueTenths = tenths of seconds since current hour <br>


Table 2: Operational Status
| Decimal | Bits | Detail |
| -- | --------- |--------|
| 0 | 0000 | Undeclared |
| 1 | 0001 | Ground |
| 2 | 0010 | Airborne |
| 3 | 0011 | Emergency |
| 4 | 0100 | Remote ID System Failure |
| 5..15 | 0101..1111 | Reserved |


Table 3: Vertical Accuracy
| Decimal | Bits | Detail |
| -- | --------- |--------|
| 0 | 0000 | greater than or equal to 150 m or Unknowkn |
| 1 | 0001 | less than 150 m |
| 2 | 0010 | less than 45 m |
| 3 | 0011 | less than 25 m |
| 4 | 0100 | less than 10 m |
| 5 | 0101 | less than 3 m |
| 6 | 0110 | less than 1 m |
| 7..15 | 0111..1111 | Reserved |


Table 4: Horizontal Accuracy
| Decimal | Bits | Detail |
| -- | --------- |--------|
| 0 | 0000 | greater than or equal to 18.52 km (10 NM) or Unknowkn |
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


Table 5: Speed Accuracy
| Decimal | Bits | Detail |
| -- | --------- |--------|
| 0 | 0000 | greater than or equal to 10 m/s or Unknowkn |
| 1 | 0001 | less than 10 m/s |
| 2 | 0010 | less than 3 m/s |
| 3 | 0011 | less than 1 m/s |
| 4 | 0100 | less than 0.3 m/s |
| 5..15 | 0101..1111 | Reserved |


The System Message type provides the Operator Latitude, Operator Longitude, AreadCount, Area Radius, Area Ceiling, Area floor, UA classification, Operator Altitude, Timestamp.
| Byte(length) | Data Field | Data type | Detail |
| -- | --------- |--------|---------|
| 1 | [Reserved][Classification Type][Operator Location/Altitude Source type] | [7..5][4..2][1..0] bits | For Classification Type, 0(000 bits) = Undeclared, 1(0001 bits) = European Union, 2..7(010..111 bits) = Reserved. For Operator Location/Altitude Source type, if 0(00 bits) = Take off, 1(01 bits) = Dynamic, 2(10 bits) = Fixed |
| 2..5(4) | Operator Latitude | Signed Int(double)(LE) | (double) Value = EncodedValue/(10^7) |
| 6..9(4) | Operator Longitude | Signed Int(double)(LE) | (double) Value = EncodedValue/(10^7) |
| 10..11(2) | AreaCount | Unsigned Int(LE) | default 1, but can have max up to 65,000. |
| 12 | Area Radius | Unsigned Int | Radius of cylindrical area of group or formation * 10 m (default 0) centered on Location/Vector Message position |
| 13..14(2) | Area Ceiling | Unsigned Int(float)(LE) | (float) Value = (EncodedValue * 0.5) - 1000, If decoded Value = -1000, then real value is unknown |
| 15..16(2) | Area Floor | Unsigned Int(float)(LE) | (float) Value = (EncodedValue * 0.5) - 1000, If decoded Value = -1000, then real value is unknown |
| 17 | UA Classification | [7..4][3..0] | When Classification Type is 1, encoded as table 6 and 7 |
| 18..19(2) | Operator Altitude | Unsigned Int(float)(LE) | (float) Value = (EncodedValue * 0.5) - 1000, If decoded Value = -1000, then real value is unknown |
| 20..23(4) | Timestamp | Unsigned Int(UInt32) | Time is in the following format =  00:00:00 01/01/1970 |
| 24 | Reserved |  |  |


Table 6: Category
| Decimal | Bits | Detail |
| -- | --------- |--------|
| 0 | 0000 | Undefined |
| 1 | 0001 | Open |
| 2 | 0010 | Specific |
| 3 | 0011 | Certified |
| 4..15 | 0100..1111 | Reserved |


Table 7: Class
| Decimal | Bits | Detail |
| -- | --------- |--------|
| 0 | 0000 | Undefined |
| 1 | 0001 | Class 0 |
| 2 | 0010 | Class 1 |
| 3 | 0011 | Class 2 |
| 4 | 0100 | Class 3 |
| 5 | 0101 | Class 4 |
| 6 | 0110 | Class 5 |
| 7 | 0111 | Class 6 |
| 8..15 | 1000..0111 | Reserved |

## Interaction with the Website Subsystem
Whenever data package is received, database application will begin unpacking the data and storing in the database then request website with for a drone operation access permission. The output return from the website shall be in Boolean which indicate if access is given or not.
| Data | Data type | Detail |
| -------- | ------------| -------- |
| Authorize Permission | Boolean | should return either a '0'(False) or '1'(True) |


## Interaction with the Camera Software Subsystem
When drone operation permission is deny or when a dron is inside the prioty zone marked by the user, it will forward the following data to the Camera software subsystem, and Control Station latitude/longitude is optional.
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

## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
| Raspberry Pi 5 | 2648-SC1112-ND | 1 | $80 | $80 |
|Total     |             |          |                |     $80    |

## References
<!-- This is how to do footnotes for the references: --> 
[1] “ASTM F34111-22a,” Standard Specification for Remote ID and Tracking, https://cdn.standards.iteh.ai/samples/112830/71297057ac42432880a203654f213709/ASTM-F3411-22a.pdf (accessed Apr. 11, 2024). 
[2] “ANSI/CTA-2063-A,” Small Unmanned Aerial Systems Serial Numbers (accessed Apr. 24, 2024).
<!--etc.-->
