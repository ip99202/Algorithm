#include <stdio.h>
int main()
{
	int x = 0, y = 0;
	while (scanf("%d %d", &x, &y) != EOF) {
		printf("%d\n", x + y);
	}
	return 0;
}