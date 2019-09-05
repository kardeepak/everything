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

int main() {
	sll(n); sll(m); sll(q);
	string grid[n];
	rep(i, 0, n)	cin >> grid[i];
	LL sum[n+1][m+1], dp[n][m][n][m], ans[n+1][m+1][n+1][m+1]; clr(sum); clr(dp); clr(ans);
	rep(i, 0, n) {
		rep(j, 0, m) {
			sum[i+1][j+1] = (grid[i][j]-'0') + sum[i][j+1] + sum[i+1][j] - sum[i][j];
		}
	}
	rep(si, 0, n) {
		rep(sj, 0, m) {
			rep(ei, si, n) {
				rep(ej, sj, m) {
					LL cnt = sum[ei+1][ej+1] - sum[si][ej+1] - sum[ei+1][sj] + sum[si][sj];
					if(cnt == 0)	dp[si][sj][ei][ej] = 1;
					else	dp[si][sj][ei][ej] = 0;
				}
			}
		}
	}
	rep(i, 0, n) {
		rep(j, 0, m) {
			rep(k, 0, n) {
				rep(l, 0, m) {
					ans[i+1][j+1][k+1][l+1] = 
						ans[i][j+1][k+1][l+1]
						+ans[i+1][j][k+1][l+1]
						+ans[i+1][j+1][k][l+1]
						+ans[i+1][j+1][k+1][l]
						-ans[i][j][k+1][l+1]
						-ans[i][j+1][k][l+1]
						-ans[i][j+1][k+1][l]
						-ans[i+1][j][k][l+1]
						-ans[i+1][j][k+1][l]
						-ans[i+1][j+1][k][l]
						+ans[i+1][j][k][l]
						+ans[i][j+1][k][l]
						+ans[i][j][k+1][l]
						+ans[i][j][k][l+1]
						-ans[i][j][k][l]
						+dp[i][j][k][l];
				}
			}
		}
	}

	rep(i, 0, q) {
		sll(a); sll(b); sll(c); sll(d);
		a--; b--; c--; d--;
		LL ret =
			ans[c+1][d+1][c+1][d+1]
			-ans[a][d+1][c+1][d+1]
			-ans[c+1][b][c+1][d+1]
			-ans[c+1][d+1][a][d+1]
			-ans[c+1][d+1][c+1][b]
			+ans[a][b][c+1][d+1]
			+ans[a][d+1][a][d+1]
			+ans[a][d+1][c+1][b]
			+ans[c+1][b][a][d+1]
			+ans[c+1][b][c+1][b]
			+ans[c+1][d+1][a][b]
			-ans[c+1][b][a][b]
			-ans[a][d+1][a][b]
			-ans[a][b][c+1][b]
			-ans[a][b][a][d+1]
			+ans[a][b][a][b];
		pll(ret); nl;
	}
}
