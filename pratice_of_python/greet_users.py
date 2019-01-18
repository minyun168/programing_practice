#

def greet_users(names):
	"""greet everbody in the list"""
	for name in names:
		msg = "hello, " + name.title() + "!"
		print (msg)


usernames = ['Harry potte','angerbaby','lihua']
greet_users = greet_users(usernames)
print (greet_users)
