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

bool isXbetterThanY(LL x, LL y) {
	LL diff = x^y;
	return ((diff&x) != 0);
}

int main() {
	sll(n);
	LL skills[n], algos[n];
	rep(i, 0, n)	algos[i] = scanLong();
	rep(i, 0, n)	skills[i] = scanLong();
	set<LL> group_indices, group_algos;
	map<LL, VLL> algos_to_indices;
	rep(i, 0, n) {
		algos_to_indices[algos[i]].push_back(i);
	}
	srep(it, algos_to_indices.begin(), algos_to_indices.end()) {
		if((it->second).size() > 1) {
			group_indices.insert((it->second).begin(), (it->second).end());
			group_algos.insert(it->first);
		}
	}
	srep(it, group_indices.begin(), group_indices.end())	pll(*it); nl;
	srep(it, algos_to_indices.begin(), algos_to_indices.end()) {
		if((it->second).size() == 1) {
			bool betterThanAll = true;
			LL elem = (it->first);
			srep(jt, group_algos.begin(), group_algos.end()) {
				if(!isXbetterThanY(elem, *jt)) {
					betterThanAll = false;
					break;
				}
			}
			if(!betterThanAll) {
				group_indices.insert((it->second).back());
				group_algos.insert(it->first);
			}
		}
	}
	LL sum = 0;
	srep(it, group_indices.begin(), group_indices.end())	sum += skills[*it];
	pll(sum); nl;
}
