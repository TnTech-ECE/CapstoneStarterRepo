# Processing Subsystem

## Function of the Subsystem

<img width="728" alt="Screen Shot 2023-04-04 at 3 25 34 PM" src="https://user-images.githubusercontent.com/123997954/229912228-53e792c0-7cce-496a-ace8-6fa46197ea0d.png">
The goal of this subsystem is to process the input signal, and output an appropriate response to the ambient noise present in the room. The processing subsystem consists of an ADC converter which will take the input and convert it into digital samples which will be analyzed and processed by the adaptive filter algorithms. The output will then be converted using a DAC converter and outputted to the other parts of the system.

## Constraints

| No. | Specifications and Constraints                     | Origin          |
| --- | -------------------------------------------------- | --------------- |
| 1   | Shall be powered from wall outlet                  | Specification   |
| 2   | Shall process and output information within 1.4 ms | Specification   |
| 3   | Shall process sounds at a rate of at least 40 kHz  | Specification   |
| 4   | Shall keep track of outputs reaching 80+ dB        | Greater Impacts |
| 5   | Shall minimize storage of classroom noise          | Ethics          |
| 6   | Shall have a safe power toggle                     | IEC 60950-1     |
| 7   | Shall not reach 60°C (140°F)                       | Safety          |

## Buildable schematic 

![image](https://github.com/CarsonDPope/Active-Noise-Control-With-Wall-Transmission-Detection/blob/jmvega52-patch-1/Documentation/Images/DSPBOARD.png)

The third section should show the buildable schematic directly embedded in the markdown file as a jpeg image. If the schematic is not clearly readable and appropriately sized, the supervisor will reject the signoff. 

The schematic must be appropriate to the design. ie. 3d model for a physical system or wiring schematic for a circuit. Further, the schematic(s) must contain every detail necessary for the design to be built by someone who has no knowledge of the design. Every relevant component value and measurement must be given.

The actual design artifacts (3d model, Cad files, gerber files, etc) must be uploaded to the documentation folder in the appropriate location.

## Analysis

#### Psuedo Code Flow Chart
![image](https://user-images.githubusercontent.com/123997954/229912784-1174c224-1c0f-4fb9-8a78-3f503ecb81d3.png)


### Input Processing

The system will receive two analog signals through the stereo jack. These signals are then sent to the ADAU1761 SigmaDSP low power stereo audio codec which features 24-bit stereo audio ADC and DAC. The rated signal to noise ratio is >98 dB SNR. The digital samples are then sent to the respective delay line.

### Input/Output Delay Line

The input delay line will receive the converted digital signals from the input subsytem. These values will be temporarily stored in an array so that the there is enough data to properly convolute the signals. The size of the array is going to depend on the length of the filter. The length of the filter is determined by the acoustic response of the room, such as echo and reverb. The longer the decay of this response, the longer the filter.

The error delay line is going to have similar functionality to the input delay line but it will be receiving data from the acoustic residual noise of the room after output, rather than values from the input subsystem. 

### Filter Updates from General Purpose Computer

The system will receive updating information from a general purpose computer through the USB 2.0 HS interface. This will both power and send the data to the processor. USB 2.0 interfaces run off of 5 volts and have a max current draw of 500 mA, for a max power draw of 2.5 Watts. To power the device through the USB connected to the processor, the jumper J2 needs to connect the 5V pin to the 706 pin.
The USB interface is directly connected to the Blackfin processor and it's SRAM memory. The speed of USB 2.0 HS is 480 Mbps. This means we can send 120 million 32-bit words to the processor per second.

###  ADSP-BF706 Blackfin Processor

The system has the ADSP-BF706 Blackfin processor on board. This processor has a clock speed of 400 MHz, and a multiply-accumulate (MAC) instruction per second speed of 800 million at max clock speed. The ADSP-BF706 has 64 kB usable SRAM internally plus an additional 1 MB of SRAM. The filtered-X least mean squares algorithm being used requires $IJ(K+1)L+JKM+Imax(L,M+1)+K$ words of memory. I is the number of inputs signals, J is the number of output signals, and K is the number of error signals. L is the control filter length and M is the length of the estimated Plant FIR Filter being recieved from the USB interface. Allowing L and M being roughly equal, we can find the maximum size of filters we can use using the internal memory. I,J, and K will be set to 1.

$$64 \text{kB} /4 \text{Bytes} = 16000 \text{ 32-bit words } = 1(1+1) + M + M + 1 + 1 = 4 + 2 M $$

$$ M = 7998 \text{ samples } = L $$ 

7998 samples per filter allow us to have approximately 167 ms for our acoustic response. The number of MAC instructions needed by the algorithm is solved by $ IJK(L+M)+K $ MACs per filter update. Using L equal to M equal to our max storage gets:

$$ 1(2 \times 7998) + 1 = 15997 \text{ MACs } $$

$$15997 \text{ MACs/Coefficent Update } \times \frac{1 s}{800 \text{Million MACs}} = 19.96 \mu s $$

19.96 microseconds is below the 20.83 microseconds before the next sample input. This means the system could do an update in real time. Adding extra time for memory instructions, the system could still run close to real time, and below the max delay of 1.4 ms.

### Signal Negation

The output of the filtered-X LMS algorithm is then negated and sent to the audio codec in order to create the anti-noise for the sound targeted. 

### Output 

The digital output is then converted back to an analog stereo signal. Both channels of the system are equal and will be sent to a 2 speaker array. 

## BOM
| DEVICE            | Quantity | Price Per Unit | Total Price |
| ----------------- | -------- | -------------- | ----------- |
| ADSP-BF706-EZMINI | 1        | $88.31         | $88.31      |
