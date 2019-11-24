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

map<LL, LL> memory;

LL getPossibilites(LL n) {
	if(n < 2)	return 1;
	if(n == 2)	return 2;
	if(memory.find(n) == memory.end()) {
		LL ans = getPossibilites(n-2) + getPossibilites(n-1);
		memory[n] = ans % MOD;
	}
	return memory[n];
}

int main() {
	string s; cin >> s;
	if(find(s.begin(), s.end(), 'm') != s.end() || find(s.begin(), s.end(), 'w') != s.end()) {
		puts("0");
		return 0;
	}
	VLL uns;
	rep(i, 0, s.length()) {
		if(s[i] == 'n' && (i > 0 && s[i-1] == 'n')) {
			uns[uns.size() - 1]++;
		} else if(s[i] == 'n')	uns.push_back(1);

		if(s[i] == 'u' && (i > 0 && s[i-1] == 'u')) {
			uns[uns.size() - 1]++;
		} else if(s[i] == 'u')	uns.push_back(1);
	}
	LL ans = 1;
	rep(it, uns.begin(), uns.end()) {
		ans *= getPossibilites(*it);
		ans %= MOD;
	}
	pll(ans); nl;
}
