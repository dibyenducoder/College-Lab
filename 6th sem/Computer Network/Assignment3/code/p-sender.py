import common as co
import time
import socket
import random
import time
import threading

busy_channel=0

# Socket to send data to channel
s_send=co.createConn(co.port_sendrec)	

time.sleep(1)

# Socket to send data to channel
s_signal=co.createConn(co.port_sendsignal)	

print('Connected to channel')

p_prob=10
p=4
timeSlot=2

# Function to send frames
def send_frame(frames_list):

	i=0
	while(True):
		# Sense the channel and check if flag is 1 then dont send
		if(busy_channel==0): # Channel is free
			# Send the frame with a probability p
			pr=random.randint(0,p_prob)
			if(pr<=p):
				# Send the frame
				print('Sending frame '+str(i))
				co.send_frame(frames_list[i], s_send)
				if(frames_list[i]!='_'):
					i=i+1
				else:
					i = 0
				time.sleep(3)
			else:
				print('Waiting for '+str(timeSlot))
				time.sleep(timeSlot)
				continue

		else: # Channel is busy
			print('Channel : Busy')
			time.sleep(2)
			continue



# Function to sense the medium
def sense_medium():
	global busy_channel

	while(True):
		if(s_signal.recv(1024).decode()=='1'):
			# Means channel is busy
			busy_channel=1
		else:
			# Means channel is not busy
			busy_channel=0

frames_list=co.readfile('input.txt', co.frame_size)
frames_list.append('_')

# create the sending thread
sendThread=threading.Thread(target=send_frame, args=(frames_list,))

# create the sending thread 
senseThread=threading.Thread(target=sense_medium) 

sendThread.start()
senseThread.start()

sendThread.join()
senseThread.join()