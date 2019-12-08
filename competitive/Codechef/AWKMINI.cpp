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

LL sumOfSquares(LL n) {
	// 1^2 + 2^2 + ... + k^2 + ... + n^2
	return n * (n + 1) * (2 * n + 1) / 6;
}

LL calcAwk(string s) {
	LL ans = 0;
	rep(i, 0, s.length()) {
		rep(j, i+1, s.length()) {
			if(s[i] != s[j])	ans += (j-i);
		}
	}
	return ans;
}

LL solve(LL boys, LL girls) {
	if(boys < girls)	swap(boys, girls);
	if(boys == girls)	return girls * girls + 2 * sumOfSquares(girls - 1);
	else if(boys == girls + 1)	return 2 * sumOfSquares(girls);
	LL ans = 2 * sumOfSquares(girls);
	LL rem = boys - girls - 1;
	rep(pos, 0, (rem/2)) {
		LL start = 2 + pos, end = pos + 2 * girls;
		ans += (start + end) * girls; 
	}
	if(rem%2 == 1) {
		LL pos = (rem - 1) / 2;
		LL start = 2 + pos, end = pos + 2 * girls;
		ans += (start + end) * girls / 2;
	}
	return ans;
}

int main() {
	sll(t);
	rep(_, 0, t) {
		string s; cin >> s;
		LL boys = count(s.begin(), s.end(), 'b');
		LL girls = count(s.begin(), s.end(), 'g');
		pll(solve(boys, girls)); nl;
	}
}
