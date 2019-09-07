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

const LL MAXN = 1e5+10;
LL values[MAXN];
VLL adj[MAXN];
LL dp1[MAXN]; // max path sum in subtree of i
LL dp2[MAXN]; // max sum of longest path starting at i going only down with only +ve integers
LL dp3[MAXN]; // max sum of longest path starting at some node in subtree of i only going down with only +ve integers

void dfs(LL src, LL par) {
	dp1[src] = 0;
	dp2[src] = (values[src] > 0 ? values[src] : 0);
	dp3[src] = (values[src] > 0 ? values[src] : 0);
	VLL maxm;
	rep(it, adj[src].begin(), adj[src].end()) {
		if(*it != par) {
			dfs(*it, src);
			if(values[src] > 0) {
				dp2[src] = max(dp2[src], dp2[*it] + values[src]);
			}
			dp3[src] = max(dp3[src], dp3[*it]);
		}
	}
	dp3[src] = max(dp3[src], dp2[src]);
}

int main() {
	sll(t);
}
