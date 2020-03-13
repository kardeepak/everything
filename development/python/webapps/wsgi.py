from pprint import pprint
import time 
def app(environ, start_fn):
    start_fn("200 OK", [('Content-Type', 'text/plain')])
    pprint(environ)
    return [b"Hello World!\n"]