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

const LL MAXN = 2010;
struct Edge {
	LL src, dest, wgt;
	Edge(LL s, LL d, LL w) {
		src = s; dest = d; wgt = w;
	}
};

bool compare(Edge a, Edge b) {
	return a.wgt < b.wgt;
}

LL distance(PLL a, PLL b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}


LL parent[MAXN];

LL findRoot(LL x) {
	if(x != parent[x])
		parent[x] = findRoot(parent[x]);
	return parent[x];
}

void unite(LL x, LL y) {
	LL rx = findRoot(x), ry = findRoot(y);
	if(rx < ry)	parent[ry] = rx;
	else	parent[rx] = ry;
}

vector<Edge> minimuSpanningTree(vector<Edge> edges, LL n) {
	rep(i, 0, n)	parent[i] = i;
	vector<Edge> mst;
	sort(edges.begin(), edges.end(), compare);
	rep(it, edges.begin(), edges.end()) {
		LL rx = findRoot(it->src), ry = findRoot(it->dest);
		if(rx != ry) {
			unite(rx, ry);
			mst.push_back(*it);
		}
	}
	return mst;
}

int main() {
	sll(n);
	vector<Edge> medges;
	vector<PLL> positions(n+1);
	vector<LL> ks(n+1), cs(n+1);
	rep(i, 1, n+1)	positions[i] = make_pair(scanLong(), scanLong());
	rep(i, 1, n+1)	cs[i] = scanLong();
	rep(i, 1, n+1)	ks[i] = scanLong();

	rep(i, 1, n+1) {
		rep(j, i+1, n+1) {
			LL wgt = (ks[i] + ks[j]) * distance(positions[i], positions[j]);
			medges.push_back(Edge(i, j, wgt));
		}
		medges.push_back(Edge(0, i, cs[i]));
	}
	vector<Edge> mst = minimuSpanningTree(medges, n+1);
	VLL plants; vector<PLL> edges;
	LL cost = 0;
	rep(it, mst.begin(), mst.end()) {
		if(it->src == 0)	plants.push_back(it->dest);
		else	edges.push_back(make_pair(it->src, it->dest));
		cost += it->wgt;
	}
	pll(cost); nl;
	pll((LL)plants.size()); nl;
	rep(it, plants.begin(), plants.end())	pll(*it); nl;
	pll((LL)edges.size()); nl;
	rep(it, edges.begin(), edges.end())	pll(it->first), pll(it->second), nl;
}
