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
LL size, SegArray[MAXN], tree[3*MAXN], lazy[3*MAXN];

// Build Segment Tree from array

void build(LL ss, LL se, LL si) {
	// tree[si] store the sum of array[ss...se]
	if(ss == se)	tree[si] = SegArray[ss];
	else {
		LL mid = (ss+se)>>1;
		build(ss, mid, 2*si+1);
		build(mid+1, se, 2*si+2);
		// the operator here can be anything as long as it is associative
		// that is, a op (b op c) == (a op b) op c
		tree[si] = tree[2*si+1] + tree[2*si+2];
	}
}

void build(LL n) {
	size = n;
	build(0ll, n-1, 0ll);
}


// Propagate Values from lazy to its children
void propagate(LL ss, LL se, LL si) {
	// This function will change based on the operation
	if(lazy[si] != 0) {
		// Adding the lazy[si] the subarray sum of array[ss...se]
		tree[si] += (se-ss+1) * lazy[si];
		if(ss != se) {
			// passing lazy[si] to its children
			lazy[2*si+1] += lazy[si];
			lazy[2*si+2] += lazy[si];
		}
		lazy[si] = 0;
	}
}

// Range Update
void update(LL ss, LL se, LL si, LL qs, LL qe, LL value) {
	if(se < qs || ss > qe || ss > se)	return;
	propagate(ss, se, si);
	if(qs <= ss && se <= qe) {
		tree[si] += (se-ss+1) * value;
		if(ss != se) {
			// lazy[si] stores the value needed to be added to the subarray array[ss...se]
			lazy[2*si+1] += value;
			lazy[2*si+2] += value;
		}
	}
	else {
		LL mid = (ss+se)>>1;
		update(ss, mid, 2*si+1, qs, qe, value);
		update(mid+1, se, 2*si+2, qs, qe, value);
		tree[si] = tree[2*si+1] + tree[2*si+2];
	}
}

void update(LL qs, LL qe, LL value) {
	update(0, size-1, 0, qs, qe, value);
}

// Get Sum
LL sum(LL ss, LL se, LL si, LL qs, LL qe) {
	if(se < qs || ss > qe || ss > se)	return 0;
	propagate(ss, se, si);
	if(qs <= ss && se <= qe)	return tree[si];
	else {
		LL mid = (ss+se)>>1;
		LL left_sum = sum(ss, mid, 2*si+1, qs, qe);
		LL right_sum = sum(mid+1, se, 2*si+2, qs, qe);
		return left_sum + right_sum;
	}
}

LL sum(LL qs, LL qe) {
	return sum(0, size-1, 0, qs, qe);
}


struct Query;

const LL MAXQ = 1e5+10;
vector<Query> queries;
LL MosArray[MAXN], answers[MAXQ];
LL BLOCK_SIZE = 448; // ceil(sqrt(MAXN))


struct Query {
	LL left, right, index;
	LL value;
	Query(LL i, LL l, LL r, LL v) {
		index = i;
		left = l;
		right = r;
		value = v;
	}
	bool operator < (const Query &q) {
		if((left / BLOCK_SIZE) == (q.left / BLOCK_SIZE))
			return right < q.right;
		return ((left / BLOCK_SIZE) < (q.left / BLOCK_SIZE));
	}
};

// add, remove & getAnswer Must be O(F) functions
// Add to Data Structure
void add(LL left, LL right) {
	LL minm = min(MosArray[left], MosArray[right]);
	LL maxm = max(MosArray[left], MosArray[right]);
	update(minm, maxm, 1ll);
}
// Remove from Data Structure
void remove(LL left, LL right) {
	LL minm = min(MosArray[left], MosArray[right]);
	LL maxm = max(MosArray[left], MosArray[right]);
	update(minm, maxm, -1ll);
}
// Get Answer from Data Structure
LL getAnswer(LL value) {
	return sum(value, value);
}

// Complexity of mo's algorithm is O((N + Q) * sqrt(N) * F)
void mosAlgorithm() {
	// Sort queries by first the block and by right index if blocks are same
	sort(queries.begin(), queries.end());
	// Current range is empty
	LL currLeft = 0, currRight = 0;
	rep(it, queries.begin(), queries.end()) {
		LL left = it->left, right = it->right;
		// As long as the current range is not the same as the query range 
		// keep adding or removing elements as needed
		while(currLeft > left) {
			currLeft--;
			add(currLeft, currLeft+1);
		}
		while(currRight < right) {
			add(currRight, currRight+1);
			currRight++;
		}
		while(currLeft < left) {
			remove(currLeft, currLeft+1);
			currLeft++;
		}
		while(currRight > right) {
			currRight--;
			remove(currRight, currRight+1);
			
		}
		// When current range is same as the query range store the answer from data structure
		answers[it->index] = getAnswer(it->value);
	}
}

void clear() {
	queries.clear();
	clr(MosArray); clr(answers);
	clr(SegArray); clr(tree); clr(lazy);	
}

void solve() {
	clear();
	sll(n); sll(q);
	set<LL> compress;

	rep(i, 0, n) {
		MosArray[i] = scanLong();
		compress.insert(MosArray[i]);
	}
	rep(i, 0, q) {
		sll(l); l--;
		sll(r); r--;
		sll(v);
		queries.push_back(Query(i, l, r, v));
		compress.insert(v);
	}

	LL mapped = 1;
	map<LL, LL> decompress;
	srep(it, compress.begin(), compress.end()) {
		decompress[*it] = mapped++;
	}

	rep(i, 0, n) {
		MosArray[i] = decompress[MosArray[i]];
	}
	rep(i, 0, q) {
		queries[i].value = decompress[queries[i].value];
	}

	build(MAXN);

	mosAlgorithm();

	rep(i, 0, q) {
		pll(answers[i]); nl;
	}
}

int main() {
	sll(t);
	rep(_, 0, t) {
		solve();
	}
}
