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

VLL multiply(VLL a, VLL b) {
	LL n = a.size();
	VLL c(n);
	rep(i, 0, n)	c[i] = b[a[i]];
	return c;
}

bool checkInfinitePath(VLL p, VLL c) {
	LL n = p.size();
	bool visited[n] = { false };
	rep(i, 0, n) {
		if(visited[i])	continue;
		VLL seq;
		LL curr = i;
		do {
			seq.push_back(curr);
			visited[curr] = true;
			curr = p[curr];
		}
		while(curr != i);

		LL clr = c[i];
		bool inf = true;
		rep(it, seq.begin(), seq.end()) {
			if(c[*it] != clr) {
				inf = false;
				break;
			}
		}
		if(inf)	return true;
	}
	return false;
}

void solve() {
	sll(n);
	VLL p(n), c(n);
	rep(i, 0, n)	p[i] = scanLong() - 1;
	rep(i, 0, n)	c[i] = scanLong();

	VLL pn(p.begin(), p.end());
	rep(i, 1, n+1) {
		if(checkInfinitePath(pn, c)) {
			cout << i << endl;
			break;
		} 
		pn = multiply(pn, p);
	}
}

int main() {
	sll(t);
	rep(_, 0, t) {
		solve();
	}
}
