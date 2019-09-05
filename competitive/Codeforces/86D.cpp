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

const int MAXN = 2e5+10;
const int MAXQ = 2e5+10;
const int MAX_VAL = 1e6+10;
int arr[MAXN], cnt[MAX_VAL];
LL answers[MAXQ];
LL current_answer = 0;
const int BLOCK_SIZE = 447;

struct Query {
	int left, right, idx;
	Query() {};
	Query(int l, int r, int i) {
		left = l, right = r, idx = i;
	}
} qs[MAXQ];

bool compare(Query &a, Query &b) {
	int block_a = a.left / BLOCK_SIZE;
	int block_b = b.left / BLOCK_SIZE;
	if(block_a != block_b)	return block_a < block_b;
	return a.right < b.right;
}

void add(int val) {
	LL tmp = cnt[val]++;
	current_answer -= tmp * tmp * val;
	current_answer += (tmp+1) * (tmp+1) * val;
}

void remove(int val) {
	LL tmp = cnt[val]--;
	current_answer -= tmp * tmp * val;
	current_answer += (tmp-1) * (tmp-1) * val;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
#endif
	si(n); si(q);
	// BLOCK_SIZE = (LL)(ceil(sqrt(n)));
	rep(i, 0, n)	arr[i] = scanLong();	
	rep(i, 0, q) {
		si(l); si(r); l--; r--;
		qs[i] = Query(l, r, i);
	}
	sort(qs, qs+q, compare);
	int mo_left = 0, mo_right = -1;

	rep(i, 0, q) {
		int left = qs[i].left;
		int right = qs[i].right;

		while(mo_right < right)	add(arr[++mo_right]);
		while(mo_right > right)	remove(arr[mo_right--]);

		while(mo_left < left)	remove(arr[mo_left++]);
		while(mo_left > left)	add(arr[--mo_left]);

		answers[qs[i].idx] = current_answer;
	}

	rep(i, 0, q) {
		cout << answers[i] << endl;
	}
}