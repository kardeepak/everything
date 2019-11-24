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

map<PLL, deque<PLL> > xy_zi; // (x, y) -> (z, index)
map<LL, deque<PLL> > x_yi; // x -> (y, index)
deque<PLL> xi;

int main() {
	sll(n);
	rep(i, 1, n+1) {
		sll(x); sll(y); sll(z);
		xy_zi[MP(x, y)].push_back(MP(z, i));
	}
	deque<PLL> snaps;

	srep(it, xy_zi.begin(), xy_zi.end()) {
		PLL xy =  it->first;
		deque<PLL> points = it->second;
		sort(points.begin(), points.end());
		if(points.size()%2 == 1) {
			x_yi[xy.first].push_back(MP(xy.second, points.back().second));
			points.pop_back();
		}
		while(!points.empty()) {
			PLL snap;
			snap.first = points.back().second; points.pop_back();
			snap.second = points.back().second; points.pop_back();
			snaps.push_back(snap);
		}
	}

	srep(it, x_yi.begin(), x_yi.end()) {
		LL x = it->first;
		deque<PLL> points = it->second;
		sort(points.begin(), points.end());
		if(points.size()%2 == 1) {
			xi.push_back(MP(x, points.back().second));
			points.pop_back();
		}
		while(!points.empty()) {
			PLL snap;
			snap.first = points.back().second; points.pop_back();
			snap.second = points.back().second; points.pop_back();
			snaps.push_back(snap);
		}
	}

	sort(xi.begin(), xi.end());
	while(!xi.empty()) {
		PLL snap;
		snap.first = xi.back().second; xi.pop_back();
		snap.second = xi.back().second; xi.pop_back();
		snaps.push_back(snap);
	}

	rep(it, snaps.begin(), snaps.end()) {
		pll(it->first); pll(it->second); nl;
	}
}
