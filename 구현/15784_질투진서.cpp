#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001][1001];

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i][b] > arr[a][b]) {
			printf("ANGRY");
			return 0;
		}
		if (arr[a][i] > arr[a][b]) {
			printf("ANGRY");
			return 0;
		}
	}
	printf("HAPPY");
}