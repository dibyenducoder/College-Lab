import common as co
import time
import socket
import random
import time
import threading

busy_channel = 0 

# Socket to send data to channel
s_send=co.createConn(co.port_sendrec)   

time.sleep(1)

# Socket to send data to channel
s_signal=co.createConn(co.port_sendsignal)  

print('Channel is connected')

t_slot = 2 #time

# Function to send frames
def send_frame(frames_list):

    i = 0
    while(True):
        # Sense the channel and check if flag is 1 then dont send
        time.sleep(2)
        if(busy_channel == 0):  # Channel is free
            print('Sending frame '+str(i))
            co.send_frame(frames_list[i], s_send)
            if(frames_list[i] != '_'):
                i = i+1
            else:
                i = 0

        else:  # Channel is busy
            print('Channel : Busy State')
            continue


# Function to sense the medium
def sense_medium():
    global busy_channel

    while(True):
        if(s_signal.recv(1024).decode() == '1'):
            busy_channel = 1 # channel is busy
        else:
            busy_channel = 0 # channel is not busy


frames_list = co.readfile('input.txt', co.frame_size)
frames_list.append('_')

sendThread = threading.Thread(target=send_frame, args=(
    frames_list,))  # create the sending thread
senseThread = threading.Thread(
    target=sense_medium)  # create the sending thread


sendThread.start()
senseThread.start()

sendThread.join()
senseThread.join()