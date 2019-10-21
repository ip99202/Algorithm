#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<cstring>
using namespace std;
char arr[3100][6200];

void star(int n, int x, int y) {
	if (n == 3) {
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';
		arr[y + 2][x - 2] = '*';
		arr[y + 2][x - 1] = '*';
		arr[y + 2][x] = '*';
		arr[y + 2][x + 1] = '*';
		arr[y + 2][x + 2] = '*';
		return;
	}
	star(n / 2, x, y);
	star(n / 2, x - n / 2, y + n / 2);
	star(n / 2, x + n / 2, y + n / 2);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			arr[i][j] = ' ';
		}
	}
	star(n, n - 1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}