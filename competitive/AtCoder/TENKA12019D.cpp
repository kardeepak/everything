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
const LL MOD = 998244353;

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

LL modpow(LL a, LL n, LL m) {
	LL r = 1;
	while(n != 0) {
		if(n&1)	r = (r*a)%m;
		a = (a*a)%m;
		n >>= 1;
	}
	return r;
}

const LL MAXN = 310, MAXSUM = 90000 + 10;
LL dp[MAXN][MAXSUM], dp2[MAXN][MAXSUM];

int main() {
	sll(n);
	LL nums[n], sum = 0;
	rep(i, 0, n) { 
		nums[i] = scanLong();
		sum += nums[i];
	}
	LL ans = modpow(3, n, MOD);
	rep(i, 0, n+1) {
		rep(j, 0, sum+1) {
			if(i == 0)	dp[i][j] = (j == 0 ? 1 : 0);
			else if(j == 0)	dp[i][j] = modpow(2, i, MOD);
			else if(nums[i-1] <= j)	dp[i][j] = 2*dp[i-1][j] + dp[i-1][j-nums[i-1]];
			else	dp[i][j] = 2*dp[i-1][j];
			dp[i][j] %= MOD;

			if(i == 0)	dp2[i][j] = (j == 0 ? 1 : 0);
			else if(j == 0)	dp2[i][j] = 1;
			else if(nums[i-1] <= j)	dp2[i][j] = dp2[i-1][j] + dp2[i-1][j-nums[i-1]];
			else	dp2[i][j] = dp2[i-1][j];
			dp2[i][j] %= MOD;

			if(i == n && 2*j >= sum) {
				ans -= 3*dp[i][j];
				while(ans < 0)	ans += MOD;
			}
			if(i == n && 2*j == sum) {
				ans += 3*dp2[i][j];
				ans %= MOD;
			}
		}
	}
	pll(ans); nl;
}
