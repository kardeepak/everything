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

const LL MAXN = 2e5+10;

int main() {
	sll(n);
	map<LL,LL> cnt;
	rep(i, 0, n)	cnt[scanLong()]++;
	LL length = 0, start = 1;
	PLL range = MP(0, -1);
	while(start <= MAXN) {
		LL end = start, currLen = 0;
		if(cnt[start] == 0) {
			start++;
			continue;
		}
		if(cnt[start] == 1)	end++, currLen++;
		while(cnt[end] >= 2) {
			currLen += cnt[end];
			end++;
		}
		currLen += cnt[end];
		if(currLen > length) {
			range = MP(start, end);
			length = currLen;
		}
		start = end;
	}
	VLL seq[2];
	rep(i, range.first, range.second+1) {
		rep(j, 0, cnt[i]) {
			seq[j%2].push_back(i);
		}
	}
	LL ans = seq[0].size() +  seq[1].size();
	pll(ans); nl;
	rep(it, seq[0].begin(), seq[0].end())	pll(*it);
	rep(it, seq[1].rbegin(), seq[1].rend())	pll(*it);
	nl;
}
