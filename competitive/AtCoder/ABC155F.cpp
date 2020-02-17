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
LL diff[MAXN]; // 1 if bombs[i].second != bombs[i-1].second

// Graph : i and j are connected if some flipping one of the given ranges cause diff[i] & diff[j] to change
// adj[src] = [(dest, index)]
vector<PLL> adj[MAXN];
bool visited[MAXN];
set<LL> selected; // selected edges

void dfs(LL src, LL index, LL parent) {
	if(visited[src])	return;
	// cout << src << " " <<  index << " "  << parent << endl;
	visited[src] = true;
	rep(it, adj[src].begin(), adj[src].end()) {
		if(it->first != -1)	dfs(it->first, it->second, src);
	}
	
	if(diff[src] == 1 && parent != -1 && index != -1) {
		diff[parent] ^= 1;
		diff[src] ^= 1;
		selected.insert(index);
	} else if(diff[src] == 1) {
		rep(it, adj[src].begin(), adj[src].end()) {
			if(it->first == -1) {
				selected.insert(it->second);
				return;
			}
		}
		selected.clear();
	}
}



int main() {
	sll(n); sll(m);
	PLL bombs[n], ranges[m];
	rep(i, 0, n) {
		bombs[i].first = scanLong();
		bombs[i].second = scanLong();
	}
	rep(i, 0, m) {
		ranges[i].first = scanLong();
		ranges[i].second = scanLong();
	}

	sort(bombs, bombs+n);
	rep(i, 0, n) {
		if(i == 0)	diff[i] = bombs[i].second;
		else	diff[i] = bombs[i].second ^ bombs[i-1].second;
	}

	// rep(i, 0, n)	pll(bombs[i].first); nl;
	// rep(i, 0, n)	pll(bombs[i].second); nl;
	// rep(i, 0, n)	pll(diff[i]); nl;
	// puts("-------------");

	rep(i, 0, m) {
		LL left = ranges[i].first, right = ranges[i].second;
		LL frst = partition_point(bombs, bombs+n, [&left](PLL a) { return a.first < left; }) - bombs;
		LL scnd = partition_point(bombs, bombs+n, [&right](PLL a) { return a.first <= right; }) - bombs;
		if(frst < scnd) {
			if(scnd == n)	scnd = -1;
			// cout << left << " " << right << " : " << frst << " " << scnd << " : " << i+1 << endl;
			adj[frst].push_back(make_pair(scnd, i+1));
			adj[scnd].push_back(make_pair(frst, i+1));
		}
	}
	// puts("-------------");

	rep(i, 0, n)	dfs(i, -1, -1);
	if(selected.size() == 0) {
		puts("-1");
	} else {
		pll((LL)selected.size()); nl;
		srep(it, selected.begin(), selected.end())	pll(*it); nl;
	}
}
