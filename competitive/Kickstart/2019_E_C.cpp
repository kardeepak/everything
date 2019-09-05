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
VLL primes;
LL lpd[MAXN];
bool interesting[MAXN];

void sieve() {
	rep(i, 0, (LL)MAXN)	lpd[i] = i;
	primes.push_back(1ll);
	rep(p, 2, (LL)MAXN) {
		if(lpd[p] == p) {
			primes.push_back(p);
			for(LL j = p*p; j < MAXN; j += p)
				lpd[j] = p;
		}
	}
}

LL calcFactorCount() {
	rep(i, 1, (LL)MAXN) {
		if(binary_search(primes.begin(), primes.end(), i))	interesting[i] = true;
		if(i%4 == 0 && binary_search(primes.begin(), primes.end(), i/4))	interesting[i] = true;
		if(i%2 == 0 && (i/2)%2 == 1)	interesting[i] = true;
	}
}

LL solve(LL l, LL r) {
	// count primes p st : l <= p <= r
	// count primes p st : l <= 4*p <= r ---> ceil(l/4.0) <= p <= floor(r/4.0)
	// count odd no k st : l <= 2*o <= r ---> ceil(l/2.0) <= o <= floor(r/2.0)
	// subtract if l <= 2 <= r as 2 is counted as prime and 2 * odd no.
	return 0;	
}

// assume 1 is prime
// it is intersting if
// x is odd prime no.
// x/4 is prime no. 
// x/2 is an odd no.
int main() {
	sieve();
	calcFactorCount();
	rep(i, 1, (LL)MAXN) {
		LL diff = abs(oddFactorCount[i] - evenFactorCount[i]);
		if(diff <= 2)	assert(interesting[i]);
	}
}
