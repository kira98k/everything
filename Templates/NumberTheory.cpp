#include <bits/stdc++.h>
#include <climits>
#define all(x) x.begin(), x.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define srep(i, begin, end) for (__typeof(end) i = begin; i != end; i++)
#define si(x) int x = scanInt();
#define sll(x) LL x = scanLong();
#define sci(x) int x; scanf("%d", &x);
#define scll(x) LL x; scanf("%lld", &x);
#define svll(x, n) VLL x(n); rep(i, 0, n) x[i] = scanLong();
#define pi(x) printf("%d ", x)
#define pll(x) printf("%lld ", x)
#define pvll(x) for(auto it : x)	pll(it);
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
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<pair<LL,LL>> VPLL;
typedef vector<vector<LL>> VVLL;
typedef deque<bool> DB;
typedef deque<int> DI;
typedef deque<LL> DLL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const LL MOD = 1e9+7;

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

vector<PLL> primeFactorization(LL n) {
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

LL modpow(LL a, LL n, LL m) {
	if(n == 0)	return 1;
	if(n == 1)	return a%m;
	if(n == 2)	return (a*a)%m;
	LL res = 1;
	while(n != 0) {
		if(n%2 == 1)	res = (res*a)%m;
		n >>= 1;
		a = (a*a)%m;
	}
	return res;
}


LL modinv(LL x, LL m) {
	// modpow from modular.cpp
	return modpow(x, phi[m]-1, m);
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
	factorials[0] = factorials[1] = 1;
	for(LL i = 2; i < MAXN; i++)
		factorials[i] = (i * factorials[i-1])%m;
}

LL Combinatorics(LL n, LL r, LL m) {
	LL num = factorials[n];
	LL den = (factorials[r] * factorials[n-r])%m;
	LL ret = num * modinv(den, m);
	return ret;
}

// Lucas Theorem
LL LucasComb(LL n, LL r, LL m) {
	LL ret = 1;
	while(n != 0 || r != 0) {
		if(n%m < r%m)	return 0;
		ret = (ret * Combinatorics(n%m, r%m, m));
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