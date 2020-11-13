#include <stdio.h>
int main()
{
	int x, y, z, temp = 0;
	int num, sum, res = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d %d", &x, &y, &z);
		if (x == y && x == z && y == z) {
			sum = 10000 + x * 1000;
		}
		else if (x != y && x != z && y != z) {
			if (x > temp) {
				temp = x;
			}
			if (y > temp) {
				temp = y;
			}
			if (z > temp) {
				temp = z;
			}
			sum = temp * 100;
		}
		else {
			int l_num[4];
			l_num[0] = x;
			l_num[1] = y;
			l_num[2] = z;
			while (1) {
				if (l_num[0] > l_num[1]) {
					temp = l_num[0];
					l_num[0] = l_num[1];
					l_num[1] = temp;
				}
				if (l_num[1] > l_num[2]) {
					temp = l_num[1];
					l_num[1] = l_num[2];
					l_num[2] = temp;
				}
				if (l_num[0] <= l_num[1] && l_num[1] <= l_num[2]) {
					break;
				}
			}
			sum = 1000 + l_num[1] * 100;
		}
		if (sum > res) {
			res = sum;
		}
	}
	printf("%d", res);
	return 0;
}