#include<iostream>
#include<vector>
using namespace std;
vector<int>arr[40000];
int n, m;
#define INF 10000000

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		arr[i].resize(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				arr[i][j] = INF;

	while (m--) {
		int u, v, b;
		scanf("%d %d %d", &u, &v, &b);
		arr[u - 1][v - 1] = 0;
		if (b == 1) {
			arr[v - 1][u - 1] = 0;
			continue;
		}
		arr[v - 1][u - 1] = 1;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	int q;
	scanf("%d", &q);
	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", arr[a - 1][b - 1]);
	}
}
