import config
import os
from pwn import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)

temp_dir = conn.mktemp("-d")

temp_file = temp_dir + "/tmp"

conn.xxd("-r data.txt " + temp_file)

while True:
	file_type = conn.file(temp_dir + "/tmp")
	if "gzip" in file_type:
		conn.mv(temp_file, temp_file + ".gz")
		conn.gzip("-d " + temp_file + ".gz")
	elif "bzip" in file_type:
		conn.mv(temp_file, temp_file + ".bz2")
		conn.bzip2("-d " + temp_file + ".bz2")
	elif "tar" in file_type:
		conn.mv(temp_file, temp_file + ".tar")
		newfile = conn.tar("-xvf " + temp_file + ".tar" + " -C " + temp_dir)
		conn.mv(os.path.join(temp_dir, newfile), temp_file)
	else:
		flag = conn.cat(temp_file).split().pop()
		break

print("Flag : " + flag)