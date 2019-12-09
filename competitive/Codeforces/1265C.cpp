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
	deque<PLL> scores;
	rep(i, 0, n) {
		sll(score);
		if(scores.empty() || score != scores.back().first)
			scores.push_back(make_pair(score, 0));
		scores[scores.size() - 1].second++;
	}
	LL gold = 0, silver = 0, bronze = 0;
	gold = scores.front().second; // all highests scoring participants
	scores.pop_front();
	while(silver <= gold && !scores.empty()) {
		silver += scores.front().second;
		scores.pop_front();
	}
	while(bronze <= gold && !scores.empty()) {
		bronze += scores.front().second;
		scores.pop_front();
	}
	while(!scores.empty() && 2*(gold + silver + bronze + scores.front().second) <= n) {
		bronze += scores.front().second;
		scores.pop_front();
	}

	if(2*(gold + silver + bronze) > n)	puts("0 0 0");
	else if(gold >= silver || gold >= bronze)	puts("0 0 0");
	else if(gold == 0 || silver == 0 || bronze == 0)	puts("0 0 0");
	else	pll(gold), pll(silver), pll(bronze), nl;
}

int main() {
	sll(t);
	rep(_, 0, t) {
		solve();
	}
}
