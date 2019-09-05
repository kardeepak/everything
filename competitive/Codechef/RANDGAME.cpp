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

bool winnable(LL n) {
	if(n%2 == 1)	return true;
	return ! winnable(n>>1);
}

void solve(LL n) {
	cout << "Win" << endl;
	while(n != 0) {
		if(n%2 == 0) {
			cout << "/2" << endl;
			cout.flush();
			n >>= 1;
		}
		else if(n != 1 && !winnable(n+1)) {
			cout << "+1" << endl;
			cout.flush();
			n++;
		} else {
			cout << "-1" << endl;
			cout.flush();
			n--;
		}

		string move; cin >> move;
		if(move == "+1")	n++;
		else if(move == "-1")	n--;
		else if(move == "/2")	n >>= 1;
		else if(move == "WA")	exit(0);
		else if(move == "GG")	break;
	}
}

int main() {
	LL t; cin >> t;
	rep(_, 0, t) {
		LL n; cin >> n;
		if(winnable(n))	solve(n);
		else {
			cout << "Lose" << endl;
			cout.flush();
			string str; cin >> str;
			if(str == "WA")	exit(0);
		}
	}
}
