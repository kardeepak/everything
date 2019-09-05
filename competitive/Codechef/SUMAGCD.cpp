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

LL gcd(LL a, LL b) {
	if(b == 0)	return a;
	return gcd(b, a%b);
}

int main() {
	sll(t);
	rep(_, 0, t) {
		sll(n);
		LL nums[n];
		rep(i, 0, n)	nums[i] = scanLong();
		sort(nums, nums+n);
		n = unique(nums, nums+n) - nums;
		LL lgcd[n], rgcd[n];
		rep(i, 0ll, n)	lgcd[i] = gcd(nums[i], (i > 0 ? lgcd[i-1] : 0));
		rep(i, n, 0ll)	rgcd[i] = gcd(nums[i], (i+1 < n ? rgcd[i+1] : 0));
		LL ans = -1;
		rep(i, 0, n) {
			LL g = gcd((i > 0 ? lgcd[i-1] : 0), (i+1 < n ? rgcd[i+1] : 0));
			ans = max(ans, nums[i] + g);
		}
		pll(ans); nl;
	}
}
