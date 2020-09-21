#include<iostream>
#include<algorithm>
using namespace std;
int dp[500];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	dp[1] = dp[2] = dp[3] = 1;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i)
				dp[(i * (i - 1)) / 2 + j] = 1;
			else
				dp[(i * (i - 1)) / 2 + j] =
				dp[((i - 2) * (i - 1)) / 2 + j - 1] + dp[((i - 2) * (i - 1)) / 2 + j];
		}
	}
	cout << dp[(n * (n - 1)) / 2 + k];
	return 0;
}