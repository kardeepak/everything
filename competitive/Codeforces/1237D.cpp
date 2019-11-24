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
	sll(n);
	LL coolness[n], answer[n], cycle[n];
	rep(i, 0, n)	coolness[i] = scanLong(), answer[i] = -2, cycle[i] = 0;
	LL minPos = min_element(coolness,  coolness+n) - coolness;
	LL maxPos = max_element(coolness, coolness+n) - coolness;
	if(2*coolness[minPos] >= coolness[maxPos]) {
		rep(i, 0, n)	pll(-1ll); nl;
		return 0;
	}
	LL currPos = 0, currMaxPos = 0, endPos = -1;
	while(true) {
		if(answer[currPos%n] != -2)	break;
		currMaxPos = currPos;
		LL newPos = currPos;
		bool cycled = false;
		while(true) {
			newPos = (newPos + 1) % n;
			if(coolness[newPos] > coolness[currMaxPos]) {
				currMaxPos = newPos;
			} else if(2 * coolness[newPos] < coolness[currMaxPos]) {
				endPos = newPos;
				break;
			}
			if(newPos == currPos) cycled = true;
		}
		pll(currPos); pll(currMaxPos); pll(endPos); nl;
		cout << (cycled ? "T" : "F") << endl;
		while(currPos != currMaxPos) {
			if(answer[currPos] == -2) {
				answer[currPos] = endPos;
				cycle[currPos] = (cycled ? 1 : 0);
			}
			currPos = (currPos + 1) % n;
		}
		if(answer[currMaxPos] == -2) {
			answer[currMaxPos] = endPos;
			cycle[currMaxPos] = (cycled ? 1 : 0);
			currPos = (currMaxPos + 1) % n;
		}
	}

	rep(i, 0, n) {
		LL end = answer[i];
		if(end == -1) continue;
		if(i < end)	answer[i] = (end-i);
		else	answer[i] = (end + (n - i));
		answer[i] += cycle[i]*n;
	}
	rep(i, 0, n) pll(answer[i]); nl;
}
