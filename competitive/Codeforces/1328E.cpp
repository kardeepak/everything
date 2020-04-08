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
LL par[MAXN][20], depth[MAXN];

void dfs(LL s = 1, LL p = -1, LL d = 0) {
	depth[s] = d;

	par[s][0] = p;
	rep(i, 1, 20) {
		if(par[s][i-1] != -1)
			par[s][i] = par[par[s][i-1]][i-1];
		else
			par[s][i] = -1;
		if(par[s][i] == 0)	par[s][i] = -1;
	}

	rep(it, adj[s].begin(), adj[s].end()) {
		if(*it != p)	dfs(*it, s, d+1);
	}
	
}

bool compare(LL a, LL b) {
	return depth[a] < depth[b];
}

LL getPar(LL node, LL limit) {
	while(depth[node] > limit) {
		rep(i, 20, 0) {
			if(par[node][i] == -1)	continue;
			LL p = par[node][i];
			if(depth[p] >= limit)	node = p;
		}
	}
	return node;
}

int main() {
	sll(n); sll(q);
	rep(i, 0, n-1) {
		sll(u); sll(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();

	rep(i, 0, q) {
		sll(k);
		deque<LL> query;
		LL deepestNode = -1;
		rep(j, 0, k) {
			LL node = scanLong();
			if(par[node][0] != -1)	node = par[node][0];
			query.push_back(node);
			if(deepestNode == -1 || depth[deepestNode] < depth[node]) {
				deepestNode = node;
			}
		}
		sort(query.begin(), query.end(), compare);

		LL curr = deepestNode;
		while(curr != -1) {
			curr = getPar(curr, depth[query.back()]);

			if(query.back() != curr)	break;
			while(!query.empty() && query.back() == curr)	query.pop_back();
			if(query.empty())	break;			
		}

		if(query.empty())	puts("YES");
		else	puts("NO");
	}
}
