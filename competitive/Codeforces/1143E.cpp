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

int main() {
	sll(n); sll(m); sll(q);
	LL perm[n], seq[m], next[m], last[m][22];
	map<LL,LL> next_perm, next_seq;
	rep(i, 0, n) {
		perm[i] = scanLong();
		if(i > 0)		next_perm[perm[i-1]] = perm[i];
		if(i+1 == n)	next_perm[perm[i]] = perm[0];
	}

	rep(i, 0, m)	seq[i] = scanLong();
	rep(i, m, 0) {
		LL req = next_perm[seq[i]];
		next_seq[seq[i]] = i;
		if(next_seq.find(req) == next_seq.end())	next[i] = LONG_MAX;
		else	next[i] = next_seq[req];
		
	} 

	rep(i, 0, 20) {
		rep(j, m, 0) {
			if(i == 0)	last[j][i] = j;
			else if(i == 1)	last[j][i] = next[j];
			else {
				LL n = last[j][i-1];
				if(n == LONG_MAX || next[n] == LONG_MAX)	last[j][i] = LONG_MAX;
				else	last[j][i] = last[next[n]][i-1];
			}
		}
	}

	LL lastn[m];
	LL pw = 0;
	while(n >= (1ll<<pw))	pw++;
	rep(i, 0, m) {
		LL t = n, a = i;
		rep(j, pw, 0) {
			if(a == LONG_MAX)	break;
			if((1ll<<j) <= t) {
				a = last[a][j];
				t -= (1ll<<j);
				if(t > 0 && a != LONG_MAX)
					a = next[a];
			}
		}
		lastn[i] = a;
	}

	LL table[m+1][22]; clr(table);
	rep(i, 0, 20) {
		rep(s, 0, m) {
			LL e = s + (i > 0 ? (1ll<<(i-1)) : 0);
			if(i == 0)	table[s][i] = lastn[s];
			else if(e < m)	table[s][i] = min(table[s][i-1], table[e][i-1]);
			else 	table[s][i] = table[s][i-1];
		}
	}

	rep(_, 0, q) {
		sll(l); sll(r); l--; r--;
		LL pw = 0;
		while((r-l+1) >= (1ll<<pw))	pw++; pw--;
		LL m = min(table[l][pw], table[r-(1ll<<pw) + 1][pw]);
		if(l <= m && m <= r)	cout << 1;
		else	cout << 0;
	}
	cout << endl;
}
