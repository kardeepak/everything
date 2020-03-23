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

const LL MAXN = 1e5+10, MAXQ = 1e5+10;
LL beauty = 0;
LL A[MAXN], C[MAXN];
LL sumA[MAXN];
LL P[MAXN][20], depth[MAXN];
LL startTime[MAXN];
VLL adj[MAXN];
LL t = 0;
set<array<LL, 2>> color_map[MAXN];


void dfs(LL src, LL par) {
	P[src][0] = par;
	sumA[src] = A[src] + (par != -1 ? sumA[par] : 0);
	depth[src] = (par != -1 ? depth[par] + 1 : 0);
	startTime[src] = ++t;
	rep(i, 1, 20) {
		P[src][i] = P[P[src][i-1]][i-1];
	}

	rep(it, adj[src].begin(), adj[src].end()) {
		if(P[*it][0] == 0 && *it != par)
			dfs(*it, src);
	}
}

LL lca(LL a, LL b) {
	if(depth[a] > depth[b])	swap(a, b);
	while(depth[a] != depth[b]) {
		rep(i, 20, 0) {
			if(depth[P[b][i]] >= depth[a])
				b = P[b][i];
		}
	}

	while(P[a][0] != P[b][0]) {
		rep(i, 20, 0) {
			if(P[a][i] != P[b][i]) {
				a = P[a][i];
				b = P[b][i];
			}
		}
	}

	return P[a][0];
}

void clear() {
	clr(startTime);
	rep(i, 0, (LL)MAXN) {
		adj[i].clear();
		color_map[i].clear();
	}
	clr(A); clr(C); clr(P);
}

void color(LL node, LL op) {
	LL par = -1;
	auto it = color_map[C[node]].lower_bound({startTime[node]});
	if(it != color_map[C[node]].begin()) {
		--it;
		par = lca(node, (*it)[1]);
		++it;
	}
	if(it != color_map[C[node]].end()) {
		LL p = lca(node, (*it)[1]);
		if(par < 0 || depth[p] > depth[par])
			par = p;
	}

	beauty += op * (sumA[node] - (par != -1 ? sumA[par] : 0));
}

void solve() {
	clear();
	sll(n); sll(q);
	rep(i, 0, n-1) {
		sll(u); sll(v);
		adj[u].push_back(v);
		adj[v].push_back(v);
	}
	dfs(1, -1);

	rep(i, 1, n+1) {
		C[i] = scanLong();
	}
	rep(i, 1, n+1) {
		A[i] = scanLong();
	}

	rep(i, 1, n+1) {
		color(i, 1ll);
		color_map[C[i]].insert({startTime[i], i});

	}

	rep(i, 0, q) {
		sll(a); sll(x);

		color_map[C[a]].erase({startTime[a], a});
		color(a, -1);
		C[a] = x;

		color(a, 1);
		color_map[C[a]].insert({startTime[a], a});

		pll(beauty); nl;
	}
}

int main() {
	sll(t);
	rep(_, 0, t) {
		solve();
	}
}
