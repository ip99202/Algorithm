#include <stdio.h>
int main() {
	long long n = 0, cnt = 0, res = 0;
	scanf("%lld", &n);
	res = n + n + 2 * n;
	printf("%lld", res);
	return 0;
}