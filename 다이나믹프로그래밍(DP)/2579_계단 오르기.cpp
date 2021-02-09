#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dp[301], stair[301];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &stair[i]);
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	dp[3] = max(stair[2] + stair[3], stair[1] + stair[3]);
	for (int i = 4; i <= n; i++)
		dp[i] = max(stair[i] + dp[i - 2], stair[i] + stair[i - 1] + dp[i - 3]);
	printf("%d", dp[n]);
	return 0;
}