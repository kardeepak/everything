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

const LL MAXN = 2e5+10;
LL distFrom1[MAXN];
LL distFromN[MAXN];
bool visited[MAXN];
VLL adj[MAXN], special;


int main() {
	sll(n); sll(m); sll(k);
	rep(i, 0, k)	special.push_back(scanLong());
	rep(i, 0, m) {
		sll(a); sll(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// BFS from 1
	clr(visited);
	queue<LL> q;
	q.push(1);
	rep(i, 1, n+1)	distFrom1[i] = LONG_MAX;
	distFrom1[1] = 0;
	while(!q.empty()) {
		LL curr = q.front(); q.pop();
		visited[curr] = true;
		rep(it, adj[curr].begin(), adj[curr].end()) {
			if(!visited[*it]) {
				q.push(*it);
				distFrom1[*it] = min(distFrom1[*it], distFrom1[curr] + 1);
			}
		}
	}

	// BFS from N
	clr(visited);
	q.push(n);
	rep(i, 1, n+1)	distFromN[i] = LONG_MAX;
	distFromN[n] = 0;
	while(!q.empty()) {
		LL curr = q.front(); q.pop();
		visited[curr] = true;
		rep(it, adj[curr].begin(), adj[curr].end()) {
			if(!visited[*it]) {
				q.push(*it);
				distFromN[*it] = min(distFromN[*it], distFromN[curr] + 1);
			}
		}
	}

	vector<PLL> data;
	rep(it, special.begin(), special.end()) {
		data.emplace_back(distFrom1[*it] - distFromN[*it], *it);
	}
	sort(data.begin(), data.end());

	LL best = 0, maxm = LONG_MIN;
	rep(it, data.begin(), data.end()) {
		best = max(best, maxm + distFromN[it->second]);
		maxm = max(maxm, distFrom1[it->second]);
	}

	LL ans = min(distFrom1[n], best+1);
	pll(ans); nl;
}
