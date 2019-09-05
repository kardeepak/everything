import config
import os, re, base64
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)
secret_url = url + "/index-source.html"

response = get(secret_url, auth=(user, password))
encoded_secret = re.findall(r"\"(?P<secret>\w+)\"\;", response.content)[0]
decoded_secret = base64.b64decode(encoded_secret.decode("hex")[::-1])

response = post(url, auth=(user, password), data={"secret" : decoded_secret,  "submit" : 1})
password = re.findall(r"\w{32}", response.content)[-1]

print(password)
