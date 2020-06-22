#include <stdio.h>
int main()
{
	int num = 0, x = 0, y = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &x, &y);
		printf("Case #%d: %d\n", i + 1, x + y);
	}
	return 0;
}