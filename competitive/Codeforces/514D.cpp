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

int main() {
	sll(n); sll(m); sll(k);
	LL count[n][m];
	rep(i, 0, n) {
		rep(j, 0, m)	count[i][j] = scanLong();
	}
	deque<LL> maxQueue[m];
	LL l = 0, r = 0, ans = 0;
	VLL shots;
	rep(i, 0, m) {
		maxQueue[i].push_back(0);
		shots.push_back(0);
	}

	while(true) {
		LL req = 0;
		VLL tmp;
		rep(i, 0, m) {
			req += count[maxQueue[i].front()][i];
			tmp.push_back(count[maxQueue[i].front()][i]);
		}
		if(req <= k && r-l+1 >= ans) {
			ans = r-l+1;
			shots = tmp;
		}
		if(req <= k) {
			r++;
			if(r == n)	break;
			rep(i, 0, m) {
				while(!maxQueue[i].empty() && count[r][i] >= count[maxQueue[i].back()][i])
					maxQueue[i].pop_back();
				maxQueue[i].push_back(r);
			}
		}
		else {
			l++;
			rep(i, 0, m) {
				while(!maxQueue[i].empty() && maxQueue[i].front() < l)	maxQueue[i].pop_front();
			}
			if(l == n)	break;
			if(l > r) {
				r = l;
				rep(i, 0, m) {
					maxQueue[i].clear();
					maxQueue[i].push_back(l);
				}
			}
		}
	}
	rep(it, shots.begin(), shots.end())	pll(*it); nl;
}
