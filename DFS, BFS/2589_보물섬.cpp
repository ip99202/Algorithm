#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int, int>P;
queue<P>q;
bool visited[55][55];
int cnt[55][55], res;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char arr[55][55];

void bfs(int y, int x) {
	visited[y][x] = true;
	q.push(P(y, x));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (arr[ny][nx] == 'L' && visited[ny][nx] == false) {
				visited[ny][nx] = true;
				q.push(P(ny, nx));
				cnt[ny][nx] = cnt[y][x] + 1;
				res = max(res, cnt[ny][nx]);
			}
		}
	}
}

int main() {
	int l, w;
	scanf("%d%d", &l, &w);
	for (int i = 0; i < l; i++) {
		getchar();
		for (int j = 0; j < w; j++) {
			char a;
			scanf("%c", &a);
			arr[i][j] = a;
		}
	}
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 'L') {
				bfs(i, j);
				memset(visited, false, sizeof(visited));
				memset(cnt, 0, sizeof(cnt));
			}
		}
	}
	printf("%d", res);
}