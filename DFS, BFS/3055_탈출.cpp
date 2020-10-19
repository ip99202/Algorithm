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
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visited[55][55];
char arr[55][55];
queue<P>hedge[1000], water[1000];
int r, c;

void wbfs(int k) {
	while (!water[k].empty()) {
		int wx = water[k].front().first;
		int wy = water[k].front().second;
		water[k].pop();
		for (int i = 0; i < 4; i++) {
			int wnx = wx + dx[i];
			int wny = wy + dy[i];
			if (wnx < r && wnx >= 0 && wny < c && wny >= 0 && arr[wnx][wny] == '.') {
				water[k + 1].push(P(wnx, wny));
				arr[wnx][wny] = '*';
			}
		}
	}
}

void bfs(int k) {
	while (!hedge[k].empty()) {
		int x = hedge[k].front().first;
		int y = hedge[k].front().second;
		hedge[k].pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (arr[nx][ny] == 'D') {
				printf("%d", visited[x][y] + 1);
				exit(0);
			}
			if (nx < r && nx >= 0 && ny < c && ny >= 0 && arr[nx][ny] == '.' && visited[nx][ny] == 0) {
				hedge[k + 1].push(P(nx, ny));
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
}

int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) {
		getchar();
		for (int j = 0; j < c; j++) {
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == '*')
				water[0].push(P(i, j));
			if (arr[i][j] == 'S') {
				hedge[0].push(P(i, j));
				visited[i][j] == 1;
			}
		}
	}
	for (int i = 0; i < 1000; i++) {
		wbfs(i);
		bfs(i);
	}
	printf("KAKTUS");
}