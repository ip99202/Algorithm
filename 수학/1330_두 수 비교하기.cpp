#include <stdio.h>
int main() {
	int n1 = 0, n2 = 0;
	scanf("%d %d", &n1, &n2);
	if (n1 < n2) {
		printf("%c", '<');
	}
	else if (n1 > n2) {
		printf("%c", '>');
	}
	else {
		printf("%s", "==");
	}
	return 0;
}