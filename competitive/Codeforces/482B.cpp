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

struct Constraint {
	LL left, right, value[30];
};

bool cmp(Constraint a, Constraint b) {
	if(a.left == b.left)	return a.right < b.right;
	return a.left < b.left;
}

bool overlap(Constraint a, Constraint b) {
	return ((a.left <= b.left && b.left <= a.right) || (a.left <= b.right && b.right <= a.right));
}

int main() {
	sll(n); sll(m);
	vector<Constraint> cons;
	rep(i, 0, m) {
		Constraint con;
		con.left = scanLong()-1;
		con.right = scanLong()-1;
		sll(val);
		rep(b, 0, 30)	con.value[b] = ((val&(1ll<<b)) != 0);
		cons.push_back(con);
	}
	sort(cons.begin(), cons.end(), cmp);
	LL array[n][30]; clr(array);
	rep(it, cons.begin(), cons.end()) {
		rep(b, 0, 30) {
			if(it->value[b] == 1) {
				array[it->left][b] += 1;
				if(it->right + 1 < n)	array[it->right + 1][b] -= 1;
			}
		}
	}
	rep(i, 0, n) {
		rep(b, 0, 30) {
			if(i > 0)	array[i][b] += array[i-1][b];
		}
	}

	rep(i, 0, n) {
		rep(b, 0, 30) {
			if(array[i][b] > 0)	array[i][b] = 1;
		}
	}
	VLL zeros[30];
	rep(i, 0, n) {
		rep(b, 0, 30) {
			if(array[i][b] == 0)	zeros[b].push_back(i);
		}
	}

	rep(it, cons.begin(), cons.end()) {
		rep(b, 0, 30) {
			if(it->value[b] == 0) {
				LL pos = lower_bound(zeros[b].begin(), zeros[b].end(), it->left) - zeros[b].begin();
				if(pos < 0 || pos >= zeros[b].size()) {
					puts("NO");
					return 0;
				}
			}
		}
	}
	puts("YES");
	rep(i, 0, n) {
		LL val = 0;
		rep(b, 0, 30) {
			if(array[i][b] != 0)	val += (1ll<<b);
		}
		pll(val);
	} nl;
}
