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
	sll(n); sll(l);
	VLL starts;
	map<LL, LL> ladders, revLadders;
	rep(i, 0, l) {
		sll(a); sll(b);
		starts.push_back(a);
		ladders[a] = b;
		revLadders[b] = a;
	}
	LL from0[n+1], toN[n+1];
	rep(i, 0, n+1) {
		if(i == 0) {
			from0[i] = 1;
			continue;
		}
		from0[i] = 0;
		rep(x, 1, 7) {
			LL j = i-x;
			if(j >= 0 && ladders.find(j) == ladders.end())
				from0[i] += from0[j];
		}
		if(revLadders.find(i) != revLadders.end()) {
			from0[i] += from0[revLadders[i]];
		}
	}
	rep(i, n+1, 0) {
		if(i == n) {
			toN[i] = 1;
			continue;
		}
		toN[i] = 0;
		if(ladders.find(i) == ladders.end()) {
			rep(x, 1, 7) {
				LL j = i+x;
				if(j <= n)	toN[i] += toN[j];
			}
		} else	toN[i] += toN[ladders[i]];
	}

	rep(it, starts.begin(), starts.end()) {
		pll(from0[*it] * toN[ladders[*it]]); nl;
	}
}
