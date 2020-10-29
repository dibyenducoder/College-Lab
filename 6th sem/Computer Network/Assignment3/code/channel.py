import socket
import threading
import common as co
import time

# shared_buffer=[]
s_sendrec=co.createSocket(co.port_sendrec)
s_sendsignal=co.createSocket(co.port_sendsignal)
s_recsend=co.createSocket(co.port_recsend)

def new_con():
	s_recsend.listen(5)
	receive, addrrec=s_recsend.accept()

	recThread=threading.Thread(target=send_to_receiver, args=[receive])
	recThread.start()

	while(True):
		# Wait for a connection
		s_sendrec.listen(5)
		c, addr=s_sendrec.accept()
		print('Sender is connected...')

		s_sendsignal.listen(5)
		signal,addrsignal=s_sendsignal.accept()

		# Start a new thread for the sender
		sendThread=threading.Thread(target=receive_from_sender, args=[c,addr])
		sendThread.start()

		signalThread=threading.Thread(target=send_signal, args=[signal, addrsignal])
		signalThread.start()

# Function to send to receiver
def send_to_receiver(receive):

	while(True):
		# If buffer not empty send the frame and clear buffer
		if(len(co.shared_buffer)>0):
			# Send the frame
			print('Sending frame to receiver')
			time.sleep(4)
			co.send_frame(co.shared_buffer[0], receive)
			del co.shared_buffer[0]
		else:
			continue

# Function to receive data from sender
def receive_from_sender(c, addr):
	# Receive data from the sender and keep it in stored buffer
	print('Started new connection to '+str(addr))

	while(True):
		# Receive data from sender
		frame=c.recv(1024).decode()
		time.sleep(2)
		co.shared_buffer.append(frame)
		print(co.shared_buffer)


def send_signal(s, saddr):
	signal=0

	while(True):
		if(len(co.shared_buffer)>=1): # Channel is busy
			signal=1
		else: # Channel not busy
			signal=0

		# Send the signal via socket
		co.send_frame(str(signal), s)

new_con()