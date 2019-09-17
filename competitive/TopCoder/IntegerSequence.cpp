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

// O(n*n)
VLL longestIncreasingSubsequence(VLL array) {
	LL n = array.size();
	// dp[i] is the longest sequence ending at index i
	VLL dp(n, 1);
	rep(i, 0, n) {
		rep(j, 0, i) {
			// if array[i] > array[j] then add array[i] to the subsequence ending at index j
			if(array[i] > array[j])	dp[i] = max(dp[i], dp[j]+1);
		}
	}
	// maximum length of such subsequences
	return dp;
}

// O(n*n)
VLL longestDecreasingSubsequence(VLL array) {
	LL n = array.size();
	// dp[i] is the longest sequence starting at index i
	VLL dp(n, 1);
	rep(i, n, 0) {
		rep(j, i, n) {
			// if array[i] > array[j] then add array[i] to the subsequence starting at index j
			if(array[i] > array[j])	dp[i] = max(dp[i], dp[j]+1);
		}
	}
	// maximum length of such subsequences
	return dp;
}

class IntegerSequence {
public:
	int maxSubsequence(vector<int> numbers) {
		LL n = numbers.size();
		VLL array(numbers.begin(), numbers.end());
		VLL increasing = longestIncreasingSubsequence(array);
		VLL decreasing = longestDecreasingSubsequence(array);
		LL removal = LONG_MAX;
		rep(i, 0, n) {
			LL sequenceLength = increasing[i] + decreasing[i] - 1;
			removal = min(removal, n - sequenceLength);
		}
		return (int)removal;
	}
};