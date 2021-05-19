#include <stdio.h>
int main()
{
	long long x = 0;
	long long y = 0;
	long long res = 0;
	scanf("%lld %lld", &x, &y);
	if (x > y) {
		res = x - y;
	}
	if (y > x) {
		res = y - x;
	}
	printf("%lld", res);
	return 0;
}