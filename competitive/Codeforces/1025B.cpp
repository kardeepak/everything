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

const LL MAXN = 1e6+10;
VLL primes;
LL lpd[MAXN];
set<LL> probablePrimes;

void sieve() {
	rep(i, 0, (LL)MAXN)	lpd[i] = i;
	rep(p, 2, (LL)MAXN) {
		if(lpd[p] == p) {
			primes.push_back(p);
			for(LL j = p*p; j < MAXN; j += p)	lpd[j] = p;
		}
	}
}

LL gcd(LL a, LL b) {
	if(b == 0)	return a;
	return gcd(b, a%b);
}

LL lcm(LL a, LL b) {
	LL g = gcd(a, b);
	return (a * b / g);
}

bool checkPrime(LL n) {
	rep(it, primes.begin(), primes.end()) {
		LL p = *it;
		if(p*p > n)	return true;
		if(n%p == 0)	return false;
	}
	return true;
}

int main() {
	sieve();
	sll(n);
	LL As[n], Bs[n];
	LL g = 0;
	rep(i, 0, n) {
		As[i] = scanLong(); Bs[i] = scanLong();
		g = gcd(g, As[i] * Bs[i]);
		
	}
	if(g == 1) {
		puts("-1");
		return 0;
	}
	rep(i, 0, n) {
		LL cand = gcd(g, As[i]);
		if(cand > 1)	g = cand;
		cand = gcd(g, Bs[i]);
		if(cand > 1)	g = cand;
	}
	cout << g << endl;
}
