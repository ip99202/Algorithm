#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
int arr[1001][1001];

int main() {
	int n, k, cnt = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		y2 = y2 - 1;
		for (int a = y1; a <= y2; a++) {
			arr[a][x1]++;
			arr[a][x2]--;
		}
	}
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			arr[i][j] += arr[i][j - 1];
			if (arr[i][j] == k)
				cnt++;
		}
	}
	printf("%d", cnt);
}