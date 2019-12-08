from pwn import *
import os, re
import config

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)

output = conn.nmap(["localhost","-p","31000-32000"])
ports = re.findall(r"(\d+)/tcp open", output)

for port in ports:
	ssl = conn.process(["/usr/bin/openssl", "s_client", "-connect", "localhost:"+port])
	try:
		ssl.recv()
		ssl.sendline(password)
		data = ssl.recv()
		if "Correct!" in data:
			break
	except:
		pass

flag = ""
started = False

for line in data.split("\n"):
	if "-----BEGIN RSA PRIVATE KEY-----" in line:
		started = True
	if started:
		flag += line + "\n"
	if "-----END RSA PRIVATE KEY-----" in line:
		started = False

print("Flag : " + flag)
print("Save this flag in a file and provide path of file in next level.")