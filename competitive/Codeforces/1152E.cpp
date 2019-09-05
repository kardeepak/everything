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
LL counter = 0;
map<LL,LL> compress, invCompress;
multiset<LL> adj[MAXN];
LL degrees[MAXN];
bool visited[MAXN];
VLL path;

void getEulerPath(LL src) {
	visited[src] = true;
	while(adj[src].size() > 0) {
		LL next = *adj[src].begin();
		adj[src].erase(adj[src].begin());
		adj[next].erase(adj[next].find(src));
		getEulerPath(next);
	}
	path.push_back(src);
}

int main() {
	sll(n);
	LL Bs[n-1], Cs[n-1];
	rep(i, 0, n-1)	Bs[i] = scanLong();
	rep(i, 0, n-1) {
		Cs[i] = scanLong();
		if(Bs[i] > Cs[i]) {
			puts("-1");
			return 0;
		}
	}
	rep(i, 0, n-1) {
		if(compress[Bs[i]] == 0) {
			compress[Bs[i]] = ++counter;
			invCompress[counter] = Bs[i];
		}
		if(compress[Cs[i]] == 0) {
			compress[Cs[i]] = ++counter;
			invCompress[counter] = Cs[i];
		}
		LL u = compress[Bs[i]], v = compress[Cs[i]];
		adj[u].insert(v);
		adj[v].insert(u);
		degrees[u]++;
		degrees[v]++;
	}
	VLL odds;
	rep(i, 1, counter+1) {
		if(degrees[i]%2 == 1)	odds.push_back(i);
	}
	if(odds.size() > 2) {
		puts("-1");
		return 0;
	}
	if(odds.size() == 0)	odds.push_back(1);
	getEulerPath(odds[0]);
	rep(i, 1, counter+1) {
		if(!visited[i]) {
			puts("-1");
			return 0;
		}
	}
	if(path.size() != n) {
		puts("-1");
		return 0;
	}
	rep(i, 0, path.size()) {
		pll(invCompress[path[i]]);
	} nl;
}
