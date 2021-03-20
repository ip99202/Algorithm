#include<iostream>
using namespace std;
int r, c;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int visited[21][21];
char str[21][21];
int alpha[30];
int cnt = 1, res = 1;

void dfs(int x, int y) {
	visited[0][0] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;
		int n = str[nx][ny] - 'A' + 1;
		if (alpha[n] == 1)
			continue;
		if (visited[nx][ny] == 1)
			continue;
		alpha[n] = 1;
		cnt++;
		if (cnt > res)
			res = cnt;
		dfs(nx, ny);
		alpha[n] = 0;
		cnt--;
	}
}

int main() {
	scanf("%d %d ", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%c", &str[i][j]);
		}
		getchar();
	}
	alpha[str[0][0] - 'A' + 1] = 1;
	dfs(0, 0);
	printf("%d", res);
}