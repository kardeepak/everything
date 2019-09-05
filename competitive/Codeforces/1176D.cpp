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

const LL MAXN = 3e6+10;
LL lpd[MAXN], numCount[MAXN], position[MAXN];
VLL primes;

void sieve() {
	rep(i, 0, (LL)MAXN) {
		lpd[i] = i;
		numCount[i] = position[i] = 0;
	}
	lpd[0] = lpd[1] = -1;
	rep(p, 2, (LL)MAXN) {
		if(lpd[p] == p) {
			primes.push_back(p);
			position[p] = primes.size();
			for(LL j = p*p; j < MAXN; j += p)	lpd[j] = p;
		}
	}
}

int main() {
	sieve();
	sll(n);
	rep(i, 0, 2*n) {
		sll(num);
		numCount[num]++;
	}

	VLL As;
	rep(i, (LL)MAXN, 2ll) {
		while(numCount[i] > 0) {
			if(lpd[i] == i) {
				LL pos = position[i];
				numCount[pos]--;
				numCount[i]--;
				As.push_back(pos);
			} else {
				LL oth = i / lpd[i];
				numCount[oth]--;
				numCount[i]--;
				As.push_back(i);
			}
		}
	}
	rep(it, As.begin(), As.end())	pll(*it); nl;
}
