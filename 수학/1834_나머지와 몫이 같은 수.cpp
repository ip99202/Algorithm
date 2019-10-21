#include <stdio.h>
int main()
{
	long long num = 0, sum = 0;
	scanf("%d", &num);
	for (long long i = 1; i < num; i++) {
		sum = sum + num * i + i;
	}
	printf("%lld", sum);
	return 0;
}