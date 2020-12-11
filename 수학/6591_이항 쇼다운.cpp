#include <iostream>
using namespace std;

int main() {
	int n, k;
	long long ans = 1, b = 1;
	while (1) {
		scanf("%d %d", &n, &k);
		if (n == 0) break;
		if (n - k < k)
			k = n - k;
		while (k-- > 0) {
			ans = ans * n--;
			ans = ans / b++;
		}
		printf("%d\n", ans);
		ans = 1;
		b = 1;
	}
}