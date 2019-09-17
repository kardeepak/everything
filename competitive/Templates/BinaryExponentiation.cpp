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

// O(n*log(n))
// Calculate a^n mod m
LL modPower(LL a, LL n, LL m) {
	LL res = 1;
	while(n != 0) {
		// a^n = ((a^2)^(n>>1)) * (a^(n%2))
		if(n%2 == 1)	res = (res * a) % m;
		a = (a*a)%m;
		n >>= 1;
	}
	return res;
}

LL fibonacci(LL n) {
	LL res[2][2] = {{1, 0}, {0, 1}};
	LL A[2][2] = {{1, 1}, {1, 0}};
	LL tmp[2][2];
	// |F(n+1)| = |1 1| * |F(n)  | = [ |1 1| ^ n ] * |F(1)|
	// |F(n)  |   |1 0|   |F(n-1)|   [ |1 0|     ]   |F(0)|
	while(n != 0) {
		if(n%2 == 1) {
			rep(i, 0, 2) {
				rep(j, 0, 2) {
					tmp[i][j] = 0;
					rep(k, 0, 2)	tmp[i][j] += res[i][k]*A[k][j];
				}
			}
			rep(i, 0, 2) {
				rep(j, 0, 2)	res[i][j] = tmp[i][j];
			}
		}
		rep(i, 0, 2) {
			rep(j, 0, 2) {
				tmp[i][j] = 0;
				rep(k, 0, 2)	tmp[i][j] += A[i][k]*A[k][j];
			}
		}
		rep(i, 0, 2) {
			rep(j, 0, 2)	A[i][j] = tmp[i][j];
		}
		n >>= 1;
	}
	LL F0 = 0, F1 = 1;
	LL Fn = res[1][0] * F1 + res[1][1] * F0;
	return Fn;
}

//Implementation Details : https://cp-algorithms.com/algebra/binary-exp.html#toc-tgt-4

int main() {
	cout << fibonacci(10) << endl;
}
