import config
import os, time
from pwn import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)

shell = conn.process(["/usr/bin/ssh",  "-i", "sshkey.private", "bandit14@localhost"], stderr="/dev/null")
shell.sendline("yes")
shell.sendline("cat /etc/bandit_pass/bandit14; exit")
flag = shell.recvall()

print("Flag : " + flag.split()[-2])