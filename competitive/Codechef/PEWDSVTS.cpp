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
	sll(t);
	rep(_, 0, t) {
		sll(n); sll(a); sll(b); sll(x); sll(y); sll(z);
		priority_queue<LL> pq;
		rep(i, 0, n) {
			sll(c);
			if(c != 0)	pq.push(c);
		}
		LL cnt = 0;
		while(!pq.empty()) {
			LL piper = ceil((z - a) / ((LD)x));
			LL hooli = ceil((z - b)/ ((LD)y));
			if(piper >= hooli) {
				LL top = pq.top(); pq.pop();
				a += top; cnt++;
				if((top>>1) > 0)	pq.push(top>>1);
			}
			else	break;
		}
		LL piper = (a < z ? ceil((z - a) / ((LD)x)) : 0);
		LL hooli = ceil((z - b) / ((LD)y));
		if(piper >= hooli)	puts("RIP");
		else	pll(cnt), nl;
	}
}
