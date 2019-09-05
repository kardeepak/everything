from pwn import *
import os, re
import config

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)

flag = conn.cat("readme")

print("Flag : " + flag)