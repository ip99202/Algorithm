#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<ll>dp(n + 1);
	dp[0] = 1;
	for (int i = 0; i < 20; i++) {
		for (int j = 1; j <= n; j++) {
			if (pow(2, i) <= j)
				dp[j] += dp[j - pow(2, i)];
			dp[j] %= 1000000000;
		}
	}
	cout << dp[n];
	return 0;
}