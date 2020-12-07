#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long dist[100001], cost[100001], res[100001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
		scanf("%d", &dist[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &cost[i]);
	res[0] = cost[0] * dist[0];
	long long minn = cost[0];
	for (int i = 1; i < n; i++) {
		minn = min(minn, cost[i]);
		res[i] = res[i - 1] + minn * dist[i];
	}
	printf("%lld", res[n - 1]);
}