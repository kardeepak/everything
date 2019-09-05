import config
import os
from pwn import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)
shell = conn.process("/bin/sh", stderr="/dev/null")
cmd = "find / -size 33c -user bandit7 -group bandit6"
shell.sendline(cmd)
file = shell.recv().strip()

flag = conn.cat(file)

print("Flag : " + flag)
