#include<iostream>
#include<algorithm>
#include<math.h>
#define BIG ((int)1e9+9)
using namespace std;
typedef long long ll;
ll dp[500001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	dp[1] = 1, dp[2] = 3;
	for (ll i = 3; i <= 50000; i++)
		dp[i] = dp[i - 1] * (2 * i - 1) % BIG;
	cout << dp[n];
	return 0;
}