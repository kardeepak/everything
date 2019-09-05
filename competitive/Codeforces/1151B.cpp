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
	sll(n); sll(m);
	LL matrix[n][m], bitcnt[n][10]; clr(bitcnt);
	rep(i, 0, n) {
		rep(j, 0, m) {
			matrix[i][j] = scanLong();
			rep(b, 0, 10) {
				if(matrix[i][j]&(1ll<<b))
					bitcnt[i][b]++;
			}
		}
	}
	LL partial[10], full[10]; clr(partial); clr(full);
	rep(i, 0, n) {
		rep(b, 0, 10) {
			if(bitcnt[i][b] > 0 && bitcnt[i][b] < m)
				partial[b]++;
			if(bitcnt[i][b] == m)	full[b]++;
		}
	}
	LL bit = -1;
	rep(b, 0, 10) {
		if(full[b]%2 == 1 || partial[b] > 0) {
			bit = b;
			break;
		}
	}
	if(bit == -1) {
		puts("NIE");
		return 0;
	}
	VLL pos(n);
	rep(i, 0, n) {
		if(bitcnt[i][bit] == m)	pos[i] = 1;
		else if(bitcnt[i][bit] == 0)	pos[i] = 1;
		else {
			if(full[bit]%2 == 0 && partial[bit] > 0) {
				rep(j, 0, m) {
					if(matrix[i][j]&(1ll<<bit)) {
						pos[i] = j+1;
						break;
					}
				}
				partial[bit] = 0;
			}
			else {
				rep(j, 0, m) {
					if((matrix[i][j]&(1ll<<bit)) == 0) {
						pos[i] = j+1;
						break;
					}
				}
			}
		}
	}
	puts("TAK");
	rep(i, 0, n)	pll(pos[i]); nl;
}
