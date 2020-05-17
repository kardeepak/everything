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

map<char, set<char>> graph;
map<char, LL> incoming;

void deleteNode(char node) {
    for(char c : graph[node]) {
        incoming[c]--;
    }
    graph[node].clear();
}

string solve() {
	graph.clear(); incoming.clear();
    sll(r); sll(c);
    string wall[r];
    set<char> bs;
    rep(i, 0, r)    cin >> wall[i];
    rep(i, 0, r) {
        rep(j, 0, c) {
            bs.insert(wall[i][j]);
            if(i+1 < r && wall[i][j] != wall[i+1][j]) {
            	if(graph[wall[i][j]].find(wall[i+1][j]) == graph[wall[i][j]].end()) {
	                graph[wall[i][j]].insert(wall[i+1][j]);
	                incoming[wall[i+1][j]]++;
	            }
            }
        }
    }
    string ans = "";
    while(true) {
        char node = '#';
        for(char c : bs) {
            if(incoming[c] == 0)    node = c;
        }

        if(node == '#') break;
        deleteNode(node);
        bs.erase(node);
        ans = node + ans;
    }
    
    if(!bs.empty())	return "-1";
    return ans;
}

int main() {
    sll(t);
    rep(c, 1, t+1) {
        string ans = solve();
        cout << "Case #" << c << ": " << ans << endl;
    }
}
