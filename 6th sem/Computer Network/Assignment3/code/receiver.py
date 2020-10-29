import common as co
import socket

# Socket to send data to channel
s_rec=co.createConn(co.port_recsend)	
print('Connected to channel')

# Function to receive a frame
def receive_frame():

	while(True):
		# Receive the frame
		frame=s_rec.recv(1024).decode()
		print('Frame received '+frame)

receive_frame()