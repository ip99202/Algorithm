#include <stdio.h>
int main() {
	long long n = 0;
	int x = 0, y = 0;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", x + y);
	}
}