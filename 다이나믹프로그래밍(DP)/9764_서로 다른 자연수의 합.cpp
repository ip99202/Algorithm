#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int dp[2001][2001];

int go_sum(int now, int sum, int end) {
	if (sum == end)
		return 1;
	if (now == end || sum > end)
		return 0;
	if (dp[now][sum] != -1)
		return dp[now][sum];
	dp[now][sum] = 0;
	return dp[now][sum] = (go_sum(now + 1, sum, end) + go_sum(now + 1, sum + now + 1, end)) % 100999;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		int n; cin >> n;
		cout << go_sum(0, 0, n) << "\n";
	}
	return 0;
}