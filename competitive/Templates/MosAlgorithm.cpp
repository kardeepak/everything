#include <bits/stdc++.h>
#include <climits>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define srep(i, begin, end) for (__typeof(end) i = begin; i != end; i++)
#define si(x) int x = scanInt();
#define sll(x) LL x = scanLong();
#define sci(x) int x; scanf("%d", &x);
#define scll(x) LL x; scanf("%lld", &x);
#define pi(x) printf("%d ", x)
#define pll(x) printf("%lld ", x)
#define nl printf("\n")
#define clr(a) memset(a, 0, sizeof(a))
#define PB push_back
#define MP make_pair
using namespace std;
typedef unsigned int UI; // 32 bit integer
typedef long int LI; // 32 bit integer
typedef unsigned long int ULI; // 32 bit unsigned integer
typedef long long int LL; // 64 bit integer
typedef unsigned long long int ULL; // 64 bit unsigned integer
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef deque<int> DI;
typedef deque<LL> DLL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const LL MOD = 1e9+7;

/* Fast I/O */
inline int scanInt() {
	int n = 0;
	char ch = getchar();
	int sign = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-')	sign = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		n = (n<<1)+(n<<3)+(int)(ch-'0');
		ch = getchar();
	}
	return n*sign;
}

inline LL scanLong() {
	LL n = 0;
	char ch = getchar();
	LL sign = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-')	sign = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		n = (n<<1)+(n<<3)+(LL)(ch-'0');
		ch = getchar();
	}
	return n*sign;
}

struct Query {
	LL left, right, index;
	bool operator < (Query other) {
		return MP(left / BLOCK_SIZE, right) < MP(other.left / BLOCK_SIZE, other.right);
	}
};

const LL MAXN = 2e5+10;
const LL MAXQ = 2e5+10;
vector<Query> queries;
LL array[MAXN], answers[MAXQ];
LL BLOCK_SIZE = 448; // ceil(sqrt(MAXN))

// add, remove & getAnswer Must be O(F) functions
// Add to Data Structure
void add(LL index);
// Remove from Data Structure
void remove(LL index);
// Get Answer from Data Structure
LL getAnswer();

// Complexity of mo's algorithm is O((N + Q) * sqrt(N) * F)
void mosAlgorithm() {
	// Sort queries by first the block and by right index if blocks are same
	sort(queries.begin(), queries.end());
	// Current range is empty
	LL currLeft = 0, currRight = -1;
	rep(it, queries.begin(), queries.end()) {
		LL left = it->left, right = it->right;
		// As long as the current range is not the same as the query range 
		// keep adding or removing elements as needed
		while(currLeft > left)		add(--currLeft);
		while(currRight < right)	add(++currRight);
		while(currLeft < left)		remove(currLeft++);
		while(currRight > right)	remove(currRight--);
		// When current range is same as the query range store the answer from data structure
		answers[it->index] = getAnswer();
	}
}

int main() {
}
