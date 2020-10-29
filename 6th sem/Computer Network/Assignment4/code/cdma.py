import time
import numpy as np
from math import log, ceil

#Returns the walsh code for n stations 
def get_walsh(n):
 return [[int(bin(i&j),13)%2 or -1 for j in range(n)] for i in
range(n)]

#Returns 0, 1 or -1, depending on given character is i, 1 or 0 respectively  
def get_bin(chr):	
	switcher = {
	'0':-1,
	'1':1,
	'i':0
	}
	return switcher.get(chr,2)

#Returns 0, 1 or i, depending on character is -1, 1 or 0 respectively
def get_char(n):

	switcher = {
	-1:'0',
	1:'1',
	0:'i'
	}
	return switcher.get(n,'na')

#To create the walsh code table 
#--filea = open("data.txt", 'r') #Test Case 1
filea = open("data1.txt",'r') #Test Case 2
data = (filea.read()).split('\n')
print(data)
la = len(data)
num_stn = la
max_num_stn = 2**ceil(log(num_stn,2))
data_fin = [['i' for i in range(max_num_stn)] for i in range(max_num_stn)]

for i in range(num_stn):
	if len(data[i]) > 0:
		for j in range(len(data[i])):
			data_fin[i][j] = data[i][j]

num_fin = 0
i = 0
w = np.array(get_walsh(max_num_stn))
print('Walsh code\n'+str(w))

#Results 
for i in range(max_num_stn):

	chara = [x[i] for x in data_fin]
	print('Data input = '+str(chara))
	data_enc = [get_bin(x) for x in chara]
	print('Data encoded = '+str(data_enc))
	data = np.matmul(w,data_enc)
	print('Data on channel = '+str(data))
	data_dec = np.matmul(w,data)/max_num_stn
	data_rcv = [get_char(int(x)) for x in data_dec]
	print('Data received = '+str(data_rcv)+'\n')
	time.sleep(1)

print('over')
