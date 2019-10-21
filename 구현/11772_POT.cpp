#include <stdio.h>
#include <math.h>
int main() {
	int n = 0, num = 0, sum = 0, pot = 0, o_num = 0, res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		pot = num % 10;
		o_num = num / 10;
		res = (int)pow((double)(o_num), (double)(pot));
		sum += res;
	}
	printf("%d", sum);
	return 0;
}