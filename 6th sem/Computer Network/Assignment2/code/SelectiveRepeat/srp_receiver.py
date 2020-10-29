import socket
import time

  
port_send = 12344
port_receive = 12346   

framesize=16
dwsize=8
m=3

def isEnd(frame):
	c = ''
	c = bytearray
	return(c==frame)

def checkParity(num):
	count=0
	for s in num:
		if s=='1':
			count=count+1
	if count%2==0:
		return True
	return False

def corrupted(frame):
	s1=frame.decode('ASCII')
	s2=s1[-(dwsize+1):]
	print(s2)
	if checkParity(s2):
		return False
	return True

def acknowledgement(r_n):
	acknowledgement=str(r_n)
	b_ack=bytearray()
	b_ack.extend(map(ord,acknowledgement))
	return b_ack

def seqno(frame):
	str_fr=frame.decode("utf-8")	
	return int(str_fr[0:dwsize-1],2)


       
s_send = socket.socket()         
print( "Socket successfully created")

s_send.bind(('', port_send))         
print( "socket binded to %s" %(port_send) )

s_send.listen(5)      
print( "socket is listening")

r_n=0

dataFile = open('data1.txt','r');
data = dataFile.read()
dataSize = len(data) - 1
numDataword = int(dataSize / dwsize)
#print('numDataword=',numDataword)
cur=0

while True:
	try:
		#print("cur=",cur," numDataword=",numDataword)
		if cur==numDataword:
			break
		s_receive = socket.socket() 
		s_receive.connect(('127.0.0.1', port_receive))
		frame=s_receive.recv(1024)
		s_receive.close()
		if isEnd(frame):
			break		
		if corrupted(frame)==False:
			if seqno(frame)==r_n:
				cur=cur+1
				try:
					print("frame [ "+str(r_n)+" ] received")
					c, addr = s_send.accept()
					print('Got connection from', addr ) 
					
					r_n=(r_n+1)%(2**m)
					time.sleep(3)

					c.send(acknowledgement(r_n))
					print("acknowledgement sent for frame [ "+str(r_n)+" ]\n")
					c.close()
				except InterruptedError as err:
					print(err)
			else:
				print("Expected Frame: "+str(r_n)+" Arrived Frame: "+str(seqno(frame))+"\n")
		
		else:
			print("Arrived Frame is NAK\n")
	except ConnectionRefusedError as err:
		print(err)
	except OSError as err2:
		a=1