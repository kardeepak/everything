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

const LL MAXN = 1e4+10;
VLL primes;
LL lpd[MAXN];
map<LL,LL> factors[MAXN];

void sieve() {
	rep(i, 0, (LL)MAXN)	lpd[i] = i;
	lpd[0] = lpd[1] = -1;
	rep(p, 2, (LL)MAXN) {
		if(lpd[p] == p) {
			primes.push_back(p);
			for(LL j = p*p; j < MAXN; j += p) {
				lpd[j] = p;
			}
		}
	}
}

map<LL,LL> factorize(LL n) {
	map<LL, LL> res;
	while(n > 1) {
		LL p = lpd[n];
		while( n % p == 0) {
			res[p]++;
			n /= p;
		}
	}
	return res;
}

map<LL,LL> findlcm(map<LL,LL> &a, map<LL,LL> &b) {
	map<LL,LL> res;
	rep(it, primes.begin(), primes.end()) {
		res[*it] = max(a[*it], b[*it]);
	}
	return res;
}

LD divide(map<LL,LL> &a, map<LL, LL> &b) {
	LD ans = 1;
	rep(it, primes.begin(), primes.end()) {
		LL diff = a[*it] - b[*it];
		ans = (ans * pow(*it, diff));
	}
	return ans;
}


int main() {
	sieve();
	rep(i, 2, (LL)MAXN) {
		LL n = i, p = lpd[n];
		factors[n] = factors[n/p];
		factors[n][p]++;
	}
	pll((LL)primes.size()); nl;
	sll(t);
	rep(_, 0, t) {
		sll(n); sll(m);
		vector< map<LL, LL> > seq(n);
		rep(i, 0, n)	seq[i] = factors[scanLong()];

		map<LL,LL> lcm = seq[0];
		rep(i, 1, n)	lcm = findlcm(lcm, seq[i]);

		map<LL,LL> oldlcm = lcm;
		LL ans = 1;
		rep(i, 1, m+1) {
			map<LL,LL> newnum = factors[i];
			map<LL,LL> newlcm = findlcm(newnum, lcm);
			LD division = divide(newlcm, oldlcm);
			if(division > (LD)1) {
				oldlcm = newlcm;
				ans = i;
			}
		}
		pll(ans); nl;
	}
}
