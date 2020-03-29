#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
queue<pair<int, int>>q;
int n, top, l = 0, cnt = 0, k = 0;
int arr[100][100];
int visited[100][100];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int ans = 0;
void bfs(int y, int x, int h) {
	visited[y][x] = 1;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || ny>n || nx<0 || nx>n)
				continue;
			if (arr[ny][nx] >= h && visited[ny][nx] == 0) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = 1;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > top)
				top = arr[i][j];
		}
	while (l <= top) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (visited[j][i] != 1 && arr[j][i] >= l) {
					cnt++;
					bfs(j, i, l);
				}
			}
		l++;
		ans = max(ans, cnt);
		cnt = 0;
		memset(visited, 0, sizeof(visited));
	}
	printf("%d", ans);
}