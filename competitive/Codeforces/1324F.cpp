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
VLL adj[MAXN];
LL color[MAXN], dp[MAXN], ans[MAXN];

void dfs(LL src = 1, LL par = -1) {
	dp[src] = color[src];
	rep(it, adj[src].begin(), adj[src].end()) {
		if(*it != par) {
			dfs(*it, src);
			dp[src] += max(0ll, dp[*it]);
		}
	}
}

void move(LL from, LL to) {
	if(from == to)	return;
	dp[from] -= max(0ll, dp[to]);
	dp[to] += max(0ll, dp[from]);
}

void dfs2(LL src = 1, LL par = -1) {
	if(par != -1)	move(par, src);
	ans[src] = dp[src];
	rep(it, adj[src].begin(), adj[src].end()) {
		if(*it != par)	dfs2(*it, src);
	}
	if(par != -1)	move(src, par);
}


int main() {
	sll(n);
	rep(i, 1, n+1)	color[i] = (scanLong() == 1 ? 1 : -1);
	rep(i, 0, n-1) {
		sll(a); sll(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	dfs2();
	rep(i, 1, n+1)	pll(ans[i]); nl;
}
