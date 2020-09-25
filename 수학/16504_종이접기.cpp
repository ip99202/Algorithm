#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
long long n, sum;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			scanf("%d", &a);
			sum += a;
		}
	}
	printf("%lld", sum);
	return 0;
}