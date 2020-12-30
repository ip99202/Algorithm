#include <stdio.h>
int main() {
	int i, j = 0, sum = 0, min = 100;
	int a[8] = { 0, };
	int b[8] = { 0, };
	for (i = 0; i < 7; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 7; i++) {
		if (a[i] % 2 == 1) {
			b[j] = a[i];
			j++;
		}
	}
	for (i = 0; i < 7 && b[i] != 0; i++) {
		if (min > b[i]) {
			min = b[i];
		}
		sum += b[i];
	}
	if (sum == 0) {
		printf("-1");

	}
	else {
		printf("%d\n", sum);
		printf("%d", min);
	}
}