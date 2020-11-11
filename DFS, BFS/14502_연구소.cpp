#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, res;
int arr[8][8];
int temp[8][8];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
typedef pair<int, int>P;

void bfs() {
	int visited[8][8];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = temp[i][j];

	queue<P>q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visited[i][j] == 2)
				q.push(P(i, j));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && ny < n && nx >= 0 && nx < m)
				if (visited[ny][nx] == 0) {
					q.push(P(ny, nx));
					visited[ny][nx] = 2;
				}

		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visited[i][j] == 0)
				cnt++;

	res = max(res, cnt);

}

void make_wall(int wall) {
	if (wall == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (temp[i][j] == 0) {
				temp[i][j] = 1;
				make_wall(wall + 1);
				temp[i][j] = 0;
			}
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				for (int a = 0; a < n; a++)
					for (int b = 0; b < m; b++)
						temp[a][b] = arr[a][b];

				temp[i][j] = 1;
				make_wall(1);
				temp[i][j] = 0;
			}
		}

	cout << res;
}