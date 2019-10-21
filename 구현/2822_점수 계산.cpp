#include <stdio.h>
int main()
{
	int arr[9] = { 0, };
	int res[6] = { 0, };
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0;
	int y1 = 0, y2 = 0, y3 = 0, y4 = 0, y5 = 0;
	int sum = 0, tem = 0;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 8; i++) {
		if (x1 < arr[i]) {
			x1 = arr[i];
			y1 = i + 1;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (x2 < arr[i] && i != (y1 - 1)) {
			x2 = arr[i];
			y2 = i + 1;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (x3 < arr[i] && i != (y1 - 1) && i != (y2 - 1)) {
			x3 = arr[i];
			y3 = i + 1;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (x4 < arr[i] && i != (y1 - 1) && i != (y2 - 1) && i != (y3 - 1)) {
			x4 = arr[i];
			y4 = i + 1;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (x5 < arr[i] && i != (y1 - 1) && i != (y2 - 1) && i != (y3 - 1) && i != (y4 - 1)) {
			x5 = arr[i];
			y5 = i + 1;
		}
	}
	res[0] = y1;
	res[1] = y2;
	res[2] = y3;
	res[3] = y4;
	res[4] = y5;
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 4; i++) {
			if (res[i] > res[i + 1]) {
				tem = res[i];
				res[i] = res[i + 1];
				res[i + 1] = tem;
			}
		}
	}
	y1 = res[0];
	y2 = res[1];
	y3 = res[2];
	y4 = res[3];
	y5 = res[4];
	sum = x1 + x2 + x3 + x4 + x5;
	printf("%d\n%d %d %d %d %d", sum, y1, y2, y3, y4, y5);
	return 0;
}