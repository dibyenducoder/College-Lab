import ErrorDetectionTechnique as err
#import random
no_of_errors=0


# Function to introduce error as well as insert the error 
def inject_error(list_of_frames, frame_no, list_of_bit):

	list_of_frames2=list_of_frames[:]
	frame=list_of_frames2[frame_no]
	new=list(frame)

	# Inserting error in the given bit position here or toggling problem 
	for i in range(len(list_of_bit)):
		
		if(new[list_of_bit[i]]=='0'):
			new[list_of_bit[i]]='1'
		elif (new[list_of_bit[i]]=='1'):
			new[list_of_bit[i]]='0'
	list_of_frames2[frame_no]=''.join(new)

	return list_of_frames2

# Function to read from the input file and convert to a list of frames
def readfile(filename, no_of_bits):
	# Open the file for reading
	f=open(filename,'r')
	data=f.read()

	# Now split the data into frames
	list_of_frames=[data[i:i+no_of_bits] for i in range(0, len(data), no_of_bits)]
	return list_of_frames

# sending codewords through transmission medium 
# error_list_frames contains the list of frames to introduce the error into
# error_bit_list is a list of lists containing bit posiiton of errors in each frame
def sending_codeword(list_of_frames, no_of_bits, error_list_frames, error_bit_list):
	global no_of_errors
	
	medium_lrc(list_of_frames, no_of_bits, error_list_frames, error_bit_list)
	
	medium_vrc(list_of_frames, no_of_bits, error_list_frames, error_bit_list)
	
	medium_chksum(list_of_frames, no_of_bits, error_list_frames, error_bit_list)

	medium_crc(list_of_frames, no_of_bits, error_list_frames, error_bit_list)

# Function to write the lrc frames to file
def medium_lrc(list_of_frames, no_of_bits, error_list_frames, error_bit_list):
	
	lrcval=err.lrc(list_of_frames=list_of_frames, no_of_bits=no_of_bits)

	list_of_frames2=list_of_frames[:]
	list_of_frames2.append(lrcval)

	# Inserting error
	for i in range(len(error_list_frames)):
		list_of_frames2=inject_error(list_of_frames2, error_list_frames[i], error_bit_list[i])

		#Reciever will read this txt file 
	with open('Trans_Medium_LRC.txt', 'w') as fw:
		for item in list_of_frames2:
			item='0'*(len(err.generator_poly)-1)+item #for list maintaining order
													#without this, bug arises 

			fw.write("%s" % item)

	with open('Latest_reciver.txt', 'w') as fw:
		fw.write('\n\nReciever LRC ---\n')
		for i in list_of_frames2:

			fw.write("%s | " % i)

# Function to insert error toggling the vrc introduced frames to file
def medium_vrc(list_of_frames, no_of_bits, error_list_frames, error_bit_list):

	list_of_frames2=err.vrc(list_of_frames=list_of_frames)[:]

	# Inserting error
	for i in range(len(error_list_frames)):
		list_of_frames2=inject_error(list_of_frames2, error_list_frames[i], error_bit_list[i])

	with open('Trans_Medium_VRC.txt', 'w') as fw:
		for item in list_of_frames2:
			item='0'*(len(err.generator_poly)-2)+item
			fw.write("%s" % item)

	with open('Latest_reciver.txt', 'a') as fw:
		fw.write('\n\nReciever VRC ---\n')
		for i in list_of_frames2:

			fw.write("%s | " % i)

# Function to insert error toggling the checksum frames to file
def medium_chksum(list_of_frames, no_of_bits, error_list_frames, error_bit_list):
	
	chksum=err.checksum(list_of_frames=list_of_frames, no_of_bits=no_of_bits)

	list_of_frames2=list_of_frames[:]
	list_of_frames2.append(chksum)

	# Inserting error
	for i in range(len(error_list_frames)):
		list_of_frames2=inject_error(list_of_frames2, error_list_frames[i], error_bit_list[i])

	with open('Trans_Medium_Checksum.txt', 'w') as f:
		for item in list_of_frames2:
			item=item='0'*(len(err.generator_poly)-1)+item
			f.write("%s" % item)

	with open('Latest_reciver.txt', 'a') as fw:
		fw.write('\n\nReciever checksum ---\n')
		for i in list_of_frames2:

			fw.write("%s |" % i)



# Function to insert error toggling the CRC frames to file
def medium_crc(list_of_frames, generator, error_list_frames, error_bit_list):

	list_of_frames2=err.crc(list_of_frames=list_of_frames, 
		generator=err.generator_poly, no_of_bits=err.no_of_bits_crc)[:]

	# Inserting error
	for i in range(len(error_list_frames)):
		list_of_frames2=inject_error(list_of_frames2, error_list_frames[i], error_bit_list[i])
	
	with open('Trans_Medium_CRC.txt', 'w') as f:
		for item in list_of_frames2:
			f.write("%s" % item)

	with open('Latest_reciver.txt', 'a') as fw:
		fw.write('\n\nReciever CRC ---\n')
		for i in list_of_frames2:

			fw.write("%s | " % i)

