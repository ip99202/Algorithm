#include <stdio.h>
#include <string.h>
int main() {
	int n = 0, x = 0, tem = 0;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tem);
		if (tem < x) {
			printf("%d ", tem);
		}
	}
	return 0;
}