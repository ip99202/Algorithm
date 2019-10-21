#include <stdio.h>
int memo[100];
int facto(int n) {
	if (n == 0) return 1;
	return n * facto(n - 1);
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", facto(n));
	return 0;
}