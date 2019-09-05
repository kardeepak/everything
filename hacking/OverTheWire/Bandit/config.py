import os, sys

# set stderr to null
if os.getenv("DEBUG") is None:
	sys.stderr = open(os.devnull, "w")

game = "bandit"

url = game + ".labs.overthewire.org"

port = 2220
