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
	sll(n); sll(m);
	
	LL arr[n];
	rep(i, 0, n)	arr[i] = scanLong();
	sort(arr, arr+n);
	
	map<LL,LL> cnt;
	rep(i, 0, m) {
		sll(b); sll(c);
		cnt[c] += b;
	}

	vector<PLL> queries;
	srep(it, cnt.begin(), cnt.end())	queries.push_back(make_pair(it->first, it->second));
	sort(queries.begin(), queries.end());


	m = queries.size();
	LL ltn[m]; // the number of Ax's such that Ax < Q[i].first;
	rep(i, 0, m)	ltn[i] = upper_bound(arr, arr+n, queries[i].first) - arr;

	LL gtm[m];
	rep(i, m, 0)	gtm[i] = (i+1 < m ? gtm[i+1] : 0) + queries[i].second;

	rep(i, 0, n)	pll(arr[i]); nl; nl;
	rep(i, 0, m) {
		pll(queries[i].first);
		pll(gtm[i]); pll(ltn[i]); nl;
	} nl;

	LL pos = -1;
	rep(i, m, 0) {
		if(gtm[i] >= ltn[i]) {
			pos = ltn[i] - 1;
			break;
		}
	}
	LL qpos = m-1;
	while(pos >= 0 && qpos >= 0) {
		while(pos >= 0 && queries[qpos].second > 0) {
			arr[pos] = max(arr[pos], queries[qpos].first);
			queries[qpos].second--;
			pos--;
		}
		qpos--;
	}
	// rep(i, 0, n)	pll(arr[i]); nl; nl;
	LL sum = accumulate(arr, arr+n, 0);
	pll(sum); nl;
}