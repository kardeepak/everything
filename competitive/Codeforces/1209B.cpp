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
	if(a == 0 || b == 0)	return a+b;
	return gcd(b, a%b);
}

LL lcm(LL a, LL b) {
	return ((a*b)/gcd(a, b));
}

int main() {
	sll(n);
	string str; cin >> str;
	LL A[n], B[n];
	rep(i, 0, n) {
		A[i] = scanLong();
		B[i] = scanLong();
	}
	LL lastStart = *max_element(B, B+n);
	LL lcmAll = 2*A[0];
	rep(i, 1, n)	lcmAll = lcm(lcmAll, 2*A[i]);

	LL ans = 0;
	rep(t, 0, lastStart+lcmAll+10) {
		LL lightOn = 0;
		rep(i, 0, n) {
			if(str[i] == '1') {
				// ON DURING [ 0, B[i]-1 ] & [ B[i] + (2k-1)*A[i], B[i] + 2k*A[i] - 1 ]
				// ON AT TIME T IF T < B[i] OR (floor((T-B[i])/A[i]))%2 == 1
				if(t < B[i])	lightOn++;
				else if( t >= B[i] && ( ((LL)floor((t - B[i])/((LD)A[i]))) % 2 == 1 ) )
					lightOn++;
			}
			else {
				// ON DURING [ B[i] + 2k*A[i], B[i] + (2k+1)*A[i] ]
				// ON AT TIME T IF (floor((T-B[i])/A[i]))%2 == 0
				if( t >= B[i] && ( ((LL)floor((t-B[i])/((LD)A[i]))) % 2 == 0 ))	lightOn++;
			}
			ans = max(ans, lightOn);
		}
	}
	pll(ans); nl;
}
