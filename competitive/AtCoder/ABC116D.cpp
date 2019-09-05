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

int main() {
	sll(n); sll(k);
	vector<PLL> sushis;
	rep(i, 0, n) {
		sll(t); sll(d);
		sushis.PB(MP(t, d));
	}
	sort(sushis.begin(), sushis.end(), [](PLL a, PLL b) { return a.second > b.second; });
	LL pts = 0;
	map<LL,LL> typeCnt;
	rep(i, 0, k) {
		pts += sushis[i].second;
		typeCnt[sushis[i].first]++;
	}
	LL totalPts = pts + typeCnt.size() * typeCnt.size();
	LL prev = totalPts;
	LL types = typeCnt.size();
	LL sml = k-1, big = k;
	rep(i, 1, k - types + 1) {
		while(sml >= 0 && typeCnt[sushis[sml].first] <= 1)	sml--;
		if(sml < 0)		break;
		while(big < n && typeCnt[sushis[big].first] > 0)	big++;
		if(big == n)	break;
		LL tmp = prev - sushis[sml].second + sushis[big].second + 2 * (types + i) - 1;
		typeCnt[sushis[sml--].first]--;
		typeCnt[sushis[big++].first]++;
		if(tmp > totalPts)	totalPts = tmp;
		prev = tmp;
	}
	pll(totalPts); nl;
}
