#include <stdio.h>
int main() {
	int r = 0, b = 0, l = 0, w = 0;
	scanf("%d %d", &r, &b);
	for (l = 1;; l++) {
		if (b % l == 0) {
			w = b / l;
			if (r == l * 2 + w * 2 + 4) {
				printf("%d %d", w + 2, l + 2);
				break;
			}
		}
	}
	return 0;
}