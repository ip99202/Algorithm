#include <stdio.h>
#include <string.h>
int main() {
	int n = 0, a = 0;
	scanf("%d", &a);
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;
		if (n % a != 0) {
			printf("%d is NOT a multiple of %d.\n", n, a);
		}
		else {
			printf("%d is a multiple of %d.\n", n, a);
		}
	}
	return 0;
}
