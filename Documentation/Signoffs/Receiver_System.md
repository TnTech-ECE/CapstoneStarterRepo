# Receiver System 
## Functionality
The Receiver system will be responsible for receiving and sending the packed Remote ID (RID) over the network to the database subsystem. This subsystem shall be composed of 9 antennas placed across the contiguous Tennessee Tech University (TTU) campus. The receivers will be placed outside to minimize the power loss that would occur due to the RF signals going through a building. 
## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | Shall only need to receive packets within the 2.4 GHz Wi-Fi and Bluetooth frequency band | Design Constraint|
|  2 | Shall only interact with RID signal and ignore other signals | Ethical Constraint       |                          
|  3 | Shall receive all RID data from remote ID emitting drones    |  Design Constraint |   
|  4 | Shall have a reception range that covers the contiguous campus and cover up to 20 m off the contiguous campus | TTU Police |
|  5 | Each receiver shall have a reception range at a minimum of 152 m | Design Constraint|

<sup>1</sup> According to research done on drone tracking and radio frequency emission, there are three different drone detection cases. In each case, the frequency band used was either between 2.4 Ghz or 5.8 Ghz ISM bands. The 5.8 GHz frequency band can be ommitted due to it being an optional transmission. The drone must emit a 2.4 GHz WiFi signal if a WiFi signal is being emitted, so this is the frequency band we will choose to focus on. This is due to the 5.8 GHz not being transmitted as far, so more receivers would be required to cover the contiguous campus and, therefore, raise the cost of the project. [^6].   

<sup>2</sup> If the receiver reads data that is not the RID signal, it could be considered a privacy concern. The information from those signals are also not applicable to the purpose of this project as they will not allow the receiver to obtain the RID data of a drone. 

<sup>3</sup> If the drone is not emitting the RID signal, the receiver will not be able to pick it up.

<sup>4</sup> Due to a higher density of students on the contiguous campus we have been asked to keep our scope smaller. This will also be easier for maintenance purposes of the subsystem in the future. The receivers will not be able to determine the distance of a signal. To cover the entire TTU campus, the detection radius of the receivers will slightly extend beyond the campus boundaries. Placement of the receivers will be used to minimize how far off campus the receivers will be able to receive signals. 

<sup>5</sup> Based on the calculations and assumptions, the receivers should be able to cover a greater range. However, to ensure an appropriate fade margin of 25 dB, the receivers need to cover a range of 152 meters to account for miscellaneous losses.

## Design

### Arduino Nano ESP32
This microcontroller has been picked due to the low receiver sensitivity of the Wi-fi and Bluetooth module and its ability to then program it to send the signal across the W-Fi to the database. Python code will be used for the receiver to know what signal to find and then relay the signal to be unpacked. Using a line to line link equation the receiver has been calculated to receive a signal from 152 m.

$$ P_{Rx} = P_{Tx} + G_{Tx} - L_{Fs} + G_{Rx} $$ 

The P<sub>Rx</sub> is the power of the signal when it reaches the receiver. The strength of the signal when it reaches the receiver can be calculated by the strength of the signal from the transmitter, P<sub>Tx</sub>. The gain of the transmitter G<sub>Tx</sub> and the receiver G<sub>Rx</sub> can also be used to extend how far the receiver can be from the transmitter. Path loss in free space L<sub>Fs</sub> is a calculated with the following equation. Where d stands for distance and $\lambda$ stands for wavelength. 

$$ L_{Fs} = 20log_{10}(\frac{4\pi * d}{\lambda}) $$

The power of the signal as it reaches the receiver is greater than the receiver sensitivity. This is due to meeting an industry standard of meeting a fade margin of 20-30 dB. Fade margin is used to account for miscellaneous losses such as weather and building structures. There are too many variables to account for when attempting to find losses from structures this is due to different materials obstructing the signal and geometry of the structures. Fade margin can be calculated using the following equation. With R<sub>x</sub> being the reciever sensitivity. 

$$ Fd = P_{Rx} - R_{x} $$

### ESP8266
This Wi-Fi module has been selected due to low cost and so it can connect to the Wi-Fi to send the RID signal packet. It would be inefficient to have the arduino use its own ESP32 module to receive signals and then try to connect to the internet to send the packet. This would create a loss in data received because of the time required to reconnect to the internet. This would affect the whole system from being able to track the drone because it will miss signals sent by the drone. 

### Receiver Enclosure
To safeguard the sensitive electronics essential for the receiver sub-system, a polycarbonate enclosure will be used. The receiver and ESP8266 will be housed in an opaque case with knockout holes for the cable glands. These boxes will be rated IP66 for dust and water protection. 

<img src="/Documentation/Images/Receiver/Schematics/SK-12-03.png" width="60%" height="60%">

## Schematic

### Circuit
The circuit will be soldered onto a perforated (perf) board utilizing the following connections. 
<img src="/Documentation/Images/Receiver/Schematics/Receiver.png" width="60%" height="60%">

## Analysis

### Receivers
The Arduino Nano ESP32 utilizes a NORA-W106-10B Wi-Fi and Bluetooth module with a receiver sensitivy of -97 dBm and -98 dBm respectively. The antenna gain for the system is 3 dBi on average. The dBi value has been assumed based on standard specifications, reflecting common values in the industry to be 3 dBi. The RID signal must be transmitted with a minimum power of 5 dBm for Bluetooth and 15 dBm for Wi-Fi. This is a standard listed in the RID data sheet. Using the line to line link budget equation we can see that the signal strength will be stronger than the receiver sensitivity. The variable d in the line to line equation is 152 m and $\lambda$ can be calculated dividing the speed of light by the frequency of the signal. 

$$
\lambda = \frac{3 \times 10^8 \, \text{m/s}}{2.4 \times 10^9 \, \text{Hz}}
$$

Then we must calculate the free space loss that will occur sending RF signals.

$$ -84 = 20log_{10}(\frac{4\pi * 152 m}{0.125 m}) $$

This gives us the loss that will occur in free space from the minum distance needed of 152 m. Then by plugging in our values for Bluetooth to the line to line equation we can see the strength of the signal as it reaches the receiver from 152 m. 

$$ -73 dBm = 5 dBm + 3 dBi + 3 dBi - 84 dB $$ 

This value of -73 dBm is above the minimum strength that the receiver is able to receive a signal, -98 dBm. This was calculated to achieve an appropriate fade margin in between 20-30 dB. Using the fade margin equation we find that the fade margin is 25 dB. 

$$ 25 dB = -73 dBm - -98 dBm $$

Then we can calculate the strength of the Wi-Fi signal as it approaches receiver.

$$ -63 dBm = 15 dBm +3 dBi + 3dBi - 84 dB $$ 

Finally the fade margin for Wi-Fi can calculated at 34 dB. 

$$ 34 dB = -63 dBm - -97 dBm $$

This is above the standard of 30 dB and this is because the system is more focused on meeting the minimum requirements of the Bluetooth signal since it's transmitted at a weaker rate. 

### Enclosure
The enclosure has a IP66 rating which is more than enough. The first 6 is used to denote that the enclosure is dust tight and will not permit an ingress of dust. Where the second 6 is used to inform that the enclosure can withstand water strong water jets from any direction with no water getting through. The image below show cases that the enclosure is big enough to fit the Arduino and ESP8266. 

<img src="/Documentation/Images/Receiver/Schematics/Eclosure-1.png" width="60%" height="60%">

### Pseudo Code
// Pseudo-code for Arduino to sift through data and find the correct packet

// Initialize necessary libraries for Wi-Fi/Bluetooth connection

initialize_communication_libraries()

// Setup Wi-Fi/Bluetooth modules

setup_communication_modules()

// Define the target packet characteristics (e.g., size, ID, specific byte patterns)

target_packet = define_target_packet()

// Loop to keep the Arduino running continuously
while (true) {
    
    // Check for incoming data packets
    incoming_packet = receive_packet()

    // If a packet is detected
    if (incoming_packet != null) {

        // Check if the incoming packet matches the target packet
        if (check_packet(incoming_packet, target_packet)) {
            
            // If it matches, process the packet data
            packet_data = extract_packet_data(incoming_packet)

            // Send the extracted data to the database
            send_to_database(packet_data)

            // Optionally, wait for a response from the database (acknowledgment)
            response = wait_for_database_response()

            // Log successful transmission or handle errors
            if (response == success) {
                log("Packet successfully transmitted")
            } else {
                log("Error in transmitting packet")
            }
        }
    }
    
    // Continue looping and checking for more packets
    delay(small_interval) // Delay to prevent CPU overload
}


## BOM
#### All prices listed are in USD
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|Arduino Nano ESP32|ABX00083|9|$20.00|$180.00|
|ESP8266| WRL-17146|9|$7.95|$71.55|
|Enclosure with Knockouts, (3.70" x 2.56" x 2.24") ext, (3.36" x 2.22" x 1.76") int, IP66|SK-12-03|9|$14.18|$127.62|
|Gray Cable Glands, IP68, M20 Thread|CG-31|9|$2.23|$20.07|
|Mounting Feet Kit for SK Series Enclosures, 4pc|SK-99|9|$3.36|$30.24|
|Total     |             |   45     |                |   $429.48         |


## References and Links
[^1]: "Standard specification for remote ID and tracking designation - F3411 - 19," ASTM International, (2019).

[^2]: J. Marcel, “3 key factors that determine the range of bluetooth,” Bluetooth® Technology Website, https://www.bluetooth.com/blog/3-key-factors-that-determinethe-range-of-bluetooth/ (accessed Apr. 3, 2024). 

[^4]: S. Cerwin, Radio Propagation and Antennas: A Non-Mathematical Treatment of Radio and Antennas. Bloomington, IN: AuthorHouse, 2019. 

[^6]: D. Aouladhadj et al., “Drone detection and tracking using RF Identification Signals,” National Center for Biotechnology Information, https://www.ncbi.nlm.nih.gov/pmc/articles/PMC10490811/ (accessed Apr. 3, 2024). 

[^7]: “Arduino® Nano ESP32,” Arduino Online Shop, https://store-usa.arduino.cc/products/nano-esp32?selectedStore=us (accessed Apr. 5, 2024).

[^8]: ABX00083-datasheet.pdf, https://docs.arduino.cc/resources/datasheets/ABX00083-datasheet.pdf (accessed Apr. 5, 2024). 

[^9]: “Calculate area on map, Google Maps Area Calculator,” CalcMaps, https://www.calcmaps.com/map-area/ (accessed Apr. 5, 2024). 

[^10]: “WIFI module - ESP8266 (4MB Flash),” WRL-17146 - SparkFun Electronics, https://www.sparkfun.com/products/17146 (accessed Apr. 10, 2024). 
