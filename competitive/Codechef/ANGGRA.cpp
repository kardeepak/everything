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
LL factorial[MAXN];

LL modpow(LL a, LL n, LL m) {
	LL res = 1;
	while(n != 0) {
		if(n&1)	res = (res * a) % m;
		a = (a * a) % m;
		n >>= 1;
	}
	return res;
}

LL modinv(LL a, LL m) {
	// only if m is prime
	return modpow(a, m-2, m);
}

void init() {
	rep(i, 0, (LL)MAXN) {
		if(i == 0)	factorial[i] = 1;
		else	factorial[i] = (factorial[i-1] * i)	% MOD;
	}
}

LL combinations(LL n, LL k, LL m) {
	LL res = factorial[n] * modinv((factorial[n-k] * factorial[k]) % m, m);
	return res % m;
}

int main() {
	init();
	sll(t);
	rep(_, 0, t) {
		sll(n); sll(m); sll(k);
		LL ans = 0;
		rep(j, k, n+1) {
			ans += (combinations(n, n-j, MOD) * modpow(m-1, n-j, MOD)) % MOD;
			ans %= MOD;
		}
		pll(ans); nl;
	}
}
