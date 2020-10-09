#include <stdio.h>
int main()
{
	int x = 1;
	int y = 0;
	int num = 0;
	scanf("%d", &num);
	y = num * 2 - 2;
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < x; j++) {
			printf("*");
		}
		for (int j = 0; j < y; j++) {
			printf(" ");
		}
		for (int j = 0; j < x; j++) {
			printf("*");
		}
		printf("\n");
		y -= 2;
		x++;
	}
	x = num;
	y = 0;
	for (int i = 0; i < num + 1; i++) {
		for (int j = 0; j < x; j++) {
			printf("*");
		}
		for (int j = 0; j < y; j++) {
			printf(" ");
		}
		for (int j = 0; j < x; j++) {
			printf("*");
		}
		printf("\n");
		x--;
		y += 2;
	}

	return 0;
}