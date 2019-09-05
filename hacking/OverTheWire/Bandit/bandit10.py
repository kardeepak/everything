import config
import os, base64
from pwn import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)
data = conn.cat("data.txt")
flag = base64.b64decode(data).split().pop()

print("Flag : " + flag)