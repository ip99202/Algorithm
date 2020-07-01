#include <stdio.h>
int main()
{
	int x = 0;
	int y = 0;
	int a = 0;
	scanf("%d", &a);
	y = a * 2 - 1;
	for (int i = 0; i < a; i++)
	{
		for (int i = 0; i < x; i++)
		{
			printf(" ");
		}
		for (int i = 0; i < y; i++)
		{
			printf("*");
		}
		x++;
		y -= 2;
		printf("\n");
	}
	return 0;
}