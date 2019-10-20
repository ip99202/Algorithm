#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll dp[101];

ll go(int k) {
	if (k <= 0)
		return 0;
	if (k < 7)
		return k;
	if (dp[k] >= 0)
		return dp[k];
	dp[k] = max({ dp[k], go(k - 3) * 2, go(k - 4) * 3, go(k - 5) * 4 });
	return dp[k];
}

int main() {
	int n;
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%lld", go(n));
}