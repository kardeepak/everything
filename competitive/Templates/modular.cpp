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
LL mod = 1e9+7;

namespace modular {
	/* Fast I/O */
	inline int scanModInt(int m) {
		int n = 0;
		char ch = getchar_unlocked();
		while(ch < '0' || ch > '9')	ch = getchar_unlocked();
		while(ch >= '0' && ch <= '9') {
			n = (n<<1)+(n<<3)+(int)(ch-'0');
			n %= m;
			ch = getchar_unlocked();
		}
		return n;
	}

	inline LL scanModLong(LL m) {
		LL n = 0;
		char ch = getchar_unlocked();
		while(ch < '0' || ch > '9') ch = getchar_unlocked();
		while(ch >= '0' && ch <= '9') {
			n = (n<<1)+(n<<3)+(LL)(ch-'0');
			n %= m;
			ch = getchar_unlocked();
		}
		return n;
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

	bool isPrime(LL n) {
		if(n < 2) return false;
		if(n == 2 || n == 3)	return true;
		rep(i, 0, 64) {
			LL x = rand()%(n-2) + 2;
			if(modpow(x, n-1, n) != 1)
				return false; 
		}
		return true;
	}
}

int main() {
}
