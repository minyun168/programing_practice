

def formatted_name(first_name, last_name, middle_name = ""):   #when we use default value just like middle_name="", we should make sure middle_name is the last variable when we define function
	"""return formatted name"""								   # middle_name = "" not middle = " "

	if middle_name:
		full_name = first_name + " " + middle_name + " " + last_name
		
	else:
		full_name = first_name + " " + last_name
	return full_name.title()
	
musician = formatted_name("sheeli", "arki", "habarum")
print (musician)

artist = formatted_name("shor", "ka")
print (artist)
