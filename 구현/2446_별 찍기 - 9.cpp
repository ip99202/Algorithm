#include <stdio.h>
int main()
{
	int num = 0, x = 1, y = 0;
	scanf("%d", &num);
	y = num * 2 - 1;
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < x - 1; j++) {
			printf(" ");
		}
		for (int j = 0; j < y; j++) {
			printf("*");
		}
		printf("\n");
		x++;
		y -= 2;
	}
	x = 0, y = 1;
	x = num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < x - 1; j++) {
			printf(" ");
		}
		for (int j = 0; j < y; j++) {
			printf("*");
		}
		printf("\n");
		x--;
		y += 2;
	}
	return 0;
}