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
	sll(n);
	LL arr[n];
	map<LL,LL> cnt;
	rep(i, 0, n) {
		arr[i] = scanLong();
		cnt[arr[i]]++;
	}
	LL maxCnt = 0, num = -1;
	srep(it, cnt.begin(), cnt.end()) {
		if(it->second > maxCnt) {
			maxCnt = it->second;
			num = it->first;
		}
	}
	LL pos = -1;
	rep(i, 0, n) {
		if(arr[i] == num) {
			pos = i;
			break;
		}
	}
	vector< pair<LL,PLL> > ops;
	rep(i, pos+1, n) {
		if(arr[i] != num) {
			pair<LL,PLL> op;
			op.first = (arr[i] < num ? 1 : 2);
			op.second = MP(i, i-1);
			ops.push_back(op);
		}
	}

	rep(i, pos, 0) {
		if(arr[i] != num) {
			pair<LL,PLL> op;
			op.first = (arr[i] < num ? 1 : 2);
			op.second = MP(i, i+1);
			ops.push_back(op);
		}
	}

	pll((LL)ops.size()); nl;
	rep(it, ops.begin(), ops.end()) {
		pll(it->first); pll(it->second.first+1); pll(it->second.second+1); nl;
	}
}
