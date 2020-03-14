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
#define ps(x) printf("%s", x)
#define nl printf("\n")
#define clr(a) memset(a, 0, sizeof(a))
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
LL mod = 1e9+7;

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

const LL MAXN = 50000+10;
string s;
LL SA[MAXN];

bool cmp(LL i, LL j) {
	string a = s.substr(i, s.size()-i);
	string b = s.substr(j, s.size()-j);
	return a < b;
}

LL lcp(LL i, LL j) {
	LL len = 0;
	while(s[i] == s[j]) {
		i++;
		j++;
		len++;
		if(i == s.size() || j == s.size())	break;
	}
	return len;
}

void countingSort(LL l, LL r, LL k) {
 	if(l >= r)	return;
	VLL alpha[255];
	LL idx = 0;
	rep(i, l, r+1) {
		idx = (SA[i]+k < s.size()) ? (s[SA[i]+k]) : 0;
		alpha[idx].push_back(SA[i]);
	}
	idx = l;
	rep(i, 0, 255) {
		if(!alpha[i].empty()) {
			rep(it, alpha[i].begin(), alpha[i].end())
				SA[idx++] = *it;
			countingSort(idx - alpha[i].size(), idx-1, k+1);
		}
	}
}

LL solve() {
	clr(SA);
	rep(i, 0, s.size())	SA[i] = i;
	countingSort(0, s.size()-1, 0);
	LL ans = s.size() * (s.size() + 1) / 2;
	rep(i, 1, s.size())
		ans -= lcp(SA[i], SA[i-1]);
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
#endif
	sll(t);
	while(t-->0) {
		// write your code here...
		cin >> s;
		cout << solve() << endl;
	}
}
