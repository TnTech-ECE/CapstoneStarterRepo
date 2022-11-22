Team 4 – Mario Kart & Ride Replay Simulator

Team Members: Ray Durlin, Blake Pickett, Tyler Chittum, Benjamin Reed, and Sage Mooneyham

Detail Design: HDMI Switcher

_Function of the Subsystem:_

The HDMI Switcher is designed to allow users to connect the HDMI ports for their Nintendo Switch and their RRS kit into a single HDMI input to their television or monitor. The switcher will use a multiplexer compatible with two HDMI inputs and one HDMI output, and the Raspberry Pi to allow user selection via the User Interface on the touchscreen. The multiplexer and HDMI ports will be implemented onto a PCB, which will then be contained within the microcontroller casing with the Raspberry Pi. The Raspberry Pi will interface with the multiplexer by sending inputs to the two selection bits, both of which are designed to control which HDMI input is to be used.

_Constraints:_

_HDMI Compatibility:_ As HDMI is standard in the modern era, the multiplexer needs to be compatible with such an input. The RRS Acquisition is designed to record video at a resolution of 720p. Furthermore, the Nintendo Switch is rated to display data at a resolution of 1080p while in TV mode, which is the mode that the Nintendo Switch will be in while using the bike [1]. The multiplexer must therefore be rated to manage resolutions up to 1080p. It should be commented on that the use of HDMI allows for ease of accessibility for the majority of the population, especially those who are capable of purchasing the MK bike and the RRS kit to begin with.

_HDMI Quantity:_ As the switcher is expected to manage three ports, the multiplexer must also be capable of doing so. The multiplexer must have one output port and be capable of switching between two input ports.

_Voltage Ratings:_ To ensure non-damaging operation of the switcher, the voltage sources need to be considered. The ratings, as per suggested operations on the datasheet, are 3V to 3.6V with a nominal voltage of 3.3V for the supply voltage and 4.5V to 5.5V with a nominal voltage of 5V for the standby supply voltage [2].

_Resistance Rating:_ Though a small component, it should also be addressed. The suggested resistor for the TMDS compliant voltage swing range is 3.66 kΩ to 4.47 kΩ, with a nominal resistance of 4.02 kΩ [2]

_Buildable Schematic:_

![](RackMultipart20221122-1-6zil3d_html_54e572438dbd2564.png)

_Analysis:_

There is little in terms of analysis for this subsystem. Most of the analysis consists of ensuring that the constraints are met. With the microcontrollers in use, this results from information obtainable in the datasheets.

_HDMI Compatibility and Quantity:_ These were the simplest constraints to meet. The TMDS251 HDMI multiplexer utilizes a 2x1 mux with two selector bits to control the output. In addition, the multiplexer is rated for resolutions of 1080p [2].

_Voltage Ratings:_ The Raspberry Pi has a voltage output of 3.3V with limited variation from that value [3]. Therefore, the 3.3V port will supply power to the VCC pins, as well as the SDA\_Sink and the SCL\_Sink pins of the multiplexer. Additionally, HDMI cables supply voltage via their +5V pin [4]. As per HDMI regulations, these pins are rated for a range of 4.7V to 5.3V. This remains in the 4.5V to 5.5V range. Therefore, the HDMI input cables supply voltage to the VDD pin as well as their designated SDA pins.

_Resistance Rating:_ The resistor selected for RVSADJ is a 4.02 kΩ resistor with tolerance 0.1%. This results in a resistance range of 4.016 kΩ to 4.024 kΩ. This range is well within the constraints and is therefore sufficient.

_BOM_

_| Team 4 - Mario Kart & RRS | Bill of Materials (BOM) | |_

_| ------------------------- | ----------------------- | --------------------- |_

_| | | | | | | | | |_

_| | | | | | | | | |_

_| Subsystem Name: | HDMI Switcher | | | | |_

_| Requested by: | Benjamin R | | | | |_

_| Approve by: | | | | | |_

_| Total Cost: | $38.38 | | | | |_

_| | | | | | | | | |_

_| | | | | | | | | |_

_| Level | Part # | Part Name | Supplier | Supplier Part # | Qty | Units | Unit Cost | Cost |_

_| 1.1 | MUXIC100 | Multiplexer IC | Texas Instruments | TMDS251PAGR | 2 | IC | $4.36 | $8.72 |_

_| 1.2 | HDMI100 | HDMI Port | CNC Tech | 2000-1-2-41-00-BK | 4 | Port | $1.72 | $6.88 |_

_| 2.1 | CRES100 | 1 kΩ Chip Resistor | YAGEO | AC1210JR-071KL | 2 | Piece | $0.23 | $0.46 |_

_| 2.2 | CRES101 | 4.02 kΩ Chip Resistor | TE Connectivity Passive Product | RQ73C2A4K02BTD | 2 | Piece | $0.77 | $1.54 |_

_| 2.3 | CRES102 | 4.7 kΩ Chip Resistor | KOA Speer Electronics, Inc. | RK73H1JRTTD4701F | 3 | Piece | $0.11 | $0.33 |_

_| 2.4 | CRES 103 | 47 kΩ Chip Resistor | YAGEO | RC1210FR-0747KL | 3 | Piece | $0.15 | $0.45 |_

_| 3 | PCB100 | PCB | JCPCB | N/A | 5 | PCB | $4.00 | $20.00 |_

_| | | | | | | | Total | $38.38 |_

REFERENCES

[1] Nintendo, "Technical Specs." nintendo.com. https://www.nintendo.com/switch/tech

specs/#switch-section (accessed Nov. 21, 2022).

[2] Texas Instruments, "2.5 Gbps 2-TO-1 DVI/HDMI SWITCH." ti.com. https://www.ti.com/lit/ds/symlink/tmds251.pdf?HQS=dis-mous-null-mousermode-dsf-pf-null-wwe&ts=1669054611580&ref\_url=https%253A%252F%252Fwww.mouser.com%252F (accessed Nov. 21, 2022).

[3] Raspberry Pi Ltd., "Raspberry Pi 4 Model B." raspberrypi.com. https://datasheets.raspberrypi.com/rpi4/raspberry-pi-4-datasheet.pdf (accessed Nov. 21, 2022)

[4] Texas Instruments, "How to Meet the HDMI 5 V Source Requirement." ti.com. https://www.ti.com/lit/an/snva412c/snva412c.pdf
