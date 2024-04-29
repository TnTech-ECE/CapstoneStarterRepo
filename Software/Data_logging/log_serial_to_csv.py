# Kyle Plant
# This script is used to read in serial data on the COM port the ESP32 node is outputting to
# and store the data in a csv file.
# You must stop reading the COM port on all other programs for this to be able to read it.
# To clean and organize the raw data read in from the serial port, run the
# "organize_data.py" script on the file made from this script.


import csv
import time

import serial

ser = serial.Serial("COM4", 115200)     # Choose the correct COM port here
ser.flushInput()

while True:
    try:
        ser_bytes = ser.readline()
        decoded_bytes = ser_bytes[0:len(ser_bytes) - 2].decode("utf-8")

        print(decoded_bytes)

        text = ""
        numbers = ""
        res = []
        for i in decoded_bytes:
            if i.isdigit():
                numbers += i
            else:
                text += i
        res.append(text)
        res.append(numbers)

        with open("logged_data_output.csv", "a") as f:      # Name this file as you wish
            writer = csv.writer(f, delimiter=",")
            writer.writerow([time.time(), res])
    except:
        print("Keyboard Interrupt")
        break
