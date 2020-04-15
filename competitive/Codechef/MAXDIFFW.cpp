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

struct Edge {
	LL src, dest, weight;
	Edge() {}
	Edge(LL s, LL d, LL w) {
		src = s;
		dest = d;
		weight = w;
	}
};

bool operator < (const Edge a, const Edge b) {
	return a.weight < b.weight;
}

PLL getPair(Edge e) {
	return make_pair(e.src, e.dest);
}

int main() {
	sll(n);
	priority_queue<Edge> pq[n+1];
	rep(i, 1, n+1) {
		rep(j, 1, n+1) {
			sll(w);
			if(i != j)	pq[i].push(Edge(i, j, w));
		}
	}
	map<PLL, bool> selected;
	// selected first
	Edge first(0, 0, 0);
	LL index = -1;
	rep(i, 1, n+1) {
		if(index == -1 || first < pq[i].top()) {
			first = pq[i].top();
			index = i;
		}
	}
	pq[index].pop();
	selected[getPair(first)] = true;
	cout << first.src << " " << first.dest << " " << endl; cout.flush();

	while(true) {
		LL src, dest; cin >> src >> dest;
		selected[make_pair(src, dest)] = true;

		while(!pq[dest].empty() && selected[getPair(pq[dest].top())]) {
			pq[dest].pop();
		}

		if(pq[dest].empty())	break;

		Edge next = pq[dest].top(); pq[dest].pop();
		selected[getPair(next)] = true;
		cout << next.src << " " << next.dest << " " << endl; cout.flush();
	}
}
