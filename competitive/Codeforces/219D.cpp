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
typedef unsigned long long int  ULL; // 64 bit unsigned integer
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
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
map<PLL, LL> edges;
VLL adj[MAXN];
LL parent[MAXN], level[MAXN];
LL toroot[MAXN]; // number of edges to be reversed to get to root from i-th node
LL subtree[MAXN]; // number of edges to be reverse to get to all nodes in it's subtree
LL revReq[MAXN];

void dfs(LL src, LL par) {
	parent[src] = par;
	level[src] = level[par] + 1;
	toroot[src] = toroot[par] + edges[MP(par, src)];
	subtree[src] = 0;
	rep(it, adj[src].begin(), adj[src].end()) {
		if(*it != par) {
			dfs(*it, src);
			subtree[src] += subtree[*it] + edges[MP(*it, src)];
		}
	}
}

int main() {
	sll(n);
	rep(i, 0, n-1) {
		sll(u); sll(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges[MP(u, v)] = 1;
	}
	dfs(1, 0);
	rep(i, 1, n+1)	revReq[i] = subtree[1] - ((level[i] - level[1]) - toroot[i]) + toroot[i];
	LL minRevReq = *min_element(revReq+1, revReq+n+1);
	pll(minRevReq); nl;
	rep(i, 1, n+1) {
		if(revReq[i] == minRevReq)	pll(i);
	} nl;
}
