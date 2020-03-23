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
LL size, arr[MAXN];

struct Node {
	LL sum, prefix, suffix;
	Node() {};
	Node(LL val, LL pre, LL suf) {
		sum = val;
		prefix = pre;
		suffix = suf;
	}
} tree[3*MAXN];

Node operator + (Node &a, Node &b) {
	Node c;
	c.sum = a.sum + b.sum;
	c.prefix = max(a.prefix, a.sum + b.prefix);
	c.suffix = max(a.suffix + b.sum, b.suffix);
	return c;
};

void build(LL ss, LL se, LL si) {
	// tree[si] store the sum of array[ss...se]
	if(ss == se)	tree[si] = Node(arr[ss], max(arr[ss], 0ll), max(arr[ss], 0ll));
	else {
		LL mid = (ss+se)>>1;
		build(ss, mid, 2*si+1);
		build(mid+1, se, 2*si+2);
		// the operator here can be anything as long as it is associative
		// that is, a op (b op c) == (a op b) op c
		tree[si] = tree[2*si+1] + tree[2*si+2];
	}
}

void build(LL n) {
	size = n;
	build(0ll, n-1, 0ll);
}

void update(LL ss, LL se, LL si, LL idx, LL value) {
	if(se < idx || ss > idx || ss > se)	return;
	if(ss == se && ss == idx)	tree[si] = Node(value, max(value, 0ll), max(value, 0ll));
	else {
		LL mid = (ss+se)>>1;
		update(ss, mid, 2*si+1, idx, value);
		update(mid+1, se, 2*si+2, idx, value);
		tree[si] = tree[2*si+1] + tree[2*si+2];
	}
}

void update(LL idx, LL value) {
	update(0, size-1, 0, idx, value);
}

Node sum(LL ss, LL se, LL si, LL qs, LL qe) {
	if(se < qs || ss > qe || ss > se)	return Node(0ll, 0ll, 0ll);
	if(qs <= ss && se <= qe)	return tree[si];
	else {
		LL mid = (ss+se)>>1;
		Node left = sum(ss, mid, 2*si+1, qs, qe);
		Node right = sum(mid+1, se, 2*si+2, qs, qe);
		return left + right;
	}
}

Node sum(LL qs, LL qe) {
	return sum(0, size-1, 0, qs, qe);
}

void clear() {
	clr(arr); clr(tree);
}

void solve() {
	clear();
	sll(n); sll(q);
	rep(i, 0, n)	arr[i] = scanLong();
	build(n);
	rep(i, 0, q) {
		char c; cin >> c;
		if(c == 'Q') {
			sll(qs); sll(qe); qs--; qe--;
			LL ans = sum(qs, qe).sum;
			if(qs-1 >= 0)	ans += sum(0, qs-1).suffix;
			if(qe+1 < n)	ans += sum(qe+1, n-1).prefix;
			pll(ans); nl;
		}
		else if(c == 'U') {
			sll(idx); sll(val); idx--;
			update(idx, val);
		}
	}
}

int main() {
	sll(t);
	rep(_, 0, t)	solve();
}
