#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int temp = 0;
	int num[4];
	scanf("%d %d %d", &a, &b, &c);
	num[0] = a;
	num[1] = b;
	num[2] = c;
	while (1) {
		if (num[0] > num[1]) {
			temp = num[0];
			num[0] = num[1];
			num[1] = temp;
		}
		if (num[1] > num[2]) {
			temp = num[1];
			num[1] = num[2];
			num[2] = temp;
		}
		if (num[0] <= num[1] && num[1] <= num[2]) {
			break;
		}
	}
	printf("%d %d %d", num[0], num[1], num[2]);
}