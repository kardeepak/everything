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
vector<PLL> edges;
VLL adj[MAXN];
LL clr[MAXN];
bool flag = true;

void dfs(LL src, LL c, LL par) {
	clr[src] = c;
	rep(it, adj[src].begin(), adj[src].end()) {
		if(*it == par)	continue;
		if(clr[*it] == 0)	dfs(*it, (c^3), src);
		else if(clr[*it] == c)	flag = false;
	}
}

int main() {
	sll(n); sll(m);
	rep(i, 0, m) {
		sll(u); sll(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back(MP(u, v));
	}
	dfs(1ll, 1ll, 0ll);
	if(!flag)	puts("NO");
	else {
		puts("YES");
		rep(i, 0, m) {
			if(clr[edges[i].first] == 1)	cout << 0;
			else	cout << 1;
		}
		cout << endl;
	}
}
