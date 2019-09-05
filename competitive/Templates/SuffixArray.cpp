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

VLL sortCyclicShifts(string str) {
	LL n = str.size();
	LL alphabet = 256;
	VLL p(n), c(n), cnt(max(alphabet,n), 0);
	// Counting Sort by first letter
	rep(i, 0, n)		cnt[str[i]]++;
	rep(i, 1, alphabet)	cnt[i] += cnt[i-1];
	rep(i, 0, n)		p[--cnt[str[i]]] = i;
	c[p[0]] = 0;
	LL classes = 1;
	// Assign classes to different letters
	rep(i, 1, n) {
		if(str[p[i]] != str[p[i-1]])	classes++;
		c[p[i]] = classes - 1;
	}

	VLL pn(n), cn(n);
	for(LL h = 0; (1ll<<h) < n; h++) {
		// Since c[n] is already sorted so we sort by p[n] using counting sort
		rep(i, 0, n) {
			pn[i] = p[i] - (1ll<<h);
			if(pn[i] < 0)	pn[i] += n;
		}
		fill(cnt.begin(), cnt.end(), 0);
		rep(i, 0, n)		cnt[c[pn[i]]]++;
		rep(i, 1, classes)	cnt[i] += cnt[i-1];
		// Sorting from n to 0 for stable sort
		rep(i, n, 0)		p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		rep(i, 1, n) {
			PLL cur = MP(c[p[i]], c[(p[i] + (1ll<<h)) % n]);
			PLL prev = MP(c[p[i-1]], c[(p[i-1] + (1ll<<h)) % n]);
			if(cur != prev)	classes++;
			cn[p[i]] = classes-1;
		}
		rep(i, 0, n)	c[i] = cn[i];
	}
	return p;
}

VLL constructSuffixArray(string str) {
	str += "$";
	VLL suffixArray = sortCyclicShifts(str);
	suffixArray.erase(suffixArray.begin());
	return suffixArray;
}

VLL constructLongestCommonPrefixArray(string str, VLL suffixArray) {
	LL n = str.size();
	VLL rank(n, 0);
	rep(i, 0, n)	rank[suffixArray[i]] = i;

	VLL lcp(n-1, 0);
	LL k = 0;
	rep(i, 0, n) {
		if(rank[i] == n-1) {
			k = 0;
			continue;
		}
		LL j = suffixArray[rank[i]+1];
		while(i + k < n && j + k < n && str[i+k] == str[j+k])
			k++;
		lcp[rank[i]] = k;
		if(k > 0)	k--;
	}
	return lcp;
}


int main() {
}
