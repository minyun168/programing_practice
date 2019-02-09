
def show_magicians(magicians):
	for magician in magicians:
		print(magician)

def make_great(magicians):

	great_magicians = []
	while  magicians:
		magician = magicians.pop()
		great_magician = magician + " is a great magician"
		great_magicians.append(great_magician)

	for great_magician in great_magicians:
		magicians.append(great_magician)

magicians = ['aclear', 'gido', 'konan']

show_magicians(magicians)

make_great(magicians)

show_magicians(magicians) 

