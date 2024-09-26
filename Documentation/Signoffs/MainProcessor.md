**Function:**

The primary function of the Raspberry Pi 4 in this project is to serve as the central processing unit for receiving, processing, and interpreting data from multiple sources—wireless transmitters receiving signals from sensors and a local sensor. The Raspberry Pi 4 acts as the brain of the system, centralizing the data and analysis of data related to a golf ball's trajectory. The board’s goal is to perform calculations to determine the velocity, height, distance, and direction of the golf ball in real-time.

The Raspberry Pi 4 plays a crucial role in controlling the golf ball interceptor’s firing mechanism. By processing the collected data, it calculates the optimal timing to activate the interceptor, making sure that it aims accurately at the golf ball during its flight path on the strings, particularly at the designated "kill zone."

![System](../Images/RaspberryPi4OutlineNew.png)
Figure 1: Raspberry Pi 4 B Wiring scematic.

**Constraints:**

| NO. | Constraint                                                          | Origin           |
|-----|---------------------------------------------------------------------|------------------|
| 1 | Time Constraints - Receive and calculate data and predict golf ball projectory| System Constraint |
| 2 | Processing Speed - Optimizing code for a faster processing speed  | System Constraint |
| 3 | Signal Interpretation Challenges - Turning all the incoming signals into readable data | Programing Constraint |
| 4 | Resource Utilization - Not overloading board memory | System Constraint |

**Fulfilling Constrains:**

Time Constraints: Real-time processing of sensor data and trajectory calculations impose time constraints on the Raspberry Pi 4. Since the processor on the Raspberry Pi 4 runs at 1.5GHz, the processor needs to be able to receive, process, calculate the interceptor’s path, and aim the interceptor before the golf ball gets too far down the string. The programs and data transmission needs to be optimized for an accurate and efficient system to be able to run fast enough. Delays in data acquisition, processing, or interceptor firing may affect the interception accuracy dramatically.

Processing Speed: Complex calculations and simultaneous tasks may strain the processing capabilities of the Raspberry Pi 4, potentially leading to performance bottlenecks. Optimizing algorithms and utilizing hardware and the multi-core techniques can help minimize processing speed limitations.

Signal Interpretation Challenges: Variability in wireless signal strength, interference, and environmental factors may pose challenges in accurately interpreting sensor data. The Raspberry Pi needs to be able to filter all signals, determine accurate data that it receives and predict the golf balls trajectory will require enormous testing and a versatile system. A accurate signal processing algorithm and error-handling backup codes are going to be essential for creating reliable data for the system.

Resource Utilization: Memory resources of the Raspberry Pi 4 is going to have 4 gigabytes of ram. Making sure the scripts, and all input data processing does not overload the board is going to be hard for the multiple scripts that will be required for all controls. It is necessary to make all scripts efficient. There are focuses on not creating memory leaks, excessive CPU usage, or inefficient code may slow the Raspberry Pi 4’s performance and responsiveness.



**Execution Using Raspberry Pi 4:**

Python will serve as the primary programming language for developing software to interface with the Raspberry Pi 4. Its ease of use, extensive libraries, and compatibility with Raspberry Pi's components make it the best choice for prototyping and developing a reliable system. However, for slow tasks or specific requirements, there is a possibility of utilizing C++ for optimized code execution, such as calculations or motor controls.

Hardware Configuration: Utilizing the GPIO (General Purpose Input Output) pins of the Raspberry Pi 4, wireless transmitters' signals from the sensors are received and processed. Additionally, a local sensor's signal is directly interfaced with the Raspberry Pi for additional real-time data. For interfacing with sensors and controlling the interceptor, GPIO pins GPIO2, GPIO3, GPIO4, GPIO17, GPIO27, and GPIO22 are recommended due to their accessibility and versatility. These pins support input/output functionalities and can be configured for various tasks through the code inside the control unit.

Programs and Tasks: Custom programs are developed to handle various tasks, including signal processing, data interpretation, and trajectory calculations. Python programming language is commonly used for its flexibility and compatibility with the Raspberry Pi ecosystem. Tasks are organized into threads or processes to manage concurrent operations efficiently.

Data Processing and Calculations: Upon receiving sensor signals, the Raspberry Pi 4 performs calculations to determine the golf ball's velocity, height, distance, and direction. There will be test data that could be used for faster calculating speeds. These calculations will use math algorithms and pre-set data points, from testing the system.

Signal Interpretation: The Raspberry Pi 4 interprets wireless signals received from the sensors, using the data points related to the golf ball's motion. Signal processing techniques are employed to filter noise, create a higher signal clarity, and extract only the useful information.

Control of Golf Ball Interceptor Shooter: Based on the calculated trajectory data, the Raspberry Pi 4 will control the timing and activation of the golf ball interceptor shooting mechanism. It needs to have the interceptor to be properly aligned towards the golf ball's predicted path, and fire at the appropriate time to hit the ball mid-air. This could use preset fire positions to optimize the interception process.

**Integration**

In addition to its role in processing sensor data and trajectory calculations, the Raspberry Pi 4 will integrate with a TB6600 Stepper Motor Driver to control the interceptor's aiming mechanism. This stepper motor driver controls the interceptor's movements, allowing for accurate alignment with the golf ball's predicted path.

Upon receiving data from the wireless communicator, the Raspberry Pi 4 will execute commands to adjust the stepper motors to a specific location, aligning the interceptor with the incoming golf ball. The Python scripts running on the Raspberry Pi will translate trajectory calculations into precise motor movements.

The TB6600 Stepper Motor Driver's compatibility with the Raspberry Pi's GPIO pins will enable easy communication and control of the system.

**Cost Analysis:**

| Name	| Count |	Price	|	Total |
|-------|-------|-------|-------|
| RASPBERRY PI 4 B 4GB |	1 |	$55.00	|	$55.00 |
| TB6600 Stepper Motor Driver | 3 | $20.00 | $60.00 |
| | | | $115.00 |

The Raspberry Pi 4 board is priced at $55.00 from DigiKey, serving as a cost-effective control unit for the project. The overall cost should remain relatively low compared to alternative solutions, making the Raspberry Pi 4 a big beneficial choice for the project's budget.

**References:**

[1] “SC0194(9) raspberry pi | embedded computers | DigiKey,” DigiKey, https://www.digikey.com/en/products/detail/raspberry-pi/SC0194-9/10258781 (accessed Apr. 7, 2024). 

[2] “Raspberry pi 4 model B specifications – raspberry pi,” Raspberry Pi, https://www.raspberrypi.com/products/raspberry-pi-4-model-b/specifications/ (accessed Apr. 7, 2024). 

[3] “TB6600 Stepper Motor Driver,” Bulkman, https://bulkman3d.com/wp-content/uploads/2019/06/TB6600-Stepper-Motor-Driver-BM3D-v1.1.pdf (accessed Apr. 8, 2024). 

[4] “TB6600 Stepper Motor Driver,” DFRobot, https://www.dfrobot.com/product-1547.html (accessed Apr. 8, 2024). 


