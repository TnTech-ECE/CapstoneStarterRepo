# Database System
## Functionality
The database subsystem will receive the drone remote ID package capture by the receiver substem, then it will forward the requested data to the camera software and website subsystem.

## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | All data recevied shall be contained in a database storage. | TTU Campus Police |
|  2 | The database application used to store the drone remote ID shall handle real-time data streaming. | Design Constraint |    
|  3 | Application shall constantly request and receive data from the receiver subsystem. | Design Constraint |
|  4 | Application shall provide the data when requested by another subsystem. | Design Constraint |

<sup>1</sup> 
The TTU campus police requested all the obtained drone remote ID data to be stored in cloud storage.

<sup>2</sup> 
Other subsystems have inputs dependent on live information whenever a drone is detected whithin the campus area.

<sup>3</sup> 
Constantly requesting updates for drone detection will ensure that possible packet lost or poor network connection related issues are caught early. It will also ensure that the data supplied to the cloud is current. 

<sup>4</sup> 
The website and camera subsystem will request/pull data from the database subsystem whenever a drone is detected.

## Schematic
![image](https://github.com/mrnye42/Drone-Tracker-Project/assets/113947428/3ba8fc14-7e0f-4cbe-b26b-8a761d125e5b)
![image](https://github.com/mrnye42/Drone-Tracker-Project/assets/113947428/fab463f7-9778-4e9d-abe5-add71418a55c)

## Analysis
If a drone remote ID signal is captured by the receiver system, the drone will sent off a block message every second, the block message is 25 bytes in length with a 1 byte header followed by 24 bytes of data. When the block message is decoded, the 1 byte message header will specify the message type, and it could contain the following datas: Basic ID message(0x0), Location/Vector Message(0x1), and the following is optional, Authentication Message(0x2), Self-ID Message(0x3), System Message(0x4), Operator ID(0x5), Message Pack(0xF)[1].

The Basic ID message will provides UAS ID, and characterizes the type of ID, and identifies the type of UA. the least significant byte(3 downto 0 bits) will be used to identify the UA type ranging from 0 to 15, A to F will correspond to 10 to 15 respectively, then the second byte(7 downto 4 bits) will identify the ID type, and UAS ID can contain up to max of 20 Bytes padded with NULLS, and the last three bytes being reserved.

UAS ID consists of four options: Serial number(CTA-2063-A Serial Number format), Registration ID, UTM(UUID), specific session ID.
0. None
1. According to ANSI(Approved American National Standards), the serial number have the following format, SN = [4 Character manufacturer(MFR) cdoe][1 Character length code][15 Character MFR's serial nmumber]. The MFR code include a combination of digits and uppercase letters, except the letters O and I. The length code is a single character that range from 1 to 15, A to F will correspond to 10 to 15 respectively. MFR's serial number length is determine by the charcter length code, which include combination of digits and uppercase letters, except the letters O and I, but may include all digits[2].
2. Registration ID shall be in the following format: [ICAO Nationality Mark].[CAA Assigned ID], ASCII encoded. The ICAO Nationality Mark is only uppercase Letters(A-Z), follow by a dot then digits(0-9) and CAA Assigned ID will be in digits (0-9).
3. UTM will provide a 128-bits universal unique ID the length of group is 8-4-4-4-12 that include a combination of letters and digit (0-9), and the UUID are fixed length.
4. specific seesion ID will be 20 byte, with the the first byte used as the unique identifier, and the remaining 19 bytes provide the session ID.

The Location/Vector Message type provides the location, altitude, direction, and speed of UA. Byte order goes from 24 dwonto 1.
1. Byte 1 is used for status and flag, bits(7 downto 4) will provide the operational Status, bits(3) is Reserved, bits(2) identify the height type: 0 is above takeoff and 1 is above ground level, bits(1) provide the direction Segment: 0 is less than 180 degree and 1 is greater than or equal to 180, bits(0) provide the speed mulitiplier: 0 will multiply the speed by 0.25 and 1 will multiply the speed by 0.75.
2. Byte 2 is used to track direction, data type is 0-359 Unsigned Int(Uint) if flag bits(1) is 1 then 180 will need be added to the Encoded Value, other wise the encoded value will be the final value.
3. Byte 3 is used for speed, data type is Unsigned Int(Uint) and it goes up to max of 254.25 m/s, if flag bits(0) is 0 the Value = EncodedValue * 0.25, if flag bits(0) is 1 then the Value = (EncodedValue * 0.75) + (255 * 0.25).
4. Byte 4 is used for Vertical speed, data type is Float and up to 62 m/s( positive and engative), (Float) Value = EncodedValue * 0.5.
5. Byte 8 downto 5 is used for Latitude(4 bytes), data type is Signed Int(double), (double) Value = EncodedValue/(10^7).
6. Byte 12 downto 9 is used for Longitude(4 bytes), data type and equation used to obtain acutal value is the same as LAtitude.
7. 







The following data will be pulled by the Website subsystem if available: Drone remote ID, location/Altitude, Velocity, control station location/elevation, operation time mark, emergency status, and Drone/Control station image. The Database system will be implemented using a SQL(Structured Query Language), python and c++. Test case senarios for the Database subsystem are provided below.

## SQL, python and C++
SQL will be used to format the data inside of the database storage, then, python or C++ code will be implemented to handle the data receiving/requesting.

## Test Case Senario
The database application will constantly request updates from the receiver subsystem whether a drone is detected or not.<br />  
When a drone is not detected: Wait a certain time period before requesting another update.<br /> 
When a drone is detected: Then the following information is stored: ID, location/altitude, velocity, control station location/elvation, time mark of operation, and emergency status.<br /><br />

When a drone is detected within the campus area, the application will forward an alert to the website subsystem that will ask TTU campus police to provide the drone authorization.<br />
When Drone operation authorization is provided: Update the drone operaton authorization status.<br /> 
When Drone operation authorization is not provided: Wait a certain period then reforward another alert.<br /><br />

When a drone is detected within the campus area, the following will happen based on the existance of a request from the camera software subsystem.<br />
When a drone is not detected: Reply with a negative boolean value.<br /> 
When a drone is detected: The following information is forwarded: drone location/altitude, drone velocity, and control station location/elvation.<br />

## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
| Cloud server | N/A | 1 | N/A | N/A |
|Total     |             |          |                |            |

## References
<!-- This is how to do footnotes for the references: --> 
[1] “ASTM F34111-22a,” Standard Specification for Remote ID and Tracking, https://cdn.standards.iteh.ai/samples/112830/71297057ac42432880a203654f213709/ASTM-F3411-22a.pdf (accessed Apr. 11, 2024). 
[2] “ANSI/CTA-2063-A,” Small Unmanned Aerial Systems Serial Numbers (accessed Apr. 24, 2024).
<!--etc.-->
