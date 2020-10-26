#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int>P;
typedef pair<int, P>PP;
int arr[101][101][101];
bool visited[101][101][101];
int cnt[101][101][101];
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue<PP>q;
int mx;

int main() {
	int n, m, h;
	scanf("%d%d%d", &m, &n, &h);
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x;
				scanf("%d", &x);
				arr[k][i][j] = x;
				if (x == 1) {
					q.push({ k,{i,j} });
				}
			}
		}
	}
	while (!q.empty()) {
		PP now = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = now.second.first + dx[i];
			int ny = now.second.second + dy[i];
			int nz = now.first + dz[i];
			if (nx < 0 || nx >= n) continue;
			if (ny < 0 || ny >= m) continue;
			if (nz < 0 || nz >= h) continue;
			if (visited[nz][nx][ny] == true || arr[nz][nx][ny] == -1)
				continue;
			if (arr[nz][nx][ny] == 0) {
				arr[nz][nx][ny] = 2;
				visited[nz][nx][ny] = true;
				cnt[nz][nx][ny] = cnt[now.first][now.second.first][now.second.second] + 1;
				mx = max(mx, cnt[nz][nx][ny]);
				q.push({ nz,{nx,ny} });
			}
		}
	}
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[k][i][j] == 0) {
					printf("-1");
					return 0;
				}
			}
		}
	}
	printf("%d", mx);
}