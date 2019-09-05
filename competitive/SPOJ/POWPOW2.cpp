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
const LL MODA = 1e9+7;
const LL MODB = 1e9+6;
const LL MODEXP = 5e8+2; // 2 * 41 * 41 * 148721
const LL PHIMODEXP = 41*40*148720;

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

const LL MAXN = 1e6+10;
LL f[MAXN];

LL modpow(LL a, LL n, LL m) {
	LL r = 1;
	while(n != 0) {
		if(n%2 == 1)	r = (r*a)%m;
		a = (a*a)%m;
		n >>= 1;
	}
	return r;
}

LL modinv(LL a, LL p) {
	return modpow(a, p-2, p);
}

void precal() {
	f[0] = 1;
	rep(i, 1, (LL)MAXN) {
		f[i] = ((((4*i-2) * f[i-1])%MODEXP) * modpow(i, PHIMODEXP-1, MODEXP))%MODEXP;
	}
}

int main() {
	precal();
	sll(t);
	rep(_, 0, t) {
		sll(a); sll(b); sll(n);
		LL exp = f[n];
		LL btoexp = modpow(b, exp, MODB);
		LL atobtoexp = modpow(a, btoexp, MODA);
		// pll(exp);
		// pll(btoexp);
		pll(atobtoexp); nl;
	}
}
