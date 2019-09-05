from pwn import *
import os
import config

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)

shell = conn.process("/bin/sh")

shell.sendline("/home/bandit19/bandit20-do cat /etc/bandit_pass/bandit20; exit")

flag = shell.recvall().split().pop()

print("Flag : " + flag)
