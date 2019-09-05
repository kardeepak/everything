import config
import os
from pwn import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)
shell = conn.process("/bin/sh")
cmd = "sort data.txt | uniq --unique; exit"
shell.sendline(cmd)
shell.recv()
flag = shell.recv().strip()
conn.close()

print("Flag : " + flag)
