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
#define ps(x) printf("%s", x)
#define nl printf("\n")
#define clr(a) memset(a, 0, sizeof(a))
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
LL mod = 1e9+7;

/* Fast I/O */
inline int scanInt() {
	int n = 0;
	char ch = getchar_unlocked();
	int sign = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-')	sign = -1;
		ch = getchar_unlocked();
	}
	while(ch >= '0' && ch <= '9') {
		n = (n<<1)+(n<<3)+(int)(ch-'0');
		ch = getchar_unlocked();
	}
	return n*sign;
}

inline LL scanLong() {
	LL n = 0;
	char ch = getchar_unlocked();
	LL sign = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-')	sign = -1;
		ch = getchar_unlocked();
	}
	while(ch >= '0' && ch <= '9') {
		n = (n<<1)+(n<<3)+(LL)(ch-'0');
		ch = getchar_unlocked();
	}
	return n*sign;
}

namespace Matrix {

	void printMatrix(LL **mat, LL n, LL m) {
		rep(i, 0, n) {
			rep(j, 0, m)	pll(mat[i][j]); nl;
		}
	}
	
	LL **matrixMul(LL **A, LL n, LL m, LL **B, LL p, LL q, LL mod) {
		assert(m==p);
		LL **C = new LL*[n];
		rep(i, 0, n)	C[i] = new LL[q];

		rep(i, 0, n) {
			rep(j, 0, q) {
				C[i][j] = 0;
				rep(k, 0, m) {
					C[i][j] += A[i][k]*B[k][j];
					C[i][j] %= mod;
				}
			}
		}

		return C;
	}

	LL **matrixPow(LL **mat, LL n, LL pow, LL mod) {
		LL **res = new LL*[n];
		rep(i, 0, n) {
			res[i] = new LL[n];
			rep(j, 0, n) {	res[i][j] = ((i==j)?1:0); }
		}
		while(pow != 0) {
			if(pow%2 == 1)
				res = matrixMul(res, n, n, mat, n, n, mod);
			mat = matrixMul(mat, n, n, mat, n, n, mod);
			pow >>= 1;
		}
		return res;
	}

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
#endif
	sll(t);
	while(t-->0) {
		// write your code here...
	}
}
