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

LL solve(DLL A, DLL B) {
	if(A.empty() || B.empty())	return 0;
	LL lsum[A.size()], rsum[B.size()];
	rep(i, 0, A.size())	lsum[i] = A[i] + (i > 0 ? lsum[i-1] : 0);
	rep(i, B.size(), 0)	rsum[i] = B[i] + (i+1 < B.size() ? rsum[i+1] : 0);
	LL minCost = -1;
	rep(ai, 0, A.size()) {
		LL x = A[ai];
		LL cost = (ai+1) * x - lsum[ai];
		LL bi = lower_bound(B.begin(), B.end(), x) - B.begin();
		if(bi < B.size())
			cost += rsum[bi] - (B.size() - bi) * x;
		if(minCost == -1)	minCost = cost;
		minCost = min(cost, minCost);
	}
	rep(bi, 0, B.size()) {
		LL x = B[bi];
		LL cost = rsum[bi] - (B.size() - bi) * x;
		LL ai = lower_bound(A.begin(), A.end(), x) - A.begin() - 1;
		if(ai >= 0)
			cost += (ai+1)* x - lsum[ai];
		if(minCost == -1)	minCost = cost;
		minCost = min(cost, minCost);
	}
	return minCost;
}

int main() {
	sll(n); sll(m);
	DLL A, B;
	rep(i, 0, n)	A.PB(scanLong());
	rep(j, 0, m)	B.PB(scanLong());
	sort(A.begin(), A.end()); sort(B.begin(), B.end());
	LL minA = A.front(), maxB = B.back();
	while(!B.empty() && B.front() <= minA)	B.pop_front();
	while(!A.empty() && A.back() >= maxB)		A.pop_back();
	LL ans = solve(A, B);
	pll(ans); nl;
}
