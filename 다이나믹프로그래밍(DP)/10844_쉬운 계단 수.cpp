#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
ll dp[101][101];

void stair(int a, int b) {
	if (b == 0)
		dp[a][b] = dp[a - 1][b + 1];
	else if (b == 9)
		dp[a][b] = dp[a - 1][b - 1];
	else
		dp[a][b] = dp[a - 1][b - 1] + dp[a - 1][b + 1] % 1000000000;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j < 10; j++) {
			stair(i, j);
		}
	}
	ll sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[n][i]) % 1000000000;
	printf("%lld", sum);
}
