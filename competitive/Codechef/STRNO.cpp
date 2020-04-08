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

const LL MAXP = 1e5+10;
LL lpd[MAXP];
map<LL,LL> pfc;
VLL primes;

void sieve() {
	rep(i, 0, (LL)MAXP)	lpd[i] = i;
	lpd[0] = lpd[1] = -1;
	rep(p, 2, (LL)MAXP) {
		if(lpd[p] == p) {
			primes.push_back(p);
			for(LL j = p * p; j < MAXP; j += p)
				lpd[j] = p;
		}
	}
}

LL primeFactorCount(LL n) {
	if(n == 1)	return 0;
	if(pfc[n] != 0)	return pfc[n];

	LL p = -1;
	if(n < MAXP)	p = lpd[n];
	else {
		rep(it, primes.begin(), primes.end()) {
			if(n % (*it) == 0) {
				p = *it;
				break;
			}
		}
		if(p == -1)	p = n;
	}

	LL res = 0;
	while(n % p == 0) {
		n /= p;
		res++;
	}

	res += primeFactorCount(n);

	pfc[n] = res;
	return pfc[n];
}

int main() {
	sieve();
	sll(t);
	rep(_, 0, t) {
		sll(x); sll(k);
		LL pfc = primeFactorCount(x);
		if(pfc >= k)	puts("1");
		else	puts("0");

	}
}
