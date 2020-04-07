#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[50], dp[50];

void fibo() {
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < 42; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	fibo();
	dp[2] = 2;
	dp[3] = 6;
	for (int i = 4; i < 42; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		for (int j = i - 1; j > 0; j--) {
			dp[i] += arr[j];
		}
	}
	if (k == 1 || k == n)
		printf("%d", dp[k] * arr[n - k] + arr[k - 1] * dp[n - k + 1]);
	else
		printf("%d", dp[k] * arr[n - k] + arr[k - 1] * dp[n - k + 1] - arr[n - k] * arr[k - 1]);
	return 0;
}