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

LL nums[6] = {4, 8, 15, 16, 23, 42};
map<LL,PLL> revMap;

int main() {
	rep(i, 0, 6) {
		rep(j, i+1, 6) {
			revMap[nums[i]*nums[j]] = MP(nums[i], nums[j]);
		}
	}
	LL arr[7], tmp;
	PLL p12, p13, p45, p46; 
	
	cout << "? 1 2" << endl; cout.flush();
	cin >> tmp;
	p12 = revMap[tmp];

	cout << "? 1 3" << endl; cout.flush();
	cin >> tmp;
	p13 = revMap[tmp];

	cout << "? 4 5" << endl; cout.flush();
	cin >> tmp;
	p45 = revMap[tmp];

	cout << "? 4 6" << endl; cout.flush();
	cin >> tmp;
	p46 = revMap[tmp];

	if(p12.first == p13.first) {
		arr[1] = p12.first;
		arr[2] = p12.second;
		arr[3] = p13.second;
	}
	else if(p12.first == p13.second) {
		arr[1] = p12.first;
		arr[2] = p12.second;
		arr[3] = p13.first;
	}
	else if(p12.second == p13.first) {
		arr[1] = p12.second;
		arr[2] = p12.first;
		arr[3] = p13.second;
	}
	else if(p12.second == p13.second) {
		arr[1] = p12.second;
		arr[2] = p12.first;
		arr[3] = p13.first;
	}


	if(p45.first == p46.first) {
		arr[4] = p45.first;
		arr[5] = p45.second;
		arr[6] = p46.second;
	}
	else if(p45.first == p46.second) {
		arr[4] = p45.first;
		arr[5] = p45.second;
		arr[6] = p46.first;
	}
	else if(p45.second == p46.first) {
		arr[4] = p45.second;
		arr[5] = p45.first;
		arr[6] = p46.second;
	}
	else if(p45.second == p46.second) {
		arr[4] = p45.second;
		arr[5] = p45.first;
		arr[6] = p46.first;
	}

	cout << "! ";
	rep(i, 1, 7)	cout << arr[i] << " ";
	cout << endl;
	cout.flush();
}
