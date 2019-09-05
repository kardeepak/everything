from pwn import *
import os, re
import config

user = os.path.splitext(__file__)[0]
keyfile = raw_input("Enter keyfile path: ").strip()

conn = ssh(host=config.url, user=user, keyfile=keyfile, port=config.port)

data = conn.diff("passwords.old", "passwords.new")

flag = re.findall(r">\s(.*)", data)[0]

print("Flag : " + flag)