#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<deque>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int, int>P;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int tomato[1005][1005];
int d[1005][1005];
queue<P>q, save;
int m, n, cnt, res;

int main() {
	scanf("%d %d", &m, &n);
	queue<pair<int, int> > q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &tomato[i][j]);
			d[i][j] = -1;
			if (tomato[i][j] == 1) {
				q.push({ i, j });
				d[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (tomato[nx][ny] == 0 && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result = max(result, d[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0 && d[i][j] == -1) {
				result = -1;
			}
		}
	}
	cout << result;
}