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

LL gcd(LL a, LL b) {
	if(a == 0) 	return b;
	return gcd(b%a, a);
}

PLL conjugate(PLL p) {
	PLL res = make_pair(-p.second, p.first);
	if(res.second < 0) {
		res.first = -res.first;
		res.second = -res.second;
	}
	return res;
}

LL modpow(LL a, LL n, LL m) {
	LL res = 1;
	while(n != 0) {
		if(n%2 == 1)	res = (res*a)%m;
		a = (a*a) % m;
		n >>= 1;
	}
	return res;
}

int main() {
	sll(n);
	map<PLL, LL> counts;
	LL total = 0;
	LL azero = 0, bzero = 0, abzero = 0;
	rep(i, 0, n) {
		sll(a); sll(b);
		if(a == 0 && b == 0)	abzero++;
		else if(a == 0)	azero++;
		else if(b == 0)	bzero++;
		else {
			if(b < 0) {
				a = -a;
				b = -b;
			}
			LL g = gcd(abs(a), abs(b));
			PLL p = make_pair(a/g, b/g);
			counts[p]++;
			total++;
		}
	}

	LL ans = 1;
	for(auto it : counts) {
		PLL p = it.first;
		PLL cp = conjugate(p);
		ans *= ((modpow(2ll, counts[p], MOD) + modpow(2ll, counts[cp], MOD) - 1 + MOD)%MOD);
		ans %= MOD;
		counts[p] = counts[cp] = 0;
	}
	ans *= ((modpow(2ll, azero, MOD) + modpow(2ll, bzero, MOD) - 1 + MOD) % MOD);
	ans %= MOD;
	if(abzero > 0 && abzero < n)	ans++;
	ans = (ans - 1 + MOD) % MOD; // remove empty set
	pll((ans % MOD)); nl;
}
