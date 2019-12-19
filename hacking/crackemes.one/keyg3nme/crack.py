from pwn import *

# Scans and integer and checkes `key % 1223 == 0`
p = process("./keyg3nme")
p.sendline("1223")
print(p.recvline())