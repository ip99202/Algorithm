#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (abs(a - b) == 1 && abs(b - c) == 1) {
		printf("0\n0");
		return 0;
	}
	else if (abs(a - b) == 2 || abs(b - c) == 2) {
		printf("1\n");
	}
	else {
		printf("2\n");
	}
	int m = max(b - a, c - b);
	printf("%d", m - 1);
}