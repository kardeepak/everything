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
	LL nums[n+1], left[n+1], right[n+1];
	rep(i, 1, n+1)	nums[i] = scanLong();
	stack<LL> st;
	rep(i, 1, n+1) {
		while(!st.empty() && nums[st.top()] >= nums[i])	st.pop();
		if(st.empty())	left[i] = 0;
		else	left[i] = st.top();
		st.push(i);
	}
	while(!st.empty())	st.pop();
	rep(i, n+1, 1) {
		while(!st.empty() && nums[st.top()] >= nums[i])	st.pop();
		if(st.empty())	right[i] = n+1;
		else	right[i] = st.top();
		st.push(i);
	}
	vector<PLL> indices;
	rep(i, 1, n+1)	indices.PB(MP(nums[i], i));
	sort(indices.begin(), indices.end());
	LL curr = 1;
	rep(it, indices.rbegin(), indices.rend()) {
		LL len = right[it->second] - left[it->second] - 1;
		while(curr <= len) {
			pll(it->first);
			curr++;
		}
	} nl;
}
