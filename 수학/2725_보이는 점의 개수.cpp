#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<cstring>
using namespace std;
int res[1001];

int gcd(int a, int b) {
	int t;
	while (b) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main() {
	int c;
	scanf("%d", &c);
	res[1] = 3;
	for (int i = 2; i <= 1000; i++) {
		int cnt = 0;
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) == 1)
				cnt++;
		}
		res[i] = res[i - 1] + 2 * cnt;
	}
	while (c--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", res[n]);
	}
}
