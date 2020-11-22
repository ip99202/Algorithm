#include <stdio.h>
int main() {
	int n1, n2, n3, n4, n5, res = 0;
	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
	res = (n1 * n1 + n2 * n2 + n3 * n3 + n4 * n4 + n5 * n5) % 10;
	printf("%d", res);
	return 0;
}