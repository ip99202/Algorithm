#include<iostream>
using namespace std;
int arr[101][101];
int n, m;
#define INF 10000000

int main() {
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				arr[i][j] = INF;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (arr[x][y] > z)
			arr[x][y] = z;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == INF)
				arr[i][j] = 0;
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
