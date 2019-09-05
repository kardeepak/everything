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

const LL MAXN = 2010;
string grid[MAXN];
LL rows[MAXN][MAXN], cols[MAXN][MAXN];

int main() {
	sll(n); sll(m);
	rep(i, 0, n)	cin >> grid[i];
	rep(i, 0, n) {
		rep(j, 0, m) {
			if(grid[i][j] == '.') {
				if(i == 0 || rows[i-1][j] == -1)	rows[i][j] = 1;
				else	rows[i][j] = rows[i-1][j] + 1;

				if(j == 0 || cols[i][j-1] == -1)	cols[i][j] = 1;
				else	cols[i][j] = cols[i][j-1] + 1;
			}
			else	rows[i][j] = cols[i][j] = -1;
		}
	}

	rep(i, n, 0) {
		rep(j, m, 0) {
			if(i+1 < n && rows[i+1][j] != -1 && rows[i][j] != -1)
				rows[i][j] = rows[i+1][j];
			if(j+1 < m && cols[i][j+1] != -1 && cols[i][j] != -1)
				cols[i][j] = cols[i][j+1];
		}
	}

	LL maxCells = 0;
	rep(i, 0, n) {
		rep(j, 0, m) {
			LL cells = rows[i][j] + cols[i][j] - 1;
			maxCells = max(maxCells, cells);
		}
	}
	pll(maxCells); nl;
}
