#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#define INF 1000000000
using namespace std;
int n, m, dist[501];
int time[501][501];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			time[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (time[x][y] > z)
			time[x][y] = z;
	}
	fill(dist, dist + 501, INF);
	dist[1] = 0;
	bool cycle = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dist[j] != INF && dist[k] > dist[j] + time[j][k]) {
					dist[k] = dist[j] + time[j][k];
					if (i == n) cycle = true;
				}
			}
		}
	}

	if (cycle)
		printf("-1");
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF)
				printf("-1\n");
			else
				printf("%d\n", dist[i]);
		}
	}
}