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

LL matches[10] = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
map<LL,LL> num;

bool cmp(LL a, LL b) {
	return (num[a] > num[b]);
}

int main() {
	sll(n); sll(m);
	VLL digits(m);
	rep(i, 0, m)	digits[i] = scanLong();
	sort(digits.begin(), digits.end());
	rep(i, 0, m)	num[matches[digits[i]]] = digits[i];
	LL dp[n+1]; dp[0] = 0;
	rep(i, 1, n+1) {
		dp[i] = -1;
		srep(it, num.begin(), num.end()) {
			if(it->first <= i)
				dp[i] = max(dp[i], dp[i - it->first] + 1);
		}
	}
	
	VLL ms;
	srep(it, num.begin(), num.end())	ms.push_back(it->first);
	sort(ms.begin(), ms.end(), cmp);

	LL cnt[10]; clr(cnt);
	while(n > 0) {
		rep(it, ms.begin(), ms.end()) {
			if(dp[n-*it] == dp[n]-1) {
				cnt[num[*it]]++;
				n -= *it;
				break;
			}
		}
	}
	rep(i, 10, 0) {
		rep(k, 0, cnt[i])	cout << i;
	} nl;
}
