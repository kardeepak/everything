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

LL getRow(LL pos) {
	LL st = 0;
	while(((1ll<<st)) <= pos)	st++; st--;
	return st;
}

LL getEvenSum(LL st, LL en) {
	if(st > en)	return 0;
	return (en * (en + 2) / 4) - (st * (st - 2) / 4);
}

LL getOddSum(LL st, LL en) {
	if(st > en)	return 0;
	return ((en+1)*(en+1)/4) - ((st-1)*(st-1)/4);
}

LL getRowStart(LL row) {
	if(row < 0)	return -1;
	if(row%2 == 0)
		return 2*((((1ll<<row)-1)/3) + 1) - 1;
	else
		return 2*((((1ll<<row)-2)/3) + 1);
}

LL getRowEnd(LL row) {
	if(row < 0)	return -1;
	LL st = getRowStart(row);
	return st + 2*((1ll<<row)-1);
}

LL MODINV4 = 250000002;

int main() {
	sll(left); sll(right);
	LL srow = getRow(left), erow = getRow(right);
	LL st = getRowStart(srow) + 2 * (left - (1ll<<srow));
	LL en = getRowStart(erow) + 2 * (right - (1ll<<erow));
	LL evenst = (st%2 == 0 ? st : getRowStart(srow+1));
	LL evenen = (en%2 == 0 ? en : getRowEnd(erow-1));
	LL oddst = (st%2 == 1 ? st : getRowStart(srow+1));
	LL odden = (en%2 == 1 ? en : getRowEnd(erow-1));
	// pll(evenst); pll(evenen); pll(oddst); pll(odden); nl;
	LL ans = 0;
	if(evenst <= evenen) {
		ans += ((((evenen / 2) % MOD) * (((evenen / 2) + 1) % MOD)) % MOD) - ((((evenst / 2) % MOD) * (((evenst / 2) - 1) % MOD)) % MOD);
		while(ans < 0)	ans += MOD;
		ans %= MOD;
	}
	if(oddst <= odden) {
		ans += ((((odden + 1) / 2) % MOD) * (((odden + 1) / 2) % MOD) % MOD) - (((((oddst - 1) / 2) % MOD) * (((oddst - 1) / 2) % MOD)) % MOD);
		while(ans < 0)	ans += MOD;
		ans %= MOD;
	}
	while(ans < 0)	ans += MOD;
	pll(ans); nl;
}
