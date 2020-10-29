import socket 
import threading 
import time       
import random

  
port_send = 12346
port_receive = 12344   

framesize=16
dwsize=8
x_time=0
codeword=[]
index=0

m=3
s_n=0
s_w=2**m-1
s_f=0
times=0

lock=threading.Lock()

window=dict()

def timeout():	#defines timeout protocol
	print("timeout!!")
	x_time=0
	try:
		temp=s_f
		while temp!=s_n:
			c,addr=s_send.accept()
			#print("Received signal from : ",addr)
			print("Got connection from",addr)
			if temp==2:
				window[str(temp)][len(window[str(temp)])-1]=48
			
			
			temp=(temp+1)%(2**m)

		#Resending the damaged or lost frame only at the end 	
		print("[Resending "+str(temp)+" ]")
		print(window[str(temp)].decode("utf-8")+" Sent")
		c.send(window[str(temp)])

		print("*******************************\n")			
		time.sleep(2)
		c.close()

	except InterruptedError as err:
		print(err)
	

def gen_frame(codeword):	# generates frame
	str_="{0:b}".format(s_n)
	new_cw='0'*(framesize-len(codeword)-len(str_))+str_+codeword
	return new_cw

def make_parity(num):	# generates parity
	count=0
	for s in num:
		if s=='1':
			count=count+1
	if count%2==0:
		num=num+'0'
	else:
		num=num+'1'
	return num

def generate_codewords():	# generates codewords
	dataword=[]
	with open("data1.txt","rt") as fp:
		for line in fp:
			newdataword=[''.join(x) for x in zip(*[list(line[z::dwsize]) for z in range(dwsize)])]

	# print("The input datawords are: ")
	dataword.extend(newdataword)

	for dw in dataword:
		codeword.append(make_parity(dw))

	# with open("codeword.txt","w") as fp:
	# 	for x in codeword:
	# 		fp.write(x+"\n")
	# print(codeword)

# def request_to_send():	# checks if codeword is ready to be sent
# 	print("index=",index," len(code)=", len(codeword))
# 	if(index<len(codeword)):
# 		return True
# 	return False

def makeframe():	# generates frames filled with codewords
	global index
	#print("new frame "+str(index)+" Created")
	if(index > int(len(codeword)-1)):
		return -1
	new_s=gen_frame(codeword[index])
	index=index+1
	fr=bytearray()
	fr.extend(map(ord,new_s))
	
	return fr

def introduce_error(frame):	#transmits frames
	global s_n
	global times
	#print('Transmission ongoing......')
	frame1=frame
	if times==1:
		times=0
		return frame1
	timesNew = random.randint(0,1)
	if s_n==2 and timesNew==1:
		if frame1[len(frame1)-1]==49:
			frame1[len(frame1)-1]=48
		else:
			frame1[len(frame1)-1]=49
		times=times+1
	return frame1


s_send = socket.socket()         
print( "Socket successfully created")

s_send.bind(('', port_send))         
print( "socket binded to %s" %(port_send) )  
s_send.listen(5)      
print( "socket is listening")                
  
cansend=True
generate_codewords()
# print("\ncodewords are:")
# for i in range(len(codeword)):
# 	print(codeword[i])
# print("")

class sendThread(threading.Thread):
	def _init_(self):
		print("Thread for sending frames")

	def run(self):
		global s_n,s_f,s_w,cansend,x_time,window,frame,timer,times
		while True:						
			if (s_n>=s_f and s_n-s_f<s_w) or (s_n<s_f):			
				try:
					c, addr = s_send.accept()
					print('Got connection from', addr ) 
				except InterruptedError as err:
					print(err)			

				frame=makeframe()
				if(frame==-1):					
					break
				window[str(s_n)]=frame			
				frame_e=introduce_error(frame)	

				#will send only the damaged frame 			
				print("[Sending "+str(s_n)+" ]")
				print(window[str(s_n)].decode("utf-8")+" sent")
				c.send(frame_e)	

				print("****************************\n")					
				time.sleep(2)
				c.close()
				
				lock.acquire()
				if (x_time!=1):
					x_time=1
					timer=threading.Timer(5.0,timeout)
					timer.start()
				lock.release()

				s_n=(s_n+1)%(2**m)
				cansend= False

class receiveThread(threading.Thread):
	def _init_(self):
		print("Thread for receiving Acknowledgements")

	def run(self):
		global s_n,s_f,s_w,cansend,x_time,window,frame,timer
		while True:
			try:
				s_receive = socket.socket() 
				s_receive.connect(('127.0.0.1', port_receive))
				ackno=s_receive.recv(1024)
				print("acknowledgement received for frame [ "+ackno.decode("utf-8")+" ]")
				s_receive.close()
				if (s_n>=s_f and int(ackno)<=s_n and int(ackno)>s_f) or (s_n<s_f and int(ackno)>s_f and int(ackno)<s_w) or(s_n<s_f and int(ackno)<s_f and int(ackno)<=s_n):
					print("No Acknowledgement error\n")
					lock.acquire()
					timer.cancel()
					x_time=0
					lock.release()
					while (s_n>=s_f and s_f<int(ackno)) or (s_n<s_f and s_n>=int(ackno)):
						x=window.pop(str(s_f))
						s_f=(s_f+1)%(2**m)
					frame=bytearray()
					cansend=True
			except ConnectionRefusedError as err:
				pass
			except ConnectionResetError as err2:
				pass

thread1=sendThread()
thread2=receiveThread()

thread1.start()
thread2.start()