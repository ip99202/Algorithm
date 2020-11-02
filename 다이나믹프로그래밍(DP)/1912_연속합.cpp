#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[100001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &dp[i]);
	int res = dp[0];
	for (int i = 1; i < n; i++) {
		if (dp[i - 1] > 0 && dp[i - 1] + dp[i] > 0)
			dp[i] += dp[i - 1];
		if (res < dp[i])
			res = dp[i];
	}
	printf("%d", res);
}