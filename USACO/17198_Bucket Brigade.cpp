#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, pair<int, int>>P;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int arr[11][11], res[11][11];
queue<P>q;

int main() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == 'L') {
				q.push({ 0,{ i,j } });
				res[i][j] = 1;
			}
		}
		getchar();
	}
	while (!q.empty()) {
		P now = q.front();
		int x = now.second.first;
		int y = now.second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.second.first + dx[i];
			int ny = now.second.second + dy[i];
			if (nx < 1 || nx > 10 || ny < 1 || ny > 10 || res[nx][ny] != 0)
				continue;
			if (arr[nx][ny] == 'R')
				continue;
			if (arr[nx][ny] == 'B') {
				printf("%d", res[x][y] - 1);
				return 0;
			}
			res[nx][ny] = res[x][y] + 1;
			q.push({ now.first + 1 ,{ nx,ny } });
		}
	}
}