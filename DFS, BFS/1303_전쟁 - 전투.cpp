#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
typedef pair<int, int>P;
queue<P>q;
char arr[105][105];
bool w_visited[105][105];
bool b_visited[105][105];
int n, m, w_res, b_res;

void soldier(int y, int x, char team) {
	int cnt = 1;
	if (team == 'W')
		w_visited[y][x] = true;
	else
		b_visited[y][x] = true;
	q.push(P(y, x));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (team == 'W') {
				if (arr[ny][nx] == team && w_visited[ny][nx] == false) {
					q.push(P(ny, nx));
					cnt++;
					w_visited[ny][nx] = true;
				}
			}
			else {
				if (arr[ny][nx] == team && b_visited[ny][nx] == false) {
					q.push(P(ny, nx));
					cnt++;
					b_visited[ny][nx] = true;
				}
			}
		}
	}
	if (team == 'W')
		w_res += cnt * cnt;
	else
		b_res += cnt * cnt;
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'W' && w_visited[i][j] == false)
				soldier(i, j, 'W');
			if (arr[i][j] == 'B' && b_visited[i][j] == false)
				soldier(i, j, 'B');
		}
	}
	printf("%d %d", w_res, b_res);
}