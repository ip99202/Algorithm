#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 999999999
using namespace std;
int arr[1001][1001];
int dist[1001];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			arr[i][j] = INF;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (arr[a][b] > c)
			arr[a][b] = c;
	}
	int st, end;
	scanf("%d%d", &st, &end);
	fill(dist, dist + 1001, INF);
	dist[st] = 0;
	bool flag;
	for (int i = 1; i < n; i++) {
		flag = false;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dist[j] != INF && dist[k] > dist[j] + arr[j][k]) {
					dist[k] = dist[j] + arr[j][k];
					flag = true;
				}
			}
		}
		if (!flag)
			break;
	}
	printf("%d", dist[end]);
	return 0;
}