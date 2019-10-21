#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int arr[65][65];

void quad(int n, int x, int y) {
	if (n == 1) {
		printf("%d", arr[y][x]);
		return;
	}
	bool flag = false;
	bool flag2 = false;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j] == 1)
				flag = true;
			else
				flag2 = true;
		}
	}
	if (flag == false)
		printf("0");
	else if (flag2 == false)
		printf("1");
	else {
		printf("(");
		quad(n / 2, x, y);
		quad(n / 2, x + n / 2, y);
		quad(n / 2, x, y + n / 2);
		quad(n / 2, x + n / 2, y + n / 2);
		printf(")");
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	quad(n, 0, 0);
}