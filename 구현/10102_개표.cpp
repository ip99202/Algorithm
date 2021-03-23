#include <stdio.h>
int main() {
	int n = 0, a = 0, b = 0;
	char arr[16] = { 0, };
	scanf("%d", &n);
	scanf("%s", arr);
	for (int i = 0; i < n; i++) {
		if (arr[i] == 'A') {
			a++;
		}
		else if (arr[i] == 'B') {
			b++;
		}
	}
	if (a > b) {
		printf("A");
	}
	else if (a < b) {
		printf("B");
	}
	else {
		printf("Tie");
	}
	return 0;
}