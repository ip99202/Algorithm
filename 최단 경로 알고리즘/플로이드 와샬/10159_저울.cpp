#include<iostream>
using namespace std;
int arr[200][200];
int n, m;

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 0 && arr[j][i] == 0)
				cnt++;
		}
		cout << cnt - 1 << endl;
	}
}
