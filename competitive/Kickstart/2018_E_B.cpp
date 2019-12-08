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
#define ps(x) printf("%s", x)
#define nl printf("\n")
#define clr(a) memset(a, 0, sizeof(a))
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
LL mod = 1e9+7;

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

LL strDiff(string a, string b) {
	LL cnt = 0;
	rep(i, 0, a.length())	if(a[i] != b[i])	cnt++;
	return cnt;
}

int main() {
	sll(t);
	rep(_, 0, t) {
		// write your code here...
		cout << "Case #" << (_+1) << ": ";
		sll(n); sll(m); sll(p);
		string dems[n];
		set<string> forb;
		LL ones[p] = { 0 }, zeros[p] = { 0 };
		rep(i, 0, n) {
			cin >> dems[i];
			rep(j, 0, p) {
				if(dems[i][j] == '1')	ones[j]++;
				else	zeros[j]++;
			}
		}
		rep(i, 0, m) {
			string tmp; cin >> tmp;
			forb.insert(tmp);
		}
	
		string opt(p, '#');
		rep(i, 0, p) {
			if(ones[i] >= zeros[i])	opt[i] = '1';
			else	opt[i] = '0';
		}
		priority_queue< pair<LL, string>, vector< pair<LL, string> >, greater< pair<LL, string> > > pq;
		pq.push(make_pair(0, opt));
		map<string, bool> visited;
		while(!pq.empty()) {
			string curr = pq.top().second;
			LL dist = pq.top().first;
			pq.pop();
			visited[curr] = true;
			if(forb.find(curr) == forb.end()) {
				opt = curr;
				break;
			}
			rep(i, 0, p) {
				if(curr[i] == '0') {
					curr[i] = '1';
					if(!visited[curr])	pq.push(make_pair(dist + zeros[i] - ones[i], curr));
					curr[i] = '0';
				}
				else if(curr[i] == '1') {
					curr[i] = '0';
					if(!visited[curr])	pq.push(make_pair(dist + ones[i] - zeros[i], curr));
					curr[i] = '1';
				}
			}
		}


		LL minComp = 0;
		rep(i, 0, n)	minComp += strDiff(dems[i], opt);
		cout << minComp << endl;
	}
}
