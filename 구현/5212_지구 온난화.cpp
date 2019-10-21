#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
typedef pair<int, int>P;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
char arr[101][101];
queue<P>q, res;

int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; i++)
		scanf("%s", &arr[i]);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 'X') {
				q.push(P(i, j));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int cnt = 0;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0) {
				cnt++;
			}
			else {
				if (arr[nx][ny] == '.' || arr[nx][ny] == 0)
					cnt++;
			}
			if (cnt >= 3)
				res.push(P(x, y));
		}
	}
	while (!res.empty()) {
		P now = res.front();
		arr[now.first][now.second] = '.';
		res.pop();
	}
	int x1 = 99999999, x2 = 0, y1 = 99999999, y2 = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 'X') {
				x1 = min(x1, i);
				x2 = max(x2, i);
				y1 = min(y1, j);
				y2 = max(y2, j);
			}
		}
	}
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}