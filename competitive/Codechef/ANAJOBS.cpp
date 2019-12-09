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

LL countJobs(map<LL, PLL> tables, LL size, LL k) {
	LL jobs = 0;
	srep(it, tables.begin(), tables.end()) {
		LL ones = it->second.first, twos = it->second.second;
		LL groups = 0;
		if(size%2 == 0) {
			twos += (ones / 2); ones %= 2;
			LL cnt = (size / 2); // number of events of size two that can fit in this size
			groups += (twos / cnt);
			twos %= cnt;
			if(twos > 0 || ones > 0)	groups++;
		} else {
			LL cnt = (size / 2);
			groups += (twos / cnt);
			ones = max(0ll, ones - (twos / cnt));
			twos %= cnt;
			if(twos > 0) {
				groups++;
				ones = max(0ll, ones - (size - 2*twos));
			}
			if(ones > 0) {
				groups += (ones / size);
				ones %= size;
				if(ones > 0)	groups++;
			}
		}
		jobs += (groups / k);
		groups %= k;
		if(groups > 0)	jobs++;
	}
	return jobs;
}

void solve() {
	sll(N); sll(K); sll(J);
	map<LL, PLL> tables;
	LL minSize = 1, maxSize = -1;
	rep(i, 0, N) {
		sll(t); sll(sz);
		// size can only be 1 or 2
		if(tables.find(t) == tables.end())	tables[t] = make_pair(0, 0);
		if(sz == 1)	tables[t].first++;
		else if(sz == 2)	tables[t].second++;
		minSize = max(minSize, sz);
		maxSize = max(maxSize, tables[t].first + 2 * tables[t].second);
	}
	while(minSize < maxSize) {
		LL size = (minSize + maxSize) >> 1;
		LL jobs = countJobs(tables, size, K);
		if(jobs > J)	minSize = size + 1;
		else	maxSize = size;	 
	}
	pll(minSize); nl;
}

int main() {
	sll(t);
	rep(_, 0, t) {
		solve();
	}
}
