import config
import os, string
from pwn import *

rot13 = string.maketrans( 
   	"ABCDEFGHIJKLMabcdefghijklmNOPQRSTUVWXYZnopqrstuvwxyz", 
    "NOPQRSTUVWXYZnopqrstuvwxyzABCDEFGHIJKLMabcdefghijklm")

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

conn = ssh(host=config.url, user=user, password=password, port=config.port)
data = conn.cat("data.txt")

flag = string.translate(data, rot13).split().pop()

print("Flag : " + flag)