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

struct Query {
	LL idx, left, right, width, answer;
};

bool cmpWidth(Query a, Query b) {
	return a.width < b.width;
}

bool cmpIndex(Query a, Query b) {
	return a.idx < b.idx;
}

int main() {
	sll(n);
	VLL nums;
	rep(i, 0, n)	nums.push_back(scanLong());
	sort(nums.begin(), nums.end());
	n = unique(nums.begin(), nums.end()) - nums.begin();
	nums.resize(n);
	VLL ds;
	rep(i, 1, n)	ds.push_back(nums[i] - nums[i-1]);
	map<LL,LL> cnt;
	rep(i, 0, ds.size())	cnt[ds[i]]++;
	sort(ds.begin(), ds.end());
	ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
	sll(q);
	vector<Query> queries;
	rep(i, 0, q) {
		Query tmp;
		tmp.left = scanLong();
		tmp.right = scanLong();
		tmp.idx = i;
		tmp.width = tmp.right - tmp.left + 1;
		queries.push_back(tmp);
	}
	sort(queries.begin(), queries.end(), cmpWidth);
	LL currAns = 0, currPtr = 0, currCnt = 0;
	rep(i, 0, queries.size()) {
		while(currPtr < ds.size() && ds[currPtr] < queries[i].width) {
			currAns += ds[currPtr] * cnt[ds[currPtr]];
			currCnt += cnt[ds[currPtr]];
			currPtr++;
		}
		queries[i].answer = currAns + (n - currCnt) * queries[i].width;
	}
	sort(queries.begin(), queries.end(), cmpIndex);
	rep(it, queries.begin(), queries.end())	pll(it->answer); nl;
}
