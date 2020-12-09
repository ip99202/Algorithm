#include <stdio.h>
int main()
{
	while (1)
	{
		int num = 0;
		scanf("%d", &num);

		for (int i = 1; i <= 9; i++)
		{
			printf("%d * %d = %d\n", num, i, num * i);
		}
		break;
	}
}