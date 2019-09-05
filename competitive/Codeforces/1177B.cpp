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

LL numCount[13] = {0, 9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000, 9000000000, 90000000000, 900000000000};

LL stringLength(LL n) {
	LL ans = 0;
	rep(i, 1, n+1)	ans += i * numCount[i];
	return ans;
}

LL strLength[13];

LL numberOfDigits(LL n) {
	if(n <= 0)	return 0;
	LL digits = 0, tmp = n;
	while(tmp != 0) {
		digits++;
		tmp /= 10;
	}
	LL ret = strLength[digits-1];
	LL diff = n - (LL)(pow(10, digits-1	)-1);
	ret += digits * diff;
	return ret;
}

int main() {
	rep(i, 0, 13)	strLength[i] = stringLength(i);
	sll(k);
	LL lo = 1, hi = 1e18;
	while(lo < hi) {
		LL mid = (lo+hi)>>1;
		LL curr = numberOfDigits(mid);
		if(curr < k)	lo = mid+1;
		else	hi = mid;
	}
	stringstream ss; ss << lo;
	string str = ss.str();
	cout << str[k-numberOfDigits(lo-1)-1] << endl;
}
