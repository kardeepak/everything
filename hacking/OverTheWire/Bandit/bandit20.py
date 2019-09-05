from pwn import *
import os, time
import config

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)

shell = conn.process("/bin/sh", stderr="/dev/null")

shell.sendline("tmux -c \"echo GbKksEFF4yrVs6il55v6gwY5aVje5f0j | nc -l -p 1234 &\"")

shell.sendline("/home/bandit20/suconnect 1234; exit")

flag = ""
while True:
	try:
		tmp = shell.recvline()
		flag = tmp
	except:
		break

print("Flag : " + flag)
print("If you don't get the flag in first try, run it again after few minutes.")
print("I'm not sure why the complete data is not transferred in the first time.")