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


int main() {
	sll(a); sll(n); sll(m);
	VLL rain(a + 1);
	vector<PLL> umb(a + 1, make_pair(LONG_MAX, -1));
	VLL costs(m);
	
	rep(i, 0, n) {
		sll(l); sll(r);
		rep(j, l, r)	rain[j] = 1;
	}
	
	rep(i, 0, m) {
		sll(x); sll(p);
		costs[i] = p;
		umb[x] = min(umb[x], make_pair(p, i));
	}
	
	vector<VLL> dp(a + 1, VLL(m + 1, LONG_MAX));
	dp[0][m] = 0;
	rep(i, 0, a) {
		rep(j, 0, m+1) {
			if (dp[i][j] == LONG_MAX)
				continue;
			if (rain[i] == 0)
				dp[i + 1][m] = min(dp[i + 1][m], dp[i][j]);
			if (j < m)
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + costs[j]);
			if (umb[i].first != LONG_MAX)
				dp[i + 1][umb[i].second] = min(dp[i + 1][umb[i].second], dp[i][j] + umb[i].first);
		}
	}
	
	LL ans = LONG_MAX;
	rep(i, 0, m+1)
		ans = min(ans, dp[a][i]);
	if (ans == LONG_MAX)
		ans = -1;
	cout << ans << endl;
	
	return 0;
}
