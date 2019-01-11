# person.py

def build_person(first_name, last_name, age=''):
	"""return a dictionary include the information of a person """
	person = {'first':first_name, 'last':last_name}
	
	if age:
		person['age'] = age
	#	print type(person['age'])  # here I want to check the type of age
	return person 

musician = build_person('jimi', 'hendrix', age = 27)   # here i can not writed as   'age'=27  //<crash python>P124
print (musician)
