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
	LL n; cin >> n;
	VLL rows;
	rep(i, 1, n+1) {
		cout << "? " << i << " " << 1 << " " << i << " " << n << endl;
		LL ans;	cin >> ans;
		if(ans%2 == 1)	rows.PB(i);
	}
	if(rows.size() == 2) {
		vector<PLL> points;
		rep(r, 0, 2) {
			LL lo = 1, hi = n;
			while(lo < hi) {
				LL mid = (lo+hi)>>1;
				cout << "? " << rows[r] << " " << lo << " " << rows[r] << " " << mid << endl;
				LL ans; cin >> ans;
				if(ans%2 == 0)	lo = mid+1;
				else	hi = mid;
			}
			points.PB(MP(rows[r], lo));
		}
		cout << "! " << points[0].first << " " << points[0].second << " " << points[1].first << " " << points[1].second << endl;
		return 0;
	}
	VLL cols;
	rep(i, 1, n) {
		cout << "? " << 1 << " " << i << " " << n << " " << i << endl;
		LL ans; cin >> ans;
		if(ans%2 == 1)	cols.PB(i);
	}
	if(cols.size() == 1)	cols.PB(n);
	vector<PLL> points;
	rep(c, 0, 2) {
		LL lo = 1, hi = n;
		while(lo < hi){
			LL mid = (lo+hi)>>1;
			cout << "? " << lo << " " << cols[c] << " " << mid << " " << cols[c] << endl;
			LL ans; cin >> ans;
			if(ans%2 == 0)	lo = mid+1;
			else	hi = mid;
		}
		points.PB(MP(lo, cols[c]));
	}
	cout << "! " << points[0].first << " " << points[0].second << " " << points[1].first << " " << points[1].second << endl;
}
