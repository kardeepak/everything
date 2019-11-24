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

LL modpow(LL a, LL n, LL m) {
	if(n == 0)	return 1;
	if(n == 1)	return a%m;
	if(n == 2)	return (a*a)%m;
	LL res = 1;
	while(n != 0) {
		if(n%2 == 1)	res = (res*a)%m;
		n >>= 1;
		a = (a*a)%m;
	}
	return res;
}

LL modinv(LL a, LL m) {
	return modpow(a, m-2, m);
}

const LL MAXN = 1010;
LL factorial[MAXN];

void init() {
	factorial[0] = 1;
	rep(i, 1, (LL)MAXN)	factorial[i] = (factorial[i-1] * i) % MOD;
}

LL nCr(LL n, LL r) {
	LL num = factorial[n];
	LL den = (factorial[r] * factorial[n-r]) % MOD;
	return (num * modinv(den, MOD)) % MOD;
}

LL arrange(LL n) {
	return modpow(2ll, (n-1), MOD);
}

int main() {
	init();
	sll(n); sll(m);
	VLL pos;
	rep(i, 0, m)	pos.push_back(scanLong());
	sort(pos.begin(), pos.end());
	LL ans = factorial[n - m];
	rep(i, 0, m+1) {
		if(i == 0)	ans *= modinv(factorial[pos[i]-1], MOD);
		else if(i == m)	ans *= modinv(factorial[n - pos[i-1]], MOD);
		else if(pos[i] - pos[i-1] - 1 > 0)	
			ans *= (modinv(factorial[pos[i] - pos[i-1] - 1], MOD) * modpow(2ll, pos[i] - pos[i-1] - 2, MOD)) % MOD;
		ans %= MOD;
	}
	pll(ans); nl;
}
