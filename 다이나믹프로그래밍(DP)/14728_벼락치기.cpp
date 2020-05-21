#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int>P;
int dp[101][10001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, t; cin >> n >> t;
	vector<P>arr(n + 1);
	for (int i = 1; i <= n; i++) 
		cin >> arr[i].first >> arr[i].second;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			if (arr[i].first <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].first] + arr[i].second);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][t];
	return 0;
}