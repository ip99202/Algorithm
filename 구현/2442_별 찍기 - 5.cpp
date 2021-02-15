#include <stdio.h>


int main()
{
	int x;
	int y = 1;
	int a;
	scanf("%d", &a);
	x = a;
	for (int i = 0; i < a; i++)
	{
		for (int i = x; i > 1; i--)
		{
			printf(" ");
		}
		for (int i = 0; i < y; i++)
		{
			printf("*");
		}
		x--;
		y += 2;
		printf("\n");
	}
	return 0;
}