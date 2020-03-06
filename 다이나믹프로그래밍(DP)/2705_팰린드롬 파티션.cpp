#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dp[1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	dp[1] = 1, dp[2] = 2, dp[3] = 2;
	for (int i = 4; i <= 1000; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if ((i - j) % 2 == 1)
				continue;
			dp[i] += dp[(i - j) / 2];
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}