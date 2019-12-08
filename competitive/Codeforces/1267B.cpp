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

LL solve(vector< pair<char, LL> > segs) {
	if(segs.size() % 2 == 0)	return 0;
	if(segs.size() == 1) {
		if(segs[0].second + 1 >= 3)	return segs[0].second + 1;
		else	return 0;
	}
	LL mid = (segs.size() - 1) / 2;
	LL left = mid - 1, right = mid + 1;
	if(segs[mid].second + 1 < 3)	return 0;
	while(left >= 0 && right < segs.size()) {
		if(segs[left].first == segs[right].first) {
			if(segs[left].second + segs[right].second >= 3) {
				left--; right++;
			} else return 0;
		} else return 0;
	}
	return segs[mid].second + 1;
}

int main() {
	string s; cin >> s;
	vector< pair<char, LL> > segs;
	pair<char, LL> curr = make_pair(s[0], 0);
	rep(i, 0, s.length()) {
		if(s[i] != curr.first) {
			segs.push_back(curr);
			curr = make_pair(s[i], 0);
		}
		curr.second++;
		if(i == s.length() - 1)	segs.push_back(curr);
	}
	pll(solve(segs)); nl;
}
