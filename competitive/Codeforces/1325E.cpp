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

const LL MAXP = 1e6+10;
LL lpd[MAXP];
VLL primes;

void sieve() {
	rep(i, 0, (LL)MAXP)	lpd[i] = i;
	rep(p, 2, (LL)MAXP) {
		if(lpd[p] == p) {
			primes.push_back(p);
			for(LL j = p*p; j < MAXP; j += p) {
 				lpd[j] = p;
			}
		}
	}
}

LL normalize(LL n) {
	if(n == 1)	return n;
	LL p = lpd[n];
	if(n % (p * p) == 0)	return normalize(n / (p * p));
	else	return p * normalize(n / p);
}

PLL factorize(LL n) {
	if(n == 1)	return make_pair(1ll, 1ll);
	if(lpd[n] == n)	return make_pair(1ll, n);
	return make_pair(lpd[n], n/lpd[n]);
}

const LL MAXN = 1e6+10;
LL ans = LONG_MAX;
VLL adj[MAXN];

void shortest_cycle(LL maxAi) {
	rep(node, 2, (LL)1010) {
		if(adj[node].empty())	continue;
		if(node * node > maxAi)	break;
		VLL dist(MAXN, LONG_MAX);
		VLL parent(MAXN, -1);
		DLL q;
		q.push_back(node);
		dist[node] = 0;

		while(!q.empty()) {
			LL curr = q.front(); q.pop_back();
			for(LL child : adj[curr]) {
				if(dist[child] == LONG_MAX) {
					dist[child] = dist[curr] + 1;
					parent[child] = curr;
					q.push_back(child);
				}
				else if(parent[child] != curr && parent[curr] != child) {
					ans = min(ans, dist[curr] + dist[child] + 1);
				}
			}
		}
	}
}

int main() {
	primes.push_back(1);
	sieve();
	sll(n);
	PLL arr[n];
	LL maxAi = LONG_MIN;
	rep(i, 0, n) {
		PLL factors = factorize(normalize(scanLong()));
		if(factors.first == factors.second == 1) {
			puts("1");
			return 0;
		}
		if(find(adj[factors.first].begin(), adj[factors.first].end(), factors.second) != adj[factors.first].end()) {
			puts("2");
			return 0;
		}
		adj[factors.first].push_back(factors.second);
		adj[factors.second].push_back(factors.first);
		maxAi = max(maxAi, factors.first * factors.second);

	}

	shortest_cycle(maxAi);
	if(ans == LONG_MAX)	ans = -1;
	pll(ans); nl;
}
