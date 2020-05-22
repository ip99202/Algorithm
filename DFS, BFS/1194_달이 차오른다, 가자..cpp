#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int>P;
char arr[51][51];
int visited[51][51][1 << 7];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
struct maze {
	int x, y, k;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	queue<maze>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0') {
				q.push({ i,j,0 });
				visited[i][j][0] = 1;
			}
		}
	}

	while (!q.empty()) {
		maze now = q.front();
		q.pop();
		if (arr[now.x][now.y] == '1') {
			cout << visited[now.x][now.y][now.k] - 1;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == '#')
				continue;
			if (visited[nx][ny][now.k])
				continue;

			if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'f') {
				int nk = now.k | (1 << (arr[nx][ny] - 'a'));
				if (!visited[nx][ny][nk]) {
					visited[nx][ny][now.k] = visited[now.x][now.y][now.k] + 1;
					visited[nx][ny][nk] = visited[now.x][now.y][now.k] + 1;
					q.push({ nx,ny,nk });
				}
			}
			else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'F') {
				int nk = now.k & (1 << (arr[nx][ny] - 'A'));
				if (nk) {
					visited[nx][ny][now.k] = visited[now.x][now.y][now.k] + 1;
					q.push({ nx,ny,now.k });
				}
			}
			else {
				visited[nx][ny][now.k] = visited[now.x][now.y][now.k] + 1;
				q.push({ nx,ny,now.k });
			}
		}
	}
	cout << -1;
	return 0;
}