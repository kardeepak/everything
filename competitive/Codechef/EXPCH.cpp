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

LL modpow(LL a, LL n, LL m) {
	if(n == 0)	return 1;
	if(n == 1)	return a%m;
	if(n == 2)	return (a*a)%m;
	LL res = 1;
	while(n != 0) {
		if(n%2 == 1)	res = (res*a)%m;
		n >>= 1;
		a = (a*a)%m;
	}
	return res;
}

LL modinv(LL a, LL m) {
	return modpow(a, m-2, m);
}

LL solve() {
	sll(n);
	string s; cin >> s;
	LL dp[n] = { 0 }, open[n] = { 0 }, close[n] = { 0 };
	// dp[i] -- Number of substrings s[j..i] (0 <= j <= i) where we need to change the ith character
	// Let O be number of opening brackets and C be the number of closing brackets in s[j..i] excluding the ith character
	// If (O > C)	No need to change s[i]
	// If (C == O)	Change if s[i] == ')'
	// If (C > 0)	Change if s[i] == ')' and (C-O) is even
	rep(i, 0, n) {
		
		open[i] = (i > 0 ? open[i-1] : 0) + ((s[i] == '(') ? 1 : 0);
		close[i] = (i > 0 ? close[i-1] : 0) + ((s[i] == ')') ? 1 : 0);

		if(s[i] == ')') {
			rep(j, 0, i+1) {
				LL opening = (i > 0 ? open[i-1] : 0) - (j > 0 ? open[j-1] : 0);
				LL closing = (i > 0 ? close[i-1] : 0) - (j > 0 ? close[j-1] : 0);
				if((closing >= opening) && (closing - opening)%2 == 0)	dp[i]++;
			}
		}
	}

	LL possible = 0;
	rep(i, 0, n)	possible += (n-i) * dp[i];

	LL total = n * (n + 1) / 2;
	LL answer = ( possible * modinv(total, MOD) ) % MOD;
	
	return answer;
}

int main() {
	sll(t);
	rep(_, 0, t) {
		pll(solve()); nl;
	}
}
