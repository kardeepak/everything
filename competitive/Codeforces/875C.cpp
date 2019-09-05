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

const LL MAX = 1e5+10;
LL N, M;
VLL words[MAX];
set<LL> adj[MAX];
bool capital[MAX], visited[MAX];
bool possible = true;

void addEdges(LL b) {
	LL a = b-1;
	LL l = min(words[a].size(), words[b].size());
	rep(i, 0, l) {
		if(words[a][i] != words[b][i]) {
			if(words[a][i] < words[b][i])	adj[words[b][i]].insert(words[a][i]);
			else if(words[a][i] > words[b][i])	capital[words[a][i]] = true;
			break;
		}
		if(i+1 == l && words[b].size() < words[a].size())	possible = false;
	}
}

void dfs(LL src) {
	capital[src] = true;
	visited[src] = true;
	srep(it, adj[src].begin(), adj[src].end()) {
		if(!visited[*it])	dfs(*it);
	}
}

bool compare(LL a, LL b) {
	if(a < b && (capital[a] || !capital[b]))	return true;
	if(a > b && (capital[a] && !capital[b]))	return true;
	if(a == b)	return true;
	return false;
}

void check(LL b) {
	LL a = b-1;
	LL l = min(words[a].size(), words[b].size());
	rep(i, 0, l) {
		if(words[a][i] != words[b][i]) {
			if(!compare(words[a][i], words[b][i]))	possible = false;
			break;
		}
	}
}


int main() {
	N = scanLong(); M = scanLong();
	rep(i, 0, N) {
		sll(l);
		rep(j, 0, l)	words[i].push_back(scanLong());
		if(i > 0)	addEdges(i);
	}
	rep(i, 1, M+1)	if(capital[i])	dfs(i);
	rep(i, 1, N)	check(i);
	if(possible) {
		puts("Yes");
		VLL caps;
		rep(i, 1, M+1)	if(capital[i])	caps.push_back(i);
		pll((LL)caps.size()); nl;
		rep(it, caps.begin(), caps.end())	pll(*it); nl;
	}
	else	puts("No");
}
