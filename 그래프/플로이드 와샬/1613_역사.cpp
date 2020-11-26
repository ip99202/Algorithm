#include<iostream>
using namespace std;
int arr[401][401];
int n, m, q;

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
		arr[y][x] = -1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] == 1 && arr[k][j] == 1)
					arr[i][j] = 1;
				if (arr[i][k] == -1 && arr[k][j] == -1)
					arr[i][j] = -1;
			}
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (arr[a][b] == 1)
			printf("-1\n");
		if (arr[a][b] == -1)
			printf("1\n");
		if (arr[a][b] == 0)
			printf("0\n");
	}
}
