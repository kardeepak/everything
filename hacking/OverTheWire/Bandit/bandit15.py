import config
import os
from pwn import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)

ssl = conn.process(["/usr/bin/openssl", "s_client", "-connect", "localhost:30001"])
ssl.sendline(password)
flag = ssl.recvall().split()[-2]

print("Flag : " + flag)