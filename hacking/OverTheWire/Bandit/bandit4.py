import config
import os
from pwn import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)
files = conn.ls("-1 inhere").split()

for file in files:
	file_type = conn.file("inhere/"+file)
	if "ASCII" in file_type:
		flag = conn.cat("inhere/"+file)
		break

conn.close()

print("Flag : " + flag)
