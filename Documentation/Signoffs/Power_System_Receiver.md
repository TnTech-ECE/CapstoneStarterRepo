# Power System for Receiver System
## Functionality
The primary functionality for the receiver power system is to reliably meet the power requirements for the receiver system's components. The system will supply 5 V to the receiver system.

## Constraints
| No.| Contraint | Origin |
| -- | --------- |--------|
|  1 | The system shall be designed to minimize future maintenance.      |   Broader Implications    |
|  2 | The system shall comply with ASTM B258-18 [2]. | Standards and Safety |
|  3 | The system shall be weather resitant to an IP67 rating [1].  | Standards and Safety |
|  4 | The system shall be able to supply enough power to the receiver system for its full functionality | Design Team |
       

<sup>1</sup> Reducing maintenace is important to reduce the workload for the continuing function of the drone tracker system after the project is completed. For example,the system will be less useful if a worker must constantly change the batteries, so solar energy will be used to charge batteries that will last for at least three years. <br />

<sup>2</sup> ASTM B258-18 is a standard for the proper wire gauge for electrical conductors. It is important to adhere to this standard to ensure the system is safe and avoid overheating, short circuits, and fires.  <br />

<sup>3</sup> The system will be located outdoors, so it is essential that the electrical components will be protected from environemental weather hazards and damage. The IP67 rating protect the system from cover rain, snow, dust, wind, and UV. <br />

<sup>4</sup> This statement is obviously the most important, because the power system must supply the proper power for the receiver system to acheive its functionality for the project. <br />



## Schematic
<img width="870" alt="Screenshot 2024-05-02 at 4 54 11 PM" src="https://github.com/mrnye42/Drone-Tracker-Project/assets/158224821/1ffb0a4e-4733-451e-a968-a7d6f8d49529"><br />
Figure 1: Electrical Schematic<br />
The above schematic is a simple proof of concept of the connections for the system. The schematic will be detailed with the signoff of the receiver system, since the design of this power system will lag the receiver system's design in case of changes required.<br />

<img width="984" alt="Screenshot 2024-04-10 at 9 43 25 PM" src="https://github.com/mrnye42/Drone-Tracker-Project/assets/158224821/e893c923-8836-458a-af27-fb9d5f76ec00"> <br />
Figure 2: Waveshare Power Management Module Schematic<br />
The above figure details the electronics and circuitry found in the Waveshare Power Management Module.<br />


## Analysis
The Arduino® Nano ESP32 can be powered with 5 V through a USB-C connector or an input voltage of 6-21 volts through the VIN pin. For this design, the team will be using the 5 V USB-C port, because this gives the microcontroller additional functionality that may be utilized in the receiver system's design. To reduce maintenace, the team will be utlizing solar panels to recharge the 3.7 V lithium ion battery in the Waveshare Solar Power Management Module. From this module, the Micro-USB 5 V output port will be connected to the Arduino Nano ESP32 with the USB C to Micro USB cable. <br />



## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|Waveshare Solar Power Management Module|       B07PBRK8KG      |   9     |  $13.99              |     125.91       |
|Mini Solar Panel 3 Pack     |     B08THXDWS1        |    3      |      $15.78          |      $47.34      |
|USB A to USB C 2 Pack  |    ‎B09R7NPWQR       |     5     |        $10.00        |      $50.00     |
|Joinfworld 6x6x4 Outdoor Electrical Box Weatherproof Junction Box | ‎ BG595935T | 9 | $19.99 | 179.91 |
|Total     |             |          |                |      $403.16   |

## References
[1] “NEMA Enclosure Types,” NEMA, https://www.nema.org/. <br />
[2] “Standard specification for standard nominal diameters and cross-sectional areas of AWG sizes of solid round wires used as electrical conductors,” ASTM International, https://www.astm.org/b0258-18.html. <br /><br />



Part List:<br />
Arduino® Nano ESP32: https://docs.arduino.cc/resources/datasheets/ABX00083-datasheet.pdf<br />

Waveshare Solar Power Management Module: <br />
Amazon: https://www.amazon.com/Waveshare-Management-Protection-Low-Power-Environmental/dp/B094FWZVFH<br />
Datasheet: https://www.waveshare.com/wiki/Solar_Power_Manager

CONMDEX Android Auto USB C Cable 10Gbps [2ft, 2-Pack] USB 3.1 Gen 2 USB A to USB C Cable, Short 3A Type C Charger Fast Charging Data Transfer Cord for iPhone 15 Plus 15 Pro Samsung Galaxy S23, Black<br />
Amazon: https://www.amazon.com/Upgrade-CONMDEX-Android-Charging-Samsung/dp/B09R7NPWQR/ref=sr_1_4?crid=1RYXFJ3ZNTWM9&dib=eyJ2IjoiMSJ9.qctCTJVEe1768CuG4mh7m_vkAYYCq2hCOJFCpJIBQThD4d6zcW81c0jlf6OTpSBLx5yZDH_9LVfGEuPEkfKrLUklckMEawejurncaNdPPwY2CTWARIxXVtKaQeIslUUL4HTyvKu9nxxQVj4DCGzrF56nyDn4IwJ-QrFPtq9MlxSeZosnUIB081t4LH3etFs8-DYivWgZnOgXbPPTNKxBk9RGEhTaiHIJmqwsm1bQpdYRbi6u5yjTuLqxDzTV2qBtEMjWiDLBe4m8RlJDhJvRcyc_bOhPB1XBaoI1V1iusoA.4YeaL1-6BJmfX4pRc94yddfdhQbfQ5AQq7_uxuX4fVU&dib_tag=se&keywords=Usb%2Bto%2Busb%2Bc%2B2%2Bft&qid=1714683565&s=electronics&sprefix=usb%2Bto%2Busb%2Bc%2B2%2B%2Celectronics%2C208&sr=1-4&th=1


3Pcs Mini Solar Panel DC 6V Polysilicon Solar Cell Charger Module Solar DIY System Kits with 30cm Cable<br />
Amazon: https://www.amazon.com/Solar-Polysilicon-Charger-Module-System/dp/B08THXDWS1/ref=pd_ci_mcx_pspc_dp_d_2_i_0?pd_rd_w=xgPjN&content-id=amzn1.sym.568f3b6b-5aad-4bfd-98ee-d827f03151e4&pf_rd_p=568f3b6b-5aad-4bfd-98ee-d827f03151e4&pf_rd_r=5HKNCZ0HYSFKPMPD4RHJ&pd_rd_wg=kC7Hx&pd_rd_r=92a4fce3-dadb-4bf2-a13d-e899e8fc5157

Joinfworld 6x6x4 Outdoor Electrical Box Weatherproof Junction Box.<br />
Amazon: https://www.amazon.com/Joinfworld-Electrical-Weatherproof-Waterproof-Electronics/dp/B0CHHJ49QN/ref=sr_1_10?dib=eyJ2IjoiMSJ9.K8G1wFmrAJsX4FBA55HSm7NZ_GKN5SPVUqAsIZlhuCcjFsf1RDn8byXREQ0s8PfCauO7c4PTc5A437ZjnWJWy2-UPdnBYnclRdZs7IskDOWobyZXINfs_FbTwsSdBBX6376kcS3TCzt03gRaK8rahKuGCoPtBZiMKi2Pq7eB11Z71PXFdY900GJAFpVnnwoJLsU_gdcpaEayblkZK02j6fTxpvfLWQCLOST2tW_HaamijlOGOe8n6nxctEMAGZ2QGEV36m7JlXhlUkxz-DiyVhzgkjzmJVQ4GSkfpmpMOI8.TnzKmygqGJtkollqDS7D4qUERq1jfc5i0ZzSMlmDt8Q&dib_tag=se&hvadid=237377448938&hvdev=c&hvlocphy=9013088&hvnetw=g&hvqmt=e&hvrand=16258796136295452947&hvtargid=kwd-338603829814&hydadcr=26287_9742884&keywords=nema%2B3r%2Brainproof%2Benclosure&qid=1714678494&sr=8-10&th=1 


