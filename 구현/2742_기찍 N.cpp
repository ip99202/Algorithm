#include <stdio.h>
int main()
{
	int num = 0;
	scanf("%d", &num);
	for (int i = num; i >= 1; i--)
	{
		printf("%d\n", i);
	}
}