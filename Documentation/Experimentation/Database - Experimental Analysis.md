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
- (more detail is describe in [Methods for testing constraint 1](#Methods-for-testing-constraint-1): 
1. Generate a packet with a maximum size of 250 bytes, plus a 9-byte header.
2. Send the drone packet.
3. Develop a method to calculate the total processing time once a packet is received.
4. Monitor and evaluate the overall time taken to process the data.

### Constraints 2
- Number of trials: 2
1. Relocate to a site different from where the database is installed.
2. Transmit the drone packet.
3. Use [upload speed tester](https://www.speedtest.net/result/17036840573) to check for upload speed, ideally we want the upload speed to be low as possible
4. Monitor and analyze the database to check for any missing data.

## Experimental Data - used for testing
![image](https://github.com/user-attachments/assets/9baf4e3d-ebf4-451b-8974-d45bd81dc4cc)
![image](https://github.com/user-attachments/assets/4cf7b2fa-40d4-4f78-b11c-7610b0900872)

As outlined in the F3411-22a document, a packet can contain up to 10 message block, with a total size of 250 bytes (the remaining space filled with filler data). The example message above will be used to test both constraints, with messages 2 and 3 in the packet designated for validating the priority zone.

#### Methods for testing constraint 1
- Method 1:
1. Only Example Message 2 will be included within the 259-byte packet.
2. Message 2 will be placed in the 10th block.
3. f the processing time exceeds 100ms, move Message 2 to the 5th block.
4. If the processing time is close to 100ms, move Message 2 down by one block (from block 5 to 6) until the processing time exceeds 100ms.

- Method 2:
1. Both Message 2 and Message 3 will be included within the 259-byte packet.
2. Message 2 will be placed in the 6th block, while Message 3 will be placed in the 10th block.
3. If the processing time exceeds 100ms, move Message 3 to the 6th block.
4. If the processing time still exceeds 100ms, shift both Message 2 and Message 3 up by one block (from block 6 to 5), and continue shifting until the processing time is less than 100ms.

- Method 3:
1. fill a full pecket with with every drone location detecetd inside the priority zone.

### Data Recored Example (method 1)
![20241120_23h44m05s_grim](https://github.com/user-attachments/assets/42294710-e2f3-4cc9-a73a-31c25a926a77)
![20241121_00h25m49s_grimexampel2](https://github.com/user-attachments/assets/aba9ffc2-9d39-44ef-b7cf-4d1f93b6d3a8)


#### Data Recored Example (method 2)

#### Data Recored Example (Method 3)
![20241120_23h44m05s_grim](https://github.com/user-attachments/assets/42294710-e2f3-4cc9-a73a-31c25a926a77)
![20241120_23h48m28sss_grim](https://github.com/user-attachments/assets/0db99c64-44ad-4b03-888d-0d5e3418b2eb)

## Experimental Data - result
<!-- data tables or graph of the results (whichever is appropriate) -->
### Constraint 1 result(first run):
|  Method used | block location | Process time | <100ms |
|--------------|----------------|--------------|--------|
|  3 | Process time | 2 | 10 ms |
|  3 | Process time | 3 | 18 ms |
|  3 | Process time | 4 | 29 ms |
|  3 | Process time | 5 | 44 ms |
|  3 | Process time | 6 | 58 ms |
|  3 | Process time | 6 | 69 ms |
|  3 | Process time | 6 | 78 ms |
|  3 | Process time | 6 | 85 ms |
|  3 | Process time | 6 | 91 ms |

### Constraint 1 result(second run):
|  Method used | block location | Process time | <100ms |
|--------------|----------------|--------------|--------|
|  3 | Process time | 2 | 14 ms |
|  3 | Process time | 3 | 25 ms |
|  3 | Process time | 4 | 51 ms |
|  3 | Process time | 5 | 77 ms |
|  3 | Process time | 6 | 86 ms |
|  3 | Process time | 6 | 109 ms |
|  3 | Process time | 6 | 117 ms |
|  3 | Process time | 6 | 125 ms |
|  3 | Process time | 6 | 134 ms |

### Constraint 2 result:
|  list | id | speed | drone_latitude | drone_longitude | drone _altitude | timestamp | Send Location | upload Speed | Recevied? |
|--------|----------------|-------------------|------------|------------|------------|------------|------------|------------|----|
|    6   |  ABC   |  63.75 m/s |     13.5323056    | -70.4707824 | 500 meter | 2024-11-20 21:07:46 | Basement of Prescott Hall | 84.19 Mbps | Yes |
|    7   |  ABC   |  63.75 m/s|     45.0143984    | -128.5120208 | 500 meter | 2024-11-20 21:07:46 | Tennis Court behind the Library | 26.75 Mbps | Yes |


## Conclusions
#### Interpretation of Data
<!-- explain what the results of the experiments mean and what conclusions you draw -->

#### Final Thoughts
<!-- Were constraints met? -->
