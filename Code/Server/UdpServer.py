import socket
import threading
import serial
import numpy as np
import time

ROW_PIXEL_LINE = 200
PIXEL_X_MAX = 550
PIXEL_X_MIN = 50
PIXEL_Y_MAX = 360
PIXEL_Y_MIN = 40
DELAY_LINE_EXPIRATION = 2000        # delay in ms that points from the camera are retained
TIME_TO_FIRE_MULTIPLIER =   0.85
TIME_TO_FIRE_DELAY_MS = 250
TIME_TO_FIRE = [1.41, 1.07, 1.38, 1.52, 1.32, 1.26, 1.41, 1.83, 1.16, 1.23, 1.18, 1.49, 1.43, 1.54, 1.64, 1.53, 1.16, 1.49, 1.64, 1.43, 1.36, 1.53, 1.98, 1.25, 1.33, 1.28, 1.61, 1.55, 1.67, 1.77]
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
        if data[0] == 48:
            print("Laser Packet!\n")
            # Laser Array Packet
            # Average the Y positions from the camera delay line
            total = 0
            for i in range(cameraArrLen):
                total += cameraPosArr[i][1]
            if total > 0:
                total = total / cameraArrLen
                
                lineNum = 0
                if total > ROW_PIXEL_LINE:
                    lineNum = data[1]
                else:
                    lineNum = data[1] + 15
                lineNum = lineNum - 64
                print(f"Fire signal sent! {lineNum}\n")

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
