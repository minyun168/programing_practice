#greeter2.py

def formatted_name(first_name, last_name):
	
	full_name = first_name + ' ' +last_name
	return full_name.title()

# keep loop
while True:
	print("\nPlease tell me your name:")
	print("(enter 'q' at any time to quit)")

	f_name = input("first_name:")        # When we input we shoud code in str just like: 'A' ,'clear'; do not forget quotation marks
	if f_name == 'q':
		break

	l_name = input("last_name:")
	if l_name == 'q':
		break
	
	formatted_name = formatted_name(f_name, l_name)
	print("\n Hello, "+ formatted_namf + "!")