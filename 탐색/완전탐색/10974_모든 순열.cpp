#include <iostream>
using namespace std;
int ans[100], check[100];

void go(int location, int n) {
	if (location == n) {
		for (int i = 0; i < n; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			check[i] = 1;
			ans[location] = i;
			go(location + 1, n);
			check[i] = 0;
			ans[location] = 0;
		}
	}
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	go(0, n);
}
