import socket
import threading
ser = serial.Serial('/dev/ttyACM0',9600)

def get_computer_ip():
    # Create a dummy socket to get the computer's IP address
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
        s.connect(("8.8.8.8", 80))
        return s.getsockname()[0]

def listen_for_packets(listen_port):
    # Create a UDP socket for receiving packets
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind(("", listen_port))
    print(f"Listening for UDP packets on {get_computer_ip()}:{listen_port}")

    while True:
        data, addr = sock.recvfrom(1024)  # Buffer size is 1024 bytes
        hex_data = data.hex()
        print(f"Received from {addr}: {hex_data}")

def send_packet(listen_port):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)  # Enable broadcast mode
    broadcast_address = ("<broadcast>", listen_port)

    while True:
        msg = input("Enter message to send: ")
        sock.sendto(msg.encode(), broadcast_address)
        print(f"Sent broadcast on port {listen_port} -> {msg.encode().hex()}")
def write_motor():
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
