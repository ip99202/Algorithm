#include <stdio.h>
int pibo(int a) {
	if (a == 0) return 0;
	else if (a == 1) return 1;
	else return pibo(a - 1) + pibo(a - 2);
}

int main() {
	int a = 0;
	scanf("%d", &a);
	printf("%d", pibo(a));
	return 0;
}