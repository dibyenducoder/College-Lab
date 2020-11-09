import socket
import sys
import pickle
import time
import threading

def cmdfun(uname, args):
	i=0
	command_array=[]
	while i<len(args):
		command={} 
		if args[i]=="get":   #get <key>
			command["user_name"]=uname
			command["type"]="get"
			command["key"]=args[i+1]
			i+=2
			command_array.append(command)

		elif args[i]=="put": #put <key><value>
			command["user_name"]=uname
			command["type"]="put"
			command["key"]=args[i+1]
			command["data"]=args[i+2]
			i+=3
			command_array.append(command)

		elif args[i]=="get_other": #get_other <username><key>
			command["user_name"]=uname
			command["type"]="get_other"
			command["key"]=args[i+1]
			command["user_name2"]=args[i+2]
			i+=3
			command_array.append(command)
		
		elif args[i]=="close": # close
			command["user_name"]=uname
			command["type"]="close"
			i+=1
			command_array.append(command)
			
		elif args[i]=="manager_mode": #manager_mode
			command["user_name"]=uname
			command["type"]="manager_mode"
			i+=1
			command_array.append(command)
			break
		else:
			command["type"]="error" 
			i+=1
			command_array.append(command)
	return command_array


if len(sys.argv) == 3: #python client.py 5000
	portname = int(sys.argv[2]) #local host
	hostname = str(sys.argv[1]) #5000

	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	server_address = (hostname, portname)
	uname = str(input("Username : "))
	try:
		while True:
			sock.sendto(pickle.dumps({"type":"connect","user_name":uname}), server_address)
			response, sender_address = sock.recvfrom(4096)
			if pickle.loads(response)["response"] == "connected":
				print("Connecting to server network",end='')
				for i in range(5):
					time.sleep(2.4)
					print(".",end='')
					sys.stdout.flush()
				print("Now Connected!")
				print("-------------------------------------------------------\n")

				while True:
					commandline_args = str(input("cmd:>> "))
					command_array = cmdfun(uname, commandline_args.split(' '))
					for command in command_array:
						if command["type"] == "error":
							print("Invalid Input Command ... ")
							print("\n")
							break
						elif command["type"] == "close":
							sock.sendto(pickle.dumps({"type":"close" , "user_name":uname}), server_address)
			
							response, sender_address = sock.recvfrom(4096)
							if pickle.loads(response)["response"] == "disconnected":
								print("{} quits!".format(uname))
								print("Disconnecting from channel network...disconnected")
								sys.exit(0)
								break
						else:
							sock.sendto(pickle.dumps(command), server_address)
							print("Requesting to server for {}".format(command))
							response, server = sock.recvfrom(4096)
							response = pickle.loads(response)
							print("{}".format(response))
							print("\n")
			else:
				print("Invalid username !\n")
				print("Or, Username already in-use")
				break
	except KeyboardInterrupt:
		print("KeyboardInterrupt")
	finally:
		print('Closing socket')
		sock.close()
else:
	print('Two arguments are required...')


