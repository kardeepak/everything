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


const LL MAXN = 1e6+10;
LL size, tree[3*MAXN];

void build(LL n) {
	size = n;
	clr(tree);
}

// Range Update
void update(LL ss, LL se, LL si, LL index, LL value) {
	if(index < ss || index > se)	return;
	if(ss == se && ss == index) {
		tree[si] += value;
	}
	else {
		LL mid = (ss+se)>>1;
		update(ss, mid, 2*si+1, index, value);
		update(mid+1, se, 2*si+2, index, value);
		tree[si] = tree[2*si+1] + tree[2*si+2];
	}
}

void update(LL index, LL value) {
	update(0, size-1, 0, index, value);
}

LL query(LL ss, LL se, LL si, LL k) {
	if(ss > se)	return 0;
	if(ss == se || ) {
		return ss;
	}
	LL left = tree[2*si+1];
	LL right = tree[2*si+2];
	LL mid = (ss+se)>>1;
	if(left >= k)	return query(ss, mid, 2*si+1, k);
	else	return query(mid+1, se, 2*si+2, k-left);
}

LL query(LL k) {
	return query(0, size-1, 0, k);
}

LL getCount(LL ss, LL se, LL si, LL index) {
	if(index < ss || index > se)	return 0;
	if(ss == se)	return tree[si];
	LL mid = (ss+se)>>1;
	if(index <= mid)	return getCount(ss, mid, 2*si+1, index);
	else				return getCount(mid+1, se, 2*si+2, index);
}

LL getCount(LL index) {
	return getCount(0, size-1, 0, index);
}

int main() {
	sll(n); sll(q);
	build(MAXN);
	rep(i, 1, n+1) {
		sll(num);
		update(num, 1);
	}
	rep(i, 0, q) {
		sll(k);
		if(k > 0)	update(k, 1);
		else {
			LL p = query(abs(k));
			update(p, -1);
		}
	}
	LL p = query(1);
	if(p > n)	p = 0;
	pll(p); nl;
}
