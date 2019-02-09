#

def magicians(magicians_names):
	if magicians_names:
		#magicians_name == magicians_names.pop
		for magicians_name in magicians_names:
			print (magicians_name)
def make_great(magicians_names,great_magicians_names):
	#if great_magicians_names:
	while magicians_names:
		magician_name = magicians_names.pop()
		great_magician_name = "the great magicians' name is " + magician_name
		print (great_magician_name)
		great_magicians_names.append(great_magician_name)

magicians_names = ['aclear', 'gido', 'konan']
great_magicians_names = []
magicians(magicians_names)
make_great(magicians_names, great_magicians_names)