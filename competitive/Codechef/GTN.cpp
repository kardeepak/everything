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

const LL MAXN = 1e6+10;
LL arr[MAXN], tmp, queryCnt = 0;

void reset() {
	clr(arr);
	queryCnt = 0;
}

LL query(LL index) {
	if(arr[index] != 0)	return arr[index];
	if(queryCnt == 44)	exit(1);
 	cout << "1 " << index << endl; cout.flush();
	cin >> tmp;
	arr[index] = tmp;
	queryCnt++;
	return tmp;
}

int main() {
	LL t; cin >> t;
	rep(_, 0, t) {
		reset();
		LL n, x; cin >> n >> x;
		LL lo = 1, hi = (n%2 == 0 ? n-1 : n);
		if(n == -1) {
			hi = MAXN-1;
		}
		while(lo < hi) {
 	 		LL mid = (lo+hi)>>1;

 	 		if(mid%2 == 0) {
 	 			if(mid+1 < hi)	mid++;
 	 			else	mid--;
 	 		}
			
			if(arr[mid] == 0)	arr[mid] = query(mid);
			if(arr[mid] == 0) {
				hi = mid-1;
			}
			else {
				if(arr[mid] < x)	lo = mid+2;
				else if(arr[mid] >= x)	hi = mid;	
			}
		}

		arr[lo] = query(lo);
		if(arr[lo] < x) {
			cout << "2 -1" << endl;
			cout.flush();
		}
		else if(arr[lo] == x) {
			cout << "2 " << lo << endl; 
			cout.flush();
		}
		else {
			LL pow2 = 0;
			tmp = lo-1;
			while(tmp%2 == 0) {
				pow2++;
				tmp /= 2;
			}
			LL sum = query(lo-1);
			rep(i, pow2, 0) {
				sum -= query(lo-1 + (1ll<<i));
			}
			if(sum == x) {
				cout << "2 " << (lo-1) << endl; cout.flush(); 
			}
			else {
				cout << "2 -1" << endl;
			}
		}
		string str; cin >> str;
		if(str == "No")	exit(1);
	}
}
