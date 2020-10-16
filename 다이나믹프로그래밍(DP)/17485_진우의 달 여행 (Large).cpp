#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int arr[1001][1001], dp[1001][1001][4];
int dy[] = { -1,0,1 };
int dx[] = { 1,1,1 };
int res = 1e9, n, m;

int moon(int x, int y, int st) {
	if (x == n - 1)
		return 0;
	if (dp[x][y][st] != -1)
		return dp[x][y][st];
	dp[x][y][st] = 1e9;
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny < 0 || ny >= m || st == i)
			continue;
		dp[x][y][st] = min(dp[x][y][st], moon(nx, ny, i) + arr[nx][ny]);
	}
	return dp[x][y][st];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < m; i++)
		res = min(res, arr[0][i] + moon(0, i, 3));
	cout << res;
	return 0;
}