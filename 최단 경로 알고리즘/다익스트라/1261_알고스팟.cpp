#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<deque>
#include<queue>
#include<cstring>
#include<string>
#define INF 999999999
using namespace std;
typedef pair<int, int>P;
priority_queue<P, vector<P>, greater<P>>pq;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, arr[105][105], dist[105][105];

void dijkstra() {
	dist[0][0] = 0;
	pq.push(P(0, 0));
	while (!pq.empty()) {
		int x = pq.top().first;
		int y = pq.top().second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue;
			if (dist[nx][ny] > dist[x][y] + arr[nx][ny]) {
				dist[nx][ny] = dist[x][y] + arr[nx][ny];
				pq.push(P(nx, ny));
			}
		}
	}
	printf("%d", dist[m - 1][n - 1]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	dijkstra();
}