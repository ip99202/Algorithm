#include <stdio.h>
int main() {
	int c = 0, nc = 0, n = 0, in = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		if (in == 0) {
			nc++;
		}
		else {
			c++;
		}
	}
	if (c > nc) {
		printf("Junhee is cute!");
	}
	else {
		printf("Junhee is not cute!");
	}
	return 0;
}