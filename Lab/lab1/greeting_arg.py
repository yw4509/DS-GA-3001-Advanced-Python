import argparse

def main(greeting, name):
	print("{}, {}!".format(greeting, name))
 
if __name__ == "__main__":

	parser = argparse.ArgumentParser()

	parser.add_argument("-n", "--name", default = "Lily", 
						help = "name of user")
	
	parser.add_argument("-g", "--greeting", default = "Hello", 
						help = "optional alternate greeting")
	
	args = parser.parse_args()
	main(args.greeting, args.name)
