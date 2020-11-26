#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
queue < pair<int, int>>q;
int arr[26][26];
int n, m, cnt = 0;
int visited[26][26];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int num[25][25];
int res[1000];
int temp = 0;
int nnum = 0;

void bfs(int y, int x, int cnt) {
	visited[y][x] = 1;
	num[y][x] = 1;
	q.push(make_pair(y, x));
	res[cnt] = 1;
	nnum = 0;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<0 || ny>n || nx<0 || nx>n)
				continue;
			if (arr[ny][nx] == 1 && visited[ny][nx] == 0) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = 1;
				nnum++;
				num[ny][nx] = nnum + 1;
				if (num[ny][nx] > temp)
					res[cnt] = num[ny][nx];
			}
		}
	}
	temp = 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				cnt++;
				bfs(i, j, cnt);
			}
		}
	sort(res, res + 1000);
	printf("%d\n", cnt);
	int i = 0;
	while (1) {
		if (res[i] != 0)
			printf("%d\n", res[i]);
		if (i == 999)
			break;
		i++;
	}
}