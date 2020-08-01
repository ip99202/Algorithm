#include <stdio.h>
#include <string.h>
int main()
{
	char x[1000000];
	int num = 0;
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++) {
		gets(x);
		printf("%d. %s\n", i + 1, x);
	}
	return 0;
}