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

void solve() {
	sll(n);
	VLL array(n);
	rep(i, 0, n)	array[i] = scanLong();
	VLL adjacent; // all numbers adjacent to -1
	rep(i, 0, n) {
		if((i-1 >= 0 && array[i-1] == -1) || (i+1 < n && array[i+1] == -1)) {
			if(array[i] != -1)	adjacent.push_back(array[i]);
		}
	}
	sort(adjacent.begin(), adjacent.end());
	LL k, m;
	if(adjacent.size() == 0)	k = m = 0;
	else if(adjacent.size() == 1) {
		k = adjacent.front();
		rep(i, 1, n) {
			LL curr = (array[i] == -1 ? k : array[i]);
			LL prev = (array[i-1] == -1 ? k : array[i-1]);
			m = max(m, abs(curr - prev));
		}
	}
	else {
		LL m1 = 0, m2 = 0;
		LL k1 = (adjacent.front() + adjacent.back())>>1;
		LL k2 = k1 + 1;
		rep(i, 1, n) {
			LL curr = (array[i] == -1 ? k1 : array[i]);
			LL prev = (array[i-1] == -1 ? k1 : array[i-1]);
			m1 = max(m1, abs(curr - prev));
		}

		rep(i, 1, n) {
			LL curr = (array[i] == -1 ? k2 : array[i]);
			LL prev = (array[i-1] == -1 ? k2 : array[i-1]);
			m2 = max(m2, abs(curr - prev));
		}

		if(m1 <= m2) {
			k = k1; m = m1;
		} else {
			k = k2; m = m2;
		}
	}
	pll(m); pll(k); nl;
}

int main() {
	sll(t);
	rep(_, 0, t) {
		solve();
	}
}
