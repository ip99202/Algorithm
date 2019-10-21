#include <stdio.h>
int main()
{
	int a = 0;
	int x = 0;
	int y = 0;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d %d", &x, &y);
		printf("%d %d\n", (y * 2 - x), y - (y * 2 - x));
	}
	return 0;
}