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

const LL MAXN = 1e5+10;
LL N, heights[MAXN], SA[MAXN];

struct Suffix {
	LL index, rank, nextRank;
};

bool cmp(Suffix a, Suffix b) {
	if(a.rank == b.rank)	return a.nextRank < b.nextRank;
	return a.rank < b.rank;
}

void build() {
	Suffix suffs[N];
	rep(i, 0, N) {
		suffs[i].index = i;
		suffs[i].rank = heights[i];
		suffs[i].nextRank = (i+1 < N ? suffs[i+1].rank : -1);
	}
	sort(suffs, suffs+N, cmp);
	LL index[N];
	for(LL k = 2; k < 2*N; k = 2*k) {
		LL rank = 0;
		LL prevRank = suffs[0].rank;
		index[suffs[0].index] = 0;
		rep(i, 1, N) {
			if(suffs[i].rank == prevRank && suffs[i].nextRank == suffs[i-1].nextRank) {
				prevRank = suffs[i].rank;
				suffs[i].rank = rank;
			}
			else {
				prevRank = suffs[i].rank;
				suffs[i].rank = ++rank;
			}
			index[suffs[i].index] = i;
		}

		rep(i, 0, N) {
			LL nextIndex = suffs[i].index + (k/2);
			suffs[i].nextRank = (nextIndex < N ? suffs[index[nextIndex]].rank : -1);
		}
		sort(suffs, suffs+N, cmp);
	}
	rep(i, 0, N)	SA[i] = suffs[i].index;
}

LL lps(LL i, LL j) {
	LL len = 0;
	while(heights[i] == heights[j]) {
		i++;
		j++;
		len++;
		if(i == N || j == N)	break;
	}
	return len;
}

LL solve() {
	clr(SA);
	rep(i, 0, N)	SA[i] = i;
	build();
	LL ans = N * (N + 1) / 2;
	rep(i, 1, N)	ans -= lps(SA[i-1], SA[i]);
	return ans;
}

int main() {
	sll(t);
	rep(_, 0, t) {
		N = scanLong();
		rep(i, 0, N)	heights[i] = scanLong();
		rep(i, N, 1)	heights[i] -= heights[i-1]; N--;
		rep(i, 0, N)	heights[i] = heights[i+1];
		pll(solve()); nl;
	}
}
