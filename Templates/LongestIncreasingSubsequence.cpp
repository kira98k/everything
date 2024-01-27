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

// O(n*n)
LL longestIncreasingSubsequenceN2(VLL array) {
	LL n = array.size();
	// dp[i] is the longest sequence ending at index i
	VLL dp(n, 1);
	rep(i, 0, n) {
		rep(j, 0, i) {
			// if array[i] > array[j] then add array[i] to the subsequence ending at index j
			if(array[i] > array[j])	dp[i] = max(dp[i], dp[j]+1);
		}
	}
	// maximum length of such subsequences
	return *max_element(dp.begin(), dp.end());
}

// O(n*log(n))
LL longestIncreasingSubsequenceNlogN(VLL array) {
	LL n = array.size();
	const LL INF = 1e9;
	// dp[i] is the element at which the subsequence of length i ends
	// if multiple such elements are present then the minimum is considered
	VLL dp(n+1, INF);
	dp[0] = -INF;
	rep(i, 0, n) {
		// if array[i] > dp[j-1] then dp[j] = min(array[i], dp[j])
		LL j = upper_bound(dp.begin(), dp.end(), array[i]) - dp.begin();
		if(dp[j-1] < array[i] && array[i] < dp[j])
			dp[j] = array[i];
	}

	LL ans = 0;
	rep(i, 0, n+1) {
		if(dp[i] < INF)	ans = i;
	}
	return ans;
}

// Implementation Details : https://cp-algorithms.com/sequences/longest_increasing_subsequence.html#toc-tgt-6
int main() {
}
