#include <stdio.h>
int main() {
	int n = 0, num = 0, res = 0, x = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		for (int j = 2; j < num; j++) {
			if (num % j != 0) {
				res++;
			}
			else {
				break;
			}
		}
		if (res == num - 2) {
			x++;
		}
		res = 0;
	}
	printf("%d", x);
}