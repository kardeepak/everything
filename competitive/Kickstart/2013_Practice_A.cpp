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

set<string> nodes;
map<string, vector<string> > edges;
map<string, LL> color;
bool bipartite = true;

void dfs(string src, LL clr) {
	color[src] = clr;
	rep(it, edges[src].begin(), edges[src].end()) {
		if(color[*it] == 0)	dfs(*it, clr^3);
		else if(color[*it] == clr)	bipartite = false;
	}
}

int main() {
	sll(t);
	rep(x, 1, t+1) {
		printf("Case #%lld: ", x);
		nodes.clear(); edges.clear(); color.clear(); bipartite = true;
		sll(m);
		rep(i, 0, m) {
			string a, b; cin >> a >> b;
			nodes.insert(a); nodes.insert(b);
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		dfs(*nodes.begin(), 1);
		if(bipartite)	puts("Yes");
		else	puts("No");
	}
}
