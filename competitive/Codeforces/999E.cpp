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

const LL MAXN = 5010;
VLL adj[MAXN];
bool visited[MAXN];
bool good[MAXN];

LL dfs(LL src) {
	visited[src] = true;
	LL cnt = 1;
	rep(it, adj[src].begin(), adj[src].end()) {
		if(!visited[*it]) {
			cnt += dfs(*it);
		}
	}
	return cnt;
}

int main() {
	sll(n); sll(m); sll(s);
	rep(i, 0, m) {
		sll(src); sll(dest);
		adj[src].push_back(dest);
	}
	vector<PLL> counts;

	dfs(s);
	rep(i, 1, n+1)	good[i] = visited[i];
	rep(i, 1, n+1) {
		if(!good[i]) {
			clr(visited);
			dfs(i);
			LL cnt = 0;
			rep(j, 1, n+1) {
				if(visited[j] && !good[j])	cnt++;
			}
			counts.push_back(make_pair(cnt, i));
		}
	}
	clr(visited);
	sort(counts.begin(), counts.end());

	LL ans = 0;
	rep(it, counts.rbegin(), counts.rend()) {
		if(!good[it->second]) {
			dfs(it->second);
			rep(i, 1, n+1) {
				if(visited[i])	good[i] = true;
			}
			ans++;
		}
	}
	pll(ans); nl;

}
