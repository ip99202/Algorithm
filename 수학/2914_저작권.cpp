#include <stdio.h>
int main() {
	int r1 = 0, r2 = 0, s = 0;
	scanf("%d %d", &r2, &s);
	printf("%d", r2 * (s - 1) + 1);
	return 0;
}
