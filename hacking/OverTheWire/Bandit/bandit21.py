from pwn import *
import os
import config

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)

flag = conn.cat("/tmp/t7O6lds9S0RqQh9aMcz6ShpAoZKF7fgv")

print("Flag : " + flag)
