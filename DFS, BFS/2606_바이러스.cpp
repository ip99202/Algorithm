#include<iostream>
using namespace std;
int num[101][101];
int n, m, cnt;

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		num[x][y] = 1;
		num[y][x] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (num[i][k] && num[k][j])
					num[i][j] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++)
		if (num[1][i] == 1)
			cnt++;
	cout << cnt;
}