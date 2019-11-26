import keyboard
from string import ascii_lowercase
from string import ascii_uppercase


def pressed1(name):
	ch = name.name
	global ctrl

	if(ch == 'esc'): # quit if esc pressed
		quit()

	if(ctrl): # check if ctrl was pressed
		keyboard.press('ctrl+'+ch)
		#ctrl = False
		return

	# juktakkhor shortcut [shift + (3 - 8)]
	if(ch == '#'):
		print(ch)
		keyboard.write(eng2beng['d']) # hosonto
		keyboard.write(eng2beng['j']) # ro
		return
	if(ch == '$'):
		print(ch)
		keyboard.write(eng2beng['j']) # ro
		keyboard.write(eng2beng['d']) # hosonto
		return
	if(ch == '%'):
		print(ch)
		keyboard.write(eng2beng['p']) # jo
		keyboard.write(eng2beng['d']) # hosonto
		keyboard.write(eng2beng['}']) # 
		return
	if(ch == '^'):
		print(ch)
		keyboard.write(eng2beng['l']) # to
		keyboard.write(eng2beng['d']) # hosonto
		keyboard.write(eng2beng['j']) # ro
		return
	if(ch == '&'):
		print(ch)
		keyboard.write(eng2beng['k']) # ko
		keyboard.write(eng2beng['d']) # hosonto
		keyboard.write(eng2beng['<']) # m sho
		return
	if(ch == '*'):
		print(ch)
		keyboard.write(eng2beng['M']) # t sho
		keyboard.write(eng2beng['d']) # hosonto
		keyboard.write(eng2beng['j']) # ro
		return

	if(name.name == 'ctrl'):
		ctrl = True

	if ch in eng2beng.keys():
		print(ch)
		keyboard.write(eng2beng[ch])
	else:
		print("pressed : " + ch)
		keyboard.press(ch) # press key if key not in eng2beng (common keys eg '!', '@' )
	
	return

def released1(name):
	ch = name.name
	global ctrl
	if ch in eng2beng.keys(): # keys present in eng2beng were suppressed during press event no need to release
		return

	keyboard.release(ch) # release key ch
	print("released : " + ch)
	if(name.name == 'ctrl'): # ctrl is released
		ctrl = False
	return

eng2beng = dict()
ctrl = False

f1 = open("./map.txt", "r", encoding="utf8") # open map.txt with utf8 encoding

lines = f1.readlines() # read lines into array

for line in lines:
	a = line.split(":")[0] # split each line by ':' left - eng char
	b = line.split(":")[1] # right - beng char
	b = b.split("\n")[0] # remove end '\n'
	eng2beng[a] = b

f1.close()

input("Press enter to start (esc to stop):")
keyboard.on_press(pressed1, suppress=True) # call pressed1 on key press event suppress the event
keyboard.on_release(released1, suppress = True) # call released1 on key release event suppress the event

keyboard.wait() # stop main thread from finishing execution




