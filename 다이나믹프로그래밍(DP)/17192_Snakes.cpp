#include <iostream>
#include <algorithm>
#define INF 999999999
using namespace std;
int n, k, arr[401], dp[401][401];

int main() {
	scanf("%d %d", &n, &k);
	int res = 0, maxs = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		maxs = max(maxs, arr[i]);
		dp[i][0] = maxs * i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = INF;
			maxs = arr[i];
			for (int f = i - 1; f >= 0; f--) {
				dp[i][j] = min(dp[i][j], dp[f][j - 1] + maxs * (i - f));
				maxs = max(maxs, arr[f]);
			}
		}
		res += arr[i];
	}
	printf("%d", dp[n][k] - res);
}