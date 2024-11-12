import socket
import threading
import serial
import numpy as np
import time
from gpiozero import LED
from gpiozero import Button
FIRING_MOTOR = LED(6)
BUZZER = LED(21)
BUZZER.on()
PROXYSENSOR = Button(11)
ROW_PIXEL_LINE = 200
PIXEL_X_MAX = 550
PIXEL_X_MIN = 50
PIXEL_Y_MAX = 360
PIXEL_Y_MIN = 40
DELAY_LINE_EXPIRATION = 2000        # delay in ms that points from the camera are retained
TIME_TO_FIRE_MULTIPLIER =   0.85
TIME_TO_FIRE_DELAY_MS = 250
TIME_TO_FIRE = [1.41, 1.07, 1.38, 1.52, 1.32, 1.26, 1.41, 1.83, 1.16, 1.23, 1.18, 1.49, 1.43, 1.54, 1.64, 1.53, 1.16, 1.49, 1.64, 1.43, 1.36, 1.53, 1.98, 1.25, 1.33, 1.28, 1.61, 1.55, 1.67, 1.77]
TURNTABLE_ANG = [29.12,25.89,22.39,17.54,13.64,9.61,4.20,0,-4.2,-9.61,-13.64,-17.54,-22.39,-25.89,29.12]
VERT_ANG = [30.22,30.56,30.92,31.37,31.63,31.83,32.03,32.03,32.03,31.82,31.63,31.37,30.92,30.56,30.22,34.94,35.43,35.86,36.31,36.56,36.80,37.01,37.01,37.01,36.80,36.56,36.31,35.86,35.43,34.94]
cameraPosArr = np.zeros((256,3))    # Stores a delay line of the previous points responded by the camera subsystem. Upto 256 points. [:][0] - X [:][1] - Y [:][2] - ms since restart
cameraArrLen = 0        # Number of points in delay line
cameraArrIndex = 0


#ser = serial.Serial('/dev/ttyACM0',9600)

def get_computer_ip():
    # Create a dummy socket to get the computer's IP address
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.connect(("8.8.8.8", 80))
        return s.getsockname()[0]
def fire(delay_ms):
    time.sleep(delay_ms / 1000)
    print("Firing after delay!\n")
    FIRING_MOTOR.on()
    PROXYSENSOR.wait_for_release()
    BUZZER.on()
    

def listen_for_packets(listen_port):
    # Create a UDP socket for receiving packets
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind(("", listen_port))
    print(f"Listening for UDP packets on {get_computer_ip()}:{listen_port}")
    global cameraArrLen
    while True:
        data, addr = sock.recvfrom(1024)  # Buffer size is 1024 bytes
        hex_data = data.hex()
        print(f"Received from {addr}: {hex_data} ID: {data[0]}")
        if data[0] == 0x00:
            print("Laser Packet!\n")
            # Laser Array Packet
            # Average the Y positions from the camera delay line
            total = 0
            for i in range(cameraArrLen):
                total += cameraPosArr[i][1]
            if total > 0:
                total = total / cameraArrLen
                BUZZER.off()
                lineNum = 0
                if total > ROW_PIXEL_LINE:
                    lineNum = data[1] -1
                else:
                    lineNum = data[1] + 14
                print(f"Fire signal sent! {lineNum+1}\n")
                print(f"Moving turntable to {TURNTABLE_ANG[lineNum%15]} deg, stepping {int(TURNTABLE_ANG[lineNum%15]/0.45)} times! \n")
                print(f"Moving vertical motor to {VERT_ANG[lineNum]} deg, stepping {int(VERT_ANG[lineNum]/0.45)} times! \n")
                
                # Create a thread object
                thread = threading.Thread(target=fire((TIME_TO_FIRE[lineNum] * 1000 - TIME_TO_FIRE_DELAY_MS) * TIME_TO_FIRE_MULTIPLIER))

                # Start the thread
                thread.start()
                #write_motor(lineNum)
                
        elif data[0] == 0x01:
            # Time of Flight Sensor Packet
            dist_cm = data[1]
            frac_cm = data[2]
            time_stamp = int(data[3] * 1677216 + data[4] * 65536 + data[5] * 256 + data[6])
            
            # TODO: Push timestamps and distance to a 3 element delay line and calculate velocity and acceleration
            
        elif data [0] == 0x02:
            # Camera Packet
            time_ms = int(time.time() * 1000)
            
            # Push back delay line
            replacementDelayLine = np.zeros((256,3))
            newIndex = 0
            for i in range(cameraArrLen):
                # If the data is not expired, add it to the replacementDelayLine
                if time_ms - cameraPosArr[i][2] < DELAY_LINE_EXPIRATION:
                    # Copy the content from cameraPosArr[i] to replacementDelayLine[newIndex]
                    replacementDelayLine[newIndex][:] = cameraPosArr[i][:]
                    # Move newIndex forward to the next position in replacementDelayLine
                    newIndex += 1
                    
            cameraArrLen = newIndex
            cameraPosArr[:][:] = replacementDelayLine[:][:]
                
            # Add new position to delay line
            cameraPosArr[cameraArrLen][0] = int(data[1]*256 + data[2])
            cameraPosArr[cameraArrLen][1] = int(data[3]*256 + data[4])
            cameraPosArr[cameraArrLen][2] = time_ms
            cameraArrLen += 1

def send_packet(listen_port):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)  # Enable broadcast mode
    broadcast_address = ("<broadcast>", listen_port)

    while True:
        msg = input("Enter message to send: ")
        sock.sendto(msg.encode(), broadcast_address)
        print(f"Sent broadcast on port {listen_port} -> {msg.encode().hex()}")
def write_motor(lineNum):
    print('move')
    ser.write(b'1')
    time.sleep(5)
    print('back')
    ser.write(b'0')
    time.sleep(5)

# Define the port for communication
PORT = 1337  # Port to send and listen for UDP packets

if __name__ == "__main__":
    # Start the listener in a separate thread
    listener_thread = threading.Thread(target=listen_for_packets, args=(PORT,), daemon=True)
    listener_thread.start()

    # Start sending packets from the main thread
    send_packet(PORT)
