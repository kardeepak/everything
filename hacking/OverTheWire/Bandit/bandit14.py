import config
import os
from pwn import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)

nc = conn.process(["/bin/nc", "localhost", "30000"])
nc.sendline(password)
flag = nc.recv().split().pop()

print("Flag : " + flag)