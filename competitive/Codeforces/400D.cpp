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
typedef unsigned long long int  ULL; // 64 bit unsigned integer
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
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

const LL MAXN = 1e5+10;
const LL MAXK = 510;

struct Edge {
	LL src, dest, weight;
	Edge(LL s, LL d, LL w) {
		src = s; dest = d; weight = w;
	}
};

bool cmp(Edge a, Edge b) {
	return a.weight < b.weight;
}

struct Tree {
	LL root, size;
	Tree() {}
	Tree(LL r, LL s) {
		root = r; size = s;
	}
};


LL types[MAXN], cnt[MAXK];
Tree trees[MAXN];
vector<Edge> edges;

LL find(LL x) {
	if(x != trees[x].root) {
		LL root = find(trees[x].root);
		trees[x].root = root;
		trees[x].size = trees[root].size;
	}
	return trees[x].root;
}

void unite(LL a, LL b) {
	a = find(a); b = find(b);
	if(trees[a].size >= trees[b].size) {
		trees[a].size += trees[b].size;
		trees[b].root = a;
	} else {
		trees[b].size += trees[a].size;
		trees[a].root = b;
	}
}

int main() {
	sll(n); sll(m); sll(k);
	LL idx = 1;
	rep(i, 1, k+1) {
		cnt[i] = scanLong();
		rep(j, 0, cnt[i])	types[idx++] = i;
	}
	rep(i, 1, n+1)	trees[i] = Tree(i, 1);
	rep(i, 0, m) {
		sll(u); sll(v); sll(k);
		edges.push_back(Edge(u, v, k));
		edges.push_back(Edge(v, u, k));
		if(k == 0)	unite(u, v);
	}
	bool pos = true;
	LL roots[k+1];
	rep(i, 1, n+1) {
		if(types[i] != types[i-1])
			roots[types[i]] = find(i);
		else if(roots[types[i]] != find(i)) {
			pos = false;
			break;
		}
	}
	if(!pos) {
		puts("No");
		return 0;
	}
	puts("Yes");
	LL dist[k+1][k+1];
	rep(i, 1, k+1) {
		rep(j, 1, k+1)
			dist[i][j] = (i != j ? LONG_MAX : 0);
	}
	rep(it, edges.begin(), edges.end()) {
		LL typeA = types[it->src], typeB = types[it->dest];
		dist[typeA][typeB] = min(dist[typeA][typeB], it->weight);
		dist[typeB][typeA] = min(dist[typeB][typeA], it->weight);
	}
	rep(l, 1, k+1) {
		rep(i, 1, k+1) {
			rep(j, 1, k+1) {
				if(dist[i][j] > dist[i][l] + dist[l][j] && (dist[i][l] != LONG_MAX && dist[l][j] != LONG_MAX))
					dist[i][j] = dist[i][l] + dist[l][j];
			}
		}
	}
	rep(i, 1, k+1) {
		rep(j, 1, k+1) {
			if(dist[i][j] == LONG_MAX)	dist[i][j] = -1;
			pll(dist[i][j]);
		} nl;
	}
}
