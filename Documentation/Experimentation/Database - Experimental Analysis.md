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
3. Use [upload speed tester](https://www.speedtest.net/result/17036840573) to check for upload speed, ideally we want the upload speed to be low as possible
4. Monitor and analyze the database to check for any missing data.

## Experimental Data - used for testing
![image](https://github.com/user-attachments/assets/9baf4e3d-ebf4-451b-8974-d45bd81dc4cc)
![image](https://github.com/user-attachments/assets/4cf7b2fa-40d4-4f78-b11c-7610b0900872)

As specified in the F3411-22a document, a package can hold a maximum of 10 messages, totaling 250 bytes (rest of the package fill with filler data). The example message above will be utilized to test both constraints, with message 2 and 3 within the package designated for verifying the priority zone.

## Experimental Data - result
<!-- data tables or graph of the results (whichever is appropriate) -->
|  list | id | speed | drone_latitude | drone_longitude | drone _altitude | timestamp | Send Location | upload Speed | Recevied? |
|--------|----------------|-------------------|------------|------------|------------|------------|------------|------------|----|
|    6   |  ABC   |  63.75|     13.5323056    | -70.4707824 | 500 | 2024-11-20 21:07:46 | Basement of Prescott Hall | 84.19 | Yes |
|    7   |  ABC   |  63.75|     45.0143984    | -128.5120208 | 500 | 2024-11-20 21:08:46 | Tennis Court behind the Library | 26.75 | Yes |


## Conclusions
#### Interpretation of Data
<!-- explain what the results of the experiments mean and what conclusions you draw -->

#### Final Thoughts
<!-- Were constraints met? -->
