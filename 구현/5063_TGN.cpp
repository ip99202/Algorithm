#include <stdio.h>

int main()
{
	int a = 0, b = 0, c = 0, d = 0, r, e;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &r);
		scanf("%d", &e);
		scanf("%d", &c);

		if (r + c == e)
		{
			printf("does not matter\n");
		}
		else if (r + c > e)
		{
			printf("do not advertise\n");
		}
		else
		{
			printf("advertise\n");
		}
	}

}