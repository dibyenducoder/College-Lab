import socket

port_sendrec=11001
port_sendsignal=11002
port_recsend=11003
frame_size=4
shared_buffer=[]

# Function to read the file and split into frames
def readfile(filename, frame_size):
	# Open the file for reading
	f=open(filename,'r')
	data=f.read()

	# Now split the data into frames
	frames_list=[data[i:i+frame_size] for i in range(0, len(data), frame_size)]
	return frames_list

# Function to create a socket and bind it to a port
def createSocket(port):
	s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	s.bind(('127.0.0.1', port))
	return s

# Function to receive a connection
def allowConn(s):
	s.listen(5)
	c, addr=s.accept()
	return c, addr

# Function to create a socket and connect to it
def createConn(port):
	sock=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sock.connect(('',port))
	return sock

# Function to send a frame
def send_frame(frame, c):
	# Send the frame to the other process
	c.send(frame.encode())
