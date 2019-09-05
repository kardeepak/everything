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

const LL MAXN = 1e5+10;
VLL adj[MAXN];
LL N, parent[MAXN], values[MAXN], mods[MAXN];

void dfs(LL src, LL par) {
	parent[src] = par;
	rep(it, adj[src].begin(), adj[src].end()) {
		if(*it != par)	dfs(*it, src);
	}
}

LL gcd(LL a, LL b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

LL getAnswer(LL src) {
	LL mod = mods[src];
	LL minG = mods[src];
	while(src != 0) {
		minG = min(minG, gcd(values[src], mod));
		src = parent[src];
	}	
	return (mod - minG);
}

int main() {
	sll(t);
	rep(_, 0, t) {
		N = scanLong();
		rep(i, 0, N-1) {
			sll(u); sll(v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		rep(i, 1, N+1)	values[i] = scanLong();
		rep(i, 1, N+1)	mods[i] = scanLong();
		dfs(1, 0);
		rep(i, 1, N+1) {
			if(adj[i].size() == 1 && parent[i] != 0)
				pll(getAnswer(i));
		} nl;
	}
}
