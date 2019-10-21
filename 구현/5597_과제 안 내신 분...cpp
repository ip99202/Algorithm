#include <stdio.h>

int arr[35];
int main() {
	int n = 28;
	while (n--) {
		int n;
		scanf("%d", &n);
		arr[n] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (arr[i] == 0) {
			printf("%d\n", i);
		}
	}
}

