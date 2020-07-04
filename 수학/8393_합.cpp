#include <stdio.h>

int main()
{
	int x = 0;
	int res = 0;
	int i = 0;
	scanf("%d", &x);
	for (i = 0; i <= x; i++)
	{
		res += i;
	}
	printf("%d", res);
	return 0;
}