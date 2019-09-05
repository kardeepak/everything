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

const LL MAXN = 1e6+10;
LL N, M;
string grid[MAXN];
LL dist[MAXN];
deque<LL> Q;

LL getIndex(LL i, LL j) { return (i*M + j + 1); }


int main() {
	N = scanLong(); M = scanLong();
	rep(i, 0, N)	cin >> grid[i];
	rep(i, 0, (LL)MAXN)	dist[i] = LONG_MAX;
	rep(i, 0, N) {
		rep(j, 0, M) {
			if(grid[i][j] == '#')	Q.push_back(getIndex(i, j));
		}
	}
	rep(it, Q.begin(), Q.end())	dist[*it] = 0;


	while(!Q.empty()) {
		LL curr = Q.front(); Q.pop_front();
		LL col = (curr - 1) % M;
		LL row = (curr - col - 1) / M;
		if(row > 0 && grid[row-1][col] == '.') {
			grid[row-1][col] = '#';
			Q.push_back(getIndex(row-1, col));
			dist[getIndex(row-1, col)] = dist[curr] + 1;
		}
		if(row+1 < N && grid[row+1][col] == '.') {
			grid[row+1][col] = '#';
			Q.push_back(getIndex(row+1, col));
			dist[getIndex(row+1, col)] = dist[curr] + 1;
		}
		if(col > 0 && grid[row][col-1] == '.') {
			grid[row][col-1] = '#';
			Q.push_back(getIndex(row, col-1));
			dist[getIndex(row, col-1)] = dist[curr] + 1;
		}
		if(col+1 < M && grid[row][col+1] == '.') {
			grid[row][col+1] = '#';
			Q.push_back(getIndex(row, col+1));
			dist[getIndex(row, col+1)] = dist[curr] + 1;
		}
	}
	LL ans = 0;
	rep(i, 0, N) {
		rep(j, 0, M) {
			ans = max(ans, dist[getIndex(i, j)]);
		}
	}
	pll(ans); nl;
}
