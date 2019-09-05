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
		sll(n); sll(d);
		PLL temps[n];
		LL degrees[n];
		rep(i, 0, n) {
			temps[i].first = scanLong();
			temps[i].second = i;
		}
		sort(temps, temps+n);
		LL temperatures[n], indexes[n], lpos[n], rpos[n], first, maxD = 0;
		rep(i, 0, n) {
			temperatures[i] = temps[i].first;
			indexes[i] = temps[i].second;
			if(indexes[i] == 0)	first = i;
			if(i > 0)	maxD = max(maxD, temperatures[i]-temperatures[i-1]);
		} 
		rep(i, 0, n) {
			LL lo = temperatures[i] - d;
			LL hi = temperatures[i] + d;
			lpos[i] = lower_bound(temperatures, temperatures+n, lo) - temperatures;
			rpos[i] = upper_bound(temperatures, temperatures+n, hi) - temperatures - 1;
			pll(lpos[i]); pll(rpos[i]); nl;
		}
		if(maxD > d) {
			puts("NO");
			continue;
		}
		if(first == 0 || first == n-1) {
			puts("YES");
			continue;
		}
		if(n == 3) {
			if(temperatures[2]-temperatures[0] < d)	puts("YES");
			else	puts("NO");
			continue;
		}
		LL curr = first;
		while(curr != 0) {
			LL next = max(curr-2, 0ll);
			if(temperatures[curr] - temperatures[next] > d)	break;
			curr = next;
		}
		if(curr == 0) {
			if(first%2 == 0)	curr++;
			while(curr != first+1) {
				LL next = curr+2;
				if(temperatures[next] - temperatures[curr] > d)	break;
				curr = next;
			}
			if(curr == first + 1) {
				puts("YES");
				continue;
			}
		}
		curr = first;
		while(curr != n-1) {
			LL next = min(curr+2, n-1);
			if(temperatures[next] - temperatures[curr] > d)	break;
			curr = next;
		}
		if(curr == n-1) {
			if((n-first)%2 == 1)	curr--;
			while(curr != first-1) {
				LL next = curr-2;
				if(temperatures[curr] - temperatures[next] > d)	break;
				curr = next;
			}
			if(curr == first-1) {
				puts("YES");
				continue;
			}
		}
		puts("NO");
	}
}
