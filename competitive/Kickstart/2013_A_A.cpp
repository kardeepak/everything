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

vector<string> changeFormat(string number, string format) {
	VLL lens;
	LL length = 0;
	format += '-';
	rep(i, 0, format.length()) {
		if('0' <= format[i] && format[i] <= '9')
			length = 10 * length + (format[i] - '0');
		else if(format[i] == '-') {
			lens.push_back(length);
			length = 0;
		}
	}
	vector<string> ret;
	LL start = 0;
	rep(it, lens.begin(), lens.end()) {
		ret.push_back(number.substr(start, *it));
		start += *it;
	}
	return ret;	
}

string multiples[11] = {"", "", "double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple"};
string digits[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

vector<string> printable(string number) {
	vector<PLL> cnts;
	rep(i, 0, number.size()) {
		LL d = number[i] - '0';
		if(cnts.empty() || (d != cnts.back().first))	cnts.push_back(MP(d, 0));
		cnts[cnts.size()-1].second++;
	}
	vector<string> ret;
	rep(it, cnts.begin(), cnts.end()) {
		LL d = it->first, c = it->second;
		if(c == 1)	ret.push_back(digits[d]);
		else if(c <= 10) {
			ret.push_back(multiples[c]);
			ret.push_back(digits[d]);
		}
		else {
			rep(i, 0, c)	ret.push_back(digits[d]);
		}
	}
	return ret;
}

int main() {
	sll(t);
	rep(x, 1, t+1) {
		printf("Case #%lld: ", x);
		string number; cin >> number;
		string format; cin >> format;
		vector<string> formatted = changeFormat(number, format);
		rep(it, formatted.begin(), formatted.end()) {
			vector<string> output = printable(*it);
			rep(jt, output.begin(), output.end())	cout << *jt << " ";
		} nl;
	}
}
