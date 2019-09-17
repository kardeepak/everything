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

const LL MAXN = 2e5+10;
LL size;
LL array[MAXN], tree[MAXN];

// g(i) will remove all trailing ones in the binary representation of i
inline g(i) { return i&(i+1); }

// h(i) will set the last unset bit in the binary representation of i
// h(i) will iterate over all the j such that g(j) <= i <= j
inline h(i) { return i|(i+1); }

// tree[i] stores sum of subarray array[g(i)...i] where 0 <= g(i) <= i
void build(LL n) {
	size = n;
	rep(i, 0, n)	update(i, array[i]);
}

// Point update
void update(LL index, LL value) {
	// updating all T[j] such that g(j) <= index <= j
	while(index < size) {
		tree[index] += value;
		index = h(index);
	}
}


// Return prefix sum of array[0...index]
LL sum(LL index) {
	LL sum = 0;
	while(index >= 0) {
		// Adding sum of subarray array[g(index)...index]
		sum += tree[index];
		// Moving index to g(index) - 1
		index = g(index) - 1;
	}
	return sum;
}

LL sum(LL left, LL right) {
	return sum(right) - sum(left-1);
}

// Implementation Details : https://cp-algorithms.com/data_structures/fenwick.html#toc-tgt-2

int main() {
}
