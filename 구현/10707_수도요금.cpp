#include <stdio.h>
int main() {
	int x_l = 0, y_base = 0, y_max = 0, y_add = 0, used = 0, x = 0, y = 0;
	scanf("%d", &x_l);
	scanf("%d", &y_base);
	scanf("%d", &y_max);
	scanf("%d", &y_add);
	scanf("%d", &used);
	x = x_l * used;
	if (used > y_max) {
		y = used - y_max;
		y *= y_add;
		y += y_base;
	}
	else if (used < y_max) {
		y = y_base;
	}
	if (x > y) {
		printf("%d", y);
	}
	else {
		printf("%d", x);
	}
}

