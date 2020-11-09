import socket
import sys,time
import pickle

#list of the user details 
class UserDetails:
	def __init__(self):
		self.data = {}

	def add_data(self, key,data):
		self.data[key]=data

	def search_data(self, key):
		if self.data.get(key,-1)==-1:
			return str("404 :- Data not Found for this key")
		else:
			return self.data.get(key,-1)


users = {}

#Creates TCP/IP socket 
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

#Binds the socket to the port 
server_address = ('', 5000) #127.0.0.1 5000
print('Starting up on host {} port {}'.format(*server_address))
sock.bind(server_address)

while True:
	packet, address = sock.recvfrom(4096) #waiting to receive the message 
	packet = pickle.loads(packet)

	#connect to the client
	if packet["type"] == "connect":
		if users.get(packet["user_name"],-1)==-1:
			uname=packet["user_name"]
			users[uname]=UserDetails()
			users[uname].add_data("authority" , "guest") #by default 

			#source,destination
			sock.sendto(pickle.dumps({"response":"connected"}), address) #sends to the client 
			time.sleep(11.6)
			sys.stdout.flush()
			print("User added {}".format(uname),"authority mode(default):Guest",sep="<~~>")
			print("\n")
		else:
			sock.sendto(pickle.dumps({"response":"failed to connect"}), address)
			print("\n")

	#close server
	elif packet["type"] == "close":
		if users.get(packet["user_name"],-1)!=-1:
			sock.sendto(pickle.dumps({"response":"disconnected"}), address)
			print("User removed {}".format(uname))
			del users[packet["user_name"]]

	#get key :- search data
	elif packet["type"] == "get":
		sock.sendto(pickle.dumps({"response":users[packet["user_name"]].search_data(packet["key"])}), address)
	
	#put key :- Adding data 
	elif packet["type"] == "put":
		users[packet["user_name"]].add_data(packet["key"],packet["data"])
		sock.sendto(pickle.dumps({"response":"data added successfully"}), address)
	
	#Only manager can do that...
	elif packet["type"] == "get_other": 
		if users[packet["user_name"]].search_data("authority") == "manager":
			sock.sendto(pickle.dumps({"response":users[packet["user_name2"]].search_data(packet["key"])}), address)
		else:
			sock.sendto(pickle.dumps({"response":"not authorized"}), address)
	
	#Request server to approve manager  
	elif packet["type"] == "manager_mode":
		print("{} wants to be the manager :".format(uname))
		accept = str(input("Accept/Reject : "))
		if accept=="Accept" or accept=="accept":
			users[packet["user_name"]].add_data("authority","manager")
			sock.sendto(pickle.dumps({"response":"authority update successful"}), address)
			print("User approved {}'s authority mode: Manager".format(uname))
		else:
			sock.sendto(pickle.dumps({"response":"discarded"}), address)
			print("User rejected {}'s authority: Manager".format(uname))

