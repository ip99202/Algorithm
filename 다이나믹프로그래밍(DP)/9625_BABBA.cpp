#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int>P;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<P>dp(n + 1);
	dp[0].first = 1;
	for (int i = 1; i <= n; i++) {
		dp[i].first = dp[i - 1].second;
		dp[i].second = dp[i - 1].first + dp[i - 1].second;
	}
	cout << dp[n].first << " " << dp[n].second;
	return 0;
}