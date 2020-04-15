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

LL solve(deque<PLL> counts, LL index, LL required) {
	LL req = max(0ll, required - counts[index].second);
	LL moves = 0;
	while(req > 0) {
		LL nearest = ((counts.back().first - counts[index].first) < (counts[index].first - counts.front().first) ? counts.size()-1 : 0);
		if(index == nearest) {
			nearest = (counts.size() - 1 - nearest);
		}
		LL permove = abs(counts[nearest].first - counts[index].first);
		LL move_count = min(req, counts[nearest].second);
		moves += move_count * permove;
		req -= move_count;
		if(nearest == 0) {
			counts.pop_front();
			index--;
		}
	}
	return moves;
}

int main() {
	sll(n); sll(k);
	VLL nums(n);
	rep(i, 0, n)	nums[i] = scanLong();
	sort(nums.begin(), nums.end());

	vector<PLL> cnt;
	rep(i, 0, n) {
		if(cnt.empty() || cnt.back().first != nums[i])
			cnt.push_back(make_pair(nums[i], 1ll));
		else
			cnt.back().second++;
	}

	VLL prefsum, prefcnt;
	VLL sufsum, sufcnt;

	rep(it, cnt.begin(), cnt.end()) {
		if(prefsum.empty() || prefcnt.empty()) {
			prefsum.push_back((it->first) * (it->second));
			prefcnt.push_back(it->second);
		} else {
			prefsum.push_back(prefsum.back() + (it->first) * (it->second));
			prefcnt.push_back(prefcnt.back() + it->second);
		}
	}

	rep(it, cnt.rbegin(), cnt.rend()) {
		if(sufsum.empty() || sufcnt.empty()) {
			sufsum.push_back((it->first) * (it->second));
			sufcnt.push_back(it->second);
		} else {
			sufsum.push_back(sufsum.back() + (it->first) * (it->second));
			sufcnt.push_back(sufcnt.back() + it->second);
		}
	}
	reverse(sufsum.begin(), sufsum.end());
	reverse(sufcnt.begin(), sufcnt.end());

	LL ans = LONG_MAX;
	rep(i, 0, (LL)cnt.size()) {
		LL need = max(0ll, k - cnt[i].second);

		LL needl = 0;
		if(i > 0)	needl = min(need, prefcnt[i-1]);
		LL needr = max(0ll, need - needl);

		LL res = 0;
		if(i > 0 && needl > 0) {
			res += prefcnt[i-1] * (cnt[i].first - 1) - prefsum[i-1];
			res += needl;
		}
		if(i+1 < (LL)cnt.size() && needr > 0) {
			res += sufsum[i+1] - sufcnt[i+1] * (cnt[i].first + 1);
			res += needr;
		}
		ans = min(ans, res);

		needr = 0;
		if(i+1 < (LL)cnt.size())	needr = min(need, sufcnt[i+1]);
		needl = max(0ll, need - needr);

		res = 0;
		if(i > 0 && needl > 0) {
			res += prefcnt[i-1] * (cnt[i].first - 1) - prefsum[i-1];
			res += needl;
		}
		if(i+1 < (LL)cnt.size() && needr > 0) {
			res += sufsum[i+1] - sufcnt[i+1] * (cnt[i].first + 1);
			res += needr;
		}
		
		ans = min(ans, res);
	}

	pll(ans); nl;
}
