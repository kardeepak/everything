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

int solve() {
	map<pair<char,int>, int> requests;
	sll(n);
	rep(i, 0, n) {
		char movie; int time;
		cin >> movie >> time;
		if(time == 12)	requests[make_pair(movie, 0)]++;
		else	requests[make_pair(movie, (time / 3))]++;
	}
	string movies = "ABCD";
	LL answer = LONG_MIN;
	do {
		vector<int> people;
		rep(i, 0, movies.length()) {
			people.push_back(requests[make_pair(movies[i], i)]);
		}
		sort(people.begin(), people.end());
		LL revenue = 0;
		rep(i, 0, people.size()) {
			revenue += 25 * (i + 1) * people[i];
			if(people[i] == 0)	revenue -= 100;
		}
		answer = max(answer, revenue);
	} while(next_permutation(movies.begin(), movies.end()));
	return answer;
}

int main() {
	sll(t);
	LL total = 0;
	rep(_, 0, t) {
		LL profit = solve();
		cout << profit << endl;
		total += profit;
	}
	pll(total); nl;
}
