#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<deque>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
typedef pair<int, int>P;
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int arr[105][105];
queue<P>q, melt;
vector<int>res;
bool visited[105][105];

void melting() {
	while (!melt.empty()) {
		int x = melt.front().first;
		int y = melt.front().second;
		arr[x][y] = 0;
		melt.pop();
	}
}

void bfs() {
	q.push(P(0, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0)
				continue;
			if (arr[nx][ny] == 0 && visited[nx][ny] == false) {
				q.push(P(nx, ny));
				visited[nx][ny] = true;
			}
			if (arr[nx][ny] == 1 && visited[nx][ny] == false) {
				melt.push(P(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	while (true) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					cnt++;
				}
			}
		}
		if (cnt == 0) {
			printf("%d\n%d", res.size(), res.back());
			return 0;
		}
		res.push_back(cnt);
		bfs();
		memset(visited, 0, sizeof(visited));
		melting();
	}
}