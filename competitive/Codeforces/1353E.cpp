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
	sll(n); sll(k);
	string s; cin >> s;
	LL ones[k]; clr(ones);
	rep(i, 0, n)	if(s[i] == '1')	ones[i%k]++;
	LL total = accumulate(ones, ones+k, 0ll);
	LL ans = LONG_MAX;
	rep(i, 0, k) {
		VLL arr;
		for(LL j = i; j < n; j += k) {
			arr.push_back((s[j] == '1' ? 1 : -1));
		}

		LL curr_max = 0, maxm = 0;
		LL s = 0, start = 0, end = -1;
		rep(j, 0, (LL)arr.size()) {
			curr_max += arr[j];
			if(maxm < curr_max) {
				maxm = curr_max;
				start = s; end = j;
			}
			if(curr_max < 0) {
				curr_max = 0;
				s = j+1;
			}
		}

		LL changes = total - ones[i];
		rep(j, 0, (LL)arr.size()) {
			if(j >= start && j <= end) {
				if(arr[j] == -1)	changes++;
			}
			else {
				if(arr[j] == 1)	changes++;
			}
		}
		ans = min(ans, changes);
	}
	pll(ans); nl;
}

int main() {
	sll(t);
	rep(_, 0, t)	solve();
}
