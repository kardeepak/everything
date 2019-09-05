import config
import os
from pwn import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)
flag = conn.cat("\"spaces in this filename\"")
conn.close()

print("Flag : " + flag)
