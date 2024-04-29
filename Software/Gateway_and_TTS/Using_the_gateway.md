# How to use the Raspberry Pi + WM1302 Gateway


## Login
The password for user1 is "password".


## Starting the Packet Forwarder
I made a script to start the packet forwarder with the config file I have configured to work with the The Things Stack application. You can find it at ~/sx1302_hal/packet_forwarder. You run it with ./start_packet_forwarder.sh. It would be nice to get that shell script to start on boot, but I did not end up implementing that.

Refer to this webpage for help getting set up: https://wiki.seeedstudio.com/WM1302_module/

### Side Note
The U.FL connector labeled ANT on the PiHAT is for the GPS module NOT the antenna! The antenna connects to the U.FL labeled RFIO on the concentrator board itself.