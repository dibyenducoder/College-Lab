#!/usr/local/bin/python
import socket 
import threading 
import os , sys             

framesize=16 #size of frame 
dwsize=8 #data word size
x_time=0 #time passed
codeword=[]
index=0
s_n=0 #send next frame 


#Generates the frame from the 9 bit codeword
def gen_frame(codeword):
	new_cw=str(s_n)+'0'*(framesize-len(codeword)-1)+codeword
	return new_cw

#Adds the a parity bit after the 8bit dataword to generate the 9bit codeword
def make_pairity(num):
	count=0
	for s in num:
		if s=='1':
			count=count+1
	if count%2==0:
		num=num+'0'
	else:
		num=num+'1'
	return num

#Reads the input file and generates datawords of length 8
def generate_codewords():
	dataword=[]
	with open("data1.txt","rt") as fp:
		for line in fp:
			newdataword=[''.join(x) for x in zip(*[list(line[z::dwsize])
			 for z in range(dwsize)])]

	dataword.extend(newdataword)

	for dw in dataword:
		codeword.append(make_pairity(dw))

#checks if the sender side is prepared for sending a new frame.
def request_to_send():
	if(index<len(codeword)):
		return True

	return False


#Converts the frame from string to bytearray
def makeframe():
	global index
	new_s=gen_frame(codeword[index])
	index=index+1
	fr=bytearray()
	fr.extend(map(ord,new_s))
	
	return fr

#Introduces error in the desired frame.
def introduce_error(frame):
	frame1=frame
	if count%2==0:
		if frame1[len(frame1)-1]==49:
			frame1[len(frame1)-1]=48
		else:
			frame1[len(frame1)-1]=49
	return frame1

#Resends the frame in case of timeout in a new thread.
def timeout():
	print("timeout !!")
	x_time=0
	try:
		global count,frame
		c,addr=s_send.accept()
		print("Got connection from",addr)
		# print(introduce_error(frame))
		print("Resending frame "+str(count%2))
		
		c.send(introduce_error(frame))
		print(frame.decode("utf-8")+" Sent")
		c.close()
		print("********************************\n")
		# timer=threading.Timer(5.0,timeout)
		# timer.start()
	except InterruptedError as err:
		print(err)
#
s_send = socket.socket()

print( "Socket successfully created")

port_send = 12345
port_receive = 12346

s_send.bind(('', port_send))
print( "socket binded to %s" %(port_send) )

s_send.listen(5)
print( "socket is listening\n")

cansend=True
generate_codewords()
count=1


while True:
     
    if (request_to_send() and cansend==True):
        try:
            c, addr = s_send.accept()
            print('Got connection from', addr ) 
        except InterruptedError as err:
            print(err)
        # getdata();
        frame=makeframe()
        count=count+1

        frame_e=introduce_error(frame)
        print("Sending frame "+str(count%2))
        print(frame_e.decode("utf-8")+" Sent")
        c.send(frame_e)
        # Close the connection with the client 
        c.close()
        print("********************************\n")
        x_time=1
        timer=threading.Timer(5.0,timeout)
        timer.start()
        s_n=(s_n+1)%2
        cansend= False

    try:
        s_receive = socket.socket() 
        s_receive.connect(('127.0.0.1', port_receive))
        ackno=s_receive.recv(1024)
        print("Acknowledgemnt for "+ackno.decode("utf-8")+" received")
        print("********************************\n")
        s_receive.close()
        if(int(ackno)==s_n):
            timer.cancel()
            frame=bytearray()
            cansend=True
    except ConnectionRefusedError as err:
        print(err)