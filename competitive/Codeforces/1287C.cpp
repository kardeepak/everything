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

struct Segment {
	LL length, left, right;
};

bool compare(Segment a, Segment b) {
	// if(a.length == b.length) {
		if(a.left == -1)	return false;
		if(b.left == -1)	return true;
		if(a.right == -1)	return false;
		if(b.right == -1)	return true;
	// }
	return a.length < b.length;
}

bool checkSegmentIsEven(Segment s) {
	if(s.left == -1)
		return (s.right%2 == 0);
	if(s.right == -1)
		return (s.left%2 == 0);
	if((s.left%2) == (s.right%2))
		return (s.left%2 == 0);
	return false;
}

bool checkBothSide(Segment s) {
	return (s.left != -1 && s.right != -1);
}

int main() {
	sll(n);
	LL arr[n], len[n], answer = 0;
	set<LL> miss_evens, miss_odds;
	rep(i, 1, n+1) {
		if(i%2 == 0)	miss_evens.insert(i);
		else			miss_odds.insert(i);
	}
	rep(i, 0, n) {
		arr[i] = scanLong();
		if(i > 0 && arr[i] != 0 && arr[i-1] != 0) {
			if(arr[i]%2 != arr[i-1]%2)	answer++;
		}
		if(arr[i] == 0)			continue;
		else if(arr[i]%2 == 0)	miss_evens.erase(arr[i]);
		else if(arr[i]%2 == 1)	miss_odds.erase(arr[i]);
	}

	rep(i, 0, n) {
		if(arr[i] != 0)	len[i] = 0;
		else	len[i] = (i > 0 ? len[i-1] : 0) + 1;
	}
	vector<Segment> segs_same, segs_diffs;
	rep(i, 0, n) {
		if(len[i] > 0 && (i+1 >= n || len[i+1] == 0)) {
			Segment s; s.length = len[i];
			LL left = i - len[i], right = i+1;
			s.left = (left >= 0 ? arr[left] : -1);
			s.right = (right < n ? arr[right] : -1);
			if(s.left == -1 || s.right == -1 || (s.left%2) == (s.right%2))
				segs_same.push_back(s);
			else
				segs_diffs.push_back(s);
		}
	}
	sort(segs_same.begin(), segs_same.end(), compare);
	sort(segs_diffs.begin(), segs_diffs.end(), compare);

	answer += segs_diffs.size();
	LL miss_evens_cnt = miss_evens.size(), miss_odds_cnt = miss_odds.size();
	rep(it, segs_same.begin(), segs_same.end()) {
		if(checkSegmentIsEven(*it)) {
			LL evens_cnt = min(miss_evens_cnt, it->length);
			LL odds_cnt = it->length - evens_cnt;
			miss_evens_cnt -= evens_cnt;
			miss_odds_cnt -= odds_cnt;
			if(odds_cnt > 0) {
				if(checkBothSide(*it))	answer += 2;
				else	answer++;
			}
		} else {
			LL odds_cnt = min(miss_odds_cnt, it->length);
			LL evens_cnt = it->length - odds_cnt;
			miss_evens_cnt -= evens_cnt;
			miss_odds_cnt -= odds_cnt;
			if(evens_cnt > 0) {
				if(checkBothSide(*it))	answer += 2;
				else	answer++;
			}
		}
	}
	pll(answer); nl;
}
