from math import factorial as f
from itertools import combinations
import sys

def ncr(n, r):
	try:
		return (f(n)/(f(n-r)*f(r)))
	except:
		return -1


N = int(sys.argv[1])

def attacks(a, b, arrangement):
	if a[0] == b[0] and a[1] == b[1]:
		return False

	if a[0] == b[0]:
		for i in range(a[1]+1, b[1]):
			if (a[0], i) in arrangement:
				return False
		return True

	if a[1] == b[1]:
		for i in range(a[0]+1, b[0]):
			if (i, a[1]) in arrangement:
				return False
		return True

	return False



def getPairs(arrangement):
	pairs = 0
	for a, b in combinations(arrangement, 2):
		if attacks(a, b, arrangement):
			pairs += 1
	return pairs
		


allpos = [(i, j) for i in range(N) for j in range(N)]

arrangements = combinations(allpos, N)

data = {}

for arrangement in arrangements:
	board = [['-' for i in range(N)] for j in range(N)]
	for pos in arrangement:
		board[pos[0]][pos[1]] = 'x'

	x = getPairs(arrangement)
	if x not in data:
		data[x] = 0
	data[x] += 1

	# if x == 7:
	# 	print("\n".join("".join(x) for x in board))
	# 	print("")

for a, b in sorted(data.items(), key=lambda x: x[0]):
	print(f"{a} : {b} \t {2* b / N / (N-1)}")

print(sum(data.values()))



print("NcR : " + str(f(N*N)/f(N)/f(N*N-N)))

