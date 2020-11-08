#include <stdio.h>
int main()
{
	int list[10] = { 0, };
	int x = 0, y = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &list[i]);
	}
	for (int i = 0; i < 9; i++) {
		if (x < list[i]) {
			x = list[i];
			y = i + 1;
		}
	}
	printf("%d\n%d", x, y);
	return 0;
}