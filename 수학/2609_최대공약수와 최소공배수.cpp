#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0) return a;
	else gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
	int a = 0, b = 0;
	int temp = 0;
	scanf("%d %d", &a, &b);
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	printf("%d\n", gcd(a, b));
	printf("%d", lcm(a, b));
	return 0;
}