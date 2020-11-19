#include <stdio.h>
#include <string.h>
int main() {
	int n = 0, m = 0;
	scanf("%d", &m);
	for (int j = 0; j < m; j++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			printf("=");
		}
		printf("\n");
	}
	return 0;
}