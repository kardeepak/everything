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

struct CustomCompare
{
    bool operator()(const PLL& a, const PLL& b)
    {
        LL la = a.second - a.first + 1;
		LL lb = b.second - b.first + 1;
		if(la == lb)	return a.first > b.first;
		return la < lb;
    }
};

VLL solve(LL n) {
	VLL arr(n, 0);
	priority_queue<PLL, vector<PLL>, CustomCompare> q;
	q.push(make_pair(0ll, n-1));
	LL cnt = 1;

	while(!q.empty()) {
		PLL p = q.top(); q.pop();
		LL l = p.first, r = p.second;

		LL m = (l+r)>>1;
		arr[m] = cnt++;
		if(l == r)	continue;

		LL lenL = (m-l);
		LL lenR = (r-m);
		if(lenL == lenR) {
			if(l <= m-1)
				q.push(make_pair(l, m-1));
			if(m+1 <= r)
				q.push(make_pair(m+1, r));
		}
		else {
			if(m+1 <= r)
				q.push(make_pair(m+1, r));
			if(l <= m-1)
				q.push(make_pair(l, m-1));
		}
	}
	return arr;
}

int main() {
	sll(t);
	rep(_, 0, t) {
		sll(n);
		VLL arr = solve(n);
		rep(it, arr.begin(), arr.end())	pll(*it); nl;
	}
}
