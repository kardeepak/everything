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

const LL MAXN = 2e5+10;
LL N, K, A[MAXN];

bool predicate(LL val) {
	LL ans = 0;
	rep(i, 0, N) {
		LL y = A[i];
		if(y < 0) {
			// A[j] is the first element for which A[j] * A[i] <= val and also for all A[j..N-1]
			LL j = (partition_point(A, A+N, [&y, &val](LL x) { return (x * y) > val; }) - A);
			if(j <= i)	ans += N - i - 1; // j <= i then only count elements after i excluding i
			else	ans += N - j; // otherwise count all elements after j including j
		}
		else if(y >= 0) {
			// A[j] is the last element for which A[j] * A[i] <= val so also for all A[0..j]
			LL j = (partition_point(A, A+N, [&y, &val](LL x) { return (x * y) <= val; }) - A) - 1;
			if(j > i)	ans += (j-i); // only count elements which come after A[i] exluding A[i]
		}
	}
	// cout << val << " " << ans << endl;
	return ans >= K;
} 

int main() {
	N = scanLong(); K = scanLong();
	rep(i, 0, N)	A[i] = scanLong();
	sort(A, A+N);

	LL low = -(1e18+10), high = 1e18+10;
	while(low < high) {
		LL mid = (low + high) >> 1;
		// cout << low << " " << mid << " " << high << endl;
		if(predicate(mid))	high = mid;
		else	low = mid+1;
		// cout << "-----" << endl;
	}
	pll(high); nl;
}
