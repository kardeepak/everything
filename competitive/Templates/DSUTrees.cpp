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
#define ps(x) printf("%s", x)
#define nl printf("\n")
#define clr(a) memset(a, 0, sizeof(a))
using namespace std;
typedef unsigned int UI; // 32 bit integer
typedef long int LI; // 32 bit integer
typedef unsigned long int ULI; // 32 bit unsigned integer
typedef long long int LL; // 64 bit integer
typedef unsigned long long int  ULL; // 64 bit unsigned integer
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
LL mod = 1e9+7;

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
VLL adj[MAXN];
LL bigChild[MAXN], subTreeSize[MAXN];

void getSizes(LL src, LL par) {
	subTreeSize[src] = 1;
	LL big = -1;
	rep(it, adj[src].begin(), adj[src].end()) {
		if(*it != par) {
			getSizes(*it, src);
			subTreeSize[src] += subTreeSize[*it];
			if(big == -1 || subTreeSize[big] < subTreeSize[*it])	big = *it;
		}
	}
	bigChild[src] = big;
}

void add(LL src, LL par, LL big) {
	// Insert to DS
	rep(it, adj[src].begin(), adj[src].end()) {
		if(*it != par && *it != big)
			add(*it, src, big);
	}
}

void remove(LL src, LL par) {
	// Remove from DS
	rep(it, adj[src].begin(), adj[src].end()) {
		if(*it != par)
			remove(*it, src);
	}
}

void dfs(LL src, LL par) {
	rep(it, adj[src].begin(), adj[src].end()) {
		if(*it != par && *it != bigChild[src]) {
			dfs(*it, src);
			remove(*it, src);
		}
	}
	if(bigChild[src] != -1)	dfs(bigChild[src], src);
	add(src, par, bigChild[src]);
	// Query the DS
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
#endif
	sll(t);
	while(t-->0) {
		// write your code here...
	}
}
