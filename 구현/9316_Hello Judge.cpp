#include <stdio.h>
int main()
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		printf("Hello World, Judge %d!\n", i + 1);
	}
	return 0;
}