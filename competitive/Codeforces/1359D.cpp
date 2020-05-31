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

int main() {

	sll(n);
	LL arr[n], ls[n], rs[n], prefix[n+1]; clr(prefix);
	LL lgn = ceil(log2(n+1));
	LL maxarr[n+1][lgn], minarr[n+1][lgn];

	rep(i, 0, n) {
		arr[i] = scanLong();
		prefix[i+1] = arr[i] + prefix[i];
	}

	rep(p, 0, lgn) {
		rep(i, 0, n+1) {
			if(p == 0)	maxarr[i][p] = minarr[i][p] = prefix[i];
			else {
				LL j = (i+(1ll<<(p-1)));
				maxarr[i][p] = max(maxarr[i][p-1], maxarr[j][p-1]);
				minarr[i][p] = min(minarr[i][p-1], minarr[j][p-1]);
			}
		}
	}
	rep(i, 0, n) {
		LL j = i-1;
		while(j >= 0 && arr[j] <= arr[i])	j -= ls[j];
		ls[i] = i-j;
	}
	rep(i, n, 0) {
		LL j = i+1;
		while(j < n && arr[j] <= arr[i])	j += rs[j];
		rs[i] = j-i;
	}
	
	LL ans = 0;
	rep(i, 0, n) {
		LL l = i - ls[i] + 1;
		LL r = i + rs[i] - 1;
		// range : max(l-1,0) to max(i-2, 0)
		LL lsum = 0;
		if(l == i)	lsum = 0;
		else {
			LL rl = l, rr = i-2;
			LL p = 0;
			while((1ll<<p) < (rr-rl+1))	p++; p--;
			LL minval = min(minarr[rl][p], minarr[rr - (1ll<<p)][p]);
			if(rl == rr)	minval = prefix[rl];
			lsum = prefix[i] - minval;
		}

		LL rsum = 0;
		if(r == i)	rsum = 0;
		else {
			LL rl = i+1, rr = r+1;
			LL p = 0;
			while((1ll<<p) < (rr-rl+1))	p++; p--;
			LL maxval = max(maxarr[rl][p], maxarr[rr-(1ll<<p)][p]);
			if(rr == rl)	maxval = prefix[rl];
			rsum = maxval - prefix[i+1];
		}
		ans = max(ans, lsum + rsum);
	}
	pll(ans); nl;
}
