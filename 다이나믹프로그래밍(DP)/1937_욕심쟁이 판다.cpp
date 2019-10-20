#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, res;
int arr[502][502];
int day[502][502];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y) {
	day[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (arr[nx][ny] == 0)
			continue;

		if (arr[x][y] < arr[nx][ny]) {
			if (day[nx][ny] == 0)
				dfs(nx, ny);
			day[x][y] = max(day[x][y], day[nx][ny] + 1);
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (day[i][j] == 0)
				dfs(i, j);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			res = max(res, day[i][j]);

	printf("%d", res);
}