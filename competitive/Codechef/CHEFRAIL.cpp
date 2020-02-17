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

bool isPerfectSquare(LL tmp) {
	LL ans = sqrt(tmp);
	return (ans * ans == tmp);
}

LL solve() {
	sll(n); sll(m);
	VLL Xs, Ys;
	bool origin = false;

	rep(i, 0, n) {
		sll(x);
		if(x == 0)	origin = true;
		else	Xs.push_back(x);
	}
	
	rep(i, 0, m) {
		sll(y);
		if(y == 0)	origin = true;
		else	Ys.push_back(y);
	}
	sort(Xs.begin(), Xs.end());
	sort(Ys.begin(), Ys.end());
	n = Xs.size(); m = Ys.size();

	LL count = 0;

	rep(i, 0, n) {
		rep(j, i+1, n) {
			LL p = - Xs[i] * Xs[j];
			if(p <= 0 || !isPerfectSquare(p)) continue;
			p = (LL)floor(sqrt(p));
			if(binary_search(Ys.begin(), Ys.end(), p))	count++;
			if(binary_search(Ys.begin(), Ys.end(), -p))	count++;
		}
	}

	rep(i, 0, m) {
		rep(j, i+1, m) {
			LL p = - Ys[i] * Ys[j];
			if(p <= 0 || !isPerfectSquare(p)) continue;
			p = (LL)floor(sqrt(p));
			if(binary_search(Xs.begin(), Xs.end(), p))	count++;
			if(binary_search(Xs.begin(), Xs.end(), -p))	count++;
		}
	}

	if(origin)	count += (n*m);

	return count;
}

int main() {
	sll(t);
	rep(_, 0, t) {
		pll(solve()); nl;
	}
}
