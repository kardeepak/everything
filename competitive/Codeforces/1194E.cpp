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

struct Line {
	LL index;
	LL sx, sy, ex, ey;
};

bool intersect(Line hl, Line vl) {
	if((vl.sy <= hl.sy && hl.sy <= vl.ey)
		&& (hl.sx <= vl.sx && vl.sx <= hl.ex))
		return true;
	return false;
}

int main() {
	sll(n);
	vector<Line> hls, vls;
	rep(i, 0, n) {
		Line l;
		l.index = i+1;
		sll(x1); sll(y1); sll(x2); sll(y2);
		l.sx = min(x1, x2);
		l.sy = min(y1, y2);
		l.ex = max(x1, x2);
		l.ey = max(y1, y2);
		if(l.sx == l.ex)	vls.push_back(l);
		else if(l.sy == l.ey)	hls.push_back(l);
	}
	LL ans = 0;
	rep(i1, 0, hls.size()-1) {
		rep(i2, i1+1, hls.size()) {
			rep(j1, 0, vls.size()-1) {
				rep(j2, j1+1, vls.size()) {
					Line h1 = hls[i1], h2 = hls[i2], v1 = vls[j1], v2 = vls[j2];
					if(intersect(h1, v1) && intersect(h1, v2) && intersect(h2, v1) && intersect(h2, v2))
						ans++;
				}
			}
		}
	}
	pll(ans); nl;
}
