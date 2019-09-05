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

string vals[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

LL getMask(LL n) {
	LL mask = 0;
	rep(i, 0, 7) {
		if(vals[n][i]=='1')	mask |= (1ll<<i);
	}
	return mask;
}

int main() {
	sll(t);
	rep(_, 0, t) {
		sll(n);
		LL X[n], Y[n];
		rep(i, 0, n) {
			X[i] = scanLong(); Y[i] = scanLong();
		}
		LL lo = LONG_MAX, hi = -1;
		rep(m, 0, 128) {
			bool possible = true;
			rep(i, 0, n) {
				LL alive = getMask(X[i]) & m;
				LL bitcnt = 0;
				rep(i, 0, 7)	if(alive&(1ll<<i))	bitcnt++;
				if(bitcnt != Y[i]) {
					possible = false;
					break;
				}
			}
			if(possible) {
				LL cnt = 0;
				rep(i, 0, 7)	if(m&(1ll<<i))	cnt++;
				cnt = 7-cnt;
				lo = min(cnt, lo);
				hi = max(cnt, hi);
			}
		}
		if(hi == -1)	puts("invalid");
		else	pll(lo), pll(hi), nl;
	}
}
