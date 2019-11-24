
def remove_punc(word):
	symbols = [".",",",";",":","'"]
	for s in symbols:
		word = word.replace(s, '')
	return word

n = int(input())

words = []
for _ in range(n):
	line = input()
	words += map(remove_punc, line.split())

print(' '.join(words[::-1]))