#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
#include<string>	
#define INF 999999999
using namespace std;
typedef pair<int, int>P;
priority_queue<P, vector<P>, greater<P>>pq;
long long dp[100][100];

int main() {
	int t, n;
	long long res = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n == 1) {
			printf("10\n");
			continue;
		}
		for (int i = 1; i <= 10; i++) {
			dp[1][i] = i;
		}
		for (int i = 2; i < n; i++) {
			dp[i][1] = 1;
			for (int j = 2; j <= 10; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		for (int i = 1; i <= 10; i++)
			res += dp[n - 1][i];
		printf("%lld\n", res);
		res = 0;
	}
}