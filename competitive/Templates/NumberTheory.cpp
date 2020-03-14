// Returns GCD
LL gcd(LL a, LL b) {
	if(b == 0)	return a;
	return gcd(b, a%b);
}

// Returns GCD && x & y such that ax+by=GCD(a, b)
LL gcdExtend(LL a, LL b, LL &x, LL &y) {
	if(a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	LL _x, _y;
	LL g = gcdExtend(b%a, a, _x, _y);
	x = _y - (b/a)*_x;
	y = _x;
	return g;
}

//Find Primes upto MAXN
//N is prime if leastPrimeDivisor[N] == N
const LL MAXN = 1e6+10;
LL leastPrimeDivisor[MAXN];

void Sieve() {
	memset(leastPrimeDivisor, 0, sizeof(leastPrimeDivisor));
	leastPrimeDivisor[0] = leastPrimeDivisor[1] = -1;
	for(LL i = 2; i < MAXN; i++) {
		if(leastPrimeDivisor[i] == 0) {
			leastPrimeDivisor[i] = i;
			for(LL j = i*i; j < MAXN; j += i)
				leastPrimeDivisor[j] = i;
		}
	}
}

// If n < 10^6 otherwise use method in modular.cpp
bool isPrime(LL n) {
	return (leastPrimeDivisor[n] == n);
}

vector<LL> primeFactorization(LL n) {
	vector<PLL> ret;
	while(n != 1) {
		LL p = leastPrimeDivisor[n];
		LL cnt = 0;
		while(n%p == 0) {
			n /= p;
			cnt++;
		}
		ret.push_back(PLL(p,cnt));
	}
	return ret;
}

LL numberOfDivisors(LL n) {
	LL count = 1;
	while(n != 1) {
		LL p = leastPrimeDivisor[n];
		LL cnt = 0;
		while(n%p == 0) {
			n /= p;
			cnt++;
		}
		count = (count * (cnt+1));
	}
	return count;
}

LL sumOfDivisors(LL n) {
	LL sum = 1;
	while(n != 1) {
		LL p = leastPrimeDivisor[n];
		LL cnt = 0;
		while(n%p == 0) {
			n /= p;
			cnt++;
		}
		sum = (sum * ((LL)pow(p, cnt+1) - 1) / (p - 1));
	}
	return sum;
}

LL phi[MAXN];

void totient() {
	for(LL i = 0; i < MAXN; i++)	phi[i] = i;
	for(LL i = 2; i < MAXN; i++) {
		if(phi[i] == i) {
			phi[i] = i-1;
			for(LL j = 2*i; j < MAXN; j += i)
				phi[j] = phi[j] * (i-1) / i; 
		}
	}
}

LL modinv(LL x, LL m) {
	// modpow from modular.cpp
	return modular::modpow(x, phi[m]-1, m);
}

LL chineseRemainderTheorem(vector<LL> As, vector<LL> Ms) {
	LL M = 1;
	rep(it, Ms.begin(), Ms.end()) M = (M*(*it));
	vector<LL> Xs, Xinv;
	rep(it, Ms.begin(), Ms.end()) {	Xs.push_back(M/(*it)); Xinv.push_back(modinv(Xs.back(), *it)); }
	LL ret = 0;
	rep(i, 0, As.size()) ret += As[i]*Xs[i]*Xinv[i];
	return ret;
}

LL factorials[MAXN];
void fact(LL m) {
	fact[0] = fact[1] = 1;
	for(LL i = 2; i < MAXN; i++)
		fact[i] = (i * fact[i-1])%m;
}

LL Combinatorics(LL n, LL r, LL m) {
	LL num = fact[n];
	LL den = (fact[r] * fact[n-r])%m;
	LL ret = num * modinv(den, m);
	return ret;
}

// Lucas Theorem
LL LucasComb(LL n, LL r, LL m) {
	LL ret = 1;
	while(n != 0 || r != 0) {
		if(n%m < r%m)	return 0;
		ret = (ret * Combinatorics(n%m, r%m));
		n /= m;
		r /= m;
	}
	return ret;
}

// Wilson's theorem (n-1)! mod n == n-1 iff n is prime
bool Wilson(LL n) {
	LL fact = 1;
	for(LL i = 1; i <= n-1; i++)	fact = (fact*i)%n;
	return (fact == n-1);
}