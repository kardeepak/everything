import config
import os
from pwn import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)
shell = conn.process("/bin/sh", stderr="/dev/null")
cmd = "strings data.txt | grep ===; exit"
shell.sendline(cmd)

lines = shell.recvall().split()

for line in lines:
	flag = line.split().pop()
	if len(flag) == 32:
		break

print("Flag : " + flag)