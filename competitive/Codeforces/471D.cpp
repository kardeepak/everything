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

const LL MAXN = 2e5+10;
const LL BASE1 = 1e4+7;
const LL BASE2 = 1e6+3;
const LL MOD1 = 1e9+7;
const LL MOD2 = 1e9+9;
LL pow1[MAXN], pow2[MAXN];

void precalc() {
	pow1[0] = pow2[0] = 1;
	rep(i, 1, (LL)MAXN) {
		pow1[i] = (pow1[i-1] * BASE1) % MOD1;
		pow2[i] = (pow2[i-1] * BASE2) % MOD2;
	}
}

bool check(PLL a, PLL b) {
	return (a.first == b.first && a.second == b.second);
}

int main() {
	precalc();
	sll(n); sll(m);
	LL bears[n], elephants[m];
	rep(i, 0, n)	bears[i] = scanLong();
	rep(i, 0, m)	elephants[i] = scanLong();
	rep(i, 0, n)	bears[i] -= (i+1 < n ? bears[i+1] : 0);
	rep(i, 0, m)	elephants[i] -= (i+1 < m ? elephants[i+1] : 0);
	rep(i, 0, n-1)	bears[i] = 2 * abs(bears[i]) - (bears[i] > 0 ? 1 : 0);
	rep(i, 0, m-1)	elephants[i] = 2 * abs(elephants[i]) - (elephants[i] > 0 ? 1 : 0);
	if(m > n) {
		puts("0");
		return 0;
	}
	PLL hash = MP(0, 0);
	PLL subhash = MP(0, 0);
	rep(i, 0, m-1) {
		hash.first = (BASE1 *  hash.first + elephants[i]) % MOD1;
		hash.second = (BASE2 *  hash.second + elephants[i]) % MOD2;
		subhash.first = (BASE1 * subhash.first + bears[i]) % MOD1;
		subhash.second = (BASE2 *  subhash.second + bears[i]) % MOD2;
	}
	LL cnt = 0;
	if(check(hash, subhash))	cnt++;
	rep(i, m-1, n-1) {
		subhash.first = ((subhash.first * BASE1) % MOD1 + bears[i] - (bears[i-m+1] * pow1[m-1]) % MOD1 + MOD1) % MOD1;
		subhash.second = ((subhash.second * BASE2) % MOD2 + bears[i] - (bears[i-m+1] * pow2[m-1]) % MOD2 + MOD2) % MOD2;
		if(check(hash, subhash))	cnt++;
	}
	pll(cnt); nl;
}
