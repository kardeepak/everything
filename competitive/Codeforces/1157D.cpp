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

int main() {
	sll(n); sll(k);
	LL As[k], sum = k * (k + 1) / 2;
	rep(i, 0, k)	As[i] = i+1;
	if(k <= 3) {
		if(k == 1)	As[0] = n;
		else if(k == 2) {
			if(n >= 3) {
				if(n%2 == 1) {
					As[0] = (n>>1);
					As[1] = (n>>1)+1;
				}
				else if(n%2 == 0 && n >= 6) {
					As[0] = (n>>1)-1;
					As[1] = (n>>1)+1;
				}
			}
		}
		else if(k == 3) {
			if(n >= 6) {
				As[0] = As[1] = As[2] = (n/3);
				As[0]--; As[2]++;
				LL req = n%3;
				if(req == 1)	As[2]++;
				else if(req == 2)	As[2]++, As[1]++;
				if((As[1] > 2*As[0]) || (As[2] > 2*As[1]))	As[0] = As[1] = As[2] = 0;
			}
		}

		sum = accumulate(As, As+k, 0);
		if(sum == n) {
			puts("YES");
			rep(i, 0, k)	pll(As[i]); nl;
		}
		else	puts("NO");
		return 0;
	}

	LL curr = k-1, cnt = 0, cnt2 = 0;
	while(cnt <= k && sum < n) {
		LL req = n - sum;
		if(req%k == 0) {
			rep(i, 0, k)	As[i] += (req/k);
			sum += req;
			break;
		}
		LL upp = min((curr+1 < k ? As[curr+1]-1 : LONG_MAX), (curr > 0 ? 2*As[curr-1] : LONG_MAX));
		if(upp == LONG_MAX) {
			sum += req;
			As[curr] += req;
			break;
		}
		if(As[curr] < upp) {
			As[curr]++;
			sum++;
			cnt++;
		}
		else {
			curr--;
			cnt2++;
			if(cnt2 == k)	break;
			if(curr < 0) {
				curr = k-1;
				cnt2 = 0;
			}
		}
	}
	if(sum == n) {
		puts("YES");
		rep(i, 0, k)	pll(As[i]); nl;
	}
	else	puts("NO");
}