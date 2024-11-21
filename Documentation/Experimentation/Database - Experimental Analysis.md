# Database - Experimental Analysis
## Experiment Description
### Summary
Taking potential interference into account, the database must reliably receive drone packets from the receiver system regardless of its location on campus. Furthermore, when handling a drone packet of maximum byte size, the system's processing time must remain within the defined time limit.

#### Subsystem(s) Involved:
Database Subsystem

#### Constraints Tested:
- Constraints 1 - If a drone enter a pre-marked geographical locations, then the drone location, drone speed and control station location will be sent to the camera subsystem.
- Constraints 2 -  The system shall support data transfer over the network.
 
#### Expected Result(s):
- Constraints 1 - Considering the maximum byte size of the drone packet, the system should detect a drone entering a predefined geographical location within 100 milliseconds.
- Constraints 2 - The database will be capable of receiving a packet from a receiver situated in a separate building.

## Experimental Procedure
<!-- Description of what you did ideally in steps -->
### constraints 1
- Number of trials:
1. Step 1
2. Step 2

### Constraints 2
- Number of trials: 2
1. Relocate to a site different from where the database is installed.
2. Transmit the drone packet.
3. Monitor and analyze the database to check for any missing data.

## Experimental Data - used for testing
   vector<uint8_t> message = {
        0x3A, 0xFA, 0x0B, 0xBC, 0x0D, 0x00,         // NAN Synchronization Beacon Frame, Vendor specific tag header Bytes
        0xF0, 0x19, 0x02,                           // Open Drone ID message pack header

   // Message 1
        0x02, 0x10,                                 // Message type and version type of message pack 1
        0x41, 0x42, 0x43, 0x44, 0x46,               // drone id padded with NULL, the id should be ABCD123456
        0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00,

   // Message 2 - value are made up
        0x12,  // Message Header (Upper 4 bits for Message Type 0x1, lower 4 bits for protocol version)
        0x02,  // Status/Flags byte (Direction Segment and Multiplier Flag)
        0x45,  // Direction byte = 69 degrees
        0x60,  // Speed byte (Multiplier flag = 0, so we will multiply by 0.25)
        0x00,  // Vertical speed, but not used
        0x08, 0x10, 0xDD, 0xB0,  // Latitude (Encoded as 4 bytes)  = 13.560200
        0xD5, 0xFF, 0x03, 0x10,  // Longitude (Encoded as 4 bytes) = -70.455600
        0x0B, 0xB8,  // pressure Altitude (Encoded as 2 bytes) = 500 meters
        0x0B, 0xB8,  // pressure Altitude (Encoded as 2 bytes) = 500 meters, however it is not used, but might be considered for a more accurate altitude reading
        0x00, 0x00, 0x00, 0x00,  // Height, Vertical/Horizontal accuracy, Baro Altitude is also not used
        0x12, 0x34,  // Timestamp (Encoded as 2 bytes) = year-month-day hr:min:day (UTC)
        0x00, 0x00   // Reserved/Timestamp Accuracy which is not used
    };

As specified in the F3411-22a document, a package can hold a maximum of 10 messages, totaling 250 bytes. The example message above will be utilized to test both constraints, with message 2 within the package designated for verifying the priority zone.

## Experimental Data - result
<!-- data tables or graph of the results (whichever is appropriate) -->

## Conclusions
#### Interpretation of Data
<!-- explain what the results of the experiments mean and what conclusions you draw -->

#### Final Thoughts
<!-- Were constraints met? -->
