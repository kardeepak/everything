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


bool isLeapYear(LL year) {
	if(year % 400 == 0)	return true;
	if(year % 4 == 0 && year % 100 != 0)	return true;
	return false;
}

LL isOverlap[420];
LL preSum[420], postSum[420];

void init() {
	clr(isOverlap); clr(preSum); clr(postSum);
	LL year = 1, day = 1;
	while(year <= 400) {
		// If year starts on Wednesday then February starts on Saturday
		if(day == 3)	isOverlap[year] = 1;
		// If year starts on Thursday then February starts on Sunday
		// We only count if February has only 28 days
		else if(day == 4 && !isLeapYear(year))	isOverlap[year] = 1;
		
		// Increment 2 if year is a leap year otherwise 1
		day += (isLeapYear(year) ? 2 : 1);
		day %= 7;
		
		year++;
	}

	rep(i, 1, 401) {
		if(i == 1)	preSum[i] = isOverlap[i];
		else	preSum[i] = preSum[i-1] + isOverlap[i];
	}

	rep(i, 401, 1) {
		if(i == 400)	postSum[i] = isOverlap[i];
		else	postSum[i] = postSum[i+1] + isOverlap[i];
	}
}

string weekdays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}; 

LL getStartOfYear(LL year) {
	LL curr = year - (year % 400) + 1;
	LL day = 1;
	while(curr != year) {
		day++;
		if(isLeapYear(curr))	day++;
		curr++;
		day %= 7;
	}
	return day;
}

LL getCount(LL start) {
	
}

LL solve() {
	// Answer will be 101 for year 400k+1 to 400k+400
	
	sll(sm); sll(sy); // start
	sll(em); sll(ey); // end
	
	// We only care about Februarys
	if(sm > 2)	sy++;
	if(em < 2)	ey--;
	if(sy > ey)	return 0;

	LL next = sy +  ( (sy%400 != 0) ? (400 - (sy%400)) : 0 );
	LL prev = ey - (ey % 400);

	LL answer = postSum[(sy%400 == 0 ? 400 : sy%400)] + preSum[ey%400] + 101 * ((prev / 400) - (next / 400));
	return answer;
}

int main() {
	init();
	sll(t);
	rep(i, 0, t) {
		pll(solve()); nl;
	}

}
