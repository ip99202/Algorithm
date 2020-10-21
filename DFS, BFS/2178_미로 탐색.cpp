#include<iostream>
#include<queue>
#include<utility>
using namespace std;
queue < pair<int, int>>q;
int arr[101][101];
int n, m;
int visited[101][101];
int cnt[101][101];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void bfs(int y, int x) {
	visited[1][1] = 1;
	cnt[0][0] = 1;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<1 || ny>n || nx<1 || nx>m)
				continue;
			if (arr[ny][nx] == 1 && visited[ny][nx] == 0) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = 1;
				cnt[ny][nx] = cnt[y][x] + 1;
			}
		}
		if (visited[n][m] == 1)
			break;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	bfs(1, 1);
	printf("%d", cnt[n][m] + 1);
}