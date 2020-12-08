#include <stdio.h>

int n, m, sum, min;

void f(int k) {
	if (k == 1) return;
	for (int i = 2; i <= k / 2; i++)
		if (k % i == 0) return;
	if (!min) min = k;
	sum += k;
}


int main() {
	scanf("%d %d", &n, &m);

	for (int i = n; i <= m; i++) f(i);

	if (!sum) printf("-1");
	else printf("%d\n%d", sum, min);

	return 0;
}