#include <stdio.h>
int main()
{
	int x = 0;
	int y = 0;
	int j = 0;
	int z = 0;
	int a = 0;
	scanf("%d", &a);
	y = a;
	z = a * 2 - 1;
	for (int i = 0; i < a - 1; i++)
	{
		for (int i = 1; i < y; i++)
		{
			printf(" ");
		}
		for (int i = 0; i <= x; i++)
		{
			printf("*");
		}
		x += 2;
		y--;
		printf("\n");
	}
	for (int i = 0; i < a; i++)
	{
		for (int i = 1; i <= j; i++)
		{
			printf(" ");
		}
		for (int i = 0; i < z; i++)
		{
			printf("*");
		}
		j++;
		z -= 2;
		printf("\n");
	}
	return 0;
}