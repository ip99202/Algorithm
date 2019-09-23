#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int>P;
queue<P>q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char arr[1002][1002];
bool visited[1002][1002];
int n;
vector<P>res;

void bfs(int x, int y) {
	visited[x][y] = true;
	q.push(P(x, y));
	int size = 0;
	int len = 0;
	while (!q.empty()) {
		P now = q.front();
		q.pop();
		size++;
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (visited[nx][ny] == true)
				continue;
			if (arr[nx][ny] == '.' || nx <= 0 || nx > n || ny <= 0 || ny > n) {
				len++;
			}
			if (arr[nx][ny] == '#') {
				q.push(P(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
	res.push_back(P(-size, len));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= n; j++) {
			scanf("%c", &arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && arr[i][j] == '#')
				bfs(i, j);
		}
	}
	sort(res.begin(), res.end());
	printf("%d %d", -res[0].first, res[0].second);
}