import ErrorDetectionTechnique as err

# Function to read from the input file and convert it to a list of frames
def readfile(filename, no_of_bits):
	# Open the file in read mode 
	f=open(filename,'r')
	data=f.read()

	# Now split the data into frames
	list_of_frames=[data[i:i+no_of_bits] for i in range(0, len(data), no_of_bits)]
	return list_of_frames

# Coverts dataword to codeword and wrote to the appropriate file
def dataword_to_codeword(list_of_frames, no_of_bits):

	print('\n\n++++++++++++++++++++++Sender++++++++++++++++++++++++++++++++\n\n')
	# Longitudinal Check Redundancy   
	print('\nWriting to lrc file :')
	write_lrc(list_of_frames, no_of_bits)

	# Vertical Redundancy Check  
	print('\n\nWriting to vrc file :')
	write_vrc(list_of_frames, no_of_bits)
	
	# Checksum  
	print('\n\nWriting to checksum file :')
	write_chksum(list_of_frames, no_of_bits)

	# Circular Redundancy Check 
	print('\n\nWriting to crc file :')
	write_crc(list_of_frames, no_of_bits)


# Function to write the lrc frames to file
def write_lrc(list_of_frames, no_of_bits):
	
	lrcval=err.lrc(list_of_frames=list_of_frames, no_of_bits=no_of_bits)

	list_of_frames2=list_of_frames[:]
	list_of_frames2.append(lrcval) #Append the resulted LRC at the last frame of datawords 

	# Printing the frames
	print('Codeword frames sent:')
	print(list_of_frames2)
	
	with open('Original_sender.txt', 'w') as fw:
		fw.write("\n\nOriginal LRC ---\n")
		for item in list_of_frames2:

			fw.write("%s | " % item)

# Function to write the vrc frames to file
def write_vrc(list_of_frames, no_of_bits):

	list_of_frames2=err.vrc(list_of_frames=list_of_frames)[:]

	# Printing the frames
	print('Codeword frames sent:')
	print(list_of_frames2)

	with open('Original_sender.txt', 'a') as fw:
		fw.write("\n\nOriginal VRC ---\n")
		for item in list_of_frames2:
			
			fw.write("%s | " % item)
	
# Function to write the checksum frames to the file
def write_chksum(list_of_frames, no_of_bits):
	
	chksum=err.checksum(list_of_frames=list_of_frames, no_of_bits=no_of_bits)

	list_of_frames2=list_of_frames[:] # added all frames 
	list_of_frames2.append(chksum) #put checksum at the end of last frame

	# Printing the frames
	print('Codeword frames sent:')
	print(list_of_frames2)

	with open('Original_sender.txt', 'a') as fw:
		fw.write("\n\nOriginal checksum ---\n")
		for item in list_of_frames2:
			
			fw.write("%s | " % item)


# Function to write the crc frames to the file
def write_crc(list_of_frames, generator):

	list_of_frames2=err.crc(list_of_frames=list_of_frames, generator=err.generator_poly,
							no_of_bits=err.no_of_bits_crc)[:]

	# Printing the frames
	print('Codeword frames sent :')
	print(list_of_frames2)

	with open('Original_sender.txt', 'a') as fw:
		fw.write("\n\nOriginal CRC ---\n")
		for item in list_of_frames2:
			
			fw.write("%s | " % item)
	
