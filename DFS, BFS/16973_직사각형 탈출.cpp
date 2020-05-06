#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int>P;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[1001][1001], cnt[1001][1001];
int n, m, h, w, sx, sy, fx, fy;
bool visited[1001][1001];
queue<P>q;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d%d", &h, &w);
	scanf("%d%d", &sx, &sy);
	scanf("%d%d", &fx, &fy);
	q.push(P(sx, sy));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			bool flag = false;
			for (int i = 0; i < h; i++) {
				if (i == 0 || i == h - 1) {
					for (int j = 0; j < w; j++) {
						if (map[nx + i][ny + j] == 1 || nx + i > n || ny + j > m || nx + i < 1 || ny + j < 1)
							flag = true;
					}
				}
				else {
					if (map[nx + i][ny] == 1 || nx + i > n || ny > m || nx + i < 1 || ny < 1)
						flag = true;
					if (map[nx + i][ny + w - 1] == 1 || nx + i > n || ny + w - 1 > m || nx + i < 1 || ny + w - 1 < 1)
						flag = true;
				}
			}
			if (flag == true) continue;
			if (visited[nx][ny] == false) {
				q.push(P(nx, ny));
				visited[nx][ny] = true;
				cnt[nx][ny] = cnt[x][y] + 1;
				if (visited[fx][fy] == true) {
					printf("%d", cnt[fx][fy]);
					return 0;
				}
			}
		}
	}
	printf("-1");
}