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
const LL MOD = 998244353;

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

LL modpow(LL a, LL n, LL m) {
	if(n == 0)	return 1;
	if(n == 1)	return a%m;
	if(n == 2)	return (a*a)%m;
	LL res = 1;
	while(n != 0) {
		if(n%2 == 1)	res = (res*a)%m;
		n >>= 1;
		a = (a*a)%m;
	}
	return res;
}

LL modinv(LL a, LL m) {
	return modpow(a, m-2, m);
}

PLL operator *(PLL a, PLL b) {
	LL num = a.first * b.first;
	LL den = a.second * b.second;
	LL gcd = __gcd(num, den);
	return make_pair(num/gcd, den/gcd);
}

PLL operator +(PLL a, PLL b) {
	LL lcm = a.second * (b.second /__gcd(a.second, b.second));
	LL num = a.first * (lcm / a.second) + b.first * (lcm / b.second);
	LL gcd = __gcd(num, lcm);
	return make_pair(num/gcd, lcm/gcd);
}

struct Probs {
	PLL zero, one, var, notvar;
	Probs() {}
	Probs(LL z, LL o, LL a, LL na, LL den) {
		zero = make_pair(z, den);
		one = make_pair(o, den);
		var = make_pair(a, den);
		notvar = make_pair(na, den);
	}
};


Probs solve(string s, LL start, LL end) {
	if(start == end) {
		return Probs(1, 1, 1, 1, 4);
	}
	LL brackets = 0, position = -1;
	rep(pos, start+1, end) {
		if(s[pos] == '(')	brackets++;
		else if(s[pos] == ')')	brackets--;
		if((s[pos] == '&' || s[pos] == '|' || s[pos] == '^') && brackets == 0) {
			position = pos;
			break;
		}
	}

	Probs first = solve(s, start+1, position-1);
	Probs second = solve(s, position+1, end-1);
	Probs answer = Probs();

	if(s[position] == '&') {
		answer.zero = first.zero * second.zero 
						+ first.zero * (second.one + second.var + second.notvar)
						+ second.zero * (first.one + first.var + first.notvar)
						+ first.var * second.notvar + first.notvar * second.var;
		answer.one = first.one * second.one;
		answer.var = first.one * second.var + first.var * second.one + first.var * second.var;
		answer.notvar = first.one * second.notvar + first.notvar * second.one + first.notvar * second.notvar;
	}
	else if(s[position] == '|') {
		answer.zero = first.zero * second.zero;
		answer.one = first.one * second.one 
					+ first.one * (second.zero + second.var + second.notvar)
					+ second.one * (first.zero + first.var + first.notvar)
					+ first.var * second.notvar + first.notvar * second.var;
		answer.var = first.zero * second.var + first.var * second.zero + first.var * second.var;
		answer.notvar = first.zero * second.notvar + first.notvar * second.zero + first.notvar * second.notvar;
	}
	else if(s[position] == '^') {
		answer.zero = first.zero * second.zero + first.one * second.one + first.var * second.var + first.notvar * second.notvar;
		answer.one = first.zero * second.one + first.one * second.zero + first.var * second.notvar + first.notvar * second.var;
		answer.var = first.zero * second.var + first.var * second.zero + first.one * second.notvar + first.notvar * second.one;
		answer.notvar = first.zero * second.notvar + first.notvar * second.zero + first.one * second.var + first.notvar * second.var;
	}

	return answer;
}

LL convert(PLL a) {
	LL num = a.first % MOD;
	LL den = a.second % MOD;
	return (num * modinv(den, MOD)) % MOD;
}

void solve() {
	string s; cin >> s;
	Probs ans = solve(s, 0, s.length()-1);
	cout << convert(ans.zero) << " " << convert(ans.one) << " " << convert(ans.var) << " " << convert(ans.notvar) << endl;
}

int main() {
	sll(t);
	rep(_, 0, t) {
		solve();
	}
}
