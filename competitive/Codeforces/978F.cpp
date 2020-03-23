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

const LL MAXN = 2e5 + 10;
VLL quarrel[MAXN];

int main() {
	sll(n); sll(k);
	vector<PLL> programmers;
	map<LL, LL> skills;
	rep(i, 0, n) {
		sll(s);
		programmers.push_back(make_pair(s, i+1));
		skills[i+1] = s;
	}
	rep(i, 0, k) {
		sll(a);  sll(b);
		if(skills[a] > skills[b])
			quarrel[a].push_back(b);
		if(skills[b] > skills[a])
			quarrel[b].push_back(a);
	}
	sort(programmers.begin(), programmers.end());
	LL lt = 0, eq = 0;
	LL answers[n] = { 0 };
	rep(i, 0, n) {
		if(i == 0) {
			eq = 1;
			continue;
		}
		if(programmers[i-1].first == programmers[i].first)	eq++;
		else {
			lt += eq;
			eq = 1;
		}
		LL ans = (lt - quarrel[programmers[i].second].size());
		answers[programmers[i].second-1] = ans;
	} 
	rep(i, 0, n)	pll(answers[i]); nl;
}
