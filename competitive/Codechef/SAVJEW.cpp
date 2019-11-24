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
LL size, values[MAXN], tree[3*MAXN];

void build(LL);
void build(LL, LL, LL);
void update(LL, LL);
void update(LL, LL, LL, LL, LL);
LL maximum(LL, LL);
LL maximum(LL, LL, LL, LL, LL);

// Build Segment Tree from values
void build(LL n) {
	size = n;
	build(0ll, n-1, 0ll);
}

void build(LL ss, LL se, LL si) {
	// tree[si] store the sum of values[ss...se]
	if(ss == se)	tree[si] = ss;
	else {
		LL mid = (ss+se)>>1;
		build(ss, mid, 2*si+1);
		build(mid+1, se, 2*si+2);
		// the operator here can be anything as long as it is associative
		// that is, a op (b op c) == (a op b) op c
		LL left = tree[2*si+1], right = tree[2*si+2];
		tree[si] = (values[left] > values[right] ? left : right);
	}
}

// Range Update
void update(LL index, LL value) {
	update(0, size-1, 0, index, value);
}

void update(LL ss, LL se, LL si, LL index, LL value) {
	if(index < ss || index > se || ss > se)	return;
	if(ss == se) {
		values[ss] = value;
		return; 
	}
	LL mid = (ss+se)>>1;
	update(ss, mid, 2*si+1, index, value);
	update(mid+1, se, 2*si+2, index, value);
	LL left = tree[2*si+1], right = tree[2*si+2];
	tree[si] = (values[left] > values[right] ? left : right);
}

// Get Sum
LL maximum(LL qs, LL qe) {
	return maximum(0, size-1, 0, qs, qe);
}

LL maximum(LL ss, LL se, LL si, LL qs, LL qe) {
	if(se < qs || ss > qe || ss > se)	return 0;
	if(qs <= ss && se <= qe)	return tree[si];
	else {
		LL mid = (ss+se)>>1;
		LL left = maximum(ss, mid, 2*si+1, qs, qe);
		LL right = maximum(mid+1, se, 2*si+2, qs, qe);
		return (values[left] > values[right] ? left : right);
	}
}

void clear() {
	clr(values); clr(tree); size = -1;
}

int main() {
	sll(t);
	rep(_, 0, t) {
		clear();
		sll(n); sll(m);
		LL copies[n];
		rep(i, 0, n)	copies[i] = values[i] = scanLong();
		build(n);
		LL stopSteal = -1;
		rep(i, 0, m) {
			sll(l); sll(r); l--; r--;
			LL maxIndex = maximum(l, r);
			if(stopSteal == -1 || values[maxIndex] > values[stopSteal])
				stopSteal = maxIndex;
			update(maxIndex, 0ll);
		}
		
	}
}
