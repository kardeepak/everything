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

const LL MAXN = 1e5+10;
LL size, array[MAXN], tree[3*MAXN], lazy[3*MAXN];

// Build Segment Tree from array
void build(LL n) {
	size = n;
	build(0ll, n-1, 0ll);
}

void build(LL ss, LL se, LL si) {
	// tree[si] store the sum of array[ss...se]
	if(ss == se)	tree[si] = array[ss];
	else {
		LL mid = (ss+se)>>1;
		build(ss, mid, 2*si+1);
		build(mid+1, se, 2*si+2);
		// the operator here can be anything as long as it is associative
		// that is, a op (b op c) == (a op b) op c
		tree[si] = tree[2*si+1] + tree[2*si+2];
	}
}

// Propagate Values from lazy to its children
void propagate(LL ss, LL se, LL si) {
	// This function will change based on the operation
	if(lazy[si] != 0) {
		// Adding the lazy[si] the subarray sum of array[ss...se]
		tree[si] += (se-ss+1) * lazy[si];
		if(ss != se) {
			// passing lazy[si] to its children
			lazy[2*si+1] += lazy[si];
			lazy[2*si+2] += lazy[si];
		}
		lazy[si] = 0;
	}
}

// Range Update
void update(LL qs, LL qe, LL value) {
	update(0, size-1, 0, qs, qe, value);
}

void update(LL ss, LL se, LL si, LL qs, LL qe, LL value) {
	if(se < qs || ss > qe || ss > se)	return;
	propagate(ss, se, si);
	if(qs <= ss && se <= qe) {
		tree[si] += (se-ss+1) * value;
		if(ss != se) {
			// lazy[si] stores the value needed to be added to the subarray array[ss...se]
			lazy[2*si+1] += value;
			lazy[2*si+2] += value;
		}
	}
	else {
		LL mid = (ss+se)>>1;
		update(ss, mid, 2*si+1, qs, qe, value);
		update(mid+1, se, 2*si+2, qs, qe, value);
		tree[si] = tree[2*si+1] + tree[2*si+2];
	}
}

// Get Sum
LL sum(LL qs, LL qe) {
	return sum(0, size-1, 0, qs, qe);
}

LL sum(LL ss, LL se, LL si, LL qs, LL qe) {
	if(se < qs || ss > qe || ss > se)	return 0;
	propagate(ss, se, si);
	if(qs <= ss && se <= qe)	return tree[si];
	else {
		LL mid = (ss+se)>>1;
		LL left_sum = sum(ss, mid, 2*si+1, qs, qe);
		LL right_sum = sum(mid+1, se, 2*si+2, qs, qe);
		return left_sum + right_sum;
	}
}

// Implementation Details : https://cp-algorithms.com/data_structures/segment_tree.html#toc-tgt-1

int main() {
}
