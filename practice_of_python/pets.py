#pets.py

def describe_pet(animal_type="pig", pet_name="dengzhizhu"):
	"""The information of pets"""
	print ("\nI have a "+animal_type+".")
	print ("My "+animal_type+" is "+pet_name+".")

describe_pet("pig","dengzhizhu")
describe_pet("monkey","hou")
describe_pet(animal_type="monkey", pet_name="hou")
