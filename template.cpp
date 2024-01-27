#include <bits/stdc++.h>
#include <climits>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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



/*
YOU CAN DO THIS! ;)
0. Always check edge cases
1. Do not forget to clean up for next test case. 
2. Do not do unecessary clean up. They are not free.
3. Always check contraints.
4. Always test with large input size.
5. Always check output format.
*/
void solve() {
	cout << "Hello, World!" << endl;
}

int main() {

	// sll(t);
	LL t = 1;

	rep(tc, 0, t) {
		#ifdef DEBUG
		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		cout << "Case #" << tc << ": " << endl;
		cout << "------------------------------" << endl;
		#endif
		solve();
		#ifdef DEBUG
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		cout << "------------------------------" << endl;
		cout << "Time Taken: " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << "[ms]" << endl << endl;
		#endif
	}
}


