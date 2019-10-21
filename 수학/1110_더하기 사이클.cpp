#include <stdio.h>
int main()
{
	int num = 0, num1 = 0, num2 = 0, sum = 0, cnt = 0, in = 0;
	scanf("%d", &in);
	num = in;
	while (1) {
		if (num < 10) {
			num1 = 0;
			num2 = num;
		}
		else {
			num1 = num / 10;
			num2 = num % 10;
		}
		sum = num1 + num2;
		if (sum >= 10) {
			sum = sum % 10;
		}
		num = num2 * 10 + sum;
		cnt++;
		if (num == in) {
			break;
		}
	}
	printf("%d", cnt);
	return 0;
}