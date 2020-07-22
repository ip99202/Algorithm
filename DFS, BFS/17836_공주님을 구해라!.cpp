#include<iostream>	
#include<algorithm>
#include<vector>
#include<queue>
#define INF 999999999
using namespace std;
typedef pair<int, int>P;
typedef pair<int, bool>PP;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int arr[101][101];
PP visited[101][101];
queue<P>q;
int n, m, t, cut;

int bfs() {
	visited[0][0].first = 1;
	q.push(P(0, 0));
	while (!q.empty()) {
		P now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (visited[nx][ny].first != 0)
				continue;
			if (arr[nx][ny] == 1)
				continue;
			visited[nx][ny].first = visited[now.first][now.second].first + 1;
			q.push(P(nx, ny));
			if (arr[nx][ny] == 2)
				cut = visited[now.first][now.second].first;
			if (nx == n - 1 && ny == m - 1)
				return visited[now.first][now.second].first;
		}
	}
	return INF;
}

int main() {
	P sword;
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2)
				sword = P(i, j);
		}
	}
	int time = bfs();
	if (cut == 0 && time == INF) {
		printf("Fail");
		return 0;
	}
	int dist = (n - sword.first) + (m - sword.second) - 2;
	int res = min(cut + dist, time);
	if (cut == 0)
		res = time;
	if (res <= t)
		printf("%d", res);
	else
		printf("Fail");
	return 0;
}