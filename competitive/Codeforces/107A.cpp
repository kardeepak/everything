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

const LL MAXN = 1010;
LL incoming[MAXN], outgoing[MAXN];
map<LL,LL> adj;
vector<pair<PLL,LL>> ans;

void dfs(LL src) {
	if(adj[src] == 0)	return;
	LL start = src;
	LL size = outgoing[src];
	while(adj[src] != 0) {
		size = min(outgoing[src], size);
		src = adj[src];
	}
	ans.push_back(make_pair(make_pair(start, src), size));
}

int main() {
	sll(n); sll(m);
	rep(i, 0, m) {
		sll(a); sll(b); sll(p);
		outgoing[a] = p;
		incoming[b] = p;
		adj[a] = b;
	}
	rep(i, 1, n+1) {
		if(incoming[i] == 0)	dfs(i);
	}
	pll((LL)ans.size()); nl;
	rep(it, ans.begin(), ans.end()) {
		pll(it->first.first); pll(it->first.second); pll(it->second); nl;
	}
}
