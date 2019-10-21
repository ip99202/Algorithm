#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
typedef pair<int, int>P;
char arr[101][101];
int res[101][101];
queue<P>q;

int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; i++)
		scanf("%s", &arr[i]);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 'c') {
				q.push(P(i, j));
			}
		}
	}
	while (!q.empty()) {
		P now = q.front();
		q.pop();
		int nx = now.first;
		int ny = now.second + 1;
		if (nx >= h || ny >= w)
			continue;
		if (arr[nx][ny] == 'c')
			continue;
		q.push(P(nx, ny));
		res[nx][ny] = res[now.first][now.second] + 1;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 'c' && res[i][j] == 0)
				printf("0 ");
			else if (res[i][j] == 0)
				printf("-1 ");
			else
				printf("%d ", res[i][j]);
		}
		printf("\n");
	}
}