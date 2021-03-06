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
LL nextpos[MAXN][2];
LL color[MAXN], classes[MAXN], blacks[MAXN];

void solve() {
	clr(nextpos); clr(color); clr(classes); clr(blacks);

	LL n, m; cin >> n >> m;
	LL nm = n * m;

	rep(i, 0, n) {
		string clr; cin >> clr;
		rep(j, 0, m) {
			LL index = i * m + j;
			color[index] = (clr[j]-'0');
		}
	}

	rep(i, 0, n) {
		string direction; cin >> direction;
		rep(j, 0, m) {
			LL index = i * m + j;
			if(direction[j] == 'L')			nextpos[index][0] = index-1;
			else if(direction[j] == 'R')	nextpos[index][0] = index+1;
			else if(direction[j] == 'U')	nextpos[index][0] = index-m;
			else if(direction[j] == 'D')	nextpos[index][0] = index+m;
		}
	}

	rep(i, 1, 24) {
		rep(x, 0, nm) {
			nextpos[x][1] = nextpos[nextpos[x][0]][0];
		}
		rep(x, 0, nm) {
			nextpos[x][0] = nextpos[x][1];
		}
	}

	rep(x, 0, nm) {
		LL curr = nextpos[x][0];
		classes[curr] += 1;
		blacks[curr] += (color[x] == 0 ? 1 : 0);
	}

	LL cnt = 0, blk = 0;
	rep(x, 0, nm) {
		if(classes[x] > 0)	cnt++;
		if(blacks[x] > 0)	blk++;
	}
	cout << cnt << ' ' << blk << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL t; cin >> t;
	rep(_, 0, t) {
		solve();
	}
}
