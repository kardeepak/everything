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
LL values[MAXN][20];

int main() {
	sll(t);
	rep(_, 0, t) {
		string str; cin >> str;
		LL n = str.length();
		LL preZeros[n];
		rep(i, 0, n) {
			if(i == 0)	preZeros[i] = (str[i] == '0' ? 1 : 0);
			else if(str[i] == '0')	preZeros[i] = preZeros[i-1] + 1;
			else if(str[i] == '1')	preZeros[i] = 0;
			rep(j, 0, 20) {
				if(i+j >= n)	break;
				if(j == 0)	values[i][j] = (str[i] == '1' ? 1 : 0);
				else	values[i][j] = 2 * values[i][j-1] + (str[i+j] == '1' ? 1 : 0);
			}
		}
		
		LL ans = 0;
		rep(i, 0, n) {
			if(str[i] == '1') {
				rep(j, 1, 19) {
					if(i+j-1 >= n)	break;
					LL val = values[i][j-1];
					if(val == j)	ans++;
					else if(i > 0 && val > j && preZeros[i-1] + j >= val)	ans++;
				}
			}
		}
		pll(ans); nl;
	}
}
