

def formatted_name(first_name, last_name):
	"""return formatted name"""

	full_name = first_name + " " + last_name
	return full_name.title()

musician = formatted_name("sheeli", "habarum")
print (musician)